

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

  while (opt = getopt(argc, argv, "do:") != -1) 
  {
    switch(opt) 
    {
      case 'd':
        


      case 'v':
        
      
      case 'o':
        asm_output = optarg;
        break;

      default:
        fprintf (stderr, "usage: %s [-d] [-v] [-o file] file\n", argv[0]);
        exit(1);
    }

    src_name = argv[optind];



  }



  return 0;
}