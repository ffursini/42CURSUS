/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex0x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:06:36 by fursini           #+#    #+#             */
/*   Updated: 2023/02/02 15:09:28 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex0x(unsigned int n)
{
	int	rvalue;

	rvalue = 0;
	if (n >= 16)
	{
		rvalue += ft_hex(n / 16);
		rvalue += ft_hex(n % 16);
	}
	else if (n < 10)
		rvalue += ft_putchar('0' + n);
	else
		rvalue += ft_putchar('a' + (n - 10));
	return (rvalue);
}
