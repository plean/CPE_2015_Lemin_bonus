/*
** init_max.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr 23 00:13:31 2016 Jean PLANCHER
** Last update Sat Apr 23 00:14:47 2016 Jean PLANCHER
*/

#include "my.h"

int	get_max_w(t_element *room)
{
  int		i, k;

  i = atoi(room->data[1]);
  while (room)
    {
      k = atoi(room->data[1]);
      if (k > i)
	i = k;
      room = room->next;
    }
  return (i);
}

int	get_max_h(t_element *room)
{
  int		i, k;

  i = atoi(room->data[2]);
  while (room)
    {
      k = atoi(room->data[2]);
      if (k > i)
	i = k;
      room = room->next;
    }
  return (i);
}
