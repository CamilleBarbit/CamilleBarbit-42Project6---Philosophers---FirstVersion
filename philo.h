/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:03 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/28 14:28:34 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
LIBRARIES
*/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

/*
MAIN STRUCTURE
*/
typedef struct s_rules  t_rules;
struct s_rules
{
	int	nb_philo; //also corresponds to the nb of forks
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
	
};

#endif