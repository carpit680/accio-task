//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_rand_mt19937ar.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 30-Aug-2022 15:10:14
//

// Include Files
#include "eml_rand_mt19937ar.h"

// Function Definitions
//
// Arguments    : unsigned int mt[625]
//                unsigned int u[2]
// Return Type  : void
//
namespace coder {
void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2])
{
  for (int j{0}; j < 2; j++) {
    unsigned int mti;
    unsigned int y;
    mti = mt[624] + 1U;
    if (mti >= 625U) {
      int kk;
      for (kk = 0; kk < 227; kk++) {
        y = (mt[kk] & 2147483648U) | (mt[kk + 1] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }
        mt[kk] = mt[kk + 397] ^ y;
      }
      for (kk = 0; kk < 396; kk++) {
        y = (mt[kk + 227] & 2147483648U) | (mt[kk + 228] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }
        mt[kk + 227] = mt[kk] ^ y;
      }
      y = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((y & 1U) == 0U) {
        y >>= 1U;
      } else {
        y = y >> 1U ^ 2567483615U;
      }
      mt[623] = mt[396] ^ y;
      mti = 1U;
    }
    y = mt[static_cast<int>(mti) - 1];
    mt[624] = mti;
    y ^= y >> 11U;
    y ^= y << 7U & 2636928640U;
    y ^= y << 15U & 4022730752U;
    u[j] = y ^ y >> 18U;
  }
}

} // namespace coder

//
// File trailer for eml_rand_mt19937ar.cpp
//
// [EOF]
//
