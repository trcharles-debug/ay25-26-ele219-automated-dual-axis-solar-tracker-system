/*
 * arduino_encoder_inc.h
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

#ifndef RTW_HEADER_arduino_encoder_inc_h_
#define RTW_HEADER_arduino_encoder_inc_h_
#ifndef arduino_encoder_inc_COMMON_INCLUDES_
#define arduino_encoder_inc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                /* arduino_encoder_inc_COMMON_INCLUDES_ */

#include "arduino_encoder_inc_types.h"
#include <string.h>
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Pulsessec;                    /* '<S1>/Divide' */
  real_T rpm;                          /* '<S1>/Product1' */
  uint8_T TotalPulses;                 /* '<S1>/Add' */
  uint8_T Add1;                        /* '<S1>/Add1' */
} B_arduino_encoder_inc_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S1>/Digital Input' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  uint8_T Delay_DSTATE;                /* '<S1>/Delay' */
  uint8_T Delay1_DSTATE[100];          /* '<S1>/Delay1' */
  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
  boolean_T objisempty;                /* '<S1>/Digital Input' */
} DW_arduino_encoder_inc_T;

/* Parameters (default storage) */
struct P_arduino_encoder_inc_T_ {
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S2>/Delay Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S1>/Digital Input'
                                        */
  real_T Constant2_Value;              /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi/5670
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 60/2*pi
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint8_T Delay_InitialCondition;  /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S1>/Delay'
                                    */
  uint8_T Delay1_InitialCondition;/* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S1>/Delay1'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_arduino_encoder_inc_T {
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
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_arduino_encoder_inc_T arduino_encoder_inc_P;

/* Block signals (default storage) */
extern B_arduino_encoder_inc_T arduino_encoder_inc_B;

/* Block states (default storage) */
extern DW_arduino_encoder_inc_T arduino_encoder_inc_DW;

/* Model entry point functions */
extern void arduino_encoder_inc_initialize(void);
extern void arduino_encoder_inc_step(void);
extern void arduino_encoder_inc_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduino_encoder_inc_T *const arduino_encoder_inc_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'arduino_encoder_inc'
 * '<S1>'   : 'arduino_encoder_inc/Right Wheel Encoder '
 * '<S2>'   : 'arduino_encoder_inc/Right Wheel Encoder /Detect Increase'
 */
#endif                                 /* RTW_HEADER_arduino_encoder_inc_h_ */
