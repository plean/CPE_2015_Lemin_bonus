/*
** is_alpha.c for  in /home/planch_j/rendu/CPE/CPE_2015_corewar/corewar/parsing/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 23 15:18:21 2016 Jean PLANCHER
** Last update Thu Apr 21 06:45:41 2016 Jean PLANCHER
*/

#include "my.h"

int	is_alpha(const char *str, char c)
{
  int	i;

  i = -1;
  if (str == NULL || !str[0])
    return (1);
  if (str[0] == '-' && c != '+')
    i++;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
    }
  return (0);
}
