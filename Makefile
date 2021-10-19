# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:53:17 by ayghazal          #+#    #+#              #
#    Updated: 2021/10/19 02:25:13 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=  main.c utils/*.c

FLAGS=-Wall -Wextra -Werror

NAME=philo

$(NAME): 
	gcc  $(FLAGS) $(SRC) -o $(NAME) -lpthread

all: $(NAME)

re: fclean all

clean:
	rm -rf $(NAME)

fclean: clean