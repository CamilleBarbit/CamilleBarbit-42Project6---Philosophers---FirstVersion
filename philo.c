/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/30 16:21:58 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_count(t_philo)
{
	int	i;

	i = 0
	while (i < 10)
	{
		printf("Le nombre est: %d\n", i);
		i++;
	}
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
}