/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:55:04 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 12:19:43 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || ft_valid_file_name(argv[1]) != 0)
	{
		ft_putstr("Error: ./so_long [map_name.ber]\n");
		exit (1);
	}
	data.map = ft_get_map(argv[1]);
	if (data.map)
	{
		ft_check_map(&data);
		ft_set_data(&data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx,
				data.win_x * 64, data.win_y * 64, "so_long");
		ft_render_map(&data);
		mlx_key_hook(data.win, ft_key_hook, &data);
		mlx_string_put(data.mlx, data.win, 5, 10, 0xffffff, "Move: ");
		mlx_hook(data.win, 17, 0, ft_close, (void *)&data);
		mlx_loop(data.mlx);
	}
	return (0);
}
