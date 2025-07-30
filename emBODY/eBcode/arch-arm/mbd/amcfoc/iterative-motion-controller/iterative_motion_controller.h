//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: iterative_motion_controller.h
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
#ifndef iterative_motion_controller_h_
#define iterative_motion_controller_h_
#include "rtwtypes.h"
#include "iterative_motion_controller_types.h"
#include "Calibrator.h"
#include "SupervisorFSM_TX.h"
#include "control_foc.h"
#include "motion_controller.h"
#include "process_sensors.h"
#include "zero_crossing_types.h"

// Includes for objects with custom storage classes
#include "rtw_defines.h"

// Block signals and states (default storage) for system '<Root>/Iterative Motion Controller' 
struct DW_CoreSubsys_iterative_motion_controller_T {
  MdlrefDW_Calibrator_T Calibrator_InstanceData;// '<S1>/Calibrator'
  MdlrefDW_SupervisorFSM_TX_T Model_InstanceData;// '<S1>/Model'
  MdlrefDW_control_foc_T FOC_InstanceData;// '<S1>/FOC'
  MdlrefDW_motion_controller_T MotionController_InstanceData;// '<S1>/Motion Controller' 
  MdlrefDW_process_sensors_T process_sensors_InstanceData;// '<S1>/process_sensors' 
  FOCSlowInputs RateTransition1_Buf[3];// '<S1>/Rate Transition1'
  ActuatorConfiguration RateTransition5_Buf[3];// '<S1>/Rate Transition5'
  ActuatorConfiguration RateTransition3_Buf[3];// '<S1>/Rate Transition3'
  FOCSlowInputs Calibrator_o3;         // '<S1>/Calibrator'
  FOCSlowInputs MotionController_o4;   // '<S1>/Motion Controller'
  ActuatorConfiguration ConfigurationParameters;// '<S1>/Motion Controller'
  BUS_MESSAGES_TX MessagesTx;          // '<S1>/Model'
  SensorsData Calibrator_o2;           // '<S1>/Calibrator'
  SensorsData Transitionto1ms;         // '<S1>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf0;    // '<S1>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf1;    // '<S1>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf2;    // '<S1>/Transition to 1ms'
  FOCOutputs FOC;                      // '<S1>/FOC'
  FOCOutputs RateTransition2;          // '<S1>/Rate Transition2'
  Flags RateTransition4_Buf[3];        // '<S1>/Rate Transition4'
  FOCOutputs RateTransition2_Buf0;     // '<S1>/Rate Transition2'
  FOCOutputs RateTransition2_Buf1;     // '<S1>/Rate Transition2'
  FOCOutputs RateTransition2_Buf2;     // '<S1>/Rate Transition2'
  Flags Flags_p;                       // '<S1>/Motion Controller'
  EstimatedData MotionController_o1;   // '<S1>/Motion Controller'
  BUS_STATUS_TX Model_o2;              // '<S1>/Model'
  real32_T TmpRTBAtMotionControllerInport7;
  void* RateTransition4_SEMAPHORE;     // '<S1>/Rate Transition4'
  void* RateTransition1_SEMAPHORE;     // '<S1>/Rate Transition1'
  void* RateTransition5_SEMAPHORE;     // '<S1>/Rate Transition5'
  void* RateTransition3_SEMAPHORE;     // '<S1>/Rate Transition3'
  void* RateTransition2_SEMAPHORE;     // '<S1>/Rate Transition2'
  void* Transitionto1ms_SEMAPHORE;     // '<S1>/Transition to 1ms'
  int8_T RateTransition4_LstBufWR;     // '<S1>/Rate Transition4'
  int8_T RateTransition4_RDBuf;        // '<S1>/Rate Transition4'
  int8_T RateTransition1_LstBufWR;     // '<S1>/Rate Transition1'
  int8_T RateTransition1_RDBuf;        // '<S1>/Rate Transition1'
  int8_T RateTransition5_LstBufWR;     // '<S1>/Rate Transition5'
  int8_T RateTransition5_RDBuf;        // '<S1>/Rate Transition5'
  int8_T RateTransition3_LstBufWR;     // '<S1>/Rate Transition3'
  int8_T RateTransition3_RDBuf;        // '<S1>/Rate Transition3'
  int8_T RateTransition2_LstBufWR;     // '<S1>/Rate Transition2'
  int8_T RateTransition2_RDBuf;        // '<S1>/Rate Transition2'
  int8_T Transitionto1ms_LstBufWR;     // '<S1>/Transition to 1ms'
  int8_T Transitionto1ms_RDBuf;        // '<S1>/Transition to 1ms'
  boolean_T areLimitsSet;              // '<S1>/Motion Controller'
  boolean_T UnitDelay_DSTATE;          // '<S1>/Unit Delay'
  volatile boolean_T TmpRTBAtFOCInport4_Buffer0;// synthesized block
};

// Block signals and states (default storage) for system '<Root>'
struct DW_iterative_motion_controller_T {
  DW_CoreSubsys_iterative_motion_controller_T CoreSubsys[2];// '<Root>/Iterative Motion Controller' 
};

// External inputs (root inport signals with default storage)
struct ExtU_iterative_motion_controller_T {
  SensorsData SensorData[2];           // '<Root>/SensorData'
  ExternalFlags ExternalFlags_j;       // '<Root>/ExternalFlags'
  ReceivedEvents EventsList[8];        // '<Root>/EventsList'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_iterative_motion_controller_T {
  FOCOutputs FOCOutputs_h[2];          // '<Root>/FOCOutputs'
  EstimatedData Estimates[2];          // '<Root>/Estimates'
  Flags Flags_d[2];                    // '<Root>/Flags'
  ActuatorConfiguration ConfigurationParameters[2];// '<Root>/ConfigurationParameters' 
  BUS_MESSAGES_TX Messages[2];         // '<Root>/Messages'
  BUS_STATUS_TX MessagesFlags[2];      // '<Root>/MessagesFlags'
};

// Real-time Model Data Structure
struct tag_RTM_iterative_motion_controller_T {
  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint32_T TID[3];
      uint32_T cLimit[3];
    } TaskCounters;
  } Timing;

  boolean_T StepTask(int32_T idx) const;
  uint32_T &CounterLimit(int32_T idx);
  uint32_T &TaskCounter(int32_T idx);
};

// Block signals and states (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct DW_iterative_motion_controller_T iterative_motion_controller_DW;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_iterative_motion_controller_T iterative_motion_controller_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_iterative_motion_controller_T iterative_motion_controller_Y;

#ifdef __cplusplus

}

#endif

// External data declarations for dependent source files
extern const JointData iterative_motion_controller_rtZJointData;// JointData ground 

//
//  Exported Global Parameters
//
//  Note: Exported global parameters are tunable parameters with an exported
//  global storage class designation.  Code generation will declare the memory for
//  these parameters and exports their symbols.
//

extern ActuatorConfiguration AmcfocInitConf[2];// Variable: AmcfocInitConf
                                                  //  Referenced by: '<Root>/Constant'


#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void AMCFOC_initialize(void);
  extern void AMCFOC_step_Time_base(void);// Sample time: [5e-06s, 0.0s]
  extern void AMCFOC_step_FOC(void);   // Sample time: [4.5e-05s, 0.0s]
  extern void AMCFOC_step_Time_1ms(void);// Sample time: [0.001s, 0.0s]
  extern void AMCFOC_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_iterative_motion_controller_T *const
    iterative_motion_controller_M;

#ifdef __cplusplus

}

#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'iterative_motion_controller'
//  '<S1>'   : 'iterative_motion_controller/Iterative Motion Controller'
//  '<S2>'   : 'iterative_motion_controller/Sort Events'

#endif                                 // iterative_motion_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
