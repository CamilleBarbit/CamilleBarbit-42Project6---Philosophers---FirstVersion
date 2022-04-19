/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:15:36 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/19 11:17:18 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct timeval  time;
	long	time_now;
	
	gettimeofday(&time, NULL);
	time_now = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_now);
}

int	eaten_enough(t_philo *philo, t_rules *rules)
{
	if (rules->times_must_eat == -1)
		return (1);
	else if (philo->times_eaten < rules->times_must_eat)
		return (1);
	return (0);
}

long	get_diff(long time)
{
	long  i;
	long  diff;

	i = get_time();
	//printf("TIME: %ld\n", i);
	diff = i - time;
	printf("DIFF TIME_NOW - TIME_LAST_EAT: %ld\n", diff);	
	return (diff);
}

void	usleep_eat_think(long time)
{
	long	time_now;

	time_now = get_time();
	while (get_time() - time_now < time)
		usleep(500);
}
