/*
** graph.h for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 22 16:52:35 2016 Jean PLANCHER
** Last update Mon Apr 25 13:29:11 2016 Jean PLANCHER
*/

#ifndef GRAPH_H_
# define GRAPH_H

# include <lapin.h>
# include "parsing.h"

# define WIDTH (1400)
# define HEIGHT (1000)
# define BORDER (100)
# define ROOM_SIZE (50)
# define PATH_SIZE (25)
# define SPEED (50)
# define ANT_SPEED (0.2)
# define NEXT_SIZE (80)

typedef struct		s_struct
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_maze		*maze;
  double		j;
  int			max[2];
  int			action;
  int			i;
}			t_struct;

/*
** Main functions
*/

void		draw_room(t_bunny_pixelarray *pix,
			  const t_bunny_position *pos,
			  unsigned int color);
void		draw_tubes(t_bunny_pixelarray *pix,
			   t_bunny_position *pos);
void		aff_ants(t_struct *a);
void		move_ants(t_struct *a);
void		aff_next(t_bunny_pixelarray *pix);
void		del_maze(t_maze *maze);
void		do_action(t_struct *b);
void		aff_end(t_bunny_pixelarray *pix);
void		draw_ants(t_struct *a, t_bunny_position *pos,
			  int size, int dir);
void		draw_next(t_bunny_pixelarray *pix,
			  t_bunny_position *pos, int size);
/*
** Init
*/

int		init_maze(t_struct *a);
void		init_screen(t_struct *a);
int		get_max_w(t_element *room);
int		get_max_h(t_element *room);
void		init_rooms(t_struct *b, t_element *tube);
void		init_tubes(t_struct *b, t_maze *maze);

/*
** Drawing
*/

void		tekpixel(t_bunny_pixelarray *pix,
			 const t_bunny_position *pos,
			 unsigned int color);
void		tekpixel_t(t_bunny_pixelarray *pix,
			   const t_bunny_position *pos,
			   unsigned int color);
unsigned int	my_get_color(const t_bunny_pixelarray *pix,
			     int x,
			     int y);
void		tekline(t_bunny_pixelarray *pix,
			t_bunny_position *pos,
			unsigned int *color);
void		teksquare(t_bunny_pixelarray *pix, const t_bunny_position *pos,
			  unsigned int color, int size);
void		fox_mod_stretch(t_bunny_pixelarray *pix,
				t_bunny_pixelarray *ori);

/*
** End
*/

void		load_end(t_bunny_pixelarray **pix, t_bunny_music **music);

#endif /* !GRAPH_H_ */
