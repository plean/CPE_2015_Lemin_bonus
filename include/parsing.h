/*
** parsing.h for  in /home/planch_j/rendu/CPE/CPE_2015_Lemin/bonus/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Thu Apr 21 04:19:17 2016 Jean PLANCHER
** Last update Sun Apr 24 18:08:50 2016 Jean PLANCHER
*/

#ifndef PARSING_H_
# define PARSING_H_

# include "list.h"

# define ON_ERROR (-1)
# define ON_SUCCESS (0)
# define START_COLOR (BLUE)
# define END_COLOR (RED)

typedef struct	s_maze
{
  int		nb_ants;
  t_list	*rooms;
  t_list	*tubes;
  t_list	*turns;
  t_element	*t_actual;
  int		*ants;
  int		start;
  int		end;
}		t_maze;

/*
** Parsing
*/

int	get_arguments(t_maze *maze);
int	*tab_to_int_tab(char **str);

/*
** Misc
*/

void	aff_arg(t_maze *maze);
void	free_tab(char **tab);
char	*cut_char(char *buffer, char c1, char c2);
int	is_ended(int *ants, int end, int nb_ants);

#endif /* !PARSING_H_ */
