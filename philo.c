/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:36:26 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/12 10:59:29 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_count(void *arg)
{
	
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