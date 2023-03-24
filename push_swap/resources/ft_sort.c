/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:20:43 by fursini           #+#    #+#             */
/*   Updated: 2023/03/22 17:10:29 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b, int ac)
{
	if (ac == 3)
		ft_sort_2(stack_a);
	else if (ac == 4)
		ft_sort_3(stack_a);
	else if (ac == 5)
		ft_sort_4(stack_a, stack_b);
	else if (ac == 6)
		ft_sort_5(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}
