/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/15 17:05:36 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(philo->dead) != 0)
		return (1);
	rules->are_dead = true;
	philo->status = 3; //philo is dead
	action(rules, philo, "died");
	usleep_eat_think(rules->time_to_die - get_diff(philo->time_last_meal));
	if (pthread_mutex_unlock(philo->dead) != 0)
		return (1);
	return (0);
}

int check_die(t_philo *philo, t_rules *rules)
{
	return (get_diff(philo->time_last_meal) >= rules->time_to_die);
}

void	*ft_check_threads(void *arg)
{
	t_rules	*rules;
	int	i;
    
	rules = (t_rules*)arg;
	while (1)
	{
		i = 0;
		while (i < nbdephilo)
		{
			if check_die(philo, rules)
				philo_is_dead(t_philo *philo, t_rules *rules)
			i++;
		}
		if (pthread_mutex_lock(&rules->have_died) != 0)
			return (NULL);
		if (rules->are_dead == true)
			return (NULL);
		if (pthread_mutex_unlock(&rules->have_died) != 0)
			return (NULL);
	}
}

2

200
100
200

0 is eating
100 is sleeping
300 is died