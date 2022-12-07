/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    componentA.c
  \brief   Component A
  \version 20211112
*/

#include "library.h"

#if !defined(NDEBUG)
# define IS_INT32(N)                 _Generic((N), int32_t: 1, default: 0)
# define ASSERT_DATATYPE(X, FAILMSG) _Static_assert(IS_INT32(X), FAILMSG)
#else
# define ASSERT_DATATYPE(X, FAILMSG)
#endif

int main()
{
  const DATATYPE x =  70510;
  const DATATYPE y = -24170;
  const DATATYPE z =  46340;
        DATATYPE sum;
        DATATYPE mul;

  debug_log("Component A!\r\n\n");

  sum = math_sum(x, y);
  debug_log("-- %d  +  %d = %d\r\n", x, y, sum);
  ASSERT_DATATYPE(sum, "FAIL: componentA - sum requires int32_t.");

  mul = math_mul(sum, z);
  debug_log("-- %d  *   %d = %d\r\n", sum, z, mul);
  ASSERT_DATATYPE(mul, "FAIL: componentA - mul requires int32_t.");

  debug_log("\nComponent A - finished execution.\r\n");

  return 0;
}

