#include "definitions.h"
#include "globals.h"

static int has_label = FALSE;

void gen(char* op, ...){
    va_list args;
    va_start(args, op);
    fprintf(asm_output, "\t");
    vfprintf(asm_output, op, args);
    fprintf (asm_output, "\n");
    va_end(args);

}

void label (char* label, ...) {

    if(has_label) {
        fprintf(asm_output, "\n");
    }

    va_list args;
    char chars[256];

    va_start(args, label);
    vsprintf(chars, label, args);
    fprintf(asm_output, "%s: ", chars);
    va_end(args);
    has_label = TRUE;
}

void label_def(int value, char* label, ...)
{

    if(has_label) {
        fprintf(asm_output, "\n");
    }

    va_list args;
    char chars[256];

    va_start(args, label); 
    vsprintf(chars, label, args);
    fprintf(asm_output, "%s=%d\n", chars, value);
    va_end(args);
    has_label = TRUE;

}
