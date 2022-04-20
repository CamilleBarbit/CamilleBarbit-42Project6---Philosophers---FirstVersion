/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:31:00 by cbarbit           #+#    #+#             */
/*   Updated: 2022/04/20 14:40:07 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
LIBRARIES
*/
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

/*
MAIN STRUCTURES
*/
typedef struct s_philo	t_philo;
struct s_philo
{
	int				philo_id;
	int				left_fork_id;
	int				right_fork_id;
	int				times_eaten;
	int				status;
	long			time_last_meal;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*philo_msg;
	pthread_mutex_t	state;
	pthread_mutex_t	time_eat;
	pthread_t		philo;
	struct s_rules	*rules;
};

typedef struct s_rules	t_rules;
struct s_rules
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	int				times_must_eat;
	bool			eaten_all;
	bool			are_dead;
	pthread_mutex_t	have_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_t		checker;
	t_philo			*all_philos;
};

/*
FUNCTIONS FOR PARSING & ERRORS
*/
int		parsing(int argc, char **argv);
void	error(char *str);

/*
FUNCTIONS TO INITIALIZE PHILO
*/
int		init_basics(t_rules *rules, char **argv);
int		init_philos(t_rules *rules);
int		dispatch_philos(t_rules *rules);
int		init_main_mutexes(t_rules *rules);

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
void	*ft_check_threads(void *arg);
void	usleep_eat_think(long time);
int		philo_is_sleeping(t_philo *philo, t_rules *rules);
int		philo_is_eating(t_philo *philo, t_rules *rules);
int		eaten_enough(t_philo *philo, t_rules *rules);
int		grab_forks(t_philo *philo, t_rules *rules);
int		drop_forks(t_philo *philo, t_rules *rules);
int		action(t_rules *rules, t_philo *philo, char *str);
int		philo_is_dead(t_philo *philo, t_rules *rules);
int		check_die(t_philo philo, t_rules rules);
int		action_dead(t_rules *rules, t_philo *philo, char *str);
int		odd_philos(t_rules *rules);
int		even_philos(t_rules *rules);
/*
ROUTINE UTILS
*/
long	get_time(void);
long	get_diff(long time);

#endif
