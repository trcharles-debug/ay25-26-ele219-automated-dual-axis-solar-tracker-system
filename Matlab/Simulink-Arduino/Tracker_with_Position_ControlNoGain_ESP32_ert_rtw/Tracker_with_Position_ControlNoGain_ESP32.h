/*
 * Tracker_with_Position_ControlNoGain_ESP32.h
 *
 * Code generation for model "Tracker_with_Position_ControlNoGain_ESP32".
 *
 * Model version              : 3.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed May  6 00:53:26 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Tracker_with_Position_ControlNoGain_ESP32_h_
#define Tracker_with_Position_ControlNoGain_ESP32_h_
#ifndef Tracker_with_Position_ControlNoGain_ESP32_COMMON_INCLUDES_
#define Tracker_with_Position_ControlNoGain_ESP32_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif          /* Tracker_with_Position_ControlNoGain_ESP32_COMMON_INCLUDES_ */

#include "Tracker_with_Position_ControlNoGain_ESP32_types.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define Tracker_with_Position_ControlNoGain_ESP32_M (Tracker_with_Position_Contro_M)

/* Block signals (default storage) */
typedef struct {
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T Gain_l;                       /* '<S11>/Gain' */
  real_T TmpSignalConversionAtTAQSigLo_e[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Sum1;                         /* '<Root>/Sum1' */
} B_Tracker_with_Position_Contr_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S10>/IN4' */
  codertarget_arduinobase_block_T obj_m;/* '<S10>/IN3' */
  codertarget_arduinobase_block_T obj_k;/* '<S6>/IN2' */
  codertarget_arduinobase_block_T obj_e;/* '<S6>/IN1' */
  codertarget_arduinobase_inter_T obj_o;/* '<S9>/Encoder' */
  codertarget_arduinobase_inter_T obj_os;/* '<S5>/Encoder' */
  codertarget_arduinobase_int_i_T obj_b;/* '<S10>/ENB' */
  codertarget_arduinobase_int_i_T obj_ki;/* '<S6>/ENA1' */
  real_T Integrator_DSTATE;            /* '<S47>/Integrator' */
  real_T Filter_DSTATE;                /* '<S42>/Filter' */
  real_T Integrator_DSTATE_j;          /* '<S99>/Integrator' */
  real_T Filter_DSTATE_b;              /* '<S94>/Filter' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_Tracker_with_Position_Cont_T;

/* Parameters (default storage) */
struct P_Tracker_with_Position_Contr_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S40>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S92>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S44>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S96>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S42>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S94>/Filter'
                               */
  real_T PIDController_InitialConditio_f;
                              /* Mask Parameter: PIDController_InitialConditio_f
                               * Referenced by: '<S47>/Integrator'
                               */
  real_T PIDController1_InitialConditi_j;
                              /* Mask Parameter: PIDController1_InitialConditi_j
                               * Referenced by: '<S99>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S50>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S102>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S52>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S104>/Proportional Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant5_Value_k;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant4_Value_e;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 90
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gear_Ratio_Gain;              /* Expression: 2*pi/(170*64)
                                        * Referenced by: '<S5>/Gear_Ratio'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S47>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S42>/Filter'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gear_Ratio_Gain_b;            /* Expression: 2*pi/(169*64)
                                        * Referenced by: '<S9>/Gear_Ratio'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 180/pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S99>/Integrator'
                                      */
  real_T Filter_gainval_n;             /* Computed Parameter: Filter_gainval_n
                                        * Referenced by: '<S94>/Filter'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -255
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Tracker_with_Position_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Tracker_with_Position_Contr_T Tracker_with_Position_Control_P;

/* Block signals (default storage) */
extern B_Tracker_with_Position_Contr_T Tracker_with_Position_Control_B;

/* Block states (default storage) */
extern DW_Tracker_with_Position_Cont_T Tracker_with_Position_Contro_DW;

/* External function called from main */
extern void Tracker_with_Position_ControlNoGain_ESP32_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void Tracker_with_Position_ControlNoGain_ESP32_initialize(void);
extern void Tracker_with_Position_ControlNoGain_ESP32_step0(void);/* Sample time: [0.005s, 0.0s] */
extern void Tracker_with_Position_ControlNoGain_ESP32_step1(void);/* Sample time: [0.01s, 0.0s] */
extern void Tracker_with_Position_ControlNoGain_ESP32_step(int_T tid);
extern void Tracker_with_Position_ControlNoGain_ESP32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Tracker_with_Positio_T *const Tracker_with_Position_Contro_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Diff' : Unused code path elimination
 * Block '<S8>/TSamp' : Unused code path elimination
 * Block '<S8>/UD' : Unused code path elimination
 * Block '<S1>/rad//s To RPM' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Diff' : Unused code path elimination
 * Block '<S12>/TSamp' : Unused code path elimination
 * Block '<S12>/UD' : Unused code path elimination
 * Block '<S2>/rad//s To RPM' : Unused code path elimination
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
 * '<Root>' : 'Tracker_with_Position_ControlNoGain_ESP32'
 * '<S1>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Azimuth Motor'
 * '<S2>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Elevator Motor1'
 * '<S3>'   : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller'
 * '<S4>'   : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1'
 * '<S5>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Azimuth Motor/Azimuth Encoder'
 * '<S6>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Azimuth Motor/Azimuth Motor'
 * '<S7>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Azimuth Motor/Radians to Degrees'
 * '<S8>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Azimuth Motor/Azimuth Encoder/Discrete Derivative'
 * '<S9>'   : 'Tracker_with_Position_ControlNoGain_ESP32/Elevator Motor1/Elevator Encoder'
 * '<S10>'  : 'Tracker_with_Position_ControlNoGain_ESP32/Elevator Motor1/Elevator Motor'
 * '<S11>'  : 'Tracker_with_Position_ControlNoGain_ESP32/Elevator Motor1/Radians to Degrees'
 * '<S12>'  : 'Tracker_with_Position_ControlNoGain_ESP32/Elevator Motor1/Elevator Encoder/Discrete Derivative'
 * '<S13>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Anti-windup'
 * '<S14>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/D Gain'
 * '<S15>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/External Derivative'
 * '<S16>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Filter'
 * '<S17>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Filter ICs'
 * '<S18>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/I Gain'
 * '<S19>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Ideal P Gain'
 * '<S20>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Ideal P Gain Fdbk'
 * '<S21>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Integrator'
 * '<S22>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Integrator ICs'
 * '<S23>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/N Copy'
 * '<S24>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/N Gain'
 * '<S25>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/P Copy'
 * '<S26>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Parallel P Gain'
 * '<S27>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Reset Signal'
 * '<S28>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Saturation'
 * '<S29>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Saturation Fdbk'
 * '<S30>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Sum'
 * '<S31>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Sum Fdbk'
 * '<S32>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tracking Mode'
 * '<S33>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tracking Mode Sum'
 * '<S34>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tsamp - Integral'
 * '<S35>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tsamp - Ngain'
 * '<S36>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/postSat Signal'
 * '<S37>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/preInt Signal'
 * '<S38>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/preSat Signal'
 * '<S39>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Anti-windup/Passthrough'
 * '<S40>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/D Gain/Internal Parameters'
 * '<S41>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/External Derivative/Error'
 * '<S42>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S43>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S44>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/I Gain/Internal Parameters'
 * '<S45>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Ideal P Gain/Passthrough'
 * '<S46>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Integrator/Discrete'
 * '<S48>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Integrator ICs/Internal IC'
 * '<S49>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/N Copy/Disabled'
 * '<S50>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/N Gain/Internal Parameters'
 * '<S51>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/P Copy/Disabled'
 * '<S52>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Reset Signal/Disabled'
 * '<S54>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Saturation/Passthrough'
 * '<S55>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Saturation Fdbk/Disabled'
 * '<S56>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Sum/Sum_PID'
 * '<S57>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Sum Fdbk/Disabled'
 * '<S58>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tracking Mode/Disabled'
 * '<S59>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S61>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/postSat Signal/Forward_Path'
 * '<S63>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/preInt Signal/Internal PreInt'
 * '<S64>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller/preSat Signal/Forward_Path'
 * '<S65>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Anti-windup'
 * '<S66>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/D Gain'
 * '<S67>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/External Derivative'
 * '<S68>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Filter'
 * '<S69>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Filter ICs'
 * '<S70>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/I Gain'
 * '<S71>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Ideal P Gain'
 * '<S72>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Ideal P Gain Fdbk'
 * '<S73>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Integrator'
 * '<S74>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Integrator ICs'
 * '<S75>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/N Copy'
 * '<S76>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/N Gain'
 * '<S77>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/P Copy'
 * '<S78>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Parallel P Gain'
 * '<S79>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Reset Signal'
 * '<S80>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Saturation'
 * '<S81>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Saturation Fdbk'
 * '<S82>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Sum'
 * '<S83>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Sum Fdbk'
 * '<S84>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tracking Mode'
 * '<S85>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tracking Mode Sum'
 * '<S86>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tsamp - Integral'
 * '<S87>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tsamp - Ngain'
 * '<S88>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/postSat Signal'
 * '<S89>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/preInt Signal'
 * '<S90>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/preSat Signal'
 * '<S91>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Anti-windup/Passthrough'
 * '<S92>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/D Gain/Internal Parameters'
 * '<S93>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/External Derivative/Error'
 * '<S94>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S95>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S96>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/I Gain/Internal Parameters'
 * '<S97>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Ideal P Gain/Passthrough'
 * '<S98>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Integrator/Discrete'
 * '<S100>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Integrator ICs/Internal IC'
 * '<S101>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/N Copy/Disabled'
 * '<S102>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/N Gain/Internal Parameters'
 * '<S103>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/P Copy/Disabled'
 * '<S104>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S105>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Reset Signal/Disabled'
 * '<S106>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Saturation/Passthrough'
 * '<S107>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Saturation Fdbk/Disabled'
 * '<S108>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Sum/Sum_PID'
 * '<S109>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Sum Fdbk/Disabled'
 * '<S110>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tracking Mode/Disabled'
 * '<S111>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S113>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/postSat Signal/Forward_Path'
 * '<S115>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/preInt Signal/Internal PreInt'
 * '<S116>' : 'Tracker_with_Position_ControlNoGain_ESP32/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                        /* Tracker_with_Position_ControlNoGain_ESP32_h_ */
