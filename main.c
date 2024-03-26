

#include "definitions.h"

#define MAIN
#include "globals.h"




int main(int argc, char** argv) {
    //process flags and input
    int opt;
    char* ASMout = NULL;

    while (opt = getopt(argc, argv)) {
        switch(opt) {
            case 'l':


            case 'd':


            case 'v':
              
            
            case 'o':
                

            default:
                printf("argument not accepted");//?




        }


    }



    return 0;
}