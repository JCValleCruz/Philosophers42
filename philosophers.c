/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:39 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/23 13:42:46 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	initialize_forks(pthread_mutex_t *forks, int nofphilos)
{
	int		c;
	int		i;

	c = nofphilos;
	i = 0;
	while (i < c)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	initialize_philos(t_philo **list, int n_of_philos, char **argv)
{
	int				c;
	long long		start_time;
	
	c = 0;
	start_time = get_time_in_ms();
    while (c < n_of_philos)
    {
        t_philo *philosophers = create_node(c + 1);
        if (!philosophers)
        {
            printf("Error al asignar memoria para el filósofo %d.\n", c + 1);
            return;
        }
		philosophers->start = get_time_in_ms();
		philosophers->n_of_philos 	= ft_atoi(argv[1]);
		philosophers->time_to_eat 	= ft_atoi(argv[2]);
		philosophers->time_to_die 	= ft_atoi(argv[3]);	
		philosophers->time_to_sleep = ft_atoi(argv[4]);
		philosophers->last_meal_time = ((get_time_in_ms() - start_time));
		ft_lstadd_back(list, philosophers);
		c++;
    }
}

void	initialize_mutex (pthread_mutex_t *forks, t_philo **list)
{
	t_philo	*aux;
	
	aux = *list;
	while(aux)
	{
		if(aux->next != NULL)
		{
			aux->left_fork = aux->id;
			aux->right_fork = aux->id + 1;
			aux->lfork = forks[aux->id];
			aux->rfork = forks[aux->id + 1];
		}
		else if(aux->next == NULL)
		{
			aux->left_fork = aux->id;
			aux->right_fork = (aux->id + 1) % aux->n_of_philos;
			aux->lfork = forks[aux->id];
			aux->rfork = forks[(aux->id + 1) % (aux->n_of_philos)];
		}
		aux = aux->next;
	}	
}

int	grab_forks(t_philo **philosophers)
{
	t_philo *aux;
	
	aux = *philosophers;

		if (pthread_mutex_lock(&aux->lfork) == 0 && pthread_mutex_lock(&aux->rfork) == 0)
			printf("[%llu]El Filosofo Nº:%d cogió ambos tenedores.\n", (get_time_in_ms() - aux->start) , aux->id);	
		else if (pthread_mutex_lock(&aux->lfork) != 0 && pthread_mutex_lock(&aux->rfork) != 0)
		{
			printf("[%llu]El Filosofo Nº:%d no pudo coger los tenedores.\n", (get_time_in_ms() - aux->start) , aux->id);
			return (1);
		}
		ft_usleep(aux->time_to_eat);
		if (pthread_mutex_unlock(&aux->lfork) == 0 && pthread_mutex_unlock(&aux->rfork) == 0)
			printf("[%llu]El Filosofo Nº:%d soltó ambos tenedores.\n", (get_time_in_ms() - aux->start) , aux->id);
		return (0);
}

int main(int argc, char **argv)
{
	pthread_mutex_t forks[PHILO_MAX];
	
    int n_of_philos = atoi(argv[1]);
    t_philo *list = NULL;
    if (argc != 5)
    {
        printf("Uso: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", argv[0]);
        return 1;
    }
	initialize_forks(forks, n_of_philos);
    initialize_philos(&list, n_of_philos, argv);
	initialize_mutex(forks, &list);
	printf("N de Filosofos:\t%d\n", list->n_of_philos);
	make_threads(&list);
	grab_forks(&list);
    //print_list_struct(&list);
	free_list(&list);
    return 0;
}
