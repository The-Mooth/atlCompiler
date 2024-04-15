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


void gen_error(char* err_msg) {
  errors_found = TRUE;

  char line_buff[100];
  sprintf(line_buff, "on line: %d in file %s: ", line_no, src_name);
  strcat(line_buff, err_msg);
  printf("%s", line_buff);
}