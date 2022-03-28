/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:51 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/28 18:15:34 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_basics(t_rules *rules, char **argv)
{
	rules->nb_philo = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	rules->times_must_eat = 0;
	if (argv[5])
		rules->times_must_eat = atoi(argv[5]);
	if (rules->nb_philo < 1 || rules->nb_philo > 32768 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0 || rules->times_must_eat < 0)
		return (1);
	init_philo(rules, philo);
	return (0);	
}