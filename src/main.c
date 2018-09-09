/*
** main.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ_bootstrap
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Nov 28 13:39:50 2016 Victor Zhu
** Last update Sun Dec 18 21:55:35 2016 Victor Zhu
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "my.h"

char	*check_alloc_mem(char *str)
{
  if (str == NULL)
    {
      my_putstr("error alloc");
      exit (84);
    }
  return (str);
}

char	**my_put_in_list(char *buff, int i, int line_nbr, int lenght)
{
  int	a;
  int	b;
  char	**str;

  a = 0;
  b = 0;
  str = malloc(sizeof(char*) * line_nbr + 1);
  while (buff[i] != '\0')
    {
      str[a] = malloc(lenght + 1);
      check_alloc_mem(str[a]);
      while (buff[i] != '\n')
	{
	  str[a][b] = buff[i];
	  i = i + 1;
	  b = b + 1;
	}
      str[a][b] = '\0';
      b = 0;
      a = a + 1;
      i = i + 1;
    }
  str[a] = NULL;
  check_error_third_part(str);
  return (str);
}

int	square_stock(char *buff)
{
  int	i;
  int	start_point;
  int	line_nbr;
  int	lenght;
  char	**str;

  i = 0;
  line_nbr = 0;
  while (buff[i] != '\n')
    i = i + 1;
  i = i + 1;
  start_point = i;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	{
	  line_nbr = line_nbr + 1;
	  if (line_nbr == 1)
	    lenght = i - start_point;
	}
      i = i + 1;
    }
  str = my_put_in_list(buff, start_point, line_nbr, lenght);
  find_square(str, line_nbr);
  return (0);
}

int	my_square(char **av)
{
  int	size;
  int	file;
  char	*buff;
  unsigned int	file_size;

  if ((file = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr("error open\n");
      exit(84);
    }
  file_size = find_file_size(av);
  buff = malloc(file_size + 1);
  size = read(file, buff, file_size);
  buff[size] = '\0';
  if (close(file) == -1)
    exit (84);
  check_error(buff);
  square_stock(buff);
  free (buff);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2)
    {
      my_putstr("Syntax error\n");
      return (84);
    }
  else if (av[1])
    my_square(av);
  else
    {
      my_putstr("Syntax error : too much arguments\n");
      return (84);
    }
}
