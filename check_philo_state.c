/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/22 14:37:48 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&philo->nb_meals);
	if (philo->times_eaten == rules->times_must_eat)
		return (pthread_mutex_unlock(&philo->nb_meals), 1);
	pthread_mutex_unlock(&philo->nb_meals);
	return (0);
}

void	modify_death_status(t_rules *rules)
{
	pthread_mutex_lock(&rules->have_died);
	if (rules->are_dead == false)
		rules->are_dead = true;
	pthread_mutex_unlock(&rules->have_died);
}
			
void	*ft_check_threads(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	while (1)
	{
		i = 0;
		while (i < rules->nb_philos)
		{
			if (check_meals(&rules->all_philos[i], rules) == 1)
				return (NULL);
			pthread_mutex_lock(&rules->all_philos[i].time_eat);
			pthread_mutex_lock(&rules->all_philos[i].state);
			if ((get_diff(rules->all_philos[i].time_last_meal) >= rules->time_to_die))
			{
				pthread_mutex_unlock(&rules->all_philos[i].state);
				pthread_mutex_unlock(&rules->all_philos[i].time_eat);
				modify_death_status(rules);
				if (action_dead(rules, &rules->all_philos[i], "died") == 1)
					return (NULL);
				return (NULL);
			}
			pthread_mutex_unlock(&rules->all_philos[i].state);
			pthread_mutex_unlock(&rules->all_philos[i].time_eat);
			i++;
		}
	}
}