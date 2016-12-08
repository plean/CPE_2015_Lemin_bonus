/*
** init_rooms.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr 23 00:02:23 2016 Jean PLANCHER
** Last update Sun Apr 24 18:10:51 2016 Jean PLANCHER
*/

#include "my.h"

static void		aff_room(t_struct *a, int max[2],
				 char **room)
{
  t_bunny_position	pos;

  pos.x = (max[0]) ? (BORDER + (WIDTH - BORDER * 2) *
	   atof(room[1]) / max[0]) : WIDTH / 2;
  pos.y = (max[1]) ? (BORDER + (HEIGHT - BORDER * 2) *
	   atof(room[2]) / max[1]) : HEIGHT / 2;
  if (atoi(room[0]) == a->maze->start)
    draw_room(a->pix, &pos, START_COLOR);
  else if (atoi(room[0]) == a->maze->end)
    draw_room(a->pix, &pos, END_COLOR);
  else
    draw_room(a->pix, &pos, WHITE);
}

void		init_rooms(t_struct *b, t_element *room)
{
  while (room)
    {
      aff_room(b, b->max, room->data);
      room = room->next;
    }
}
