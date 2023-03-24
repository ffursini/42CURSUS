/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:37:23 by fursini           #+#    #+#             */
/*   Updated: 2023/03/22 17:20:15 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **stack_a, t_list **stack_b, char **nums)
{
	int	i;

	i = 0;
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(stack_a);
	free(stack_b);
	if (nums[0][0] != '.')
	{
		while (nums[i])
		{
			free(nums[i]);
			i++;
		}
		free(nums);
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**nums;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(0);
	nums = av;
	if (ac == 2)
	{
		if (!av[1][0])
			exit(0);
		nums = ft_split(av[1], ' ');
		ac = 0;
		while (nums[ac])
			ac++;
		if (ac == 1)
			exit(0);
		ac++;
	}
	ft_check_input(nums);
	ft_stack_init(&stack_a, &stack_b, nums);
	ft_sort(stack_a, stack_b, ac);
	ft_free(stack_a, stack_b, nums);
}
