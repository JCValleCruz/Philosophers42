/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:21:54 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/05 11:16:04 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(char *str, t_philo *philo, int id, char *color)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time_in_ms() - philo->meal_start;
	if(live_loop(philo))
		printf("%s[%zu] %d %s\n", color, time, id, str);
	pthread_mutex_unlock(philo->write_lock);	
}

int	ft_strlen(char *str)
{
	int c;

	c = 0;
	while(str)
		c++;
	return (c);	
}

size_t	get_time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_usleep(size_t milisec)
{
	size_t start;
	
	start = get_time_in_ms();
	while((get_time_in_ms() - start) < milisec)
		usleep(10);
	return(0);	
}