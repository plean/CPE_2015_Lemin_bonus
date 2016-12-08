/*
** sprite.c for sprite in /home/rigaud_b/rendu/CPE_2015_Lemin/bonus
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Apr 24 16:23:18 2016 Matthias RIGAUD
** Last update Mon Apr 25 13:09:38 2016 Jean PLANCHER
*/

#include <my.h>

void				sprite_display(t_bunny_pixelarray *pix, t_spm *sprite)
{
  t_bunny_position		new;
  t_bunny_position		final;
  t_color			*pixels;
  int				pos;

  pixels = sprite->pix->pixels;
  new.y = -1;
  while (++new.y < (SHEIGHT / sprite->nb_frame_v) &&
	 (new.x = (sprite->pos.x < 0) ? (-sprite->pos.x - 1) : (-1)) >= -1)
    while (++new.x < (SWIDTH / sprite->nb_frame_h) &&
	   sprite->pos.x + new.x < pix->clipable.buffer.width)
      {
	final.y = sprite->pos.y + new.y;
	final.x = sprite->pos.x + new.x;
	pos = (new.y + (SHEIGHT / sprite->nb_frame_v) * sprite->frame_v) *
	  SWIDTH + (SWIDTH / sprite->nb_frame_h) * sprite->frame_h + new.x;
	tekpixel_t(pix, &final, pixels[pos].full);
      }
}

void			draw_ants(t_struct *a,
				  t_bunny_position *pos, int size, int dir)
{
  static t_spm		*sprite = NULL;
  t_bunny_pixelarray	*tmp;

  if (sprite == NULL)
    {
      if (!(tmp = bunny_load_pixelarray("img/ant.png")))
	exit(ON_ERROR);
      sprite = my_malloc(sizeof(t_spm));
      sprite->pix = bunny_new_pixelarray(size * 7, size * 2);
      fox_mod_stretch(sprite->pix, tmp);
      bunny_delete_clipable(&tmp->clipable);
      sprite->frame_speed = 1;
      sprite->nb_frame_h = 7;
      sprite->nb_frame_v = 2;
      sprite->frame_h = 0;
    }
  sprite->pos.x = pos->x - size / 2;
  sprite->pos.y = pos->y - size / 2;
  sprite->frame_v = dir;
  sprite_display(a->pix, sprite);
  sprite->frame_h += sprite->frame_speed * a->j;
  sprite->frame_h %= sprite->nb_frame_h;
}

void			draw_next(t_bunny_pixelarray *pix,
				  t_bunny_position *pos, int size)
{
  static t_spm		*sprite = NULL;
  t_bunny_pixelarray	*tmp;

    if (sprite == NULL)
    {
      if (!(tmp = bunny_load_pixelarray("img/next.png")))
	{
	  bunny_delete_clipable(&tmp->clipable);
	  exit(ON_ERROR);
	}
      sprite = my_malloc(sizeof(t_spm));
      sprite->pix = bunny_new_pixelarray(size, size);
      fox_mod_stretch(sprite->pix, tmp);
      bunny_delete_clipable(&tmp->clipable);
      sprite->nb_frame_h = 1;
      sprite->nb_frame_v = 1;
      sprite->frame_h = 0;
      sprite->frame_v = 0;
    }
  sprite->pos.x = pos->x - size / 2;
  sprite->pos.y = pos->y - size / 2;
  sprite_display(pix, sprite);
}
