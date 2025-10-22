#include "Functions.h" // Incluye las declaraciones del .h
#include <limits.h>

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = ui_a + ui_b;
  return usum;
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a * ui_b;
  return umul;
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  ui_b = ui_b % 32;
  uint32_t uShift = (ui_a << ui_b) | (ui_a >> (32 - ui_b));
  return uShift;
}
