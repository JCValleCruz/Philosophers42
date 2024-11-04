/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:45:45 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/04 20:04:54 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_forks(t_philo *philo)									//Porque se hace inversamente, cuestionar.
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_action("has taken a fork", philo, philo->id, YELLOW);
		pthread_mutex_lock(philo->l_fork);
		print_action("has taken a fork", philo, philo->id, ORANGE);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_action("has taken a fork", philo, philo->id, ORANGE);
		pthread_mutex_lock(philo->r_fork);
		print_action("has taken a fork", philo, philo->id, YELLOW);
	}
}

void	eat(t_philo *philo)
{
	grab_forks(philo);
	philo->eating_flag = 1;
	print_action("is eating", philo, philo->id, GREEN);
	pthread_mutex_lock(philo->eat_lock);
	philo->last_meal = get_time_in_ms();
	philo->times_eaten++;
	pthread_mutex_unlock(philo->eat_lock);
}

void	*routine(void *ph)
{
	t_philo *philo;
	
	philo = (t_philo *)ph;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	if (philo->n_philo == 1)
	{
		print_action("has taken a fork", philo, philo->id, BLUE);
		ft_usleep(philo->time_to_die);
		return (ph);
	}
	while (live_loop(philo) == 1)
	{
		eat(philo);
		sleeping(philo);
		rave(philo);
	}
	return (ph);
}