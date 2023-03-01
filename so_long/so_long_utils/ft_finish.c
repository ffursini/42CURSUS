/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:35:40 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 12:14:42 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_finish(t_data ***data)
{
	int		i;

	i = 0;
	while ((**data)->map[i])
	{
		free((**data)->map[i]);
		i++;
	}
	free((**data)->map);
	mlx_destroy_window((**data)->mlx, (**data)->win);
	exit(0);
}

int	ft_close(t_data *data)
{
	int		i;

	i = 0;
	while ((data)->map[i])
	{
		free((data)->map[i]);
		i++;
	}
	free((data)->map);
	mlx_destroy_window((data)->mlx, (data)->win);
	exit (0);
}