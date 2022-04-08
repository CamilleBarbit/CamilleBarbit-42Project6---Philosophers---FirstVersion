/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/08 16:27:08 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count(void *arg)
{
	//int	i;
	t_philo *philo;
	//(void)arg;
	philo = (t_philo*)arg;
	//i = 0;
	// while (i < 10)
	// {
	// 	printf("Le nombre est: %d\n", i);
	// 	i++;
	// }
	printf("L'ID du thread': %d\n", philo->philo_id);
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
		return (1);
	return (0);
}