/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/31 14:15:52 by camillebarb      ###   ########.fr       */
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
	
	if (!(rules = malloc(sizeof(t_rules))))
		return (error("Malloc failed"), 1);
	if (argc != 5 && argc != 6)
		return(error("Wrong number of arguments"), 1);	
	if (parsing(argc, argv) == 1)
		return (error("Invalid argument(s)"), 1);
	if (init_basics(rules, argv) == 1)
		return (1);
	return (0);
}