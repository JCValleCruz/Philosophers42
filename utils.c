/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:45:30 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/18 23:11:04 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(philo *philosophers, char **argv)
{
	philosophers->n_of_philos = atoi(argv[1]);
	philosophers->time_to_die = atoi(argv[2]);	
	philosophers->time_to_eat = atoi(argv[3]);
	philosophers->time_to_sleep	= atoi(argv[4]);
	philosophers->last_meal_time = get_time_in_ms();	
}

void	print_struct(philo *philosophers)
{
	printf("N of Philos:%d\nTime to die:%d\nTime to eat:%d\nTime to sleep:%d\n",philosophers->n_of_philos, philosophers->time_to_die,
	philosophers->time_to_eat, philosophers->time_to_sleep);
}

size_t	get_time_in_ms(void)
{
	struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000LL) + (time.tv_usec / 1000LL);
}