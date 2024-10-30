/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:43:02 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/30 19:43:31 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *ph)
{
	t_philo *philos;

	philos = (t_philo *)ph;
	while (1)
	{
		if(check_dead(philos) == 1 || all_ate(philos) == 1)
			return (ph);
	}
	return (ph);
}


