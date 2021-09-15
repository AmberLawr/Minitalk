# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 11:42:39 by jzhou             #+#    #+#              #
#    Updated: 2021/09/15 17:50:23 by jzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCCLIENT = ft_client.c ft_utils.c ft_utils1.c\

SRCSERVER = ft_server.c ft_utils.c ft_utils1.c\

MAKE = make

NAME1 = server

NAME2 = client


$(NAME1): $(SRCSERVER)
	$(CC) $(FLAGS) -c $(SRCSERVER)
	$(CC) $(FLAGS) ft_server.o ft_utils.o ft_utils1.o -o server

$(NAME2): $(SRCCLIENT)
	$(CC) $(FLAGS) -c $(SRCCLIENT)
	$(CC) $(FLAGS) ft_client.o ft_utils.o ft_utils1.o -o client

all:
	$(MAKE) server
	$(MAKE)	client

clean:
	rm -f *.out
	rm -f *.o

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

