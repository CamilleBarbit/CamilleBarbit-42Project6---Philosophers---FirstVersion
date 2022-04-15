/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/15 15:19:29 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(philo->dead) != 0)
		return (1);
	*(philo->is_dead) = true;
	philo->status = 3; //philo is dead
	action(rules, philo, "died");
	usleep_eat_think(rules->time_to_die - get_diff(philo->time_last_meal));
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
