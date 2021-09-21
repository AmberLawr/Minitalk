# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 11:42:39 by jzhou             #+#    #+#              #
#    Updated: 2021/09/20 17:50:57 by jzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCSERVER = ft_server.c ft_utils.c ft_utils1.c\

SRCCLIENT = ft_client.c ft_utils.c ft_utils1.c\

SRCBONUS = ft_server_bonus.c ft_client_bonus.c ft_utils_bonus.c ft_utils1_bonus.c\

MAKE = make

NAME1 = server

NAME2 = client

NAME3 = bonus

all:
	$(MAKE) $(NAME1)
	$(MAKE) $(NAME2)

$(NAME1): $(SRCSERVER)
	$(CC) $(FLAGS) -c $(SRCSERVER)
	$(CC) $(FLAGS) $(SRCSERVER:.c=.o) -o server

$(NAME2): $(SRCCLIENT)
	$(CC) $(FLAGS) -c $(SRCCLIENT)
	$(CC) $(FLAGS) $(SRCCLIENT:.c=.o) -o client

$(NAME3): $(SRCBONUS)
	$(CC) $(FLAGS) -c $(SRCBONUS)
	$(CC) $(FLAGS) ft_server_bonus.o ft_utils_bonus.o ft_utils1_bonus.o -o server
	$(CC) $(FLAGS) ft_client_bonus.o ft_utils_bonus.o ft_utils1_bonus.o -o client

clean:
	rm -f *.out
	rm -f *.o

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

