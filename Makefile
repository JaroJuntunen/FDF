# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 15:30:07 by jjuntune          #+#    #+#              #
#    Updated: 2022/02/08 15:05:02 by jjuntune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBRERY = libft/libft.a

FILES = main.c draw_line.c draw_line_extentions.c

INCLUDES = -I /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(LIBRERY)
	gcc $(FILES) $(LIBRERY) $(INCLUDES)
$(LIBRERY):
	make -C libft/

clean:
	make -C libft/ clean


fclean: clean
	make -C libft/ fclean
	rm a.out

re: fclean all