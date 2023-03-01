/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:36:05 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 11:54:51 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_invalid(void)
{
	ft_putstr("Error: Invalid map");
	exit (1);
}

char	**ft_get_map(char const *map_name)
{
	int		fd;
	char	*map;
	char	*mapline;
	char	**remap;

	mapline = "";
	map = ft_strdup("");
	fd = open (map_name, O_RDONLY);
	if (fd < 0)
		ft_invalid();
	while (mapline)
	{
		mapline = get_next_line(fd);
		if (mapline == NULL)
			break ;
		map = ft_strjoin(map, mapline);
		free (mapline);
	}
	close (fd);
	free (mapline);
	if (!map)
		ft_invalid();
	remap = ft_split(map, '\n');
	free (map);
	return (remap);
}
