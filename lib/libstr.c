/*
** libstr.c for beauli_a in /home/beauli_a/rush_1/save/modif2/marvin/lib
** 
** Made by arthur beaulieu
** Login   <beauli_a@epitech.net>
** 
** Started on  Sun Jan  4 19:11:11 2015 arthur beaulieu
** Last update Sun Jan  4 19:12:25 2015 arthur beaulieu
*/

#include "../include/marvin.h"

bool	check_valid_char(const char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9'))
    return (FALSE);
  else if (c == ',' || c == '_' || c == '*' || c == ';' || c == '('
	   || c == ')' || c == '[' || c == ']' || c == ' ' || c == '\0'
	   || c == '\n')
    return (FALSE);
  return (TRUE);
}

char	*trimwhitespace(char *str)
{
  char	*end;

  while (isspace(*str))
    str++;
  if (*str == 0)
    return str;
  end = str + strlen(str) - 1;
  while (end > str && isspace(*end))
    end--;
  *(end + 1) = ';';
  *(end + 2) = 0;
  return str;
}

int    	cut_words(char *s)
{
  int  	i;
  int  	count;

  i = 0;
  count = 1;
  while (s[i])
    {
      if (s[i] == ' ')
	{
	  s[i] = '\0';
	  count++;
	}
      i++;
    }
  return (count);
}

void   	print_wordtab(char **tab)
{
  int  	i;

  i = 0;
  while (tab[i])
    {
      printf("tab[%d]: %s\n", i, tab[i]);
      i++;
    }
}

char   	**str_to_wordtab(const char *s)
{
  int  	i;
  int  	j;
  int  	count;
  char 	*s_cpy;
  char 	**res;

  i = j = 0;
  s_cpy = 0;
  if (s == NULL)
    return (NULL);
  s_cpy = strdup(s);
  count = cut_words(s_cpy);
  if ((res = malloc(sizeof(char *) * (count + 1))) == NULL)
    print_err(ERROR_MALLOC);
  while (count > 0)
    {
      res[j] = strdup(&s_cpy[i]);
      while (s_cpy[i]) i++;
      i++;
      j++;
      count--;
    }
  res[j] = 0;
  free(s_cpy);
  return (res);
}
