//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Calibrator.h
//
// Code generated for Simulink model 'Calibrator'.
//
// Model version                  : 1.110
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 16 15:20:31 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Calibrator_h_
#define Calibrator_h_
#include "rtwtypes.h"
#include "Calibrator_types.h"

// Block signals for model 'Calibrator'
struct B_Calibrator_c_T {
  real32_T offset;                     // '<S2>/calibrator'
  real32_T target_angle;               // '<S2>/calibrator'
  real32_T Iq_ref;                     // '<S2>/calibrator'
  boolean_T finish;                    // '<S2>/calibrator'
};

// Block states (default storage) for model 'Calibrator'
struct DW_Calibrator_f_T {
  real_T condition;                    // '<S2>/calibrator'
  real_T talign;                       // '<S2>/calibrator'
  real_T tzeroalign;                   // '<S2>/calibrator'
  real_T v_threshold;                  // '<S2>/calibrator'
  uint32_T Delay_DSTATE[665];          // '<S3>/Delay'
  real32_T count;                      // '<S2>/calibrator'
  real32_T p_index;                    // '<S2>/calibrator'
  real32_T diff_index;                 // '<S2>/calibrator'
  uint32_T CircBufIdx;                 // '<S3>/Delay'
  uint32_T temporalCounter_i1;         // '<S2>/calibrator'
  int8_T SwitchCase1_ActiveSubsystem;  // '<Root>/Switch Case1'
  uint8_T is_active_c1_Calibrator;     // '<S2>/calibrator'
  uint8_T is_c1_Calibrator;            // '<S2>/calibrator'
};

struct MdlrefDW_Calibrator_T {
  B_Calibrator_c_T rtb;
  DW_Calibrator_f_T rtdw;
};

extern void Calibrator_Init(DW_Calibrator_f_T *localDW);
extern void Calibrator_Disable(DW_Calibrator_f_T *localDW);
extern void Calibrator(const Flags *rtu_Flags, const SensorsData *rtu_Sensors,
  const FOCSlowInputs *rtu_FocInputs, const ActuatorConfiguration
  *rtu_ActuatorCfg, boolean_T *rty_CalibrationDone, SensorsData
  *rty_SensorDataCalibration, FOCSlowInputs *rty_FocInputsCalibration,
  B_Calibrator_c_T *localB, DW_Calibrator_f_T *localDW);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/DataTypeSet' : Unused code path elimination
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
//  '<Root>' : 'Calibrator'
//  '<S1>'   : 'Calibrator/If Action Subsystem2'
//  '<S2>'   : 'Calibrator/If Action Subsystem3'
//  '<S3>'   : 'Calibrator/If Action Subsystem3/Speed Measurement2'
//  '<S4>'   : 'Calibrator/If Action Subsystem3/calibrator'
//  '<S5>'   : 'Calibrator/If Action Subsystem3/Speed Measurement2/DT_Handle'
//  '<S6>'   : 'Calibrator/If Action Subsystem3/Speed Measurement2/DT_Handle/floating-point'

#endif                                 // Calibrator_h_

//
// File trailer for generated code.
//
// [EOF]
//
