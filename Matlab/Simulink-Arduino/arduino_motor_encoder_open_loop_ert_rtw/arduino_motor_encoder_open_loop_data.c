/*
 * arduino_motor_encoder_open_loop_data.c
 *
 * Code generation for model "arduino_motor_encoder_open_loop".
 *
 * Model version              : 3.7
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Tue May  5 22:26:30 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_motor_encoder_open_loop.h"

/* Block parameters (default storage) */
P_arduino_motor_encoder_open__T arduino_motor_encoder_open_lo_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S6>/UD'
   */
  0.05,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_j
   * Referenced by: '<S10>/UD'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 2*pi/(169*64)
   * Referenced by: '<S3>/Gear_Ratio'
   */
  0.00058091580132947358,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S6>/TSamp'
   */
  100.0,

  /* Expression: 2*pi/60
   * Referenced by: '<S1>/rad//s To RPM'
   */
  0.10471975511965977,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Switch'
   */
  0.0,

  /* Expression: 2*pi/(169*64)
   * Referenced by: '<S7>/Gear_Ratio'
   */
  0.00058091580132947358,

  /* Computed Parameter: TSamp_WtEt_k
   * Referenced by: '<S10>/TSamp'
   */
  100.0,

  /* Expression: 2*pi/60
   * Referenced by: '<S2>/rad//s To RPM'
   */
  0.10471975511965977
};
