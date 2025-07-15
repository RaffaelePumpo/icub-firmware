//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Calibrator.cpp
//
// Code generated for Simulink model 'Calibrator'.
//
// Model version                  : 1.92
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Mon Jul 14 12:23:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Calibrator.h"
#include "rtwtypes.h"
#include "Calibrator_types.h"
#include "rtw_mutex.h"
#include <cmath>

// Named constants for Chart: '<Root>/calibrator'
const uint8_T Calibrator_IN_Finish = 1U;
const uint8_T Calibrator_IN_Idx_found = 2U;
const uint8_T Calibrator_IN_Read_0_encoder = 3U;
const uint8_T Calibrator_IN_Search_idx = 4U;
const uint8_T Calibrator_IN_Zero_electric = 5U;
const uint8_T Calibrator_IN_velocity_check = 6U;

// System initialize for referenced model: 'Calibrator'
void Calibrator_Init(void)
{
	return;
  // Start for RateTransition generated from: '<Root>/Merge1'
  rtw_mutex_init();
}

// Output and update for referenced model: 'Calibrator'
void CalibratorTID0(real32_T *rty_SensorDataCalibration_driversensors_Vcc,
                    real32_T
                    *rty_SensorDataCalibration_motorsensors_qencoder_offset,
                    real32_T
                    *rty_SensorDataCalibration_motorsensors_qencoder_rotor_angle,
                    real32_T
                    *rty_SensorDataCalibration_motorsensors_qencoder_counter,
                    real32_T
                    *rty_SensorDataCalibration_motorsensors_qencoder_Idx_counter,
                    real32_T rty_SensorDataCalibration_motorsensors_Iabc[3],
                    real32_T
                    *rty_SensorDataCalibration_motorsensors_electrical_angle,
                    real32_T *rty_SensorDataCalibration_motorsensors_temperature,
                    real32_T *rty_SensorDataCalibration_motorsensors_voltage,
                    real32_T *rty_SensorDataCalibration_motorsensors_current,
                    uint8_T *rty_SensorDataCalibration_motorsensors_hallABC,
                    DW_Calibrator_f_T *localDW)
{
	return;
  int32_T tmp;

  // RateTransition generated from: '<Root>/Merge1'
  rtw_mutex_lock();
  localDW->Iabc_RDBuf = localDW->Iabc_LstBufWR;
  rtw_mutex_unlock();
  tmp = localDW->Iabc_RDBuf * 3;
  rty_SensorDataCalibration_motorsensors_Iabc[0] = localDW->Iabc_Buf[tmp];
  rty_SensorDataCalibration_motorsensors_Iabc[1] = localDW->Iabc_Buf[tmp + 1];
  rty_SensorDataCalibration_motorsensors_Iabc[2] = localDW->Iabc_Buf[tmp + 2];

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_qencoder_Idx_counter =
    localDW->Idx_counter_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_driversensors_Vcc = localDW->Vcc_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_qencoder_counter =
    localDW->counter_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_current = localDW->current_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_electrical_angle =
    localDW->electrical_angle_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_hallABC = localDW->hallABC_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_qencoder_offset =
    localDW->offset_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_qencoder_rotor_angle =
    localDW->rotor_angle_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_temperature =
    localDW->temperature_Buffer0;

  // RateTransition generated from: '<Root>/Merge1'
  *rty_SensorDataCalibration_motorsensors_voltage = localDW->voltage_Buffer0;
}

// Output and update for referenced model: 'Calibrator'
void CalibratorTID1(const CalibrationTypes *rtu_Flags_calibration_type, const
                    real32_T *rtu_Sensors_driversensors_Vcc, const real32_T
                    *rtu_Sensors_motorsensors_qencoder_offset, const real32_T
                    *rtu_Sensors_motorsensors_qencoder_rotor_angle, const
                    real32_T *rtu_Sensors_motorsensors_qencoder_counter, const
                    real32_T *rtu_Sensors_motorsensors_qencoder_Idx_counter,
                    const real32_T rtu_Sensors_motorsensors_Iabc[3], const
                    real32_T *rtu_Sensors_motorsensors_electrical_angle, const
                    real32_T *rtu_Sensors_motorsensors_temperature, const
                    real32_T *rtu_Sensors_motorsensors_voltage, const real32_T
                    *rtu_Sensors_motorsensors_current, const uint8_T
                    *rtu_Sensors_motorsensors_hallABC, const real32_T
                    *rtu_ActuatorConf_thresholds_motorNominalCurrents, const
                    real32_T
                    *rtu_FocInputs_global_configuration_estimation_environment_te,
                    const real32_T
                    *rtu_FocInputs_global_configuration_estimation_current_rms_la,
                    const EstimationVelocityModes
                    *rtu_FocInputs_global_configuration_estimation_velocity_est_m,
                    const uint32_T
                    *rtu_FocInputs_global_configuration_estimation_velocity_est_w,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_thresholds_jntVelMax,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_thresholds_motorNominal,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_thresholds_motorPeakCur,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_thresholds_motorOverloa,
                    const uint32_T
                    *rtu_FocInputs_actuator_configuration_thresholds_motorPwmLimi,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_thresholds_motorCritica,
                    const ControlModes
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_type,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMax,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMin,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_P,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_I,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_D,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_N,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_I0,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_D0,
                    const uint8_T
                    *rtu_FocInputs_actuator_configuration_pids_currentPID_shift_f,
                    const ControlModes
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_type,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMax,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMin,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_P,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_I,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_D,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_N,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_I0,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_D0,
                    const uint8_T
                    *rtu_FocInputs_actuator_configuration_pids_velocityPID_shift_,
                    const ControlModes
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_type,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMax,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMin,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_P,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_I,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_D,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_N,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_I0,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_D0,
                    const uint8_T
                    *rtu_FocInputs_actuator_configuration_pids_positionPID_shift_,
                    const boolean_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_enable_,
                    const boolean_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_has_hal,
                    const boolean_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_has_qua,
                    const boolean_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_has_spe,
                    const boolean_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_has_tem,
                    const uint8_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_encoder,
                    const uint8_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_pole_pa,
                    const int16_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_rotor_e,
                    const int16_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_rotor_i,
                    const boolean_T
                    *rtu_FocInputs_actuator_configuration_motor_externals_use_ind,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_Kbemf, const
                    real32_T *rtu_FocInputs_actuator_configuration_motor_Rphase,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_Imin, const
                    real32_T *rtu_FocInputs_actuator_configuration_motor_Imax,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_Vmax, const
                    real32_T
                    *rtu_FocInputs_actuator_configuration_motor_resistance,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_inductance,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_thermal_resistanc,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_thermal_time_cons,
                    const real32_T
                    *rtu_FocInputs_actuator_configuration_motor_hall_sensors_offs,
                    const ReferenceEncoder
                    *rtu_FocInputs_actuator_configuration_motor_reference_encoder,
                    const real32_T *rtu_FocInputs_estimated_data_rotor_velocity,
                    const real32_T *rtu_FocInputs_estimated_data_Iq_filtered,
                    const real32_T
                    *rtu_FocInputs_estimated_data_motor_temperature, const
                    real32_T *rtu_FocInputs_estimated_data_joint_velocity, const
                    real32_T *rtu_FocInputs_targets_position, const real32_T
                    *rtu_FocInputs_targets_velocity, const real32_T
                    *rtu_FocInputs_targets_current, const real32_T
                    *rtu_FocInputs_targets_voltage, const boolean_T
                    *rtu_FocInputs_control_outer_outputs_vel_en, const boolean_T
                    *rtu_FocInputs_control_outer_outputs_cur_en, const boolean_T
                    *rtu_FocInputs_control_outer_outputs_out_en, const boolean_T
                    *rtu_FocInputs_control_outer_outputs_pid_reset, const
                    real32_T *rtu_FocInputs_control_outer_outputs_motorcurrent,
                    const real32_T
                    *rtu_FocInputs_control_outer_outputs_current_limiter,
                    boolean_T *rty_CalibrationDone, real32_T
                    *rty_FocInputsCalibration_global_configuration_estimation_env,
                    real32_T
                    *rty_FocInputsCalibration_global_configuration_estimation_cur,
                    EstimationVelocityModes
                    *rty_FocInputsCalibration_global_configuration_estimation_vel,
                    uint32_T
                    *rty_FocInputsCalibration_global_configuration_estimation_v_p,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_thresholds_j,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_thresholds_m,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_thresholds_g,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_threshold_m2,
                    uint32_T
                    *rty_FocInputsCalibration_actuator_configuration_thresholds_p,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_thresholds_i,
                    ControlModes
                    *rty_FocInputsCalibration_actuator_configuration_pids_current,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curre_p,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curre_o,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curre_e,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curre_m,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curre_j,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curr_po,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curr_m3,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curr_p2,
                    uint8_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_curre_i,
                    ControlModes
                    *rty_FocInputsCalibration_actuator_configuration_pids_velocit,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_h,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_b,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_n,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_g,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_velo_go,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_e,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_k,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_velo_bn,
                    uint8_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_c,
                    ControlModes
                    *rty_FocInputsCalibration_actuator_configuration_pids_positio,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posit_p,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posi_py,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posit_e,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posi_px,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posit_m,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posit_n,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posit_f,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posit_d,
                    uint8_T
                    *rty_FocInputsCalibration_actuator_configuration_pids_posi_mw,
                    boolean_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_extern,
                    boolean_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_exte_h,
                    boolean_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h2,
                    boolean_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_ext_hs,
                    boolean_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_exte_i,
                    uint8_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h5,
                    uint8_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h1,
                    int16_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_ext_ig,
                    int16_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_exte_d,
                    boolean_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_exte_a,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_Kbemf,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_Rphase,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_Imin,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_Imax,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_Vmax,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_resist,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_induct,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_therma,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_ther_h,
                    real32_T
                    *rty_FocInputsCalibration_actuator_configuration_motor_hall_s,
                    ReferenceEncoder
                    *rty_FocInputsCalibration_actuator_configuration_motor_refere,
                    real32_T
                    *rty_FocInputsCalibration_estimated_data_rotor_velocity,
                    real32_T
                    *rty_FocInputsCalibration_estimated_data_Iq_filtered,
                    real32_T
                    *rty_FocInputsCalibration_estimated_data_motor_temperature,
                    real32_T
                    *rty_FocInputsCalibration_estimated_data_joint_velocity,
                    real32_T *rty_FocInputsCalibration_targets_position,
                    real32_T *rty_FocInputsCalibration_targets_velocity,
                    real32_T *rty_FocInputsCalibration_targets_current, real32_T
                    *rty_FocInputsCalibration_targets_voltage, boolean_T
                    *rty_FocInputsCalibration_control_outer_outputs_vel_en,
                    boolean_T
                    *rty_FocInputsCalibration_control_outer_outputs_cur_en,
                    boolean_T
                    *rty_FocInputsCalibration_control_outer_outputs_out_en,
                    boolean_T
                    *rty_FocInputsCalibration_control_outer_outputs_pid_reset,
                    real32_T
                    *rty_FocInputsCalibration_control_outer_outputs_motorcurrent,
                    real32_T
                    *rty_FocInputsCalibration_control_outer_outputs_current_limit,
                    B_Calibrator_c_T *localB, DW_Calibrator_f_T *localDW)
{
	return;
  int32_T tmp_1;
  real32_T Idx_counter;
  real32_T Vcc;
  real32_T counter;
  real32_T current;
  real32_T electrical_angle;
  real32_T offset;
  real32_T rotor_angle;
  real32_T temperature;
  real32_T voltage;
  uint32_T rtb_AlgoDataType;
  int8_T wrBufIdx;
  uint8_T hallABC;

  // DataTypeConversion: '<S3>/AlgoDataType' incorporates:
  //   Constant: '<S3>/PositionToCount'
  //   Product: '<S3>/Product'

  rtb_AlgoDataType = static_cast<uint32_T>(1.1930465E+7F *
    *rtu_Sensors_motorsensors_qencoder_rotor_angle);

  // Chart: '<Root>/calibrator'
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c2_Calibrator == 0) {
    localDW->is_active_c2_Calibrator = 1U;
    localDW->is_c2_Calibrator = Calibrator_IN_Zero_electric;
    *rty_CalibrationDone = false;
    localDW->p_index = *rtu_Sensors_motorsensors_qencoder_Idx_counter;
    localDW->diff_index = 0.0F;
    localDW->tzeroalign = 0.7;
    localDW->talign = 0.1;
    localDW->v_threshold = 2.0;
    localDW->count = 0.0F;
    localB->target_angle = 0.0F;
  } else {
    boolean_T guard1;
    boolean_T guard2;
    guard1 = false;
    guard2 = false;
    switch (localDW->is_c2_Calibrator) {
     case Calibrator_IN_Finish:
      localB->Iq_ref = 0.0F;
      break;

     case Calibrator_IN_Idx_found:
      localDW->condition = 4.0;
      localDW->temporalCounter_i1 = 0U;
      localDW->is_c2_Calibrator = Calibrator_IN_velocity_check;
      localB->Iq_ref = *rtu_ActuatorConf_thresholds_motorNominalCurrents;
      break;

     case Calibrator_IN_Read_0_encoder:
      *rty_CalibrationDone = true;
      localDW->is_c2_Calibrator = Calibrator_IN_Finish;
      localB->Iq_ref = 0.0F;
      break;

     case Calibrator_IN_Search_idx:
      if (localDW->count == 360.0F) {
        localDW->is_c2_Calibrator = Calibrator_IN_Zero_electric;
        *rty_CalibrationDone = false;
        localDW->p_index = *rtu_Sensors_motorsensors_qencoder_Idx_counter;
        localDW->diff_index = 0.0F;
        localDW->tzeroalign = 0.7;
        localDW->talign = 0.1;
        localDW->v_threshold = 2.0;
        localDW->count = 0.0F;
        localB->target_angle = 0.0F;
      } else if ((localDW->diff_index != 0.0F) && (*rtu_Flags_calibration_type ==
                  CalibrationTypes_Search_Index)) {
        *rty_CalibrationDone = true;
        localDW->is_c2_Calibrator = Calibrator_IN_Finish;
        localB->Iq_ref = 0.0F;
      } else {
        localDW->condition = 2.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c2_Calibrator = Calibrator_IN_velocity_check;
        localB->Iq_ref = *rtu_ActuatorConf_thresholds_motorNominalCurrents;
      }
      break;

     case Calibrator_IN_Zero_electric:
      if (*rtu_Flags_calibration_type != CalibrationTypes_None) {
        localDW->condition = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c2_Calibrator = Calibrator_IN_velocity_check;
        localB->Iq_ref = *rtu_ActuatorConf_thresholds_motorNominalCurrents;
      }
      break;

     default:
      {
        // case IN_velocity_check:
        if ((localDW->diff_index != 0.0F) && (*rtu_Flags_calibration_type ==
             CalibrationTypes_Full_Calibration) && (localDW->condition == 2.0))
        {
          localDW->condition = 3.0;
          guard1 = true;
        } else if (std::abs(static_cast<real32_T>(static_cast<int32_T>
                     (rtb_AlgoDataType) - static_cast<int32_T>
                     (localDW->Delay_DSTATE[localDW->CircBufIdx])) *
                            4.67218683E-7F) > localDW->v_threshold) {
          guard1 = true;
        } else {
          real_T tmp_0;
          tmp_0 = std::ceil(localDW->tzeroalign / 0.0001 - 1.0E-12);
          if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>(tmp_0)) &&
              (localDW->condition == 1.0)) {
            guard2 = true;
          } else {
            real_T tmp;
            tmp = std::ceil(localDW->talign / 0.0001 - 1.0E-12);
            if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>(tmp)) &&
                (localDW->condition == 2.0)) {
              guard2 = true;
            } else if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>(tmp))
                       && (localDW->condition == 3.0)) {
              localDW->is_c2_Calibrator = Calibrator_IN_Idx_found;
              localB->Iq_ref = *rtu_ActuatorConf_thresholds_motorNominalCurrents;
              localB->target_angle = 0.0F;
            } else if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>
                        (tmp_0)) && (localDW->condition == 4.0)) {
              localDW->is_c2_Calibrator = Calibrator_IN_Read_0_encoder;
              localB->offset_d = *rtu_Sensors_motorsensors_qencoder_rotor_angle
                + 90.0F;
              if (localB->offset_d > 360.0F) {
                localB->offset_d -= 360.0F;
              }
            } else {
              localB->Iq_ref = *rtu_ActuatorConf_thresholds_motorNominalCurrents;
            }
          }
        }
      }
      break;
    }

    if (guard2) {
      localDW->is_c2_Calibrator = Calibrator_IN_Search_idx;
      localDW->count++;
      localB->target_angle = localDW->count;
      localDW->diff_index = *rtu_Sensors_motorsensors_qencoder_Idx_counter -
        localDW->p_index;
      if (localDW->diff_index != 0.0F) {
        localDW->p_index = *rtu_Sensors_motorsensors_qencoder_Idx_counter;
      }
    }

    if (guard1) {
      localDW->temporalCounter_i1 = 0U;
      localDW->is_c2_Calibrator = Calibrator_IN_velocity_check;
      localB->Iq_ref = *rtu_ActuatorConf_thresholds_motorNominalCurrents;
    }
  }

  // End of Chart: '<Root>/calibrator'

  // SwitchCase: '<Root>/Switch Case1'
  if (*rtu_Flags_calibration_type == CalibrationTypes_None) {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    Vcc = *rtu_Sensors_driversensors_Vcc;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    current = *rtu_Sensors_motorsensors_current;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    hallABC = *rtu_Sensors_motorsensors_hallABC;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    offset = *rtu_Sensors_motorsensors_qencoder_offset;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    rotor_angle = *rtu_Sensors_motorsensors_qencoder_rotor_angle;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    counter = *rtu_Sensors_motorsensors_qencoder_counter;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    Idx_counter = *rtu_Sensors_motorsensors_qencoder_Idx_counter;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    electrical_angle = *rtu_Sensors_motorsensors_electrical_angle;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    temperature = *rtu_Sensors_motorsensors_temperature;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S1>/SensorDataCalibration'

    voltage = *rtu_Sensors_motorsensors_voltage;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_env =
      *rtu_FocInputs_global_configuration_estimation_environment_te;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_i =
      *rtu_FocInputs_actuator_configuration_thresholds_motorCritica;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_current =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_type;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_p =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMax;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_o =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMin;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_e =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_P;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_m =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_I;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_j =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_D;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curr_po =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_N;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curr_m3 =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_I0;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curr_p2 =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_D0;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_cur =
      *rtu_FocInputs_global_configuration_estimation_current_rms_la;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_i =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_shift_f;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_velocit =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_type;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_h =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMax;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_b =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMin;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_n =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_P;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_g =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_I;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_velo_go =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_D;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_e =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_N;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_k =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_I0;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_velo_bn =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_D0;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_vel =
      *rtu_FocInputs_global_configuration_estimation_velocity_est_m;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_c =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_shift_;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_positio =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_type;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_p =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMax;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posi_py =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMin;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_e =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_P;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posi_px =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_I;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_m =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_D;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_n =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_N;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_f =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_I0;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_d =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_D0;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_v_p =
      *rtu_FocInputs_global_configuration_estimation_velocity_est_w;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posi_mw =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_shift_;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_extern =
      *rtu_FocInputs_actuator_configuration_motor_externals_enable_;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_h =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_hal;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h2 =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_qua;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_hs =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_spe;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_i =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_tem;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h5 =
      *rtu_FocInputs_actuator_configuration_motor_externals_encoder;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h1 =
      *rtu_FocInputs_actuator_configuration_motor_externals_pole_pa;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_ig =
      *rtu_FocInputs_actuator_configuration_motor_externals_rotor_e;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_d =
      *rtu_FocInputs_actuator_configuration_motor_externals_rotor_i;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_j =
      *rtu_FocInputs_actuator_configuration_thresholds_jntVelMax;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_a =
      *rtu_FocInputs_actuator_configuration_motor_externals_use_ind;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Kbemf =
      *rtu_FocInputs_actuator_configuration_motor_Kbemf;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Rphase =
      *rtu_FocInputs_actuator_configuration_motor_Rphase;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Imin =
      *rtu_FocInputs_actuator_configuration_motor_Imin;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Imax =
      *rtu_FocInputs_actuator_configuration_motor_Imax;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Vmax =
      *rtu_FocInputs_actuator_configuration_motor_Vmax;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_resist =
      *rtu_FocInputs_actuator_configuration_motor_resistance;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_induct =
      *rtu_FocInputs_actuator_configuration_motor_inductance;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_therma =
      *rtu_FocInputs_actuator_configuration_motor_thermal_resistanc;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ther_h =
      *rtu_FocInputs_actuator_configuration_motor_thermal_time_cons;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_m =
      *rtu_FocInputs_actuator_configuration_thresholds_motorNominal;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_hall_s =
      *rtu_FocInputs_actuator_configuration_motor_hall_sensors_offs;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_refere =
      *rtu_FocInputs_actuator_configuration_motor_reference_encoder;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_rotor_velocity =
      *rtu_FocInputs_estimated_data_rotor_velocity;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_Iq_filtered =
      *rtu_FocInputs_estimated_data_Iq_filtered;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_motor_temperature =
      *rtu_FocInputs_estimated_data_motor_temperature;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_joint_velocity =
      *rtu_FocInputs_estimated_data_joint_velocity;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_position = *rtu_FocInputs_targets_position;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_velocity = *rtu_FocInputs_targets_velocity;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_current = *rtu_FocInputs_targets_current;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_voltage = *rtu_FocInputs_targets_voltage;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_g =
      *rtu_FocInputs_actuator_configuration_thresholds_motorPeakCur;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_vel_en =
      *rtu_FocInputs_control_outer_outputs_vel_en;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_cur_en =
      *rtu_FocInputs_control_outer_outputs_cur_en;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_out_en =
      *rtu_FocInputs_control_outer_outputs_out_en;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_pid_reset =
      *rtu_FocInputs_control_outer_outputs_pid_reset;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_motorcurrent =
      *rtu_FocInputs_control_outer_outputs_motorcurrent;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_current_limit =
      *rtu_FocInputs_control_outer_outputs_current_limiter;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_threshold_m2 =
      *rtu_FocInputs_actuator_configuration_thresholds_motorOverloa;

    // SignalConversion generated from: '<S1>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_p =
      *rtu_FocInputs_actuator_configuration_thresholds_motorPwmLimi;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem2'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S2>/Action Port'

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_cur_en = true;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_out_en = true;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    Vcc = *rtu_Sensors_driversensors_Vcc;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    current = *rtu_Sensors_motorsensors_current;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    hallABC = *rtu_Sensors_motorsensors_hallABC;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    offset = localB->offset_d;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    rotor_angle = *rtu_Sensors_motorsensors_qencoder_rotor_angle;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    counter = *rtu_Sensors_motorsensors_qencoder_counter;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    Idx_counter = *rtu_Sensors_motorsensors_qencoder_Idx_counter;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    electrical_angle = localB->target_angle;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    temperature = *rtu_Sensors_motorsensors_temperature;

    // Merge generated from: '<Root>/Merge1' incorporates:
    //   SignalConversion generated from: '<S2>/SensorDataCalibration'

    voltage = *rtu_Sensors_motorsensors_voltage;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_env =
      *rtu_FocInputs_global_configuration_estimation_environment_te;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_i =
      *rtu_FocInputs_actuator_configuration_thresholds_motorCritica;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_current =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_type;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_p =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMax;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_o =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMin;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_e =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_P;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_m =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_I;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_j =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_D;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curr_po =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_N;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curr_m3 =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_I0;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curr_p2 =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_D0;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_cur =
      *rtu_FocInputs_global_configuration_estimation_current_rms_la;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_curre_i =
      *rtu_FocInputs_actuator_configuration_pids_currentPID_shift_f;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_velocit =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_type;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_h =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMax;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_b =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMin;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_n =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_P;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_g =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_I;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_velo_go =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_D;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_e =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_N;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_k =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_I0;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_velo_bn =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_D0;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_vel =
      *rtu_FocInputs_global_configuration_estimation_velocity_est_m;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_veloc_c =
      *rtu_FocInputs_actuator_configuration_pids_velocityPID_shift_;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_positio =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_type;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_p =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMax;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posi_py =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMin;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_e =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_P;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posi_px =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_I;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_m =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_D;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_n =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_N;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_f =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_I0;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posit_d =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_D0;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_global_configuration_estimation_v_p =
      *rtu_FocInputs_global_configuration_estimation_velocity_est_w;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_pids_posi_mw =
      *rtu_FocInputs_actuator_configuration_pids_positionPID_shift_;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_extern =
      *rtu_FocInputs_actuator_configuration_motor_externals_enable_;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_h =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_hal;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h2 =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_qua;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_hs =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_spe;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_i =
      *rtu_FocInputs_actuator_configuration_motor_externals_has_tem;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h5 =
      *rtu_FocInputs_actuator_configuration_motor_externals_encoder;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_h1 =
      *rtu_FocInputs_actuator_configuration_motor_externals_pole_pa;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ext_ig =
      *rtu_FocInputs_actuator_configuration_motor_externals_rotor_e;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_d =
      *rtu_FocInputs_actuator_configuration_motor_externals_rotor_i;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_j =
      *rtu_FocInputs_actuator_configuration_thresholds_jntVelMax;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_exte_a =
      *rtu_FocInputs_actuator_configuration_motor_externals_use_ind;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Kbemf =
      *rtu_FocInputs_actuator_configuration_motor_Kbemf;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Rphase =
      *rtu_FocInputs_actuator_configuration_motor_Rphase;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Imin =
      *rtu_FocInputs_actuator_configuration_motor_Imin;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Imax =
      *rtu_FocInputs_actuator_configuration_motor_Imax;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_Vmax =
      *rtu_FocInputs_actuator_configuration_motor_Vmax;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_resist =
      *rtu_FocInputs_actuator_configuration_motor_resistance;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_induct =
      *rtu_FocInputs_actuator_configuration_motor_inductance;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_therma =
      *rtu_FocInputs_actuator_configuration_motor_thermal_resistanc;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_ther_h =
      *rtu_FocInputs_actuator_configuration_motor_thermal_time_cons;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_m =
      *rtu_FocInputs_actuator_configuration_thresholds_motorNominal;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_hall_s =
      *rtu_FocInputs_actuator_configuration_motor_hall_sensors_offs;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_motor_refere =
      *rtu_FocInputs_actuator_configuration_motor_reference_encoder;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_rotor_velocity =
      *rtu_FocInputs_estimated_data_rotor_velocity;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_Iq_filtered =
      *rtu_FocInputs_estimated_data_Iq_filtered;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_motor_temperature =
      *rtu_FocInputs_estimated_data_motor_temperature;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_estimated_data_joint_velocity =
      *rtu_FocInputs_estimated_data_joint_velocity;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_position = *rtu_FocInputs_targets_position;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_velocity = *rtu_FocInputs_targets_velocity;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_current = *rtu_FocInputs_targets_current;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_targets_voltage = *rtu_FocInputs_targets_voltage;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_g =
      *rtu_FocInputs_actuator_configuration_thresholds_motorPeakCur;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_vel_en =
      *rtu_FocInputs_control_outer_outputs_vel_en;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_pid_reset =
      *rtu_FocInputs_control_outer_outputs_pid_reset;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_motorcurrent =
      localB->Iq_ref;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_control_outer_outputs_current_limit =
      *rtu_FocInputs_control_outer_outputs_current_limiter;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_threshold_m2 =
      *rtu_FocInputs_actuator_configuration_thresholds_motorOverloa;

    // SignalConversion generated from: '<S2>/FocInputsCalibration'
    *rty_FocInputsCalibration_actuator_configuration_thresholds_p =
      *rtu_FocInputs_actuator_configuration_thresholds_motorPwmLimi;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem3'
  }

  // End of SwitchCase: '<Root>/Switch Case1'

  // RateTransition generated from: '<Root>/Merge1'
  rtw_mutex_lock();
  wrBufIdx = static_cast<int8_T>(localDW->Iabc_LstBufWR + 1);
  if (wrBufIdx == 3) {
    wrBufIdx = 0;
  }

  if (wrBufIdx == localDW->Iabc_RDBuf) {
    wrBufIdx = static_cast<int8_T>(wrBufIdx + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }
  }

  rtw_mutex_unlock();
  tmp_1 = wrBufIdx * 3;
  localDW->Iabc_Buf[tmp_1] = rtu_Sensors_motorsensors_Iabc[0];
  localDW->Iabc_Buf[tmp_1 + 1] = rtu_Sensors_motorsensors_Iabc[1];
  localDW->Iabc_Buf[tmp_1 + 2] = rtu_Sensors_motorsensors_Iabc[2];
  localDW->Iabc_LstBufWR = wrBufIdx;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->Idx_counter_Buffer0 = Idx_counter;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->Vcc_Buffer0 = Vcc;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->counter_Buffer0 = counter;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->current_Buffer0 = current;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->electrical_angle_Buffer0 = electrical_angle;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->hallABC_Buffer0 = hallABC;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->offset_Buffer0 = offset;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->rotor_angle_Buffer0 = rotor_angle;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->temperature_Buffer0 = temperature;

  // RateTransition generated from: '<Root>/Merge1'
  localDW->voltage_Buffer0 = voltage;

  // Update for Delay: '<S3>/Delay'
  localDW->Delay_DSTATE[localDW->CircBufIdx] = rtb_AlgoDataType;
  if (localDW->CircBufIdx < 298U) {
    localDW->CircBufIdx++;
  } else {
    localDW->CircBufIdx = 0U;
  }

  // End of Update for Delay: '<S3>/Delay'
}

// Termination for referenced model: 'Calibrator'
void Calibrator_Term(void)
{
	return;
  // Terminate for RateTransition generated from: '<Root>/Merge1'
  rtw_mutex_destroy();
}

//
// File trailer for generated code.
//
// [EOF]
//
