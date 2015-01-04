/*
** parse_fc.c for marvin in /home/barrau_h/Desktop/marvin/fonction
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 14:19:04 2015 Hippolyte Barraud
** Last update Sun Jan  4 19:10:30 2015 arthur beaulieu
*/

#include "../include/marvin.h"

void		analyse_keyword_fc(t_fc_entity *entity, char *keywrd)
{
  if (!entity->type.type)
    entity->type.type = (entity->type.isstruct) ? strcat(strdup("struct "),
							 keywrd) : keywrd;
  else if (keywrd[0] == '*' && !entity->name)
    {
      entity->type.ptr = TRUE;
      entity->type.ptr_depth = get_ptr_depth(keywrd);
      keywrd += entity->type.ptr_depth;
    }
  if (keywrd[strlen(keywrd) - 1] == '(')
    {
      keywrd[strlen(keywrd) - 1] = '\0';
      set_array_config(&entity->type, keywrd);
      entity->name = keywrd;
    }
}

char		*cut_fonction_param(const char *str)
{
  char		*out;
  int		i;

  out = strdup(str);
  i = 0;
  while (out[i] != '(')
    i++;
  out[++i] = '\0';
  return (out);
}

void		get_params(char *params, t_fc_entity *entity)
{
  int		i;
  int		lastx;
  char		*tmp;

  i = 0;
  lastx = 0;
  while (params[i] != '\0')
    {
      if (params[i] == ',' || params[i] == ')')
	{
	  params[i] = ' ';
	  tmp = strndup(params + lastx, i + 1);
	  entity->params[entity->param_count++] = get_declaration(tmp);
	  lastx = i;
	}
      i++;
    }
}

void		detect_params(const char *str, t_fc_entity *entity)
{
  int		i;
  int		end;
  char		*params;

  i = 0;
  end = 0;
  while (str[i] != '(')
    i++;
  if (str[i] == '(' && str[i + 1] == ')')
    {
      entity->param = FALSE;
      return;
    }
  else
    entity->param = TRUE;
  while (str[end] != ')')
    end++;
  params = strndup(str + i + 1, end - i);
  get_params(params, entity);
}

void		parse_fonction(const char *str)
{
  t_fc_entity	entity;
  char		**grammar;
  int		i;
  char		*cpy_str;

  cpy_str = cut_fonction_param(str);
  init_fc_entity(&entity);
  grammar = str_to_wordtab(cpy_str);
  i = 0;
  while (grammar[i])
    {
      analyse_keyword_fc(&entity, grammar[i++]);
    }
  detect_params(str, &entity);
  print_fc_entity(&entity);
}
