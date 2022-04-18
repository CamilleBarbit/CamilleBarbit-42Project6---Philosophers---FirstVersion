/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/18 18:27:02 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	philo_is_dead(t_philo *philo, t_rules *rules)
// {
// 	if (pthread_mutex_lock(&rules->have_died) != 0)
// 		return (1);
// 	rules->are_dead = true;
// 	philo->status = 3; //philo is dead
// 	action(rules, philo, "died");
// 	usleep_eat_think(rules->time_to_die - get_diff(philo->time_last_meal));
// 	if (pthread_mutex_unlock(&rules->have_died) != 0)
// 		return (1);
// 	return (0);
// }

// int check_die(t_philo philo, t_rules rules)
// {
// 	if (get_diff(philo.time_last_meal) >= rules.time_to_die)
// 		return (1);
// 	return (0);
// }

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
			if (get_diff(rules->all_philos[i].time_last_meal) >= rules->time_to_die)
			{
				pthread_mutex_lock(&rules->have_died);
				if (rules->are_dead == false)
					rules->are_dead = true;
				if (action_dead(rules, &rules->all_philos[i], "died") == 1)
					return (NULL);
				pthread_mutex_unlock(&rules->have_died);
				return (NULL);
			}
			i++;
		}
	}
}
