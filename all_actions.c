/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:02:20 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/12 15:00:28 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.c"

void	ft_is_eating(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) != 0) //on envoie ce qu'il y a à cette adresse
        return (1);
    action(rules, philo, "has taken [left] fork"); //lock la fourchette de gauche
    if (pthread_mutex_lock(&rules->forks[philo->right_fork_id]) != 0)
        return (1);
    action(rules, philo, "has taken [right] fork"); //lock la fourchette de droite
    action(rules, philo, "is eating");
    if (usleep(rules->time_to_eat * 1000) != 0)
        return (1);
    if (pthread_mutex_unlock(&rules->forks[philo->right_fork_id]) != 0)
        return (1);
    if (pthread_mutex_unlock(&rules->forks[philo->left_fork_id]) != 0)
        return (1);
    
    
    
    if (check_philo_state(philo) == 1)
    {
        if (pthread_mutex_lock(&rules->has_died) != 0)
            return (1);
        rules->are_dead = 1;
        if (pthread_mutex_unlock(&rules->has_died) != 0)
            return (1);
        return (1);
    }
    rules->time_last_meal = get_time();
    rules->times_eaten += 1;



}

void	*ft_start(void *arg)
{
	t_philo	*philo; //la structure que j'envoie dans la fonction pthread_create
	t_rules	*rules;
	
	philo = (t_philo*)arg;
	rules = philo->rules;
	while(rules->are_dead)
	{

	}
	
}