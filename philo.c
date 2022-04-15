/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/15 16:52:06 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dispatch_philos(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_create(&rules->checker, NULL, &ft_check_threads, &rules) != 0)
		return (1);
	rules->start_time = get_time();
	while (i < rules->nb_philos)
	{
		rules->all_philos[i].time_last_meal = rules->start_time;
		if (pthread_create(&rules->all_philos[i].philo, NULL, &ft_start_daily_routine, &rules->all_philos[i]) != 0)
			return (1);
		i += 1;
	}
	/*i = 1;
	while (i < rules->nb_philos)
	{
		rules->all_philos[i].time_last_meal = rules->start_time;
		if (pthread_create(&rules->all_philos[i].philo, NULL, &ft_start_daily_routine, &rules->all_philos[i]) != 0)
			return (1);
		i += 2;
	}*/
	return (0);
}

	
int	main(int argc, char **argv)
{
	t_rules *rules;
	int	i;
	
	if (argc != 5 && argc != 6)
		return(error("Wrong number of arguments\n"), 1);	
	if (parsing(argc, argv) == 1)
		return (error("Invalid argument(s)\n"), 1);
	if (!(rules = malloc(sizeof(t_rules))))
		return (error("Malloc failed\n"), 1);
	if (init_basics(rules, argv) == 1)
		return (error("Failed initialising variables\n"), 1);
	if (dispatch_philos(rules) == 1)
		return (1);
	i = 0;
	while (i < rules->nb_philos)
		if (pthread_join(rules->all_philos[i++].philo, NULL) != 0)
			return (1);
	if (pthread_join(rules->checker, NULL) != 0)
			return (1);
	return (0);
}