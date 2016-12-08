/*
** tekpixel.c for  in /home/planch_j/rendu/Info/chromatic_2020
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Feb  5 14:42:15 2016 Jean PLANCHER
** Last update Sun Apr 24 01:29:47 2016 Jean PLANCHER
*/

#include "my.h"

unsigned int		my_get_color(const t_bunny_pixelarray *pix,
				     int x,
				     int y)
{
  t_bunny_position	pos;
  unsigned int		*pixel;

  if (x < 0 || y < 0 || x >= pix->clipable.clip_width ||
      y >= pix->clipable.clip_height)
    return (0);
  pos.x = x;
  pos.y = y;
  pixel = (unsigned int*)pix->pixels;
  return (pixel[pix->clipable.clip_width * pos.y + pos.x]);
}

void		tekpixel_t(t_bunny_pixelarray *pix,
			   const t_bunny_position *pos,
			   unsigned int color)
{
  unsigned int	*pixel;
  double	percent;
  t_color	t;
  t_color	c;

  t.full = color;
  percent = (double)t.argb[3] / 255.0;
  if (percent != 1)
    {
      c.full = my_get_color(pix, pos->x, pos->y);
      c.argb[2] = t.argb[2] * percent + c.argb[2] * (1 - percent);
      c.argb[1] = t.argb[1] * percent + c.argb[1] * (1 - percent);
      c.argb[0] = t.argb[0] * percent + c.argb[0] * (1 - percent);
    }
  else
    c.full = t.full;
  pixel = (unsigned int *)pix->pixels;
  if (pos->y >= 0 && pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y < pix->clipable.clip_height)
  pixel[pix->clipable.clip_width * pos->y + pos->x] = c.full;
}

void		tekpixel(t_bunny_pixelarray *pix,
			 const t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*pixel;

  pixel = (unsigned int *)pix->pixels;
  if (pos->y >= 0 && pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y < pix->clipable.clip_height)
  pixel[pix->clipable.clip_width * pos->y + pos->x] = color;
}
