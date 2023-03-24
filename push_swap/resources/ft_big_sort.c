/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:55:23 by fursini           #+#    #+#             */
/*   Updated: 2023/03/22 15:35:39 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_push_all_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_put_index(t_list **stack_a)
{
	t_list	*higher;
	t_list	*list;
	int		i;
	int		size;

	size = ft_lstsize(*stack_a);
	i = -1;
	list = *stack_a;
	while (size > ++i)
	{
		list = *stack_a;
		higher = list;
		while (list && higher->index != 0)
		{
			list = list->next;
			higher = list;
		}
		while (list)
		{
			if (higher->num < list->num && list->index == 0)
				higher = list;
			list = list->next;
		}
		higher->index = size - i;
	}
}

void	ft_big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	ft_put_index(stack_a);
	i = 0;
	while (ft_check_order(stack_a) == 0)
	{
		tmp = *stack_a;
		tmp2 = NULL;
		while (tmp && tmp != tmp2)
		{
			if (((tmp->index >> i) & 1) == 1)
			{
				if (tmp2 == NULL)
					tmp2 = tmp;
				ft_ra(stack_a);
			}
			else
				ft_pb(stack_a, stack_b);
			tmp = *stack_a;
		}
		ft_push_all_b(stack_a, stack_b);
		i++;
	}
}
