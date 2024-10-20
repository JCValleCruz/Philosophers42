/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:39 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/21 01:02:25 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void initialize_philos(philo **list, int n_of_philos, char **argv)
{
	int c;
	c = 0;
    
	while (c < n_of_philos)
    {
        philo *philosophers = create_node(c + 1);
        if (!philosophers)
        {
            printf("Error al asignar memoria para el filósofo %d.\n", c + 1);
            return;
        }
		philosophers->n_of_philos 	= atoi(argv[1]);
		philosophers->time_to_die 	= atoi(argv[2]);	
		philosophers->time_to_eat 	= atoi(argv[3]);
		philosophers->time_to_sleep = atoi(argv[4]);
        ft_lstadd_back(list, philosophers);
		c++;
    }
}

void print_list_struct(philo **philosophers)
{
    philo *aux = *philosophers;
    while (aux != NULL)
    {
		printf("\nID:\t\t%d\nN of Philos:\t%d\nTime to die:\t%d\nTime to eat:\t%d\nTime to sleep:\t%d\n",aux->id, aux->n_of_philos, aux->time_to_die,
		aux->time_to_eat, aux->time_to_sleep);
        aux = aux->next;
    }
}

long long get_time_in_ms(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000LL) + (time.tv_usec / 1000LL);
}

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        printf("Uso: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", argv[0]);
        return 1;
    }

    int n_of_philos = atoi(argv[1]);
    philo *list = NULL;

    initialize_philos(&list, n_of_philos, argv);
    print_list_struct(&list);

    // No olvides liberar la memoria de la lista después de usarla.
    return 0;
}
