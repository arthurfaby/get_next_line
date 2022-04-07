# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:42:25 by afaby             #+#    #+#              #
#    Updated: 2022/04/06 17:48:52 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./a.out

SRCS =	get_next_line.c	get_next_line_utils.c	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -g -D BUFFER_SIZE=$(BUFFER_SIZE)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
