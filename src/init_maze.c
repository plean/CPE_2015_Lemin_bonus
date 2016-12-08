/*
** init_maze.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr 24 00:17:50 2016 Jean PLANCHER
** Last update Sun Apr 24 17:54:25 2016 Jean PLANCHER
*/

#include "my.h"

int	init_maze(t_struct *a)
{
  int	i;

  a->maze = my_malloc(sizeof(t_maze));
  if (get_arguments(a->maze) == -1)
    return (ON_ERROR);
  a->win = bunny_start_style(WIDTH, HEIGHT, TITLEBAR | CLOSE_BUTTON, "Lemin");
  a->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  a->max[0] = get_max_w(a->maze->rooms->first);
  a->max[1] = get_max_h(a->maze->rooms->first);
  a->action = 0;
  a->i = 0;
  a->j = 0;
  a->maze->ants = my_malloc(sizeof(int) * (a->maze->nb_ants + 1));
  a->maze->t_actual = a->maze->turns->first;
  a->pos.x = 0;
  a->pos.y = 0;
  i = -1;
  while (++i < a->maze->nb_ants)
    a->maze->ants[i] = a->maze->start;
  a->maze->ants[i] = 0;
  return (ON_SUCCESS);
}

static void	refresh_rooms(char **data, int *ants)
{
  char		**tab;
  int		i;

  i = -1;
  while (data[++i])
    {
      tab = my_str_to_tab(data[i], '-', '-');
      ants[atoi(tab[0]) - 1] = atoi(tab[1]);
      free_tab(tab);
    }
}

static void	remove_rooms(char **data, int *ants)
{
  char		**tab;
  int		i;

  i = -1;
  while (data[++i])
    {
      tab = my_str_to_tab(data[i], '-', '-');
      ants[atoi(tab[0]) - 1] *= -1;
      ants[atoi(tab[0]) - 1]--;
      free_tab(tab);
    }
}

void	do_action(t_struct *b)
{
  if (!b->i)
    remove_rooms(b->maze->t_actual->data, b->maze->ants);
  move_ants(b);
  b->i++;
  if (b->i > SPEED)
    {
      b->i = 0;
      b->action = 0;
      refresh_rooms(b->maze->t_actual->data, b->maze->ants);
      b->maze->t_actual = b->maze->t_actual->next;
    }
}
