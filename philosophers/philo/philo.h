/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:48:27 by fursini           #+#    #+#             */
/*   Updated: 2023/03/28 03:33:25 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

struct	s_data;

typedef struct s_philos
{
	int				id;
	int				meals;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal;
	pthread_t		thread_id;
	struct s_data	*data;
}				t_philos;

typedef struct s_data
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				start_time;
	int				death;
	int				all_eat;
	long long		time;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	forks[250];
	t_philos		philos[250];
}				t_data;


int			ft_init_params(t_data *data, int ac, char **av);
int			ft_init_mutex(t_data *data);
void		ft_init_philo(t_data *data);

int			ft_start(t_data *data);
void		*routine(void *philosopher);
void		ft_eat(t_philos *philo);
void		ft_sleep(long long time, t_data *data);
void		ft_death(t_data *data, t_philos *philo);
void		ft_exit(t_data *data, t_philos *philo);

long long	ft_get_time(void);
void		ft_print_status(t_philos *philo, char *status);
int			ft_atoi(const char *str);

#endif
