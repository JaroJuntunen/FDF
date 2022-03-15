# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 15:30:07 by jjuntune          #+#    #+#              #
#    Updated: 2022/03/09 13:17:15 by jjuntune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBRERY = libft/libft.a

FILES = main.c draw_line.c draw_to_image.c get_next_line.c keyhooks.c
FILES += readingmap.c structures.c

OFILES = $(FILES:.c=.o)

COMP = gcc -Wall -Wextra -Werror

INCLUDES = -I /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(OFILES) $(LIBRERY)
	$(COMP) $(OFILES) $(LIBRERY) $(INCLUDES) -o $(NAME)

%.o:%.c
	$(COMP) $(FLAGS) -c $(FILES) $<

$(LIBRERY):
	make -C libft/

clean:
	rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all