#include "definitions.h"
#include "globals.h"


type_desc_ptr make_type_desc(type_kind tk_kind, int size, int low, int high, type_desc_ptr arr_type) {

  type_desc_ptr new_tdp = malloc(sizeof(type_desc));
  new_tdp->kind = tk_kind;
  new_tdp->size = size;
  new_tdp->low = low;
  new_tdp->high = high;
  new_tdp->arr_type = arr_type;

  if (low >= high) {
    //error: low must be greater than high 
  }

  if (!size == (high - low)) {
    //error: size != actual size
  }

  return new_tdp;
}

//hopefully, this will be self documenting
//to find the correct input for this function,
//go to the switch, and find the input order
//of the variable args for your id_kind
id_info_ptr make_id_info(char* name, id_kind id, type_desc_ptr desc, ...){

  //init and populate universal parameters
  id_info_ptr new_ptr = malloc(sizeof(id_info));

  new_ptr->name = name;
  new_ptr->id = id;
  new_ptr->desc = desc;
  
  //using va_args, populate specific fields
  va_list args;
  va_start(args, desc);
  switch(id){

    case ik_VAR:
      new_ptr->u.var.level = va_arg(args, int);
      new_ptr->u.var.offset = va_arg(args, int);
      break;

    case ik_PROC:
      break;

    case ik_FUNC:
      break;

    case ik_PARAM:
      break;

    case ik_LIST:
      break;

    case ik_TYPE:
      break;
    
    case ik_CONST:
    //using switch for speed. less legible?
      switch(desc->kind) {
        case tk_SCALAR:
          break;
        case tk_STRING:
          break;
        case tk_ARRAY:
          break;
      }
      break;

    default:
      //print error: invalid id kind!
  }
  va_end(args);
}