//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: motion_controller.h
//
// Code generated for Simulink model 'motion_controller'.
//
// Model version                  : 5.115
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Mon Jul 14 12:24:06 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef motion_controller_h_
#define motion_controller_h_
#include "rtwtypes.h"
#include "motion_controller_types.h"
#include "Calibrator.h"
#include "control_foc.h"
#include "estimation_velocity.h"
#include "filter_current.h"
#include "supervisor.h"
#include "position_velocity_cascade.h"
#include "zero_crossing_types.h"

// Includes for objects with custom storage classes
#include "rtw_defines.h"

// Block signals for model 'motion_controller'
struct B_motion_controller_c_T {
  FOCSlowInputs BusConversion_InsertedFor_FOC_at_inport_1_BusCreator1;
  SensorsData Transitionto1ms;         // '<Root>/Transition to 1ms'
  FOCOutputs RateTransition2;          // '<Root>/Rate Transition2'
  Targets targets;                     // '<Root>/Motor Supervisor'
  uint32_T TmpRTBAtCalibratorInport22;
  uint32_T velocity_est_window;        // '<Root>/Calibrator'
  uint32_T motorPwmLimit;              // '<Root>/Calibrator'
  real32_T Vcc;                        // '<Root>/Calibrator'
  real32_T offset;                     // '<Root>/Calibrator'
  real32_T rotor_angle;                // '<Root>/Calibrator'
  real32_T counter;                    // '<Root>/Calibrator'
  real32_T Idx_counter;                // '<Root>/Calibrator'
  real32_T electrical_angle;           // '<Root>/Calibrator'
  real32_T temperature;                // '<Root>/Calibrator'
  real32_T voltage;                    // '<Root>/Calibrator'
  real32_T current;                    // '<Root>/Calibrator'
  real32_T ConfigurationParameters;
  real32_T TmpRTBAtCalibratorInport20;
  real32_T TmpRTBAtCalibratorInport21;
  real32_T TmpRTBAtCalibratorInport23;
  real32_T TmpRTBAtCalibratorInport25;
  real32_T TmpRTBAtCalibratorInport26;
  real32_T TmpRTBAtCalibratorInport27;
  real32_T TmpRTBAtCalibratorInport28;
  real32_T TmpRTBAtCalibratorInport29;
  real32_T TmpRTBAtCalibratorInport30;
  real32_T TmpRTBAtCalibratorInport31;
  real32_T TmpRTBAtCalibratorInport32;
  real32_T TmpRTBAtCalibratorInport35;
  real32_T TmpRTBAtCalibratorInport36;
  real32_T TmpRTBAtCalibratorInport37;
  real32_T TmpRTBAtCalibratorInport38;
  real32_T TmpRTBAtCalibratorInport39;
  real32_T TmpRTBAtCalibratorInport40;
  real32_T TmpRTBAtCalibratorInport41;
  real32_T TmpRTBAtCalibratorInport42;
  real32_T TmpRTBAtCalibratorInport45;
  real32_T TmpRTBAtCalibratorInport46;
  real32_T TmpRTBAtCalibratorInport47;
  real32_T TmpRTBAtCalibratorInport48;
  real32_T TmpRTBAtCalibratorInport49;
  real32_T TmpRTBAtCalibratorInport50;
  real32_T TmpRTBAtCalibratorInport51;
  real32_T TmpRTBAtCalibratorInport52;
  real32_T TmpRTBAtCalibratorInport64;
  real32_T TmpRTBAtCalibratorInport65;
  real32_T TmpRTBAtCalibratorInport66;
  real32_T TmpRTBAtCalibratorInport67;
  real32_T TmpRTBAtCalibratorInport68;
  real32_T TmpRTBAtCalibratorInport69;
  real32_T TmpRTBAtCalibratorInport70;
  real32_T TmpRTBAtCalibratorInport71;
  real32_T TmpRTBAtCalibratorInport72;
  real32_T TmpRTBAtCalibratorInport73;
  real32_T TmpRTBAtCalibratorInport19;
  real32_T environment_temperature;    // '<Root>/Calibrator'
  real32_T current_rms_lambda;         // '<Root>/Calibrator'
  real32_T jntVelMax;                  // '<Root>/Calibrator'
  real32_T motorNominalCurrents;       // '<Root>/Calibrator'
  real32_T motorPeakCurrents;          // '<Root>/Calibrator'
  real32_T motorOverloadCurrents;      // '<Root>/Calibrator'
  real32_T motorCriticalTemperature;   // '<Root>/Calibrator'
  real32_T OutMax;                     // '<Root>/Calibrator'
  real32_T OutMin;                     // '<Root>/Calibrator'
  real32_T P;                          // '<Root>/Calibrator'
  real32_T I;                          // '<Root>/Calibrator'
  real32_T D;                          // '<Root>/Calibrator'
  real32_T N;                          // '<Root>/Calibrator'
  real32_T I0;                         // '<Root>/Calibrator'
  real32_T D0;                         // '<Root>/Calibrator'
  real32_T OutMax_f;                   // '<Root>/Calibrator'
  real32_T OutMin_p;                   // '<Root>/Calibrator'
  real32_T P_p;                        // '<Root>/Calibrator'
  real32_T I_c;                        // '<Root>/Calibrator'
  real32_T D_p;                        // '<Root>/Calibrator'
  real32_T N_n;                        // '<Root>/Calibrator'
  real32_T I0_i;                       // '<Root>/Calibrator'
  real32_T D0_g;                       // '<Root>/Calibrator'
  real32_T OutMax_n;                   // '<Root>/Calibrator'
  real32_T OutMin_b;                   // '<Root>/Calibrator'
  real32_T P_o;                        // '<Root>/Calibrator'
  real32_T I_p;                        // '<Root>/Calibrator'
  real32_T D_n;                        // '<Root>/Calibrator'
  real32_T N_b;                        // '<Root>/Calibrator'
  real32_T I0_o;                       // '<Root>/Calibrator'
  real32_T D0_e;                       // '<Root>/Calibrator'
  real32_T Kbemf;                      // '<Root>/Calibrator'
  real32_T Rphase;                     // '<Root>/Calibrator'
  real32_T Imin;                       // '<Root>/Calibrator'
  real32_T Imax;                       // '<Root>/Calibrator'
  real32_T Vmax;                       // '<Root>/Calibrator'
  real32_T resistance;                 // '<Root>/Calibrator'
  real32_T inductance;                 // '<Root>/Calibrator'
  real32_T thermal_resistance;         // '<Root>/Calibrator'
  real32_T thermal_time_constant;      // '<Root>/Calibrator'
  real32_T hall_sensors_offset;        // '<Root>/Calibrator'
  real32_T rotor_velocity;             // '<Root>/Calibrator'
  real32_T Iq_filtered;                // '<Root>/Calibrator'
  real32_T motor_temperature;          // '<Root>/Calibrator'
  real32_T joint_velocity;             // '<Root>/Calibrator'
  real32_T position;                   // '<Root>/Calibrator'
  real32_T velocity;                   // '<Root>/Calibrator'
  real32_T current_j;                  // '<Root>/Calibrator'
  real32_T voltage_l;                  // '<Root>/Calibrator'
  real32_T motorcurrent;               // '<Root>/Calibrator'
  real32_T current_limiter;            // '<Root>/Calibrator'
  real32_T velocity_b;                 // '<S1>/Motor Velocity Estimator'
  real32_T velocity_j;                 // '<S1>/Joint Velocity Estimator'
  ReferenceEncoder TmpRTBAtCalibratorInport74;
  ReferenceEncoder reference_encoder;  // '<Root>/Calibrator'
  EstimationVelocityModes velocity_est_mode;// '<Root>/Calibrator'
  ControlModes TmpRTBAtCalibratorInport24;
  ControlModes TmpRTBAtCalibratorInport34;
  ControlModes TmpRTBAtCalibratorInport44;
  ControlModes TmpRTBAtCalibratorInport6;
  ControlModes type;                   // '<Root>/Calibrator'
  ControlModes type_i;                 // '<Root>/Calibrator'
  ControlModes type_n;                 // '<Root>/Calibrator'
  CalibrationTypes Flags_k;
  int16_T TmpRTBAtCalibratorInport61;
  int16_T TmpRTBAtCalibratorInport62;
  int16_T rotor_encoder_resolution;    // '<Root>/Calibrator'
  int16_T rotor_index_offset;          // '<Root>/Calibrator'
  uint8_T hallABC;                     // '<Root>/Calibrator'
  uint8_T TmpRTBAtCalibratorInport33;
  uint8_T TmpRTBAtCalibratorInport43;
  uint8_T TmpRTBAtCalibratorInport53;
  uint8_T TmpRTBAtCalibratorInport59;
  uint8_T TmpRTBAtCalibratorInport60;
  uint8_T shift_factor;                // '<Root>/Calibrator'
  uint8_T shift_factor_c;              // '<Root>/Calibrator'
  uint8_T shift_factor_k;              // '<Root>/Calibrator'
  uint8_T encoder_tolerance;           // '<Root>/Calibrator'
  uint8_T pole_pairs;                  // '<Root>/Calibrator'
  boolean_T TmpRTBAtCalibratorInport2;
  boolean_T TmpRTBAtCalibratorInport3;
  boolean_T TmpRTBAtCalibratorInport4;
  boolean_T TmpRTBAtCalibratorInport5;
  boolean_T TmpRTBAtCalibratorInport54;
  boolean_T TmpRTBAtCalibratorInport55;
  boolean_T TmpRTBAtCalibratorInport56;
  boolean_T TmpRTBAtCalibratorInport57;
  boolean_T TmpRTBAtCalibratorInport58;
  boolean_T TmpRTBAtCalibratorInport63;
  boolean_T finish;                    // '<Root>/Calibrator'
  boolean_T enable_verbosity;          // '<Root>/Calibrator'
  boolean_T has_hall_sens;             // '<Root>/Calibrator'
  boolean_T has_quadrature_encoder;    // '<Root>/Calibrator'
  boolean_T has_speed_quadrature_encoder;// '<Root>/Calibrator'
  boolean_T has_temperature_sens;      // '<Root>/Calibrator'
  boolean_T use_index;                 // '<Root>/Calibrator'
  boolean_T vel_en;                    // '<Root>/Calibrator'
  boolean_T cur_en;                    // '<Root>/Calibrator'
  boolean_T out_en;                    // '<Root>/Calibrator'
  boolean_T pid_reset;                 // '<Root>/Calibrator'
};

// Block states (default storage) for model 'motion_controller'
struct DW_motion_controller_f_T {
  FOCSlowInputs TmpRTBAtBusCreatorOutport1_Buf[3];// synthesized block
  SensorsData TmpRTBAtFOCInport1_Buf[3];// synthesized block
  SensorsData Transitionto1ms_Buf0;    // '<Root>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf1;    // '<Root>/Transition to 1ms'
  SensorsData Transitionto1ms_Buf2;    // '<Root>/Transition to 1ms'
  FOCOutputs RateTransition2_Buf0;     // '<Root>/Rate Transition2'
  FOCOutputs RateTransition2_Buf1;     // '<Root>/Rate Transition2'
  FOCOutputs RateTransition2_Buf2;     // '<Root>/Rate Transition2'
  void* TmpRTBAtCalibratorInport24_SEMAPHORE;// synthesized block
  void* TmpRTBAtCalibratorInport34_SEMAPHORE;// synthesized block
  void* TmpRTBAtCalibratorInport44_SEMAPHORE;// synthesized block
  void* TmpRTBAtCalibratorInport6_SEMAPHORE;// synthesized block
  void* TmpRTBAtCalibratorInport74_SEMAPHORE;// synthesized block
  void* RateTransition1_6_SEMAPHORE;   // '<Root>/Rate Transition1'
  void* RateTransition3_6_SEMAPHORE;   // '<Root>/Rate Transition3'
  void* RateTransition_3_SEMAPHORE;    // '<Root>/Rate Transition'
  void* RateTransition_11_SEMAPHORE;   // '<Root>/Rate Transition'
  void* RateTransition_21_SEMAPHORE;   // '<Root>/Rate Transition'
  void* RateTransition_31_SEMAPHORE;   // '<Root>/Rate Transition'
  void* RateTransition_61_SEMAPHORE;   // '<Root>/Rate Transition'
  void* TmpRTBAtFOCInport1_SEMAPHORE;  // synthesized block
  void* RateTransition2_SEMAPHORE;     // '<Root>/Rate Transition2'
  void* Flags_SEMAPHORE;               // synthesized block
  void* TmpRTBAtBusCreatorOutport1_SEMAPHORE;// synthesized block
  void* Transitionto1ms_SEMAPHORE;     // '<Root>/Transition to 1ms'
  volatile real32_T ConfigurationParameters_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport20_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport21_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport23_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport25_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport26_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport27_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport28_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport29_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport30_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport31_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport32_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport35_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport36_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport37_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport38_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport39_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport40_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport41_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport42_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport45_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport46_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport47_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport48_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport49_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport50_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport51_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport52_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport64_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport65_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport66_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport67_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport68_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport69_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport70_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport71_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport72_Buffer0;// synthesized block
  volatile real32_T TmpRTBAtCalibratorInport73_Buffer0;// synthesized block
  real32_T RateTransition1_6_Buf0[3];  // '<Root>/Rate Transition1'
  real32_T RateTransition1_6_Buf1[3];  // '<Root>/Rate Transition1'
  real32_T RateTransition1_6_Buf2[3];  // '<Root>/Rate Transition1'
  real32_T RateTransition3_6_Buf0[3];  // '<Root>/Rate Transition3'
  real32_T RateTransition3_6_Buf1[3];  // '<Root>/Rate Transition3'
  real32_T RateTransition3_6_Buf2[3];  // '<Root>/Rate Transition3'
  volatile real32_T RateTransition_1_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_2_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_5_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_6_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_7_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_8_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_10_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_12_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_13_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_14_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_15_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_16_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_17_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_18_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_19_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_22_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_23_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_24_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_25_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_26_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_27_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_28_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_29_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_32_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_33_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_34_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_35_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_36_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_37_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_38_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_39_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_51_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_52_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_53_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_54_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_55_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_56_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_57_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_58_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_59_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_60_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_62_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_63_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_64_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_65_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_66_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_67_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_68_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_69_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_74_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T RateTransition_75_Buffer0;// '<Root>/Rate Transition'
  volatile real32_T TmpRTBAtCalibratorInport19_Buffer0;// synthesized block
  volatile uint32_T TmpRTBAtCalibratorInport22_Buffer0;// synthesized block
  volatile uint32_T RateTransition_4_Buffer0;// '<Root>/Rate Transition'
  volatile uint32_T RateTransition_9_Buffer0;// '<Root>/Rate Transition'
  ControlModes TmpRTBAtCalibratorInport24_Buf[3];// synthesized block
  ControlModes TmpRTBAtCalibratorInport34_Buf[3];// synthesized block
  ControlModes TmpRTBAtCalibratorInport44_Buf[3];// synthesized block
  ControlModes TmpRTBAtCalibratorInport6_Buf[3];// synthesized block
  ControlModes RateTransition_11_Buf[3];// '<Root>/Rate Transition'
  ControlModes RateTransition_21_Buf[3];// '<Root>/Rate Transition'
  ControlModes RateTransition_31_Buf[3];// '<Root>/Rate Transition'
  ReferenceEncoder TmpRTBAtCalibratorInport74_Buf[3];// synthesized block
  ReferenceEncoder RateTransition_61_Buf[3];// '<Root>/Rate Transition'
  EstimationVelocityModes RateTransition_3_Buf[3];// '<Root>/Rate Transition'
  CalibrationTypes Flags_Buf[3];       // synthesized block
  volatile int16_T TmpRTBAtCalibratorInport61_Buffer0;// synthesized block
  volatile int16_T TmpRTBAtCalibratorInport62_Buffer0;// synthesized block
  volatile int16_T RateTransition_48_Buffer0;// '<Root>/Rate Transition'
  volatile int16_T RateTransition_49_Buffer0;// '<Root>/Rate Transition'
  volatile int16_T ConfigurationParameters_Buffer0_a;// synthesized block
  int8_T TmpRTBAtCalibratorInport24_LstBufWR;// synthesized block
  int8_T TmpRTBAtCalibratorInport24_RDBuf;// synthesized block
  int8_T TmpRTBAtCalibratorInport34_LstBufWR;// synthesized block
  int8_T TmpRTBAtCalibratorInport34_RDBuf;// synthesized block
  int8_T TmpRTBAtCalibratorInport44_LstBufWR;// synthesized block
  int8_T TmpRTBAtCalibratorInport44_RDBuf;// synthesized block
  int8_T TmpRTBAtCalibratorInport6_LstBufWR;// synthesized block
  int8_T TmpRTBAtCalibratorInport6_RDBuf;// synthesized block
  int8_T TmpRTBAtCalibratorInport74_LstBufWR;// synthesized block
  int8_T TmpRTBAtCalibratorInport74_RDBuf;// synthesized block
  int8_T RateTransition1_6_LstBufWR;   // '<Root>/Rate Transition1'
  int8_T RateTransition1_6_RDBuf;      // '<Root>/Rate Transition1'
  int8_T RateTransition3_6_LstBufWR;   // '<Root>/Rate Transition3'
  int8_T RateTransition3_6_RDBuf;      // '<Root>/Rate Transition3'
  int8_T RateTransition_3_LstBufWR;    // '<Root>/Rate Transition'
  int8_T RateTransition_3_RDBuf;       // '<Root>/Rate Transition'
  int8_T RateTransition_11_LstBufWR;   // '<Root>/Rate Transition'
  int8_T RateTransition_11_RDBuf;      // '<Root>/Rate Transition'
  int8_T RateTransition_21_LstBufWR;   // '<Root>/Rate Transition'
  int8_T RateTransition_21_RDBuf;      // '<Root>/Rate Transition'
  int8_T RateTransition_31_LstBufWR;   // '<Root>/Rate Transition'
  int8_T RateTransition_31_RDBuf;      // '<Root>/Rate Transition'
  int8_T RateTransition_61_LstBufWR;   // '<Root>/Rate Transition'
  int8_T RateTransition_61_RDBuf;      // '<Root>/Rate Transition'
  int8_T TmpRTBAtFOCInport1_LstBufWR;  // synthesized block
  int8_T TmpRTBAtFOCInport1_RDBuf;     // synthesized block
  int8_T RateTransition2_LstBufWR;     // '<Root>/Rate Transition2'
  int8_T RateTransition2_RDBuf;        // '<Root>/Rate Transition2'
  int8_T Flags_LstBufWR;               // synthesized block
  int8_T Flags_RDBuf;                  // synthesized block
  int8_T TmpRTBAtBusCreatorOutport1_LstBufWR;// synthesized block
  int8_T TmpRTBAtBusCreatorOutport1_RDBuf;// synthesized block
  int8_T Transitionto1ms_LstBufWR;     // '<Root>/Transition to 1ms'
  int8_T Transitionto1ms_RDBuf;        // '<Root>/Transition to 1ms'
  volatile uint8_T TmpRTBAtCalibratorInport33_Buffer0;// synthesized block
  volatile uint8_T TmpRTBAtCalibratorInport43_Buffer0;// synthesized block
  volatile uint8_T TmpRTBAtCalibratorInport53_Buffer0;// synthesized block
  volatile uint8_T TmpRTBAtCalibratorInport59_Buffer0;// synthesized block
  volatile uint8_T TmpRTBAtCalibratorInport60_Buffer0;// synthesized block
  volatile uint8_T RateTransition_20_Buffer0;// '<Root>/Rate Transition'
  volatile uint8_T RateTransition_30_Buffer0;// '<Root>/Rate Transition'
  volatile uint8_T RateTransition_40_Buffer0;// '<Root>/Rate Transition'
  volatile uint8_T RateTransition_46_Buffer0;// '<Root>/Rate Transition'
  volatile uint8_T RateTransition_47_Buffer0;// '<Root>/Rate Transition'
  volatile uint8_T ConfigurationParameters_Buffer0_o;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport2_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport3_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport4_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport5_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport54_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport55_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport56_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport57_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport58_Buffer0;// synthesized block
  volatile boolean_T TmpRTBAtCalibratorInport63_Buffer0;// synthesized block
  volatile boolean_T RateTransition_41_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_42_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_43_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_44_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_45_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_50_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_70_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_71_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_72_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T RateTransition_73_Buffer0;// '<Root>/Rate Transition'
  volatile boolean_T finish_Buffer0;   // synthesized block
  volatile boolean_T ConfigurationParameters_Buffer0_m;// synthesized block
  MdlrefDW_Calibrator_T Calibrator_InstanceData;// '<Root>/Calibrator'
  MdlrefDW_control_foc_T FOC_InstanceData;// '<Root>/FOC'
  MdlrefDW_estimation_velocity_T MotorVelocityEstimator_InstanceData;// '<S1>/Motor Velocity Estimator' 
  MdlrefDW_filter_current_T CurrentFilter_InstanceData;// '<S1>/Current Filter'
  MdlrefDW_estimation_velocity_T JointVelocityEstimator_InstanceData;// '<S1>/Joint Velocity Estimator' 
  MdlrefDW_supervisor_T MotorSupervisor_InstanceData;// '<Root>/Motor Supervisor' 
  MdlrefDW_position_velocity_cascade_T Positionvelocitycascade_InstanceData;// '<Root>/Position velocity cascade' 
};

struct MdlrefDW_motion_controller_T {
  B_motion_controller_c_T rtb;
  DW_motion_controller_f_T rtdw;
};

// Model reference registration function
extern void motion_controller_initialize(DW_motion_controller_f_T *localDW);
extern void motion_controller_Init(Flags *rty_Flags, ActuatorConfiguration
  *rty_ActuatorsConfiguration, B_motion_controller_c_T *localB,
  DW_motion_controller_f_T *localDW);
extern void motion_controller_Enable(DW_motion_controller_f_T *localDW);
extern void motion_controller_Disable(DW_motion_controller_f_T *localDW);
extern void motion_controllerTID0(B_motion_controller_c_T *localB,
  DW_motion_controller_f_T *localDW);
extern void motion_controllerTID1(FOCOutputs *rty_FOCOutputs,
  B_motion_controller_c_T *localB, DW_motion_controller_f_T *localDW);
extern void motion_controllerTID2(const SensorsData *rtu_SensorData,
  B_motion_controller_c_T *localB, DW_motion_controller_f_T *localDW);
extern void mc_step_1ms(const ExternalFlags *rtu_ExternalFlags, const
  ReceivedEvents rtu_Events[4], const ActuatorConfiguration *rtu_InitConf, const
  JointData *rtu_JointData, EstimatedData *rty_EstimatedData, Flags *rty_Flags,
  ActuatorConfiguration *rty_ActuatorsConfiguration, SensorsData
  *rty_SensorData_out, B_motion_controller_c_T *localB, DW_motion_controller_f_T
  *localDW);
extern void motion_controller_Term(DW_motion_controller_f_T *localDW);

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S9>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/ReplaceInport_CountsPerRev' : Unused code path elimination
//  Block '<S7>/ReplaceInport_OneByCountsPerRev' : Unused code path elimination
//  Block '<S3>/Zero-Order Hold2' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'motion_controller'
//  '<S1>'   : 'motion_controller/Estimation'
//  '<S2>'   : 'motion_controller/Global configuration'
//  '<S3>'   : 'motion_controller/Process Sensors'
//  '<S4>'   : 'motion_controller/Estimation/Thermal model'
//  '<S5>'   : 'motion_controller/Estimation/Thermal model/Thermal model OFF'
//  '<S6>'   : 'motion_controller/Process Sensors/Mechanical to Electrical Position'
//  '<S7>'   : 'motion_controller/Process Sensors/Quadrature Decoder'
//  '<S8>'   : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec'
//  '<S9>'   : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point'
//  '<S10>'  : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
//  '<S11>'  : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
//  '<S12>'  : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
//  '<S13>'  : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
//  '<S14>'  : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
//  '<S15>'  : 'motion_controller/Process Sensors/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Input Port'
//  '<S16>'  : 'motion_controller/Process Sensors/Quadrature Decoder/DT_Handle'
//  '<S17>'  : 'motion_controller/Process Sensors/Quadrature Decoder/PositionNoReset'
//  '<S18>'  : 'motion_controller/Process Sensors/Quadrature Decoder/PositionResetAtIndex'
//  '<S19>'  : 'motion_controller/Process Sensors/Quadrature Decoder/Variant Subsystem'
//  '<S20>'  : 'motion_controller/Process Sensors/Quadrature Decoder/DT_Handle/floating-point'
//  '<S21>'  : 'motion_controller/Process Sensors/Quadrature Decoder/PositionNoReset/Variant Subsystem'
//  '<S22>'  : 'motion_controller/Process Sensors/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
//  '<S23>'  : 'motion_controller/Process Sensors/Quadrature Decoder/Variant Subsystem/Dialog'

#endif                                 // motion_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
