# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:53:17 by ayghazal          #+#    #+#              #
#    Updated: 2021/10/20 15:32:16 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=  main.c  data.c list.c utils.c thread.c supervisor.c ft_atoi.c

FLAGS=-Wall -Wextra -Werror

NAME=philo

$(NAME):
	gcc	$(FLAGS) $(SRC) -o $(NAME) -lpthread

all: $(NAME)

re: fclean all

clean:
	rm -rf $(NAME)

fclean: clean