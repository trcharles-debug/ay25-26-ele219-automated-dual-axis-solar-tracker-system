/*
 * arduino_motor_encoder_open_loop_private.h
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

#ifndef arduino_motor_encoder_open_loop_private_h_
#define arduino_motor_encoder_open_loop_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "arduino_motor_encoder_open_loop_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                          /* arduino_motor_encoder_open_loop_private_h_ */
