/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidptr0x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:06:31 by fursini           #+#    #+#             */
/*   Updated: 2023/02/01 18:34:51 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_voidptr(uintptr_t p)
{
	int	rvalue;

	rvalue = 0;
	if (p > 15)
	{
		rvalue += ft_voidptr(p / 16);
		rvalue += ft_voidptr(p % 16);
	}
	else if (p < 10)
		rvalue += ft_putchar('0' + p);
	else
		rvalue += ft_putchar('a' + (p - 10));
	return (rvalue);
}

int	ft_voidptr0x(uintptr_t p)
{
	ft_putstr("0x");
	return (ft_voidptr(p) + 2);
}
