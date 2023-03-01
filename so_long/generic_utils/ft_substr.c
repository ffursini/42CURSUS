/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:48:13 by fursini           #+#    #+#             */
/*   Updated: 2023/02/28 20:23:53 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if ((len == 0 && start == 0) || (size_t)start >= ft_strlen(s))
	{
		dst = (char *) malloc(sizeof(char) * 1);
		dst[0] = 0;
		return (dst);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dst = (char *) ft_calloc((len + 1), 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
