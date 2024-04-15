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

//union accounts for id_kind
typedef union id_union {

  //for functions, procedures, and params
  //procedures are just void functions
  struct {
    int param_size;
    //return address?? not sure yet
  } pf;

  struct {
    int is_val;
  }param;

  union {
    int i_val;
    char* s_val;
  } val;

  struct {
    int level;
    int offset;
  } var;

} id_union;

typedef struct id_info* id_info_ptr;

typedef struct id_info {
  //universals
  char* name;
  id_kind id;
  //if function, the type is the return type
  type_desc_ptr desc;
  //if function, id_list is 1st parameter
  //if parameter, id_list is next parameter
  //if var declaration, id_list is next var declared on line
  //ex: int foo, bar, fizz
  //if id kind ik_list, id_list is 1st var on list
  //if type or const(?), it's null
  //unless I decide to do multiple type declarations
  id_info_ptr id_list;

  id_union u;

} id_info;


