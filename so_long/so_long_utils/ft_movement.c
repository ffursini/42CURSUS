/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:31:31 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 11:49:29 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_movement(t_data **data)
{
	int		img_x;
	int		img_y;
	char	*move;

	move = ft_itoa((*data)->movement);
	(*data)->movement++;
	(*data)->img = mlx_xpm_file_to_image((*data)->mlx,
			"./img/wall.xpm", &img_x, &img_y);
	mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img, 0, 0);
	mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img, 64, 0);
	mlx_string_put((*data)->mlx, (*data)->win, 5, 10, 0xffffff, "Move: ");
	mlx_string_put((*data)->mlx, (*data)->win, 60, 10, 0xffffff, move);
	free (move);
}
