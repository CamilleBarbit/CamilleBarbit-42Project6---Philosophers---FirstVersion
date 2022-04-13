/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/13 14:58:03 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

void	usleep_eat_think(t_rules *rules, double time)
{
	double i;

	i = get_time();
	while (rules->are_dead == 0 && get_time() - i < time)
		usleep(50);
}

int	philo_is_eating(t_philo *philo, t_rules *rules)
{
	if (grab_forks(philo, rules) == 1)
		return (1);
	action(rules, philo, "is eating");
	philo->time_last_meal = get_time(); //Update heure du début de dernier repas
	usleep_eat_think(rules, rules->time_to_eat);
	philo->times_eaten++;
	if (drop_forks(philo, rules) == 1)
		return (1);
	//if (philo->times_eaten == rules->times_must_eat) //we will have to do something
	return (0);
}

void	philo_is_sleeping(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is sleeping");
	usleep_eat_think(rules, rules->time_to_sleep);
}

void	*ft_start_daily_routine(void *arg)
{
	t_philo	*philo; //la structure que j'envoie dans la fonction pthread_create
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;

	while(philo->is_alive == false)
	{
		if (philo_is_eating(philo, rules) == 1)
			return (NULL);
		philo_is_sleeping(philo, rules);
		action(rules, philo, "is thinking");
	}
	
}