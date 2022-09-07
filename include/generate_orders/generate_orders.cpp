//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: generate_orders.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 30-Aug-2022 15:10:14
//

// Include Files
#include "generate_orders.h"
#include "generate_orders_data.h"
#include "generate_orders_initialize.h"
#include "rand.h"
#include "randn.h"
#include "sort.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const coder::array<double, 2U> &tote_freq_dist
//                double order[50]
// Return Type  : void
//
void generate_orders(const coder::array<double, 2U> &tote_freq_dist,
                     double order[50])
{
  coder::array<double, 2U> b_chances;
  coder::array<double, 2U> cdf;
  coder::array<double, 2U> chances;
  coder::array<int, 2U> iidx;
  coder::array<int, 2U> r;
  double d;
  double key;
  int b_i;
  int i;
  int loop_ub;
  if (!isInitialized_generate_orders) {
    generate_orders_initialize();
  }
  key = 6.0 * coder::randn() + 0.1;
  std::memset(&order[0], 0, 50U * sizeof(double));
  chances.set_size(1, tote_freq_dist.size(1));
  d = coder::sum(tote_freq_dist);
  loop_ub = tote_freq_dist.size(1);
  for (i = 0; i < loop_ub; i++) {
    chances[i] = tote_freq_dist[i] / d;
  }
  coder::internal::sort(chances, iidx);
  loop_ub = chances.size(1);
  cdf.set_size(1, chances.size(1));
  for (i = 0; i < loop_ub; i++) {
    cdf[i] = 0.0;
  }
  i = chances.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    b_chances.set_size(1, b_i + 1);
    for (loop_ub = 0; loop_ub <= b_i; loop_ub++) {
      b_chances[loop_ub] = chances[loop_ub];
    }
    cdf[b_i] = coder::sum(b_chances);
  }
  i = static_cast<int>(std::ceil(std::abs(key)));
  for (b_i = 0; b_i < i; b_i++) {
    int c_i;
    int end;
    key = coder::b_rand();
    end = cdf.size(1) - 1;
    loop_ub = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (cdf[c_i] > key) {
        loop_ub++;
      }
    }
    r.set_size(1, loop_ub);
    loop_ub = 0;
    for (c_i = 0; c_i <= end; c_i++) {
      if (cdf[c_i] > key) {
        r[loop_ub] = c_i + 1;
        loop_ub++;
      }
    }
    order[b_i] = iidx[r[0] - 1];
  }
}

//
// File trailer for generate_orders.cpp
//
// [EOF]
//
