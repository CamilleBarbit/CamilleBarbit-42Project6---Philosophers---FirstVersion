/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:06 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/13 17:30:55 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int    is_philo_still_alive(t_philo *philo)
{
    double  time_now;
    t_rules *rules;
    
    rules = philo->rules;
    time_now = get_time();
    if (time_now >= philo->time_last_meal + rules->time_to_die)
    {
        philo->is_alive = true; //1 -> philo is dead
        if (pthread_mutex_lock(rules->has_died) != 0)
			return (1);
		rules->are_dead = 1; //1 -> un philo est mort
        action(rules, philo, "died");
		if (pthread_mutex_unlock(rules->has_died) != 0)
			return (1);
        return (1);
    }
    return (0);
}
