# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:53:17 by ayghazal          #+#    #+#              #
#    Updated: 2021/10/19 15:39:45 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=  main.c utils/*.c

FLAGS=-Wall -Wextra -Werror

NAME=philo

$(NAME): 
	gcc   -fsanitize=address $(FLAGS) $(SRC) -o $(NAME) -lpthread

all: $(NAME)

re: fclean all

clean:
	rm -rf $(NAME)

fclean: clean