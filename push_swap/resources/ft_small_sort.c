/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:17:05 by fursini           #+#    #+#             */
/*   Updated: 2023/03/20 20:53:04 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_5plus(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
	ft_ra(stack_a);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
	if ((*stack_b)->num < (*stack_a)->num)
		ft_pa(stack_a, stack_b);
	else if ((*stack_b)->num < (*stack_a)->next->num)
	{
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
	else if ((*stack_b)->num < (*stack_a)->next->next->num)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_b)->num < (*stack_a)->next->next->next->num)
		ft_sort_5plus(stack_a, stack_b);
	else
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	if ((*stack_b)->num < (*stack_a)->num)
		ft_pa(stack_a, stack_b);
	else if ((*stack_b)->num < (*stack_a)->next->num)
	{
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
	else if ((*stack_b)->num < (*stack_a)->next->next->num)
	{
		ft_rra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}

void	ft_sort_3(t_list **stack_a)
{
	int		num[3];

	num[0] = (*stack_a)->num;
	num[1] = (*stack_a)->next->num;
	num[2] = (*stack_a)->next->next->num;
	if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		ft_sa(stack_a);
	else if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		ft_sa(stack_a);
	else if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		ft_rra(stack_a);
	else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		ft_ra(stack_a);
}

void	ft_sort_2(t_list **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		ft_sa(stack_a);
}
