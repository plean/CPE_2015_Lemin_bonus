/*
** main.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Apr 21 03:04:30 2016 Jean PLANCHER
** Last update Sun Apr 24 19:21:15 2016 Jean PLANCHER
*/

#include "my.h"

static t_bunny_response        test_exit(t_bunny_event_state state,
				  t_bunny_keysym key,
				  void *data)
{
  t_struct              *b;

  b = (t_struct*)data;
  if (state == GO_DOWN && key == BKS_RETURN)
    b->action = 1;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static t_bunny_response        my_refresh(void *a)
{
  t_struct              *b;

  b = (t_struct*)a;
  b->j += ANT_SPEED;
  if (b->j > 1.0 + ANT_SPEED)
    b->j= 0;
  init_screen(b);
  aff_ants(b);
  if (!is_ended(b->maze->ants, b->maze->end, b->maze->nb_ants))
    aff_end(b->pix);
  else
    {
      if (b->action && b->maze->t_actual)
	do_action(b);
      else
	aff_next(b->pix);
    }
  bunny_blit(&(b->win->buffer), &(b->pix->clipable), &b->pos);
  bunny_display(b->win);
  return (GO_ON);
}

int		main(void)
{
  t_struct	a;

  if (init_maze(&a))
    return (ON_ERROR);
  //aff_arg(a.maze);
  bunny_set_loop_main_function(&my_refresh);
  bunny_set_key_response(&test_exit);
  bunny_loop(a.win, 60, (void*)&a);
  bunny_stop(a.win);
  bunny_delete_clipable(&(a.pix->clipable));
  aff_end(NULL);
  del_maze(a.maze);
  return (ON_SUCCESS);
}
