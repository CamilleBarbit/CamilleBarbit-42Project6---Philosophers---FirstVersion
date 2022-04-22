/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:26:19 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/22 15:47:36 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_forks(t_philo *philo, t_rules *rules)
{
	if (philo->philo_id % 2 == 0)
	{
		if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) != 0)
			return (1);
		action(rules, philo, "has taken a fork");
		if (pthread_mutex_lock(&rules->forks[philo->right_fork_id]) != 0)
		{
			pthread_mutex_unlock(&rules->forks[philo->left_fork_id]);
			return (1);
		}
		action(rules, philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(&rules->forks[philo->right_fork_id]) != 0)
			return (1);
		action(rules, philo, "has taken a fork");
		if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) != 0)
		{
			pthread_mutex_unlock(&rules->forks[philo->right_fork_id]);
			return (1);
		}
		action(rules, philo, "has taken a fork");
	}
	return (0);
}

int	drop_forks(t_philo *philo, t_rules *rules)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(&rules->forks[philo->right_fork_id]);
		pthread_mutex_unlock(&rules->forks[philo->left_fork_id]);
	}
	else
	{
		pthread_mutex_unlock(&rules->forks[philo->left_fork_id]);
		pthread_mutex_unlock(&rules->forks[philo->right_fork_id]);
	}
	return (0);
}
