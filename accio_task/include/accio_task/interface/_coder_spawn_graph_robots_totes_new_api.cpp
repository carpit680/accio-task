//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_spawn_graph_robots_totes_new_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 22-Aug-2022 16:38:52
//

// Include Files
#include "_coder_spawn_graph_robots_totes_new_api.h"
#include "_coder_spawn_graph_robots_totes_new_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "spawn_graph_robots_totes_new",                       // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *wh_x,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *wh_x
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *wh_x,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(wh_x), &thisId);
  emlrtDestroyArray(&wh_x);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<real_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const real_T u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray * const prhs[10]
//                int32_T nlhs
//                const mxArray *plhs[8]
// Return Type  : void
//
void spawn_graph_robots_totes_new_api(const mxArray *const prhs[10],
                                      int32_T nlhs, const mxArray *plhs[8])
{
  coder::array<real_T, 2U> delivery_stations;
  coder::array<real_T, 2U> graph_info;
  coder::array<real_T, 2U> robot_spots;
  coder::array<real_T, 2U> robots;
  coder::array<real_T, 2U> totes;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T columns;
  real_T gz_x;
  real_T gz_y;
  real_T gz_z;
  real_T levels;
  real_T n_delivery_grid;
  real_T n_delivery_stations;
  real_T n_robots;
  real_T n_totes;
  real_T rows;
  real_T wh_x;
  real_T wh_y;
  real_T wh_z;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  wh_x = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "wh_x");
  wh_y = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "wh_y");
  wh_z = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "wh_z");
  gz_x = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "gz_x");
  gz_y = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "gz_y");
  gz_z = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "gz_z");
  n_robots = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "n_robots");
  n_totes = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "n_totes");
  n_delivery_stations =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "n_delivery_stations");
  n_delivery_grid =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "n_delivery_grid");
  // Invoke the target function
  spawn_graph_robots_totes_new(wh_x, wh_y, wh_z, gz_x, gz_y, gz_z, n_robots,
                               n_totes, n_delivery_stations, n_delivery_grid,
                               robots, totes, robot_spots, delivery_stations,
                               graph_info, &columns, &rows, &levels);
  // Marshall function outputs
  robots.no_free();
  plhs[0] = emlrt_marshallOut(robots);
  if (nlhs > 1) {
    totes.no_free();
    plhs[1] = emlrt_marshallOut(totes);
  }
  if (nlhs > 2) {
    robot_spots.no_free();
    plhs[2] = emlrt_marshallOut(robot_spots);
  }
  if (nlhs > 3) {
    delivery_stations.no_free();
    plhs[3] = emlrt_marshallOut(delivery_stations);
  }
  if (nlhs > 4) {
    graph_info.no_free();
    plhs[4] = emlrt_marshallOut(graph_info);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(columns);
  }
  if (nlhs > 6) {
    plhs[6] = emlrt_marshallOut(rows);
  }
  if (nlhs > 7) {
    plhs[7] = emlrt_marshallOut(levels);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void spawn_graph_robots_totes_new_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  spawn_graph_robots_totes_new_xil_terminate();
  spawn_graph_robots_totes_new_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void spawn_graph_robots_totes_new_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void spawn_graph_robots_totes_new_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_spawn_graph_robots_totes_new_api.cpp
//
// [EOF]
//
