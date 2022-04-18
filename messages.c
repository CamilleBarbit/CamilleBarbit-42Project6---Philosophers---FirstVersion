/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:32:55 by camillebarb       #+#    #+#             */
/*   Updated: 2022/04/18 18:31:47 by cbarbit          ###   ########.fr       */
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
	if (rules->are_dead == true)
	{
		//printf("value is dead: %i\n", rules->are_dead);
		//printf("over\n");
		pthread_mutex_unlock(philo->state);
		return (1);
	}
	printf("COUCOU\n");
	printf("[%ld] ", (get_time() - rules->start_time)); //pour calculer le timestamp
	printf("%d ", philo->philo_id);
	printf("%s\n", str);
	if (pthread_mutex_unlock(philo->state) != 0)
		return (1);
	return (0);
}

int	action_dead(t_rules *rules, t_philo *philo, char *str)
{
	if (pthread_mutex_lock(philo->state) != 0)
		return (1);
	printf("[%ld] ", (get_time() - rules->start_time)); //pour calculer le timestamp
	printf("%d ", philo->philo_id);
	printf("%s\n", str);
	if (pthread_mutex_unlock(philo->state) != 0)
		return (1);
	return (0);
}