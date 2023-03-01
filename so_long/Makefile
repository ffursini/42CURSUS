# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 20:45:42 by fursini           #+#    #+#              #
#    Updated: 2023/03/01 11:03:45 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRCS =	./generic_utils/get_next_line/get_next_line_utils.c \
		./generic_utils/get_next_line/get_next_line.c \
		./generic_utils/ft_bzero.c \
		./generic_utils/ft_calloc.c \
		./generic_utils/ft_itoa.c \
		./generic_utils/ft_memcpy.c \
		./generic_utils/ft_memset.c \
		./generic_utils/ft_putchar.c \
		./generic_utils/ft_putstr.c \
		./generic_utils/ft_split.c \
		./generic_utils/ft_strcmp.c \
		./generic_utils/ft_strdup.c \
		./generic_utils/ft_strjoin.c \
		./generic_utils/ft_strlcpy.c \
		./generic_utils/ft_strlen.c \
		./generic_utils/ft_substr.c \
		./so_long_utils/ft_check_map.c \
		./so_long_utils/ft_check_non_elements.c \
		./so_long_utils/ft_collected.c \
		./so_long_utils/ft_finish.c \
		./so_long_utils/ft_get_map.c \
		./so_long_utils/ft_key_hook.c \
		./so_long_utils/ft_movement.c \
		./so_long_utils/ft_render_map.c \
		./so_long_utils/ft_set_data.c \
		./so_long_utils/ft_valid_file_name.c \
		so_long.c \

OBJS	= $(SRCS:.c=.o)

%.c%.o:
		$(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -lmlx  -framework OpenGL -framework AppKit -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re


