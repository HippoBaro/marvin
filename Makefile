##
## Makefile for my_select in /home/barrau_h/Desktop/my_select
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Thu Dec 25 17:11:33 2014 Hippolyte Barraud
## Last update Sun Jan  4 20:16:30 2015 Hippolyte Barraud
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Werror -Wextra -Wall -ansi -pedantic

NAME	= marvin

SRCS	= marvin.c \
	  syntax_handler.c \
	  lib/libstr.c \
	  declaration/var_entity.c \
	  declaration/parse_dim.c \
	  fonction/parse_fc.c \
	  fonction/fc_entity.c \
          lib/lib.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
