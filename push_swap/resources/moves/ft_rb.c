/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:14:35 by fursini           #+#    #+#             */
/*   Updated: 2023/03/19 13:56:01 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*stack_b) || !(*stack_b)->next)
		ft_error(NULL, stack_b);
	tmp = *stack_b;
	tmp2 = *stack_b;
	*stack_b = (*stack_b)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
}
