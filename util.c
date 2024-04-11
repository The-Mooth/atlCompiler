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


void gen_error(char* err_msg, ...) {
  errors_found = TRUE;

  char line_buff[50] = sprintf_s("on line: %d in file %s: ", line_no, src_name);
  char err_buff[100];
  va_list args;
  va_start(args, err_msg);
  vsprintf(err_buff, err_msg, args);
  va_end(args);

  printf(strcat(line_buff, err_buff));
}