/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:37 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/10/30 18:42:49 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *str)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, str, ft_strlen(str));
	return (1);
}