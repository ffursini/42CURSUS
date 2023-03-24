/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:39:47 by fursini           #+#    #+#             */
/*   Updated: 2023/03/22 17:10:45 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

//moves
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

void	ft_check_input(char **av);
void	ft_stack_init(t_list ***stack_a, t_list ***stack_b, char **av);
void	ft_error(t_list **stack_a, t_list **stack_b);

void	ft_sort(t_list **stack_a, t_list **stack_b, int ac);
void	ft_sort_2(t_list **stack_a);
void	ft_sort_3(t_list **stack_a);
void	ft_sort_4(t_list **stack_a, t_list **stack_b);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
void	ft_big_sort(t_list **stack_a, t_list **stack_b);

void	ft_put_index(t_list **stack_a);
void	ft_push_all_b(t_list **stack_a, t_list **stack_b);
int		ft_check_order(t_list **stack_a);

#endif
