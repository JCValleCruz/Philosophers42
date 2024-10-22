/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:39 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/22 13:43:09 by jvalle-d         ###   ########.fr       */
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
		philosophers->n_of_philos 	= ft_atoi(argv[1]);
		philosophers->time_to_die 	= ft_atoi(argv[2]);	
		philosophers->time_to_eat 	= ft_atoi(argv[3]);
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

void	grab_forks(t_philo **philosophers)
{
	t_philo *aux;
	
	aux = *philosophers;
	while (aux)
	{
		pthread_mutex_lock(&aux->lfork);
		printf("El Filosofo Nº:%d cogió el tenedor de su izquierda.\n", aux->id);
		printf("El tenedor era el nº:%d.\n", aux->left_fork);
		pthread_mutex_lock(&aux->rfork);
		printf("El Filosofo Nº:%d cogió el tenedor de su derecha.\n", aux->id);
		printf("El tenedor era el nº:%d.\n", aux->right_fork);
		aux = aux->next;
	}
	
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
	grab_forks(&list);
    print_list_struct(&list);
	free_list(&list);
    return 0;
}
