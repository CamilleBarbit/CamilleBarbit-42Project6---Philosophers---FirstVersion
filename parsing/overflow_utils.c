/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:35:35 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/28 16:35:40 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_count_char(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n = n * -1;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;

	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	i = ft_count_char(n);
	string = malloc(sizeof(char) * i + 1);
	if (!string)
		return (NULL);
	string[i] = '\0';
	i--;
	if (n == 0)
		string[i] = 48;
	if (n < 0)
	{
		n = n * -1;
		string[0] = '-';
	}
	while (n > 0)
	{
		string[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (string);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}