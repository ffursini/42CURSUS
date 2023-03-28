# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 17:47:44 by fursini           #+#    #+#              #
#    Updated: 2023/03/28 17:43:00 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	philo.c \
			ft_init.c \
			ft_utils.c \
			ft_start.c \

OBJS	=	$(SRCS:.c=.o)

CCFLAGS	=	gcc -Wall -Wextra -Werror
RM		=	rm -f

$(NAME):
		$(CCFLAGS) $(SRCS) -o $(NAME)

all:
		$(NAME)
clean:
			$(RM) $(OBJS)
fclean:	clean
			$(RM) $(NAME)
re:		fclean all
.PHONY: all clean fclean re
