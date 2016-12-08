/*
** tekline.c for  in /home/planch_j/rendu/Info/mystify_2020/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Apr 19 15:51:01 2016 Jean PLANCHER
** Last update Fri Apr 22 23:40:03 2016 Jean PLANCHER
*/

#include "my.h"

static void		vertline(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color t,
				 double add[4])
{
  t_bunny_position	p;
  t_color		tmp;
  int			i;
  int			j;
  int			e;
  int			k;

  e = 0;
  tmp.full = t.full;
  j = pos[0].y > pos[1].y;
  i = (pos[j].y < 0) * -pos[j].y;
  while (i < pos[!j].y - pos[j].y &&
	 i + pos[j].y < pix->clipable.buffer.height)
    {
      p.y = pos[j].y + i;
      p.x = pos[j].x + ((pos[!j].x - pos[j].x) * i) / (pos[!j].y - pos[j].y);
      tekpixel_t(pix, &p, t.full);
      k = -1;
      while (++k < 4)
	t.argb[k] = tmp.argb[k] + e * add[k];
      e++;
      i = i + 1;
    }
}

static void		notvertline(t_bunny_pixelarray *pix,
				    t_bunny_position *pos,
				    t_color t,
				    double add[4])
{
  t_bunny_position	p;
  t_color		tmp;
  int			i;
  int			j;
  int			e;
  int			k;

  e = 0;
  tmp.full = t.full;
  j = pos[0].x > pos[1].x;
  i = (pos[j].x < 0) * -pos[j].x - 1;
  while (i++ < pos[!j].x - pos[j].x &&
	 i + pos[j].x < pix->clipable.buffer.width)
    {
      p.x = pos[j].x + i;
      p.y = pos[j].y + ((pos[!j].y - pos[j].y) * i) / (pos[!j].x - pos[j].x);
      tekpixel_t(pix, &p, t.full);
      k = -1;
      while (++k < 4)
	t.argb[k] = tmp.argb[k] + e * add[k];
      e++;
    }
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				unsigned int *color)
{
  t_color		t;
  t_color		tmp[2];
  double		add[4];
  int			p_color;
  int			i;

  if ((pos[1].y == pos[0].y) || (pos[1].x - pos[0].x) / (pos[1].y - pos[0].y))
    {
      t.full = tmp[0].full = color[!(pos[0].x > pos[1].x)];
      tmp[1].full = color[(pos[0].x > pos[1].x)];
      p_color = fabs(pos[1].x - pos[0].x);
      i = -1;
      while (++i < 4)
	add[i] = (double)(tmp[1].argb[i] - tmp[0].argb[i]) / p_color;
      notvertline(pix, pos, t, add);
    }
  else
    {
      t.full = tmp[0].full = color[!(pos[0].y > pos[1].y)];
      tmp[1].full = color[(pos[0].y > pos[1].y)];
      p_color = fabs(pos[1].y - pos[1 - (i = -1)].y);
      while (++i < 4)
	add[i] = (double)(tmp[1].argb[i] - tmp[0].argb[i]) / p_color;
      vertline(pix, pos, t, add);
    }
}
