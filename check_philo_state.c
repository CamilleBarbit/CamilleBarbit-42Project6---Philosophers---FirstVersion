/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/19 11:55:11 by cbarbit          ###   ########.fr       */
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
			if (get_diff(rules->all_philos[i].time_last_meal) >= (rules->time_to_die + 10) && rules->all_philos[i].status != 0)
			{
				pthread_mutex_lock(&rules->have_died);
				if (rules->are_dead == false)
					rules->are_dead = true;
				//printf("Philo ID: %d\n", rules->all_philos[i].philo_id);
				//printf("Time to die: %ld\n", rules->time_to_die);
				//printf("Time since last meal: %ld\n", get_diff(rules->all_philos[i].time_last_meal));
				if (action_dead(rules, &rules->all_philos[i], "died") == 1)
					return (NULL);
				pthread_mutex_unlock(&rules->have_died);
				return (NULL);
			}
			i++;
		}
	}
}
