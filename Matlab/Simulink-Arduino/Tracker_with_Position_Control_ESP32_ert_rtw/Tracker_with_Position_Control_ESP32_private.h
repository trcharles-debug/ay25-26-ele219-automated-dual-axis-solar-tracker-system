/*
 * Tracker_with_Position_Control_ESP32_private.h
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

#ifndef Tracker_with_Position_Control_ESP32_private_h_
#define Tracker_with_Position_Control_ESP32_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Tracker_with_Position_Control_ESP32_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                      /* Tracker_with_Position_Control_ESP32_private_h_ */
