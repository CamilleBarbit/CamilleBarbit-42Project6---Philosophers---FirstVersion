/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/15 16:52:37 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_is_eating(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is eating");
	philo->status = 0; //le philo mange
	philo->time_last_meal = get_time(); //Update heure du début de dernier repas
	usleep_eat_think(rules->time_to_eat);
	philo->times_eaten++;
}

int	can_philo_eat(t_philo *philo, t_rules *rules)
{
	if (grab_forks(philo, rules) == 1)
		return (1);
	if (get_diff(philo->time_last_meal) + rules->time_to_eat < rules->time_to_die)
		philo_is_eating(philo, rules);
	else
	{
		philo_is_dead(philo, rules);
		if (drop_forks(philo, rules) == 1)
			return (1);
		return (1);
	}
	if (drop_forks(philo, rules) == 1)
		return (1);
	return (0);
}

void	philo_is_sleeping(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is sleeping");
	philo->status = 1; //le philo dort
	usleep_eat_think(rules->time_to_sleep);
}

void	*ft_start_daily_routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;
	
	while(rules->are_dead == false && eaten_enough(philo, rules) != 0)
	{
		if (can_philo_eat(philo, rules) == 1)
			return (NULL);
		philo_is_sleeping(philo, rules);
		if (philo->status != 0)
		{
			philo->status = 2; //le philo pense
			action(rules, philo, "is thinking");
		}
	}
	return (NULL);
}

/*

*(philo->id_dead) : philo->is_dead est une adresse, 
donc pour avoir la valeur de la variable stockée à cette adresse, 
je mets * devant!

*/