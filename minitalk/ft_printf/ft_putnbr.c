/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:28 by fursini           #+#    #+#             */
/*   Updated: 2023/02/01 18:48:51 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	rvalue;

	rvalue = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		rvalue += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		rvalue += ft_putnbr(nb / 10);
		rvalue += ft_putnbr(nb % 10);
	}
	else
		rvalue += ft_putchar('0' + nb);
	return (rvalue);
}
