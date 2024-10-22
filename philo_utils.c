/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:50:33 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/22 13:17:24 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_usleep(size_t milisec)
{
	size_t	start;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < milisec)
		usleep(10);
	return (0);
}

void print_list_struct(t_philo**philosophers)
{
    t_philo *aux = *philosophers;
    while (aux != NULL)
    {
		printf("\nID:\t\t%d\nN of Philos:\t%d\nTime to die:\t%d\nTime to eat:\t%d\nTime to sleep:\t%d\nLeft Fork:\t%d\nRight Fork:\t%d\n",aux->id,
		 aux->n_of_philos, aux->time_to_die, aux->time_to_eat, aux->time_to_sleep, aux->left_fork, aux->right_fork);
		
		aux = aux->next;
    }
}

t_philo *create_node(int id)
{
    t_philo *new_node = (t_philo *)malloc(sizeof(t_philo));
    if (!new_node)
        return NULL;
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}
void ft_lstadd_back(t_philo **lst, t_philo *new)
{
   t_philo *last;

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
void	free_list(t_philo **lst)
{
	t_philo	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
	*lst = NULL;
}