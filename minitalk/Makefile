# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 12:21:27 by fursini           #+#    #+#              #
#    Updated: 2023/03/16 15:48:37 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	=	client
NAME_S	=	server

SRCS_C	=	client.c
SRCS_S	=	server.c

OBJS_C	=	${SRCS_C:.c=.o}
OBJS_S	=	${SRCS_S:.c=.o}

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
PRINTF	=	./ft_printf/
LIBFT	=	./libft/
LIPRIN	=	libft/libft.a ft_printf/libftprintf.a

all:
		make -C $(PRINTF)
		make -C $(LIBFT)
		${CC} ${FLAGS} ${SRCS_C} ${LIPRIN} -o ${NAME_C}
		${CC} ${FLAGS} ${SRCS_S} ${LIPRIN} -o ${NAME_S}
client:
		make -C $(PRINTF)
		make -C $(LIBFT)
		${CC} ${FLAGS} ${SRCS_C} ${LIPRIN} -o ${NAME_C}
server:
		make -C $(PRINTF)
		make -C $(LIBFT)
		${CC} ${FLAGS} ${SRCS_S} ${LIPRIN} -o ${NAME_S}
clean:
		make clean -C ${PRINTF}
		make clean -C ${LIBFT}
		${RM} ${OBJS_C}
		${RM} ${OBJS_S}
fclean:	clean
		make fclean -C ${PRINTF}
		make fclean -C ${LIBFT}
		${RM} ${NAME_C}
		${RM} ${NAME_S}
re:		fclean all
.PHONY:	all clean fclean re
