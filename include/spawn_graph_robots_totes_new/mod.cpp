//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mod.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

// Include Files
#include "mod.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double x
// Return Type  : double
//
namespace coder {
double b_mod(double x)
{
  double r;
  if (std::isinf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = std::fmod(x, 3.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 3.0;
    }
  }
  return r;
}

//
// Arguments    : double x
//                double y
// Return Type  : double
//
double b_mod(double x, double y)
{
  double r;
  r = x;
  if (std::isnan(x) || std::isnan(y) || std::isinf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else if (std::isinf(y)) {
    if (x < 0.0) {
      r = y;
    }
  } else {
    r = std::fmod(x, y);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += y;
    }
  }
  return r;
}

//
// Arguments    : double x
//                double y
// Return Type  : double
//
double c_mod(double x, double y)
{
  double r;
  r = x;
  if (y == 0.0) {
    if (x == 0.0) {
      r = y;
    }
  } else if (std::isnan(x) || std::isnan(y) || std::isinf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0 / y;
  } else if (std::isinf(y)) {
    if ((y < 0.0) != (x < 0.0)) {
      r = y;
    }
  } else {
    r = std::fmod(x, y);
    if (r == 0.0) {
      r = y * 0.0;
    } else if ((x < 0.0) != (y < 0.0)) {
      r += y;
    }
  }
  return r;
}

} // namespace coder

//
// File trailer for mod.cpp
//
// [EOF]
//
