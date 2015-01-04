/*
** marvin.c for marvin in /home/barrau_h/Desktop/marvin
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 22:59:27 2015 Hippolyte Barraud
** Last update Sun Jan  4 23:01:34 2015 Hippolyte Barraud
*/

#include "include/marvin.h"

bool	isDim(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
      if (str[i] == '(' || str[i] == ')')
	return (FALSE);
    i++;
  }
  return (TRUE);
}

void	parse(const char *str)
{
  if (isDim(str) == TRUE)
    parse_declaration(str);
  else
    parse_fonction(str);
}

int	main(int ac, char **av)
{
  if (ac < 2 || ac > 2)
    {
      putchar('\n');
      return (SUCCES);
    }
  syntax_check(av[1]);
  parse(av[1]);
  return (SUCCES);
}
