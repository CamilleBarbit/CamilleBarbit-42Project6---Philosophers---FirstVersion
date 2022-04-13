/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:26:19 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/13 17:26:38 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_forks(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) != 0) //on envoie ce qu'il y a à cette adresse
 		return (1);
	action(rules, philo, "has taken [left] fork"); //lock la fourchette de gauche
	if (pthread_mutex_lock(&rules->forks[philo->right_fork_id]) != 0)
		return (1);
	action(rules, philo, "has taken [right] fork"); //lock la fourchette de droite
	return (0);
}

int	drop_forks(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_unlock(&rules->forks[philo->left_fork_id]) != 0)
		return (1);
	action(rules, philo, "has dropped [left] fork");
	if (pthread_mutex_unlock(&rules->forks[philo->right_fork_id]) != 0)
		return (1);
	action(rules, philo, "has dropped [right] fork");
	return (0);
}