/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:47:42 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/30 19:43:22 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thread_destroy(t_prog *prog, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while(i < prog->philo_num)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);	
}

void	thread_create(t_prog *prog, pthread_mutex_t *forks)
{
	pthread_t	boss;
	int			i;

	i = 0;
	if (pthread_create(&boss, NULL, &monitor, prog->philos) != 0)
		thread_destroy(prog, forks);
	while (i < prog->philo_num)
	{
		if (pthread_create(&prog->philos[i].thread, NULL, &routine, &prog->philos[i]) != 0)
			thread_destroy(prog, forks);
		i++;	
	}
}