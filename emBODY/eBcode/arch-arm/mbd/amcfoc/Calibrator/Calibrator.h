//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Calibrator.h
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
#ifndef Calibrator_h_
#define Calibrator_h_
#include "rtwtypes.h"
#include "Calibrator_types.h"

// Block signals for model 'Calibrator'
struct B_Calibrator_c_T {
  real32_T offset_d;                   // '<Root>/calibrator'
  real32_T target_angle;               // '<Root>/calibrator'
  real32_T Iq_ref;                     // '<Root>/calibrator'
};

// Block states (default storage) for model 'Calibrator'
struct DW_Calibrator_f_T {
  real_T condition;                    // '<Root>/calibrator'
  real_T talign;                       // '<Root>/calibrator'
  real_T tzeroalign;                   // '<Root>/calibrator'
  real_T v_threshold;                  // '<Root>/calibrator'
  void* Iabc_SEMAPHORE;                // synthesized block
  uint32_T Delay_DSTATE[299];          // '<S3>/Delay'
  real32_T Iabc_Buf[9];                // synthesized block
  volatile real32_T Idx_counter_Buffer0;// synthesized block
  volatile real32_T Vcc_Buffer0;       // synthesized block
  volatile real32_T counter_Buffer0;   // synthesized block
  volatile real32_T current_Buffer0;   // synthesized block
  volatile real32_T electrical_angle_Buffer0;// synthesized block
  volatile real32_T offset_Buffer0;    // synthesized block
  volatile real32_T rotor_angle_Buffer0;// synthesized block
  volatile real32_T temperature_Buffer0;// synthesized block
  volatile real32_T voltage_Buffer0;   // synthesized block
  real32_T count;                      // '<Root>/calibrator'
  real32_T p_index;                    // '<Root>/calibrator'
  real32_T diff_index;                 // '<Root>/calibrator'
  uint32_T CircBufIdx;                 // '<S3>/Delay'
  uint32_T temporalCounter_i1;         // '<Root>/calibrator'
  int8_T Iabc_LstBufWR;                // synthesized block
  int8_T Iabc_RDBuf;                   // synthesized block
  volatile uint8_T hallABC_Buffer0;    // synthesized block
  uint8_T is_active_c2_Calibrator;     // '<Root>/calibrator'
  uint8_T is_c2_Calibrator;            // '<Root>/calibrator'
};

struct MdlrefDW_Calibrator_T {
  B_Calibrator_c_T rtb;
  DW_Calibrator_f_T rtdw;
};

extern void Calibrator_Init(void);
extern void CalibratorTID0(real32_T *rty_SensorDataCalibration_driversensors_Vcc,
  real32_T *rty_SensorDataCalibration_motorsensors_qencoder_offset, real32_T
  *rty_SensorDataCalibration_motorsensors_qencoder_rotor_angle, real32_T
  *rty_SensorDataCalibration_motorsensors_qencoder_counter, real32_T
  *rty_SensorDataCalibration_motorsensors_qencoder_Idx_counter, real32_T
  rty_SensorDataCalibration_motorsensors_Iabc[3], real32_T
  *rty_SensorDataCalibration_motorsensors_electrical_angle, real32_T
  *rty_SensorDataCalibration_motorsensors_temperature, real32_T
  *rty_SensorDataCalibration_motorsensors_voltage, real32_T
  *rty_SensorDataCalibration_motorsensors_current, uint8_T
  *rty_SensorDataCalibration_motorsensors_hallABC, DW_Calibrator_f_T *localDW);
extern void CalibratorTID1(const CalibrationTypes *rtu_Flags_calibration_type,
  const real32_T *rtu_Sensors_driversensors_Vcc, const real32_T
  *rtu_Sensors_motorsensors_qencoder_offset, const real32_T
  *rtu_Sensors_motorsensors_qencoder_rotor_angle, const real32_T
  *rtu_Sensors_motorsensors_qencoder_counter, const real32_T
  *rtu_Sensors_motorsensors_qencoder_Idx_counter, const real32_T
  rtu_Sensors_motorsensors_Iabc[3], const real32_T
  *rtu_Sensors_motorsensors_electrical_angle, const real32_T
  *rtu_Sensors_motorsensors_temperature, const real32_T
  *rtu_Sensors_motorsensors_voltage, const real32_T
  *rtu_Sensors_motorsensors_current, const uint8_T
  *rtu_Sensors_motorsensors_hallABC, const real32_T
  *rtu_ActuatorConf_thresholds_motorNominalCurrents, const real32_T
  *rtu_FocInputs_global_configuration_estimation_environment_te, const real32_T *
  rtu_FocInputs_global_configuration_estimation_current_rms_la, const
  EstimationVelocityModes
  *rtu_FocInputs_global_configuration_estimation_velocity_est_m, const uint32_T *
  rtu_FocInputs_global_configuration_estimation_velocity_est_w, const real32_T
  *rtu_FocInputs_actuator_configuration_thresholds_jntVelMax, const real32_T
  *rtu_FocInputs_actuator_configuration_thresholds_motorNominal, const real32_T *
  rtu_FocInputs_actuator_configuration_thresholds_motorPeakCur, const real32_T
  *rtu_FocInputs_actuator_configuration_thresholds_motorOverloa, const uint32_T *
  rtu_FocInputs_actuator_configuration_thresholds_motorPwmLimi, const real32_T
  *rtu_FocInputs_actuator_configuration_thresholds_motorCritica, const
  ControlModes *rtu_FocInputs_actuator_configuration_pids_currentPID_type, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMax, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_OutMin, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_P, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_I, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_D, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_N, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_I0, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_currentPID_D0, const
  uint8_T *rtu_FocInputs_actuator_configuration_pids_currentPID_shift_f, const
  ControlModes *rtu_FocInputs_actuator_configuration_pids_velocityPID_type,
  const real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMax,
  const real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_OutMin,
  const real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_P, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_I, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_D, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_N, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_I0, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_D0, const
  uint8_T *rtu_FocInputs_actuator_configuration_pids_velocityPID_shift_, const
  ControlModes *rtu_FocInputs_actuator_configuration_pids_positionPID_type,
  const real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMax,
  const real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_OutMin,
  const real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_P, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_I, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_D, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_N, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_I0, const
  real32_T *rtu_FocInputs_actuator_configuration_pids_positionPID_D0, const
  uint8_T *rtu_FocInputs_actuator_configuration_pids_positionPID_shift_, const
  boolean_T *rtu_FocInputs_actuator_configuration_motor_externals_enable_, const
  boolean_T *rtu_FocInputs_actuator_configuration_motor_externals_has_hal, const
  boolean_T *rtu_FocInputs_actuator_configuration_motor_externals_has_qua, const
  boolean_T *rtu_FocInputs_actuator_configuration_motor_externals_has_spe, const
  boolean_T *rtu_FocInputs_actuator_configuration_motor_externals_has_tem, const
  uint8_T *rtu_FocInputs_actuator_configuration_motor_externals_encoder, const
  uint8_T *rtu_FocInputs_actuator_configuration_motor_externals_pole_pa, const
  int16_T *rtu_FocInputs_actuator_configuration_motor_externals_rotor_e, const
  int16_T *rtu_FocInputs_actuator_configuration_motor_externals_rotor_i, const
  boolean_T *rtu_FocInputs_actuator_configuration_motor_externals_use_ind, const
  real32_T *rtu_FocInputs_actuator_configuration_motor_Kbemf, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_Rphase, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_Imin, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_Imax, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_Vmax, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_resistance, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_inductance, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_thermal_resistanc, const real32_T *
  rtu_FocInputs_actuator_configuration_motor_thermal_time_cons, const real32_T
  *rtu_FocInputs_actuator_configuration_motor_hall_sensors_offs, const
  ReferenceEncoder *rtu_FocInputs_actuator_configuration_motor_reference_encoder,
  const real32_T *rtu_FocInputs_estimated_data_rotor_velocity, const real32_T
  *rtu_FocInputs_estimated_data_Iq_filtered, const real32_T
  *rtu_FocInputs_estimated_data_motor_temperature, const real32_T
  *rtu_FocInputs_estimated_data_joint_velocity, const real32_T
  *rtu_FocInputs_targets_position, const real32_T
  *rtu_FocInputs_targets_velocity, const real32_T *rtu_FocInputs_targets_current,
  const real32_T *rtu_FocInputs_targets_voltage, const boolean_T
  *rtu_FocInputs_control_outer_outputs_vel_en, const boolean_T
  *rtu_FocInputs_control_outer_outputs_cur_en, const boolean_T
  *rtu_FocInputs_control_outer_outputs_out_en, const boolean_T
  *rtu_FocInputs_control_outer_outputs_pid_reset, const real32_T
  *rtu_FocInputs_control_outer_outputs_motorcurrent, const real32_T
  *rtu_FocInputs_control_outer_outputs_current_limiter, boolean_T
  *rty_CalibrationDone, real32_T
  *rty_FocInputsCalibration_global_configuration_estimation_env, real32_T
  *rty_FocInputsCalibration_global_configuration_estimation_cur,
  EstimationVelocityModes
  *rty_FocInputsCalibration_global_configuration_estimation_vel, uint32_T
  *rty_FocInputsCalibration_global_configuration_estimation_v_p, real32_T
  *rty_FocInputsCalibration_actuator_configuration_thresholds_j, real32_T
  *rty_FocInputsCalibration_actuator_configuration_thresholds_m, real32_T
  *rty_FocInputsCalibration_actuator_configuration_thresholds_g, real32_T
  *rty_FocInputsCalibration_actuator_configuration_threshold_m2, uint32_T
  *rty_FocInputsCalibration_actuator_configuration_thresholds_p, real32_T
  *rty_FocInputsCalibration_actuator_configuration_thresholds_i, ControlModes
  *rty_FocInputsCalibration_actuator_configuration_pids_current, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curre_p, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curre_o, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curre_e, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curre_m, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curre_j, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curr_po, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curr_m3, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curr_p2, uint8_T
  *rty_FocInputsCalibration_actuator_configuration_pids_curre_i, ControlModes
  *rty_FocInputsCalibration_actuator_configuration_pids_velocit, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_h, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_b, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_n, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_g, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_velo_go, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_e, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_k, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_velo_bn, uint8_T
  *rty_FocInputsCalibration_actuator_configuration_pids_veloc_c, ControlModes
  *rty_FocInputsCalibration_actuator_configuration_pids_positio, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posit_p, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posi_py, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posit_e, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posi_px, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posit_m, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posit_n, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posit_f, real32_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posit_d, uint8_T
  *rty_FocInputsCalibration_actuator_configuration_pids_posi_mw, boolean_T
  *rty_FocInputsCalibration_actuator_configuration_motor_extern, boolean_T
  *rty_FocInputsCalibration_actuator_configuration_motor_exte_h, boolean_T
  *rty_FocInputsCalibration_actuator_configuration_motor_ext_h2, boolean_T
  *rty_FocInputsCalibration_actuator_configuration_motor_ext_hs, boolean_T
  *rty_FocInputsCalibration_actuator_configuration_motor_exte_i, uint8_T
  *rty_FocInputsCalibration_actuator_configuration_motor_ext_h5, uint8_T
  *rty_FocInputsCalibration_actuator_configuration_motor_ext_h1, int16_T
  *rty_FocInputsCalibration_actuator_configuration_motor_ext_ig, int16_T
  *rty_FocInputsCalibration_actuator_configuration_motor_exte_d, boolean_T
  *rty_FocInputsCalibration_actuator_configuration_motor_exte_a, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_Kbemf, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_Rphase, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_Imin, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_Imax, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_Vmax, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_resist, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_induct, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_therma, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_ther_h, real32_T
  *rty_FocInputsCalibration_actuator_configuration_motor_hall_s,
  ReferenceEncoder *rty_FocInputsCalibration_actuator_configuration_motor_refere,
  real32_T *rty_FocInputsCalibration_estimated_data_rotor_velocity, real32_T
  *rty_FocInputsCalibration_estimated_data_Iq_filtered, real32_T
  *rty_FocInputsCalibration_estimated_data_motor_temperature, real32_T
  *rty_FocInputsCalibration_estimated_data_joint_velocity, real32_T
  *rty_FocInputsCalibration_targets_position, real32_T
  *rty_FocInputsCalibration_targets_velocity, real32_T
  *rty_FocInputsCalibration_targets_current, real32_T
  *rty_FocInputsCalibration_targets_voltage, boolean_T
  *rty_FocInputsCalibration_control_outer_outputs_vel_en, boolean_T
  *rty_FocInputsCalibration_control_outer_outputs_cur_en, boolean_T
  *rty_FocInputsCalibration_control_outer_outputs_out_en, boolean_T
  *rty_FocInputsCalibration_control_outer_outputs_pid_reset, real32_T
  *rty_FocInputsCalibration_control_outer_outputs_motorcurrent, real32_T
  *rty_FocInputsCalibration_control_outer_outputs_current_limit,
  B_Calibrator_c_T *localB, DW_Calibrator_f_T *localDW);
extern void Calibrator_Term(void);

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
//  '<S3>'   : 'Calibrator/Speed Measurement2'
//  '<S4>'   : 'Calibrator/calibrator'
//  '<S5>'   : 'Calibrator/Speed Measurement2/DT_Handle'
//  '<S6>'   : 'Calibrator/Speed Measurement2/DT_Handle/floating-point'

#endif                                 // Calibrator_h_

//
// File trailer for generated code.
//
// [EOF]
//
