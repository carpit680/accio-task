//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: spawn_graph_robots_totes_new.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

#ifndef SPAWN_GRAPH_ROBOTS_TOTES_NEW_H
#define SPAWN_GRAPH_ROBOTS_TOTES_NEW_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void spawn_graph_robots_totes_new(
    double wh_x, double wh_y, double wh_z, double gz_x, double gz_y,
    double gz_z, double n_robots, double n_totes, double n_delivery_stations,
    double n_delivery_grid, coder::array<double, 2U> &robots,
    coder::array<double, 2U> &totes, coder::array<double, 2U> &robot_spots,
    coder::array<double, 2U> &delivery_stations,
    coder::array<double, 2U> &graph_info, double *columns, double *rows,
    double *levels);

#endif
//
// File trailer for spawn_graph_robots_totes_new.h
//
// [EOF]
//
