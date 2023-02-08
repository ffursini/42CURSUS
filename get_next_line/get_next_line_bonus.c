/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:05:47 by fursini           #+#    #+#             */
/*   Updated: 2023/02/06 18:05:47 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_brokenl(char *brokenl)
{
	char	*newbl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (brokenl[i] && brokenl[i - 1] != '\n')
		i++;
	if (!brokenl[i])
	{
		free (brokenl);
		return (NULL);
	}
	newbl = (char *)malloc(sizeof(char) * (ft_strlen(brokenl) - i + 1));
	if (!newbl)
		return (NULL);
	while (brokenl[i])
		newbl[j++] = brokenl[i++];
	newbl[j] = 0;
	free(brokenl);
	return (newbl);
}

char	*get_fixed_line(const char *brokenl)
{
	char	*fixedl;
	int		i;
	int		x;

	i = 0;
	if (!brokenl[0])
		return (NULL);
	while (brokenl[i] && brokenl[i - 1] != '\n')
		i++;
	fixedl = (char *)malloc(sizeof(char) * (i + 1));
	if (!fixedl)
		return (NULL);
	x = 0;
	while (i--)
	{
		fixedl[x] = brokenl[x];
		x++;
	}
	fixedl[x] = 0;
	return (fixedl);
}

char	*get_broken_line(int fd, char *brokenl)
{
	int		rlen;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rlen = 1;
	while (rlen != 0 && ft_strchr(brokenl, '\n') == 0)
	{
		rlen = read(fd, buf, BUFFER_SIZE);
		if (rlen == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rlen] = 0;
		brokenl = ft_strjoin(brokenl, buf);
	}
	free (buf);
	return (brokenl);
}

char	*get_next_line(int fd)
{
	char		*fixedl;
	static char	*brokenl[4096];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	brokenl[fd] = get_broken_line(fd, brokenl[fd]);
	if (!brokenl[fd])
		return (NULL);
	fixedl = get_fixed_line(brokenl[fd]);
	brokenl[fd] = get_next_brokenl(brokenl[fd]);
	return (fixedl);
}

// int	main()
// {
// 	int fd[2];

//    fd[0] = open("loreipsum.txt", O_RDONLY);
//    fd[1] = open("testone.txt", O_RDONLY);
// 	char *s = get_next_line(fd[0]);
//    char *s2 = get_next_line(fd[1]);

// 	while (s)
// 	{
// 		printf("%s%s", s, s2);
// 		s = get_next_line(fd[0]);
//        s2  = get_next_line(fd[1]);
// 	}
// 	close(fd[0]);
//    close(fd[1]);
// 	return (0);
// }
