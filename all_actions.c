/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/19 10:47:51 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_eating(t_philo *philo, t_rules *rules)
{
	// if (philo->philo_id % 2 == 1 && philo->times_eaten == 1) //ajouté
	// 	usleep(100);
	if (grab_forks(philo, rules) == 1)
		return (1);
	action(rules, philo, "is eating");
	// philo->status = 0; //le philo mange
	philo->time_last_meal = get_time(); //Update heure du début de dernier repas
	usleep_eat_think(rules->time_to_eat);
	philo->times_eaten++;
	if (drop_forks(philo, rules) == 1)
		return (1);
	return (0);
}

void	philo_is_sleeping(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is sleeping");
	// philo->status = 1; //le philo dort
	usleep_eat_think(rules->time_to_sleep);
}

void	*ft_start_daily_routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;
	if (pthread_mutex_lock(philo->dead) != 0)
		return (NULL);
	// if (philo->philo_id % 2 == 0) //ajouté
	// 	usleep(100);
	while(rules->are_dead == false && eaten_enough(philo, rules) != 0)
	{
		if (philo_is_eating(philo, rules) == 1)
			return (pthread_mutex_lock(philo->dead), NULL); //ajouté le lock
		philo_is_sleeping(philo, rules);
		action(rules, philo, "is thinking");
		if (rules->are_dead == true)
			return (pthread_mutex_unlock(philo->dead), NULL); //ajouté le unlock
		if (pthread_mutex_unlock(philo->dead) != 0)
			return (NULL);
	}
	return (NULL);
}