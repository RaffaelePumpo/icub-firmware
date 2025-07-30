//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: FOCInnerLoop.cpp
//
// Code generated for Simulink model 'control_foc'.
//
// Model version                  : 9.8
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Wed Jul 30 12:05:19 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "FOCInnerLoop.h"
#include "rtwtypes.h"
#include "control_foc_types.h"
#include <cmath>
#include "control_foc_private.h"
#include "zero_crossing_types.h"

// Named constants for Chart: '<S1>/Chart'
const uint8_T control_foc_IN_Initial = 1U;
const uint8_T control_foc_IN_Initial1 = 2U;
const uint8_T control_foc_IN_Initial2 = 3U;

// Forward declaration for local functions
static void control_foc_SystemCore_setup
  (dsp_simulink_MovingAverage_control_foc_T *obj);
static void control_foc_SystemCore_setup
  (dsp_simulink_MovingAverage_control_foc_T *obj)
{
  obj->isInitialized = 1;

  // Start for MATLABSystem: '<S14>/Moving Average'
  obj->NumChannels = 1;
  obj->FrameLength = 3;
  obj->pwN = 0.0F;
  obj->pmN = 0.0F;
  obj->plambda = obj->ForgettingFactor;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// System initialize for atomic system: '<Root>/FOC inner loop'
void FOCInnerLoop_Init(DW_FOCInnerLoop_T *localDW)
{
  // InitializeConditions for DiscreteTransferFcn: '<S119>/Filter Differentiator TF' 
  localDW->FilterDifferentiatorTF_icLoad = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S126>/Integrator'
  localDW->Integrator_PrevResetState = 2;
  localDW->Integrator_IC_LOADING = 1U;

  // InitializeConditions for DiscreteTransferFcn: '<S55>/Filter Differentiator TF' 
  localDW->FilterDifferentiatorTF_icLoad_c = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S62>/Integrator'
  localDW->Integrator_PrevResetState_k = 2;
  localDW->Integrator_IC_LOADING_b = 1U;

  // SystemInitialize for Chart: '<S1>/Chart' incorporates:
  //   SubSystem: '<S2>/ComputeOffset'

  // Start for MATLABSystem: '<S14>/Moving Average'
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.FrameLength = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.ForgettingFactor = 0.99F;
  control_foc_SystemCore_setup(&localDW->obj);

  // InitializeConditions for MATLABSystem: '<S14>/Moving Average'
  localDW->obj.pwN = 0.0F;
  localDW->obj.pmN = 0.0F;
}

// Outputs for atomic system: '<Root>/FOC inner loop'
void FOCInnerLoop(const boolean_T *rtu_CalibrationDone, const SensorsData
                  *rtu_Sensors_Inport_2, const ActuatorConfiguration
                  *rtu_ConfigurationParameters, const Targets
                  *rtu_Targets_Inport_5, const ControlOuterOutputs
                  *rtu_OuterOutputs, const boolean_T *rtu_areLimitSet,
                  FOCOutputs *rty_FOCOutputs, B_FOCInnerLoop_T *localB,
                  DW_FOCInnerLoop_T *localDW, ZCE_FOCInnerLoop_T *localZCE)
{
  real32_T DProdOut;
  real32_T rtb_Diff;
  real32_T rtb_IaIbIc0_idx_0;
  real32_T rtb_IaIbIc0_idx_1;
  real32_T rtb_NProdOut;
  real32_T rtb_PProdOut_k;
  real32_T rtb_Product;
  real32_T rtb_SinCos_o1;
  real32_T rtb_SinCos_o2;
  real32_T rtb_Switch_c_idx_0;
  real32_T rtb_sum_beta;
  int8_T tmp;
  int8_T tmp_0;

  // MinMax: '<S1>/Min'
  if (rtu_Sensors_Inport_2->driversensors.Vcc <=
      rtu_ConfigurationParameters->motor.Vmax) {
    rtb_Diff = rtu_Sensors_Inport_2->driversensors.Vcc;
  } else {
    rtb_Diff = rtu_ConfigurationParameters->motor.Vmax;
  }

  // Product: '<S1>/Product' incorporates:
  //   Constant: '<S1>/Constant2'
  //   Constant: '<S1>/Constant3'
  //   Gain: '<S1>/Gain4'
  //   Gain: '<S1>/Gain5'
  //   MinMax: '<S1>/Min'
  //   Sum: '<S1>/Sum5'

  rtb_Product = 0.5F * rtb_Diff * 0.975F;

  // Chart: '<S1>/Chart' incorporates:
  //   MATLABSystem: '<S14>/Moving Average'
  //
  if (localDW->temporalCounter_i1 < 127) {
    localDW->temporalCounter_i1 = static_cast<uint8_T>
      (localDW->temporalCounter_i1 + 1);
  }

  if (localDW->is_active_c3_control_foc == 0) {
    localDW->is_active_c3_control_foc = 1U;
    localDW->is_c3_control_foc = control_foc_IN_Initial;
  } else {
    switch (localDW->is_c3_control_foc) {
     case control_foc_IN_Initial:
      if (*rtu_areLimitSet) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_control_foc = control_foc_IN_Initial1;
      }
      break;

     case control_foc_IN_Initial1:
      if (localDW->temporalCounter_i1 >= 100) {
        localDW->is_c3_control_foc = control_foc_IN_Initial2;
        localB->outputs[0] = rtu_Sensors_Inport_2->motorsensors.Iabc[0] -
          localDW->offsets[0];
        localB->outputs[1] = rtu_Sensors_Inport_2->motorsensors.Iabc[1] -
          localDW->offsets[1];
        localB->outputs[2] = rtu_Sensors_Inport_2->motorsensors.Iabc[2] -
          localDW->offsets[2];
      } else {
        // Outputs for Function Call SubSystem: '<S2>/ComputeOffset'
        if (localDW->obj.ForgettingFactor != 0.99F) {
          // MATLABSystem: '<S14>/Moving Average'
          if (localDW->obj.isInitialized == 1) {
            localDW->obj.TunablePropsChanged = true;
          }

          localDW->obj.ForgettingFactor = 0.99F;
        }

        // MATLABSystem: '<S14>/Moving Average'
        if (localDW->obj.TunablePropsChanged) {
          localDW->obj.TunablePropsChanged = false;
          localDW->obj.plambda = 0.99F;
        }

        rtb_IaIbIc0_idx_0 = localDW->obj.plambda * localDW->obj.pwN + 1.0F;

        // Start for MATLABSystem: '<S14>/Moving Average'
        rtb_IaIbIc0_idx_1 = 1.0F / rtb_IaIbIc0_idx_0;

        // MATLABSystem: '<S14>/Moving Average'
        rtb_Switch_c_idx_0 = (1.0F - rtb_IaIbIc0_idx_1) * localDW->obj.pmN +
          rtb_IaIbIc0_idx_1 * rtu_Sensors_Inport_2->motorsensors.Iabc[0];
        localDW->offsets[0] = rtb_Switch_c_idx_0;
        rtb_IaIbIc0_idx_0 = localDW->obj.plambda * rtb_IaIbIc0_idx_0 + 1.0F;

        // Start for MATLABSystem: '<S14>/Moving Average'
        rtb_IaIbIc0_idx_1 = 1.0F / rtb_IaIbIc0_idx_0;

        // MATLABSystem: '<S14>/Moving Average'
        rtb_Switch_c_idx_0 = (1.0F - rtb_IaIbIc0_idx_1) * rtb_Switch_c_idx_0 +
          rtb_IaIbIc0_idx_1 * rtu_Sensors_Inport_2->motorsensors.Iabc[1];
        localDW->offsets[1] = rtb_Switch_c_idx_0;
        rtb_IaIbIc0_idx_0 = localDW->obj.plambda * rtb_IaIbIc0_idx_0 + 1.0F;

        // Start for MATLABSystem: '<S14>/Moving Average'
        rtb_IaIbIc0_idx_1 = 1.0F / rtb_IaIbIc0_idx_0;

        // MATLABSystem: '<S14>/Moving Average'
        rtb_Switch_c_idx_0 = (1.0F - rtb_IaIbIc0_idx_1) * rtb_Switch_c_idx_0 +
          rtb_IaIbIc0_idx_1 * rtu_Sensors_Inport_2->motorsensors.Iabc[2];
        localDW->offsets[2] = rtb_Switch_c_idx_0;
        localDW->obj.pwN = rtb_IaIbIc0_idx_0;
        localDW->obj.pmN = rtb_Switch_c_idx_0;

        // End of Outputs for SubSystem: '<S2>/ComputeOffset'
      }
      break;

     default:
      // case IN_Initial2:
      localB->outputs[0] = rtu_Sensors_Inport_2->motorsensors.Iabc[0] -
        localDW->offsets[0];
      localB->outputs[1] = rtu_Sensors_Inport_2->motorsensors.Iabc[1] -
        localDW->offsets[1];
      localB->outputs[2] = rtu_Sensors_Inport_2->motorsensors.Iabc[2] -
        localDW->offsets[2];
      break;
    }
  }

  // End of Chart: '<S1>/Chart'

  // Gain: '<S1>/Ia+Ib+Ic=0'
  rtb_IaIbIc0_idx_0 = 0.0F;
  rtb_IaIbIc0_idx_1 = 0.0F;
  for (int32_T i = 0; i < 3; i++) {
    int32_T rtb_IaIbIc0_idx_0_tmp;
    rtb_Diff = localB->outputs[i];
    rtb_IaIbIc0_idx_0_tmp = i << 1;
    rtb_IaIbIc0_idx_0 += rtCP_IaIbIc0_Gain[rtb_IaIbIc0_idx_0_tmp] * rtb_Diff;
    rtb_IaIbIc0_idx_1 += rtCP_IaIbIc0_Gain[rtb_IaIbIc0_idx_0_tmp + 1] * rtb_Diff;
  }

  // End of Gain: '<S1>/Ia+Ib+Ic=0'

  // Outputs for Atomic SubSystem: '<S18>/Two phase CRL wrap'
  // Gain: '<S19>/one_by_sqrt3' incorporates:
  //   Sum: '<S19>/a_plus_2b'

  rtb_sum_beta = ((rtb_IaIbIc0_idx_0 + rtb_IaIbIc0_idx_1) + rtb_IaIbIc0_idx_1) *
    0.577350259F;

  // End of Outputs for SubSystem: '<S18>/Two phase CRL wrap'

  // Gain: '<S6>/Gain1'
  rtb_Diff = 0.0174532924F * rtu_Sensors_Inport_2->motorsensors.electrical_angle;

  // Trigonometry: '<S21>/SinCos'
  rtb_SinCos_o1 = std::sin(rtb_Diff);
  rtb_SinCos_o2 = std::cos(rtb_Diff);

  // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
  // Outputs for Atomic SubSystem: '<S18>/Two phase CRL wrap'
  // Switch: '<S148>/Switch' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S19>/a16'
  //   Product: '<S147>/acos'
  //   Product: '<S147>/asin'
  //   Product: '<S147>/bcos'
  //   Product: '<S147>/bsin'
  //   Sum: '<S147>/sum_Ds'
  //   Sum: '<S147>/sum_Qs'

  rtb_Switch_c_idx_0 = rtb_IaIbIc0_idx_0 * rtb_SinCos_o2 + rtb_sum_beta *
    rtb_SinCos_o1;
  rtb_IaIbIc0_idx_0 = rtb_sum_beta * rtb_SinCos_o2 - rtb_IaIbIc0_idx_0 *
    rtb_SinCos_o1;

  // End of Outputs for SubSystem: '<S18>/Two phase CRL wrap'

  // AlgorithmDescriptorDelegate generated from: '<S147>/a16'
  rtb_IaIbIc0_idx_1 = rtb_Switch_c_idx_0;

  // Sum: '<S1>/Sum' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'

  rtb_Diff = rtu_OuterOutputs->motorcurrent - rtb_IaIbIc0_idx_0;

  // End of Outputs for SubSystem: '<S146>/Two inputs CRL'

  // Product: '<S131>/PProd Out'
  rtb_sum_beta = rtb_Diff * rtu_ConfigurationParameters->pids.currentPID.P;

  // Product: '<S123>/IProd Out'
  rtb_PProdOut_k = rtb_Diff * rtu_ConfigurationParameters->pids.currentPID.I;

  // Product: '<S117>/DProd Out'
  DProdOut = rtb_Diff * rtu_ConfigurationParameters->pids.currentPID.D;

  // SampleTimeMath: '<S121>/Tsamp'
  //
  //  About '<S121>/Tsamp':
  //   y = u * K where K = ( w * Ts )
  //
  rtb_Diff = rtu_ConfigurationParameters->pids.currentPID.N * 2.25E-5F;

  // Sum: '<S88>/sum_alpha' incorporates:
  //   Constant: '<S119>/Filter Den Constant'
  //   Math: '<S119>/Reciprocal'
  //   Sum: '<S119>/SumDen'
  //
  //  About '<S119>/Reciprocal':
  //   Operator: reciprocal

  localB->Switch = 1.0F / (rtb_Diff + 1.0F);

  // DiscreteTransferFcn: '<S119>/Filter Differentiator TF'
  if (rtu_OuterOutputs->pid_reset && (localZCE->FilterDifferentiatorTF_Reset_ZCE
       != POS_ZCSIG)) {
    localDW->FilterDifferentiatorTF_icLoad = 1U;
  }

  localZCE->FilterDifferentiatorTF_Reset_ZCE = rtu_OuterOutputs->pid_reset;
  if (localDW->FilterDifferentiatorTF_icLoad != 0) {
    localDW->FilterDifferentiatorTF_states = 0.0F;
    localDW->FilterDifferentiatorTF_icLoad = 0U;
  }

  // Product: '<S119>/Divide' incorporates:
  //   Constant: '<S119>/Filter Den Constant'
  //   Product: '<S55>/Divide'
  //   Sum: '<S119>/SumNum'

  rtb_Diff = (rtb_Diff - 1.0F) * localB->Switch;

  // DiscreteTransferFcn: '<S119>/Filter Differentiator TF' incorporates:
  //   Product: '<S119>/Divide'

  localDW->FilterDifferentiatorTF_tmp = DProdOut - rtb_Diff *
    localDW->FilterDifferentiatorTF_states;

  // Product: '<S129>/NProd Out' incorporates:
  //   DiscreteTransferFcn: '<S119>/Filter Differentiator TF'
  //   Product: '<S119>/DenCoefOut'

  rtb_NProdOut = (localDW->FilterDifferentiatorTF_tmp -
                  localDW->FilterDifferentiatorTF_states) * localB->Switch *
    rtu_ConfigurationParameters->pids.currentPID.N;

  // Sum: '<S138>/SumI1' incorporates:
  //   Sum: '<S136>/Sum Fdbk'
  //   Sum: '<S137>/SumI3'
  //   UnitDelay: '<S1>/Unit Delay'

  localB->SumI1 = (localDW->UnitDelay_DSTATE - ((rtb_sum_beta +
    localDW->Integrator_DSTATE) + rtb_NProdOut)) + rtb_PProdOut_k;

  // DiscreteIntegrator: '<S126>/Integrator' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'

  if (localDW->Integrator_IC_LOADING != 0) {
    // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
    localDW->Integrator_DSTATE = rtb_IaIbIc0_idx_0;

    // End of Outputs for SubSystem: '<S146>/Two inputs CRL'
  }

  if (rtu_OuterOutputs->pid_reset && (localDW->Integrator_PrevResetState <= 0))
  {
    // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
    localDW->Integrator_DSTATE = rtb_IaIbIc0_idx_0;

    // End of Outputs for SubSystem: '<S146>/Two inputs CRL'
  }

  // DiscreteIntegrator: '<S126>/Integrator'
  localB->Integrator = 2.25E-5F * localB->SumI1 + localDW->Integrator_DSTATE;

  // Gain: '<S1>/Gain8'
  DProdOut = 0.5F * rtu_Sensors_Inport_2->driversensors.Vcc;

  // Switch: '<S1>/Switch1'
  if (rtu_OuterOutputs->cur_en) {
    // Switch: '<S1>/Switch1' incorporates:
    //   Sum: '<S135>/Sum'

    localDW->UnitDelay_DSTATE = (rtb_sum_beta + localB->Integrator) +
      rtb_NProdOut;
  } else {
    // Switch: '<S1>/Switch1' incorporates:
    //   Gain: '<S1>/Gain6'
    //   Product: '<S1>/Divide2'
    //   Sum: '<S1>/Sum6'

    localDW->UnitDelay_DSTATE = 0.01F * rtu_Targets_Inport_5->voltage * DProdOut
      + rtu_OuterOutputs->current_limiter;
  }

  // End of Switch: '<S1>/Switch1'

  // Switch: '<S13>/Switch2' incorporates:
  //   Gain: '<S1>/Gain2'
  //   RelationalOperator: '<S13>/LowerRelop1'
  //   RelationalOperator: '<S13>/UpperRelop'
  //   Switch: '<S13>/Switch'

  if (localDW->UnitDelay_DSTATE > rtb_Product) {
    // Switch: '<S1>/Switch1'
    localDW->UnitDelay_DSTATE = rtb_Product;
  } else if (localDW->UnitDelay_DSTATE < -rtb_Product) {
    // Switch: '<S1>/Switch1' incorporates:
    //   Gain: '<S1>/Gain2'
    //   Switch: '<S13>/Switch'

    localDW->UnitDelay_DSTATE = -rtb_Product;
  }

  // End of Switch: '<S13>/Switch2'

  // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
  // Product: '<S67>/PProd Out' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'
  //   Gain: '<S1>/Gain'

  rtb_PProdOut_k = -rtb_Switch_c_idx_0 *
    rtu_ConfigurationParameters->pids.currentPID.P;

  // End of Outputs for SubSystem: '<S146>/Two inputs CRL'

  // DiscreteTransferFcn: '<S55>/Filter Differentiator TF' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'
  //   DiscreteTransferFcn: '<S119>/Filter Differentiator TF'
  //   Gain: '<S1>/Gain'
  //   Product: '<S53>/DProd Out'

  if (rtu_OuterOutputs->pid_reset &&
      (localZCE->FilterDifferentiatorTF_Reset_ZCE_o != POS_ZCSIG)) {
    localDW->FilterDifferentiatorTF_icLoad_c = 1U;
  }

  localZCE->FilterDifferentiatorTF_Reset_ZCE_o = rtu_OuterOutputs->pid_reset;
  if (localDW->FilterDifferentiatorTF_icLoad_c != 0) {
    localDW->FilterDifferentiatorTF_states_k = 0.0F;
    localDW->FilterDifferentiatorTF_icLoad_c = 0U;
  }

  // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
  localDW->FilterDifferentiatorTF_tmp_c = -rtb_Switch_c_idx_0 *
    rtu_ConfigurationParameters->pids.currentPID.D - rtb_Diff *
    localDW->FilterDifferentiatorTF_states_k;

  // End of Outputs for SubSystem: '<S146>/Two inputs CRL'

  // Product: '<S65>/NProd Out' incorporates:
  //   DiscreteTransferFcn: '<S55>/Filter Differentiator TF'
  //   Math: '<S55>/Reciprocal'
  //   Product: '<S55>/DenCoefOut'
  //
  //  About '<S55>/Reciprocal':
  //   Operator: reciprocal

  rtb_sum_beta = (localDW->FilterDifferentiatorTF_tmp_c -
                  localDW->FilterDifferentiatorTF_states_k) * localB->Switch *
    rtu_ConfigurationParameters->pids.currentPID.N;

  // Sum: '<S73>/Sum Fdbk'
  rtb_NProdOut = (rtb_PProdOut_k + localDW->Integrator_DSTATE_o) + rtb_sum_beta;

  // Switch: '<S52>/Switch' incorporates:
  //   Gain: '<S1>/Gain2'
  //   RelationalOperator: '<S52>/u_GTE_up'
  //   RelationalOperator: '<S52>/u_GT_lo'
  //   Switch: '<S52>/Switch1'

  if (rtb_NProdOut >= rtb_Product) {
    rtb_Diff = rtb_Product;
  } else if (rtb_NProdOut > -rtb_Product) {
    // Switch: '<S52>/Switch1'
    rtb_Diff = rtb_NProdOut;
  } else {
    rtb_Diff = -rtb_Product;
  }

  // Sum: '<S52>/Diff' incorporates:
  //   Switch: '<S52>/Switch'

  rtb_Diff = rtb_NProdOut - rtb_Diff;

  // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
  // Sum: '<S88>/sum_alpha' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'
  //   Gain: '<S1>/Gain'
  //   Product: '<S59>/IProd Out'

  localB->Switch = -rtb_Switch_c_idx_0 *
    rtu_ConfigurationParameters->pids.currentPID.I;

  // End of Outputs for SubSystem: '<S146>/Two inputs CRL'

  // Switch: '<S49>/Switch1' incorporates:
  //   Constant: '<S49>/Clamping_zero'
  //   Constant: '<S49>/Constant'
  //   Constant: '<S49>/Constant2'
  //   RelationalOperator: '<S49>/fix for DT propagation issue'

  if (rtb_Diff > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S49>/Switch2' incorporates:
  //   Constant: '<S49>/Clamping_zero'
  //   Constant: '<S49>/Constant3'
  //   Constant: '<S49>/Constant4'
  //   RelationalOperator: '<S49>/fix for DT propagation issue1'

  if (localB->Switch > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S49>/Switch' incorporates:
  //   Constant: '<S49>/Clamping_zero'
  //   Logic: '<S49>/AND3'
  //   RelationalOperator: '<S49>/Equal1'
  //   RelationalOperator: '<S49>/Relational Operator'
  //   Switch: '<S49>/Switch1'
  //   Switch: '<S49>/Switch2'

  if ((rtb_Diff != 0.0F) && (tmp == tmp_0)) {
    // Sum: '<S88>/sum_alpha' incorporates:
    //   Constant: '<S49>/Constant1'
    //   Switch: '<S49>/Switch'

    localB->Switch = 0.0F;
  }

  // End of Switch: '<S49>/Switch'

  // DiscreteIntegrator: '<S62>/Integrator' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'

  if (localDW->Integrator_IC_LOADING_b != 0) {
    // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
    localDW->Integrator_DSTATE_o = rtb_Switch_c_idx_0;

    // End of Outputs for SubSystem: '<S146>/Two inputs CRL'
  }

  if (rtu_OuterOutputs->pid_reset && (localDW->Integrator_PrevResetState_k <= 0))
  {
    // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
    localDW->Integrator_DSTATE_o = rtb_Switch_c_idx_0;

    // End of Outputs for SubSystem: '<S146>/Two inputs CRL'
  }

  // DiscreteIntegrator: '<S62>/Integrator'
  localB->Integrator_j = 2.25E-5F * localB->Switch +
    localDW->Integrator_DSTATE_o;

  // Sum: '<S72>/Sum'
  rtb_PProdOut_k = (rtb_PProdOut_k + localB->Integrator_j) + rtb_sum_beta;

  // Switch: '<S70>/Switch2' incorporates:
  //   Gain: '<S1>/Gain2'
  //   RelationalOperator: '<S70>/LowerRelop1'
  //   RelationalOperator: '<S70>/UpperRelop'
  //   Switch: '<S70>/Switch'

  if (rtb_PProdOut_k > rtb_Product) {
    rtb_PProdOut_k = rtb_Product;
  } else if (rtb_PProdOut_k < -rtb_Product) {
    // Switch: '<S70>/Switch' incorporates:
    //   Gain: '<S1>/Gain2'

    rtb_PProdOut_k = -rtb_Product;
  }

  // End of Switch: '<S70>/Switch2'

  // Outputs for Atomic SubSystem: '<S87>/Two inputs CRL'
  // Switch: '<S89>/Switch' incorporates:
  //   Product: '<S88>/dcos'
  //   Product: '<S88>/qsin'
  //   Sum: '<S88>/sum_alpha'

  rtb_Switch_c_idx_0 = rtb_PProdOut_k * rtb_SinCos_o2 -
    localDW->UnitDelay_DSTATE * rtb_SinCos_o1;

  // End of Outputs for SubSystem: '<S87>/Two inputs CRL'

  // Switch: '<S1>/Switch2' incorporates:
  //   Constant: '<S1>/Constant1'

  if (rtu_OuterOutputs->out_en) {
    // Outputs for Atomic SubSystem: '<S87>/Two inputs CRL'
    // Gain: '<S84>/sqrt3_by_two' incorporates:
    //   Product: '<S88>/dsin'
    //   Product: '<S88>/qcos'
    //   Sum: '<S88>/sum_beta'

    rtb_SinCos_o2 = (localDW->UnitDelay_DSTATE * rtb_SinCos_o2 + rtb_PProdOut_k *
                     rtb_SinCos_o1) * 0.866025388F;

    // Gain: '<S84>/one_by_two' incorporates:
    //   AlgorithmDescriptorDelegate generated from: '<S88>/a16'

    rtb_SinCos_o1 = 0.5F * rtb_Switch_c_idx_0;

    // End of Outputs for SubSystem: '<S87>/Two inputs CRL'

    // Sum: '<S84>/add_c'
    rtb_Product = (0.0F - rtb_SinCos_o1) - rtb_SinCos_o2;

    // Sum: '<S84>/add_b'
    rtb_SinCos_o1 = rtb_SinCos_o2 - rtb_SinCos_o1;

    // Outputs for Atomic SubSystem: '<S87>/Two inputs CRL'
    // MinMax: '<S1>/Min1' incorporates:
    //   AlgorithmDescriptorDelegate generated from: '<S88>/a16'

    if (rtb_Switch_c_idx_0 <= rtb_SinCos_o1) {
      rtb_SinCos_o2 = rtb_Switch_c_idx_0;
    } else {
      rtb_SinCos_o2 = rtb_SinCos_o1;
    }

    // End of Outputs for SubSystem: '<S87>/Two inputs CRL'
    if (rtb_SinCos_o2 > rtb_Product) {
      rtb_SinCos_o2 = rtb_Product;
    }

    // Gain: '<S1>/Gain3' incorporates:
    //   Product: '<S1>/Divide1'

    DProdOut = localDW->UnitDelay_DSTATE / DProdOut * 100.0F;

    // Saturate: '<S1>/Saturation1'
    if (DProdOut > 100.0F) {
      DProdOut = 100.0F;
    } else if (DProdOut < -100.0F) {
      DProdOut = -100.0F;
    }

    // End of Saturate: '<S1>/Saturation1'

    // Outputs for Atomic SubSystem: '<S87>/Two inputs CRL'
    // Sum: '<S1>/Sum1' incorporates:
    //   AlgorithmDescriptorDelegate generated from: '<S88>/a16'
    //   Constant: '<S1>/Constant2'
    //   Gain: '<S1>/Gain1'
    //   MinMax: '<S1>/Min1'
    //   Product: '<S1>/Divide'
    //   Sum: '<S1>/Sum4'

    rtb_Switch_c_idx_0 = (rtb_Switch_c_idx_0 - rtb_SinCos_o2) /
      rtu_Sensors_Inport_2->driversensors.Vcc * 100.0F + 5.0F;

    // End of Outputs for SubSystem: '<S87>/Two inputs CRL'

    // Saturate: '<S1>/Saturation'
    if (rtb_Switch_c_idx_0 > 100.0F) {
      rtb_Switch_c_idx_0 = 100.0F;
    } else if (rtb_Switch_c_idx_0 < 0.0F) {
      rtb_Switch_c_idx_0 = 0.0F;
    }

    // Sum: '<S1>/Sum1' incorporates:
    //   Constant: '<S1>/Constant2'
    //   Gain: '<S1>/Gain1'
    //   MinMax: '<S1>/Min1'
    //   Product: '<S1>/Divide'
    //   Sum: '<S1>/Sum4'

    rtb_SinCos_o1 = (rtb_SinCos_o1 - rtb_SinCos_o2) /
      rtu_Sensors_Inport_2->driversensors.Vcc * 100.0F + 5.0F;

    // Saturate: '<S1>/Saturation'
    if (rtb_SinCos_o1 > 100.0F) {
      rtb_SinCos_o1 = 100.0F;
    } else if (rtb_SinCos_o1 < 0.0F) {
      rtb_SinCos_o1 = 0.0F;
    }

    // Sum: '<S1>/Sum1' incorporates:
    //   Constant: '<S1>/Constant2'
    //   Gain: '<S1>/Gain1'
    //   MinMax: '<S1>/Min1'
    //   Product: '<S1>/Divide'
    //   Sum: '<S1>/Sum4'

    rtb_Product = (rtb_Product - rtb_SinCos_o2) /
      rtu_Sensors_Inport_2->driversensors.Vcc * 100.0F + 5.0F;

    // Saturate: '<S1>/Saturation'
    if (rtb_Product > 100.0F) {
      rtb_Product = 100.0F;
    } else if (rtb_Product < 0.0F) {
      rtb_Product = 0.0F;
    }
  } else {
    DProdOut = 0.0F;
    rtb_Switch_c_idx_0 = 0.0F;
    rtb_SinCos_o1 = 0.0F;
    rtb_Product = 0.0F;
  }

  // End of Switch: '<S1>/Switch2'

  // BusCreator: '<S1>/Bus Creator' incorporates:
  //   AlgorithmDescriptorDelegate generated from: '<S147>/a16'
  //   Constant: '<S20>/Constant'
  //   Constant: '<S20>/Constant1'

  rty_FOCOutputs->calibrationdone = *rtu_CalibrationDone;
  rty_FOCOutputs->Vq = DProdOut;
  rty_FOCOutputs->Vabc[0] = rtb_Switch_c_idx_0;
  rty_FOCOutputs->Vabc[1] = rtb_SinCos_o1;
  rty_FOCOutputs->Vabc[2] = rtb_Product;

  // Outputs for Atomic SubSystem: '<S146>/Two inputs CRL'
  rty_FOCOutputs->Iq_fbk = rtb_IaIbIc0_idx_0;

  // End of Outputs for SubSystem: '<S146>/Two inputs CRL'
  rty_FOCOutputs->Id_fbk = rtb_IaIbIc0_idx_1;
  rty_FOCOutputs->Iq_rms = 0.0F;
  rty_FOCOutputs->Id_rms = 0.0F;
}

// Update for atomic system: '<Root>/FOC inner loop'
void FOCInnerLoop_Update(const ControlOuterOutputs *rtu_OuterOutputs,
  B_FOCInnerLoop_T *localB, DW_FOCInnerLoop_T *localDW)
{
  // Update for DiscreteTransferFcn: '<S119>/Filter Differentiator TF'
  localDW->FilterDifferentiatorTF_icLoad = 0U;
  localDW->FilterDifferentiatorTF_states = localDW->FilterDifferentiatorTF_tmp;

  // Update for DiscreteIntegrator: '<S126>/Integrator'
  localDW->Integrator_IC_LOADING = 0U;
  localDW->Integrator_DSTATE = 2.25E-5F * localB->SumI1 + localB->Integrator;
  localDW->Integrator_PrevResetState = static_cast<int8_T>
    (rtu_OuterOutputs->pid_reset);

  // Update for DiscreteTransferFcn: '<S55>/Filter Differentiator TF'
  localDW->FilterDifferentiatorTF_icLoad_c = 0U;
  localDW->FilterDifferentiatorTF_states_k =
    localDW->FilterDifferentiatorTF_tmp_c;

  // Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
  //   DiscreteIntegrator: '<S126>/Integrator'

  localDW->Integrator_IC_LOADING_b = 0U;
  localDW->Integrator_DSTATE_o = 2.25E-5F * localB->Switch +
    localB->Integrator_j;
  localDW->Integrator_PrevResetState_k = static_cast<int8_T>
    (rtu_OuterOutputs->pid_reset);
}

// Termination for atomic system: '<Root>/FOC inner loop'
void FOCInnerLoop_Term(DW_FOCInnerLoop_T *localDW)
{
  // Terminate for Chart: '<S1>/Chart' incorporates:
  //   SubSystem: '<S2>/ComputeOffset'

  // Terminate for MATLABSystem: '<S14>/Moving Average'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      localDW->obj.NumChannels = -1;
      localDW->obj.FrameLength = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S14>/Moving Average'
}

//
// File trailer for generated code.
//
// [EOF]
//
