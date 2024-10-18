/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:19:29 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/18 23:08:05 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	main(int argc, char **argv)
{
	philo *philosophers;
	init_philo(philosophers, argv);
	print_struct(philosophers);
	return 0;	
}