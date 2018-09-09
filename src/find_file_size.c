/*
** find_file_size.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ_bootstrap
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Wed Dec  7 12:35:46 2016 Victor Zhu
** Last update Fri Dec 16 13:45:16 2016 Victor Zhu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

unsigned int	find_file_size(char **av)
{
  struct stat	sb;
  unsigned int	size;

  if (stat(av[1], &sb) == -1)
    {
      my_putstr("Error\n");
      exit (84);
    }
  size = sb.st_size;
  return (size);
}

int		*put_in(int *put_value, char **biggest_square, int line_nbr)
{
  put_value[0] = 0;
  put_value[1] = 0;
  put_value[2] = 0;
  put_value[3] = 0;
  put_value = check_o(biggest_square, put_value, line_nbr);
  put_value[4] = find_big_square(biggest_square, 0, 0, line_nbr);
  return (put_value);
}
