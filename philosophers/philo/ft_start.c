/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:44:03 by fursini           #+#    #+#             */
/*   Updated: 2023/03/28 16:43:59 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start(t_data *data)
{
	t_philos	*philo;
	int			i;

	philo = data->philos;
	i = 0;
	if (data->philo_num != 1)
	{
		while (i < data->philo_num)
		{
			if (pthread_create(&(philo[i].thread_id), NULL,
					&routine, &(philo[i])))
				return (1);
			philo[i].last_meal = ft_get_time();
			i++;
		}
		ft_death(data, data->philos);
	}
	else
		ft_one_philo(data);
	ft_exit(data, philo);
	return (0);
}

void	*routine(void *philosopher)
{
	t_philos	*philo;
	t_data		*data;
	int			i;

	philo = (t_philos *)philosopher;
	data = philo->data;
	i = 0;
	if (philo->id % 2)
		usleep(15000);
	while (data->death == 0)
	{
		ft_eat(philo);
		if (data->all_eat == 1)
			break ;
		ft_print_status(philo, "is sleeping");
		ft_sleep(data->time_to_sleep, data);
		ft_print_status(philo, "is thinking");
		i++;
	}
	return (NULL);
}

void	ft_eat(t_philos *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[philo->left_fork_id]);
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&data->forks[philo->right_fork_id]);
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&data->eat);
	ft_print_status(philo, "is eating");
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&data->eat);
	ft_sleep(data->time_to_eat, data);
	(philo->meals)++;
	pthread_mutex_unlock(&data->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&data->forks[philo->right_fork_id]);
}

void	ft_sleep(unsigned long time, t_data *data)
{
	unsigned long	start;

	start = ft_get_time();
	while (!data->death && ft_get_time() - start < time)
		usleep(50);
}

void	ft_death(t_data *d, t_philos *philo)
{
	int	i;

	while (d->all_eat == 0)
	{
		i = -1;
		while (++i < d->philo_num && d->death == 0)
		{
			pthread_mutex_lock(&d->eat);
			if ((int)((ft_get_time() - philo[i].last_meal)) >= d->time_to_die)
			{
				ft_print_status(&philo[i], "died");
				d->death = 1;
			}
			pthread_mutex_unlock(&d->eat);
			usleep(100);
		}
		if (d->death == 1)
			break ;
		i = 0;
		while (d->times_must_eat != -1 && i < d->philo_num
			&& philo[i].meals >= d->times_must_eat)
			i++;
		if (i == d->philo_num)
			d->all_eat = 1;
	}
}
