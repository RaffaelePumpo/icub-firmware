//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: motion_controller.h
//
// Code generated for Simulink model 'motion_controller'.
//
// Model version                  : 5.60
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Fri Jul 18 16:27:28 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef motion_controller_h_
#define motion_controller_h_
#include "rtwtypes.h"
#include "motion_controller_types.h"
#include "Calibrator.h"
#include "control_foc.h"
#include "estimation_velocity.h"
#include "filter_current.h"
#include "supervisor.h"
#include "position_velocity_cascade.h"
#include "zero_crossing_types.h"

// Includes for objects with custom storage classes
#include "rtw_defines.h"

// Block signals for model 'motion_controller'
struct B_motion_controller_c_T {
  FOCSlowInputs Model_o3;              // '<Root>/Model'
  SensorsData Model_o2;                // '<Root>/Model'
  SensorsData Transitionto1ms;         // '<Root>/Transition to 1ms'
  FOCOutputs RateTransition2;          // '<Root>/Rate Transition2'
  Targets targets;                     // '<Root>/Motor Supervisor'
  real32_T velocity;                   // '<S1>/Motor Velocity Estimator'
  real32_T velocity_g;                 // '<S1>/Joint Velocity Estimator'
  real32_T TmpRTBAtMotorSupervisorInport8;
  real32_T Gain;                       // '<S10>/Gain'
};

// Block states (default storage) for model 'motion_controller'
struct DW_motion_controller_f_T {
  FOCSlowInputs RateTransition5_Buf[3];// '<Root>/Rate Transition5'
  ActuatorConfiguration RateTransition4_Buf[3];// '<Root>/Rate Transition4'
  ActuatorConfiguration RateTransition3_Buf[3];// '<Root>/Rate Transition3'
  SensorsData Transitionto1ms_Buf0;    // '<Root>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf1;    // '<Root>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf2;    // '<Root>/Transition to 1ms'
  FOCOutputs RateTransition2_Buf0;     // '<Root>/Rate Transition2'
  FOCOutputs RateTransition2_Buf1;     // '<Root>/Rate Transition2'
  FOCOutputs RateTransition2_Buf2;     // '<Root>/Rate Transition2'
  Flags Flags_Buf[3];                  // synthesized block
  void* RateTransition4_SEMAPHORE;     // '<Root>/Rate Transition4'
  void* Flags_SEMAPHORE;               // synthesized block
  void* RateTransition5_SEMAPHORE;     // '<Root>/Rate Transition5'
  void* RateTransition3_SEMAPHORE;     // '<Root>/Rate Transition3'
  void* RateTransition2_SEMAPHORE;     // '<Root>/Rate Transition2'
  void* Transitionto1ms_SEMAPHORE;     // '<Root>/Transition to 1ms'
  real32_T Unwrap_Prev;                // '<S7>/Unwrap'
  real32_T Unwrap_Cumsum;              // '<S7>/Unwrap'
  boolean_T UnitDelay1_DSTATE;         // '<S3>/Unit Delay1'
  boolean_T DelayInput1_DSTATE;        // '<S6>/Delay Input1'
  int8_T RateTransition4_LstBufWR;     // '<Root>/Rate Transition4'
  int8_T RateTransition4_RDBuf;        // '<Root>/Rate Transition4'
  int8_T Flags_LstBufWR;               // synthesized block
  int8_T Flags_RDBuf;                  // synthesized block
  int8_T RateTransition5_LstBufWR;     // '<Root>/Rate Transition5'
  int8_T RateTransition5_RDBuf;        // '<Root>/Rate Transition5'
  int8_T RateTransition3_LstBufWR;     // '<Root>/Rate Transition3'
  int8_T RateTransition3_RDBuf;        // '<Root>/Rate Transition3'
  int8_T RateTransition2_LstBufWR;     // '<Root>/Rate Transition2'
  int8_T RateTransition2_RDBuf;        // '<Root>/Rate Transition2'
  int8_T Transitionto1ms_LstBufWR;     // '<Root>/Transition to 1ms'
  int8_T Transitionto1ms_RDBuf;        // '<Root>/Transition to 1ms'
  boolean_T Unwrap_FirstStep;          // '<S7>/Unwrap'
  MdlrefDW_Calibrator_T Model_InstanceData;// '<Root>/Model'
  MdlrefDW_control_foc_T FOC_InstanceData;// '<Root>/FOC'
  MdlrefDW_estimation_velocity_T MotorVelocityEstimator_InstanceData;// '<S1>/Motor Velocity Estimator' 
  MdlrefDW_filter_current_T CurrentFilter_InstanceData;// '<S1>/Current Filter'
  MdlrefDW_estimation_velocity_T JointVelocityEstimator_InstanceData;// '<S1>/Joint Velocity Estimator' 
  MdlrefDW_supervisor_T MotorSupervisor_InstanceData;// '<Root>/Motor Supervisor' 
  MdlrefDW_position_velocity_cascade_T Positionvelocitycascade_InstanceData;// '<Root>/Position velocity cascade' 
};

// Zero-crossing (trigger) state for model 'motion_controller'
struct ZCE_motion_controller_T {
  ZCSigState EnabledSubsystem_Trig_ZCE;// '<S3>/Enabled Subsystem'
};

struct MdlrefDW_motion_controller_T {
  B_motion_controller_c_T rtb;
  DW_motion_controller_f_T rtdw;
  ZCE_motion_controller_T rtzce;
};

// Model reference registration function
extern void motion_controller_initialize(DW_motion_controller_f_T *localDW,
  ZCE_motion_controller_T *localZCE);
extern void motion_controller_Init(Flags *rty_Flags, ActuatorConfiguration
  *rty_ActuatorsConfiguration, B_motion_controller_c_T *localB,
  DW_motion_controller_f_T *localDW);
extern void motion_controller_Enable(DW_motion_controller_f_T *localDW);
extern void motion_controller_Disable(DW_motion_controller_f_T *localDW);
extern void motion_controllerTID0(void);
extern void motion_controllerTID1(const SensorsData *rtu_SensorData, FOCOutputs *
  rty_FOCOutputs, B_motion_controller_c_T *localB, DW_motion_controller_f_T
  *localDW, ZCE_motion_controller_T *localZCE);
extern void mc_step_1ms(const ExternalFlags *rtu_ExternalFlags, const
  ReceivedEvents rtu_Events[4], const ActuatorConfiguration *rtu_InitConf, const
  JointData *rtu_JointData, EstimatedData *rty_EstimatedData, Flags *rty_Flags,
  ActuatorConfiguration *rty_ActuatorsConfiguration, B_motion_controller_c_T
  *localB, DW_motion_controller_f_T *localDW);
extern void motion_controller_Term(DW_motion_controller_f_T *localDW);

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
//  '<Root>' : 'motion_controller'
//  '<S1>'   : 'motion_controller/Estimation'
//  '<S2>'   : 'motion_controller/Global configuration'
//  '<S3>'   : 'motion_controller/Process Sensors'
//  '<S4>'   : 'motion_controller/Estimation/Thermal model'
//  '<S5>'   : 'motion_controller/Estimation/Thermal model/Thermal model OFF'
//  '<S6>'   : 'motion_controller/Process Sensors/Detect Rise Positive'
//  '<S7>'   : 'motion_controller/Process Sensors/Enabled Subsystem'
//  '<S8>'   : 'motion_controller/Process Sensors/Detect Rise Positive/Positive'
//  '<S9>'   : 'motion_controller/Process Sensors/Enabled Subsystem/Degrees to Radians'
//  '<S10>'  : 'motion_controller/Process Sensors/Enabled Subsystem/Radians to Degrees'

#endif                                 // motion_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
