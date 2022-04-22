# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:54:51 by camillebarb       #+#    #+#              #
#    Updated: 2022/04/22 13:31:49 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

C_FILES = philo.c \
		init_structs.c \
		all_actions.c \
		check_philo_state.c \
		messages.c \
		utils.c \
		lock.c \
		parsing/parsing.c \
		parsing/utils.c \
		parsing/overflow_utils.c \

O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES}
	@${CC} ${O_FILES} -fsanitize=thread -pthread -o ${NAME}

clean:
	@${RM} ${O_FILES}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re