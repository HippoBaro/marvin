/*
** marvin.h for marvin in /home/barrau_h/Desktop/rush_1
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sat Jan  3 15:47:33 2015 Hippolyte Barraud
** Last update Sun Jan  4 23:13:41 2015 Hippolyte Barraud
*/

#ifndef _MARVIN_H_
# define _MARVIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE		1
#define FALSE		0
#define SUCCES		0
#define ERROR		1

#define MAX_DIMENSIONS	99
#define MAX_PARAM_LEN	99

#define ERROR_MALLOC	"Erreur fatale survenue durant l'allocation mémoire."
#define SYNTAX_ERROR	"Erreur de syntaxe. Vous êtes naze."
#define SYNTAX_ENDOFLINE "Pedantic : Le point-virgule n'est pas optionnel."
#define SYNTAX_PARENTHESIS "Pedantic : Parenthese manquante."
#define SYNTAX_HOOK	"Pedantic : Ouverture/Fermeture de crochet manquante."
#define SYNTAX_CHARS	"Lunatic : Votre requete n'est pas comprise"
#define SYNTAX_INCOHERENCE "Lunatic : Entrée incohérente. Faites un effort."
#define SYNTAX_MISSING_ARRAY_SIZE "Certain(s) tableau(x) n'ont pas de taille."

#define IS_FC_USELESS(k) (strcmp(k, "extern") ==  0 || strcmp(k, "inline") ==  0 || strcmp(k, "signed") ==  0) ? TRUE : FALSE
#define IS_DIM_USELESS(k) (strcmp(k, "extern") ==  0 || strcmp(k, "signed") ==  0 || strcmp(k, "volatile") ==  0 || strcmp(k, "register") ==  0 || strcmp(k, "typedef") ==  0) ? TRUE : FALSE

typedef		int bool;

typedef struct	s_var_entity
{
	bool	constant;
	bool	unsign;
	bool	isstruct;
	char	*type;
	char	*name;
	bool	ptr;
	int	ptr_depth;
	bool	array;
	int	array_dimensions;
	int	array_depth[MAX_DIMENSIONS];
}	t_var_entity;

typedef struct	s_fc_entity
{
	t_var_entity	type;
	char		*name;
	bool		param;
	int		param_count;
	t_var_entity	params[99];
}	t_fc_entity;

extern char	*strdup(const char *s);
extern char	*strndup(const char *s, int);

char		**str_to_wordtab(const char *s);
char		*trimwhitespace(char *str);

void		init_fc_entity(t_fc_entity *entity);
void		print_fc_entity(t_fc_entity *entity);

void		init_var_entity(t_var_entity *entity);
void		print_var_entity(t_var_entity *entity);
t_var_entity	*entcpy(t_var_entity entity);

void		parse_declaration(const char *str);
void		analyse_keyword(t_var_entity *entity, char *keywrd);
int		get_ptr_depth(char *keywrd);
void		set_array_config(t_var_entity *entity, char *keywrd);
t_var_entity	get_declaration(char *str);

void		parse_fonction(const char *str);

bool		syntax_check(const char*);
bool		check_valid_char(const char c);
void		print_err(const char*);

#endif
