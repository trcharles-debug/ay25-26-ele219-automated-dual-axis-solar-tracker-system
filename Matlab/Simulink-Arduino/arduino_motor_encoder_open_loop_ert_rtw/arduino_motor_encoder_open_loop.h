/*
 * arduino_motor_encoder_open_loop.h
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

#ifndef arduino_motor_encoder_open_loop_h_
#define arduino_motor_encoder_open_loop_h_
#ifndef arduino_motor_encoder_open_loop_COMMON_INCLUDES_
#define arduino_motor_encoder_open_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                    /* arduino_motor_encoder_open_loop_COMMON_INCLUDES_ */

#include "arduino_motor_encoder_open_loop_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define arduino_motor_encoder_open_loop_M (arduino_motor_encoder_open_l_M)

/* Block signals (default storage) */
typedef struct {
  real_T Constant;                     /* '<Root>/Constant' */
  real_T radsToRPM;                    /* '<S1>/rad//s To RPM' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T radsToRPM_k;                  /* '<S2>/rad//s To RPM' */
} B_arduino_motor_encoder_open__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S8>/IN4' */
  codertarget_arduinobase_block_T obj_c;/* '<S8>/IN3' */
  codertarget_arduinobase_block_T obj_e;/* '<S4>/IN2' */
  codertarget_arduinobase_block_T obj_o;/* '<S4>/IN1' */
  codertarget_arduinobase_inter_T obj_l;/* '<S7>/Encoder' */
  codertarget_arduinobase_inter_T obj_b;/* '<S3>/Encoder' */
  codertarget_arduinobase_int_i_T obj_p;/* '<S8>/ENB' */
  codertarget_arduinobase_int_i_T obj_d;/* '<S4>/ENA1' */
  real_T UD_DSTATE;                    /* '<S6>/UD' */
  real_T UD_DSTATE_b;                  /* '<S10>/UD' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_arduino_motor_encoder_open_T;

/* Parameters (default storage) */
struct P_arduino_motor_encoder_open__T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S6>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_j;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_j
                               * Referenced by: '<S10>/UD'
                               */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant5_Value_e;            /* Expression: 1
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T Constant4_Value_p;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Gear_Ratio_Gain;              /* Expression: 2*pi/(169*64)
                                        * Referenced by: '<S3>/Gear_Ratio'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S6>/TSamp'
                                        */
  real_T radsToRPM_Gain;               /* Expression: 2*pi/60
                                        * Referenced by: '<S1>/rad//s To RPM'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Gear_Ratio_Gain_m;            /* Expression: 2*pi/(169*64)
                                        * Referenced by: '<S7>/Gear_Ratio'
                                        */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S10>/TSamp'
                                        */
  real_T radsToRPM_Gain_n;             /* Expression: 2*pi/60
                                        * Referenced by: '<S2>/rad//s To RPM'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_arduino_motor_encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_arduino_motor_encoder_open__T arduino_motor_encoder_open_lo_P;

/* Block signals (default storage) */
extern B_arduino_motor_encoder_open__T arduino_motor_encoder_open_lo_B;

/* Block states (default storage) */
extern DW_arduino_motor_encoder_open_T arduino_motor_encoder_open_l_DW;

/* Model entry point functions */
extern void arduino_motor_encoder_open_loop_initialize(void);
extern void arduino_motor_encoder_open_loop_step(void);
extern void arduino_motor_encoder_open_loop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduino_motor_encode_T *const arduino_motor_encoder_open_l_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Gain' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Gain' : Unused code path elimination
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
 * '<Root>' : 'arduino_motor_encoder_open_loop'
 * '<S1>'   : 'arduino_motor_encoder_open_loop/Azimuth Motor'
 * '<S2>'   : 'arduino_motor_encoder_open_loop/Elevator Motor1'
 * '<S3>'   : 'arduino_motor_encoder_open_loop/Azimuth Motor/Azimuth Encoder'
 * '<S4>'   : 'arduino_motor_encoder_open_loop/Azimuth Motor/Azimuth Motor'
 * '<S5>'   : 'arduino_motor_encoder_open_loop/Azimuth Motor/Radians to Degrees'
 * '<S6>'   : 'arduino_motor_encoder_open_loop/Azimuth Motor/Azimuth Encoder/Discrete Derivative'
 * '<S7>'   : 'arduino_motor_encoder_open_loop/Elevator Motor1/Elevator Encoder'
 * '<S8>'   : 'arduino_motor_encoder_open_loop/Elevator Motor1/Elevator Motor'
 * '<S9>'   : 'arduino_motor_encoder_open_loop/Elevator Motor1/Radians to Degrees'
 * '<S10>'  : 'arduino_motor_encoder_open_loop/Elevator Motor1/Elevator Encoder/Discrete Derivative'
 */
#endif                                 /* arduino_motor_encoder_open_loop_h_ */
