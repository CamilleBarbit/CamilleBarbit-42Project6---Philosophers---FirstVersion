/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:03 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/08 17:23:54 by cbarbit          ###   ########.fr       */
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
#include <stdbool.h>
#include <sys/time.h>

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
	double	time_last_meal;
	int	is_alive; //check if the philo is alive
	struct s_rules	*rules; //pk si je mets t_rules ça ne marche pas?
};

typedef struct s_rules  t_rules;
struct s_rules
{
	int	nb_philos; //argv[1]
	double	time_to_die; //argv[2] -> time_to_die + time_last_meal = is_dead
	double	time_to_eat; //argv[3]
	double	time_to_sleep;//argv[4]
	double	start_time; //indicateur du debut de lancement du programme
	int	times_must_eat;//argv[5] -> optional
	bool	eaten_all; //equals to 1 if all philo->times_eaten >= rules->times_must_eat
	bool	are_dead; //equals to 1 if at least one philo is dead
	pthread_mutex_t	*forks; //un tableau de mutexes (forks)
	pthread_mutex_t	*msg; //lock the messages
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
int	init_philos(t_rules *rules);
int	init_mutexes(t_rules *rules);

/*
UTILS
*/
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

void	*ft_count(void *arg);

#endif
