/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:11:07 by fursini           #+#    #+#             */
/*   Updated: 2023/03/22 16:55:19 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

static void	ft_check_out_of_range(char *num)
{
	int		len;
	int		negative;
	int		i;

	len = ft_strlen(num);
	negative = 0;
	i = 0;
	if (num[i] == '-')
	{
		negative = 1;
		i++;
	}
	if (len - negative > 10)
	{
		ft_printf("Error\n");
		exit(0);
	}
	else if (len - negative == 10)
	{
		if (negative && ft_strncmp(num, "-2147483648", 11) > 0)
			ft_print_error();
		else if (!negative && ft_strncmp(num, "2147483647", 10) > 0)
			ft_print_error();
	}
}

static void	ft_check_equal(char **av, char *str)
{
	int		i;

	i = -1;
	if (av[i] == NULL)
		return ;
	while (av[++i])
	{
		if (ft_atoi(av[i]) == ft_atoi(str))
			ft_print_error();
	}
}

static void	ft_check_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]))
			i++;
		else
			ft_print_error();
	}
	ft_check_out_of_range(num);
}

void	ft_check_input(char **av)
{
	int		i;

	i = 0;
	if (av[0][0] != '.')
		i--;
	while (av[++i])
		ft_check_number(av[i]);
	i = 0;
	if (av[0][0] != '.')
		i--;
	while (av[++i])
		ft_check_equal(av + i + 1, av[i]);
}
