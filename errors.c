/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:37 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/07 12:30:57 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *str)
{
	int	count;

	count = ft_strlen(str);
	if (str == NULL)
		write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, str, count);
	return (1);
}
