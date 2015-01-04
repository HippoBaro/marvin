/*
** fc_entity.c for marvin in /home/barrau_h/Desktop/marvin/fonction
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 14:31:12 2015 Hippolyte Barraud
** Last update Sun Jan  4 23:26:11 2015 Hippolyte Barraud
*/

#include "../include/marvin.h"

void	init_fc_entity(t_fc_entity *entity)
{
  entity->name = NULL;
  entity->param = FALSE;
  entity->type.name = NULL;
  entity->type.type = NULL;
  entity->type.constant = FALSE;
  entity->type.unsign = FALSE;
  entity->type.ptr = FALSE;
  entity->type.ptr_depth = 0;
  entity->type.array = FALSE;
  entity->type.isstruct = FALSE;
  entity->param_count = 0;
}

void	print_fc_params(t_fc_entity *entity)
{
  int	i;

  i = 0;
  if (entity->param)
    {
      printf(". Elle prend %d parametre(s) : ",
	     entity-> param_count);
      while (i != entity->param_count)
	{
	  print_var_entity(&(entity->params[i]));
	  i++;
	  if (i < entity->param_count - 1)
	    printf(", ");
	  else if (i == entity->param_count - 1)
	    printf(" et ");
	}
    }
}

void	print_fc_entity(t_fc_entity *entity)
{
  printf("Déclaration d'une fonction %s ", entity->name);
  printf("qui retourne un %s ", (entity->type.ptr) ?
	 "pointeur" : (strcmp(entity->type.type, "void") == 0) ?
	 "\b\b\b\b\b\brien." : "type");
  if (entity->type.ptr && entity->type.ptr_depth > 1)
    printf("de profondeur %d ", entity->type.ptr_depth);
  printf("%s", (entity->type.ptr) ? "sur type " : "");
  if (!strcmp(entity->type.type, "void") == 0)
    printf("%s%s%s", entity->type.type, (entity->type.unsign) ?
	   " non-signée" : "", (entity->type.constant) ?
	   " en lecture seule" : "");
  print_fc_params(entity);
}
