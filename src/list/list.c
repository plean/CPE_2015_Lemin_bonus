/*
** list.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Mar 27 06:14:14 2016 Jean PLANCHER
** Last update Sun Apr 24 02:54:05 2016 Jean PLANCHER
*/

#include "my.h"

t_list		*create_list(void)
{
  t_list	*list;
  list = my_malloc(sizeof(t_list));
  list->first = NULL;
  list->length = 0;
  return (list);
}

void		add_start(t_list **list, char **data)
{
  t_element	*tmp;

  tmp = my_malloc(sizeof(t_element));
  tmp->data = data;
  tmp->next = (*list)->first;
  (*list)->first = tmp;
  (*list)->length++;
}

void		add_end(t_list **list, char **data)
{
  t_element	*tmp;
  t_element	*temp;

  tmp = my_malloc(sizeof(t_element));
  tmp->data = data;
  temp = (*list)->first;
  if (!temp)
    {
      (*list)->first = tmp;
    }
  else
    {
      while (temp->next)
	temp = temp->next;
      temp->next = tmp;
    }
  tmp->next = NULL;
  (*list)->length++;
}

void		del_list(t_list **list)
{
  t_element	*tmp;
  char		**temp;
  int		i;

  while ((*list)->first != NULL)
    {
      tmp = (*list)->first->next;
      temp = (char **)(*list)->first->data;
      i = -1;
      while (temp[++i])
	free(temp[i]);
      free((*list)->first->data);
      free((*list)->first);
      (*list)->first = tmp;
      (*list)->length--;
    }
  free((*list));
}
