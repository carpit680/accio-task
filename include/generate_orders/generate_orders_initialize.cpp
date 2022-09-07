//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: generate_orders_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 30-Aug-2022 15:10:14
//

// Include Files
#include "generate_orders_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "generate_orders_data.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void generate_orders_initialize()
{
  eml_rand_mt19937ar_stateful_init();
  isInitialized_generate_orders = true;
}

//
// File trailer for generate_orders_initialize.cpp
//
// [EOF]
//
