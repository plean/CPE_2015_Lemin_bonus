/*
** get_element.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Apr 23 22:06:46 2016 Jean PLANCHER
** Last update Sat Apr 23 22:06:47 2016 Jean PLANCHER
*/

#include "my.h"

t_element	*get_element(t_list *list, int nb)
{
  t_element 	*tmp;

  tmp = list->first;
  while (tmp && atoi(tmp->data[0]) != nb)
    tmp = tmp->next;
  return ((tmp) ? tmp : NULL);
}
