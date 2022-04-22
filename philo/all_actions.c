/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/22 16:02:18 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_eating(t_philo *philo, t_rules *rules)
{
	if (grab_forks(philo, rules) == 1)
		return (1);
	if (pthread_mutex_lock(&philo->state) != 0)
		return (1);
	philo->status = 0;
	if (pthread_mutex_unlock(&philo->state) != 0)
		return (1);
	action(rules, philo, "is eating");
	if (pthread_mutex_lock(&philo->time_eat) != 0)
		return (1);
	philo->time_last_meal = get_time();
	if (pthread_mutex_unlock(&philo->time_eat) != 0)
		return (1);
	usleep_eat_think(rules->time_to_eat);
	if (pthread_mutex_lock(&philo->nb_meals) != 0)
		return (1);
	philo->times_eaten++;
	if (pthread_mutex_unlock(&philo->nb_meals) != 0)
		return (1);
	if (drop_forks(philo, rules) == 1)
		return (1);
	return (0);
}

int	philo_is_sleeping(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is sleeping");
	if (pthread_mutex_lock(&philo->state) != 0)
		return (1);
	philo->status = 1;
	if (pthread_mutex_unlock(&philo->state) != 0)
		return (1);
	usleep_eat_think(rules->time_to_sleep);
	return (0);
}

static int	check_death_status(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(philo->dead) != 0)
		return (1);
	if (rules->are_dead == true)
		return (pthread_mutex_unlock(philo->dead), 1);
	if (pthread_mutex_unlock(philo->dead) != 0)
		return (1);
	return (0);
}

void	*ft_start_daily_routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	while (eaten_enough(philo, rules) != 0)
	{
		if (check_death_status(philo, rules) == 1)
			return (NULL);
		if (philo_is_eating(philo, rules) == 1)
			return (NULL);
		if (philo_is_sleeping(philo, rules) == 1)
			return (NULL);
		if (pthread_mutex_lock(&philo->state) != 0)
			return (NULL);
		if (philo->status != 0)
		{
			philo->status = 2;
			if (pthread_mutex_unlock(&philo->state) != 0)
				return (NULL);
			action(rules, philo, "is thinking");
		}
	}
	return (NULL);
}
