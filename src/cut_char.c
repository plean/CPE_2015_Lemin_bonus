/*
** cut_char.c for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Apr 22 15:14:26 2016 Jean PLANCHER
** Last update Fri Apr 22 15:15:22 2016 Jean PLANCHER
*/

#include "my.h"

char	*cut_char(char *buffer, char c1, char c2)
{
  int	i;
  int	e;

  e = 0;
  i = -1;
  if (!buffer)
    return (NULL);
  while (buffer[++i])
    {
      if (buffer[i] != c1 && buffer[i] != c2)
	buffer[e++] = buffer[i];
      if ((buffer[i] == c1 || buffer[i] == c2) && e > 0 &&
	  buffer[e - 1] != c1 && buffer[e - 1] != c2)
	buffer[e++] = c1;
    }
  if (e && buffer[e - 1] == c1)
    e--;
  buffer[e] = 0;
  return (buffer);
}
