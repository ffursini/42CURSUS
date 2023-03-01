/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:39:44 by fursini           #+#    #+#             */
/*   Updated: 2023/03/01 12:20:30 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "generic_utils/get_next_line/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map {
	int	collectible;
	int	exit;
	int	player;
	int	x;
	int	y;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*img;
	void	*win;
	char	**map;
	int		win_x;
	int		win_y;
	int		player_x;
	int		player_y;
	int		collectables;
	int		movement;
}	t_data;

// so_long_utils
int		ft_valid_file_name(char *name);
int		ft_key_hook(int keycode, t_data *data);
int		ft_close(t_data *data);
char	**ft_get_map(char const *map_name);
void	ft_check_map(t_data *data);
void	ft_set_data(t_data *data);
void	ft_render_map(t_data *data);
void	ft_go_right(t_data **data);
void	ft_finish(t_data ***data);
void	ft_collected(t_data ***data, int y, int x);
void	ft_movement(t_data **data);
void	ft_check_non_elements(t_data **data);

// generic_utils
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2);
int		ft_putstr(char *s);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t len);
void	ft_putchar(char c);
void	ft_bzero(void *s, size_t n);

#endif
