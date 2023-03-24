/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:19:41 by fursini           #+#    #+#             */
/*   Updated: 2023/03/22 16:40:20 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_list ***stack_a, t_list ***stack_b, char **av)
{
	int		i;

	i = 0;
	if (ft_isdigit(av[0][0]))
		i--;
	*stack_a = (t_list **)malloc(sizeof(t_list *));
	*stack_b = (t_list **)malloc(sizeof(t_list *));
	**stack_a = NULL;
	**stack_b = NULL;
	while (av[++i])
		ft_lstadd_back(*stack_a, ft_lstnew(ft_atoi(av[i])));
}
