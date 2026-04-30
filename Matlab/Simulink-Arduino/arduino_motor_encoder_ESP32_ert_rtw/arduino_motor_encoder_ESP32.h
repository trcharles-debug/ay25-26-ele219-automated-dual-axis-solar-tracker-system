/*
 * File: arduino_motor_encoder_ESP32.h
 *
 * Code generated for Simulink model 'arduino_motor_encoder_ESP32'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Apr 30 13:08:46 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_arduino_motor_encoder_ESP32_h_
#define RTW_HEADER_arduino_motor_encoder_ESP32_h_
#ifndef arduino_motor_encoder_ESP32_COMMON_INCLUDES_
#define arduino_motor_encoder_ESP32_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                        /* arduino_motor_encoder_ESP32_COMMON_INCLUDES_ */

#include "arduino_motor_encoder_ESP32_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/IN2' */
  codertarget_arduinobase_block_T obj_m;/* '<S2>/IN1' */
  codertarget_arduinobase_int_g_T obj_g;/* '<S2>/ENA1' */
} DW_arduino_motor_encoder_ESP3_T;

/* Parameters (default storage) */
struct P_arduino_motor_encoder_ESP32_T_ {
  real_T Encoder_SampleTime;           /* Expression: 0.05
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: -3.819571167883225
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_arduino_motor_encoder_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_arduino_motor_encoder_ESP32_T arduino_motor_encoder_ESP32_P;

/* Block states (default storage) */
extern DW_arduino_motor_encoder_ESP3_T arduino_motor_encoder_ESP32_DW;

/* Model entry point functions */
extern void arduino_motor_encoder_ESP32_initialize(void);
extern void arduino_motor_encoder_ESP32_step(void);
extern void arduino_motor_encoder_ESP32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduino_motor_encode_T *const arduino_motor_encoder_ESP32_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Diff' : Unused code path elimination
 * Block '<S4>/TSamp' : Unused code path elimination
 * Block '<S4>/UD' : Unused code path elimination
 * Block '<S1>/Gear_Ratio' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S3>/Gain' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Sine Wave' : Unused code path elimination
 * Block '<Root>/rad//sToRPM' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'arduino_motor_encoder_ESP32'
 * '<S1>'   : 'arduino_motor_encoder_ESP32/Azimut Encoder'
 * '<S2>'   : 'arduino_motor_encoder_ESP32/Azimut Motor'
 * '<S3>'   : 'arduino_motor_encoder_ESP32/Radians to Degrees'
 * '<S4>'   : 'arduino_motor_encoder_ESP32/Azimut Encoder/Discrete Derivative'
 */
#endif                           /* RTW_HEADER_arduino_motor_encoder_ESP32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
