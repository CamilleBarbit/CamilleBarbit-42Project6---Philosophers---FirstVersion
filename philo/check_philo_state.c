/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/22 16:37:50 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_meals(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&philo->nb_meals);
	if (philo->times_eaten == rules->times_must_eat)
		return (pthread_mutex_unlock(&philo->nb_meals), 1);
	pthread_mutex_unlock(&philo->nb_meals);
	return (0);
}

static void	modify_death_status(t_rules *rules)
{
	pthread_mutex_lock(&rules->have_died);
	if (rules->are_dead == false)
		rules->are_dead = true;
	pthread_mutex_unlock(&rules->have_died);
}

static	int	routine_thread(t_philo *philo, t_rules *rules)
{
	if ((get_diff(philo->time_last_meal)
			>= rules->time_to_die))
	{
		pthread_mutex_unlock(&philo->state);
		pthread_mutex_unlock(&philo->time_eat);
		modify_death_status(rules);
		if (action_dead(rules, philo, "died") == 1)
			return (1);
		return (1);
	}
	return (0);
}

void	*ft_check_threads(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	while (1)
	{
		i = 0;
		while (i < rules->nb_philos)
		{
			if (check_meals(&rules->all_philos[i], rules) == 1)
				return (NULL);
			pthread_mutex_lock(&rules->all_philos[i].time_eat);
			pthread_mutex_lock(&rules->all_philos[i].state);
			if (routine_thread(&rules->all_philos[i], rules) == 1)
				return (NULL);
			pthread_mutex_unlock(&rules->all_philos[i].state);
			pthread_mutex_unlock(&rules->all_philos[i].time_eat);
			i++;
		}
	}
}
