/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include "library.h"

enum {
  BUFFER_SIZE = 16
};

void doInit(const uint8_t *msg)
{
  // error_log has not been initialized,
  // (an indeterminate value is read)
  const uint32_t *error_num;
  uint32_t buffer[BUFFER_SIZE];

  memcpy(buffer, error_num, sizeof(buffer));
  debug_log("Error: %s\n", error_num);
}
