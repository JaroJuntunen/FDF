# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 15:30:07 by jjuntune          #+#    #+#              #
#    Updated: 2022/01/24 15:40:15 by jjuntune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBRERY = libft/libft.a

all: $(NAME)

$(NAME): $(LIBRERY)

$(LIBRERY):
	make -C libft/

clean:
	make -C libft/ clean


fclean: clean
	make -C libft/ fclean

re: fclean all