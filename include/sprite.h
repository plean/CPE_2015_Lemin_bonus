/*
** sprite.h for sprite in /home/rigaud_b/rendu/CPE_2015_Lemin/bonus
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Apr 24 16:20:03 2016 Matthias RIGAUD
** Last update Sun Apr 24 17:43:47 2016 Jean PLANCHER
*/

#ifndef SPRITE_H_
# define SPRITE_H_

/*
** Include
*/

#include <lapin.h>

/*
** Typedef && define
*/

# define SWIDTH				sprite->pix->clipable.buffer.width
# define SHEIGHT			sprite->pix->clipable.buffer.height

/*
** Struct
*/

typedef struct		s_spm
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  int			frame_speed;
  int			nb_frame_h;
  int			nb_frame_v;
  int			frame_h;
  int			frame_v;
}			t_spm;

/*
** End
*/

#endif /* SPRITE_H_ */
