//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: trajectory_planner.cpp
//
// Code generated for Simulink model 'trajectory_planner'.
//
// Model version                  : 2.9
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Mon Sep 22 11:06:24 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "trajectory_planner.h"
#include "trajectory_planner_types.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// System initialize for referenced model: 'trajectory_planner'
void trajectory_planner_Init(B_trajectory_planner_c_T *localB,
  DW_trajectory_planner_f_T *localDW)
{
  // SystemInitialize for Atomic SubSystem: '<Root>/If Action Subsystem'
  // InitializeConditions for DiscreteFilter: '<S5>/Discrete Filter'
  localDW->DiscreteFilter_icLoad = 1U;

  // SystemInitialize for Triggered SubSystem: '<S5>/Compute Coefficients'
  // SystemInitialize for SignalConversion generated from: '<S6>/Den' incorporates:
  //   Outport: '<S6>/Den'

  localB->OutportBufferForDen[0] = 1.0;
  localB->OutportBufferForDen[1] = 0.0;
  localB->OutportBufferForDen[2] = 0.0;
  localB->OutportBufferForDen[3] = 0.0;

  // End of SystemInitialize for SubSystem: '<S5>/Compute Coefficients'
  // End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem'
}

// Output and update for referenced model: 'trajectory_planner'
void trajectory_planner(const Targets *rtu_Targets, const SensorsData
  *rtu_SensorData, Targets *rty_Targets_out, Targets *rty_planner,
  B_trajectory_planner_c_T *localB, DW_trajectory_planner_f_T *localDW,
  ZCE_trajectory_planner_T *localZCE)
{
  real_T rtb_UnitDelay;
  uint8_T rtb_FixPtRelationalOperator;

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // BusAssignment: '<S1>/Bus Assignment'
  *rty_planner = *rtu_Targets;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem1'
  // SignalConversion generated from: '<S2>/Targets'
  *rty_Targets_out = *rtu_Targets;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem1'

  // Outputs for Atomic SubSystem: '<Root>/If Action Subsystem'
  // UnitDelay: '<S5>/Unit Delay'
  rtb_UnitDelay = localDW->UnitDelay_DSTATE;

  // RelationalOperator: '<S8>/FixPt Relational Operator' incorporates:
  //   UnitDelay: '<S5>/Unit Delay'
  //   UnitDelay: '<S8>/Delay Input1'
  //
  //  Block description for '<S8>/Delay Input1':
  //
  //   Store in Global RAM

  rtb_FixPtRelationalOperator = (localDW->UnitDelay_DSTATE !=
    localDW->DelayInput1_DSTATE);

  // Outputs for Triggered SubSystem: '<S5>/Compute Coefficients' incorporates:
  //   TriggerPort: '<S6>/Trigger'

  if ((rtb_FixPtRelationalOperator > 0) &&
      (localZCE->ComputeCoefficients_Trig_ZCE != POS_ZCSIG)) {
    real_T Divide9_tmp;
    real_T Divide9_tmp_0;
    real_T rtb_Divide8;
    real_T rtb_Fcn4;
    real_T rtb_Sum;

    // Math: '<S6>/Square' incorporates:
    //   UnitDelay: '<S5>/Unit Delay'

    rtb_Sum = localDW->UnitDelay_DSTATE * localDW->UnitDelay_DSTATE;

    // Product: '<S6>/Divide6' incorporates:
    //   Constant: '<S6>/Constant1'
    //   Constant: '<S6>/Constant7'
    //   Product: '<S6>/Divide'
    //   UnitDelay: '<S5>/Unit Delay'
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    localDW->DelayInput1_DSTATE = -150.765868956161 / localDW->UnitDelay_DSTATE /
      rtb_Sum * 1.0E-9;

    // Product: '<S6>/Divide4' incorporates:
    //   Constant: '<S6>/Constant'
    //   Constant: '<S6>/Constant3'
    //   Product: '<S6>/Divide2'
    //   UnitDelay: '<S5>/Unit Delay'

    rtb_Divide8 = -15.9669610709384 / localDW->UnitDelay_DSTATE * 0.004;

    // Product: '<S6>/Divide5' incorporates:
    //   Constant: '<S6>/Constant2'
    //   Constant: '<S6>/Constant6'
    //   Product: '<S6>/Divide1'

    rtb_Sum = -84.9812819469538 / rtb_Sum * 2.0E-6;

    // Fcn: '<S6>/Fcn4' incorporates:
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_Fcn4 = ((rtb_Divide8 + rtb_Sum) + localDW->DelayInput1_DSTATE) - 8.0;

    // Product: '<S6>/Divide9' incorporates:
    //   Gain: '<S6>/Gain1'
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    Divide9_tmp_0 = localDW->DelayInput1_DSTATE / rtb_Fcn4;

    // Product: '<S6>/Divide9'
    localB->Divide9[0] = Divide9_tmp_0;

    // Product: '<S6>/Divide9' incorporates:
    //   Gain: '<S6>/Gain1'
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    Divide9_tmp = 3.0 * localDW->DelayInput1_DSTATE / rtb_Fcn4;

    // Product: '<S6>/Divide9'
    localB->Divide9[1] = Divide9_tmp;
    localB->Divide9[2] = Divide9_tmp;
    localB->Divide9[3] = Divide9_tmp_0;

    // SignalConversion generated from: '<S6>/Den' incorporates:
    //   Constant: '<S6>/Constant4'

    localB->OutportBufferForDen[0] = 1.0;

    // Fcn: '<S6>/Fcn1' incorporates:
    //   Fcn: '<S6>/Fcn2'
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    Divide9_tmp_0 = 3.0 * localDW->DelayInput1_DSTATE;

    // SignalConversion generated from: '<S6>/Den' incorporates:
    //   Fcn: '<S6>/Fcn1'
    //   Fcn: '<S6>/Fcn2'
    //   Fcn: '<S6>/Fcn3'
    //   Product: '<S6>/Divide3'
    //   Product: '<S6>/Divide7'
    //   Product: '<S6>/Divide8'
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    localB->OutportBufferForDen[1] = (((-rtb_Divide8 + rtb_Sum) + Divide9_tmp_0)
      + 24.0) / rtb_Fcn4;
    localB->OutportBufferForDen[2] = (((-rtb_Divide8 - rtb_Sum) + Divide9_tmp_0)
      - 24.0) / rtb_Fcn4;
    localB->OutportBufferForDen[3] = (((rtb_Divide8 - rtb_Sum) +
      localDW->DelayInput1_DSTATE) + 8.0) / rtb_Fcn4;
  }

  localZCE->ComputeCoefficients_Trig_ZCE = (rtb_FixPtRelationalOperator > 0);

  // End of Outputs for SubSystem: '<S5>/Compute Coefficients'

  // Outputs for Triggered SubSystem: '<S5>/Compute Init State' incorporates:
  //   TriggerPort: '<S7>/Trigger'

  // UnitDelay: '<S5>/Unit Delay1'
  if (localDW->UnitDelay1_DSTATE && (localZCE->ComputeInitState_Trig_ZCE !=
       POS_ZCSIG)) {
    // Sum: '<S7>/Sum of Elements'
    localDW->DelayInput1_DSTATE = (localB->OutportBufferForDen[1] +
      localB->OutportBufferForDen[2]) + localB->OutportBufferForDen[3];

    // Product: '<S7>/Product1' incorporates:
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    localDW->DelayInput1_DSTATE *= localB->Divide9[0];

    // Product: '<S7>/Product2' incorporates:
    //   Constant: '<S7>/Constant'
    //   DataTypeConversion: '<S1>/Cast To Double2'
    //   Sum: '<S7>/Sum'
    //   Sum: '<S7>/Sum of Elements1'
    //   Sum: '<S7>/Sum1'
    //   UnitDelay: '<S8>/Delay Input1'
    //
    //  Block description for '<S8>/Delay Input1':
    //
    //   Store in Global RAM

    localB->Product2 = 1.0 / (((localB->Divide9[1] + localB->Divide9[2]) +
      localB->Divide9[3]) - localDW->DelayInput1_DSTATE) * (1.0 -
      localB->Divide9[0]) * rtu_SensorData->motorsensors.qencoder.rotor_angle;
  }

  localZCE->ComputeInitState_Trig_ZCE = localDW->UnitDelay1_DSTATE;

  // End of Outputs for SubSystem: '<S5>/Compute Init State'

  // DiscreteFilter: '<S5>/Discrete Filter' incorporates:
  //   DataTypeConversion: '<S1>/Cast To Double'
  //   UnitDelay: '<S5>/Unit Delay1'

  if (localDW->UnitDelay1_DSTATE && (localZCE->DiscreteFilter_Reset_ZCE !=
       POS_ZCSIG)) {
    localDW->DiscreteFilter_icLoad = 1U;
  }

  // Outputs for Triggered SubSystem: '<S5>/Compute Init State' incorporates:
  //   TriggerPort: '<S7>/Trigger'

  localZCE->DiscreteFilter_Reset_ZCE = localDW->UnitDelay1_DSTATE;

  // End of Outputs for SubSystem: '<S5>/Compute Init State'
  if (localDW->DiscreteFilter_icLoad != 0) {
    localDW->DiscreteFilter_states[0] = localB->Product2;
    localDW->DiscreteFilter_states[1] = localB->Product2;
    localDW->DiscreteFilter_states[2] = localB->Product2;
  }

  localDW->DiscreteFilter_tmp = ((rtu_Targets->position -
    localDW->DiscreteFilter_states[0] * localB->OutportBufferForDen[1]) -
    localDW->DiscreteFilter_states[1] * localB->OutportBufferForDen[2]) -
    localDW->DiscreteFilter_states[2] * localB->OutportBufferForDen[3];

  // BusAssignment: '<S1>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S1>/Cast To Single'
  //   DiscreteFilter: '<S5>/Discrete Filter'

  rty_planner->position = static_cast<real32_T>(((localB->Divide9[0] *
    localDW->DiscreteFilter_tmp + localDW->DiscreteFilter_states[0] *
    localB->Divide9[1]) + localDW->DiscreteFilter_states[1] * localB->Divide9[2])
    + localDW->DiscreteFilter_states[2] * localB->Divide9[3]+0.1);

//	rty_planner->position = rtu_SensorData->motorsensors.qencoder.rotor_angle ;
  // Logic: '<S1>/OR' incorporates:
  //   RelationalOperator: '<S3>/FixPt Relational Operator'
  //   RelationalOperator: '<S4>/FixPt Relational Operator'
  //   UnitDelay: '<S3>/Delay Input1'
  //   UnitDelay: '<S4>/Delay Input1'
  //   UnitDelay: '<S5>/Unit Delay1'
  //
  //  Block description for '<S3>/Delay Input1':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S4>/Delay Input1':
  //
  //   Store in Global RAM

  localDW->UnitDelay1_DSTATE = ((1 !=
    localDW->DelayInput1_DSTATE_n) || (rtu_Targets->position !=
    localDW->DelayInput1_DSTATE_l));

  // Update for UnitDelay: '<S5>/Unit Delay' incorporates:
  //   DataTypeConversion: '<S1>/Cast To Double1'

  localDW->UnitDelay_DSTATE = 1;

  // Update for UnitDelay: '<S8>/Delay Input1'
  //
  //  Block description for '<S8>/Delay Input1':
  //
  //   Store in Global RAM

  localDW->DelayInput1_DSTATE = rtb_UnitDelay;

  // Update for DiscreteFilter: '<S5>/Discrete Filter'
  localDW->DiscreteFilter_icLoad = 0U;
  localDW->DiscreteFilter_states[2] = localDW->DiscreteFilter_states[1];
  localDW->DiscreteFilter_states[1] = localDW->DiscreteFilter_states[0];
  localDW->DiscreteFilter_states[0] = localDW->DiscreteFilter_tmp;

  // Update for UnitDelay: '<S3>/Delay Input1'
  //
  //  Block description for '<S3>/Delay Input1':
  //
  //   Store in Global RAM
	rty_Targets_out->position = rty_planner->position;
  localDW->DelayInput1_DSTATE_l = rtu_Targets->position;

  // Update for UnitDelay: '<S4>/Delay Input1'
  //
  //  Block description for '<S4>/Delay Input1':
  //
  //   Store in Global RAM

  localDW->DelayInput1_DSTATE_n = 1;

  // End of Outputs for SubSystem: '<Root>/If Action Subsystem'
}

// Model initialize function
void trajectory_planner_initialize(ZCE_trajectory_planner_T *localZCE)
{
  localZCE->ComputeCoefficients_Trig_ZCE = POS_ZCSIG;
  localZCE->ComputeInitState_Trig_ZCE = POS_ZCSIG;
  localZCE->DiscreteFilter_Reset_ZCE = POS_ZCSIG;
}

//
// File trailer for generated code.
//
// [EOF]
//
