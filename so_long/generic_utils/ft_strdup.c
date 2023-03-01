/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:26:49 by fursini           #+#    #+#             */
/*   Updated: 2023/02/21 17:51:22 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *) malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}
