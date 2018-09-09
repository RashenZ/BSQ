/*
** show_square.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ_bootstrap
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Tue Dec  6 15:21:55 2016 Victor Zhu
** Last update Thu Dec  8 11:14:16 2016 Victor Zhu
*/

#include "my.h"

void	show_square(char **str, int line_nbr)
{
  int	i;

  i = 0;
  while (i != line_nbr)
  {
    my_putstr(str[i]);
    i = i + 1;
    my_putchar('\n');
  }
}

char	**final_square(int square_size, char **strg, int i, int j)
{
  int	stock_sqsize;
  int	stock_line;
  int	stock_j;

  stock_j = j;
  stock_sqsize = square_size;
  stock_line = square_size - 1;
  while (square_size != 0)
    {
      strg[i][j] = 'x';
      j = j + 1;
      square_size = square_size - 1;
      if (square_size == 0 && stock_line != 0)
	{
	  i = i + 1;
	  square_size = stock_sqsize;
	  stock_line = stock_line - 1;
	  j = stock_j;
	}
    }
  return (strg);
}
