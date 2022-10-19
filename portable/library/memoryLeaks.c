/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include "library.h"

void simpleLeakInCycle()
{
  int count = 0;
  int LOOPS = 100;
  int MAXSIZE = 100;
  char *pointer = NULL;

  for(count=0; count < LOOPS; count++) {
    pointer = (char *)malloc(sizeof(char) * MAXSIZE);
  }

  /* Repair: put the call to free() inside the cycle. */
//  free(pointer);
}
