#include "definitions.h"
#include "globals.h"


type_desc_ptr make_type_desc(type_kind tk_kind, int size, int low, int high, type_desc_ptr arr_type) {

  type_desc_ptr new_tdp = malloc(sizeof(type_desc));
  new_tdp->kind = tk_kind;
  new_tdp->size = size;
  new_tdp->low = low;
  new_tdp->high = high;
  new_tdp->arr_type = arr_type;

  return new_tdp;
}