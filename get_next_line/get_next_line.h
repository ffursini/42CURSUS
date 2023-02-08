/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:05:03 by fursini           #+#    #+#             */
/*   Updated: 2023/02/07 21:02:49 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*get_broken_line(int fd, char *brokenl);
char	*get_fixed_line(const char *brokenl);
char	*get_next_brokenl(char *brokenl);

char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, int n);

#endif
