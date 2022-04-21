/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/21 11:59:45 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_threads(void *arg)
{
	t_rules	*rules;
	int	i;
    
	rules = (t_rules*)arg;
	while (1)
	{
		i = 0;
		//usleep(100);
		while (i < rules->nb_philos)
		{
			if (pthread_mutex_lock(&rules->all_philos[i].nb_meals) != 0)
				return (NULL);
			if (rules->all_philos[i].times_eaten == rules->times_must_eat)
				return (NULL);
			if (pthread_mutex_unlock(&rules->all_philos[i].nb_meals) != 0)
				return (NULL);
			if (pthread_mutex_lock(&rules->all_philos[i].time_eat) != 0)
				return (NULL);
			if (pthread_mutex_lock(&rules->all_philos[i].state) != 0)
				return (NULL);
			if ((get_diff(rules->all_philos[i].time_last_meal) >= rules->time_to_die))
			{
				if (pthread_mutex_unlock(&rules->all_philos[i].state) != 0)
					return (NULL);
				if (pthread_mutex_unlock(&rules->all_philos[i].time_eat) != 0)
					return (NULL);	
				pthread_mutex_lock(&rules->have_died);
				if (rules->are_dead == false)
					rules->are_dead = true;
				pthread_mutex_unlock(&rules->have_died);
				if (action_dead(rules, &rules->all_philos[i], "died") == 1)
					return (NULL);
				return (NULL);
			}
			if (pthread_mutex_unlock(&rules->all_philos[i].state) != 0)
				return (NULL);
			if (pthread_mutex_unlock(&rules->all_philos[i].time_eat) != 0)
				return (NULL);
			i++;
		}
	}
}

// && rules->all_philos[i].status != 0