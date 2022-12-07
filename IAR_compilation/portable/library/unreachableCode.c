/*
  Copyright (c) 2020-2021, IAR Systems AB.
  See LICENSE for detailed license information.
*/

#include "library.h"

enum figures_e {
  SPHERE,
  CIRCLE,
  CUBE,
  SQUARE,
  HEMISPHERE
};

void guessFigure(int round, int volumetric) {
  int figure;
  if (round && volumetric) {
    figure = SPHERE;
  }
  else if (round && !volumetric) {
    figure = CIRCLE;
  }
  else if (!round && volumetric) {
    figure = CUBE;
  }
  else {
    figure = SQUARE;
  }

  switch (figure) {
    case SQUARE:
      debug_log("This is a sphere");
      break;
    /* remove the case below to fix the violation */
    case HEMISPHERE:
      debug_log("This is a hemispere");
      break;
    case CIRCLE:
      debug_log("This is a circle");
      break;
    case CUBE:
      debug_log("This is a cube");
      break;
    default:
      debug_log("This is a square");
      break;
  }
}

void checkRange(char* cur) {
  if ((*cur < '0') || (*cur > '9')) {
    debug_log("Error: only digits are permitted");
    return;
  }
  /* obviously dead code */
  if ((*cur >= 'a') && (*cur <= 'f')) {
    /* process hex value */
  }
}

void checkSequence(char cur[]) {
  if (cur[0] == '-') {
    debug_log("Error: only positive values are permitted");
    return;
  }
  /* misplaced null check */
  if (cur == 0) {
    debug_log("Error: null argument provided");
    return;
  }
}
