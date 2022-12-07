/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

/*!
  \file    library.h
  \brief   Library header
  \version 20211111
*/

#pragma once

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#if !defined(NDEBUG)
# include <stdio.h>
#endif
#if defined(__IAR_SYSTEMS_ICC__)
# include <intrinsics.h>
#endif

#define DATATYPE int32_t

/* Functions */
DATATYPE math_sum (DATATYPE a, DATATYPE b);
DATATYPE math_mul (DATATYPE a, DATATYPE b);
float    math_log (DATATYPE b, float n);
void     debug_log(const char * format, ...);
uint32_t fastCRC32(uint32_t crc, uint32_t const* data, uint32_t words);
