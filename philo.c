/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/31 12:26:32 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count(void *arg)
{
	int	i;
	t_philo *philo;

	philo = (t_philo*)arg;
	i = 0;
	while (i < 10)
	{
		printf("Le nombre avant le thread est: %d\n", i);
		i++;
		printf("Le nombre après le thread est: %d\n", i);
	}
	printf("Le nombre de threads: %d\n", philo->rules->nb_philos);
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
	return (0);
}