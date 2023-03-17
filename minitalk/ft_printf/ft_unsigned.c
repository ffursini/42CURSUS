/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:46 by fursini           #+#    #+#             */
/*   Updated: 2023/02/01 18:34:42 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int nb)
{
	int	rvalue;

	rvalue = 0;
	if (nb > 9)
	{
		rvalue += ft_unsigned(nb / 10);
		rvalue += ft_unsigned(nb % 10);
	}
	else
		rvalue += ft_putchar('0' + nb);
	return (rvalue);
}
