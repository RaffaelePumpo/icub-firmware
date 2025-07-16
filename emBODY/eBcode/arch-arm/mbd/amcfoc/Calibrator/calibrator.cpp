//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: calibrator.cpp
//
// Code generated for Simulink model 'calibrator'.
//
// Model version                  : 1.99
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 16 14:12:13 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "calibrator.h"
#include "calibrator_types.h"

// Output and update for referenced model: 'calibrator'
void calibrator(const Flags *rtu_Flags, const SensorsData *rtu_Sensors, const
                FOCSlowInputs *rtu_FocInputs, SensorsData
                *rty_SensorDataCalibration, FOCSlowInputs
                *rty_FocInputsCalibration)
{
  // SwitchCase: '<Root>/Switch Case1'
  if (rtu_Flags->calibration_type == CalibrationTypes_None) {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // SignalConversion generated from: '<S1>/FocInputs'
    *rty_FocInputsCalibration = *rtu_FocInputs;

    // SignalConversion generated from: '<S1>/Sensors_Inport_1'
    *rty_SensorDataCalibration = *rtu_Sensors;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem2'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/If Action Subsystem3' incorporates:
    //   ActionPort: '<S2>/Action Port'

    // BusAssignment: '<S2>/Bus Assignment'
    *rty_SensorDataCalibration = *rtu_Sensors;

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   Constant: '<S2>/Constant'

    *rty_FocInputsCalibration = *rtu_FocInputs;
    rty_FocInputsCalibration->control_outer_outputs.motorcurrent = 0.0F;
    rty_FocInputsCalibration->control_outer_outputs.cur_en = true;
    rty_FocInputsCalibration->control_outer_outputs.out_en = true;

    // BusAssignment: '<S2>/Bus Assignment'
    rty_SensorDataCalibration->motorsensors.electrical_angle = 0.0F;
    rty_SensorDataCalibration->motorsensors.qencoder.offset = 0.0F;

    // End of Outputs for SubSystem: '<Root>/If Action Subsystem3'
  }

  // End of SwitchCase: '<Root>/Switch Case1'
}

//
// File trailer for generated code.
//
// [EOF]
//
