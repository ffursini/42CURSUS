/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_non_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:26:22 by fursini           #+#    #+#             */
/*   Updated: 2023/02/28 20:27:13 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_non_elements(t_data **data)
{
	t_map	map;

	map.y = -1;
	while ((*data)->map[++map.y])
	{
		map.x = -1;
		while ((*data)->map[map.y][++map.x])
		{
			if ((*data)->map[map.y][map.x] != 'C' &&
			(*data)->map[map.y][map.x] != 'E' &&
			(*data)->map[map.y][map.x] != 'P' &&
			(*data)->map[map.y][map.x] != '0' &&
			(*data)->map[map.y][map.x] != '1')
			{
				ft_putstr("Error: The types of elements in the map are wrong");
				exit (1);
			}
		}
	}
}
