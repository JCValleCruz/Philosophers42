/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:50:33 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/21 01:10:16 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_list_struct(philo **philosophers)
{
    philo *aux = *philosophers;
    while (aux != NULL)
    {
		printf("\nID:\t\t%d\nN of Philos:\t%d\nTime to die:\t%d\nTime to eat:\t%d\nTime to sleep:\t%d\nLast meal time:\t%lld\n",aux->id, aux->n_of_philos, aux->time_to_die,
		aux->time_to_eat, aux->time_to_sleep, aux->last_meal_time);
        aux = aux->next;
    }
}

philo *create_node(int id)
{
    philo *new_node = (philo *)malloc(sizeof(philo));
    if (!new_node)
        return NULL;

    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}
void ft_lstadd_back(philo **lst, philo *new)
{
    philo *last;

    if (*lst == NULL)
        *lst = new;
    else
    {
        last = *lst;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new;
    }
}