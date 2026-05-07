/*
 * Tracker_with_Position_Control_ESP32_data.c
 *
 * Code generation for model "Tracker_with_Position_Control_ESP32".
 *
 * Model version              : 3.4
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed May  6 00:29:00 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Tracker_with_Position_Control_ESP32.h"

/* Block parameters (default storage) */
P_Tracker_with_Position_Contr_T Tracker_with_Position_Control_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S40>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S92>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S44>/Integral Gain'
   */
  0.005,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S96>/Integral Gain'
   */
  0.005,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S42>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S94>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_f
   * Referenced by: '<S47>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_j
   * Referenced by: '<S99>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S50>/Filter Coefficient'
   */
  0.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S102>/Filter Coefficient'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S52>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S104>/Proportional Gain'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S6>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant4'
   */
  0.0,

  /* Expression: 90
   * Referenced by: '<Root>/Constant'
   */
  90.0,

  /* Expression: 2*pi/(169*64)
   * Referenced by: '<S5>/Gear_Ratio'
   */
  0.00058091580132947358,

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S47>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S42>/Filter'
   */
  0.01,

  /* Expression: 255
   * Referenced by: '<Root>/Gain'
   */
  255.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<Root>/Saturation'
   */
  -255.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 2*pi/(169*64)
   * Referenced by: '<S9>/Gear_Ratio'
   */
  0.00058091580132947358,

  /* Expression: 180/pi
   * Referenced by: '<S11>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S99>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval_n
   * Referenced by: '<S94>/Filter'
   */
  0.01,

  /* Expression: 255
   * Referenced by: '<Root>/Gain1'
   */
  255.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation1'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<Root>/Saturation1'
   */
  -255.0,

  /* Expression: 0
   * Referenced by: '<S10>/Switch'
   */
  0.0
};
