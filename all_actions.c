/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/14 14:34:10 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

void	philo_is_eating(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is eating");
	philo->status = 0; //il mange //est-ce important?
	philo->time_last_meal = get_time(); //Update heure du début de dernier repas
	usleep_eat_think(rules, rules->time_to_eat);
	philo->times_eaten++;
}

int	can_philo_eat(t_philo *philo, t_rules *rules)
{
	if (grab_forks(philo, rules) == 1)
		return (1);
	if (get_diff(rules->time_last_meal) + rules->time_to_eat < rules->time_to_die) //to change
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
	philo->status = 1; //il dort
	usleep_eat_think(rules, rules->time_to_sleep);
}

void	*ft_start_daily_routine(void *arg)
{
	t_philo	*philo; //la structure que j'envoie dans la fonction pthread_create
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;

	while(*(philo->is_dead) == false && eaten_enough(philo, rules) != 0)
	{
		if (philo_is_eating(philo, rules) == 1)
			return (NULL);
		philo_is_sleeping(philo, rules);
		if (philo->status != 0)
			action(rules, philo, "is thinking");
	}
	return (NULL);
}

/*

*(philo->id_dead) : philo->is_dead est une adresse, 
donc pour avoir la valeur de la variable stockée à cette adresse, 
je mets * devant!

*/