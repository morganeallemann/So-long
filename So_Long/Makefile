# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 13:39:48 by malleman          #+#    #+#              #
#    Updated: 2023/02/08 12:14:03 by malleman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#-------------------------- SOURCES -------------------------------------------#
SRCS =	main.c


#--------------------------	VARIABLES -----------------------------------------#
NAME		= so_long

LIBFT		= libft.a
LIBFTPATH	= ./libft/

MLX			= libmlx.dylib
MLXPATH		= ./mlx/

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAGSDDBUG	= -Wall -Wextra =Werror -I. -Iincludes -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -I. -Iincludes

#-------------------------- COMMANDES -----------------------------------------#
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS} 
	make -C ${LIBFTPATH}
	make -C ${MLXPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	mv ${MLXPATH}${MLX} ${MLX}
	${CC} ${CLFAGS} ${SRCS} ${LIBFT} ${MLX} -o ${NAME}

all: 	${NAME}

clean :
		
		rm -f ${OBJS}
		make clean -C ${LIBFTPATH}
		make clean -C ${MLXPATH}

fclean : clean
		rm -f ${NAME}
		rm -f ${LIBFT}
		rm -f ${MLX}
		make fclean -C ${LIBFTPATH}
		make fclean -C ${MLXPATH}

re: 	fclean all
		make re -C ${LIBFTPATH}
		make re -C ${MLXPATH}

.PHONY: all clean fclean re

