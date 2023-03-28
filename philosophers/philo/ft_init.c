/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:59:44 by fursini           #+#    #+#             */
/*   Updated: 2023/03/25 22:11:42 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_params(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->death = 0;
	data->all_eat = 0;
	data->start_time = ft_get_time();
	if (data->philo_num < 1 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->philo_num > 250)
		return (1);
	if (ac == 6)
	{
		data->times_must_eat = ft_atoi(av[5]);
		if (data->times_must_eat <= 0)
			return (1);
	}
	else
		data->times_must_eat = -1;
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = data->philo_num;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->eat, NULL))
		return (1);
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	return (0);
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = data->philo_num;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		data->philos[i].meals = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].left_fork_id = i;
		data->philos[i].right_fork_id = (i + 1) % data->philo_num;
		data->philos[i].data = data;
	}
}
