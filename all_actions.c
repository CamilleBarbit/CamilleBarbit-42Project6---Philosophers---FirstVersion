/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/12 19:09:07 by camillebarb      ###   ########.fr       */
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

void	philo_is_eating(t_philo *philo, t_rules *rules)
{
	if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) != 0) //on envoie ce qu'il y a à cette adresse
        return (1);
    action(rules, philo, "has taken [left] fork"); //lock la fourchette de gauche
    if (pthread_mutex_lock(&rules->forks[philo->right_fork_id]) != 0)
        return (1);
    action(rules, philo, "has taken [right] fork"); //lock la fourchette de droite
    action(rules, philo, "is eating"); //il est entrain de manger
	philo->time_last_meal = get_time(); //Update heure du début de dernier repas
	usleep_eat_think(rules, rules->time_to_eat);
	philo->times_eaten++;
	if (pthread_mutex_unlock(&rules->forks[philo->left_fork_id]) != 0)
		return (1);
	if (pthread_mutex_unlock(&rules->forks[philo->right_fork_id]) != 0)
		return (1);	
	if (philo->times_eaten == rules->times_must_eat) //we will have to do something
}

void	philo_is_sleeping(t_philo *philo, t_rules *rules)
{
	action(rules, philo, "is sleeping");
	usleep_eat_think(rules, rules->time_to_sleep);
}

void	*ft_start(void *arg)
{
	t_philo	*philo; //la structure que j'envoie dans la fonction pthread_create
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;

	while(rules->are_dead == false)
	{
		philo_is_eating(philo, rules);
	}
	
}