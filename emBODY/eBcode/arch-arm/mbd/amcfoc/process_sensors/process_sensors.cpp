//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: process_sensors.cpp
//
// Code generated for Simulink model 'process_sensors'.
//
// Model version                  : 1.8
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Tue Jul 29 11:49:09 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "process_sensors.h"
#include "rtwtypes.h"
#include "process_sensors_types.h"
#include <cmath>
#include "rt_remf.h"
#include "zero_crossing_types.h"

// Output and update for referenced model: 'process_sensors'
void process_sensors(const boolean_T *rtu_calibDone, const SensorsData
                     *rtu_SensorData, const ActuatorConfiguration
                     *rtu_ActuatorConfig, SensorsData *rty_SensorData_decoded,
                     B_process_sensors_c_T *localB, DW_process_sensors_f_T
                     *localDW, ZCE_process_sensors_T *localZCE)
{
  real32_T rtb_Rem;
  real32_T rtb_Switch1;

  // BusAssignment: '<Root>/Bus Assignment'
  *rty_SensorData_decoded = *rtu_SensorData;

  // Outputs for Triggered SubSystem: '<Root>/Sample and Hold' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  // UnitDelay: '<Root>/Unit Delay1'
  if (localDW->UnitDelay1_DSTATE && (localZCE->SampleandHold_Trig_ZCE !=
       POS_ZCSIG)) {
    // SignalConversion generated from: '<S2>/In'
    localB->In_b = rtu_SensorData->motorsensors.qencoder.Idx_counter;
  }

  localZCE->SampleandHold_Trig_ZCE = localDW->UnitDelay1_DSTATE;

  // End of Outputs for SubSystem: '<Root>/Sample and Hold'

  // Outputs for Triggered SubSystem: '<Root>/Sample and Hold1' incorporates:
  //   TriggerPort: '<S3>/Trigger'

  if (localDW->UnitDelay1_DSTATE && (localZCE->SampleandHold1_Trig_ZCE !=
       POS_ZCSIG)) {
    // SignalConversion generated from: '<S3>/In' incorporates:
    //   Constant: '<Root>/One'

    localB->In = 1.0F;
  }

  // Outputs for Triggered SubSystem: '<Root>/Sample and Hold' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  localZCE->SampleandHold1_Trig_ZCE = localDW->UnitDelay1_DSTATE;

  // End of UnitDelay: '<Root>/Unit Delay1'
  // End of Outputs for SubSystem: '<Root>/Sample and Hold'
  // End of Outputs for SubSystem: '<Root>/Sample and Hold1'

  // Switch: '<Root>/Switch1' incorporates:
  //   Sum: '<Root>/Add'
  //   Sum: '<Root>/Add2'

  if (localB->In > 0.0F) {
    rtb_Switch1 = rtu_SensorData->motorsensors.qencoder.counter - localB->In_b;
  } else {
    rtb_Switch1 = rtu_SensorData->motorsensors.qencoder.counter -
      rtu_SensorData->motorsensors.qencoder.Idx_counter;
  }

  // End of Switch: '<Root>/Switch1'

  // If: '<S6>/If' incorporates:
  //   Constant: '<S8>/Constant'
  //   Product: '<S11>/Product'
  //   Sum: '<S8>/Add'
  //   Sum: '<S9>/Add'
  //   Switch: '<S5>/Switch'

  if (rtb_Switch1 <= rtu_ActuatorConfig->motor.externals.rotor_index_offset) {
    // Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
    //   ActionPort: '<S8>/Action Port'

    rtb_Rem = (rtb_Switch1 + 360.0F) - static_cast<real32_T>
      (rtu_ActuatorConfig->motor.externals.rotor_index_offset);

    // End of Outputs for SubSystem: '<S6>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S9>/Action Port'

    rtb_Rem = rtb_Switch1 - static_cast<real32_T>
      (rtu_ActuatorConfig->motor.externals.rotor_index_offset);

    // End of Outputs for SubSystem: '<S6>/If Action Subsystem1'
  }

  rtb_Rem *= static_cast<real32_T>
    (rtu_ActuatorConfig->motor.externals.pole_pairs);

  // End of If: '<S6>/If'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Gain: '<S7>/Multiply'
  //   Gain: '<S7>/Multiply1'
  //   Math: '<Root>/Rem'
  //   Rounding: '<S7>/Floor'
  //   Sum: '<S7>/Add'

  rty_SensorData_decoded->motorsensors.electrical_angle = rt_remf(rtb_Rem - std::
    floor(0.00277777785F * rtb_Rem) * 360.0F, 360.0F);
  rty_SensorData_decoded->motorsensors.qencoder.rotor_angle = rtb_Switch1;

  // Switch: '<Root>/Switch'
  if (!rtu_ActuatorConfig->motor.externals.has_quadrature_encoder) {
    *rty_SensorData_decoded = *rtu_SensorData;
  }

  // End of Switch: '<Root>/Switch'

  // Update for UnitDelay: '<Root>/Unit Delay1'
  localDW->UnitDelay1_DSTATE = *rtu_calibDone;
}

// Model initialize function
void process_sensors_initialize(ZCE_process_sensors_T *localZCE)
{
  localZCE->SampleandHold_Trig_ZCE = POS_ZCSIG;
  localZCE->SampleandHold1_Trig_ZCE = POS_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
