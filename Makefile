# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 00:03:30 by agrumbac          #+#    #+#              #
#    Updated: 2017/03/06 22:49:01 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = agrumbac.filler

SRC = filler.c filler_player.c filler_block.c filler_block2.c filler_spy.c \
filler_directions.c filler_love.c

OBJDIR = objs

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

all:${NAME}

${NAME}: ${OBJ}
	@make -C libft/
	@echo Compiling ${NAME}
	@${CC} ${CFLAGS} -I./libft/includes/ -Llibft/ -lft -I. -o $@ ${OBJ}
	@echo "\033[32mJob's done\033[0m"

${OBJDIR}/%.o : ./srcs/%.c
	@echo Compiling $@
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./libft/includes/ -I. -c -o $@ $<

clean:
	@echo clean libft...
	@make -C libft/ clean
	@echo clean objs...
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo fclean libft...
	@make -C libft/ fclean
	@echo clean ${NAME}...
	@/bin/rm -f ${NAME} test

test:
	@${CC} -I./libft/includes/ -fsanitize=address -Llibft/ -lft -I. -o ${NAME} \
	$(addprefix srcs/, ${SRC})

re: fclean all

build: ${OBJ}

.PHONY: all clean fclean re test

#make -C .. && hilite ./filler_vm -f maps/map01 -p1 players/carli.filler -p2 ../agrumbac.filler
