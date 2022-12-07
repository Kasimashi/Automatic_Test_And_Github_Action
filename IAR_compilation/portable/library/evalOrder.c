/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/
#include "library.h"

void evalOrder(int i, int *b)
{
  // Do not depend on the order of evaluation for side effects
  int a = i + b[++i];
  debug_log("%d, %d", a, i);
}
