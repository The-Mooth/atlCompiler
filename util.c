#include "definitions.h"
#include "globals.h"



void debug_printf(char* line, ...) 
{
  if (debug) {
    va_list args;
    va_start(args, line);
    vprintf(line, args);
    va_end(args);
    };
}


void yyerror(char* err_msg, ...) {
  errors_found = TRUE;

  //prep error format
  char line_buff[100];
  char line_buff2[200]; 
  sprintf(line_buff, "on line: %d in file %s: ", line_no, src_name);

  //add error message
  va_list args;
  va_start(args, err_msg);
  vsprintf(line_buff2, err_msg, args);
  va_end(args);
  strcat(line_buff, line_buff2);
  fprintf(stderr, "%s\n", line_buff);
}