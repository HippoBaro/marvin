/*
** var_entity.c for marvin in /home/barrau_h/Desktop/marvin/declaration
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Jan  4 14:09:10 2015 Hippolyte Barraud
** Last update Sun Jan  4 19:07:05 2015 arthur beaulieu
*/

#include "../include/marvin.h"

void	init_var_entity(t_var_entity *entity)
{
  entity->name = NULL;
  entity->type = NULL;
  entity->constant = FALSE;
  entity->unsign = FALSE;
  entity->ptr = FALSE;
  entity->ptr_depth = 0;
  entity->array = FALSE;
  entity->isstruct = FALSE;
}

void	get_str_for_data(char *ptrdeth, char *arraydim,
			 t_var_entity *entity)
{
  if (!(entity->ptr_depth == 0 || entity->ptr_depth == 1))
    sprintf(ptrdeth, "%d ", entity->ptr_depth);
  else
    ptrdeth[0] = '\0';
  if (!entity->array_dimensions == 0)
    sprintf(arraydim, "%d ", entity->array_dimensions);
  else
    arraydim[0] = '\0';
  arraydim[strlen(arraydim) - 1] = '\0';
}

void	print_var_entity(t_var_entity *entity)
{
  char	ptrdeth[15];
  char	arraydim[15];
  
  get_str_for_data(&ptrdeth[0], &arraydim[0], entity);
  printf("%s%s%s %s%s%snommé(e) %s %s%s%s%s%s%s",
	 (entity->ptr) ? "un pointeur" :
	 (entity->array) ? "un tableau" : "une variable",
	 (entity->array && !entity->ptr) ? " de dimension " : "",
	 (entity->array && !entity->ptr) ? arraydim : "",
	 (entity->ptr && entity->ptr_depth != 1) ? "de " : "",
	 (entity->ptr) ? ptrdeth : "",
	 (entity->ptr && entity->ptr_depth != 1) ? "\bème degré " : "",
	 entity->name,
	 (entity->ptr) ? (entity->array) ? "vers un tableaux de type " :
	 "vers une variable de type " : "de type ",
	 entity->type,
	 (entity->array && entity->ptr) ? " et de dimension " : "",
	 (entity->array && entity->ptr) ? arraydim : "",
	 (entity->unsign) ? " non-signée" : "",
	 (entity->constant) ? " en lecture seule" : "");
}
