/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:10:17 by fursini           #+#    #+#             */
/*   Updated: 2023/02/28 21:17:49 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_put_image(t_data ***data, int x, int y, char *img)
{
	int	img_x;
	int	img_y;

	(**data)->img = mlx_xpm_file_to_image((**data)->mlx, img, &img_x, &img_y);
	mlx_put_image_to_window((**data)->mlx, (**data)->win, (**data)->img, x, y);
}

void	ft_image_to_map(char type, int x, int y, t_data **data)
{
	if (type == '1')
		ft_put_image(&data, x, y, "./img/wall.xpm");
	if (type == 'E')
		ft_put_image(&data, x, y, "./img/exit.xpm");
	if (type == '0')
		ft_put_image(&data, x, y, "./img/floor.xpm");
	if (type == 'C')
	{
		ft_put_image(&data, x, y, "./img/floor.xpm");
		ft_put_image(&data, x, y, "./img/collectable.xpm");
		(*data)->collectables++;
	}
	if (type == 'P')
	{
		ft_put_image(&data, x, y, "./img/floor.xpm");
		ft_put_image(&data, x, y, "./img/player_left.xpm");
		(*data)->player_x = x;
		(*data)->player_y = y;
	}
}

void	ft_render_map(t_data *data)
{
	int		map_x;
	int		map_y;
	int		x;
	int		y;

	map_y = 0;
	y = 0;
	while (data->map[map_y])
	{
		map_x = 0;
		x = 0;
		while (data->map[map_y][map_x])
		{
			ft_image_to_map(data->map[map_y][map_x], x, y, &data);
			map_x++;
			x += 64;
		}
		map_y++;
		y += 64;
	}
}
