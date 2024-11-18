/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:11:31 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/07 11:41:41 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[37;1m"

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*eat_lock;
	int					n_philo;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				last_meal;
	size_t				meal_start;
	int					eating_flag;
	int					times_eaten;
	int					n_times_to_eat;
	int					*dead;
}	t_philo;

typedef struct s_list
{
	int				philo_num;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_prog;

//UTILS------------------------------> utils.c
void				print_action(char *str, t_philo *philo,
						int id, char *color);
int					ft_strlen(const char *str);
size_t				get_time_in_ms(void);
int					ft_atoi(const char *str);
int					ft_usleep(size_t milisec);
//ERRORS----------------------------> errors.c
int					ft_error(char *str);
//----------------------------------> routine.c
void				grab_forks(t_philo *philo);
void				eating(t_philo *philo);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
void				*routine(void *ph);
//MONITOR - MAIN THREAD ------------> monitor.c
void				*monitor(void *ph);
int					live_loop(t_philo *philo);
int					philo_is_dead(t_philo *philo);
int					check_dead(t_philo *philo);
int					all_ate(t_philo *philo);
//THREADS MANAGEMENT ---------------> threads.c
void				thread_destroy(t_prog *prog, pthread_mutex_t *forks);
void				thread_create(t_prog *prog, pthread_mutex_t *forks);
//INIT------------------------------> init.c
void				initialize_forks(pthread_mutex_t *forks, int nofphilos);
void				initialize_args(t_philo *ph, char **argv);
void				initialize_philos(t_philo *ph, char **argv, t_prog *prog,
						pthread_mutex_t *forks);
void				initialize_program(t_prog *prog, t_philo *philos,
						char **argv);
#endif