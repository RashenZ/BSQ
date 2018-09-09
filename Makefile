##
## Makefile for emacs in /home/Victor/101pong
## 
## Made by Victor Zhu
## Login   <Victor@epitech.net>
## 
## Started on  Mon Nov  7 11:11:25 2016 Victor Zhu
## Last update Fri Dec 23 15:10:14 2016 Victor Zhu
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./include/

SRCS	=	lib/my_put_nbr.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c		\
		lib/my_strlen.c		\
		lib/my_strcpy.c		\
		lib/my_strdup.c		\
		src/find_big_square.c	\
		src/find_file_size.c	\
		src/check_jump.c	\
		src/show_square.c	\
		src/square.c		\
		src/error.c		\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	all clean

.PHONY:	all clean fclean re
