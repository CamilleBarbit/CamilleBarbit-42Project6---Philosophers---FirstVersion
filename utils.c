/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:15:36 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/13 14:58:49 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	get_time()
{
	struct timeval	*time;
	double	time_now;
	
	gettimeofday(time, NULL);
	time_now = ((time->tv_sec * 1000) + (time->tv_usec / 1000));
	return (time_now);
}