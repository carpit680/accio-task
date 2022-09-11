//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: randperm.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

// Include Files
#include "accio_task/randperm.h"
#include "accio_task/mod.h"
#include "accio_task/rand.h"
#include "accio_task/rt_nonfinite.h"
#include "accio_task/coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double n
//                double k
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
namespace coder {
void randperm(double n, double k, ::coder::array<double, 2U> &p)
{
  array<double, 1U> hashTbl;
  array<double, 1U> link;
  array<double, 1U> loc;
  array<double, 1U> val;
  int i;
  int loop_ub_tmp;
  loop_ub_tmp = static_cast<int>(k);
  p.set_size(1, loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    p[i] = 0.0;
  }
  if (!(k == 0.0)) {
    if (k >= n) {
      p[0] = 1.0;
      i = static_cast<int>(n - 1.0);
      for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
        double j;
        j = b_rand() * ((static_cast<double>(loop_ub_tmp) + 1.0) + 1.0);
        j = std::floor(j);
        p[loop_ub_tmp + 1] = p[static_cast<int>(j + 1.0) - 1];
        p[static_cast<int>(j + 1.0) - 1] =
            (static_cast<double>(loop_ub_tmp) + 1.0) + 1.0;
      }
    } else if (k >= n / 4.0) {
      double t;
      t = 0.0;
      i = static_cast<int>((k - 1.0) + 1.0);
      for (int m{0}; m < i; m++) {
        double b_i;
        double newEntry;
        double nleftm1;
        double selectedLoc;
        selectedLoc = k - static_cast<double>(m);
        b_i = n - t;
        newEntry = selectedLoc / b_i;
        nleftm1 = b_rand();
        while (nleftm1 > newEntry) {
          t++;
          b_i--;
          newEntry += (1.0 - newEntry) * (selectedLoc / b_i);
        }
        double j;
        t++;
        j = b_rand() * (static_cast<double>(m) + 1.0);
        j = std::floor(j);
        p[m] = p[static_cast<int>(j + 1.0) - 1];
        p[static_cast<int>(j + 1.0) - 1] = t;
      }
    } else {
      double newEntry;
      hashTbl.set_size(loop_ub_tmp);
      link.set_size(loop_ub_tmp);
      val.set_size(loop_ub_tmp);
      loc.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        hashTbl[i] = 0.0;
        link[i] = 0.0;
        val[i] = 0.0;
        loc[i] = 0.0;
      }
      newEntry = 1.0;
      for (int m{0}; m < loop_ub_tmp; m++) {
        double b_i;
        double j;
        double nleftm1;
        double selectedLoc;
        nleftm1 = n - (static_cast<double>(m) + 1.0);
        selectedLoc = b_rand() * (nleftm1 + 1.0);
        selectedLoc = std::floor(selectedLoc);
        b_i = b_mod(selectedLoc, k) + 1.0;
        j = hashTbl[static_cast<int>(b_i) - 1];
        while ((j > 0.0) && (loc[static_cast<int>(j) - 1] != selectedLoc)) {
          j = link[static_cast<int>(j) - 1];
        }
        if (j > 0.0) {
          p[m] = val[static_cast<int>(j) - 1] + 1.0;
        } else {
          p[m] = selectedLoc + 1.0;
          j = newEntry;
          newEntry++;
          loc[static_cast<int>(j) - 1] = selectedLoc;
          link[static_cast<int>(j) - 1] = hashTbl[static_cast<int>(b_i) - 1];
          hashTbl[static_cast<int>(b_i) - 1] = j;
        }
        if (static_cast<double>(m) + 1.0 < k) {
          selectedLoc = hashTbl[static_cast<int>(b_mod(nleftm1, k) + 1.0) - 1];
          while ((selectedLoc > 0.0) &&
                 (loc[static_cast<int>(selectedLoc) - 1] != nleftm1)) {
            selectedLoc = link[static_cast<int>(selectedLoc) - 1];
          }
          if (selectedLoc > 0.0) {
            val[static_cast<int>(j) - 1] =
                val[static_cast<int>(selectedLoc) - 1];
          } else {
            val[static_cast<int>(j) - 1] = nleftm1;
          }
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for randperm.cpp
//
// [EOF]
//
