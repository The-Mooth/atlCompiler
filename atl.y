/* declarations */
%{
#include "definitions.h"
#include "globals.h"

%}

/* union 
returntypes for $$?
*/
%union {
  id_desc_ptr id_value;
  type_info_ptr type_value;
  int i_value;
  char* s_value;

  node_ptr ast;

}


/* tokens */
/* token BANK 
write read open_parenth close_parenth
or if  
*/
%start PROGRAM

%token PROGRAM
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

PROGRAM : PROGRAM ID

%%
/* c code */