/*
** load_end.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Apr 24 19:23:33 2016 Jean PLANCHER
** Last update Sun Apr 24 19:39:18 2016 Jean PLANCHER
*/

#include "my.h"

static void	end_1(t_bunny_pixelarray **pix, t_bunny_music **music)
{
  *pix = bunny_load_pixelarray("img/AntManPoster1.jpg");
  *music = bunny_load_music("music/AntMan.wav");
}

static void	end_2(t_bunny_pixelarray **pix, t_bunny_music **music)
{
  *pix = bunny_load_pixelarray("img/ProWrestling.png");
  *music = bunny_load_music("music/TemShop.wav");
}

static void	end_3(t_bunny_pixelarray **pix, t_bunny_music **music)
{
  *pix = bunny_load_pixelarray("img/IkaMasume.jpg");
  *music = bunny_load_music("music/IkaMusume.wav");
}

static void	end_4(t_bunny_pixelarray **pix, t_bunny_music **music)
{
  *pix = bunny_load_pixelarray("img/scott_brown_nak.jpg");
  *music = bunny_load_music("music/Gunther.wav");
}

void	load_end(t_bunny_pixelarray **pix, t_bunny_music **music)
{
  int	k;

  k = rand() % 5;
  if (k == 0)
    end_1(pix, music);
  else if (k == 1)
    end_2(pix, music);
  else if (k == 2)
    end_3(pix, music);
  else if (k == 3)
    end_4(pix, music);
  else if (k == 4)
    *pix = bunny_load_pixelarray("img/myfirstever.jpg");
}
