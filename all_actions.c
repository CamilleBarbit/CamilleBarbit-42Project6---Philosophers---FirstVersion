/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/20 11:58:37 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_eating(t_philo *philo, t_rules *rules)
{
	// if (philo->philo_id % 2 == 1 && philo->times_eaten == 1) //ajouté
	// 	usleep(100);
	if (grab_forks(philo, rules) == 1)
		return (1);
	// if (pthread_mutex_lock(&philo->state) != 0)
	// 	return (1);
	philo->status = 0; //le philo mange
	// if (pthread_mutex_unlock(&philo->state) != 0)
	// 	return (1);
	action(rules, philo, "is eating");
	if (pthread_mutex_lock(&philo->time_eat) != 0)
			return (1);
	philo->time_last_meal = get_time(); //Update heure du début de dernier repas
	if (pthread_mutex_unlock(&philo->time_eat) != 0)
			return (1);
	usleep_eat_think(rules->time_to_eat);
	philo->times_eaten++;
	if (drop_forks(philo, rules) == 1)
		return (1);
	return (0);
}

int	philo_is_sleeping(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is sleeping");
	// if (pthread_mutex_lock(&philo->state) != 0)
	// 	return (1);
	philo->status = 1; //le philo dort
	// if (pthread_mutex_unlock(&philo->state) != 0)
	// 	return (1);
	usleep_eat_think(rules->time_to_sleep);
	return (0);
}

void	*ft_start_daily_routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;
	while(eaten_enough(philo, rules) != 0)
	{
		if (pthread_mutex_lock(philo->dead) != 0)
			return (NULL);
		if (rules->are_dead == true)
			return (pthread_mutex_unlock(philo->dead), NULL);
		if (pthread_mutex_unlock(philo->dead) != 0)
			return (NULL);
		if (philo_is_eating(philo, rules) == 1)
			return (NULL);
		if (philo_is_sleeping(philo, rules) == 1)
			return (NULL);
		// if (pthread_mutex_lock(&philo->state) != 0)
		// 	return (NULL);
		if (philo->status != 0)
		{
			philo->status = 2;
			// if (pthread_mutex_unlock(&philo->state) != 0)
			// 	return (NULL);
			action(rules, philo, "is thinking");
		}
		// if (pthread_mutex_unlock(&philo->state) != 0)
		// 	return (NULL);
		// if (rules->are_dead == true)
		// 	return (pthread_mutex_unlock(philo->dead), NULL);
	}
	return (NULL);
}