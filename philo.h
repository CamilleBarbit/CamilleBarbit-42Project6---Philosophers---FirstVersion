/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:03 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/28 17:52:20 by camillebarb      ###   ########.fr       */
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
#include <stdlib.h>

/*
MAIN STRUCTURES
*/
typedef struct s_philo t_philo;
struct s_philo
{
	int	philo_id;
	int	left_fork_id;
	int	right_fork_id;
	int	times_eaten; //if there is a times_must_eat argument, we need to mornitor how many times each has eaten
	int	times_last_meal;
}

typedef struct s_rules  t_rules;
struct s_rules
{
	int	nb_philo; //also corresponds to the nb of forks
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
	
};

/*
FUNCTIONS FOR PARSING & ERRORS
*/
int		parsing(int argc, char **argv);
void	error(char *str);

/*
FUNCTIONS TO INITIALIZE PHILO
*/
void	init_basics(t_rules *rules, char **argv);

/*
UTILS
*/
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif