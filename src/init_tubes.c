/*
** init_tubes.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr 23 00:09:40 2016 Jean PLANCHER
** Last update Sun Apr 24 03:54:35 2016 Jean PLANCHER
*/

#include "my.h"

void			init_tubes(t_struct *b, t_maze *maze)
{
  t_bunny_position	pos[2];
  t_element		*tube;
  t_element		*tmp;
  int			i;

  tube = maze->tubes->first;
  while (tube)
    {
      i = -1;
      while (++i < 2)
	{
	  if (!(tmp = get_element(maze->rooms, atoi(tube->data[i]))))
	    continue;
	  pos[i].x = (b->max[0]) ? (BORDER + (WIDTH - BORDER * 2) *
		      atof(tmp->data[1]) / b->max[0]) : WIDTH / 2;
	  pos[i].y = (b->max[1]) ? (BORDER + (HEIGHT - BORDER * 2) *
		      atof(tmp->data[2]) / b->max[1]) : HEIGHT / 2;
	}
      draw_tubes(b->pix, pos);
      tube = tube->next;
    }
}
