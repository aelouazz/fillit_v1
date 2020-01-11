# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelouazz <aelouazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 00:51:21 by aelouazz          #+#    #+#              #
#    Updated: 2019/07/19 13:54:35 by aelouazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
INCLUDE=./
FLAGS=-Wall -Wextra -Werror
FILES=main.c validation.c logic_getting_beaten.c shifting.c map.c
LIBFT=./libft/libft.a

all: $(NAME)

$(NAME):
	make -s -C ./libft
	gcc $(FLAGS) $(FILES) $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft

fclean:
	make -s fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
