

//#include "definitions.h"
#include "definitions.h"
#define MAIN
#include "globals.h"



int main(int argc, char** argv) 
{
  //process flags and input
  extern char getarg (int argc, char **argv, char *optchars);
  extern int optind;
  extern char* optarg;

  int opt;
  char* asm_output = NULL;

  while ((opt = getopt(argc, argv, "do:")) != -1) 
  {
    switch(opt) 
    {
      case 'd':
        debug = TRUE;       
      
      case 'o':
        asm_output = optarg;
        break;

      default:
        fprintf (stderr, "usage: %s [-d] [-o file] file\n", argv[0]);
        exit(1);
    }
    char* src_name = argv[optind];

    //get contents of source file
    debug_printf("opening input file");

    //for debugging scanner
    #ifdef TESTSCAN
      yyerror("hello world");
      exit(0);
    #endif

    yyin = fopen(src_name, "r");
    if (yyin == NULL) {
      perror("could not open input file");
      exit(1);
    }


    if (!asm_output) {
      asm_output = "atl.out";
    } 

    debug_printf("executable name = %s", asm_output);

    yyout = fopen(asm_output, "w");
    if (yyout == NULL) {
      perror("could not open output file");
      exit(1);
    }

    debug_printf("calling parser");
    yyparse();
    
    //close files
    fclose(yyin);
    fclose(yyout);



  }


  return 0;
}


