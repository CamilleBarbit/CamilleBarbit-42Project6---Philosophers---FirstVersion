/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:32:55 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/15 12:09:12 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *str)
{
	int i;

	i = 0;
	write(2, "Error:\n", 7);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	action(t_rules *rules, t_philo *philo, char *str)
{
	if (pthread_mutex_lock(philo->state) != 0)
		return (1);
	printf("%f ", (get_time() - rules->start_time)); //pour calculer le timestamp
	printf("%d ", philo->philo_id);
	printf("%s\n", str);
	if (pthread_mutex_unlock(philo->state) != 0)
		return (1);
	return (0);
}
