/*
** init_screen.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr 23 22:09:45 2016 Jean PLANCHER
** Last update Sat Apr 23 22:35:43 2016 Jean PLANCHER
*/

#include "my.h"

void	init_screen(t_struct *a)
{
  int		i;

  i = -1;
  while (++i < WIDTH * HEIGHT)
    ((unsigned int *)a->pix->pixels)[i] = BLACK;
  init_tubes(a, a->maze);
  init_rooms(a, a->maze->rooms->first);
}
