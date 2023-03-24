/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:35:45 by fursini           #+#    #+#             */
/*   Updated: 2023/02/01 18:35:15 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_variable(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_voidptr0x(va_arg(ap, uintptr_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_hex0x(va_arg(ap, unsigned long)));
	else if (c == 'X')
		return (ft_hex0xbig(va_arg(ap, size_t)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		rvalue;
	int		i;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	rvalue = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
			rvalue += (print_variable(ap, s[++i]) - 1);
		i++;
		rvalue++;
	}
	va_end(ap);
	return (rvalue--);
}

// int main()
// {
// 	char c[] = "ciaone";
// 	unsigned int d = __INT_MAX__;
// 	int x = ft_printf("%x\n", d);
// 	int y = printf("%x\n", d);
// 	printf ("%d\n%d\n", x, y);
// }
