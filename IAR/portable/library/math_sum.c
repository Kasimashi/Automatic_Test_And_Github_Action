/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    math_sum.c
  \brief   Performs sum
  \version 20210511
*/

#include "library.h"

DATATYPE math_sum(DATATYPE a, DATATYPE b)
{
  DATATYPE ret = (a + b);
  return ret;
}
