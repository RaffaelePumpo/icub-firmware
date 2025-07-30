//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: FOCInnerLoop.h
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
#ifndef FOCInnerLoop_h_
#define FOCInnerLoop_h_
#include "rtwtypes.h"
#include "control_foc_types.h"
#include "zero_crossing_types.h"

// Block signals for system '<Root>/FOC inner loop'
struct B_FOCInnerLoop_T {
  real32_T SumI1;                      // '<S138>/SumI1'
  real32_T Integrator;                 // '<S126>/Integrator'
  real32_T Switch;                     // '<S49>/Switch'
  real32_T Integrator_j;               // '<S62>/Integrator'
  real32_T outputs[3];                 // '<S1>/Chart'
};

// Block states (default storage) for system '<Root>/FOC inner loop'
struct DW_FOCInnerLoop_T {
  dsp_simulink_MovingAverage_control_foc_T obj;// '<S14>/Moving Average'
  real32_T FilterDifferentiatorTF_states;// '<S119>/Filter Differentiator TF'
  real32_T UnitDelay_DSTATE;           // '<S1>/Unit Delay'
  real32_T Integrator_DSTATE;          // '<S126>/Integrator'
  real32_T FilterDifferentiatorTF_states_k;// '<S55>/Filter Differentiator TF'
  real32_T Integrator_DSTATE_o;        // '<S62>/Integrator'
  real32_T FilterDifferentiatorTF_tmp; // '<S119>/Filter Differentiator TF'
  real32_T FilterDifferentiatorTF_tmp_c;// '<S55>/Filter Differentiator TF'
  real32_T offsets[3];                 // '<S1>/Chart'
  int8_T Integrator_PrevResetState;    // '<S126>/Integrator'
  int8_T Integrator_PrevResetState_k;  // '<S62>/Integrator'
  uint8_T FilterDifferentiatorTF_icLoad;// '<S119>/Filter Differentiator TF'
  uint8_T Integrator_IC_LOADING;       // '<S126>/Integrator'
  uint8_T FilterDifferentiatorTF_icLoad_c;// '<S55>/Filter Differentiator TF'
  uint8_T Integrator_IC_LOADING_b;     // '<S62>/Integrator'
  uint8_T is_active_c3_control_foc;    // '<S1>/Chart'
  uint8_T is_c3_control_foc;           // '<S1>/Chart'
  uint8_T temporalCounter_i1;          // '<S1>/Chart'
  boolean_T objisempty;                // '<S14>/Moving Average'
};

// Zero-crossing (trigger) state for system '<Root>/FOC inner loop'
struct ZCE_FOCInnerLoop_T {
  ZCSigState FilterDifferentiatorTF_Reset_ZCE;// '<S119>/Filter Differentiator TF' 
  ZCSigState FilterDifferentiatorTF_Reset_ZCE_o;// '<S55>/Filter Differentiator TF' 
};

extern void FOCInnerLoop_Init(DW_FOCInnerLoop_T *localDW);
extern void FOCInnerLoop_Update(const ControlOuterOutputs *rtu_OuterOutputs,
  B_FOCInnerLoop_T *localB, DW_FOCInnerLoop_T *localDW);
extern void FOCInnerLoop(const boolean_T *rtu_CalibrationDone, const SensorsData
  *rtu_Sensors_Inport_2, const ActuatorConfiguration
  *rtu_ConfigurationParameters, const Targets *rtu_Targets_Inport_5, const
  ControlOuterOutputs *rtu_OuterOutputs, const boolean_T *rtu_areLimitSet,
  FOCOutputs *rty_FOCOutputs, B_FOCInnerLoop_T *localB, DW_FOCInnerLoop_T
  *localDW, ZCE_FOCInnerLoop_T *localZCE);
extern void FOCInnerLoop_Term(DW_FOCInnerLoop_T *localDW);

#endif                                 // FOCInnerLoop_h_

//
// File trailer for generated code.
//
// [EOF]
//
