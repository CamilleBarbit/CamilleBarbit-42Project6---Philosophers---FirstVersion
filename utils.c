/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:15:36 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/15 16:14:31 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	get_time()
{
	struct timeval  time;
	double	time_now;
	
	gettimeofday(&time, NULL); //il me dit à la compilation que la variable time n'est pas déclarée
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

double	get_diff(double time)
{
	double  i;
	double  diff;

	i = get_time();
	diff = i - time;
	return (diff);
}

void	usleep_eat_think(double time)
{
	double i;

	i = get_time(); //l'heure à laquelle je commence mon action
	while (get_time() - i < time)
		if (usleep(50) != 0)
			return;
}
