/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:59:26 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/18 23:09:36 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philosophers
{
	int				n_of_philos;
	int				time_to_die;	//argv[2] = Tiempo que tienen max para comer antes de su muerte.
	int				time_to_eat;	//argv[3] = Tiempo que tardan en comer.
	int				time_to_sleep;	//argv[4] = Tiempo que tardan en dormir.
	int				meals_eaten;	//Optional	= Veces que han comido
	int				times_must_eat; //Optional	= argv[5] opcional, veces que debe de comer cada filosofo.
	int				id;
	int				left_fork;
	int				right_fork;
	size_t			last_meal_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write_lock;
}	philo;



#define NUM_PHILOSOPHERS = atoi(argv[1]);	//argv 1 = N de filosofos

void	init_philo(philo *philosophers, char **argv);
size_t	get_time_in_ms(void);
void	print_struct(philo *philosophers);

#endif