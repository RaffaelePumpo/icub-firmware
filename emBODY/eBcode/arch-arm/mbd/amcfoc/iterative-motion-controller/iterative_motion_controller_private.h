//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: iterative_motion_controller_private.h
//
// Code generated for Simulink model 'iterative_motion_controller'.
//
// Model version                  : 4.29
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 30 12:36:29 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef iterative_motion_controller_private_h_
#define iterative_motion_controller_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "iterative_motion_controller_types.h"
#include "iterative_motion_controller.h"

extern void iterative_motion_controller_SortEvents_Init(ReceivedEvents
  rty_SortedEvs[8]);
extern void iterative_motion_controller_SortEvents(const ReceivedEvents rtu_e[8],
  ReceivedEvents rty_SortedEvs[8]);

#endif                                // iterative_motion_controller_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
