/*
 * motor_position_control.h
 *
 * Code generation for model "motor_position_control".
 *
 * Model version              : 1.118
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 22 10:53:50 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_position_control_h_
#define RTW_HEADER_motor_position_control_h_
#ifndef motor_position_control_COMMON_INCLUDES_
#define motor_position_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                             /* motor_position_control_COMMON_INCLUDES_ */

#include "motor_position_control_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSumInport2;           /* '<Root>/Azimuth Motor' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T radsToRPM1;                   /* '<S1>/rad//s To RPM1' */
} B_motor_position_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder' */
  codertarget_arduinobase_int_e_T obj_g;/* '<S4>/ENA1' */
  codertarget_arduinobase_block_T obj_d;/* '<S4>/IN2' */
  codertarget_arduinobase_block_T obj_e;/* '<S4>/IN1' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<S4>/IN2' */
  boolean_T objisempty_j;              /* '<S4>/IN1' */
  boolean_T objisempty_a;              /* '<S4>/ENA1' */
  boolean_T objisempty_i;              /* '<S3>/Encoder' */
} DW_motor_position_control_T;

/* Parameters (default storage) */
struct P_motor_position_control_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S32>/Filter'
                               */
  real_T PIDController_InitialConditio_f;
                              /* Mask Parameter: PIDController_InitialConditio_f
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S40>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T Encoder_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<S3>/Encoder'
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
  real_T Azimut_Amp;                   /* Expression: 90
                                        * Referenced by: '<Root>/Azimut'
                                        */
  real_T Azimut_Bias;                  /* Expression: 0
                                        * Referenced by: '<Root>/Azimut'
                                        */
  real_T Azimut_Freq;                  /* Expression: pi
                                        * Referenced by: '<Root>/Azimut'
                                        */
  real_T Azimut_Phase;                 /* Expression: 0
                                        * Referenced by: '<Root>/Azimut'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S37>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S32>/Filter'
                                        */
  real_T Gain_Gain;                    /* Expression: 255
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Gear_Ratio_Gain;              /* Expression: 2*pi/(169*64)
                                        * Referenced by: '<S3>/Gear_Ratio'
                                        */
  real_T radsToRPM1_Gain;              /* Expression: 180/pi
                                        * Referenced by: '<S1>/rad//s To RPM1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_position_contro_T {
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
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_position_control_T motor_position_control_P;

/* Block signals (default storage) */
extern B_motor_position_control_T motor_position_control_B;

/* Block states (default storage) */
extern DW_motor_position_control_T motor_position_control_DW;

/* External function called from main */
extern void motor_position_control_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void motor_position_control_initialize(void);
extern void motor_position_control_step0(void);
extern void motor_position_control_step2(void);
extern void motor_position_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_position_contr_T *const motor_position_control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Diff' : Unused code path elimination
 * Block '<S5>/TSamp' : Unused code path elimination
 * Block '<S5>/UD' : Unused code path elimination
 * Block '<S1>/rad//s To RPM' : Unused code path elimination
 * Block '<Root>/Elevation' : Unused code path elimination
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
 * '<Root>' : 'motor_position_control'
 * '<S1>'   : 'motor_position_control/Azimuth Motor'
 * '<S2>'   : 'motor_position_control/PID Controller'
 * '<S3>'   : 'motor_position_control/Azimuth Motor/Azimut Encoder'
 * '<S4>'   : 'motor_position_control/Azimuth Motor/Azimut Motor'
 * '<S5>'   : 'motor_position_control/Azimuth Motor/Azimut Encoder/Discrete Derivative'
 * '<S6>'   : 'motor_position_control/PID Controller/Anti-windup'
 * '<S7>'   : 'motor_position_control/PID Controller/D Gain'
 * '<S8>'   : 'motor_position_control/PID Controller/Filter'
 * '<S9>'   : 'motor_position_control/PID Controller/Filter ICs'
 * '<S10>'  : 'motor_position_control/PID Controller/I Gain'
 * '<S11>'  : 'motor_position_control/PID Controller/Ideal P Gain'
 * '<S12>'  : 'motor_position_control/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'motor_position_control/PID Controller/Integrator'
 * '<S14>'  : 'motor_position_control/PID Controller/Integrator ICs'
 * '<S15>'  : 'motor_position_control/PID Controller/N Copy'
 * '<S16>'  : 'motor_position_control/PID Controller/N Gain'
 * '<S17>'  : 'motor_position_control/PID Controller/P Copy'
 * '<S18>'  : 'motor_position_control/PID Controller/Parallel P Gain'
 * '<S19>'  : 'motor_position_control/PID Controller/Reset Signal'
 * '<S20>'  : 'motor_position_control/PID Controller/Saturation'
 * '<S21>'  : 'motor_position_control/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'motor_position_control/PID Controller/Sum'
 * '<S23>'  : 'motor_position_control/PID Controller/Sum Fdbk'
 * '<S24>'  : 'motor_position_control/PID Controller/Tracking Mode'
 * '<S25>'  : 'motor_position_control/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'motor_position_control/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'motor_position_control/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'motor_position_control/PID Controller/postSat Signal'
 * '<S29>'  : 'motor_position_control/PID Controller/preSat Signal'
 * '<S30>'  : 'motor_position_control/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'motor_position_control/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'motor_position_control/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'motor_position_control/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'motor_position_control/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'motor_position_control/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'motor_position_control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'motor_position_control/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'motor_position_control/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'motor_position_control/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'motor_position_control/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'motor_position_control/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'motor_position_control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'motor_position_control/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'motor_position_control/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'motor_position_control/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'motor_position_control/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'motor_position_control/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'motor_position_control/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'motor_position_control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'motor_position_control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'motor_position_control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'motor_position_control/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'motor_position_control/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                /* RTW_HEADER_motor_position_control_h_ */
