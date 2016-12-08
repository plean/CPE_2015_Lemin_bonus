/*
** end.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr 24 04:47:51 2016 Jean PLANCHER
** Last update Mon Apr 25 13:11:38 2016 Jean PLANCHER
*/

#include "my.h"

void				aff_end(t_bunny_pixelarray *pix)
{
  static t_bunny_pixelarray	*tmp = NULL;
  static t_bunny_music		*m_tmp = NULL;

  if (!pix)
    {
      if (tmp)
	bunny_delete_clipable(&tmp->clipable);
      if (m_tmp)
	{
	  bunny_sound_stop(&m_tmp->sound);
	  bunny_delete_sound(&m_tmp->sound);
	}
      return ;
    }
  if (!tmp)
    {
      load_end(&tmp, &m_tmp);
      if (m_tmp)
	bunny_sound_play(&m_tmp->sound);
    }
  if (tmp)
    fox_mod_stretch(pix, tmp);
}

int	is_ended(int *ants, int end, int nb_ants)
{
  int	i;

  i = -1;
  while (++i < nb_ants)
    {
      if (ants[i] != end)
	return (ON_ERROR);
    }
  return (ON_SUCCESS);
}
