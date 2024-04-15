/* declarations */
%{
#include "definitions.h"
#include "globals.h"

%}

/* union 
returntypes for $$?
*/
%union {
  id_info_ptr id_value;
  type_desc_ptr type_value;
  int i_value;
  char* s_value;

}


/* tokens */
/* token BANK 
write read open_parenth close_parenth
or if  
*/
%start PROGRAM

%token FUNC PROC
%token BEGIN WHILE DO
/* precedence is in ascending order */
%nonassoc ASSIGN
%nonassoc EQ GT LT GTE LTE
%left '+' '-'
%left'*' '/' '%'
%left UMINUS


/* grammar rules */
%%
PROGRAM: PROGRAM


%%
/* c code */