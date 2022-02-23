# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 15:30:07 by jjuntune          #+#    #+#              #
#    Updated: 2022/02/22 14:24:02 by jjuntune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBRERY = libft/libft.a

FILES = main.c draw_line.c draw_to_image.c get_next_line.c keyhooks.c
FILES += readingmap.c structures.c 
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