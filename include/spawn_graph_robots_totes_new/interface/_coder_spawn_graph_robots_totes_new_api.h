//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_spawn_graph_robots_totes_new_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

#ifndef _CODER_SPAWN_GRAPH_ROBOTS_TOTES_NEW_API_H
#define _CODER_SPAWN_GRAPH_ROBOTS_TOTES_NEW_API_H

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
void spawn_graph_robots_totes_new(
    real_T wh_x, real_T wh_y, real_T wh_z, real_T gz_x, real_T gz_y,
    real_T gz_z, real_T n_robots, real_T n_totes, real_T n_delivery_stations,
    real_T n_delivery_grid, coder::array<real_T, 2U> *robots,
    coder::array<real_T, 2U> *totes, coder::array<real_T, 2U> *robot_spots,
    coder::array<real_T, 2U> *delivery_stations,
    coder::array<real_T, 2U> *graph_info, real_T *columns, real_T *rows,
    real_T *levels);

void spawn_graph_robots_totes_new_api(const mxArray *const prhs[10],
                                      int32_T nlhs, const mxArray *plhs[8]);

void spawn_graph_robots_totes_new_atexit();

void spawn_graph_robots_totes_new_initialize();

void spawn_graph_robots_totes_new_terminate();

void spawn_graph_robots_totes_new_xil_shutdown();

void spawn_graph_robots_totes_new_xil_terminate();

#endif
//
// File trailer for _coder_spawn_graph_robots_totes_new_api.h
//
// [EOF]
//
