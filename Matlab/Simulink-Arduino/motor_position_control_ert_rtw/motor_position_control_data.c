/*
 * motor_position_control_data.c
 *
 * Code generation for model "motor_position_control".
 *
 * Model version              : 1.119
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sun May  3 23:07:59 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_position_control.h"

/* Block parameters (default storage) */
P_motor_position_control_T motor_position_control_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S33>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S37>/Integral Gain'
   */
  0.001,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S35>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_f
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S43>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  0.01,

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

  /* Expression: 90
   * Referenced by: '<Root>/Azimut'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<Root>/Azimut'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<Root>/Azimut'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<Root>/Azimut'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S40>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S35>/Filter'
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
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 2*pi/(169*64)
   * Referenced by: '<S3>/Gear_Ratio'
   */
  0.00058091580132947358,

  /* Expression: 180/pi
   * Referenced by: '<S1>/rad//s To RPM1'
   */
  57.295779513082323
};
