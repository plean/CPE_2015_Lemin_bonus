/*
** parsing.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Apr 21 06:14:39 2016 Jean PLANCHER
** Last update Mon Apr 25 15:06:13 2016 Matthias RIGAUD
*/

#include "my.h"

static int	get_ants(void)
{
  char		*str;
  int		nb;

  str = get_next_line(0);
  if (!str)
    return (-1);
  if (is_alpha(str, '+'))
    {
      free(str);
      return (-1);
    }
  nb = atoi(str);
  return (nb);
}

int	get_arguments(t_maze *maze)
{
  char	*str;
  int	i[2];

  if (!(i[0] = i[1] = 0) && (maze->start = maze->end = -1)
      && (maze->nb_ants = get_ants()) == -1)
    return (ON_ERROR);
  maze->rooms = create_list();
  maze->tubes = create_list();
  maze->turns = create_list();
  while ((str = get_next_line(0)))
    {
      if (!(str[0] == '#' && str[1] == '#'))
	{
	  i[0] = (!i[0] && str[0] && str[1] == '-') ? 1 :
	      ((i[0] == 1 && str[0] == 'P') ? 2 : i[0]);
	  (i[0] == 0) ? add_start(&maze->rooms, my_str_to_tab(str, ' ', ' ')) :
	    (i[0] == 1) ? add_start(&maze->tubes, my_str_to_tab(str, '-', '-')) :
	  add_end(&maze->turns, my_str_to_tab(cut_char(str, ' ', 'P'), 'P', ' '));
	  (i[1] == 1) ? maze->start = atoi(maze->rooms->first->data[0]) :
	    ((i[1] == 2) ? maze->end = atoi(maze->rooms->first->data[0]) : (0));
	}
      i[1] = (!strcmp(str, "##start")) ? 1 : (!strcmp(str, "##end")) ? 2 : 0;
      free(str);
    }
  return (ON_SUCCESS);
}
