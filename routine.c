/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:42:15 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/23 13:47:48 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	make_threads (t_philo **list)
{
	t_philo 	*aux;
	pthread_t 	*threads;
	int			i;	

	aux = *list;
	printf("PESCA MAKE THREADS N OF PHILOS:%d\n", aux->n_of_philos);
	threads = malloc(sizeof(pthread_t) * aux->n_of_philos);
	if (!threads)
	{
    	perror("Error al reservar memoria para threads");
   		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < aux->n_of_philos && aux)
	{
		if(pthread_create(&threads[i], NULL, &routine, (void *)aux) != 0)
			fprintf(stderr, "Error al crear hilo %d.\n", aux->id);
		//aux->threads[i] = threads[i];
		printf("ID:%d\n",aux->id);
		aux = aux->next;
		i++;
	}	
}

void	*routine(void *job)
{
	t_philo *aux;

	job = (t_philo *)aux;
	printf("Filosofo:%d creó un hilo de trabajo correctamente.\n", aux->id);	
	grab_forks(&aux);
	return (job);
}
	

	