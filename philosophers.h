/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:59:26 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/23 12:56:19 by jvalle-d         ###   ########.fr       */
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

# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[37;1m"

typedef struct s_philo
{
	int					id;
	int					n_of_philos;
	int					time_to_die;	//argv[2] = Tiempo que tienen max para comer antes de su muerte.
	int					time_to_eat;	//argv[3] = Tiempo que tardan en comer.
	int					time_to_sleep;	//argv[4] = Tiempo que tardan en dormir.
	int					meals_eaten;	//Optional	= Veces que han comido
	int					times_must_eat; //Optional	= argv[5] opcional, veces que debe de comer cada filosofo.
	pthread_mutex_t		lfork;			//Mutex left fork
	pthread_mutex_t		rfork;			//Mutex right fork	
	pthread_mutex_t		*forks;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*eat_lock;
	int					left_fork;
	int					right_fork;
	size_t				meal_start;
	size_t				last_meal_time;
	size_t				start;
	pthread_t			own;
	pthread_t			director;
	pthread_t			*threads;
	struct s_philo 		*next;
}	t_philo;


#ifndef	PHILO_MAX
# define PHILO_MAX	200

#endif


//CREAR NODO
t_philo		*create_node(int id);
//AÑADIR NODO AL FINAL DE LA LISTA ENLAZADA
void		ft_lstadd_back(t_philo **lst, t_philo *new);
//IMPRIME POR PANTALLA LOS DATOS DE LOS ELEMENTOS DE LA ESTRUCTURA
void		print_list_struct(t_philo **philosophers);
//NOS DA LA FIRMA DE TIEMPO EN MS -- CONSULTAR -- MISMA FIRMA EN TODOS LOS PHILOS
long long	get_time_in_ms(void);
//LIBERA LA LISTA
void		free_list(t_philo **philosophers);
//PRUEBA ASOCIAR TENEDORES
void	initialize_mutex (pthread_mutex_t *forks, t_philo **list);
//USLEEP - ESPERAR EN VALOR MILISEGUNDOS
int			ft_usleep(size_t milisec);
//FT_ATOI - ASCII TO INT FUCTION - LIBFT
int			ft_atoi(const char *str);

//Routine
void	*routine(void *job);

void	make_threads (t_philo **list);

int	grab_forks(t_philo **philosophers);

#endif