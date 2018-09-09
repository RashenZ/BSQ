/*
** find_big_square.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ_bootstrap
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Dec  5 17:45:00 2016 Victor Zhu
** Last update Fri Dec 16 13:25:51 2016 Victor Zhu
*/

#include <stdlib.h>
#include "my.h"

int	count_line(char **biggest_square)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (biggest_square[a][b] != '\0')
    {
      b = b + 1;
      if (biggest_square[a][b] == '\0')
	{
	  a = a + 1;
	  b = 0;
	  if (biggest_square[a][b] == '\0')
	    return (a);
	}
    }
  return (a);
}

int	find_big_square_y(char **biggest_square, int i, int j, int y)
{
  int	line;

  line = count_line(biggest_square);
  if (i >= line)
    return (0);
  while (biggest_square[i][j] == '.' && y > 0)
    {
      i = i + 1;
      y = y - 1;
      if (i >= line)
	return (0);
    }
  if (biggest_square[i][j] != '.' && y > 0)
    return (2);
  return (0);
}

int	find_big_square_x(char **biggest_square, int i, int j, int x)
{
  int	line;

  line = count_line(biggest_square);
  if (i >= line)
    return (2);
  while (biggest_square[i][j] == '.' && x > 0)
    {
      j = j + 1;
      x = x - 1;
    }
  if (biggest_square[i][j] != '.' && x > 0)
    return (2);
  return (0);
}

int	find_big_square(char **biggest_square, int i, int j)
{
  t_square	*size;

  size = malloc(sizeof(*size));
  size->square_size = 1;
  size->x = 2;
  size->y = 2;
  size->stock_i = i;
  size->stock_j = j;
  while (biggest_square[i][j])
    {
      size->error = find_big_square_x(biggest_square, size->stock_i + 1,
					j, size->x);
      if (size->error == 2)
	return (size->square_size);
      size->error = find_big_square_y(biggest_square, i,
					size->stock_j + 1, size->y);
      if (size->error == 2)
	return (size->square_size);
      size->x = size->x + 1;
      size->y = size->y + 1;
      size->stock_i = size->stock_i + 1;
      size->stock_j = size->stock_j + 1;
      size->square_size = size->square_size + 1;
    }
  return (size->square_size);
}
