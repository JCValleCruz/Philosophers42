/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:50:33 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/21 00:52:19 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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