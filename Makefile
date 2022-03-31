# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:54:51 by camillebarb       #+#    #+#              #
#    Updated: 2022/03/31 13:53:01 by camillebarb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

C_FILES = philo.c \
		init_structs.c \
		errors.c \
		parsing/parsing.c \
		parsing/utils.c \
		parsing/overflow_utils.c \

O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES}
	@${CC} ${O_FILES} -pthread -o ${NAME}

clean:
	@${RM} ${O_FILES}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re