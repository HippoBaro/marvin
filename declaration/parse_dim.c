/*
** parse_dim.c for marvin in /home/barrau_h/Desktop/marvin/declaration
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 14:07:57 2015 Hippolyte Barraud
** Last update Sun Jan  4 23:34:32 2015 Hippolyte Barraud
*/

#include"../include/marvin.h"

void		parse_declaration(const char *str)
{
  t_var_entity	entity;
  char		**grammar;
  int		i;

  init_var_entity(&entity);
  grammar = str_to_wordtab(str);
  i = 0;
  while (grammar[i])
    analyse_keyword(&entity, grammar[i++]);
  printf("Déclaration d'");
  print_var_entity(&entity);
  printf(".\n");
  i = 0;
  while (grammar[i])
    free(grammar[i++]);
}

t_var_entity	get_declaration(char *str)
{
  t_var_entity	entity;
  char		**grammar;
  int		i;

  str = trimwhitespace(str);
  init_var_entity(&entity);
  grammar = str_to_wordtab(str);
  i = 0;
  while (grammar[i])
    analyse_keyword(&entity, grammar[i++]);
  return (entity);
}

void		analyse_keyword(t_var_entity *entity, char *keywrd)
{
  if (IS_DIM_USELESS(keywrd))
    return;
  else if (strcmp(keywrd, "struct") == 0)
    entity->isstruct = TRUE;
  else if (strcmp(keywrd, "const") == 0)
    entity->constant = TRUE;
  else if (strcmp(keywrd, "unsigned") == 0 && !entity->type)
    entity->unsign = TRUE;
  else if (!entity->type)
    entity->type = (entity->isstruct) ? strcat(strdup("struct "),
					       keywrd) : keywrd;
  else if (keywrd[0] == '*')
    {
      entity->ptr = TRUE;
      entity->ptr_depth = get_ptr_depth(keywrd);
      keywrd += entity->ptr_depth;
    }
  if (keywrd[strlen(keywrd) - 1] == ';')
    {
      if (!entity->type)
	print_err("Pedantic : Le type de l'élément déclaré est inrouvable.");
      keywrd[strlen(keywrd) - 1] = '\0';
      set_array_config(entity, keywrd);
      entity->name = keywrd;
    }
}

int		get_ptr_depth(char *keywrd)
{
  int		i;
  int		out;

  out = 0;
  i = 0;
  while (keywrd[i] == '*')
    {
      out++;
      i++;
    }
  return (out);
}

void		set_array_config(t_var_entity *entity, char *keywrd)
{
  int		i;
  int		index;
  int		len;

  i = index = 0;
  len = strlen(keywrd) - 1;
  while (i < len)
    {
      if (keywrd[i] == '[')
	{
	  keywrd[i] = '\0';
	  if (keywrd[i + 1] == ']')
	    print_err(SYNTAX_MISSING_ARRAY_SIZE);
	  else
	    {	len = strlen(keywrd) - 1;
	      entity->array = TRUE;
	      entity->array_dimensions = index + 1;
	      entity->array_depth[index] = atoi(keywrd + i);
	      index++;
	    }
	}
      i++;
    }
}
