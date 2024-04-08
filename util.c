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

  

}