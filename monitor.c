/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:43:02 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/05 11:52:33 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		live_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (0);		
	}
	pthread_mutex_unlock(philo->dead);
	return (1);	
}

int	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_lock);
	if (get_time_in_ms() - philo->last_meal >= philo->time_to_die
		&& philo->eating_flag == 0)
	{
		pthread_mutex_unlock(philo->eat_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_lock);
	return (0);	
}

int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		if (philo_is_dead(&philo[i]))
		{
			print_action("died", &philo[i], philo[i].id, RED);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_ate(t_philo *philo)
{
	int	i;
	int	full_count;

	i = 0;
	full_count = 0;
	if (philo->n_times_to_eat == -1)
		return (0);
	while (i < philo->n_philo)
	{
		pthread_mutex_lock(philo[i].eat_lock);
		if (philo[i].times_eaten >= philo[i].n_times_to_eat)
			full_count++;
		pthread_mutex_unlock(philo[i].eat_lock);
		i++;
	}
	if (full_count == philo[0].n_philo)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

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




