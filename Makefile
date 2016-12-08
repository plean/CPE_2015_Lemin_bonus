##
## Makefile for  in /home/planch_j/rendu/Info/gfx_raytracer1/
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Mon Feb 22 18:22:47 2016 Jean PLANCHER
## Last update Sun Apr 10 19:02:50 2016 Jean PLANCHER
##

all:
	make -C lib
	make -C src

clean:
	make clean -C lib
	make clean -C src

fclean: clean
	make fclean -C lib
	make fclean -C src

re: fclean all

.PHONY: all clean fclean re
