/*
** check_jump.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Dec 13 16:31:14 2016 Victor Zhu
** Last update Wed Dec 14 14:27:30 2016 Victor Zhu
*/

#include <stdlib.h>
#include "my.h"

int	*check_the_jumpx(int *coord, char **biggest_square)
{
  int	x;

  x = coord[4];
  while (x != 0)
    {
      if (biggest_square[coord[0]][coord[1] + x] == '\0' ||
	  (biggest_square[coord[0]][coord[1] + x] == 'o' &&
	   biggest_square[coord[0]][coord[1] + x + 1] == '\0'))
	{
	  coord[0] = coord[0] + 1;
	  coord[1] = 0;
	  return (coord);
	}
      if (biggest_square[coord[0]][coord[1] + x] == 'o' &&
	  biggest_square[coord[0]][coord[1] + x + 1] == '.')
	{
	  coord[1] = coord[1] + x + 1;
	  x = coord[4] + 1;
	}
      x = x - 1;
    }
  return (coord);
}

int	*check_the_jumpy(int *coord, char **biggest_square, int line_nbr)
{
  int	y;

  y = coord[4];
  while (y != 0)
    {
      if (coord[0] + y > line_nbr)
	{
	  find_square_end(coord, biggest_square, line_nbr);
	  exit (0);
	}
      if (biggest_square[coord[0] + y][coord[1]] == 'o')
	{
	  coord[1] = coord[1] + 1;
	  y = coord[4] + 1;
	}
      y = y - 1;
    }
  return (coord);
}
