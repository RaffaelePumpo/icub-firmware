//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: iterative_motion_controller.cpp
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
#include "iterative_motion_controller.h"
#include "iterative_motion_controller_types.h"
#include "iterative_motion_controller_private.h"
#include "rtwtypes.h"
#include <cstring>
#include "rtw_mutex.h"
#include "mul_s32_sat.h"
#include "rtw_defines.h"
#include "process_sensors.h"
#include "Calibrator.h"
#include "control_foc.h"
#include "motion_controller.h"
#include "SupervisorFSM_TX.h"

const JointData iterative_motion_controller_rtZJointData = {
  0.0F                                 // position
};                                     // JointData ground

// Exported block parameters
ActuatorConfiguration AmcfocInitConf[2] = { {
    {
      60000.0F,
      1.0F,
      2.0F,
      3.0F,
      32000U,
      60.0F
    },

    {
      {
        ControlModes_Current,
        100.0F,
        -100.0F,
        2.0F,
        500.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0U
      },

      {
        ControlModes_Velocity,
        3.0F,
        -3.0F,
        10.0F,
        10.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0U
      },

      {
        ControlModes_Position,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0U
      }
    },

    {
      {
        false,
        true,
        false,
        false,
        false,
        0U,
        7U,
        0,
        0,
        false
      },
      0.0F,
      0.0F,
      -3.0F,
      3.0F,
      24.0F,
      0.0F,
      0.0F,
      0.0F,
      0.0F,
      0.0F,
      ReferenceEncoder_Motor
    }
  }, { {
      60000.0F,
      1.0F,
      2.0F,
      3.0F,
      32000U,
      60.0F
    },

    {
      {
        ControlModes_Current,
        100.0F,
        -100.0F,
        2.0F,
        500.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0U
      },

      {
        ControlModes_Velocity,
        3.0F,
        -3.0F,
        10.0F,
        10.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0U
      },

      {
        ControlModes_Position,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0.0F,
        0U
      }
    },

    {
      {
        false,
        true,
        false,
        false,
        false,
        0U,
        7U,
        0,
        0,
        false
      },
      0.0F,
      0.0F,
      -3.0F,
      3.0F,
      24.0F,
      0.0F,
      0.0F,
      0.0F,
      0.0F,
      30.0F,
      ReferenceEncoder_Motor
    }
  } } ;                                // Variable: AmcfocInitConf
                                          //  Referenced by: '<Root>/Constant'


// Block signals and states (default storage)
DW_iterative_motion_controller_T iterative_motion_controller_DW;

// External inputs (root inport signals with default storage)
ExtU_iterative_motion_controller_T iterative_motion_controller_U;

// External outputs (root outports fed by signals with default storage)
ExtY_iterative_motion_controller_T iterative_motion_controller_Y;

// Real-time model
RT_MODEL_iterative_motion_controller_T iterative_motion_controller_M_ =
  RT_MODEL_iterative_motion_controller_T();
RT_MODEL_iterative_motion_controller_T *const iterative_motion_controller_M =
  &iterative_motion_controller_M_;

// System initialize for atomic system: '<Root>/Sort Events'
void iterative_motion_controller_SortEvents_Init(ReceivedEvents rty_SortedEvs[8])
{
  ReceivedEvents struct_temp;
  struct_temp.motor_id = 0U;
  struct_temp.event_type = EventTypes_None;
  struct_temp.targets_content.position = 0.0F;
  struct_temp.targets_content.velocity = 0.0F;
  struct_temp.targets_content.current = 0.0F;
  struct_temp.targets_content.voltage = 0.0F;
  struct_temp.pid_content.type = ControlModes_NotConfigured;
  struct_temp.pid_content.OutMax = 0.0F;
  struct_temp.pid_content.OutMin = 0.0F;
  struct_temp.pid_content.P = 0.0F;
  struct_temp.pid_content.I = 0.0F;
  struct_temp.pid_content.D = 0.0F;
  struct_temp.pid_content.N = 0.0F;
  struct_temp.pid_content.I0 = 0.0F;
  struct_temp.pid_content.D0 = 0.0F;
  struct_temp.pid_content.shift_factor = 0U;
  struct_temp.control_mode_content = ControlModes_NotConfigured;
  struct_temp.limits_content.overload = 0.0F;
  struct_temp.limits_content.peak = 0.0F;
  struct_temp.limits_content.nominal = 0.0F;
  struct_temp.limits_content.type = ControlModes_NotConfigured;
  struct_temp.motor_config_content.enable_verbosity = false;
  struct_temp.motor_config_content.has_hall_sens = false;
  struct_temp.motor_config_content.has_quadrature_encoder = false;
  struct_temp.motor_config_content.has_speed_quadrature_encoder = false;
  struct_temp.motor_config_content.has_temperature_sens = false;
  struct_temp.motor_config_content.encoder_tolerance = 0U;
  struct_temp.motor_config_content.pole_pairs = 0U;
  struct_temp.motor_config_content.rotor_encoder_resolution = 0;
  struct_temp.motor_config_content.rotor_index_offset = 0;
  struct_temp.motor_config_content.use_index = false;
  for (int32_T i = 0; i < 8; i++) {
    rty_SortedEvs[i] = struct_temp;
  }
}

// Output and update for atomic system: '<Root>/Sort Events'
void iterative_motion_controller_SortEvents(const ReceivedEvents rtu_e[8],
  ReceivedEvents rty_SortedEvs[8])
{
  ReceivedEvents struct_temp;
  int32_T i;
  uint8_T counter_motor_1;
  uint8_T counter_motor_2;
  uint8_T idx;
  struct_temp.motor_id = 0U;
  struct_temp.event_type = EventTypes_None;
  struct_temp.targets_content.position = 0.0F;
  struct_temp.targets_content.velocity = 0.0F;
  struct_temp.targets_content.current = 0.0F;
  struct_temp.targets_content.voltage = 0.0F;
  struct_temp.pid_content.type = ControlModes_NotConfigured;
  struct_temp.pid_content.OutMax = 0.0F;
  struct_temp.pid_content.OutMin = 0.0F;
  struct_temp.pid_content.P = 0.0F;
  struct_temp.pid_content.I = 0.0F;
  struct_temp.pid_content.D = 0.0F;
  struct_temp.pid_content.N = 0.0F;
  struct_temp.pid_content.I0 = 0.0F;
  struct_temp.pid_content.D0 = 0.0F;
  struct_temp.pid_content.shift_factor = 0U;
  struct_temp.control_mode_content = ControlModes_NotConfigured;
  struct_temp.limits_content.overload = 0.0F;
  struct_temp.limits_content.peak = 0.0F;
  struct_temp.limits_content.nominal = 0.0F;
  struct_temp.limits_content.type = ControlModes_NotConfigured;
  struct_temp.motor_config_content.enable_verbosity = false;
  struct_temp.motor_config_content.has_hall_sens = false;
  struct_temp.motor_config_content.has_quadrature_encoder = false;
  struct_temp.motor_config_content.has_speed_quadrature_encoder = false;
  struct_temp.motor_config_content.has_temperature_sens = false;
  struct_temp.motor_config_content.encoder_tolerance = 0U;
  struct_temp.motor_config_content.pole_pairs = 0U;
  struct_temp.motor_config_content.rotor_encoder_resolution = 0;
  struct_temp.motor_config_content.rotor_index_offset = 0;
  struct_temp.motor_config_content.use_index = false;
  for (i = 0; i < 8; i++) {
    rty_SortedEvs[i] = struct_temp;
  }

  // Chart: '<Root>/Sort Events'
  //  Bin Events
  idx = 0U;
  counter_motor_1 = 0U;
  counter_motor_2 = 0U;
  while (idx < mul_s32_sat(N_MOTORS, MAX_EVENTS_PER_TICK)) {
    if ((rtu_e[idx].motor_id == 0) && (counter_motor_1 < MAX_EVENTS_PER_TICK)) {
      rty_SortedEvs[rtu_e[idx].motor_id + (counter_motor_1 << 1)] = rtu_e[idx];
      i = counter_motor_1 + 1;
      if (counter_motor_1 + 1 > 255) {
        i = 255;
      }

      counter_motor_1 = static_cast<uint8_T>(i);
    } else if ((rtu_e[idx].motor_id == 1) && (counter_motor_2 <
                MAX_EVENTS_PER_TICK)) {
      rty_SortedEvs[rtu_e[idx].motor_id + (counter_motor_2 << 1)] = rtu_e[idx];
      i = counter_motor_2 + 1;
      if (counter_motor_2 + 1 > 255) {
        i = 255;
      }

      counter_motor_2 = static_cast<uint8_T>(i);
    }

    i = idx + 1;
    if (idx + 1 > 255) {
      i = 255;
    }

    idx = static_cast<uint8_T>(i);
  }

  // End of Chart: '<Root>/Sort Events'
}

// Model step function for TID0
void AMCFOC_step_Time_base(void)       // Sample time: [5e-06s, 0.0s]
{
  // local scratch DWork variables
  int32_T ForEach_itr;
}

// Model step function for TID1
void AMCFOC_step_FOC(void)             // Sample time: [4.5e-05s, 0.0s]
{
  // local block i/o variables
  SensorsData rtb_process_sensors;
  boolean_T rtb_Calibrator_o1;

  // local scratch DWork variables
  int32_T ForEach_itr;
  ActuatorConfiguration rtb_RateTransition3;
  ActuatorConfiguration rtb_RateTransition5;
  FOCOutputs rtb_ImpAsg_InsertedFor_FOCOutputs_at_inport_0[2];
  FOCSlowInputs rtb_RateTransition1;
  Flags rtb_RateTransition4;
  SensorsData rtb_ImpSel_InsertedFor_SensorData_at_outport_0;
  int8_T wrBufIdx;
  boolean_T rtb_TmpRTBAtFOCInport4;
  boolean_T rtb_UnitDelay;

  // Outputs for Iterator SubSystem: '<Root>/Iterative Motion Controller' incorporates:
  //   ForEach: '<S1>/For Each'

  for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
    // ForEachSliceSelector generated from: '<S1>/SensorData' incorporates:
    //   Inport: '<Root>/SensorData'

    rtb_ImpSel_InsertedFor_SensorData_at_outport_0 =
      iterative_motion_controller_U.SensorData[ForEach_itr];

    // RateTransition generated from: '<S1>/FOC'
    rtb_TmpRTBAtFOCInport4 =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      TmpRTBAtFOCInport4_Buffer0;

    // RateTransition: '<S1>/Rate Transition4'
    rtw_mutex_lock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition4_RDBuf
      = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition4_LstBufWR;
    rtw_mutex_unlock();
    rtb_RateTransition4 = iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition4_Buf[iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition4_RDBuf];

    // RateTransition: '<S1>/Rate Transition1'
    rtw_mutex_lock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition1_RDBuf
      = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition1_LstBufWR;
    rtw_mutex_unlock();
    rtb_RateTransition1 = iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition1_Buf[iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition1_RDBuf];

    // RateTransition: '<S1>/Rate Transition5'
    rtw_mutex_lock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition5_RDBuf
      = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition5_LstBufWR;
    rtw_mutex_unlock();
    rtb_RateTransition5 = iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition5_Buf[iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition5_RDBuf];

    // RateTransition: '<S1>/Rate Transition3'
    rtw_mutex_lock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition3_RDBuf
      = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition3_LstBufWR;
    rtw_mutex_unlock();
    rtb_RateTransition3 = iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition3_Buf[iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition3_RDBuf];

    // UnitDelay: '<S1>/Unit Delay'
    rtb_UnitDelay = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      UnitDelay_DSTATE;

    // ModelReference generated from: '<S1>/process_sensors'
    process_sensors(&rtb_UnitDelay,
                    &rtb_ImpSel_InsertedFor_SensorData_at_outport_0,
                    &rtb_RateTransition3, &rtb_process_sensors,
                    &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                      process_sensors_InstanceData.rtb),
                    &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                      process_sensors_InstanceData.rtdw),
                    &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                      process_sensors_InstanceData.rtzce));

    // ModelReference: '<S1>/Calibrator'
    Calibrator(&rtb_RateTransition4, &rtb_RateTransition1, &rtb_RateTransition5,
               &rtb_process_sensors, &rtb_Calibrator_o1,
               &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
               Calibrator_o2,
               &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
               Calibrator_o3,
               &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                 Calibrator_InstanceData.rtb),
               &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                 Calibrator_InstanceData.rtdw));

    // ModelReference: '<S1>/FOC'
    control_foc(&iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                Calibrator_o2,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                Calibrator_o3, &rtb_Calibrator_o1, &rtb_TmpRTBAtFOCInport4,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].FOC,
                &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                  FOC_InstanceData.rtb),
                &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                  FOC_InstanceData.rtdw),
                &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                  FOC_InstanceData.rtzce));

    // RateTransition: '<S1>/Rate Transition2' incorporates:
    //   ModelReference: '<S1>/FOC'

    rtw_mutex_lock();
    wrBufIdx = static_cast<int8_T>
      (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
       RateTransition2_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_RDBuf) {
      wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_mutex_unlock();
    switch (wrBufIdx) {
     case 0:
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_Buf0 =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].FOC;
      break;

     case 1:
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_Buf1 =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].FOC;
      break;

     case 2:
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_Buf2 =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].FOC;
      break;
    }

    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition2_LstBufWR = wrBufIdx;

    // End of RateTransition: '<S1>/Rate Transition2'

    // RateTransition: '<S1>/Transition to 1ms'
    rtw_mutex_lock();
    wrBufIdx = static_cast<int8_T>
      (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
       Transitionto1ms_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_RDBuf) {
      wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_mutex_unlock();
    switch (wrBufIdx) {
     case 0:
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_Buf0 = rtb_process_sensors;
      break;

     case 1:
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_Buf1 = rtb_process_sensors;
      break;

     case 2:
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_Buf2 = rtb_process_sensors;
      break;
    }

    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      Transitionto1ms_LstBufWR = wrBufIdx;

    // End of RateTransition: '<S1>/Transition to 1ms'

    // Update for UnitDelay: '<S1>/Unit Delay'
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].UnitDelay_DSTATE =
      rtb_Calibrator_o1;

    // ForEachSliceAssignment generated from: '<S1>/FOCOutputs' incorporates:
    //   ModelReference: '<S1>/FOC'

    rtb_ImpAsg_InsertedFor_FOCOutputs_at_inport_0[ForEach_itr] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].FOC;
  }

  // End of Outputs for SubSystem: '<Root>/Iterative Motion Controller'

  // Outport: '<Root>/FOCOutputs' incorporates:
  //   ForEachSliceAssignment generated from: '<S1>/FOCOutputs'

  std::memcpy(&iterative_motion_controller_Y.FOCOutputs_h[0],
              &rtb_ImpAsg_InsertedFor_FOCOutputs_at_inport_0[0], sizeof
              (FOCOutputs) << 1U);
}

// Model step function for TID2
void AMCFOC_step_Time_1ms(void)        // Sample time: [0.001s, 0.0s]
{
  // local scratch DWork variables
  int32_T ForEach_itr;
  ActuatorConfiguration
    rtb_ImpAsg_InsertedFor_ConfigurationParameters_at_inport_0[2];
  ActuatorConfiguration rtb_ImpSel_InsertedFor_InitConf_at_outport_0;
  BUS_MESSAGES_TX rtb_ImpAsg_InsertedFor_Messages_at_inport_0[2];
  BUS_STATUS_TX rtb_ImpAsg_InsertedFor_MessagesFlags_at_inport_0[2];
  EstimatedData rtb_ImpAsg_InsertedFor_Estimates_at_inport_0[2];
  Flags rtb_ImpAsg_InsertedFor_Flags_at_inport_0[2];
  ReceivedEvents SortedEvs[8];
  ReceivedEvents rtb_ImpSel_InsertedFor_Events_at_outport_0[4];
  int8_T wrBufIdx;

  // Chart: '<Root>/Sort Events' incorporates:
  //   Inport: '<Root>/EventsList'

  iterative_motion_controller_SortEvents
    (iterative_motion_controller_U.EventsList, SortedEvs);

  // Outputs for Iterator SubSystem: '<Root>/Iterative Motion Controller' incorporates:
  //   ForEach: '<S1>/For Each'

  for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
    // ForEachSliceSelector generated from: '<S1>/Events'
    rtb_ImpSel_InsertedFor_Events_at_outport_0[0] = SortedEvs[ForEach_itr];
    rtb_ImpSel_InsertedFor_Events_at_outport_0[1] = SortedEvs[ForEach_itr + 2];
    rtb_ImpSel_InsertedFor_Events_at_outport_0[2] = SortedEvs[ForEach_itr + 4];
    rtb_ImpSel_InsertedFor_Events_at_outport_0[3] = SortedEvs[ForEach_itr + 6];

    // ForEachSliceSelector generated from: '<S1>/InitConf' incorporates:
    //   Constant: '<Root>/Constant'

    rtb_ImpSel_InsertedFor_InitConf_at_outport_0 = AmcfocInitConf[ForEach_itr];

    // RateTransition: '<S1>/Transition to 1ms'
    rtw_mutex_lock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Transitionto1ms_RDBuf
      = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      Transitionto1ms_LstBufWR;
    rtw_mutex_unlock();
    switch (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
            Transitionto1ms_RDBuf) {
     case 0:
      // RateTransition: '<S1>/Transition to 1ms'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Transitionto1ms =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_Buf0;
      break;

     case 1:
      // RateTransition: '<S1>/Transition to 1ms'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Transitionto1ms =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_Buf1;
      break;

     case 2:
      // RateTransition: '<S1>/Transition to 1ms'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Transitionto1ms =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        Transitionto1ms_Buf2;
      break;
    }

    // End of RateTransition: '<S1>/Transition to 1ms'

    // RateTransition: '<S1>/Rate Transition2'
    rtw_mutex_lock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition2_RDBuf
      = iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition2_LstBufWR;
    rtw_mutex_unlock();
    switch (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
            RateTransition2_RDBuf) {
     case 0:
      // RateTransition: '<S1>/Rate Transition2'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition2 =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_Buf0;
      break;

     case 1:
      // RateTransition: '<S1>/Rate Transition2'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition2 =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_Buf1;
      break;

     case 2:
      // RateTransition: '<S1>/Rate Transition2'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition2 =
        iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition2_Buf2;
      break;
    }

    // End of RateTransition: '<S1>/Rate Transition2'

    // RateTransition generated from: '<S1>/Motion Controller'
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      TmpRTBAtMotionControllerInport7 =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      Calibrator_o2.motorsensors.qencoder.offset;

    // ModelReference: '<S1>/Motion Controller' incorporates:
    //   Inport: '<Root>/ExternalFlags'

    mc_step_1ms(&iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                Transitionto1ms, &iterative_motion_controller_U.ExternalFlags_j,
                &rtb_ImpSel_InsertedFor_Events_at_outport_0[0],
                &rtb_ImpSel_InsertedFor_InitConf_at_outport_0,
                &iterative_motion_controller_rtZJointData,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                RateTransition2,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                TmpRTBAtMotionControllerInport7,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                MotionController_o1,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Flags_p,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                ConfigurationParameters,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                MotionController_o4,
                &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                areLimitsSet,
                &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                  MotionController_InstanceData.rtb),
                &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                  MotionController_InstanceData.rtdw));

    // ModelReference generated from: '<S1>/Model' incorporates:
    //   Inport: '<Root>/ExternalFlags'

    SupervisorFSM_TX(&iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                     Transitionto1ms,
                     &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                     MotionController_o1,
                     &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                     Flags_p,
                     &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                     RateTransition2,
                     &iterative_motion_controller_U.ExternalFlags_j.fault_button,
                     &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                     MessagesTx,
                     &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                     Model_o2,
                     &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                       Model_InstanceData.rtdw));

    // RateTransition: '<S1>/Rate Transition1' incorporates:
    //   ModelReference: '<S1>/Motion Controller'

    rtw_mutex_lock();
    wrBufIdx = static_cast<int8_T>
      (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
       RateTransition1_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition1_RDBuf) {
      wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_mutex_unlock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition1_Buf[wrBufIdx] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].MotionController_o4;
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition1_LstBufWR = wrBufIdx;

    // End of RateTransition: '<S1>/Rate Transition1'

    // RateTransition: '<S1>/Rate Transition3' incorporates:
    //   ModelReference: '<S1>/Motion Controller'

    rtw_mutex_lock();
    wrBufIdx = static_cast<int8_T>
      (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
       RateTransition3_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition3_RDBuf) {
      wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_mutex_unlock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition3_Buf[wrBufIdx] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      ConfigurationParameters;
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition3_LstBufWR = wrBufIdx;

    // End of RateTransition: '<S1>/Rate Transition3'

    // RateTransition: '<S1>/Rate Transition4'
    rtw_mutex_lock();
    wrBufIdx = static_cast<int8_T>
      (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
       RateTransition4_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition4_RDBuf) {
      wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_mutex_unlock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition4_Buf[wrBufIdx] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Flags_p;
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition4_LstBufWR = wrBufIdx;

    // End of RateTransition: '<S1>/Rate Transition4'

    // RateTransition: '<S1>/Rate Transition5' incorporates:
    //   ModelReference: '<S1>/Motion Controller'

    rtw_mutex_lock();
    wrBufIdx = static_cast<int8_T>
      (iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
       RateTransition5_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
        RateTransition5_RDBuf) {
      wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_mutex_unlock();
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr]
      .RateTransition5_Buf[wrBufIdx] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      ConfigurationParameters;
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      RateTransition5_LstBufWR = wrBufIdx;

    // End of RateTransition: '<S1>/Rate Transition5'

    // RateTransition generated from: '<S1>/FOC'
    iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      TmpRTBAtFOCInport4_Buffer0 =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].areLimitsSet;

    // ForEachSliceAssignment generated from: '<S1>/Messages' incorporates:
    //   ModelReference generated from: '<S1>/Model'

    rtb_ImpAsg_InsertedFor_Messages_at_inport_0[ForEach_itr] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].MessagesTx;

    // ForEachSliceAssignment generated from: '<S1>/MessagesFlags'
    rtb_ImpAsg_InsertedFor_MessagesFlags_at_inport_0[ForEach_itr] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Model_o2;

    // ForEachSliceAssignment generated from: '<S1>/Flags'
    rtb_ImpAsg_InsertedFor_Flags_at_inport_0[ForEach_itr] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Flags_p;

    // ForEachSliceAssignment generated from: '<S1>/Estimates'
    rtb_ImpAsg_InsertedFor_Estimates_at_inport_0[ForEach_itr] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].MotionController_o1;

    // ForEachSliceAssignment generated from: '<S1>/ConfigurationParameters' incorporates:
    //   ModelReference: '<S1>/Motion Controller'

    rtb_ImpAsg_InsertedFor_ConfigurationParameters_at_inport_0[ForEach_itr] =
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
      ConfigurationParameters;
  }

  // End of Outputs for SubSystem: '<Root>/Iterative Motion Controller'

  // Outport: '<Root>/Estimates'
  iterative_motion_controller_Y.Estimates[0] =
    rtb_ImpAsg_InsertedFor_Estimates_at_inport_0[0];

  // Outport: '<Root>/Flags'
  iterative_motion_controller_Y.Flags_d[0] =
    rtb_ImpAsg_InsertedFor_Flags_at_inport_0[0];

  // Outport: '<Root>/ConfigurationParameters' incorporates:
  //   ForEachSliceAssignment generated from: '<S1>/ConfigurationParameters'

  std::memcpy(&iterative_motion_controller_Y.ConfigurationParameters[0],
              &rtb_ImpAsg_InsertedFor_ConfigurationParameters_at_inport_0[0],
              sizeof(ActuatorConfiguration) << 1U);

  // Outport: '<Root>/Messages' incorporates:
  //   ForEachSliceAssignment generated from: '<S1>/Messages'

  std::memcpy(&iterative_motion_controller_Y.Messages[0],
              &rtb_ImpAsg_InsertedFor_Messages_at_inport_0[0], sizeof
              (BUS_MESSAGES_TX) << 1U);

  // Outport: '<Root>/MessagesFlags'
  iterative_motion_controller_Y.MessagesFlags[0] =
    rtb_ImpAsg_InsertedFor_MessagesFlags_at_inport_0[0];

  // Outport: '<Root>/Estimates'
  iterative_motion_controller_Y.Estimates[1] =
    rtb_ImpAsg_InsertedFor_Estimates_at_inport_0[1];

  // Outport: '<Root>/Flags'
  iterative_motion_controller_Y.Flags_d[1] =
    rtb_ImpAsg_InsertedFor_Flags_at_inport_0[1];

  // Outport: '<Root>/MessagesFlags'
  iterative_motion_controller_Y.MessagesFlags[1] =
    rtb_ImpAsg_InsertedFor_MessagesFlags_at_inport_0[1];
}

// Model initialize function
void AMCFOC_initialize(void)
{
  // Registration code

  // Set task counter limit used by the static main program
  (iterative_motion_controller_M)->Timing.TaskCounters.cLimit[0] = 1;
  (iterative_motion_controller_M)->Timing.TaskCounters.cLimit[1] = 9;
  (iterative_motion_controller_M)->Timing.TaskCounters.cLimit[2] = 200;

  // Model Initialize function for ModelReference Block: '<S1>/FOC'
  {
    int32_T i_1;
    for (i_1 = 0; i_1 < 2; i_1++) {
      control_foc_initialize(&(iterative_motion_controller_DW.CoreSubsys[i_1].
        FOC_InstanceData.rtzce));
    }
  }

  // Model Initialize function for ModelReference Block: '<S1>/Motion Controller' 
  {
    int32_T i_1;
    for (i_1 = 0; i_1 < 2; i_1++) {
      motion_controller_initialize
        (&(iterative_motion_controller_DW.CoreSubsys[i_1].
           MotionController_InstanceData.rtdw));
    }
  }

  // Model Initialize function for ModelReference Block: '<S1>/process_sensors'
  {
    int32_T i_1;
    for (i_1 = 0; i_1 < 2; i_1++) {
      process_sensors_initialize(&(iterative_motion_controller_DW.CoreSubsys[i_1]
        .process_sensors_InstanceData.rtzce));
    }
  }

  {
    // local scratch DWork variables
    int32_T ForEach_itr;
    ReceivedEvents SortedEvs[8];
    static const FOCOutputs tmp = { false,// calibrationdone
      0.0F,                            // Vq

      { 0.0F, 0.0F, 0.0F },            // Vabc
      0.0F,                            // Iq_fbk
      0.0F,                            // Id_fbk
      0.0F,                            // Iq_rms
      0.0F                             // Id_rms
    };

    static const SensorsData tmp_0 = { { 0.0F// Vcc
      },                               // driversensors

      { { 0.0F,                        // offset
          0.0F,                        // rotor_angle
          0.0F,                        // counter
          0.0F                         // Idx_counter
        },                             // qencoder

        { 0.0F, 0.0F, 0.0F },          // Iabc
        0.0F,                          // electrical_angle
        0.0F,                          // temperature
        0.0F,                          // voltage
        0.0F,                          // current
        0U                             // hallABC
      }                                // motorsensors
    };

    // SystemInitialize for Iterator SubSystem: '<Root>/Iterative Motion Controller' 
    for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
      // SystemInitialize for RateTransition: '<S1>/Rate Transition2'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].RateTransition2 =
        tmp;

      // SystemInitialize for RateTransition: '<S1>/Transition to 1ms'
      iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Transitionto1ms =
        tmp_0;

      // Start for RateTransition: '<S1>/Rate Transition4'
      rtw_mutex_init();

      // Start for RateTransition: '<S1>/Rate Transition1'
      rtw_mutex_init();

      // Start for RateTransition: '<S1>/Rate Transition5'
      rtw_mutex_init();

      // Start for RateTransition: '<S1>/Rate Transition3'
      rtw_mutex_init();

      // Start for RateTransition: '<S1>/Rate Transition2'
      rtw_mutex_init();

      // Start for RateTransition: '<S1>/Transition to 1ms'
      rtw_mutex_init();

      // SystemInitialize for ModelReference: '<S1>/Calibrator'
      Calibrator_Init(&(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                        Calibrator_InstanceData.rtdw));

      // SystemInitialize for ModelReference: '<S1>/FOC'
      control_foc_Init(&(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                         FOC_InstanceData.rtdw));

      // SystemInitialize for ModelReference generated from: '<S1>/Model'
      SupervisorFSM_TX_Init
        (&iterative_motion_controller_DW.CoreSubsys[ForEach_itr].MessagesTx,
         &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Model_o2);

      // SystemInitialize for ModelReference: '<S1>/Motion Controller'
      motion_controller_Init
        (&iterative_motion_controller_DW.CoreSubsys[ForEach_itr].Flags_p,
         &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
         ConfigurationParameters,
         &iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
         MotionController_o4,
         &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
           MotionController_InstanceData.rtb),
         &(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
           MotionController_InstanceData.rtdw));
    }

    // End of SystemInitialize for SubSystem: '<Root>/Iterative Motion Controller' 

    // SystemInitialize for Chart: '<Root>/Sort Events'
    iterative_motion_controller_SortEvents_Init(SortedEvs);

    // Enable for Iterator SubSystem: '<Root>/Iterative Motion Controller'
    for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
      // Enable for Iterator SubSystem: '<Root>/Iterative Motion Controller'
      // Enable for ModelReference: '<S1>/Motion Controller'
      motion_controller_Enable
        (&(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
           MotionController_InstanceData.rtdw));

      // End of Enable for SubSystem: '<Root>/Iterative Motion Controller'
    }

    // End of Enable for SubSystem: '<Root>/Iterative Motion Controller'
  }
}

// Model terminate function
void AMCFOC_terminate(void)
{
  // local scratch DWork variables
  int32_T ForEach_itr;

  // Terminate for Iterator SubSystem: '<Root>/Iterative Motion Controller'
  for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
    // Terminate for RateTransition: '<S1>/Rate Transition4'
    rtw_mutex_destroy();

    // Terminate for RateTransition: '<S1>/Rate Transition1'
    rtw_mutex_destroy();

    // Terminate for RateTransition: '<S1>/Rate Transition5'
    rtw_mutex_destroy();

    // Terminate for RateTransition: '<S1>/Rate Transition3'
    rtw_mutex_destroy();

    // Terminate for ModelReference: '<S1>/FOC'
    control_foc_Term(&(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
                       FOC_InstanceData.rtdw));

    // Terminate for RateTransition: '<S1>/Rate Transition2'
    rtw_mutex_destroy();

    // Terminate for RateTransition: '<S1>/Transition to 1ms'
    rtw_mutex_destroy();

    // Terminate for ModelReference: '<S1>/Motion Controller'
    motion_controller_Term
      (&(iterative_motion_controller_DW.CoreSubsys[ForEach_itr].
         MotionController_InstanceData.rtdw));
  }

  // End of Terminate for SubSystem: '<Root>/Iterative Motion Controller'
}

boolean_T RT_MODEL_iterative_motion_controller_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

uint32_T &RT_MODEL_iterative_motion_controller_T::CounterLimit(int32_T idx)
{
  return (Timing.TaskCounters.cLimit[(idx)]);
}

uint32_T &RT_MODEL_iterative_motion_controller_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

//
// File trailer for generated code.
//
// [EOF]
//
