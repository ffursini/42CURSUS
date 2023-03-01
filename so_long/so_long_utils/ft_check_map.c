/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:42:54 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 11:30:20 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_shape(t_data **data);
static void	ft_check_walls(t_data **data);
static void	ft_check_elements(t_data **data);

void	ft_check_map(t_data *data)
{
	ft_check_shape(&data);
	ft_check_walls(&data);
	ft_check_elements(&data);
	ft_check_non_elements(&data);
}

static void	ft_check_elements(t_data **data)
{
	t_map	map;

	map.collectible = 0;
	map.exit = 0;
	map.player = 0;
	map.y = -1;
	while ((*data)->map[++map.y])
	{
		map.x = -1;
		while ((*data)->map[map.y][++map.x])
		{
			if ((*data)->map[map.y][map.x] == 'C')
				map.collectible++;
			if ((*data)->map[map.y][map.x] == 'E')
				map.exit++;
			if ((*data)->map[map.y][map.x] == 'P')
				map.player++;
		}
	}
	if (map.collectible == 0 || map.exit == 0 || map.player != 1)
	{
		(*data)->collectables = map.collectible;
		ft_putstr("Error: The number of elements in the map is wrong");
		exit (1);
	}
}

static void	ft_check_firstlast_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			ft_putstr("Error: The map is not surrounded by walls");
			exit (1);
		}
		i++;
	}
}

static void	ft_check_walls(t_data **data)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((*data)->map[i]);
	while ((*data)->map[i])
	{
		if ((*data)->map[i][len - 1] != '1' ||
			(*data)->map[i][0] != '1')
		{
			ft_putstr("Error: The map is not surrounded by walls");
			exit (1);
		}
		i++;
	}
	ft_check_firstlast_wall((*data)->map[i - 1]);
	ft_check_firstlast_wall((*data)->map[0]);
}

static void	ft_check_shape(t_data **data)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen((*data)->map[i]);
	while ((*data)->map[i])
	{
		if (len != ft_strlen((*data)->map[i]))
		{
			ft_putstr("Error: Invalid map shape");
			exit (1);
		}
		i++;
	}
}
