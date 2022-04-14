/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/14 14:34:23 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(philo->dead) != 0)
		return (1);
	*(philo->is_dead) = true;
	action(rules, philo, "died");
	usleep_eat_think(rules, rules->time_to_die - get_diff(rules->time_last_meal));
	if (pthread_mutex_unlock(philo->dead) != 0)
		return (1);
	return (0);
}

void	*ft_check_threads(void *arg)
{
	t_rules	*rules;
    
	rules = (t_rules*)arg;
	while (1)
	{
	if (pthread_mutex_lock(&rules->have_died) != 0)
		return (NULL);
	if (rules->are_dead == true)
		return(NULL);
	if (pthread_mutex_unlock(&rules->have_died) != 0)
		return (NULL);
	}
}
