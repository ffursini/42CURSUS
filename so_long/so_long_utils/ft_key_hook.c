/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:39:18 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 11:35:56 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_go_right(t_data **data);
void	ft_go_left(t_data **data);
void	ft_go_up(t_data **data);
void	ft_go_down(t_data **data);

int	ft_key_hook(int keycode, t_data *data)
{
	int		i;

	i = -1;
	if (keycode == 2 || keycode == 124)
		ft_go_right(&data);
	else if (keycode == 0 || keycode == 123)
		ft_go_left(&data);
	else if (keycode == 13 || keycode == 126)
		ft_go_up(&data);
	else if (keycode == 1 || keycode == 125)
		ft_go_down(&data);
	else if (keycode == 53)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	else
		return (0);
	ft_movement(&data);
	return (0);
}

void	ft_go_right(t_data **data)
{
	int		img_x;
	int		img_y;

	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/floor.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
	if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64) + 1] == 'E')
	{
		if ((*data)->collectables == 0)
			ft_finish(&data);
	}
	else if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64) + 1] != '1')
	{
		(*data)->player_x += 64;
	}
	if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64)] == 'C')
		ft_collected(&data, (*data)->player_y / 64, (*data)->player_x / 64);
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/player_right.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
}

void	ft_go_left(t_data **data)
{
	int		img_x;
	int		img_y;

	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/floor.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
	if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64) - 1] == 'E')
	{
		if ((*data)->collectables == 0)
			ft_finish(&data);
	}
	else if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64) - 1] != '1')
	{
		(*data)->player_x -= 64;
	}
	if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64)] == 'C')
		ft_collected(&data, (*data)->player_y / 64, (*data)->player_x / 64);
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/player_left.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
}

void	ft_go_up(t_data **data)
{
	int		img_x;
	int		img_y;

	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/floor.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
	if ((*data)-> map[((*data)->player_y / 64) - 1]
		[((*data)->player_x / 64)] == 'E')
	{
		if ((*data)->collectables == 0)
			ft_finish(&data);
	}
	else if ((*data)-> map[((*data)->player_y / 64) - 1]
		[((*data)->player_x / 64)] != '1')
	{
		(*data)->player_y -= 64;
	}
	if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64)] == 'C')
		ft_collected(&data, (*data)->player_y / 64, (*data)->player_x / 64);
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/player_up.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
}

void	ft_go_down(t_data **data)
{
	int		img_x;
	int		img_y;

	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/floor.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
	if ((*data)-> map[((*data)->player_y / 64) + 1]
		[((*data)->player_x / 64)] == 'E')
	{
		if ((*data)->collectables == 0)
			ft_finish(&data);
	}
	else if ((*data)-> map[((*data)->player_y / 64) + 1]
		[((*data)->player_x / 64)] != '1')
	{
		(*data)->player_y += 64;
	}
	if ((*data)-> map[(*data)->player_y / 64]
		[((*data)->player_x / 64)] == 'C')
		ft_collected(&data, (*data)->player_y / 64, (*data)->player_x / 64);
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/player_down.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->img, (*data)->player_x, (*data)->player_y);
}
// # Key Codes for MacOS
// ESC = KEY_ESC=53
// W = KEY_W=13
// A = KEY_A=0
// S = KEY_S=1
// D = KEY_D=2
// UP = KEY_UP=126
// DOWN = KEY_DOWN=125
// LEFT = KEY_LEFT=123
// RIGHT = KEY_RIGHT=124
// R = KEY_R=15
// Q = KEY_Q=12
