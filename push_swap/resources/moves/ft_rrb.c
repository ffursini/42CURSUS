/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:48:05 by fursini           #+#    #+#             */
/*   Updated: 2023/03/19 13:56:28 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		ft_error(NULL, stack_b);
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_printf("rrb\n");
}
