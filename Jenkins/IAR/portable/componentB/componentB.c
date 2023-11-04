/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    componentB.c
  \brief   Component B
  \version 20211112
*/

#include "library.h"

#define FORMAT_MUL_STRING(X) _Generic((X), \
        uint32_t: "-- %d * %d = %u\r\n",   \
        default:  "-- %d * %d = %d\r\n"    )

int main()
{
  const DATATYPE x = 45000;
  const DATATYPE y = 20000;
  const DATATYPE z = 65000;
        DATATYPE sum;
        DATATYPE mul;

  debug_log("Component B!\r\n\n");

  sum = math_sum(x, y);
  debug_log("-- %d + %d = %d\r\n", x, y, sum);

  mul = math_mul(sum, z);
  debug_log(FORMAT_MUL_STRING(mul), sum, z, mul);

  debug_log("\nComponent B - finished execution.\r\n");

  return 0;
}

