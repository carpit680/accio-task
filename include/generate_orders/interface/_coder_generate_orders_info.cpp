//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_generate_orders_info.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 30-Aug-2022 15:10:14
//

// Include Files
#include "_coder_generate_orders_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
//
// Arguments    : void
// Return Type  : const mxArray *
//
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  static const int32_T iv[2]{0, 1};
  const mxArray *m;
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&nameCaptureInfo, m);
  return nameCaptureInfo;
}

//
// Arguments    : void
// Return Type  : mxArray *
//
mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6]{
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  const char_T *propFieldName[5]{"Version", "ResolvedFunctions", "EntryPoints",
                                 "CoverageInfo", "IsPolymorphic"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"Name",
                emlrtMxCreateString((const char_T *)"generate_orders"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, (const char_T *)"FullPath",
      emlrtMxCreateString((
          const char_T *)"/home/arjun/Documents/MATLAB/Examples/R2021b/"
                         "robotics/VerticalRobotSimulation/generate_orders.m"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"TimeStamp",
                emlrtMxCreateDoubleScalar(738763.57888888894));
  xResult =
      emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&propFieldName[0]);
  emlrtSetField(
      xResult, 0, (const char_T *)"Version",
      emlrtMxCreateString((const char_T *)"9.11.0.2022996 (R2021b) Update 4"));
  emlrtSetField(xResult, 0, (const char_T *)"ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_generate_orders_info.cpp
//
// [EOF]
//
