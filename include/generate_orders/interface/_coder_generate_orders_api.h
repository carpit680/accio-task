//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_generate_orders_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 30-Aug-2022 15:10:14
//

#ifndef _CODER_GENERATE_ORDERS_API_H
#define _CODER_GENERATE_ORDERS_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void generate_orders(coder::array<real_T, 2U> *tote_freq_dist,
                     real_T order[50]);

void generate_orders_api(const mxArray *prhs, const mxArray **plhs);

void generate_orders_atexit();

void generate_orders_initialize();

void generate_orders_terminate();

void generate_orders_xil_shutdown();

void generate_orders_xil_terminate();

#endif
//
// File trailer for _coder_generate_orders_api.h
//
// [EOF]
//
