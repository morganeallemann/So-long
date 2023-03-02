# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 13:39:48 by malleman          #+#    #+#              #
#    Updated: 2023/02/15 17:05:37 by malleman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#-------------------------- SOURCES -------------------------------------------#
SRCS =	main.c images_setup.c map_setup.c window_setup.c utils.c \
		player_setup.c events_setup.c checker_map.c checker_exit.c

#--------------------------	VARIABLES -----------------------------------------#
NAME		= so_long

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAGSDDBUG	= -Wall -Wextra =Werror -I. -Iincludes -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -I. -Iincludes

#-------------------------- COMMANDES -----------------------------------------#
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C ./libft
	make -C ./mlx
	${CC} ${CLFAGS} ${SRCS} ${LIBFT} ${MLX} -o ${NAME} -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -g
all: 	${NAME}

clean :
		
		rm -f ${OBJS}
		make clean -C ./libft
		make clean -C ./mlx

fclean : clean
		rm -f ${NAME}
		make fclean -C ./libft
		make clean -C ./mlx

re: 	fclean all

.PHONY: all clean fclean re

