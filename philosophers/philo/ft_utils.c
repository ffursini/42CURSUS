/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:02:45 by fursini           #+#    #+#             */
/*   Updated: 2023/03/28 12:41:54 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
			return (-1);
	}
	return (result * sign);
}

unsigned long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print_status(t_philos *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->death == 0)
	{
		printf("%lu %d %s\n", ft_get_time() - philo->data->start_time,
			philo->id + 1, status);
	}
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_exit(t_data *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print);
}
