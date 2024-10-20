/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:59:26 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/21 01:10:55 by jvalle-d         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				n_of_philos;
	int				time_to_die;	//argv[2] = Tiempo que tienen max para comer antes de su muerte.
	int				time_to_eat;	//argv[3] = Tiempo que tardan en comer.
	int				time_to_sleep;	//argv[4] = Tiempo que tardan en dormir.
	int				meals_eaten;	//Optional	= Veces que han comido
	int				times_must_eat; //Optional	= argv[5] opcional, veces que debe de comer cada filosofo.
	int				left_fork;
	int				right_fork;
	long long				last_meal_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write_lock;
	struct s_philo 	*next;
}	philo;



#define NUM_PHILOSOPHERS = atoi(argv[1]);	//argv 1 = N de filosofos

//CREAR NODO
philo *create_node(int id);
//AÑADIR NODO AL FINAL DE LA LISTA ENLAZADA
void ft_lstadd_back(philo **lst, philo *new);
//IMPRIME POR PANTALLA LOS DATOS DE LOS ELEMENTOS DE LA ESTRUCTURA
void print_list_struct(philo **philosophers);

long long get_time_in_ms(void);


#endif