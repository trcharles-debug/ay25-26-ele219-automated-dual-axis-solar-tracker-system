/*
 * arduino_motor_encoder_data.c
 *
 * Code generation for model "arduino_motor_encoder".
 *
 * Model version              : 1.92
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 22 02:32:37 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_motor_encoder.h"

/* Block parameters (default storage) */
P_arduino_motor_encoder_T arduino_motor_encoder_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  { { 0x47AE147BUL, 0x1UL } },

  /* Expression: 0.05
   * Referenced by: '<S1>/Encoder'
   */
  0.05,

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

  /* Expression: 129.8331052311435
   * Referenced by: '<Root>/Constant'
   */
  129.83310523114349,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  { { 0x70698F08UL, 0x7297UL } },

  /* Computed Parameter: Gear_Ratio_Gain
   * Referenced by: '<Root>/Gear_Ratio'
   */
  { { 0xEFAF5400UL, 0x6B3BA7CDUL } },

  /* Computed Parameter: Gear_Ratio_Gain_a
   * Referenced by: '<S1>/Gear_Ratio'
   */
  1277447357
};
