//code for type descriptors

//declaring typedef for pointers allows me to call struct type_desc* 
//without the struct
typedef struct type_desc* type_desc_ptr;

typedef enum type_kind {
  tk_SCALAR, 
  tk_ARRAY, 
  tk_STRING
  } type_kind;
  

typedef struct type_desc {
  //fixed
  type_kind kind;
  int size;

  //for arrays only
  int low;
  int high;
  type_desc_ptr arr_type;
} type_desc;



//code for id information

typedef enum id_kind {
  ik_VAR, //level, offset
  ik_PROC, //id list, level, offset, param size, param list 
  ik_FUNC, //id list, level, offset, param size, param list
  ik_PARAM, //id list, level, offset, isval
  ik_LIST, //id list (next item)
  ik_TYPE, //nothing
  ik_CONST //value
  }id_kind;

typedef union id_union {

  //for functions and procedures
  //procedures are void functions
  struct {
    int param_size;
    //id_info_ptr param_list;
  } pf;

  union {
    int i_val;
    char* s_val;
  } val;

} id_union;

typedef struct id_info {
  //universals
  char* name;
  id_kind kind;
  //if function, the type is the return type
  type_desc_ptr type;
  //if function, id_list is 1st parameter
  //if parameter, id_list is next parameter
  id_info_ptr id_list;

  id_union u;

} id_info;

typedef struct id_info* id_info_ptr;
