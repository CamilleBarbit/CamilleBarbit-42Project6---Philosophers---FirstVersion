/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/13 14:58:32 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dispatch_philos(t_rules *rules)
{
	int	i;

	rules->start_time = get_time(); //en millisecondes -> début de la simulation
	i = 0;
	while (i < rules->nb_philos)
	{
		if (pthread_create(&rules->all_philos[i].philo, NULL, ft_start, &rules->all_philos[i]) != 0)
			return (1);
		i += 2;
	}
	i = 1;
	while (i < rules->nb_philos)
	{
		if (pthread_create(&rules->all_philos[i].philo, NULL, ft_start, &rules->all_philos[i]) != 0)
			return (1);
		i += 2;
	}
	return (0);
}

	
int	main(int argc, char **argv)
{
	t_rules *rules;
	
	if (argc != 5 && argc != 6)
		return(error("Wrong number of arguments\n"), 1);	
	if (parsing(argc, argv) == 1)
		return (error("Invalid argument(s)\n"), 1);
	if (!(rules = malloc(sizeof(t_rules))))
		return (error("Malloc failed\n"), 1);
	if (init_basics(rules, argv) == 1)
		return (error("Failed initialising variables\n")1);
	if (dispatch_philos(rules) == 1)
		return (1);
	return (0);
}