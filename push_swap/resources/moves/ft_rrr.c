/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:49:06 by fursini           #+#    #+#             */
/*   Updated: 2023/03/19 13:56:32 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (!(*stack_a) || !(*stack_b) || !(*stack_a)->next || !(*stack_b)->next)
		ft_error(stack_a, stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_printf("rrr\n");
}
