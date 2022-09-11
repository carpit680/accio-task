/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "accio_task/main.h"
#include "accio_task/rt_nonfinite.h"
#include "accio_task/spawn_graph_robots_totes_new.h"
#include "accio_task/spawn_graph_robots_totes_new_terminate.h"
#include "accio_task/coder_array.h"

// Function Declarations
static double argInit_real_T();

static void main_spawn_graph_robots_totes_new();

// Function Definitions
//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_spawn_graph_robots_totes_new()
{
  coder::array<double, 2U> delivery_stations;
  coder::array<double, 2U> graph_info;
  coder::array<double, 2U> robot_spots;
  coder::array<double, 2U> robots;
  coder::array<double, 2U> totes;
  double columns;
  double levels;
  double rows;
  double wh_x_tmp;
  // Initialize function 'spawn_graph_robots_totes_new' input arguments.
  wh_x_tmp = argInit_real_T();
  // Call the entry-point 'spawn_graph_robots_totes_new'.
  spawn_graph_robots_totes_new(wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp,
                               wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp, wh_x_tmp,
                               robots, totes, robot_spots, delivery_stations,
                               graph_info, &columns, &rows, &levels);
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_spawn_graph_robots_totes_new();
  // Terminate the application.
  // You do not need to do this more than one time.
  spawn_graph_robots_totes_new_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
