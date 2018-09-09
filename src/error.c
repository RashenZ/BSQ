/*
** error.c for emacs in /home/Victor/BSQ/CPE_2016_BSQ
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Thu Dec  8 14:52:20 2016 Victor Zhu
** Last update Sun Dec 18 21:55:48 2016 Victor Zhu
*/

#include <stdlib.h>
#include "my.h"

int	check_error_third_part(char **str)
{
  int	i;
  int	j;
  int	size;

  i = 0;
  j = 0;
  size = 0;
  while (str[i] != '\0')
    {
      j = j + 1;
      if (str[i][j] == '\0')
	{
	  i = i + 1;
	  if (i == 1)
	    size = j;
	  if (size != j)
	    {
	      my_putstr("Syntax error: invalid size of line\n");
	      exit (84);
	    }
	  j = 0;
	}
    }
  return (0);
}

int	check_error_second_part(char *buff, int i)
{
  int	number;
  int	line_nbr;

  number = 0;
  line_nbr = 0;
  while (buff[i] != '\n')
    {
      number = number * 10 + (buff[i] - '0');
      i = i + 1;
    }
  i = i + 1;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	line_nbr = line_nbr + 1;
      i = i + 1;
    }
  if (line_nbr != number)
    {
      my_putstr("Syntax error: Invalid number of line\n");
      exit (84);
    }
  //check_error_third_part(buff, 0, 0, 1);
  return (0);
}

int	check_error(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\n')
    {
      if (buff[i] >= '0' && buff[i] <= '9')
	i = i + 1;
      else
	{
	  my_putstr("invalid number\n");
	  exit (84);
	}
    }
  while (buff[i] != '\0')
    {
      if (buff[i] == 'o' || buff[i] == '.' || buff[i] == '\n')
	i = i + 1;
      else
	{
	  my_putstr("Syntax error\n");
	  exit (84);
	}
    }
  check_error_second_part(buff, 0);
  return (0);
}
