/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:47:42 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/30 19:37:34 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *ph)
{
	t_philo *philos;

	philos = (t_philo *)ph;
	while (1)
	{
		if(check_dead(philos) == 1 || all_ate(philos) == 1)
			return (ph);
	}
	return (ph);
}

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
	if(pthread_create(&boss, NULL, &monitor, prog->philos) != 0)
		thread_destroy(prog, forks);
	i++;	
}