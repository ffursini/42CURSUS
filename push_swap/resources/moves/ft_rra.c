/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:23:19 by fursini           #+#    #+#             */
/*   Updated: 2023/03/19 13:56:17 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		ft_error(stack_a, NULL);
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_printf("rra\n");
}
