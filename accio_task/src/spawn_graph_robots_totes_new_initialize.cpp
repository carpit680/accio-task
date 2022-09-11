//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: spawn_graph_robots_totes_new_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

// Include Files
#include "accio_task/spawn_graph_robots_totes_new_initialize.h"
#include "accio_task/eml_rand_mt19937ar_stateful.h"
#include "accio_task/rt_nonfinite.h"
#include "accio_task/spawn_graph_robots_totes_new_data.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void spawn_graph_robots_totes_new_initialize()
{
  eml_rand_mt19937ar_stateful_init();
  isInitialized_spawn_graph_robots_totes_new = true;
}

//
// File trailer for spawn_graph_robots_totes_new_initialize.cpp
//
// [EOF]
//
