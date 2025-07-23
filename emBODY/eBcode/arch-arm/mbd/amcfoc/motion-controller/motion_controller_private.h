//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: motion_controller_private.h
//
// Code generated for Simulink model 'motion_controller'.
//
// Model version                  : 5.79
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 23 11:46:18 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef motion_controller_private_h_
#define motion_controller_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "motion_controller_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

// Constant parameters (default storage)
struct ConstP_motion_controller_T {
  // Expression: EstimationVelocityModes.Disabled
  //  Referenced by: '<S1>/Constant'

  EstimationVelocityModes Constant_Value;

  // Expression: EstimationVelocityModes.MovingAverage
  //  Referenced by: '<S2>/Velocity Estimation Mode'

  EstimationVelocityModes VelocityEstimationMode_Value;
};

extern const uint32_T rtCP_pooled_UdZPJ5vElovg;

#define rtCP_Velocityestimationwindow_Value rtCP_pooled_UdZPJ5vElovg// Computed Parameter: rtCP_Velocityestimationwindow_Value
                                                                    //  Referenced by: '<S2>/Velocity estimation window'


// Constant parameters (default storage)
extern const ConstP_motion_controller_T motion_controller_ConstP;

#endif                                 // motion_controller_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
