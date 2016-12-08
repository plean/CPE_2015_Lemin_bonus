/*
** draw.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 22 23:26:07 2016 Jean PLANCHER
** Last update Sun Apr 24 18:47:23 2016 Jean PLANCHER
*/

#include "my.h"

void		draw_room(t_bunny_pixelarray *pix,
			  const t_bunny_position *pos,
			  unsigned int color)
{
  int		size;

  size = ROOM_SIZE;
  teksquare(pix, pos, color, size);
  while (--size)
    teksquare(pix, pos, BLACK, size);
  tekpixel(pix, pos, BLACK);
}

void			draw_tubes(t_bunny_pixelarray *pix,
				   t_bunny_position *pos)
{
  t_bunny_position	pos_tmp[2];
  unsigned int		color[2];
  double		tmp[2];
  int			sens[2];
  int			div;

  if (!(div = pow(pos[1].x - pos[0].x, 2) + pow(pos[1].y - pos[0].y, 2)))
    return ;
  color[0] = WHITE;
  color[1] = WHITE;
  sens[0] = (pos[1].y - pos[0].y > 0) * 2 - 1;
  sens[1] = (pos[1].x - pos[0].x > 0) * 2 - 1;
  tmp[0] = (double)pow(pos[1].y - pos[0].y, 2) / div;
  tmp[1] = (double)pow(pos[1].x - pos[0].x, 2) / div;
  pos_tmp[0].x = pos[0].x - tmp[0] * PATH_SIZE * sens[1];
  pos_tmp[0].y = pos[0].y + tmp[1] * PATH_SIZE * sens[0];
  pos_tmp[1].x = pos[1].x - tmp[0] * PATH_SIZE * sens[1];
  pos_tmp[1].y = pos[1].y + tmp[1] * PATH_SIZE * sens[0];
  tekline(pix, pos_tmp, color);
  pos_tmp[0].x = pos[0].x + tmp[0] * PATH_SIZE * sens[1];
  pos_tmp[0].y = pos[0].y - tmp[1] * PATH_SIZE * sens[0];
  pos_tmp[1].x = pos[1].x + tmp[0] * PATH_SIZE * sens[1];
  pos_tmp[1].y = pos[1].y - tmp[1] * PATH_SIZE * sens[0];
  tekline(pix, pos_tmp, color);
}

void			aff_ants(t_struct *a)
{
  t_bunny_position	pos;
  t_element		*tmp;
  int			cu;
  int			i;

  cu = 0;
  while (cu * cu < a->maze->nb_ants)
    cu++;
  i = -1;
  while (++i < a->maze->nb_ants)
    {
      if (a->maze->ants[i] < 0)
	continue;
      tmp = get_element(a->maze->rooms, a->maze->ants[i]);
      pos.x = (a->max[0]) ? (BORDER + (WIDTH - BORDER * 2) *
	       atof(tmp->data[1]) / a->max[0]) : WIDTH / 2;
      pos.y = (a->max[1]) ? (BORDER + (HEIGHT - BORDER * 2) *
	       atof(tmp->data[2]) / a->max[1]) : HEIGHT / 2;
      pos.x += -ROOM_SIZE + 2 * ROOM_SIZE * ((i % cu) + 0.5) / cu;
      pos.y += -ROOM_SIZE + 2 * ROOM_SIZE * ((i / cu) + 0.5) / cu;
      draw_ants(a, &pos, (ROOM_SIZE / (1.5 * cu)) * 2, 0);
    }
}

void			move_ants(t_struct *a)
{
  t_bunny_position	pos[2];
  t_element		*tmp[2];
  double		perc;
  char			**tab;
  int			i[2];

  perc = ((double)a->i / SPEED) + (i[0] = -1) * 0;
  while (a->maze->t_actual->data[++i[0]] && (i[1] = -1))
    {
      tab = my_str_to_tab(a->maze->t_actual->data[i[0]], '-', '-');
      tmp[0] = get_element(a->maze->rooms,
			   fabs(a->maze->ants[atoi(tab[0]) - 1] + 1));
      tmp[1] = get_element(a->maze->rooms, atoi(tab[1]));
      while (++i[1] < 2)
	{
	  pos[i[1]].x = (a->max[0]) ? (BORDER + (WIDTH - BORDER * 2) *
			 atof(tmp[i[1]]->data[1]) / a->max[0]) : WIDTH / 2;
	  pos[i[1]].y = (a->max[1]) ? (BORDER + (HEIGHT - BORDER * 2) *
			 atof(tmp[i[1]]->data[2]) / a->max[1]) : HEIGHT / 2;
	}
      pos[0].x += (pos[1].x - pos[0].x) * perc;
      pos[0].y += (pos[1].y - pos[0].y) * perc;
      draw_ants(a, &pos[0], PATH_SIZE, (pos[1].x - pos[0].x > 0));
      free_tab(tab);
    }
}

void	aff_next(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;

  pos.x = WIDTH - NEXT_SIZE * 1.1;
  pos.y = HEIGHT - NEXT_SIZE * 1.1;
  draw_next(pix, &pos, NEXT_SIZE);
}

/*
** a² + b² = 1
** (pos[1].x - pos[0].x)² + (pos[1].y - pos[0].y)² = r²
** (pos[1].x - pos[0].x)² / r² + (pos[1].y - pos[0].y)² / r² = r² / r² = 1
** (pos[1].x - pos[0].x)² / ((pos[1].x - pos[0].x)² + (pos[1].y - pos[0].y)²) = a²
** (pos[1].y - pos[0].y)² / ((pos[1].x - pos[0].x)² + (pos[1].y - pos[0].y)²) = b²
*/
