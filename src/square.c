/*
** SQuare.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ_bootstrap
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Nov 29 09:42:44 2016 Victor Zhu
** Last update Wed Dec 21 17:54:07 2016 Victor Zhu
*/

#include <stdlib.h>
#include "my.h"

char		**strg_dup(int line_nbr, char **strg)
{
  int		i;
  char		**biggest_square;

  i = 0;
  biggest_square = malloc(sizeof(char*) * line_nbr + 1);
  while (i != line_nbr)
    {
      biggest_square[i] = my_strdup(strg[i]);
      i = i + 1;
    }
  biggest_square[i] = my_strdup("\0");
  return (biggest_square);
}

int	find_square_end(int *square_size, char **strg, int line_nbr)
{
  final_square(square_size[4], strg, square_size[2], square_size[3]);
  show_square(strg, line_nbr);
  return (0);
}

int		*check_o(char **strg, int *coord, int line_nbr)
{
  while (strg[coord[0]][coord[1]] == 'o')
    {
      coord[1] = coord[1] + 1;
      if (strg[coord[0]][coord[1]] == '\0')
	{
	  coord[0] = coord[0] + 1;
	  coord[1] = 0;
	}
      if (coord[0] + 1 > line_nbr)
	{
	  find_square_end(coord, strg, line_nbr);
	  exit(0);
	}
    }
  return (coord);
}

int		*check_size_value(int size_value, int *square_size, int i, int j)
{
  if (size_value > square_size[4])
    {
      square_size[2] = i;
      square_size[3] = j;
      square_size[4] = size_value;
    }
  return (square_size);
}


int		find_square(char **strg, int line_nbr)
{
  t_square	*s;
  char		**biggest_square;
  int		*coord;

  s = malloc(sizeof(*s));
  biggest_square = strg_dup(line_nbr, strg);
  coord = malloc(sizeof(int) * 6);
  coord = put_in(coord, biggest_square, line_nbr);
  while (strg[coord[0]][coord[1]] != '\0')
    {
      check_o(strg, coord, line_nbr);
      s->size_value = find_big_square(biggest_square, coord[0], coord[1]);
      check_size_value(s->size_value, coord, coord[0], coord[1]);
      coord[1] = coord[1] + 1;
      if (strg[coord[0]][coord[1]] == '\0' && coord[0] + 1 < line_nbr)
      {
        coord[0] = coord[0] + 1;
        coord[1] = 0;
      }
      check_the_jumpx(coord, biggest_square);
      check_the_jumpy(coord, biggest_square, line_nbr);
    }
  find_square_end(coord, strg, line_nbr);
  return (0);
}
