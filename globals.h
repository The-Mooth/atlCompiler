

#ifdef MAIN
    #define EXTERN
    #define init(value) = value
#endif
#ifndef MAIN
    #define EXTERN extern 
    #define init(value)
#endif 


//src file
EXTERN char* src_name;

//io
extern FILE* yyin;
extern FILE* yyout;
EXTERN FILE* asm_output;

//switches
EXTERN int debug init(FALSE);
EXTERN int list_src init(FALSE);
EXTERN int errors_found init(FALSE);

//scanner variables
EXTERN int line_no init(1);

//symbol table variables
//max scope is for indexing. The -1 scope will be for language reserved symbols/types, like int and string.
EXTERN int cur_scope init(-1);
EXTERN int max_scope init(15);

EXTERN type_desc_ptr int_ptr;
EXTERN type_desc_ptr bool_ptr;
EXTERN type_desc_ptr string_ptr;
EXTERN type_desc_ptr err_ptr;

EXTERN id_info_ptr cur_procedure;
EXTERN char* cur_procedure_name;
EXTERN int proc_num init(0);