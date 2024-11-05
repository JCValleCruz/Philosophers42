/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:15:08 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/05 11:36:38 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_forks(pthread_mutex_t *forks, int nofphilos)
{
	int i;

	i = 0;
	while(i < nofphilos)
		pthread_mutex_init(&forks[i++], NULL);
	
}

void	initialize_args(t_philo *ph, char **argv)
{
	ph->n_philo = ft_atoi(argv[1]);
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	ph->n_times_to_eat = -1;
	if (argv[5])
		ph->n_times_to_eat = ft_atoi(argv[5]);
}

void	initialize_philos(t_philo *ph, char **argv, t_prog *prog, pthread_mutex_t *forks)
{
	int i;
	
	i = 0;
	while(i < prog->philo_num)
	{
		arg_init(&ph[i], argv);
		ph[i].times_eaten = 0;
		ph[i].last_meal = get_time_in_ms();
		ph[i].meal_start = get_time_in_ms();
		ph[i].write_lock = &prog->write_lock;
		ph[i].eat_lock = &prog->meal_lock;
		ph[i].dead_lock = &prog->dead_lock;
		ph[i].id = i + 1;
		ph[i].dead = &prog->dead_flag;
		ph[i].l_fork = &forks[i];
		if (i == 0)
			ph[i].r_fork = &forks[ph[i].n_philo - 1];
		else
			ph[i].l_fork = &forks[i - 1];
		i++;
	}
}

void	initialize_program(t_prog *prog, t_philo *philos, char **argv)
{
	pthread_mutex_t forks[PHILO_MAX];
	prog->dead_flag = 0;
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	prog->philos = philos;
	prog->philo_num = ft_atoi(argv[1]);
	initialize_forks(forks, prog->philo_num);
	initialize_philos(philos, argv, prog, forks);
	thread_create(prog, forks);
	thread_destroy(prog, forks);
}