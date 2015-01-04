/*
** lib.c for marvin in /home/barrau_h/Desktop/marvin/lib
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 17:47:25 2015 Hippolyte Barraud
** Last update Sun Jan  4 17:47:47 2015 Hippolyte Barraud
*/

#include "../include/marvin.h"

void	print_err(const char *str)
{
  printf("%s\n%s\n", SYNTAX_ERROR, str);
  exit(ERROR);
}
