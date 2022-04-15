/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/15 18:49:58 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(philo->dead) != 0)
		return (1);
	rules->are_dead = true;
	//philo->status = 3; //philo is dead
	action(rules, philo, "died");
	//usleep_eat_think(rules->time_to_die - get_diff(philo->time_last_meal));
	if (pthread_mutex_unlock(philo->dead) != 0)
		return (1);
	return (0);
}

int check_die(t_philo *philo, t_rules *rules)
{
	if (get_diff(philo->time_last_meal) >= rules->time_to_die)
		return (1);
	return (0);
}

void	*ft_check_threads(void *arg)
{
	t_rules	*rules;
	t_philo	*philo;
	int	i;
    
	rules = (t_rules*)arg;
	philo = rules->all_philos;
	while (1)
	{
		i = 0;
		while (i < rules->nb_philos)
		{
			if (check_die(&philo[i], rules) == 1)
			{
				if (philo_is_dead(&philo[i], rules) == 1)
					return (NULL);
				return (NULL);
			}
			i++;
		}
	}
}
