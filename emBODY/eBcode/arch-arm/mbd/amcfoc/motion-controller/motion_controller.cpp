//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: motion_controller.cpp
//
// Code generated for Simulink model 'motion_controller'.
//
// Model version                  : 5.114
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Mon Jul 14 09:23:00 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller.h"
#include "motion_controller_types.h"
#include "rtw_mutex.h"
#include "rtwtypes.h"
#include <cmath>
#include "motion_controller_private.h"
#include "control_foc.h"
#include "estimation_velocity.h"
#include "filter_current.h"
#include "supervisor.h"
#include "position_velocity_cascade.h"
#include "Calibrator.h"

// System initialize for referenced model: 'motion_controller'
void motion_controller_Init(Flags *rty_Flags, ActuatorConfiguration
  *rty_ActuatorsConfiguration, B_motion_controller_c_T *localB,
  DW_motion_controller_f_T *localDW)
{
  // Start for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition1'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition3'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/FOC'
  rtw_mutex_init();

  // Start for RateTransition: '<Root>/Rate Transition2'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Bus Creator'
  rtw_mutex_init();

  // Start for RateTransition: '<Root>/Transition to 1ms'
  rtw_mutex_init();

  // SystemInitialize for ModelReference generated from: '<Root>/Calibrator'
  Calibrator_Init();

  // SystemInitialize for ModelReference: '<S1>/Current Filter'
  filter_current_Init(&(localDW->CurrentFilter_InstanceData.rtdw));

  // SystemInitialize for ModelReference: '<S1>/Joint Velocity Estimator'
  estimation_velocity_Init(&(localDW->JointVelocityEstimator_InstanceData.rtdw));

  // SystemInitialize for ModelReference: '<S1>/Motor Velocity Estimator'
  estimation_velocity_Init(&(localDW->MotorVelocityEstimator_InstanceData.rtdw));

  // SystemInitialize for ModelReference: '<Root>/FOC'
  control_foc_Init(&(localDW->FOC_InstanceData.rtdw));

  // SystemInitialize for ModelReference generated from: '<Root>/Motor Supervisor' 
  supervisor_Init(&localB->targets, rty_ActuatorsConfiguration, rty_Flags,
                  &(localDW->MotorSupervisor_InstanceData.rtdw));

  // SystemInitialize for ModelReference generated from: '<Root>/Position velocity cascade' 
  position_velocity_cascade_Init
    (&(localDW->Positionvelocitycascade_InstanceData.rtdw));
}

// Enable for referenced model: 'motion_controller'
void motion_controller_Enable(DW_motion_controller_f_T *localDW)
{
  // Enable for ModelReference generated from: '<Root>/Position velocity cascade' 
  position_velocity_cascade_Enable
    (&(localDW->Positionvelocitycascade_InstanceData.rtdw));
}

// Disable for referenced model: 'motion_controller'
void motion_controller_Disable(DW_motion_controller_f_T *localDW)
{
  // Disable for ModelReference generated from: '<Root>/Position velocity cascade' 
  position_velocity_cascade_Disable
    (&(localDW->Positionvelocitycascade_InstanceData.rtb),
     &(localDW->Positionvelocitycascade_InstanceData.rtdw));
}

// Output and update for referenced model: 'motion_controller'
void motion_controllerTID0(B_motion_controller_c_T *localB,
  DW_motion_controller_f_T *localDW)
{
  // local block i/o variables
  real32_T rtb_Iabc[3];
  int8_T wrBufIdx;

  // ModelReference generated from: '<Root>/Calibrator'
  CalibratorTID0(&localB->Vcc, &localB->offset, &localB->rotor_angle,
                 &localB->counter, &localB->Idx_counter, &rtb_Iabc[0],
                 &localB->electrical_angle, &localB->temperature,
                 &localB->voltage, &localB->current, &localB->hallABC,
                 &(localDW->Calibrator_InstanceData.rtdw));

  // RateTransition generated from: '<Root>/Calibrator'
  localB->ConfigurationParameters = localDW->ConfigurationParameters_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport19 =
    localDW->TmpRTBAtCalibratorInport19_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport2 = localDW->TmpRTBAtCalibratorInport2_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport20 =
    localDW->TmpRTBAtCalibratorInport20_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport21 =
    localDW->TmpRTBAtCalibratorInport21_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport22 =
    localDW->TmpRTBAtCalibratorInport22_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  localDW->TmpRTBAtCalibratorInport23_RDBuf =
    localDW->TmpRTBAtCalibratorInport23_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport23 = localDW->
    TmpRTBAtCalibratorInport23_Buf[localDW->TmpRTBAtCalibratorInport23_RDBuf];

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport24 =
    localDW->TmpRTBAtCalibratorInport24_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport25 =
    localDW->TmpRTBAtCalibratorInport25_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport26 =
    localDW->TmpRTBAtCalibratorInport26_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport27 =
    localDW->TmpRTBAtCalibratorInport27_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport28 =
    localDW->TmpRTBAtCalibratorInport28_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport29 =
    localDW->TmpRTBAtCalibratorInport29_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport3 = localDW->TmpRTBAtCalibratorInport3_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport30 =
    localDW->TmpRTBAtCalibratorInport30_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport31 =
    localDW->TmpRTBAtCalibratorInport31_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport32 =
    localDW->TmpRTBAtCalibratorInport32_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  localDW->TmpRTBAtCalibratorInport33_RDBuf =
    localDW->TmpRTBAtCalibratorInport33_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport33 = localDW->
    TmpRTBAtCalibratorInport33_Buf[localDW->TmpRTBAtCalibratorInport33_RDBuf];

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport34 =
    localDW->TmpRTBAtCalibratorInport34_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport35 =
    localDW->TmpRTBAtCalibratorInport35_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport36 =
    localDW->TmpRTBAtCalibratorInport36_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport37 =
    localDW->TmpRTBAtCalibratorInport37_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport38 =
    localDW->TmpRTBAtCalibratorInport38_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport39 =
    localDW->TmpRTBAtCalibratorInport39_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport4 = localDW->TmpRTBAtCalibratorInport4_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport40 =
    localDW->TmpRTBAtCalibratorInport40_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport41 =
    localDW->TmpRTBAtCalibratorInport41_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport42 =
    localDW->TmpRTBAtCalibratorInport42_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  localDW->TmpRTBAtCalibratorInport43_RDBuf =
    localDW->TmpRTBAtCalibratorInport43_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport43 = localDW->
    TmpRTBAtCalibratorInport43_Buf[localDW->TmpRTBAtCalibratorInport43_RDBuf];

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport44 =
    localDW->TmpRTBAtCalibratorInport44_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport45 =
    localDW->TmpRTBAtCalibratorInport45_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport46 =
    localDW->TmpRTBAtCalibratorInport46_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport47 =
    localDW->TmpRTBAtCalibratorInport47_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport48 =
    localDW->TmpRTBAtCalibratorInport48_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport49 =
    localDW->TmpRTBAtCalibratorInport49_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  localDW->TmpRTBAtCalibratorInport5_RDBuf =
    localDW->TmpRTBAtCalibratorInport5_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport5 = localDW->
    TmpRTBAtCalibratorInport5_Buf[localDW->TmpRTBAtCalibratorInport5_RDBuf];

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport50 =
    localDW->TmpRTBAtCalibratorInport50_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport51 =
    localDW->TmpRTBAtCalibratorInport51_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport52 =
    localDW->TmpRTBAtCalibratorInport52_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport53 =
    localDW->TmpRTBAtCalibratorInport53_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport54 =
    localDW->TmpRTBAtCalibratorInport54_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport55 =
    localDW->TmpRTBAtCalibratorInport55_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport56 =
    localDW->TmpRTBAtCalibratorInport56_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport57 =
    localDW->TmpRTBAtCalibratorInport57_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport58 =
    localDW->TmpRTBAtCalibratorInport58_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport59 =
    localDW->TmpRTBAtCalibratorInport59_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport60 =
    localDW->TmpRTBAtCalibratorInport60_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport61 =
    localDW->TmpRTBAtCalibratorInport61_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport62 =
    localDW->TmpRTBAtCalibratorInport62_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport63 =
    localDW->TmpRTBAtCalibratorInport63_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport64 =
    localDW->TmpRTBAtCalibratorInport64_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport65 =
    localDW->TmpRTBAtCalibratorInport65_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport66 =
    localDW->TmpRTBAtCalibratorInport66_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport67 =
    localDW->TmpRTBAtCalibratorInport67_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport68 =
    localDW->TmpRTBAtCalibratorInport68_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport69 =
    localDW->TmpRTBAtCalibratorInport69_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport70 =
    localDW->TmpRTBAtCalibratorInport70_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport71 =
    localDW->TmpRTBAtCalibratorInport71_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport72 =
    localDW->TmpRTBAtCalibratorInport72_Buffer0;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  localDW->TmpRTBAtCalibratorInport73_RDBuf =
    localDW->TmpRTBAtCalibratorInport73_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport73 = localDW->
    TmpRTBAtCalibratorInport73_Buf[localDW->TmpRTBAtCalibratorInport73_RDBuf];

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition1_6_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition1_6_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  switch (wrBufIdx) {
   case 0:
    localDW->RateTransition1_6_Buf0[0] = rtb_Iabc[0];
    localDW->RateTransition1_6_Buf0[1] = rtb_Iabc[1];
    localDW->RateTransition1_6_Buf0[2] = rtb_Iabc[2];
    break;

   case 1:
    localDW->RateTransition1_6_Buf1[0] = rtb_Iabc[0];
    localDW->RateTransition1_6_Buf1[1] = rtb_Iabc[1];
    localDW->RateTransition1_6_Buf1[2] = rtb_Iabc[2];
    break;

   case 2:
    localDW->RateTransition1_6_Buf2[0] = rtb_Iabc[0];
    localDW->RateTransition1_6_Buf2[1] = rtb_Iabc[1];
    localDW->RateTransition1_6_Buf2[2] = rtb_Iabc[2];
    break;
  }

  localDW->RateTransition1_6_LstBufWR = wrBufIdx;

  // End of RateTransition generated from: '<Root>/Rate Transition1'

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition3_6_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition3_6_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  switch (wrBufIdx) {
   case 0:
    localDW->RateTransition3_6_Buf0[0] = rtb_Iabc[0];
    localDW->RateTransition3_6_Buf0[1] = rtb_Iabc[1];
    localDW->RateTransition3_6_Buf0[2] = rtb_Iabc[2];
    break;

   case 1:
    localDW->RateTransition3_6_Buf1[0] = rtb_Iabc[0];
    localDW->RateTransition3_6_Buf1[1] = rtb_Iabc[1];
    localDW->RateTransition3_6_Buf1[2] = rtb_Iabc[2];
    break;

   case 2:
    localDW->RateTransition3_6_Buf2[0] = rtb_Iabc[0];
    localDW->RateTransition3_6_Buf2[1] = rtb_Iabc[1];
    localDW->RateTransition3_6_Buf2[2] = rtb_Iabc[2];
    break;
  }

  localDW->RateTransition3_6_LstBufWR = wrBufIdx;

  // End of RateTransition generated from: '<Root>/Rate Transition3'
}

// Output and update for referenced model: 'motion_controller'
void motion_controllerTID1(FOCOutputs *rty_FOCOutputs, B_motion_controller_c_T
  *localB, DW_motion_controller_f_T *localDW)
{
  SensorsData rtb_TmpRTBAtFOCInport1;
  real32_T rtb_D0;
  real32_T rtb_I0;
  real32_T rtb_N;
  real32_T rtb_current_rms_lambda;
  real32_T rtb_environment_temperature;
  real32_T rtb_hall_sensors_offset;
  real32_T rtb_motorCriticalTemperature;
  real32_T rtb_motorOverloadCurrents;
  real32_T rtb_motorPeakCurrents;
  real32_T rtb_thermal_time_constant;
  uint32_T rtb_velocity_est_window;
  int16_T rtb_rotor_encoder_resolution;
  int16_T rtb_rotor_index_offset;
  int8_T wrBufIdx;
  uint8_T rtb_pole_pairs;
  uint8_T rtb_shift_factor;
  boolean_T rtb_enable_verbosity;
  boolean_T rtb_has_hall_sens;
  boolean_T rtb_has_quadrature_encoder;
  boolean_T rtb_has_speed_quadrature_encoder;
  boolean_T rtb_has_temperature_sens;
  boolean_T rtb_use_index;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_1_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_2_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  localDW->RateTransition_3_RDBuf = localDW->RateTransition_3_LstBufWR;
  rtw_mutex_unlock();
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.global_configuration.estimation.velocity_est_mode
    = localDW->RateTransition_3_Buf[localDW->RateTransition_3_RDBuf];

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_velocity_est_window = localDW->RateTransition_4_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.global_configuration.estimation.environment_temperature
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.global_configuration.estimation.current_rms_lambda
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.global_configuration.estimation.velocity_est_window
    = rtb_velocity_est_window;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_5_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_6_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_7_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_8_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_velocity_est_window = localDW->RateTransition_9_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorCriticalTemperature = localDW->RateTransition_10_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.thresholds.jntVelMax
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.thresholds.motorNominalCurrents
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.thresholds.motorPeakCurrents
    = rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.thresholds.motorOverloadCurrents
    = rtb_motorOverloadCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.thresholds.motorPwmLimit
    = rtb_velocity_est_window;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.thresholds.motorCriticalTemperature
    = rtb_motorCriticalTemperature;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  localDW->RateTransition_11_RDBuf = localDW->RateTransition_11_LstBufWR;
  rtw_mutex_unlock();
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.type
    = localDW->RateTransition_11_Buf[localDW->RateTransition_11_RDBuf];

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_12_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_13_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_14_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_15_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorCriticalTemperature = localDW->RateTransition_16_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_N = localDW->RateTransition_17_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_I0 = localDW->RateTransition_18_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_D0 = localDW->RateTransition_19_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_shift_factor = localDW->RateTransition_20_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.OutMax
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.OutMin
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.P
    = rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.I
    = rtb_motorOverloadCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.D
    = rtb_motorCriticalTemperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.N
    = rtb_N;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.I0
    = rtb_I0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.D0
    = rtb_D0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.currentPID.shift_factor
    = rtb_shift_factor;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  localDW->RateTransition_21_RDBuf = localDW->RateTransition_21_LstBufWR;
  rtw_mutex_unlock();
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.type
    = localDW->RateTransition_21_Buf[localDW->RateTransition_21_RDBuf];

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_22_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_23_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_24_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_25_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorCriticalTemperature = localDW->RateTransition_26_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_N = localDW->RateTransition_27_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_I0 = localDW->RateTransition_28_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_D0 = localDW->RateTransition_29_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_shift_factor = localDW->RateTransition_30_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.OutMax
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.OutMin
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.P
    = rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.I
    = rtb_motorOverloadCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.D
    = rtb_motorCriticalTemperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.N
    = rtb_N;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.I0
    = rtb_I0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.D0
    = rtb_D0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.velocityPID.shift_factor
    = rtb_shift_factor;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  localDW->RateTransition_31_RDBuf = localDW->RateTransition_31_LstBufWR;
  rtw_mutex_unlock();
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.type
    = localDW->RateTransition_31_Buf[localDW->RateTransition_31_RDBuf];

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_32_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_33_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_34_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_35_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorCriticalTemperature = localDW->RateTransition_36_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_N = localDW->RateTransition_37_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_I0 = localDW->RateTransition_38_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_D0 = localDW->RateTransition_39_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_shift_factor = localDW->RateTransition_40_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.OutMax
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.OutMin
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.P
    = rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.I
    = rtb_motorOverloadCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.D
    = rtb_motorCriticalTemperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.N
    = rtb_N;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.I0
    = rtb_I0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.D0
    = rtb_D0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.pids.positionPID.shift_factor
    = rtb_shift_factor;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_enable_verbosity = localDW->RateTransition_41_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_hall_sens = localDW->RateTransition_42_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_quadrature_encoder = localDW->RateTransition_43_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_speed_quadrature_encoder = localDW->RateTransition_44_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_temperature_sens = localDW->RateTransition_45_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_shift_factor = localDW->RateTransition_46_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_pole_pairs = localDW->RateTransition_47_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_rotor_encoder_resolution = localDW->RateTransition_48_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_rotor_index_offset = localDW->RateTransition_49_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_use_index = localDW->RateTransition_50_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.enable_verbosity
    = rtb_enable_verbosity;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.has_hall_sens
    = rtb_has_hall_sens;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.has_quadrature_encoder
    = rtb_has_quadrature_encoder;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.has_speed_quadrature_encoder
    = rtb_has_speed_quadrature_encoder;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.has_temperature_sens
    = rtb_has_temperature_sens;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.encoder_tolerance
    = rtb_shift_factor;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.pole_pairs
    = rtb_pole_pairs;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.rotor_encoder_resolution
    = rtb_rotor_encoder_resolution;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.rotor_index_offset
    = rtb_rotor_index_offset;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.externals.use_index
    = rtb_use_index;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_51_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_52_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_53_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_54_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorCriticalTemperature = localDW->RateTransition_55_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_N = localDW->RateTransition_56_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_I0 = localDW->RateTransition_57_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_D0 = localDW->RateTransition_58_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_thermal_time_constant = localDW->RateTransition_59_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_hall_sensors_offset = localDW->RateTransition_60_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  localDW->RateTransition_61_RDBuf = localDW->RateTransition_61_LstBufWR;
  rtw_mutex_unlock();
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.reference_encoder
    = localDW->RateTransition_61_Buf[localDW->RateTransition_61_RDBuf];

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.Kbemf
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.Rphase
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.Imin
    = rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.Imax
    = rtb_motorOverloadCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.Vmax
    = rtb_motorCriticalTemperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.resistance
    = rtb_N;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.inductance
    = rtb_I0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.thermal_resistance
    = rtb_D0;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.thermal_time_constant
    = rtb_thermal_time_constant;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.actuator_configuration.motor.hall_sensors_offset
    = rtb_hall_sensors_offset;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_62_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_63_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_64_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_65_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.estimated_data.rotor_velocity
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.estimated_data.Iq_filtered
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.estimated_data.motor_temperature
    = rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.estimated_data.joint_velocity
    = rtb_motorOverloadCurrents;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_66_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_67_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorPeakCurrents = localDW->RateTransition_68_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_motorOverloadCurrents = localDW->RateTransition_69_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.targets.position
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.targets.velocity
    = rtb_current_rms_lambda;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.targets.current =
    rtb_motorPeakCurrents;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.targets.voltage =
    rtb_motorOverloadCurrents;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_enable_verbosity = localDW->RateTransition_70_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_hall_sens = localDW->RateTransition_71_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_quadrature_encoder = localDW->RateTransition_72_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_has_speed_quadrature_encoder = localDW->RateTransition_73_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_environment_temperature = localDW->RateTransition_74_Buffer0;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtb_current_rms_lambda = localDW->RateTransition_75_Buffer0;

  // BusCreator generated from: '<Root>/FOC'
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.control_outer_outputs.vel_en
    = rtb_enable_verbosity;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.control_outer_outputs.cur_en
    = rtb_has_hall_sens;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.control_outer_outputs.out_en
    = rtb_has_quadrature_encoder;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.control_outer_outputs.pid_reset
    = rtb_has_speed_quadrature_encoder;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.control_outer_outputs.motorcurrent
    = rtb_environment_temperature;
  localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1.control_outer_outputs.current_limiter
    = rtb_current_rms_lambda;

  // RateTransition generated from: '<Root>/FOC'
  rtw_mutex_lock();
  localDW->TmpRTBAtFOCInport1_RDBuf = localDW->TmpRTBAtFOCInport1_LstBufWR;
  rtw_mutex_unlock();
  rtb_TmpRTBAtFOCInport1 = localDW->TmpRTBAtFOCInport1_Buf
    [localDW->TmpRTBAtFOCInport1_RDBuf];

  // RateTransition generated from: '<Root>/FOC'
  rtb_enable_verbosity = localDW->finish_Buffer0;

  // ModelReference: '<Root>/FOC'
  control_foc(&rtb_TmpRTBAtFOCInport1,
              &localB->BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1,
              &rtb_enable_verbosity, rty_FOCOutputs,
              &(localDW->FOC_InstanceData.rtb), &(localDW->FOC_InstanceData.rtdw),
              &(localDW->FOC_InstanceData.rtzce));

  // RateTransition: '<Root>/Rate Transition2'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition2_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition2_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  switch (wrBufIdx) {
   case 0:
    localDW->RateTransition2_Buf0 = *rty_FOCOutputs;
    break;

   case 1:
    localDW->RateTransition2_Buf1 = *rty_FOCOutputs;
    break;

   case 2:
    localDW->RateTransition2_Buf2 = *rty_FOCOutputs;
    break;
  }

  localDW->RateTransition2_LstBufWR = wrBufIdx;

  // End of RateTransition: '<Root>/Rate Transition2'
}

// Output and update for referenced model: 'motion_controller'
void motion_controllerTID2(const SensorsData *rtu_SensorData,
  B_motion_controller_c_T *localB, DW_motion_controller_f_T *localDW)
{
  // local block i/o variables
  FOCSlowInputs rtb_TmpRTBAtBusCreatorOutport1;
  SensorsData rtb_Switch;
  SensorsData rtb_BusAssignment;
  int32_T rtb_Product;
  real32_T rtb_Add;
  int16_T rtb_ConfigurationParameters;
  uint16_T rtb_Sum3;
  int8_T wrBufIdx;
  uint8_T rtb_ConfigurationParameters_l;
  boolean_T rtb_use_index;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  localDW->Flags_RDBuf = localDW->Flags_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Calibrator'
  localB->Flags_k = localDW->Flags_Buf[localDW->Flags_RDBuf];

  // DataTypeConversion: '<S3>/Data Type Conversion'
  rtb_Add = std::abs(rtu_SensorData->motorsensors.qencoder.counter);

  // BusAssignment: '<S3>/Bus Assignment'
  rtb_BusAssignment = *rtu_SensorData;

  // DataTypeConversion: '<S3>/Data Type Conversion'
  if (rtb_Add < 8.388608E+6F) {
    if (rtb_Add >= 0.5F) {
      rtb_Add = std::floor(rtu_SensorData->motorsensors.qencoder.counter + 0.5F);
    } else {
      rtb_Add = 0.0F;
    }
  } else {
    rtb_Add = rtu_SensorData->motorsensors.qencoder.counter;
  }

  // Outputs for IfAction SubSystem: '<S7>/PositionNoReset' incorporates:
  //   ActionPort: '<S17>/Action Port'

  // If: '<S7>/If1' incorporates:
  //   Constant: '<S22>/Constant'
  //   DataTypeConversion: '<S3>/Data Type Conversion'
  //   DataTypeConversion: '<S3>/Data Type Conversion1'
  //   MinMax: '<S17>/MinMax'
  //   Sum: '<S17>/Sum3'
  //   Sum: '<S17>/Sum7'

  rtb_Sum3 = static_cast<uint16_T>(static_cast<uint16_T>(rtb_Add) - static_cast<
    uint16_T>(rtu_SensorData->motorsensors.qencoder.Idx_counter));
  if (rtb_Sum3 <= static_cast<uint16_T>(rtb_Sum3 + 360)) {
    // Product: '<S7>/Product'
    rtb_Product = rtb_Sum3;
  } else {
    // Product: '<S7>/Product'
    rtb_Product = static_cast<uint16_T>(rtb_Sum3 + 360);
  }

  // End of Outputs for SubSystem: '<S7>/PositionNoReset'

  // RateTransition generated from: '<S9>/Switch'
  rtb_ConfigurationParameters = localDW->ConfigurationParameters_Buffer0_a;

  // RateTransition generated from: '<S15>/Product'
  rtb_ConfigurationParameters_l = localDW->ConfigurationParameters_Buffer0_o;

  // If: '<S10>/If' incorporates:
  //   Constant: '<S12>/Constant'
  //   Product: '<S15>/Product'
  //   Sum: '<S12>/Add'
  //   Sum: '<S13>/Add'
  //   Switch: '<S9>/Switch'

  if (rtb_Product <= rtb_ConfigurationParameters) {
    // Outputs for IfAction SubSystem: '<S10>/If Action Subsystem' incorporates:
    //   ActionPort: '<S12>/Action Port'

    rtb_Add = (static_cast<real32_T>(rtb_Product) + 360.0F) -
      static_cast<real32_T>(rtb_ConfigurationParameters);

    // End of Outputs for SubSystem: '<S10>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S13>/Action Port'

    rtb_Add = static_cast<real32_T>(rtb_Product) - static_cast<real32_T>
      (rtb_ConfigurationParameters);

    // End of Outputs for SubSystem: '<S10>/If Action Subsystem1'
  }

  rtb_Add *= static_cast<real32_T>(rtb_ConfigurationParameters_l);

  // End of If: '<S10>/If'

  // Outputs for IfAction SubSystem: '<S7>/PositionNoReset' incorporates:
  //   ActionPort: '<S17>/Action Port'

  // If: '<S7>/If1' incorporates:
  //   Constant: '<S22>/Constant'
  //   MinMax: '<S17>/MinMax'
  //   Sum: '<S17>/Sum7'

  if (rtb_Sum3 <= static_cast<uint16_T>(rtb_Sum3 + 360)) {
    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S20>/DTC'

    rtb_BusAssignment.motorsensors.qencoder.rotor_angle = rtb_Sum3;
  } else {
    // BusAssignment: '<S3>/Bus Assignment' incorporates:
    //   DataTypeConversion: '<S20>/DTC'

    rtb_BusAssignment.motorsensors.qencoder.rotor_angle = static_cast<uint16_T>
      (rtb_Sum3 + 360);
  }

  // End of Outputs for SubSystem: '<S7>/PositionNoReset'

  // BusAssignment: '<S3>/Bus Assignment' incorporates:
  //   Gain: '<S11>/Multiply'
  //   Gain: '<S11>/Multiply1'
  //   Rounding: '<S11>/Floor'
  //   Sum: '<S11>/Add'

  rtb_BusAssignment.motorsensors.electrical_angle = rtb_Add - std::floor
    (0.00277777785F * rtb_Add) * 360.0F;

  // RateTransition generated from: '<S3>/Switch'
  rtb_use_index = localDW->ConfigurationParameters_Buffer0_m;

  // Switch: '<S3>/Switch'
  if (rtb_use_index) {
    // Switch: '<S3>/Switch'
    rtb_Switch = rtb_BusAssignment;
  } else {
    // Switch: '<S3>/Switch'
    rtb_Switch = *rtu_SensorData;
  }

  // End of Switch: '<S3>/Switch'

  // RateTransition generated from: '<Root>/Calibrator'
  localB->TmpRTBAtCalibratorInport18 =
    localDW->TmpRTBAtCalibratorInport18_Buffer0;

  // RateTransition generated from: '<Root>/Bus Creator'
  rtw_mutex_lock();
  localDW->TmpRTBAtBusCreatorOutport1_RDBuf =
    localDW->TmpRTBAtBusCreatorOutport1_LstBufWR;
  rtw_mutex_unlock();

  // RateTransition generated from: '<Root>/Bus Creator'
  rtb_TmpRTBAtBusCreatorOutport1 = localDW->
    TmpRTBAtBusCreatorOutport1_Buf[localDW->TmpRTBAtBusCreatorOutport1_RDBuf];

  // ModelReference generated from: '<Root>/Calibrator'
  CalibratorTID1(&localB->Flags_k, &rtb_Switch.driversensors.Vcc,
                 &rtb_Switch.motorsensors.qencoder.offset,
                 &rtb_Switch.motorsensors.qencoder.rotor_angle,
                 &rtb_Switch.motorsensors.qencoder.counter,
                 &rtb_Switch.motorsensors.qencoder.Idx_counter,
                 &rtb_Switch.motorsensors.Iabc[0],
                 &rtb_Switch.motorsensors.electrical_angle,
                 &rtb_Switch.motorsensors.temperature,
                 &rtb_Switch.motorsensors.voltage,
                 &rtb_Switch.motorsensors.current,
                 &rtb_Switch.motorsensors.hallABC,
                 &localB->TmpRTBAtCalibratorInport18,
                 &rtb_TmpRTBAtBusCreatorOutport1.global_configuration.estimation.environment_temperature,
                 &rtb_TmpRTBAtBusCreatorOutport1.global_configuration.estimation.current_rms_lambda,
                 &rtb_TmpRTBAtBusCreatorOutport1.global_configuration.estimation.velocity_est_mode,
                 &rtb_TmpRTBAtBusCreatorOutport1.global_configuration.estimation.velocity_est_window,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.thresholds.jntVelMax,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.thresholds.motorNominalCurrents,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.thresholds.motorPeakCurrents,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.thresholds.motorOverloadCurrents,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.thresholds.motorPwmLimit,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.thresholds.motorCriticalTemperature,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.type,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.OutMax,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.OutMin,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.P,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.I,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.D,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.N,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.I0,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.D0,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.currentPID.shift_factor,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.type,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.OutMax,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.OutMin,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.P,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.I,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.D,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.N,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.I0,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.D0,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.velocityPID.shift_factor,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.type,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.OutMax,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.OutMin,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.P,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.I,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.D,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.N,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.I0,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.D0,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.pids.positionPID.shift_factor,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.enable_verbosity,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.has_hall_sens,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.has_quadrature_encoder,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.has_speed_quadrature_encoder,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.has_temperature_sens,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.encoder_tolerance,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.pole_pairs,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.rotor_encoder_resolution,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.rotor_index_offset,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.externals.use_index,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.Kbemf,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.Rphase,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.Imin,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.Imax,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.Vmax,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.resistance,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.inductance,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.thermal_resistance,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.thermal_time_constant,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.hall_sensors_offset,
                 &rtb_TmpRTBAtBusCreatorOutport1.actuator_configuration.motor.reference_encoder,
                 &rtb_TmpRTBAtBusCreatorOutport1.estimated_data.rotor_velocity,
                 &rtb_TmpRTBAtBusCreatorOutport1.estimated_data.Iq_filtered,
                 &rtb_TmpRTBAtBusCreatorOutport1.estimated_data.motor_temperature,
                 &rtb_TmpRTBAtBusCreatorOutport1.estimated_data.joint_velocity,
                 &rtb_TmpRTBAtBusCreatorOutport1.targets.position,
                 &rtb_TmpRTBAtBusCreatorOutport1.targets.velocity,
                 &rtb_TmpRTBAtBusCreatorOutport1.targets.current,
                 &rtb_TmpRTBAtBusCreatorOutport1.targets.voltage,
                 &rtb_TmpRTBAtBusCreatorOutport1.control_outer_outputs.vel_en,
                 &rtb_TmpRTBAtBusCreatorOutport1.control_outer_outputs.cur_en,
                 &rtb_TmpRTBAtBusCreatorOutport1.control_outer_outputs.out_en,
                 &rtb_TmpRTBAtBusCreatorOutport1.control_outer_outputs.pid_reset,
                 &rtb_TmpRTBAtBusCreatorOutport1.control_outer_outputs.motorcurrent,
                 &rtb_TmpRTBAtBusCreatorOutport1.control_outer_outputs.current_limiter,
                 &localB->finish, &localB->environment_temperature,
                 &localB->current_rms_lambda, &localB->velocity_est_mode,
                 &localB->velocity_est_window, &localB->jntVelMax,
                 &localB->motorNominalCurrents, &localB->motorPeakCurrents,
                 &localB->motorOverloadCurrents, &localB->motorPwmLimit,
                 &localB->motorCriticalTemperature, &localB->type,
                 &localB->OutMax, &localB->OutMin, &localB->P, &localB->I,
                 &localB->D, &localB->N, &localB->I0, &localB->D0,
                 &localB->shift_factor, &localB->type_i, &localB->OutMax_f,
                 &localB->OutMin_p, &localB->P_p, &localB->I_c, &localB->D_p,
                 &localB->N_n, &localB->I0_i, &localB->D0_g,
                 &localB->shift_factor_c, &localB->type_n, &localB->OutMax_n,
                 &localB->OutMin_b, &localB->P_o, &localB->I_p, &localB->D_n,
                 &localB->N_b, &localB->I0_o, &localB->D0_e,
                 &localB->shift_factor_k, &localB->enable_verbosity,
                 &localB->has_hall_sens, &localB->has_quadrature_encoder,
                 &localB->has_speed_quadrature_encoder,
                 &localB->has_temperature_sens, &localB->encoder_tolerance,
                 &localB->pole_pairs, &localB->rotor_encoder_resolution,
                 &localB->rotor_index_offset, &localB->use_index, &localB->Kbemf,
                 &localB->Rphase, &localB->Imin, &localB->Imax, &localB->Vmax,
                 &localB->resistance, &localB->inductance,
                 &localB->thermal_resistance, &localB->thermal_time_constant,
                 &localB->hall_sensors_offset, &localB->reference_encoder,
                 &localB->rotor_velocity, &localB->Iq_filtered,
                 &localB->motor_temperature, &localB->joint_velocity,
                 &localB->position, &localB->velocity, &localB->current_j,
                 &localB->voltage_l, &localB->vel_en, &localB->cur_en,
                 &localB->out_en, &localB->pid_reset, &localB->motorcurrent,
                 &localB->current_limiter,
                 &(localDW->Calibrator_InstanceData.rtb),
                 &(localDW->Calibrator_InstanceData.rtdw));

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_1_Buffer0 = localB->environment_temperature;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_10_Buffer0 = localB->motorCriticalTemperature;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition_11_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition_11_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition_11_Buf[wrBufIdx] = localB->type;
  localDW->RateTransition_11_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_12_Buffer0 = localB->OutMax;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_13_Buffer0 = localB->OutMin;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_14_Buffer0 = localB->P;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_15_Buffer0 = localB->I;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_16_Buffer0 = localB->D;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_17_Buffer0 = localB->N;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_18_Buffer0 = localB->I0;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_19_Buffer0 = localB->D0;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_2_Buffer0 = localB->current_rms_lambda;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_20_Buffer0 = localB->shift_factor;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition_21_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition_21_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition_21_Buf[wrBufIdx] = localB->type_i;
  localDW->RateTransition_21_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_22_Buffer0 = localB->OutMax_f;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_23_Buffer0 = localB->OutMin_p;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_24_Buffer0 = localB->P_p;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_25_Buffer0 = localB->I_c;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_26_Buffer0 = localB->D_p;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_27_Buffer0 = localB->N_n;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_28_Buffer0 = localB->I0_i;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_29_Buffer0 = localB->D0_g;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition_3_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition_3_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition_3_Buf[wrBufIdx] = localB->velocity_est_mode;
  localDW->RateTransition_3_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_30_Buffer0 = localB->shift_factor_c;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition_31_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition_31_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition_31_Buf[wrBufIdx] = localB->type_n;
  localDW->RateTransition_31_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_32_Buffer0 = localB->OutMax_n;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_33_Buffer0 = localB->OutMin_b;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_34_Buffer0 = localB->P_o;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_35_Buffer0 = localB->I_p;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_36_Buffer0 = localB->D_n;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_37_Buffer0 = localB->N_b;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_38_Buffer0 = localB->I0_o;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_39_Buffer0 = localB->D0_e;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_4_Buffer0 = localB->velocity_est_window;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_40_Buffer0 = localB->shift_factor_k;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_41_Buffer0 = localB->enable_verbosity;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_42_Buffer0 = localB->has_hall_sens;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_43_Buffer0 = localB->has_quadrature_encoder;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_44_Buffer0 = localB->has_speed_quadrature_encoder;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_45_Buffer0 = localB->has_temperature_sens;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_46_Buffer0 = localB->encoder_tolerance;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_47_Buffer0 = localB->pole_pairs;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_48_Buffer0 = localB->rotor_encoder_resolution;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_49_Buffer0 = localB->rotor_index_offset;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_5_Buffer0 = localB->jntVelMax;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_50_Buffer0 = localB->use_index;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_51_Buffer0 = localB->Kbemf;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_52_Buffer0 = localB->Rphase;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_53_Buffer0 = localB->Imin;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_54_Buffer0 = localB->Imax;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_55_Buffer0 = localB->Vmax;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_56_Buffer0 = localB->resistance;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_57_Buffer0 = localB->inductance;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_58_Buffer0 = localB->thermal_resistance;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_59_Buffer0 = localB->thermal_time_constant;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_6_Buffer0 = localB->motorNominalCurrents;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_60_Buffer0 = localB->hall_sensors_offset;

  // RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition_61_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition_61_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition_61_Buf[wrBufIdx] = localB->reference_encoder;
  localDW->RateTransition_61_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_62_Buffer0 = localB->rotor_velocity;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_63_Buffer0 = localB->Iq_filtered;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_64_Buffer0 = localB->motor_temperature;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_65_Buffer0 = localB->joint_velocity;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_66_Buffer0 = localB->position;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_67_Buffer0 = localB->velocity;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_68_Buffer0 = localB->current_j;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_69_Buffer0 = localB->voltage_l;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_7_Buffer0 = localB->motorPeakCurrents;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_70_Buffer0 = localB->vel_en;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_71_Buffer0 = localB->cur_en;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_72_Buffer0 = localB->out_en;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_73_Buffer0 = localB->pid_reset;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_74_Buffer0 = localB->motorcurrent;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_75_Buffer0 = localB->current_limiter;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_8_Buffer0 = localB->motorOverloadCurrents;

  // RateTransition generated from: '<Root>/Rate Transition'
  localDW->RateTransition_9_Buffer0 = localB->motorPwmLimit;

  // RateTransition: '<Root>/Transition to 1ms'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->Transitionto1ms_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->Transitionto1ms_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  switch (wrBufIdx) {
   case 0:
    localDW->Transitionto1ms_Buf0 = rtb_Switch;
    break;

   case 1:
    localDW->Transitionto1ms_Buf1 = rtb_Switch;
    break;

   case 2:
    localDW->Transitionto1ms_Buf2 = rtb_Switch;
    break;
  }

  localDW->Transitionto1ms_LstBufWR = wrBufIdx;

  // End of RateTransition: '<Root>/Transition to 1ms'

  // RateTransition generated from: '<Root>/FOC'
  localDW->finish_Buffer0 = localB->finish;
}

// Output and update for referenced model: 'motion_controller'
void mc_step_1ms(const ExternalFlags *rtu_ExternalFlags, const ReceivedEvents
                 rtu_Events[4], const ActuatorConfiguration *rtu_InitConf, const
                 JointData *rtu_JointData, EstimatedData *rty_EstimatedData,
                 Flags *rty_Flags, ActuatorConfiguration
                 *rty_ActuatorsConfiguration, SensorsData *rty_SensorData_out,
                 B_motion_controller_c_T *localB, DW_motion_controller_f_T
                 *localDW)
{
  ControlOuterOutputs rtb_Positionvelocitycascade;
  real32_T rtb_Iabc_h_idx_0;
  real32_T rtb_Iabc_h_idx_1;
  real32_T rtb_Iabc_h_idx_2;
  real32_T rtb_Idx_counter;
  real32_T rtb_Idx_counter_o;
  real32_T rtb_Vcc;
  real32_T rtb_Vcc_a;
  real32_T rtb_counter;
  real32_T rtb_counter_b;
  real32_T rtb_current_h;
  real32_T rtb_electrical_angle;
  real32_T rtb_offset;
  real32_T rtb_rotor_angle;
  real32_T rtb_rotor_angle_i;
  real32_T rtb_temperature;
  real32_T rtb_voltage_c;
  int8_T wrBufIdx;
  uint8_T rtb_hallABC;
  uint8_T rtb_hallABC_h;

  // RateTransition: '<Root>/Transition to 1ms'
  rtw_mutex_lock();
  localDW->Transitionto1ms_RDBuf = localDW->Transitionto1ms_LstBufWR;
  rtw_mutex_unlock();
  switch (localDW->Transitionto1ms_RDBuf) {
   case 0:
    // RateTransition: '<Root>/Transition to 1ms'
    localB->Transitionto1ms = localDW->Transitionto1ms_Buf0;
    break;

   case 1:
    // RateTransition: '<Root>/Transition to 1ms'
    localB->Transitionto1ms = localDW->Transitionto1ms_Buf1;
    break;

   case 2:
    // RateTransition: '<Root>/Transition to 1ms'
    localB->Transitionto1ms = localDW->Transitionto1ms_Buf2;
    break;
  }

  // End of RateTransition: '<Root>/Transition to 1ms'

  // ModelReference: '<S1>/Motor Velocity Estimator' incorporates:
  //   Constant: '<S2>/Velocity Estimation Mode'
  //   Constant: '<S2>/Velocity estimation window'

  estimation_velocity(&motion_controller_ConstP.VelocityEstimationMode_Value,
                      &localB->Transitionto1ms.motorsensors.qencoder.rotor_angle,
                      &rtCP_Velocityestimationwindow_Value, &localB->velocity_b,
                      &(localDW->MotorVelocityEstimator_InstanceData.rtdw));

  // RateTransition: '<Root>/Rate Transition2'
  rtw_mutex_lock();
  localDW->RateTransition2_RDBuf = localDW->RateTransition2_LstBufWR;
  rtw_mutex_unlock();
  switch (localDW->RateTransition2_RDBuf) {
   case 0:
    // RateTransition: '<Root>/Rate Transition2'
    localB->RateTransition2 = localDW->RateTransition2_Buf0;
    break;

   case 1:
    // RateTransition: '<Root>/Rate Transition2'
    localB->RateTransition2 = localDW->RateTransition2_Buf1;
    break;

   case 2:
    // RateTransition: '<Root>/Rate Transition2'
    localB->RateTransition2 = localDW->RateTransition2_Buf2;
    break;
  }

  // End of RateTransition: '<Root>/Rate Transition2'

  // ModelReference: '<S1>/Current Filter'
  filter_current(&localB->RateTransition2, &rty_EstimatedData->Iq_filtered,
                 &(localDW->CurrentFilter_InstanceData.rtdw));

  // ModelReference: '<S1>/Joint Velocity Estimator' incorporates:
  //   Constant: '<S1>/Constant'
  //   Constant: '<S2>/Velocity estimation window'

  estimation_velocity(&motion_controller_ConstP.Constant_Value,
                      &rtu_JointData->position,
                      &rtCP_Velocityestimationwindow_Value, &localB->velocity_j,
                      &(localDW->JointVelocityEstimator_InstanceData.rtdw));

  // BusCreator generated from: '<S1>/Estimation_BusCreator'
  rty_EstimatedData->rotor_velocity = localB->velocity_b;
  rty_EstimatedData->motor_temperature = 0.0F;
  rty_EstimatedData->joint_velocity = localB->velocity_j;

  // ModelReference generated from: '<Root>/Motor Supervisor'
  supervisor(rtu_ExternalFlags, rty_EstimatedData, &localB->RateTransition2,
             &localB->Transitionto1ms, &rtu_Events[0], rtu_InitConf,
             &localB->targets, rty_ActuatorsConfiguration, rty_Flags,
             &(localDW->MotorSupervisor_InstanceData.rtdw));

  // ModelReference generated from: '<Root>/Position velocity cascade'
  position_velocity_cascade(rty_EstimatedData, &localB->targets,
    &rtu_JointData->position, &rty_ActuatorsConfiguration->thresholds.jntVelMax,
    &rty_ActuatorsConfiguration->thresholds.motorNominalCurrents,
    &rty_ActuatorsConfiguration->thresholds.motorPeakCurrents,
    &rty_ActuatorsConfiguration->pids.currentPID.I,
    &rty_ActuatorsConfiguration->pids.velocityPID.P,
    &rty_ActuatorsConfiguration->pids.velocityPID.I,
    &rty_ActuatorsConfiguration->pids.velocityPID.D,
    &rty_ActuatorsConfiguration->pids.velocityPID.N,
    &rty_ActuatorsConfiguration->pids.positionPID.P,
    &rty_ActuatorsConfiguration->pids.positionPID.I,
    &rty_ActuatorsConfiguration->pids.positionPID.D,
    &rty_ActuatorsConfiguration->pids.positionPID.N,
    &rty_ActuatorsConfiguration->motor.reference_encoder,
    &localB->Transitionto1ms.motorsensors.qencoder.rotor_angle,
    &rty_Flags->enable_thermal_protection, &rty_Flags->control_mode,
    &rtb_Positionvelocitycascade,
    &(localDW->Positionvelocitycascade_InstanceData.rtb),
    &(localDW->Positionvelocitycascade_InstanceData.rtdw),
    &(localDW->Positionvelocitycascade_InstanceData.rtzce));

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_Vcc = localB->Vcc;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_offset = localB->offset;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_rotor_angle = localB->rotor_angle;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_counter = localB->counter;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_Idx_counter = localB->Idx_counter;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtw_mutex_lock();
  localDW->RateTransition3_6_RDBuf = localDW->RateTransition3_6_LstBufWR;
  rtw_mutex_unlock();
  switch (localDW->RateTransition3_6_RDBuf) {
   case 0:
    rtb_Iabc_h_idx_0 = localDW->RateTransition3_6_Buf0[0];
    rtb_Iabc_h_idx_1 = localDW->RateTransition3_6_Buf0[1];
    rtb_Iabc_h_idx_2 = localDW->RateTransition3_6_Buf0[2];
    break;

   case 1:
    rtb_Iabc_h_idx_0 = localDW->RateTransition3_6_Buf1[0];
    rtb_Iabc_h_idx_1 = localDW->RateTransition3_6_Buf1[1];
    rtb_Iabc_h_idx_2 = localDW->RateTransition3_6_Buf1[2];
    break;

   case 2:
    rtb_Iabc_h_idx_0 = localDW->RateTransition3_6_Buf2[0];
    rtb_Iabc_h_idx_1 = localDW->RateTransition3_6_Buf2[1];
    rtb_Iabc_h_idx_2 = localDW->RateTransition3_6_Buf2[2];
    break;
  }

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_electrical_angle = localB->electrical_angle;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_temperature = localB->temperature;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_voltage_c = localB->voltage;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_current_h = localB->current;

  // RateTransition generated from: '<Root>/Rate Transition3'
  rtb_hallABC = localB->hallABC;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_Vcc_a = localB->Vcc;

  // BusCreator generated from: '<Root>/SensorData_out'
  rty_SensorData_out->driversensors.Vcc = rtb_Vcc_a;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_Vcc_a = localB->offset;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_rotor_angle_i = localB->rotor_angle;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_counter_b = localB->counter;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_Idx_counter_o = localB->Idx_counter;

  // BusCreator generated from: '<Root>/SensorData_out'
  rty_SensorData_out->motorsensors.qencoder.offset = rtb_Vcc_a;
  rty_SensorData_out->motorsensors.qencoder.rotor_angle = rtb_rotor_angle_i;
  rty_SensorData_out->motorsensors.qencoder.counter = rtb_counter_b;
  rty_SensorData_out->motorsensors.qencoder.Idx_counter = rtb_Idx_counter_o;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtw_mutex_lock();
  localDW->RateTransition1_6_RDBuf = localDW->RateTransition1_6_LstBufWR;
  rtw_mutex_unlock();
  switch (localDW->RateTransition1_6_RDBuf) {
   case 0:
    rty_SensorData_out->motorsensors.Iabc[0] = localDW->RateTransition1_6_Buf0[0];
    rty_SensorData_out->motorsensors.Iabc[1] = localDW->RateTransition1_6_Buf0[1];
    rty_SensorData_out->motorsensors.Iabc[2] = localDW->RateTransition1_6_Buf0[2];
    break;

   case 1:
    rty_SensorData_out->motorsensors.Iabc[0] = localDW->RateTransition1_6_Buf1[0];
    rty_SensorData_out->motorsensors.Iabc[1] = localDW->RateTransition1_6_Buf1[1];
    rty_SensorData_out->motorsensors.Iabc[2] = localDW->RateTransition1_6_Buf1[2];
    break;

   case 2:
    rty_SensorData_out->motorsensors.Iabc[0] = localDW->RateTransition1_6_Buf2[0];
    rty_SensorData_out->motorsensors.Iabc[1] = localDW->RateTransition1_6_Buf2[1];
    rty_SensorData_out->motorsensors.Iabc[2] = localDW->RateTransition1_6_Buf2[2];
    break;
  }

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_Vcc_a = localB->electrical_angle;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_rotor_angle_i = localB->temperature;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_counter_b = localB->voltage;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_Idx_counter_o = localB->current;

  // RateTransition generated from: '<Root>/Rate Transition1'
  rtb_hallABC_h = localB->hallABC;

  // BusCreator generated from: '<Root>/SensorData_out'
  rty_SensorData_out->motorsensors.electrical_angle = rtb_Vcc_a;
  rty_SensorData_out->motorsensors.temperature = rtb_rotor_angle_i;
  rty_SensorData_out->motorsensors.voltage = rtb_counter_b;
  rty_SensorData_out->motorsensors.current = rtb_Idx_counter_o;
  rty_SensorData_out->motorsensors.hallABC = rtb_hallABC_h;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->ConfigurationParameters_Buffer0 =
    rty_ActuatorsConfiguration->thresholds.jntVelMax;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->Flags_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->Flags_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->Flags_Buf[wrBufIdx] = rty_Flags->calibration_type;
  localDW->Flags_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport18_Buffer0 =
    rty_ActuatorsConfiguration->thresholds.motorNominalCurrents;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport19_Buffer0 =
    rty_ActuatorsConfiguration->thresholds.motorPeakCurrents;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport2_Buffer0 =
    rty_Flags->enable_sending_msg_status;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport20_Buffer0 =
    rty_ActuatorsConfiguration->thresholds.motorOverloadCurrents;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport21_Buffer0 =
    rty_ActuatorsConfiguration->thresholds.motorPwmLimit;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport22_Buffer0 =
    rty_ActuatorsConfiguration->thresholds.motorCriticalTemperature;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtCalibratorInport23_LstBufWR +
    1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtCalibratorInport23_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtCalibratorInport23_Buf[wrBufIdx] =
    rty_ActuatorsConfiguration->pids.currentPID.type;
  localDW->TmpRTBAtCalibratorInport23_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport24_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.OutMax;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport25_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.OutMin;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport26_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.P;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport27_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.I;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport28_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.D;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport29_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.N;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport3_Buffer0 = rty_Flags->hw_faults.overcurrent;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport30_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.I0;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport31_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.D0;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport32_Buffer0 =
    rty_ActuatorsConfiguration->pids.currentPID.shift_factor;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtCalibratorInport33_LstBufWR +
    1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtCalibratorInport33_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtCalibratorInport33_Buf[wrBufIdx] =
    rty_ActuatorsConfiguration->pids.velocityPID.type;
  localDW->TmpRTBAtCalibratorInport33_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport34_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.OutMax;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport35_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.OutMin;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport36_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.P;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport37_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.I;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport38_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.D;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport39_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.N;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport4_Buffer0 =
    rty_Flags->enable_thermal_protection;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport40_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.I0;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport41_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.D0;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport42_Buffer0 =
    rty_ActuatorsConfiguration->pids.velocityPID.shift_factor;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtCalibratorInport43_LstBufWR +
    1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtCalibratorInport43_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtCalibratorInport43_Buf[wrBufIdx] =
    rty_ActuatorsConfiguration->pids.positionPID.type;
  localDW->TmpRTBAtCalibratorInport43_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport44_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.OutMax;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport45_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.OutMin;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport46_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.P;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport47_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.I;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport48_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.D;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport49_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.N;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtCalibratorInport5_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtCalibratorInport5_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtCalibratorInport5_Buf[wrBufIdx] = rty_Flags->control_mode;
  localDW->TmpRTBAtCalibratorInport5_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport50_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.I0;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport51_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.D0;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport52_Buffer0 =
    rty_ActuatorsConfiguration->pids.positionPID.shift_factor;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport53_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.enable_verbosity;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport54_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.has_hall_sens;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport55_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.has_quadrature_encoder;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport56_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.has_speed_quadrature_encoder;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport57_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.has_temperature_sens;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport58_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.encoder_tolerance;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport59_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.pole_pairs;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport60_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.rotor_encoder_resolution;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport61_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.rotor_index_offset;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport62_Buffer0 =
    rty_ActuatorsConfiguration->motor.externals.use_index;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport63_Buffer0 =
    rty_ActuatorsConfiguration->motor.Kbemf;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport64_Buffer0 =
    rty_ActuatorsConfiguration->motor.Rphase;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport65_Buffer0 =
    rty_ActuatorsConfiguration->motor.Imin;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport66_Buffer0 =
    rty_ActuatorsConfiguration->motor.Imax;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport67_Buffer0 =
    rty_ActuatorsConfiguration->motor.Vmax;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport68_Buffer0 =
    rty_ActuatorsConfiguration->motor.resistance;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport69_Buffer0 =
    rty_ActuatorsConfiguration->motor.inductance;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport70_Buffer0 =
    rty_ActuatorsConfiguration->motor.thermal_resistance;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport71_Buffer0 =
    rty_ActuatorsConfiguration->motor.thermal_time_constant;

  // RateTransition generated from: '<Root>/Calibrator'
  localDW->TmpRTBAtCalibratorInport72_Buffer0 =
    rty_ActuatorsConfiguration->motor.hall_sensors_offset;

  // RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtCalibratorInport73_LstBufWR +
    1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtCalibratorInport73_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtCalibratorInport73_Buf[wrBufIdx] =
    rty_ActuatorsConfiguration->motor.reference_encoder;
  localDW->TmpRTBAtCalibratorInport73_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<S3>/Switch'
  localDW->ConfigurationParameters_Buffer0_m =
    rty_ActuatorsConfiguration->motor.externals.use_index;

  // RateTransition generated from: '<S9>/Switch'
  localDW->ConfigurationParameters_Buffer0_a =
    rty_ActuatorsConfiguration->motor.externals.rotor_index_offset;

  // RateTransition generated from: '<S15>/Product'
  localDW->ConfigurationParameters_Buffer0_o =
    rty_ActuatorsConfiguration->motor.externals.pole_pairs;

  // RateTransition generated from: '<Root>/Bus Creator' incorporates:
  //   BusCreator: '<Root>/Bus Creator'
  //
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtBusCreatorOutport1_LstBufWR +
    1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtBusCreatorOutport1_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].
    global_configuration.estimation.environment_temperature = 25.0F;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].
    global_configuration.estimation.current_rms_lambda = 0.995F;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].
    global_configuration.estimation.velocity_est_mode =
    EstimationVelocityModes_MovingAverage;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].
    global_configuration.estimation.velocity_est_window = 64U;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].actuator_configuration =
    *rty_ActuatorsConfiguration;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].estimated_data =
    *rty_EstimatedData;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].targets = localB->targets;
  localDW->TmpRTBAtBusCreatorOutport1_Buf[wrBufIdx].control_outer_outputs =
    rtb_Positionvelocitycascade;
  localDW->TmpRTBAtBusCreatorOutport1_LstBufWR = wrBufIdx;

  // End of RateTransition generated from: '<Root>/Bus Creator'

  // RateTransition generated from: '<Root>/FOC' incorporates:
  //   BusCreator generated from: '<Root>/FOC'

  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->TmpRTBAtFOCInport1_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->TmpRTBAtFOCInport1_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].driversensors.Vcc = rtb_Vcc;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.qencoder.offset =
    rtb_offset;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.qencoder.rotor_angle =
    rtb_rotor_angle;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.qencoder.counter =
    rtb_counter;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.qencoder.Idx_counter =
    rtb_Idx_counter;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.Iabc[0] =
    rtb_Iabc_h_idx_0;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.Iabc[1] =
    rtb_Iabc_h_idx_1;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.Iabc[2] =
    rtb_Iabc_h_idx_2;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.electrical_angle =
    rtb_electrical_angle;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.temperature =
    rtb_temperature;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.voltage = rtb_voltage_c;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.current = rtb_current_h;
  localDW->TmpRTBAtFOCInport1_Buf[wrBufIdx].motorsensors.hallABC = rtb_hallABC;
  localDW->TmpRTBAtFOCInport1_LstBufWR = wrBufIdx;

  // End of RateTransition generated from: '<Root>/FOC'
}

// Termination for referenced model: 'motion_controller'
void motion_controller_Term(DW_motion_controller_f_T *localDW)
{
  // Terminate for ModelReference generated from: '<Root>/Calibrator'
  Calibrator_Term();

  // Terminate for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition1'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition3'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Rate Transition'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/FOC'
  rtw_mutex_destroy();

  // Terminate for RateTransition: '<Root>/Rate Transition2'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Calibrator'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Bus Creator'
  rtw_mutex_destroy();

  // Terminate for RateTransition: '<Root>/Transition to 1ms'
  rtw_mutex_destroy();

  // Terminate for ModelReference: '<S1>/Current Filter'
  filter_current_Term(&(localDW->CurrentFilter_InstanceData.rtdw));
}

// Model initialize function
void motion_controller_initialize(DW_motion_controller_f_T *localDW)
{
  // Model Initialize function for ModelReference Block: '<Root>/FOC'
  control_foc_initialize(&(localDW->FOC_InstanceData.rtzce));

  // Model Initialize function for ModelReference Block: '<Root>/Position velocity cascade' 
  position_velocity_cascade_initialize
    (&(localDW->Positionvelocitycascade_InstanceData.rtzce));
}

//
// File trailer for generated code.
//
// [EOF]
//
