/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:00:03 by camillebarb       #+#    #+#             */
/*   Updated: 2022/03/28 15:49:36 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_rules *rules;

    if (argc != 5 && argc != 6)
        return(error("Wrong number of arguments"), 1);
    if (parsing(argc, argv) == 1)
        return (error("Invalid argument(s)"), 1);
}