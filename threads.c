/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:47:42 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/07 11:24:35 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thread_destroy(t_prog *prog, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < prog->philo_num)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
}

void	thread_create(t_prog *prog, pthread_mutex_t *forks)
{
	pthread_t	threaddirector;
	int			i;

	i = 0;
	if (pthread_create(&threaddirector, NULL, &monitor, prog->philos) != 0)
		thread_destroy(prog, forks);
	while (i < prog->philo_num)
	{
		if (pthread_create(&prog->philos[i].thread, NULL,
				&routine, &prog->philos[i]) != 0)
			thread_destroy(prog, forks);
		i++;
	}
	if (pthread_join(threaddirector, NULL) != 0)
		thread_destroy(prog, forks);
	i = 0;
	while (i < prog->philo_num)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			thread_destroy(prog, forks);
		i++;
	}
}
