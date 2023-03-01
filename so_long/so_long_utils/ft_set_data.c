/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:39:09 by fursini           #+#    #+#             */
/*   Updated: 2023/02/26 16:31:30 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_get_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_set_data(t_data *data)
{
	data->win_x = ft_strlen(data->map[0]);
	data->win_y = ft_get_y(data->map);
	data->collectables = 0;
	data->movement = 0;
}
