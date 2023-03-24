# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 21:06:37 by fursini           #+#    #+#              #
#    Updated: 2023/03/22 15:35:59 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	resources/main.c \
			resources/ft_check_input.c \
			resources/ft_stack_init.c \
			resources/ft_error.c \
			resources/ft_sort.c \
			resources/ft_small_sort.c \
			resources/ft_big_sort.c \
			resources/moves/ft_sa.c \
			resources/moves/ft_sb.c \
			resources/moves/ft_ss.c \
			resources/moves/ft_pa.c \
			resources/moves/ft_pb.c \
			resources/moves/ft_ra.c \
			resources/moves/ft_rb.c \
			resources/moves/ft_rr.c \
			resources/moves/ft_rra.c \
			resources/moves/ft_rrb.c \
			resources/moves/ft_rrr.c \

OBJS	=	$(SRCS:.c=.o)

CCFLAGS	=	gcc -Wall -Wextra -Werror
RM		=	rm -f
PRINTF	=	./resources/ft_printf/
LIBFT	=	./resources/libft/
LIBS	=	./resources/libft/libft.a ./resources/ft_printf/libftprintf.a

all:
			make -C $(PRINTF)
			make -C $(LIBFT)
			$(CCFLAGS) $(SRCS) $(LIBS) -o $(NAME)
clean:
			make clean -C $(PRINTF)
			make clean -C $(LIBFT)
			$(RM) $(OBJS)
fclean:	clean
			make fclean -C $(PRINTF)
			make fclean -C $(LIBFT)
			$(RM) $(NAME)
re:		fclean all
.PHONY: all clean fclean re

