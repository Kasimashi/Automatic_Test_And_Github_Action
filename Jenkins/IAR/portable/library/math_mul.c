/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    math_mul.c
  \brief   Performs multiplication
  \version 20210511
*/

#include "library.h"

DATATYPE math_mul(DATATYPE a, DATATYPE b)
{
  DATATYPE ret = (a * b);
  return ret;
}
