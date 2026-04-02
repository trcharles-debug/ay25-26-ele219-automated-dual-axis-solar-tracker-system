/*
 * arduino_PWM_motor_private.h
 *
 * Code generation for model "arduino_PWM_motor".
 *
 * Model version              : 1.14
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Mar 21 13:41:33 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_arduino_PWM_motor_private_h_
#define RTW_HEADER_arduino_PWM_motor_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "arduino_PWM_motor_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                             /* RTW_HEADER_arduino_PWM_motor_private_h_ */
