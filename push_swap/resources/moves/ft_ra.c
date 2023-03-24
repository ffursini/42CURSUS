/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:08:26 by fursini           #+#    #+#             */
/*   Updated: 2023/03/19 13:55:46 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*stack_a) || !(*stack_a)->next)
		ft_error(stack_a, NULL);
	tmp = *stack_a;
	tmp2 = *stack_a;
	*stack_a = (*stack_a)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}
