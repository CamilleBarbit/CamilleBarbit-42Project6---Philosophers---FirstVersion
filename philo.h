/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:03 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/14 12:03:52 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
LIBRARIES
*/
#include <pthread.h>
#include <unistd.h>
#include <string.h>
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
	int	status;
	double	time_last_meal; //need to be updated everytime the philo eats //at first, it is equal to start_time
	bool	*is_dead; //if philo dead -> he modifies the rules->are_dead directly
	pthread_mutex_t	*dead; //mutex qui protège le booléen is_alive -> le thread checker et le thred philo y ont accès
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
	pthread_mutex_t	have_died; //mutex qui protège le booléen are_dead ->seul le thread checker y a accès
	pthread_mutex_t	*forks; //un tableau de mutexes (forks)
	pthread_mutex_t	*msg; //lock the messages
	pthread_t	checker;
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
int	dispatch_philos(t_rules *rules);
int	init_main_mutexes(t_rules *rules);

/*
PARSING UTILS
*/
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

/*
DAILY ROUTINE
*/
void	*ft_start_daily_routine(void *arg);
void	usleep_eat_think(t_rules *rules, double time);
void	philo_is_sleeping(t_philo *philo, t_rules *rules);
void	philo_is_eating(t_philo *philo, t_rules *rules);
int		can_philo_eat(t_philo *philo, t_rules *rules);
int 	eaten_enough(t_philo *philo, t_rules *rules);
int		grab_forks(t_philo *philo, t_rules *rules);
int		drop_forks(t_philo *philo, t_rules *rules);
int		action(t_rules *rules, t_philo *philo, char *str);

/*
UTILS
*/
double	get_time();
double	get_diff(double time);

#endif
