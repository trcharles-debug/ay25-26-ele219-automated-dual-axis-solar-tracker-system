/*
 * arduino_encoder_inc_data.c
 *
 * Code generation for model "arduino_encoder_inc".
 *
 * Model version              : 1.54
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Fri Mar 22 20:00:54 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_encoder_inc.h"

/* Block parameters (default storage) */
P_arduino_encoder_inc_T arduino_encoder_inc_P = {
  /* Mask Parameter: DetectIncrease_vinit
   * Referenced by: '<S2>/Delay Input1'
   */
  false,

  /* Expression: -1
   * Referenced by: '<S1>/Digital Input'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Constant2'
   */
  0.5,

  /* Expression: 2*pi/5670
   * Referenced by: '<S1>/Constant1'
   */
  0.0011081455568217966,

  /* Expression: 60/2*pi
   * Referenced by: '<S1>/Constant3'
   */
  94.247779607693786,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S1>/Delay'
   */
  0U,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S1>/Delay1'
   */
  0U
};
