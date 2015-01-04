/*
** fc_entity.c for marvin in /home/barrau_h/Desktop/marvin/fonction
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 14:31:12 2015 Hippolyte Barraud
** Last update Sun Jan  4 19:07:49 2015 arthur beaulieu
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

void	print_fc_entity(t_fc_entity *entity)
{
  int	i;

  i = 0;
  printf("Déclaration d'une fonction %s ", entity->name);
  printf("renvoyant un %s. ", entity->type.type);
  if (entity->param)
    {
      printf("Elle prend en paramettre %d variable(s) : ",
	     entity-> param_count);
      while (i != entity->param_count)
	{
	  print_var_entity(&(entity->params[i]));
	  i++;
	  if (i != entity->param_count)
	    printf(", ");
	}
    }
  printf("\n");
}
