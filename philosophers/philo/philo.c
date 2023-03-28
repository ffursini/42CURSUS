/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:47:21 by fursini           #+#    #+#             */
/*   Updated: 2023/03/28 02:59:40 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 5 && ac != 6)
		return (printf("Error: wrong number of arguments\n"));
	if (ft_init_params(&data, ac, av))
		return (printf("Error: wrong arguments\n"));
	if (ft_init_mutex(&data))
		return (printf("Error: mutex failed\n"));
	ft_init_philo(&data);
	if (ft_start(&data))
		return (printf("Error: thread failed\n"));
	return (0);
}
