//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: control_foc.h
//
// Code generated for Simulink model 'control_foc'.
//
// Model version                  : 9.8
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 30 12:05:19 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef control_foc_h_
#define control_foc_h_
#include "rtwtypes.h"
#include "control_foc_types.h"
#include "FOCInnerLoop.h"

// Block signals for model 'control_foc'
struct B_control_foc_c_T {
  B_FOCInnerLoop_T FOCinnerloop;       // '<Root>/FOC inner loop'
};

// Block states (default storage) for model 'control_foc'
struct DW_control_foc_f_T {
  DW_FOCInnerLoop_T FOCinnerloop;      // '<Root>/FOC inner loop'
};

// Zero-crossing (trigger) state for model 'control_foc'
struct ZCE_control_foc_T {
  ZCE_FOCInnerLoop_T FOCinnerloop;     // '<Root>/FOC inner loop'
};

struct MdlrefDW_control_foc_T {
  B_control_foc_c_T rtb;
  DW_control_foc_f_T rtdw;
  ZCE_control_foc_T rtzce;
};

// Model reference registration function
extern void control_foc_initialize(ZCE_control_foc_T *localZCE);
extern void control_foc_Init(DW_control_foc_f_T *localDW);
extern void control_foc(const SensorsData *rtu_Sensors, const FOCSlowInputs
  *rtu_FocSlowInputs, const boolean_T *rtu_CalibrationDone, const boolean_T
  *rtu_areLimitSet, FOCOutputs *rty_FOCOutputs, B_control_foc_c_T *localB,
  DW_control_foc_f_T *localDW, ZCE_control_foc_T *localZCE);
extern void control_foc_Term(DW_control_foc_f_T *localDW);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S19>/Data Type Duplicate' : Unused code path elimination
//  Block '<S1>/Direct Lookup Table (n-D)1' : Unused code path elimination
//  Block '<S70>/Data Type Duplicate' : Unused code path elimination
//  Block '<S70>/Data Type Propagation' : Unused code path elimination
//  Block '<S84>/Data Type Duplicate' : Unused code path elimination
//  Block '<S88>/Data Type Duplicate' : Unused code path elimination
//  Block '<S88>/Data Type Duplicate1' : Unused code path elimination
//  Block '<S147>/Data Type Duplicate' : Unused code path elimination
//  Block '<S147>/Data Type Duplicate1' : Unused code path elimination
//  Block '<S13>/Data Type Duplicate' : Unused code path elimination
//  Block '<S13>/Data Type Propagation' : Unused code path elimination
//  Block '<S18>/Kalpha' : Eliminated nontunable gain of 1
//  Block '<S18>/Kbeta' : Eliminated nontunable gain of 1
//  Block '<S55>/Passthrough for tuning' : Eliminate redundant data type conversion
//  Block '<S84>/Ka' : Eliminated nontunable gain of 1
//  Block '<S84>/Kb' : Eliminated nontunable gain of 1
//  Block '<S84>/Kc' : Eliminated nontunable gain of 1
//  Block '<S119>/Passthrough for tuning' : Eliminate redundant data type conversion
//  Block '<S137>/Kt' : Eliminated nontunable gain of 1
//  Block '<S89>/Offset' : Unused code path elimination
//  Block '<S89>/Unary_Minus' : Unused code path elimination
//  Block '<S148>/Offset' : Unused code path elimination
//  Block '<S148>/Unary_Minus' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'control_foc'
//  '<S1>'   : 'control_foc/FOC inner loop'
//  '<S2>'   : 'control_foc/FOC inner loop/Chart'
//  '<S3>'   : 'control_foc/FOC inner loop/Clarke Transform'
//  '<S4>'   : 'control_foc/FOC inner loop/Compute RMS'
//  '<S5>'   : 'control_foc/FOC inner loop/Compute Sin//Cos'
//  '<S6>'   : 'control_foc/FOC inner loop/Degrees to Radians'
//  '<S7>'   : 'control_foc/FOC inner loop/Feedforward'
//  '<S8>'   : 'control_foc/FOC inner loop/Id PID control'
//  '<S9>'   : 'control_foc/FOC inner loop/Inverse Clarke Transform'
//  '<S10>'  : 'control_foc/FOC inner loop/Inverse Park Transform'
//  '<S11>'  : 'control_foc/FOC inner loop/Iq PID control'
//  '<S12>'  : 'control_foc/FOC inner loop/Park Transform'
//  '<S13>'  : 'control_foc/FOC inner loop/Saturation Dynamic'
//  '<S14>'  : 'control_foc/FOC inner loop/Chart/ComputeOffset'
//  '<S15>'  : 'control_foc/FOC inner loop/Clarke Transform/Variant'
//  '<S16>'  : 'control_foc/FOC inner loop/Clarke Transform/Variant/mcb'
//  '<S17>'  : 'control_foc/FOC inner loop/Clarke Transform/Variant/mcb/Clarke Transform'
//  '<S18>'  : 'control_foc/FOC inner loop/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input'
//  '<S19>'  : 'control_foc/FOC inner loop/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input/Two phase CRL wrap'
//  '<S20>'  : 'control_foc/FOC inner loop/Compute RMS/Disabled'
//  '<S21>'  : 'control_foc/FOC inner loop/Compute Sin//Cos/STD'
//  '<S22>'  : 'control_foc/FOC inner loop/Feedforward/FF disabled'
//  '<S23>'  : 'control_foc/FOC inner loop/Id PID control/Anti-windup'
//  '<S24>'  : 'control_foc/FOC inner loop/Id PID control/D Gain'
//  '<S25>'  : 'control_foc/FOC inner loop/Id PID control/External Derivative'
//  '<S26>'  : 'control_foc/FOC inner loop/Id PID control/Filter'
//  '<S27>'  : 'control_foc/FOC inner loop/Id PID control/Filter ICs'
//  '<S28>'  : 'control_foc/FOC inner loop/Id PID control/I Gain'
//  '<S29>'  : 'control_foc/FOC inner loop/Id PID control/Ideal P Gain'
//  '<S30>'  : 'control_foc/FOC inner loop/Id PID control/Ideal P Gain Fdbk'
//  '<S31>'  : 'control_foc/FOC inner loop/Id PID control/Integrator'
//  '<S32>'  : 'control_foc/FOC inner loop/Id PID control/Integrator ICs'
//  '<S33>'  : 'control_foc/FOC inner loop/Id PID control/N Copy'
//  '<S34>'  : 'control_foc/FOC inner loop/Id PID control/N Gain'
//  '<S35>'  : 'control_foc/FOC inner loop/Id PID control/P Copy'
//  '<S36>'  : 'control_foc/FOC inner loop/Id PID control/Parallel P Gain'
//  '<S37>'  : 'control_foc/FOC inner loop/Id PID control/Reset Signal'
//  '<S38>'  : 'control_foc/FOC inner loop/Id PID control/Saturation'
//  '<S39>'  : 'control_foc/FOC inner loop/Id PID control/Saturation Fdbk'
//  '<S40>'  : 'control_foc/FOC inner loop/Id PID control/Sum'
//  '<S41>'  : 'control_foc/FOC inner loop/Id PID control/Sum Fdbk'
//  '<S42>'  : 'control_foc/FOC inner loop/Id PID control/Tracking Mode'
//  '<S43>'  : 'control_foc/FOC inner loop/Id PID control/Tracking Mode Sum'
//  '<S44>'  : 'control_foc/FOC inner loop/Id PID control/Tsamp - Integral'
//  '<S45>'  : 'control_foc/FOC inner loop/Id PID control/Tsamp - Ngain'
//  '<S46>'  : 'control_foc/FOC inner loop/Id PID control/postSat Signal'
//  '<S47>'  : 'control_foc/FOC inner loop/Id PID control/preInt Signal'
//  '<S48>'  : 'control_foc/FOC inner loop/Id PID control/preSat Signal'
//  '<S49>'  : 'control_foc/FOC inner loop/Id PID control/Anti-windup/Disc. Clamping Parallel'
//  '<S50>'  : 'control_foc/FOC inner loop/Id PID control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S51>'  : 'control_foc/FOC inner loop/Id PID control/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
//  '<S52>'  : 'control_foc/FOC inner loop/Id PID control/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
//  '<S53>'  : 'control_foc/FOC inner loop/Id PID control/D Gain/External Parameters'
//  '<S54>'  : 'control_foc/FOC inner loop/Id PID control/External Derivative/Error'
//  '<S55>'  : 'control_foc/FOC inner loop/Id PID control/Filter/Disc. Trapezoidal Filter'
//  '<S56>'  : 'control_foc/FOC inner loop/Id PID control/Filter/Disc. Trapezoidal Filter/Tsamp'
//  '<S57>'  : 'control_foc/FOC inner loop/Id PID control/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
//  '<S58>'  : 'control_foc/FOC inner loop/Id PID control/Filter ICs/External IC'
//  '<S59>'  : 'control_foc/FOC inner loop/Id PID control/I Gain/External Parameters'
//  '<S60>'  : 'control_foc/FOC inner loop/Id PID control/Ideal P Gain/Passthrough'
//  '<S61>'  : 'control_foc/FOC inner loop/Id PID control/Ideal P Gain Fdbk/Passthrough'
//  '<S62>'  : 'control_foc/FOC inner loop/Id PID control/Integrator/Discrete'
//  '<S63>'  : 'control_foc/FOC inner loop/Id PID control/Integrator ICs/External IC'
//  '<S64>'  : 'control_foc/FOC inner loop/Id PID control/N Copy/External Parameters'
//  '<S65>'  : 'control_foc/FOC inner loop/Id PID control/N Gain/External Parameters'
//  '<S66>'  : 'control_foc/FOC inner loop/Id PID control/P Copy/Disabled'
//  '<S67>'  : 'control_foc/FOC inner loop/Id PID control/Parallel P Gain/External Parameters'
//  '<S68>'  : 'control_foc/FOC inner loop/Id PID control/Reset Signal/External Reset'
//  '<S69>'  : 'control_foc/FOC inner loop/Id PID control/Saturation/External'
//  '<S70>'  : 'control_foc/FOC inner loop/Id PID control/Saturation/External/Saturation Dynamic'
//  '<S71>'  : 'control_foc/FOC inner loop/Id PID control/Saturation Fdbk/Passthrough'
//  '<S72>'  : 'control_foc/FOC inner loop/Id PID control/Sum/Sum_PID'
//  '<S73>'  : 'control_foc/FOC inner loop/Id PID control/Sum Fdbk/Enabled'
//  '<S74>'  : 'control_foc/FOC inner loop/Id PID control/Tracking Mode/Disabled'
//  '<S75>'  : 'control_foc/FOC inner loop/Id PID control/Tracking Mode Sum/Passthrough'
//  '<S76>'  : 'control_foc/FOC inner loop/Id PID control/Tsamp - Integral/TsSignalSpecification'
//  '<S77>'  : 'control_foc/FOC inner loop/Id PID control/Tsamp - Ngain/Passthrough'
//  '<S78>'  : 'control_foc/FOC inner loop/Id PID control/postSat Signal/Feedback_Path'
//  '<S79>'  : 'control_foc/FOC inner loop/Id PID control/preInt Signal/Internal PreInt'
//  '<S80>'  : 'control_foc/FOC inner loop/Id PID control/preSat Signal/Feedback_Path'
//  '<S81>'  : 'control_foc/FOC inner loop/Inverse Clarke Transform/Variant'
//  '<S82>'  : 'control_foc/FOC inner loop/Inverse Clarke Transform/Variant/mcb'
//  '<S83>'  : 'control_foc/FOC inner loop/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
//  '<S84>'  : 'control_foc/FOC inner loop/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
//  '<S85>'  : 'control_foc/FOC inner loop/Inverse Park Transform/Variant'
//  '<S86>'  : 'control_foc/FOC inner loop/Inverse Park Transform/Variant/mcb'
//  '<S87>'  : 'control_foc/FOC inner loop/Inverse Park Transform/Variant/mcb/Inverse Park Transform'
//  '<S88>'  : 'control_foc/FOC inner loop/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL'
//  '<S89>'  : 'control_foc/FOC inner loop/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL/Switch_Axis'
//  '<S90>'  : 'control_foc/FOC inner loop/Iq PID control/Anti-windup'
//  '<S91>'  : 'control_foc/FOC inner loop/Iq PID control/D Gain'
//  '<S92>'  : 'control_foc/FOC inner loop/Iq PID control/External Derivative'
//  '<S93>'  : 'control_foc/FOC inner loop/Iq PID control/Filter'
//  '<S94>'  : 'control_foc/FOC inner loop/Iq PID control/Filter ICs'
//  '<S95>'  : 'control_foc/FOC inner loop/Iq PID control/I Gain'
//  '<S96>'  : 'control_foc/FOC inner loop/Iq PID control/Ideal P Gain'
//  '<S97>'  : 'control_foc/FOC inner loop/Iq PID control/Ideal P Gain Fdbk'
//  '<S98>'  : 'control_foc/FOC inner loop/Iq PID control/Integrator'
//  '<S99>'  : 'control_foc/FOC inner loop/Iq PID control/Integrator ICs'
//  '<S100>' : 'control_foc/FOC inner loop/Iq PID control/N Copy'
//  '<S101>' : 'control_foc/FOC inner loop/Iq PID control/N Gain'
//  '<S102>' : 'control_foc/FOC inner loop/Iq PID control/P Copy'
//  '<S103>' : 'control_foc/FOC inner loop/Iq PID control/Parallel P Gain'
//  '<S104>' : 'control_foc/FOC inner loop/Iq PID control/Reset Signal'
//  '<S105>' : 'control_foc/FOC inner loop/Iq PID control/Saturation'
//  '<S106>' : 'control_foc/FOC inner loop/Iq PID control/Saturation Fdbk'
//  '<S107>' : 'control_foc/FOC inner loop/Iq PID control/Sum'
//  '<S108>' : 'control_foc/FOC inner loop/Iq PID control/Sum Fdbk'
//  '<S109>' : 'control_foc/FOC inner loop/Iq PID control/Tracking Mode'
//  '<S110>' : 'control_foc/FOC inner loop/Iq PID control/Tracking Mode Sum'
//  '<S111>' : 'control_foc/FOC inner loop/Iq PID control/Tsamp - Integral'
//  '<S112>' : 'control_foc/FOC inner loop/Iq PID control/Tsamp - Ngain'
//  '<S113>' : 'control_foc/FOC inner loop/Iq PID control/postSat Signal'
//  '<S114>' : 'control_foc/FOC inner loop/Iq PID control/preInt Signal'
//  '<S115>' : 'control_foc/FOC inner loop/Iq PID control/preSat Signal'
//  '<S116>' : 'control_foc/FOC inner loop/Iq PID control/Anti-windup/Passthrough'
//  '<S117>' : 'control_foc/FOC inner loop/Iq PID control/D Gain/External Parameters'
//  '<S118>' : 'control_foc/FOC inner loop/Iq PID control/External Derivative/Error'
//  '<S119>' : 'control_foc/FOC inner loop/Iq PID control/Filter/Disc. Trapezoidal Filter'
//  '<S120>' : 'control_foc/FOC inner loop/Iq PID control/Filter/Disc. Trapezoidal Filter/Tsamp'
//  '<S121>' : 'control_foc/FOC inner loop/Iq PID control/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
//  '<S122>' : 'control_foc/FOC inner loop/Iq PID control/Filter ICs/External IC'
//  '<S123>' : 'control_foc/FOC inner loop/Iq PID control/I Gain/External Parameters'
//  '<S124>' : 'control_foc/FOC inner loop/Iq PID control/Ideal P Gain/Passthrough'
//  '<S125>' : 'control_foc/FOC inner loop/Iq PID control/Ideal P Gain Fdbk/Passthrough'
//  '<S126>' : 'control_foc/FOC inner loop/Iq PID control/Integrator/Discrete'
//  '<S127>' : 'control_foc/FOC inner loop/Iq PID control/Integrator ICs/External IC'
//  '<S128>' : 'control_foc/FOC inner loop/Iq PID control/N Copy/External Parameters'
//  '<S129>' : 'control_foc/FOC inner loop/Iq PID control/N Gain/External Parameters'
//  '<S130>' : 'control_foc/FOC inner loop/Iq PID control/P Copy/Disabled'
//  '<S131>' : 'control_foc/FOC inner loop/Iq PID control/Parallel P Gain/External Parameters'
//  '<S132>' : 'control_foc/FOC inner loop/Iq PID control/Reset Signal/External Reset'
//  '<S133>' : 'control_foc/FOC inner loop/Iq PID control/Saturation/Passthrough'
//  '<S134>' : 'control_foc/FOC inner loop/Iq PID control/Saturation Fdbk/Passthrough'
//  '<S135>' : 'control_foc/FOC inner loop/Iq PID control/Sum/Sum_PID'
//  '<S136>' : 'control_foc/FOC inner loop/Iq PID control/Sum Fdbk/Enabled'
//  '<S137>' : 'control_foc/FOC inner loop/Iq PID control/Tracking Mode/Enabled'
//  '<S138>' : 'control_foc/FOC inner loop/Iq PID control/Tracking Mode Sum/Tracking Mode'
//  '<S139>' : 'control_foc/FOC inner loop/Iq PID control/Tsamp - Integral/TsSignalSpecification'
//  '<S140>' : 'control_foc/FOC inner loop/Iq PID control/Tsamp - Ngain/Passthrough'
//  '<S141>' : 'control_foc/FOC inner loop/Iq PID control/postSat Signal/Feedback_Path'
//  '<S142>' : 'control_foc/FOC inner loop/Iq PID control/preInt Signal/Internal PreInt'
//  '<S143>' : 'control_foc/FOC inner loop/Iq PID control/preSat Signal/Feedback_Path'
//  '<S144>' : 'control_foc/FOC inner loop/Park Transform/Variant'
//  '<S145>' : 'control_foc/FOC inner loop/Park Transform/Variant/mcb'
//  '<S146>' : 'control_foc/FOC inner loop/Park Transform/Variant/mcb/Park Transform'
//  '<S147>' : 'control_foc/FOC inner loop/Park Transform/Variant/mcb/Park Transform/Two inputs CRL'
//  '<S148>' : 'control_foc/FOC inner loop/Park Transform/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'

#endif                                 // control_foc_h_

//
// File trailer for generated code.
//
// [EOF]
//
