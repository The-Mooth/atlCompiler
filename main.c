

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
  printf("starting project\n");
  #ifdef TESTSCAN
    printf("starting testscan\n");
  #endif

  int opt;
  char* asm_filename = NULL;

  while ((opt = getopt(argc, argv, "do:")) != -1) 
  {
    switch(opt) 
    {
      case 'd':
        debug = TRUE;       
      
      case 'o':
        asm_filename = optarg;
        break;

      default:
        fprintf(stderr, "usage: %s [-d] [-o file] file\n", argv[0]);
    }
    src_name = argv[optind];

    //get contents of source file
    debug_printf("opening input file\n");

    //for debugging scanner
    #ifdef TESTSCAN
      printf("end of testscan\n");
      yyerror("hello world\n");
      exit(0);
    #endif

    if (!src_name){
      perror("no input file given");
      exit(1);
    }
    
    yyin = fopen(src_name, "r");
    if (yyin == NULL) {
      perror("could not open input file");
      exit(1);
    }


    if (!asm_filename) {
      asm_filename = "atl.out";
    } 

    debug_printf("executable name = %s\n", asm_filename);


    asm_output = fopen(asm_filename, "w");
    if (asm_output == NULL) {
      perror("could not open output file");
      exit(1);  
    }

    debug_printf("calling parser\n");
    yyparse();
    
    //close files
    fclose(yyin);
    fclose(yyout);

  debug_printf("end on main reached!\n");

  }


  return 0;
}


