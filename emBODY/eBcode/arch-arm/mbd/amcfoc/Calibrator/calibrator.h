//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: calibrator.h
//
// Code generated for Simulink model 'calibrator'.
//
// Model version                  : 1.99
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 16 14:12:13 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef calibrator_h_
#define calibrator_h_
#include "rtwtypes.h"
#include "calibrator_types.h"

extern void calibrator(const Flags *rtu_Flags, const SensorsData *rtu_Sensors,
  const FOCSlowInputs *rtu_FocInputs, SensorsData *rty_SensorDataCalibration,
  FOCSlowInputs *rty_FocInputsCalibration);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/AlgoDataType' : Unused code path elimination
//  Block '<S5>/DTC' : Unused code path elimination
//  Block '<S3>/DataTypeSet' : Unused code path elimination
//  Block '<S3>/Delay' : Unused code path elimination
//  Block '<S3>/PositionToCount' : Unused code path elimination
//  Block '<S3>/Product' : Unused code path elimination
//  Block '<S3>/SpeedCount' : Unused code path elimination
//  Block '<S3>/SpeedGain' : Unused code path elimination
//  Block '<S3>/fixdtDatatype' : Unused code path elimination


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
//  '<Root>' : 'calibrator'
//  '<S1>'   : 'calibrator/If Action Subsystem2'
//  '<S2>'   : 'calibrator/If Action Subsystem3'
//  '<S3>'   : 'calibrator/Speed Measurement2'
//  '<S4>'   : 'calibrator/Speed Measurement2/DT_Handle'
//  '<S5>'   : 'calibrator/Speed Measurement2/DT_Handle/floating-point'

#endif                                 // calibrator_h_

//
// File trailer for generated code.
//
// [EOF]
//
