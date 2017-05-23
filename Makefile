# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afanneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:10:35 by afanneau          #+#    #+#              #
#    Updated: 2017/04/07 17:27:03 by afanneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SOURCES =  sources/main.c \
		   sources/init.c \
		   sources/raycasting.c \
		   sources/print.c \
		   sources/event.c \
		   sources/draw_map.c \
		   sources/calc.c \
		   sources/next_lvl.c \
		   sources/check_tab.c \

OBJECTS =  main.o \
		   init.o \
		   raycasting.o \
		   print.o \
		   event.o \
		   draw_map.o \
		   calc.o \
		   next_lvl.o \
		   check_tab.o \

all : $(NAME)

$(NAME) :
	make -C libft/ && make -C libft/ clean
	make -C minilibx/
	gcc -Wall -Wextra -Werror -I libft/includes -c $(SOURCES) -Iincludes -O2
	gcc -o $(NAME) $(OBJECTS) -L libft/ -lft minilibx/libmlx.a -framework OpenGL -framework AppKit -O2

clean :
	rm -f  $(OBJECTS)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
