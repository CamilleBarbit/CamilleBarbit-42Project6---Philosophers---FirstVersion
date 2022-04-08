/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:51 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/08 17:26:33 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_rules *rules)
{
	int	i;
	
	i = 0;
	if (!(rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos)))
		return (error("Malloc failed\n"), 1);
	while (i < rules->nb_philos)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (error("Failed to init mutexes\n"), 1);
		i++;
	}
	if (pthread_mutex_init(rules->msg, NULL) != 0)
		return (error("Failed to init mutexes\n"), 1); 
	return (0);
}

int	init_philos(t_rules *rules)
{
	int	i;

	i = 0;
	if (!(rules->all_philos = malloc(sizeof(t_philo) * rules->nb_philos)))
		return (error("Malloc failed\n"), 1);
	while (i < rules->nb_philos)
	{
		rules->all_philos[i].philo_id = i + 1;
		rules->all_philos[i].left_fork_id = i;
		if (i == 0)
			rules->all_philos[i].right_fork_id = rules->nb_philos - 1;
		else
			rules->all_philos[i].right_fork_id = i - 1;
		rules->all_philos[i].times_eaten = 0;
		rules->all_philos[i].time_last_meal = rules->start_time; //Au debut on prend le temps du debut de la simulation
		// if (pthread_create(&rules->all_philos[i].philo, NULL, ft_count, &rules->all_philos[i]) != 0) //not sure about creating all the threads here
		// 	return (1);
		// usleep(100); il ne faut pas lancer les threads en même temps
		i++;
	}
	return (0);
}

double	get_time(t_rules *rules)
{
	struct timeval	*time;
	double	time_now;
	
	gettimeofday(time, NULL);
	time_now = ((time->tv_sec * 1000) + (time->tv_usec / 1000));
	return (time_now);
}

int	init_basics(t_rules *rules, char **argv)
{
	rules->nb_philos = atoi(argv[1]); //en millisecondes
	rules->time_to_die = atoi(argv[2]); //en millisecondes
	rules->time_to_eat = atoi(argv[3]); //en millisecondes
	rules->time_to_sleep = atoi(argv[4]); //en millisecondes
	rules->start_time = get_time(rules); //en millisecondes
	rules->eaten_all = false;
	rules->are_dead = false;
	if (rules->nb_philos < 1 || rules->nb_philos > 62464 || rules->time_to_die <= 0
		|| rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
		return (error("Invalid argument value\n"), 1);
	if (argv[5])
	{
		rules->times_must_eat = atoi(argv[5]);
		if (rules->times_must_eat <= 0)
			return (error("Invalid argument value\n"), 1);	
	}
	else
		rules->times_must_eat = 0;
	if (init_mutexes(rules) == 1)
		return (1);
	if (init_philos(rules) == 1)
		return (1);
	return (0);	
}
