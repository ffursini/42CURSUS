/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:01 by fursini           #+#    #+#             */
/*   Updated: 2023/02/01 19:15:39 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_voidptr0x(uintptr_t p);
int	ft_putnbr(int nb);
int	ft_unsigned(unsigned int nb);
int	ft_hex0x(unsigned int n);
int	ft_hex0xbig(unsigned int n);
int	ft_printf(const char *s, ...);

#endif
