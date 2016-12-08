##
## Makefile for  in /home/planch_j/rendu/Info/gfx_raytracer1/src/
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Mon Feb 22 18:22:55 2016 Jean PLANCHER
## Last update Mon Apr 25 15:08:07 2016 Matthias RIGAUD
##

CC			= gcc

RM     	= rm -f

CFLAGS	+= -L/home/${USER}/.froot/lib/ \
					 -llapin \
					 -lsfml-audio \
           -lsfml-graphics \
           -lsfml-window \
           -lsfml-system \
           -lstdc++ \
           -ldl \
           -lm \


CFLAGS 	+= -W -Wall -Wextra -lmy -O3
CFLAGS  += -I../include/ -I/home/${USER}/.froot/include/ -L../lib/

NAME  	= ../bonus

SRCS   	= main.c \
	  cut_char.c \
		draw.c \
		tekline.c \
		tekpixel.c \
		teksquare.c \
		parsing.c \
		get_element.c \
		init_max.c \
		init_maze.c \
		init_screen.c \
		init_tubes.c \
		init_rooms.c \
		get_next_line.c \
		my_free.c \
		load_end.c \
		end.c \
		list/list.c \
		sprite.c \
		fox_mod_stretch.c

OBJS   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "\e[0m"
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
	@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreated !\e[0m"

clean:
	@echo -en "\e[0mCleaning .o files..."
	@$(RM) $(OBJS)
	@echo -e "       [\e[32mOk !\e[39m]\e[0m"

fclean: clean
	@echo -en "\e[39mCleaning executable..."
	@$(RM) $(NAME)
	@echo -e "		[\e[32m0k !\e[39m]\e[0m"

re: fclean all

.c.o:%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY: all clean fclean re
