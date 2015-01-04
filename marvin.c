
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
  if (ac == 1)
    {
      putchar('\n');
      return (SUCCES);
    }
  syntax_check(av[1]);
  parse(av[1]);
  return (SUCCES);
}
