/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:03 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/08 11:12:16 by cbarbit          ###   ########.fr       */
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
	pthread_t	philo;
	int	left_fork_id;
	int	right_fork_id;
	int	times_eaten; //if there is a times_must_eat argument, we need to mornitor how many times each has eaten
	int	time_last_meal;
	struct s_rules	*rules; //pk si je mets t_rules ça ne marche pas?
};

typedef struct s_rules  t_rules;
struct s_rules
{
	int	nb_philos; //also corresponds to the nb of forks
	int	time_to_die; //time_to_die + time_last_meal = is_dead
	int	time_to_eat;
	int	time_to_sleep;
	int	times_must_eat;
	bool	eaten_all; //variable to check whether they have eaten enough
	bool	is_dead; //variable to check whether a philosopher is dead -> it's a boolean -> can be of type bool
	pthread_mutex_t	*forks; //un tableau de mutexes (forks)
	t_philo	*all_philos; //un tableau de struct de type t_philo
};

/*
FUNCTIONS FOR PARSING & ERRORS
*/
int		parsing(int argc, char **argv);
void	error(char *str);

/*
FUNCTIONS TO INITIALIZE PHILO
*/
int	init_basics(t_rules *rules, char **argv);
int		init_philos(t_rules *rules);
int		init_mutexes(t_rules *rules);

/*
UTILS
*/
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

void	*ft_count(void *arg);

#endif
