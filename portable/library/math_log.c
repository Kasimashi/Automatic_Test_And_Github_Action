/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    math_log.c
  \brief   Performs logarithm
  \version 20211111
*/

#include "library.h"

static float p(float x, DATATYPE i)
{
  float res = 1.0f;
  for (; i > 0; i--) {
    res *= x;
  }
  return res;
}

float math_log(DATATYPE b, float n)
{
  float val = 0.0f;
  int i, accurate = 10, reps = 0;
  while (n != 1 && accurate >= 0) {
    for(i=0; n >= b; i++) {
      n /= b;
    }
    n = p(n, 10);
    val = 10 * (val + i);
    accurate--;
    reps++;
  }
  return (float)val / p(10, reps);
}
