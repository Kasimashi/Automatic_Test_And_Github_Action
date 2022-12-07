/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include "library.h"

int j=0;
void div0_test(void)
{
  int32_t i=5;

  j = i / j;
}
