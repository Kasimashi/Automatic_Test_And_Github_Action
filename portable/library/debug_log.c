/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    debug_log.c
  \brief   Print information for debugging
  \version 20211109
*/

#include "library.h"

void debug_log(const char * format, ...)
{
#if !defined(NDEBUG)
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
#endif
}
