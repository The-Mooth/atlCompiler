#include "definitions.h"
#include "globals.h"

//includes necessary?? idk yet

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

  if (!(size == (high - low))) {
    //error: size != actual size
  }

  return new_tdp;
}

//hopefully, this will be self documenting.
//to find the correct input for this function,
//go to the switch, and find the input order
//of the variable args for your id_kind
id_info_ptr make_id_info(char* name, id_kind id, type_desc_ptr desc, id_info_ptr next, ...){

  //init and populate universal parameters
  id_info_ptr new_ptr = malloc(sizeof(id_info));

  new_ptr->name = name;
  new_ptr->id = id;
  new_ptr->desc = desc;
  new_ptr->next = next;
  
  //using va_args, populate specific fields
  va_list args;
  va_start(args, next);
  switch(id){

    case ik_VAR:
      new_ptr->u.var.level = va_arg(args, int);
      new_ptr->u.var.offset = va_arg(args, int);
      break;

    case ik_PROC:
      new_ptr->u.pf.param_size = va_arg(args, int);
      break;

    case ik_FUNC:
      new_ptr->u.pf.param_size = va_arg(args, int);
      break;

    case ik_PARAM:
    new_ptr->u.param.is_val = va_arg(args, int);
      break;

    case ik_LIST:
      break;

    case ik_TYPE:
      //no fields to populate
      break;
    
    //this is incomplete: need to account for arrays. possibly treat string as char tk_array?
    case ik_CONST:
    //using switch for speed. less legible?
      switch(desc->kind) {
        case tk_SCALAR:
        new_ptr->u.val.i_val = va_arg(args, int);
          break;
        case tk_STRING:
        new_ptr->u.val.s_val = va_arg(args, char*);
          break;
        case tk_ARRAY:

          break;
      }
      break;

    default:
      break;
      //print error: invalid id kind!
  }
  va_end(args);

  //print the thing
  debug_printf("");

  return new_ptr;
}