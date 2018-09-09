/*
** my.h for emacs in /home/Victor/BSQ/CPE_2016_BSQ_bootstrap
** 
** Made by Victor Zhu
** Login   <Victor@epitech.net>
** 
** Started on  Mon Nov 28 14:57:55 2016 Victor Zhu
** Last update Tue Dec 20 01:44:28 2016 Victor Zhu
*/

#ifndef MY_H
#define MY_H

#define SYNTAX_ERROR

typedef struct	s_square
{
  int	square_size;
  int	size_value;
  int	i;
  int	j;
  int	a;
  int	b;
  int	stock_i;
  int	stock_j;
  int	x;
  int	y;
  int	error;
  char	**strsq;
}		t_square;

//typedef struct s_square	t_square;

int	my_putchar (char c);
int	my_put_nbr();
int	my_putstr();
int	my_strlen();
unsigned int	find_file_size();
void	show_square();
char	*my_strdup();
char	*my_strcpy();
int	find_big_square();
int	find_square();
char	**final_square();
int	find_big_square();
int	check_error();
int	check_error_third_part();
int	*put_in();
int	*check_the_jumpx();
int	*check_the_jumpy();
int	find_square_end();
int	*check_o();

#endif
