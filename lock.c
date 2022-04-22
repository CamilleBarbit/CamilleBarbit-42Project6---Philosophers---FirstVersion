/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:26:19 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/22 13:18:57 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	drop_forks(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_unlock(&rules->forks[philo->right_fork_id]) != 0)
		return (1);
	action(rules, philo, "has dropped [right] fork");
	if (pthread_mutex_unlock(&rules->forks[philo->left_fork_id]) != 0)
		return (1);
	action(rules, philo, "has dropped [left] fork");
	return (0);
}

int	grab_forks(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) == 0) //on envoie ce qu'il y a à cette adresse
 	{
		action(rules, philo, "has taken [left] fork");
		if (rules->nb_philos == 1)
			return (1);
		if (pthread_mutex_lock(&rules->forks[philo->right_fork_id]) != 0)
			return (pthread_mutex_unlock(&rules->forks[philo->left_fork_id]), 1);
		action(rules, philo, "has taken [right] fork"); //lock la fourchette de droite
		return (0);
	}
	return (1);
}