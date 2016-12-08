/*
** my_free.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Apr 21 10:38:42 2016 Jean PLANCHER
** Last update Sun Apr 24 03:00:55 2016 Jean PLANCHER
*/

#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}

void	del_maze(t_maze *maze)
{
  del_list(&maze->rooms);
  del_list(&maze->tubes);
  del_list(&maze->turns);
  free(maze);
}
