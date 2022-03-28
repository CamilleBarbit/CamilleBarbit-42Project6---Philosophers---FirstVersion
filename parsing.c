/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:20:19 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/28 16:20:20 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	arg_is_digit(char *str, int i)
{
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
}

static int	arg_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (arg_is_digit(str, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	check_overflow(char *str1)
{
	int		nb;
	char	*str2;

	nb = ft_atoi(str1);
	str2 = ft_itoa(nb);
	if (ft_strcmp(str1, str2) != 0)
		return (free(str2), 1);
	free(str2);
	return (0);
}

int	parsing(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (arg_is_valid(argv[i]) == 1)
			return (1);
		if (check_overflow(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}