/*
** syntax_handler.c for rush in /home/barrau_h/Desktop/rush_1
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sat Jan  3 15:26:49 2015 Hippolyte Barraud
** Last update Sun Jan  4 19:03:49 2015 arthur beaulieu
*/

#include "include/marvin.h"

bool	check_basic_coherence(const char *str)
{
  int	i;
  bool	space;

  i = 0;
  while (str[i] != '\0')
    {
      if (check_valid_char(str[i]) == TRUE)
	{
	  print_err(SYNTAX_CHARS);
	  return (TRUE);
	}
      if (str[i] == ' ')
	space = TRUE;
      i++;
    }
  if (space == FALSE)
    {
      print_err(SYNTAX_INCOHERENCE);
      return (TRUE);
    }
  return (FALSE);
}

bool	check_hook(const char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '[')
	count++;
      else if (str[i] == ']')
	count--;
      i++;
    }
  if (count != 0)
    {
      print_err(SYNTAX_HOOK);
      return (TRUE);
    }
  return (FALSE);
}

bool	check_parenthesis(const char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	count++;
      else if (str[i] == ')')
	count--;
      i++;
    }
  if (count != 0)
    {
      print_err(SYNTAX_PARENTHESIS);
      return (TRUE);
    }
  return (FALSE);
}

bool	check_endofline(const char *str)
{
  int	len;

  len = strlen(str) - 1;
  while (str[len] == ' ')
    len--;
  if (str[len] != ';')
    {
      print_err(SYNTAX_ENDOFLINE);
      return (TRUE);
    }
  return (FALSE);
}

bool	syntax_check(const char *str)
{
  if (check_basic_coherence(str) == TRUE)
    return (TRUE);
  if (check_endofline(str) == TRUE)
    return (TRUE);
  if (check_parenthesis(str) == TRUE)
    return (TRUE);
  if (check_hook(str) == TRUE)
    return (TRUE);
  return (FALSE);
}
