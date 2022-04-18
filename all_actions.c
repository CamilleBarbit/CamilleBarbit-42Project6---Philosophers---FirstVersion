/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/18 16:04:48 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_eating(t_philo *philo, t_rules *rules)
{
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

// int	can_philo_eat(t_philo *philo, t_rules *rules)
// {
// 	if (grab_forks(philo, rules) == 1)
// 		return (1);
// 	if (get_diff(philo->time_last_meal) + rules->time_to_eat < rules->time_to_die)
// 		philo_is_eating(philo, rules);
// 	else
// 	{
// 		philo_is_dead(philo, rules);
// 		if (drop_forks(philo, rules) == 1)
// 			return (1);
// 		return (1);
// 	}
// 	philo_is_eating(philo, rules);
// 	if (drop_forks(philo, rules) == 1)
// 		return (1);
// 	return (0);
// }

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
	if (pthread_create(&rules->checker, NULL, ft_check_threads, &rules) != 0)
		return (NULL);
	if (pthread_mutex_lock(philo->dead) != 0)
		return (NULL);
	while(rules->are_dead == false && eaten_enough(philo, rules) != 0)
	{
		if (pthread_mutex_unlock(philo->dead) != 0)
			return (NULL);
		if (philo_is_eating(philo, rules) == 1)
			return (NULL);
		philo_is_sleeping(philo, rules);
		action(rules, philo, "is thinking");
	}
	if (pthread_join(rules->checker, NULL) != 0)
		return (NULL);
	return (NULL);
}

// void	*ft_start_daily_routine(void *arg)
// {
// 	t_rules	*rules;
	
// 	rules = (t_rules*)arg;
// 	if (pthread_create(&rules->checker, NULL, ft_check_threads, &rules) != 0)
// 		return (NULL);
// 	if (pthread_mutex_lock(rules->all_philos->dead) != 0)
// 		return (NULL);
// 	while(rules->are_dead == false && eaten_enough(rules->all_philos, rules) != 0)
// 	{
// 		if (pthread_mutex_unlock(rules->all_philos->dead) != 0)
// 			return (NULL);
// 		if (philo_is_eating(rules->all_philos, rules) == 1)
// 			return (NULL);
// 		philo_is_sleeping(rules->all_philos, rules);
// 		action(rules, rules->all_philos, "is thinking");
// 	}
// 	if (pthread_join(rules->checker, NULL) != 0)
// 		return (NULL);
// 	return (NULL);
// }

//rules->are_dead == false && eaten_enough(philo, rules) != 0
/*

*(philo->id_dead) : philo->is_dead est une adresse, 
donc pour avoir la valeur de la variable stockée à cette adresse, 
je mets * devant!

*/