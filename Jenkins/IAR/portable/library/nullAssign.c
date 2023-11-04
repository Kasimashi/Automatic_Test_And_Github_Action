/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include "library.h"

int null_ptr_derreference(void)
{
  int *p;
  p = NULL;   // assignment to NULL
  // << a lot of code in between >>
  return *p;  // dereference after
}
