/*
 * arduino_motor_encoder_open_loop_data.c
 *
 * Code generation for model "arduino_motor_encoder_open_loop".
 *
 * Model version              : 1.96
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 22 20:11:51 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_motor_encoder_open_loop.h"

/* Block parameters (default storage) */
P_arduino_motor_encoder_open__T arduino_motor_encoder_open_lo_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  0.05,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant4'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Step'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<Root>/Step'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 2*pi/(169*64)
   * Referenced by: '<S1>/Gear_Ratio'
   */
  0.00058091580132947358,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S4>/TSamp'
   */
  100.0,

  /* Expression: 2*pi/60
   * Referenced by: '<Root>/rad//sToRPM'
   */
  0.10471975511965977
};
