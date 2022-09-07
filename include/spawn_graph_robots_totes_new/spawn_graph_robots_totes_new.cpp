//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: spawn_graph_robots_totes_new.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

// Include Files
#include "spawn_graph_robots_totes_new.h"
#include "colon.h"
#include "find.h"
#include "mod.h"
#include "randperm.h"
#include "rt_nonfinite.h"
#include "spawn_graph_robots_totes_new_data.h"
#include "spawn_graph_robots_totes_new_initialize.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double wh_x
//                double wh_y
//                double wh_z
//                double gz_x
//                double gz_y
//                double gz_z
//                double n_robots
//                double n_totes
//                double n_delivery_stations
//                double n_delivery_grid
//                coder::array<double, 2U> &robots
//                coder::array<double, 2U> &totes
//                coder::array<double, 2U> &robot_spots
//                coder::array<double, 2U> &delivery_stations
//                coder::array<double, 2U> &graph_info
//                double *columns
//                double *rows
//                double *levels
// Return Type  : void
//
void spawn_graph_robots_totes_new(
    double wh_x, double wh_y, double wh_z, double gz_x, double gz_y,
    double gz_z, double n_robots, double n_totes, double n_delivery_stations,
    double n_delivery_grid, coder::array<double, 2U> &robots,
    coder::array<double, 2U> &totes, coder::array<double, 2U> &robot_spots,
    coder::array<double, 2U> &delivery_stations,
    coder::array<double, 2U> &graph_info, double *columns, double *rows,
    double *levels)
{
  coder::array<double, 2U> A;
  coder::array<double, 2U> base_nodes;
  coder::array<double, 2U> botloc;
  coder::array<double, 2U> ic;
  coder::array<double, 2U> jc;
  coder::array<double, 2U> xd;
  coder::array<double, 2U> y;
  coder::array<double, 2U> yd;
  coder::array<double, 2U> zd;
  coder::array<int, 2U> r;
  coder::array<boolean_T, 2U> b_A;
  double b_rows;
  double count;
  double d;
  double dest_node_num;
  double level;
  double mid_line;
  double node_num;
  double rack_rows;
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int loop_ub;
  int loop_ub_tmp;
  unsigned int pos_count;
  if (!isInitialized_spawn_graph_robots_totes_new) {
    spawn_graph_robots_totes_new_initialize();
  }
  i = static_cast<int>(n_robots);
  robots.set_size(i, 11);
  loop_ub = static_cast<int>(n_robots) * 11;
  for (i1 = 0; i1 < loop_ub; i1++) {
    robots[i1] = 0.0;
  }
  totes.set_size(static_cast<int>(n_totes), 11);
  loop_ub = static_cast<int>(n_totes) * 11;
  for (i1 = 0; i1 < loop_ub; i1++) {
    totes[i1] = 0.0;
  }
  loop_ub_tmp = static_cast<int>(n_delivery_stations);
  delivery_stations.set_size(1, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    delivery_stations[i1] = 0.0;
  }
  *columns = std::round(wh_x / gz_x);
  *rows = std::round(wh_y / gz_y);
  *levels = std::floor((wh_z - gz_z) / gz_z);
  rack_rows = ((*rows - n_delivery_grid) - 1.0) / 1.5;
  mid_line = std::ceil(*columns / 2.0);
  b_rows = *columns * *rows;
  d = rack_rows * 0.5 * (*columns - 3.0);
  node_num = b_rows + d * *levels;
  A.set_size(static_cast<int>(node_num), static_cast<int>(node_num));
  loop_ub = static_cast<int>(node_num) * static_cast<int>(node_num);
  for (i1 = 0; i1 < loop_ub; i1++) {
    A[i1] = 0.0;
  }
  loop_ub_tmp = static_cast<int>(rack_rows * 0.5 * ((*columns - 3.0) - 2.0));
  robot_spots.set_size(1, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    robot_spots[i1] = 0.0;
  }
  pos_count = 1U;
  i1 = static_cast<int>(*rows);
  for (loop_ub_tmp = 0; loop_ub_tmp < i1; loop_ub_tmp++) {
    i2 = static_cast<int>(*columns);
    for (loop_ub = 0; loop_ub < i2; loop_ub++) {
      node_num = ((static_cast<double>(loop_ub_tmp) + 1.0) - 1.0) * *columns +
                 (static_cast<double>(loop_ub) + 1.0);
      if (loop_ub_tmp + 1U == 1U) {
        if (static_cast<double>(loop_ub) + 1.0 < mid_line) {
          A[(static_cast<int>(node_num) +
             A.size(0) *
                 static_cast<int>(static_cast<unsigned int>(node_num))) -
            1] = 1.0;
        }
        if (static_cast<double>(loop_ub) + 1.0 > mid_line) {
          A[(static_cast<int>(node_num) +
             A.size(0) * (static_cast<int>(node_num) - 2)) -
            1] = 1.0;
        }
      } else if (static_cast<double>(loop_ub_tmp) + 1.0 == *rows) {
        if ((loop_ub + 1U > 1U) &&
            (static_cast<double>(loop_ub) + 1.0 <= mid_line)) {
          A[(static_cast<int>(node_num) +
             A.size(0) * (static_cast<int>(node_num) - 2)) -
            1] = 1.0;
        }
        if ((static_cast<double>(loop_ub) + 1.0 >= mid_line) &&
            (static_cast<double>(loop_ub) + 1.0 < *columns)) {
          A[(static_cast<int>(node_num) +
             A.size(0) *
                 static_cast<int>(static_cast<unsigned int>(node_num))) -
            1] = 1.0;
        }
      } else if ((loop_ub_tmp + 1U == 2U) || (loop_ub_tmp + 1U == 3U)) {
        if ((loop_ub + 1U > 3U) &&
            (static_cast<double>(loop_ub) + 1.0 <= mid_line)) {
          A[(static_cast<int>(node_num) +
             A.size(0) * (static_cast<int>(node_num) - 2)) -
            1] = 1.0;
        }
        if ((static_cast<double>(loop_ub) + 1.0 < *columns - 2.0) &&
            (static_cast<double>(loop_ub) + 1.0 >= mid_line)) {
          A[(static_cast<int>(node_num) +
             A.size(0) *
                 static_cast<int>(static_cast<unsigned int>(node_num))) -
            1] = 1.0;
        }
        if ((loop_ub + 1U == 3U) ||
            (static_cast<double>(loop_ub) + 1.0 == *columns - 2.0)) {
          A[(static_cast<int>(node_num) +
             A.size(0) * (static_cast<int>(
                              ((static_cast<double>(loop_ub_tmp) + 1.0) - 2.0) *
                                  *columns +
                              (static_cast<double>(loop_ub) + 1.0)) -
                          1)) -
            1] = 1.0;
        }
      } else if (loop_ub_tmp + 1U == 4U) {
        if ((loop_ub + 1U > 4U) &&
            (static_cast<double>(loop_ub) + 1.0 < mid_line)) {
          A[(static_cast<int>(node_num) +
             A.size(0) *
                 static_cast<int>(static_cast<unsigned int>(node_num))) -
            1] = 1.0;
        }
        if ((static_cast<double>(loop_ub) + 1.0 < *columns - 3.0) &&
            (static_cast<double>(loop_ub) + 1.0 > mid_line)) {
          A[(static_cast<int>(node_num) +
             A.size(0) * (static_cast<int>(node_num) - 2)) -
            1] = 1.0;
        }
      } else if (static_cast<double>(loop_ub_tmp) + 1.0 > n_delivery_grid) {
        rack_rows = coder::b_mod(
            ((static_cast<double>(loop_ub_tmp) + 1.0) - n_delivery_grid) + 1.0);
        if (rack_rows == 0.0) {
          if ((loop_ub + 1U > 1U) &&
              (static_cast<double>(loop_ub) + 1.0 <= mid_line)) {
            A[(static_cast<int>(node_num) +
               A.size(0) * (static_cast<int>(node_num) - 2)) -
              1] = 1.0;
          }
          if ((static_cast<double>(loop_ub) + 1.0 >= mid_line) &&
              (static_cast<double>(loop_ub) + 1.0 < *columns)) {
            A[(static_cast<int>(node_num) +
               A.size(0) *
                   static_cast<int>(static_cast<unsigned int>(node_num))) -
              1] = 1.0;
          }
        } else if (rack_rows == 2.0) {
          //                      if (col == 2)
          //                          dest_node_num = (row+2)*columns + col;
          //                          A( node_num, dest_node_num) = 2;
          //                      end
          if ((loop_ub + 1U > 1U) &&
              (static_cast<double>(loop_ub) + 1.0 < *columns) &&
              (static_cast<double>(loop_ub) + 1.0 != mid_line)) {
            A[(static_cast<int>(node_num) +
               A.size(0) *
                   (static_cast<int>((static_cast<double>(loop_ub_tmp) + 1.0) *
                                         *columns +
                                     (static_cast<double>(loop_ub) + 1.0)) -
                    1)) -
              1] = 2.0;
            //                           A(dest_node_num, node_num) = 2;
          }
          if (static_cast<double>(loop_ub) + 1.0 < *columns - 1.0) {
            if ((static_cast<double>(loop_ub) + 1.0 < mid_line) &&
                (loop_ub + 1U > 2U)) {
              robot_spots[static_cast<int>(pos_count) - 1] = node_num;
              pos_count++;
            }
            //                          if (col ~= mid_line) && (col ~=
            //                          mid_line-1) if (col ~= 1)
            A[(static_cast<int>(node_num) +
               A.size(0) *
                   static_cast<int>(static_cast<unsigned int>(node_num))) -
              1] = 3.0;
            //                          end
          }
        } else if (rack_rows == 1.0) {
          if (loop_ub + 1U == 2U) {
            dest_node_num =
                ((static_cast<double>(loop_ub_tmp) + 1.0) - 2.0) * *columns +
                2.0;
            A[(static_cast<int>(node_num) +
               A.size(0) * (static_cast<int>(dest_node_num) - 1)) -
              1] = 6.0;
            A[(static_cast<int>(dest_node_num) +
               A.size(0) * (static_cast<int>(node_num) - 1)) -
              1] = 2.0;
            if (static_cast<double>(loop_ub_tmp) + 1.0 != *rows - 1.0) {
              A[(static_cast<int>(node_num) +
                 A.size(0) *
                     (static_cast<int>(
                          (static_cast<double>(loop_ub_tmp) + 1.0) * *columns +
                          2.0) -
                      1)) -
                1] = 2.0;
            }
          }
          if (static_cast<double>(loop_ub) + 1.0 == *columns - 1.0) {
            dest_node_num =
                ((static_cast<double>(loop_ub_tmp) + 1.0) - 2.0) * *columns +
                (static_cast<double>(loop_ub) + 1.0);
            A[(static_cast<int>(node_num) +
               A.size(0) * (static_cast<int>(dest_node_num) - 1)) -
              1] = 6.0;
            A[(static_cast<int>(dest_node_num) +
               A.size(0) * (static_cast<int>(node_num) - 1)) -
              1] = 2.0;
            if (static_cast<double>(loop_ub_tmp) + 1.0 != *rows - 1.0) {
              A[(static_cast<int>((static_cast<double>(loop_ub_tmp) + 1.0) *
                                      *columns +
                                  (static_cast<double>(loop_ub) + 1.0)) +
                 A.size(0) * (static_cast<int>(node_num) - 1)) -
                1] = 2.0;
            }
          }
          if ((loop_ub + 1U > 2U) &&
              (static_cast<double>(loop_ub) + 1.0 < mid_line)) {
            A[(static_cast<int>(node_num) +
               A.size(0) *
                   (static_cast<int>(
                        ((static_cast<double>(loop_ub_tmp) + 1.0) - 2.0) *
                            *columns +
                        (static_cast<double>(loop_ub) + 1.0)) -
                    1)) -
              1] = 2.0;
            //                          A(dest_node_num, node_num) = 2;
            if (static_cast<double>(loop_ub_tmp) + 1.0 != *rows - 1.0) {
              A[(static_cast<int>((static_cast<double>(loop_ub_tmp) + 1.0) *
                                      *columns +
                                  (static_cast<double>(loop_ub) + 1.0)) +
                 A.size(0) * (static_cast<int>(node_num) - 1)) -
                1] = 2.0;
            }
          }
          if ((static_cast<double>(loop_ub) + 1.0 > mid_line) &&
              (static_cast<double>(loop_ub) + 1.0 < *columns - 1.0)) {
            A[(static_cast<int>(node_num) +
               A.size(0) *
                   (static_cast<int>(
                        ((static_cast<double>(loop_ub_tmp) + 1.0) - 2.0) *
                            *columns +
                        (static_cast<double>(loop_ub) + 1.0)) -
                    1)) -
              1] = 2.0;
            //                           A(dest_node_num, node_num) = 2;
            if (static_cast<double>(loop_ub_tmp) + 1.0 != *rows - 1.0) {
              A[(static_cast<int>(node_num) +
                 A.size(0) *
                     (static_cast<int>(
                          (static_cast<double>(loop_ub_tmp) + 1.0) * *columns +
                          (static_cast<double>(loop_ub) + 1.0)) -
                      1)) -
                1] = 2.0;
            }
          }
          if ((loop_ub + 1U > 2U) &&
              (static_cast<double>(loop_ub) + 1.0 <= *columns)) {
            if ((static_cast<double>(loop_ub) + 1.0 > mid_line) &&
                (static_cast<double>(loop_ub) + 1.0 < *columns - 1.0)) {
              robot_spots[static_cast<int>(pos_count) - 1] = node_num;
              pos_count++;
            }
            //                          if (col ~= mid_line) && (col ~=
            //                          mid_line+1) if (col ~= columns)
            A[(static_cast<int>(node_num) +
               A.size(0) * (static_cast<int>(node_num) - 2)) -
              1] = 3.0;
            //                          end
          }
        }
      }
      if ((loop_ub + 1U == 1U) ||
          (static_cast<double>(loop_ub) + 1.0 == *columns)) {
        if (loop_ub_tmp + 1U != 1U) {
          A[(static_cast<int>(node_num) +
             A.size(0) * (static_cast<int>(
                              ((static_cast<double>(loop_ub_tmp) + 1.0) - 2.0) *
                                  *columns +
                              (static_cast<double>(loop_ub) + 1.0)) -
                          1)) -
            1] = 1.0;
        }
      } else if ((static_cast<double>(loop_ub) + 1.0 == mid_line) &&
                 (static_cast<double>(loop_ub_tmp) + 1.0 != *rows)) {
        A[(static_cast<int>(node_num) +
           A.size(0) *
               (static_cast<int>((static_cast<double>(loop_ub_tmp) + 1.0) *
                                     *columns +
                                 (static_cast<double>(loop_ub) + 1.0)) -
                1)) -
          1] = 1.0;
      }
      if (((loop_ub + 1U == 5U) ||
           (static_cast<double>(loop_ub) + 1.0 == *columns - 4.0)) &&
          (loop_ub_tmp + 1U > 1U) && (loop_ub_tmp + 1U < 4U)) {
        A[(static_cast<int>(node_num) +
           A.size(0) *
               (static_cast<int>((static_cast<double>(loop_ub_tmp) + 1.0) *
                                     *columns +
                                 (static_cast<double>(loop_ub) + 1.0)) -
                1)) -
          1] = 1.0;
      }
    }
  }
  xd.set_size(1, 0);
  yd.set_size(1, 0);
  loop_ub_tmp = static_cast<int>(b_rows);
  zd.set_size(1, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    zd[i1] = 0.0;
  }
  i1 = static_cast<int>((b_rows + (*columns - 1.0)) / *columns);
  if (0 <= i1 - 1) {
    if (std::isnan(*columns - 1.0)) {
      botloc.set_size(1, 1);
      botloc[0] = rtNaN;
    } else if (*columns - 1.0 < 0.0) {
      botloc.set_size(1, 0);
    } else if (std::isinf(*columns - 1.0) && (0.0 == *columns - 1.0)) {
      botloc.set_size(1, 1);
      botloc[0] = rtNaN;
    } else {
      botloc.set_size(1, static_cast<int>(*columns - 1.0) + 1);
      loop_ub = static_cast<int>(*columns - 1.0);
      for (i2 = 0; i2 <= loop_ub; i2++) {
        botloc[i2] = i2;
      }
    }
    i3 = botloc.size(1);
    b_loop_ub = botloc.size(1);
  }
  for (b_i = 0; b_i < i1; b_i++) {
    i2 = xd.size(1);
    xd.set_size(xd.size(0), xd.size(1) + i3);
    for (i5 = 0; i5 < b_loop_ub; i5++) {
      xd[i2 + i5] = gz_x * botloc[i5];
    }
  }
  count = 0.0;
  if (0 <= i1 - 1) {
    i4 = static_cast<int>(*columns);
    c_loop_ub = static_cast<int>(*columns);
  }
  for (b_i = 0; b_i < i1; b_i++) {
    i2 = yd.size(1);
    yd.set_size(yd.size(0), yd.size(1) + i4);
    for (i3 = 0; i3 < c_loop_ub; i3++) {
      yd[i2 + i3] = count;
    }
    count += gz_y;
  }
  dest_node_num = static_cast<double>(static_cast<int>(b_rows)) + 1.0;
  loop_ub_tmp = static_cast<int>(d);
  base_nodes.set_size(1, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    base_nodes[i1] = 0.0;
  }
  pos_count = 1U;
  if (std::isnan(n_delivery_grid + 2.0) || std::isnan(*rows)) {
    ic.set_size(1, 1);
    ic[0] = rtNaN;
  } else if (*rows < n_delivery_grid + 2.0) {
    ic.set_size(1, 0);
  } else if ((std::isinf(n_delivery_grid + 2.0) || std::isinf(*rows)) &&
             (n_delivery_grid + 2.0 == *rows)) {
    ic.set_size(1, 1);
    ic[0] = rtNaN;
  } else if (std::floor(n_delivery_grid + 2.0) == n_delivery_grid + 2.0) {
    loop_ub =
        static_cast<int>(std::floor((*rows - (n_delivery_grid + 2.0)) / 3.0));
    ic.set_size(1, loop_ub + 1);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      ic[i1] = (n_delivery_grid + 2.0) + 3.0 * static_cast<double>(i1);
    }
  } else {
    coder::eml_float_colon(n_delivery_grid + 2.0, *rows, ic);
  }
  if (std::isnan(mid_line - 1.0)) {
    botloc.set_size(1, 1);
    botloc[0] = rtNaN;
  } else if (mid_line - 1.0 < 2.0) {
    botloc.set_size(1, 0);
  } else if (std::isinf(mid_line - 1.0) && (2.0 == mid_line - 1.0)) {
    botloc.set_size(1, 1);
    botloc[0] = rtNaN;
  } else {
    botloc.set_size(1, static_cast<int>((mid_line - 1.0) - 2.0) + 1);
    loop_ub = static_cast<int>((mid_line - 1.0) - 2.0);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      botloc[i1] = static_cast<double>(i1) + 2.0;
    }
  }
  if (std::isnan(mid_line + 1.0) || std::isnan(*columns - 1.0)) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else if (*columns - 1.0 < mid_line + 1.0) {
    y.set_size(1, 0);
  } else if ((std::isinf(mid_line + 1.0) || std::isinf(*columns - 1.0)) &&
             (mid_line + 1.0 == *columns - 1.0)) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else if (mid_line + 1.0 == mid_line + 1.0) {
    loop_ub = static_cast<int>((*columns - 1.0) - (mid_line + 1.0));
    y.set_size(1, loop_ub + 1);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      y[i1] = (mid_line + 1.0) + static_cast<double>(i1);
    }
  } else {
    coder::b_eml_float_colon(mid_line + 1.0, *columns - 1.0, y);
  }
  jc.set_size(1, botloc.size(1) + y.size(1));
  loop_ub = botloc.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    jc[i1] = botloc[i1];
  }
  loop_ub = y.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    jc[i1 + botloc.size(1)] = y[i1];
  }
  i1 = ic.size(1);
  for (b_i = 0; b_i < i1; b_i++) {
    i2 = jc.size(1);
    if (0 <= jc.size(1) - 1) {
      i6 = static_cast<int>(*levels);
      level = (ic[b_i] - 1.0) * gz_y;
      if (std::isnan(*levels)) {
        botloc.set_size(1, 1);
        botloc[0] = rtNaN;
      } else if (*levels < 1.0) {
        botloc.set_size(1, 0);
      } else if (std::isinf(*levels) && (1.0 == *levels)) {
        botloc.set_size(1, 1);
        botloc[0] = rtNaN;
      } else {
        botloc.set_size(1, static_cast<int>(*levels - 1.0) + 1);
        loop_ub = static_cast<int>(*levels - 1.0);
        for (i3 = 0; i3 <= loop_ub; i3++) {
          botloc[i3] = static_cast<double>(i3) + 1.0;
        }
      }
      i7 = botloc.size(1);
      d_loop_ub = botloc.size(1);
    }
    for (loop_ub = 0; loop_ub < i2; loop_ub++) {
      node_num = (ic[b_i] - 1.0) * *columns + jc[loop_ub];
      base_nodes[static_cast<int>(pos_count + loop_ub) - 1] = node_num;
      for (loop_ub_tmp = 0; loop_ub_tmp < i6; loop_ub_tmp++) {
        rack_rows = dest_node_num + static_cast<double>(loop_ub_tmp);
        A[(static_cast<int>(node_num) +
           A.size(0) * (static_cast<int>(rack_rows) - 1)) -
          1] = 1.0;
        A[(static_cast<int>(rack_rows) +
           A.size(0) * (static_cast<int>(node_num) - 1)) -
          1] = 1.0;
        node_num = rack_rows;
      }
      dest_node_num += static_cast<double>(i6 - 1) + 1.0;
      rack_rows = (jc[loop_ub] - 1.0) * gz_x;
      i3 = xd.size(1);
      loop_ub_tmp = static_cast<int>(*levels);
      xd.set_size(xd.size(0), xd.size(1) + static_cast<int>(*levels));
      for (i5 = 0; i5 < loop_ub_tmp; i5++) {
        xd[i3 + i5] = rack_rows;
      }
      i3 = yd.size(1);
      yd.set_size(yd.size(0), yd.size(1) + static_cast<int>(*levels));
      for (i5 = 0; i5 < loop_ub_tmp; i5++) {
        yd[i3 + i5] = level;
      }
      i3 = zd.size(1);
      zd.set_size(zd.size(0), zd.size(1) + i7);
      for (i5 = 0; i5 < d_loop_ub; i5++) {
        zd[i3 + i5] = gz_z + gz_z * botloc[i5];
      }
    }
    pos_count += jc.size(1);
  }
  coder::randperm(static_cast<double>(robot_spots.size(1)), n_robots, botloc);
  for (b_i = 0; b_i < i; b_i++) {
    robots[b_i] = static_cast<double>(b_i) + 1.0;
    rack_rows = robot_spots[static_cast<int>(botloc[b_i]) - 1];
    robots[b_i + robots.size(0)] =
        gz_x * coder::c_mod(rack_rows - 1.0, *columns);
    robots[b_i + robots.size(0) * 2] = gz_y * std::floor(rack_rows / *columns);
    robots[b_i + robots.size(0) * 3] = 0.0;
    robots[b_i + robots.size(0) * 4] = 0.707;
    robots[b_i + robots.size(0) * 5] = 0.0;
    robots[b_i + robots.size(0) * 6] = 0.0;
    robots[b_i + robots.size(0) * 7] = -0.707;
    robots[b_i + robots.size(0) * 8] = 1.0;
    robots[b_i + robots.size(0) * 9] = rack_rows;
    robots[b_i + robots.size(0) * 10] = 2.0;
  }
  coder::randperm(static_cast<double>(A.size(0)) - *rows * *columns,
                  n_totes / 2.0, botloc);
  botloc.set_size(1, botloc.size(1));
  loop_ub = botloc.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    botloc[i] = b_rows + botloc[i];
  }
  count = 1.0;
  i = botloc.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    d = botloc[b_i];
    rack_rows = d - b_rows;
    level = coder::c_mod(rack_rows, *levels);
    rack_rows = std::floor(rack_rows / *levels);
    node_num = rack_rows + 1.0;
    if (rack_rows + 1.0 == 91.0) {
      node_num = 90.0;
    }
    if (level == 0.0) {
      level = 7.0;
    }
    totes[static_cast<int>(count) - 1] = count;
    dest_node_num = base_nodes[static_cast<int>(node_num) - 1];
    mid_line = gz_x * (coder::c_mod(dest_node_num, *columns) - 1.0);
    totes[(static_cast<int>(count) + totes.size(0)) - 1] = mid_line;
    dest_node_num = std::floor(dest_node_num / *columns);
    totes[(static_cast<int>(count) + totes.size(0) * 2) - 1] =
        gz_y * (dest_node_num + 1.0);
    rack_rows = gz_z + gz_z * level;
    totes[(static_cast<int>(count) + totes.size(0) * 3) - 1] = rack_rows;
    totes[(static_cast<int>(count) + totes.size(0) * 4) - 1] = 0.707;
    totes[(static_cast<int>(count) + totes.size(0) * 5) - 1] = 0.0;
    totes[(static_cast<int>(count) + totes.size(0) * 6) - 1] = 0.0;
    totes[(static_cast<int>(count) + totes.size(0) * 7) - 1] = -0.707;
    totes[(static_cast<int>(count) + totes.size(0) * 8) - 1] = 0.0;
    totes[(static_cast<int>(count) + totes.size(0) * 9) - 1] = d;
    totes[(static_cast<int>(count) + totes.size(0) * 10) - 1] = 2.0;
    node_num = (n_totes - count) + 1.0;
    totes[static_cast<int>(node_num) - 1] = node_num;
    totes[(static_cast<int>(node_num) + totes.size(0)) - 1] = mid_line;
    totes[(static_cast<int>(node_num) + totes.size(0) * 2) - 1] =
        gz_y * (dest_node_num - 1.0);
    totes[(static_cast<int>(node_num) + totes.size(0) * 3) - 1] = rack_rows;
    totes[(static_cast<int>(node_num) + totes.size(0) * 4) - 1] = 0.707;
    totes[(static_cast<int>(node_num) + totes.size(0) * 5) - 1] = 0.0;
    totes[(static_cast<int>(node_num) + totes.size(0) * 6) - 1] = 0.0;
    totes[(static_cast<int>(node_num) + totes.size(0) * 7) - 1] = -0.707;
    totes[(static_cast<int>(node_num) + totes.size(0) * 8) - 1] = 0.0;
    totes[(static_cast<int>(node_num) + totes.size(0) * 9) - 1] = d;
    totes[(static_cast<int>(node_num) + totes.size(0) * 10) - 1] = 2.0;
    count++;
  }
  count = 0.0;
  if (0.0 < n_delivery_stations) {
    delivery_stations[0] = *columns + 7.0;
    count = 1.0;
  }
  if (count < n_delivery_stations) {
    delivery_stations[static_cast<int>(count)] = *columns + (*columns - 6.0);
    count++;
  }
  if (count < n_delivery_stations) {
    delivery_stations[static_cast<int>(count)] = 2.0 * *columns + 7.0;
    count++;
  }
  if (count < n_delivery_stations) {
    delivery_stations[static_cast<int>(count)] =
        2.0 * *columns + (*columns - 6.0);
  }
  //      figure('units','normalized','outerposition',[0 0 1 1])
  //      graph = digraph(A, string([1:size(A,1)]));
  //      p = plot(graph,'XData', xd, 'YData', yd, 'Zdata', zd);
  //  %     p.NodeColor = 'black';
  //  %     p.NodeLabelMode = 'auto';
  //  %     p.EdgeLabel = graph.Edges.Weight;
  //      p.ArrowSize = 6;
  //      p.LineWidth = 1;
  //      axis equal
  //      xlim([-0.4,wh_x])
  //      ylim([-0.3,wh_y])
  //      zlim([-0.2,wh_z])
  //      hold on
  //      plot(xd(robot_spots), yd(robot_spots), '*r')
  //  %     plot3(robots(:,2),robots(:,3),robots(:,4),'*r')
  //  %     plot3(totes(:,2),totes(:,3),totes(:,4),'*g')
  graph_info.set_size(A.size(0), 16);
  loop_ub = A.size(0) << 4;
  for (i = 0; i < loop_ub; i++) {
    graph_info[i] = 0.0;
  }
  i = A.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    loop_ub = A.size(1);
    b_A.set_size(1, A.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_A[i1] = (A[b_i + A.size(0) * i1] > 0.0);
    }
    coder::eml_find(b_A, r);
    botloc.set_size(1, r.size(1));
    loop_ub = r.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      botloc[i1] = r[i1];
    }
    ic.set_size(1, botloc.size(1));
    loop_ub = botloc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      ic[i1] = A[b_i + A.size(0) * (static_cast<int>(botloc[i1]) - 1)];
    }
    loop_ub_tmp = 6 - botloc.size(1);
    base_nodes.set_size(1, (ic.size(1) - botloc.size(1)) + 16);
    base_nodes[0] = static_cast<double>(b_i) + 1.0;
    base_nodes[1] = xd[b_i];
    base_nodes[2] = yd[b_i];
    base_nodes[3] = zd[b_i];
    loop_ub = botloc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      base_nodes[i1 + 4] = botloc[i1];
    }
    loop_ub = 6 - botloc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      base_nodes[(i1 + botloc.size(1)) + 4] = 0.0;
    }
    loop_ub = ic.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      base_nodes[((i1 + botloc.size(1)) + loop_ub_tmp) + 4] = ic[i1];
    }
    loop_ub = 6 - botloc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      base_nodes[(((i1 + botloc.size(1)) + loop_ub_tmp) + ic.size(1)) + 4] =
          0.0;
    }
    for (i1 = 0; i1 < 16; i1++) {
      graph_info[b_i + graph_info.size(0) * i1] = base_nodes[i1];
    }
  }
}

//
// File trailer for spawn_graph_robots_totes_new.cpp
//
// [EOF]
//
