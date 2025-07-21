//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: motion_controller.cpp
//
// Code generated for Simulink model 'motion_controller'.
//
// Model version                  : 5.64
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Mon Jul 21 11:20:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller.h"
#include "motion_controller_types.h"
#include "rtw_mutex.h"
#include <cmath>
#include "rtwtypes.h"
#include "motion_controller_private.h"
#include "Calibrator.h"
#include "control_foc.h"
#include "estimation_velocity.h"
#include "filter_current.h"
#include "supervisor.h"
#include "position_velocity_cascade.h"

// System initialize for referenced model: 'motion_controller'
void motion_controller_Init(Flags *rty_Flags, ActuatorConfiguration
  *rty_ActuatorsConfiguration, B_motion_controller_c_T *localB,
  DW_motion_controller_f_T *localDW)
{
  // Start for RateTransition: '<Root>/Rate Transition4'
  rtw_mutex_init();

  // Start for RateTransition generated from: '<Root>/Model'
  rtw_mutex_init();

  // Start for RateTransition: '<Root>/Rate Transition5'
  rtw_mutex_init();

  // Start for RateTransition: '<Root>/Rate Transition3'
  rtw_mutex_init();

  // Start for RateTransition: '<Root>/Rate Transition2'
  rtw_mutex_init();

  // Start for RateTransition: '<Root>/Transition to 1ms'
  rtw_mutex_init();

  // SystemInitialize for ModelReference: '<S1>/Current Filter'
  filter_current_Init(&(localDW->CurrentFilter_InstanceData.rtdw));

  // SystemInitialize for ModelReference: '<S1>/Joint Velocity Estimator'
  estimation_velocity_Init(&(localDW->JointVelocityEstimator_InstanceData.rtdw));

  // SystemInitialize for ModelReference: '<S1>/Motor Velocity Estimator'
  estimation_velocity_Init(&(localDW->MotorVelocityEstimator_InstanceData.rtdw));

  // SystemInitialize for ModelReference: '<Root>/FOC'
  control_foc_Init(&(localDW->FOC_InstanceData.rtdw));

  // SystemInitialize for ModelReference generated from: '<Root>/Model'
  Calibrator_Init(&(localDW->Model_InstanceData.rtdw));

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
  // Disable for ModelReference generated from: '<Root>/Model'
  Calibrator_Disable(&(localDW->Model_InstanceData.rtdw));

  // Disable for ModelReference generated from: '<Root>/Position velocity cascade' 
  position_velocity_cascade_Disable
    (&(localDW->Positionvelocitycascade_InstanceData.rtb),
     &(localDW->Positionvelocitycascade_InstanceData.rtdw));
}

// Output and update for referenced model: 'motion_controller'
void motion_controllerTID0(void)
{
}

// Output and update for referenced model: 'motion_controller'
void motion_controllerTID1(const SensorsData *rtu_SensorData, FOCOutputs
  *rty_FOCOutputs, B_motion_controller_c_T *localB, DW_motion_controller_f_T
  *localDW)
{
  ActuatorConfiguration rtb_RateTransition3;
  FOCSlowInputs rtb_RateTransition5;
  Flags rtb_Flags;
  SensorsData rtb_BusAssignment;
  real32_T rtb_Add;
  int16_T rtb_RateTransition4_motor_externals_rotor_index_offset;
  int8_T wrBufIdx;
  uint8_T rtb_RateTransition4_motor_externals_pole_pairs;
  boolean_T rtb_Compare;
  boolean_T rtb_RateTransition4_motor_externals_has_quadrature_encoder;

  // RateTransition: '<Root>/Rate Transition4'
  rtw_mutex_lock();
  localDW->RateTransition4_RDBuf = localDW->RateTransition4_LstBufWR;
  rtw_mutex_unlock();
  rtb_RateTransition4_motor_externals_has_quadrature_encoder =
    localDW->RateTransition4_Buf[localDW->RateTransition4_RDBuf].
    motor.externals.has_quadrature_encoder;
  rtb_RateTransition4_motor_externals_pole_pairs = localDW->
    RateTransition4_Buf[localDW->RateTransition4_RDBuf].
    motor.externals.pole_pairs;
  rtb_RateTransition4_motor_externals_rotor_index_offset =
    localDW->RateTransition4_Buf[localDW->RateTransition4_RDBuf].
    motor.externals.rotor_index_offset;

  // Outputs for Atomic SubSystem: '<Root>/Process Sensors'
  // Sum: '<S3>/Add'
  rtb_Add = rtu_SensorData->motorsensors.qencoder.counter -
    rtu_SensorData->motorsensors.qencoder.Idx_counter;

  // RelationalOperator: '<S8>/Compare' incorporates:
  //   UnitDelay: '<S3>/Unit Delay1'

  rtb_Compare = localDW->UnitDelay1_DSTATE;

  // BusAssignment: '<S3>/Bus Assignment'
  rtb_BusAssignment = *rtu_SensorData;

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // RelationalOperator: '<S6>/FixPt Relational Operator' incorporates:
  //   UnitDelay: '<S3>/Unit Delay1'
  //   UnitDelay: '<S6>/Delay Input1'
  //
  //  Block description for '<S6>/Delay Input1':
  //
  //   Store in Global RAM

  if (static_cast<int32_T>(localDW->UnitDelay1_DSTATE) > static_cast<int32_T>
      (localDW->DelayInput1_DSTATE)) {
    // MATLAB Function: '<S7>/MATLAB Function'
    if (!localDW->first_call_not_empty) {
      localDW->first_call_not_empty = true;
      localDW->previous_unwrapped = rtb_Add;
      localB->unwrapped_angle = rtb_Add;
    } else {
      rtb_Add = std::fmod((rtb_Add - localDW->previous_unwrapped) + 180.0F,
                          360.0F);
      if (rtb_Add == 0.0F) {
        rtb_Add = 0.0F;
      } else if (rtb_Add < 0.0F) {
        rtb_Add += 360.0F;
      }

      localB->unwrapped_angle = (rtb_Add - 180.0F) + localDW->previous_unwrapped;
      localDW->previous_unwrapped = localB->unwrapped_angle;
    }

    // End of MATLAB Function: '<S7>/MATLAB Function'

    // Switch: '<S3>/Switch2'
    rtb_Add = localB->unwrapped_angle;
  }

  // End of RelationalOperator: '<S6>/FixPt Relational Operator'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // BusAssignment: '<S3>/Bus Assignment' incorporates:
  //   Product: '<S3>/Product'
  //   RateTransition: '<Root>/Rate Transition4'
  //   Sum: '<S3>/Add1'

  rtb_BusAssignment.motorsensors.qencoder.rotor_angle = rtb_Add;
  rtb_BusAssignment.motorsensors.electrical_angle = rtb_Add *
    static_cast<real32_T>(rtb_RateTransition4_motor_externals_pole_pairs) -
    static_cast<real32_T>(rtb_RateTransition4_motor_externals_rotor_index_offset);

  // Switch: '<S3>/Switch' incorporates:
  //   RateTransition: '<Root>/Rate Transition4'

  if (!rtb_RateTransition4_motor_externals_has_quadrature_encoder) {
    rtb_BusAssignment = *rtu_SensorData;
  }

  // End of Switch: '<S3>/Switch'
  // End of Outputs for SubSystem: '<Root>/Process Sensors'

  // RateTransition generated from: '<Root>/Model'
  rtw_mutex_lock();
  localDW->Flags_RDBuf = localDW->Flags_LstBufWR;
  rtw_mutex_unlock();
  rtb_Flags = localDW->Flags_Buf[localDW->Flags_RDBuf];

  // RateTransition: '<Root>/Rate Transition5'
  rtw_mutex_lock();
  localDW->RateTransition5_RDBuf = localDW->RateTransition5_LstBufWR;
  rtw_mutex_unlock();
  rtb_RateTransition5 = localDW->RateTransition5_Buf
    [localDW->RateTransition5_RDBuf];

  // RateTransition: '<Root>/Rate Transition3'
  rtw_mutex_lock();
  localDW->RateTransition3_RDBuf = localDW->RateTransition3_LstBufWR;
  rtw_mutex_unlock();
  rtb_RateTransition3 = localDW->RateTransition3_Buf
    [localDW->RateTransition3_RDBuf];

  // ModelReference generated from: '<Root>/Model' incorporates:
  //   UnitDelay: '<S3>/Unit Delay1'

  Calibrator(&rtb_Flags, &rtb_BusAssignment, &rtb_RateTransition5,
             &rtb_RateTransition3, &localDW->UnitDelay1_DSTATE,
             &localB->Model_o2, &localB->Model_o3,
             &(localDW->Model_InstanceData.rtb),
             &(localDW->Model_InstanceData.rtdw));

  // ModelReference: '<Root>/FOC' incorporates:
  //   UnitDelay: '<S3>/Unit Delay1'

  control_foc(&localB->Model_o2, &localB->Model_o3, &localDW->UnitDelay1_DSTATE,
              rty_FOCOutputs, &(localDW->FOC_InstanceData.rtb),
              &(localDW->FOC_InstanceData.rtdw),
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
    localDW->Transitionto1ms_Buf0 = rtb_BusAssignment;
    break;

   case 1:
    localDW->Transitionto1ms_Buf1 = rtb_BusAssignment;
    break;

   case 2:
    localDW->Transitionto1ms_Buf2 = rtb_BusAssignment;
    break;
  }

  localDW->Transitionto1ms_LstBufWR = wrBufIdx;

  // End of RateTransition: '<Root>/Transition to 1ms'

  // Update for Atomic SubSystem: '<Root>/Process Sensors'
  // Update for UnitDelay: '<S6>/Delay Input1'
  //
  //  Block description for '<S6>/Delay Input1':
  //
  //   Store in Global RAM

  localDW->DelayInput1_DSTATE = rtb_Compare;

  // End of Update for SubSystem: '<Root>/Process Sensors'
}

// Output and update for referenced model: 'motion_controller'
void mc_step_1ms(const ExternalFlags *rtu_ExternalFlags, const ReceivedEvents
                 rtu_Events[4], const ActuatorConfiguration *rtu_InitConf, const
                 JointData *rtu_JointData, EstimatedData *rty_EstimatedData,
                 Flags *rty_Flags, ActuatorConfiguration
                 *rty_ActuatorsConfiguration, B_motion_controller_c_T *localB,
                 DW_motion_controller_f_T *localDW)
{
  ControlOuterOutputs rtb_Positionvelocitycascade;
  int8_T wrBufIdx;

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
                      &rtCP_Velocityestimationwindow_Value, &localB->velocity,
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
                      &rtCP_Velocityestimationwindow_Value, &localB->velocity_g,
                      &(localDW->JointVelocityEstimator_InstanceData.rtdw));

  // BusCreator generated from: '<S1>/Estimation_BusCreator'
  rty_EstimatedData->rotor_velocity = localB->velocity;
  rty_EstimatedData->motor_temperature = 0.0F;
  rty_EstimatedData->joint_velocity = localB->velocity_g;

  // RateTransition generated from: '<Root>/Motor Supervisor'
  localB->TmpRTBAtMotorSupervisorInport8 =
    localB->Model_o2.motorsensors.qencoder.offset;

  // ModelReference generated from: '<Root>/Motor Supervisor'
  supervisor(rtu_ExternalFlags, rty_EstimatedData, &localB->RateTransition2,
             &localB->Transitionto1ms, &rtu_Events[0], rtu_InitConf,
             &localB->TmpRTBAtMotorSupervisorInport8, &localB->targets,
             rty_ActuatorsConfiguration, rty_Flags,
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

  // RateTransition: '<Root>/Rate Transition5' incorporates:
  //   BusCreator: '<Root>/Bus Creator'
  //
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition5_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition5_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition5_Buf[wrBufIdx].
    global_configuration.estimation.environment_temperature = 25.0F;
  localDW->RateTransition5_Buf[wrBufIdx].
    global_configuration.estimation.current_rms_lambda = 0.995F;
  localDW->RateTransition5_Buf[wrBufIdx].
    global_configuration.estimation.velocity_est_mode =
    EstimationVelocityModes_MovingAverage;
  localDW->RateTransition5_Buf[wrBufIdx].
    global_configuration.estimation.velocity_est_window = 64U;
  localDW->RateTransition5_Buf[wrBufIdx].actuator_configuration =
    *rty_ActuatorsConfiguration;
  localDW->RateTransition5_Buf[wrBufIdx].estimated_data = *rty_EstimatedData;
  localDW->RateTransition5_Buf[wrBufIdx].targets = localB->targets;
  localDW->RateTransition5_Buf[wrBufIdx].control_outer_outputs =
    rtb_Positionvelocitycascade;
  localDW->RateTransition5_LstBufWR = wrBufIdx;

  // End of RateTransition: '<Root>/Rate Transition5'

  // RateTransition generated from: '<Root>/Model'
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
  localDW->Flags_Buf[wrBufIdx] = *rty_Flags;
  localDW->Flags_LstBufWR = wrBufIdx;

  // End of RateTransition generated from: '<Root>/Model'

  // RateTransition: '<Root>/Rate Transition3'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition3_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition3_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition3_Buf[wrBufIdx] = *rty_ActuatorsConfiguration;
  localDW->RateTransition3_LstBufWR = wrBufIdx;

  // End of RateTransition: '<Root>/Rate Transition3'

  // RateTransition: '<Root>/Rate Transition4'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->RateTransition4_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->RateTransition4_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  localDW->RateTransition4_Buf[wrBufIdx] = *rty_ActuatorsConfiguration;
  localDW->RateTransition4_LstBufWR = wrBufIdx;

  // End of RateTransition: '<Root>/Rate Transition4'
}

// Termination for referenced model: 'motion_controller'
void motion_controller_Term(DW_motion_controller_f_T *localDW)
{
  // Terminate for RateTransition: '<Root>/Rate Transition4'
  rtw_mutex_destroy();

  // Terminate for RateTransition generated from: '<Root>/Model'
  rtw_mutex_destroy();

  // Terminate for RateTransition: '<Root>/Rate Transition5'
  rtw_mutex_destroy();

  // Terminate for RateTransition: '<Root>/Rate Transition3'
  rtw_mutex_destroy();

  // Terminate for RateTransition: '<Root>/Rate Transition2'
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
