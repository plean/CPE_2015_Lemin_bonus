/*
** teksquare.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr 23 00:03:16 2016 Jean PLANCHER
** Last update Sat Apr 23 00:04:54 2016 Jean PLANCHER
*/

#include "my.h"

void	teksquare(t_bunny_pixelarray *pix, const t_bunny_position *pos,
		  unsigned int color, int size)
{
  t_bunny_position	s_pos[2];
  unsigned int		s_color[2];

  s_color[0] = color;
  s_color[1] = color;
  s_pos[0].x = pos->x - size;
  s_pos[0].y = pos->y - size;
  s_pos[1].x = pos->x + size;
  s_pos[1].y = pos->y - size;
  tekline(pix, s_pos, s_color);
  s_pos[1].x = pos->x - size;
  s_pos[1].y = pos->y + size;
  tekline(pix, s_pos, s_color);
  s_pos[0].x = pos->x + size;
  s_pos[0].y = pos->y + size;
  tekline(pix, s_pos, s_color);
  s_pos[1].x = pos->x + size;
  s_pos[1].y = pos->y - size;
  tekline(pix, s_pos, s_color);
}
