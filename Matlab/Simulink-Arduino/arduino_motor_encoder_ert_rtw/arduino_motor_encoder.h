/*
 * arduino_motor_encoder.h
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

#ifndef RTW_HEADER_arduino_motor_encoder_h_
#define RTW_HEADER_arduino_motor_encoder_h_
#ifndef arduino_motor_encoder_COMMON_INCLUDES_
#define arduino_motor_encoder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                              /* arduino_motor_encoder_COMMON_INCLUDES_ */

#include "arduino_motor_encoder_types.h"
#include "multiword_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  int128m_T Gear_Ratio;                /* '<Root>/Gear_Ratio' */
  int64m_T Gain;                       /* '<S3>/Gain' */
} B_arduino_motor_encoder_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_int_h_T obj_g;/* '<S2>/ENA1' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/IN2' */
  codertarget_arduinobase_block_T obj_m;/* '<S2>/IN1' */
  int64m_T UD_DSTATE;                  /* '<S4>/UD' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<S2>/IN2' */
  boolean_T objisempty_a;              /* '<S2>/IN1' */
  boolean_T objisempty_aw;             /* '<S2>/ENA1' */
  boolean_T objisempty_e;              /* '<S1>/Encoder' */
} DW_arduino_motor_encoder_T;

/* Parameters (default storage) */
struct P_arduino_motor_encoder_T_ {
  int64m_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S4>/UD'
                               */
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
  real_T Constant_Value;               /* Expression: 129.8331052311435
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  int64m_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  int64m_T Gear_Ratio_Gain;            /* Computed Parameter: Gear_Ratio_Gain
                                        * Referenced by: '<Root>/Gear_Ratio'
                                        */
  int32_T Gear_Ratio_Gain_a;           /* Computed Parameter: Gear_Ratio_Gain_a
                                        * Referenced by: '<S1>/Gear_Ratio'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_arduino_motor_encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_arduino_motor_encoder_T arduino_motor_encoder_P;

/* Block signals (default storage) */
extern B_arduino_motor_encoder_T arduino_motor_encoder_B;

/* Block states (default storage) */
extern DW_arduino_motor_encoder_T arduino_motor_encoder_DW;

/* Model entry point functions */
extern void arduino_motor_encoder_initialize(void);
extern void arduino_motor_encoder_step(void);
extern void arduino_motor_encoder_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduino_motor_encode_T *const arduino_motor_encoder_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Sine Wave' : Unused code path elimination
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
 * '<Root>' : 'arduino_motor_encoder'
 * '<S1>'   : 'arduino_motor_encoder/Azimut Encoder'
 * '<S2>'   : 'arduino_motor_encoder/Azimut Motor'
 * '<S3>'   : 'arduino_motor_encoder/Radians to Degrees'
 * '<S4>'   : 'arduino_motor_encoder/Azimut Encoder/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_arduino_motor_encoder_h_ */
