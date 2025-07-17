//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Calibrator.cpp
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
#include "Calibrator.h"
#include "Calibrator_types.h"
#include "rtwtypes.h"
#include <cmath>

#include "embot_core.h"

// Named constants for Chart: '<S2>/calibrator'
const uint8_T Calibrator_IN_Finish = 1U;
const uint8_T Calibrator_IN_Idx_found = 2U;
const uint8_T Calibrator_IN_Read_0_encoder = 3U;
const uint8_T Calibrator_IN_Search_idx = 4U;
const uint8_T Calibrator_IN_Zero_electric = 5U;
const uint8_T Calibrator_IN_velocity_check = 6U;

// System initialize for referenced model: 'Calibrator'
void Calibrator_Init(DW_Calibrator_f_T *localDW)
{
  // Start for SwitchCase: '<Root>/Switch Case1'
  localDW->SwitchCase1_ActiveSubsystem = -1;
}

// Disable for referenced model: 'Calibrator'
void Calibrator_Disable(DW_Calibrator_f_T *localDW)
{
  // Disable for SwitchCase: '<Root>/Switch Case1'
  localDW->SwitchCase1_ActiveSubsystem = -1;
}

// Output and update for referenced model: 'Calibrator'
void Calibrator(const Flags *rtu_Flags, const SensorsData *rtu_Sensors, const
                FOCSlowInputs *rtu_FocInputs, const ActuatorConfiguration
                *rtu_ActuatorCfg, boolean_T *rty_CalibrationDone, SensorsData
                *rty_SensorDataCalibration, FOCSlowInputs
                *rty_FocInputsCalibration, B_Calibrator_c_T *localB,
                DW_Calibrator_f_T *localDW)
{
  // SwitchCase: '<Root>/Switch Case1'
  if (rtu_Flags->calibration_type == CalibrationTypes_None) {
    localDW->SwitchCase1_ActiveSubsystem = 0;
  } else {
    localDW->SwitchCase1_ActiveSubsystem = 1;
  }

  if (localDW->SwitchCase1_ActiveSubsystem == 0) {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // SignalConversion generated from: '<S1>/Sensors_Inport_1'
    *rty_SensorDataCalibration = *rtu_Sensors;

    // SignalConversion generated from: '<S1>/FocInputs'
    *rty_FocInputsCalibration = *rtu_FocInputs;

    // SignalConversion generated from: '<S1>/CalibrationDone' incorporates:
    //   Constant: '<S1>/Constant'

    *rty_CalibrationDone = true;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem2'
  } else {
    uint32_T rtb_AlgoDataType;

    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S2>/Action Port'

    // BusAssignment: '<S2>/Bus Assignment1'
    *rty_FocInputsCalibration = *rtu_FocInputs;

    // BusAssignment: '<S2>/Bus Assignment'
    *rty_SensorDataCalibration = *rtu_Sensors;

    // DataTypeConversion: '<S3>/AlgoDataType' incorporates:
    //   Constant: '<S3>/PositionToCount'
    //   Product: '<S3>/Product'

    rtb_AlgoDataType = static_cast<uint32_T>(1.1930465E+7F *
      rtu_Sensors->motorsensors.qencoder.rotor_angle);

    // Chart: '<S2>/calibrator'
    if (localDW->temporalCounter_i1 < MAX_uint32_T) {
      localDW->temporalCounter_i1++;
    }

    if (localDW->is_active_c1_Calibrator == 0) {
      localDW->is_active_c1_Calibrator = 1U;
      localDW->is_c1_Calibrator = Calibrator_IN_Zero_electric;
      localB->finish = false;
      localDW->p_index = rtu_Sensors->motorsensors.qencoder.Idx_counter;
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
      switch (localDW->is_c1_Calibrator) {
       case Calibrator_IN_Finish:
        localB->Iq_ref = 0.0F;
        break;

       case Calibrator_IN_Idx_found:
        localDW->condition = 4.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c1_Calibrator = Calibrator_IN_velocity_check;
        localB->Iq_ref = rtu_ActuatorCfg->thresholds.motorNominalCurrents;
        break;

       case Calibrator_IN_Read_0_encoder:
        localB->finish = true;
        localDW->is_c1_Calibrator = Calibrator_IN_Finish;
        localB->Iq_ref = 0.0F;
        break;

       case Calibrator_IN_Search_idx:
        if (localDW->count == 360.0F) {
          localDW->is_c1_Calibrator = Calibrator_IN_Zero_electric;
          localB->finish = false;
          localDW->p_index = rtu_Sensors->motorsensors.qencoder.Idx_counter;
          localDW->diff_index = 0.0F;
          localDW->tzeroalign = 0.7;
          localDW->talign = 0.1;
          localDW->v_threshold = 2.0;
          localDW->count = 0.0F;
          localB->target_angle = 0.0F;
        } else if ((localDW->diff_index != 0.0F) && (rtu_Flags->calibration_type
                    == CalibrationTypes_Search_Index)) {
          localB->finish = true;
          localDW->is_c1_Calibrator = Calibrator_IN_Finish;
          localB->Iq_ref = 0.0F;
        } else {
          localDW->condition = 2.0;
          localDW->temporalCounter_i1 = 0U;
          localDW->is_c1_Calibrator = Calibrator_IN_velocity_check;
          localB->Iq_ref = rtu_ActuatorCfg->thresholds.motorNominalCurrents;
        }
        break;

       case Calibrator_IN_Zero_electric:
        if (rtu_Flags->calibration_type != CalibrationTypes_None) {
          localDW->condition = 1.0;
          localDW->temporalCounter_i1 = 0U;
          localDW->is_c1_Calibrator = Calibrator_IN_velocity_check;
          localB->Iq_ref = rtu_ActuatorCfg->thresholds.motorNominalCurrents;
        }
        break;

       default:
        {
          // case IN_velocity_check:
          if ((localDW->diff_index != 0.0F) && (rtu_Flags->calibration_type ==
               CalibrationTypes_Full_Calibration) && (localDW->condition == 2.0))
          {
            localDW->condition = 3.0;
            guard1 = true;
          } else if (std::abs(static_cast<real32_T>(static_cast<int32_T>
                       (rtb_AlgoDataType) - static_cast<int32_T>
                       (localDW->Delay_DSTATE[localDW->CircBufIdx])) *
                              4.66828368E-7F) > localDW->v_threshold) {
            guard1 = true;
          } else {
            real_T tmp_0;
            tmp_0 = std::ceil(localDW->tzeroalign / 4.5E-5 -
                              4.5000000000000005E-13);
            if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>(tmp_0)) &&
                (localDW->condition == 1.0)) {
              guard2 = true;
            } else {
              real_T tmp;
              tmp = std::ceil(localDW->talign / 4.5E-5 - 4.5000000000000005E-13);
              if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>(tmp)) &&
                  (localDW->condition == 2.0)) {
                guard2 = true;
              } else if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>
                          (tmp)) && (localDW->condition == 3.0)) {
                localDW->is_c1_Calibrator = Calibrator_IN_Idx_found;
                localB->Iq_ref =
                  rtu_ActuatorCfg->thresholds.motorNominalCurrents;
                localB->target_angle = 0.0F;
              } else if ((localDW->temporalCounter_i1 >= static_cast<uint32_T>
                          (tmp_0)) && (localDW->condition == 4.0)) {
                localDW->is_c1_Calibrator = Calibrator_IN_Read_0_encoder;
                localB->offset = rtu_Sensors->motorsensors.qencoder.rotor_angle
                  + 90.0F;
                if (localB->offset > 360.0F) {
                  localB->offset -= 360.0F;
                }
              } else {
                localB->Iq_ref =
                  rtu_ActuatorCfg->thresholds.motorNominalCurrents;
              }
            }
          }
        }
        break;
      }

      if (guard2) {
        localDW->is_c1_Calibrator = Calibrator_IN_Search_idx;
        localDW->count++;
        localB->target_angle = localDW->count;
        localDW->diff_index = rtu_Sensors->motorsensors.qencoder.Idx_counter -
          localDW->p_index;
        if (localDW->diff_index != 0.0F) {
          localDW->p_index = rtu_Sensors->motorsensors.qencoder.Idx_counter;
        }
      }

      if (guard1) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c1_Calibrator = Calibrator_IN_velocity_check;
        localB->Iq_ref = rtu_ActuatorCfg->thresholds.motorNominalCurrents;
      }
    }

    // End of Chart: '<S2>/calibrator'

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   Constant: '<S2>/Constant'

    rty_FocInputsCalibration->control_outer_outputs.motorcurrent =
      localB->Iq_ref;
    rty_FocInputsCalibration->control_outer_outputs.cur_en = true;
    rty_FocInputsCalibration->control_outer_outputs.out_en = true;

    // BusAssignment: '<S2>/Bus Assignment'
    rty_SensorDataCalibration->motorsensors.electrical_angle =
      localB->target_angle;
    rty_SensorDataCalibration->motorsensors.qencoder.offset = localB->offset;
		
		static bool hasPrinted = false;
		
		if(localB->finish && !hasPrinted)
		{
			hasPrinted = true;
			embot::core::print("OFFSET: "  + std::to_string(localB->offset) + 
												 "TG ANGLE: "  + std::to_string(localB->target_angle));
			
		}
		
    // SignalConversion generated from: '<S2>/CalibrationDone'
    *rty_CalibrationDone = localB->finish;

    // Update for Delay: '<S3>/Delay'
    localDW->Delay_DSTATE[localDW->CircBufIdx] = rtb_AlgoDataType;
    if (localDW->CircBufIdx < 664U) {
      localDW->CircBufIdx++;
    } else {
      localDW->CircBufIdx = 0U;
    }

    // End of Update for Delay: '<S3>/Delay'
    // End of Outputs for SubSystem: '<Root>/If Action Subsystem3'
  }

  // End of SwitchCase: '<Root>/Switch Case1'
}

//
// File trailer for generated code.
//
// [EOF]
//
