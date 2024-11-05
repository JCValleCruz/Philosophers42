/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:13:47 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/05 11:37:05 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_argv(char **argv)
{
	int	argv1;

	argv1 = ft_atoi(argv[1]);
	if (argv1 <= 0 || argv1 > 200)
		return (ft_error("Incorrect Nº of Philos"));
	if (ft_atoi(argv[2]) <= 0)
		return (ft_error("Error Time to Die value was incorrect"));
	if (ft_atoi(argv[3]) <= 0)
		return (ft_error("Error Time to Eat value was incorrect"));
	if (ft_atoi(argv[4]) <= 0)
		return (ft_error("Error Time to Sleep value was incorrect"));
	if (argv[5])
		if (ft_atoi(argv[5]) < 0)
			return (ft_error("Number of meals value was incorrect"));				
	return (0);	
}

int main(int argc, char **argv)
{
	t_philo		philos[PHILO_MAX];
	t_prog		prog;
	
	if (argc != 5 && argc != 6)
		return (ft_error("Error: Nº of arguments was incorrect"));
	if (check_argv(argv) == 1)
		return (1);
	initialize_program(&prog, philos, argv);
	return (0);		
}
