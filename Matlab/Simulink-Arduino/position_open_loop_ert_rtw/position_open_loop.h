/*
 * position_open_loop.h
 *
 * Code generation for model "position_open_loop".
 *
 * Model version              : 1.113
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 22 10:45:04 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_open_loop_h_
#define RTW_HEADER_position_open_loop_h_
#ifndef position_open_loop_COMMON_INCLUDES_
#define position_open_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* position_open_loop_COMMON_INCLUDES_ */

#include "position_open_loop_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Azimut;                       /* '<Root>/Azimut' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T radsToRPM1;                   /* '<S1>/rad//s To RPM1' */
} B_position_open_loop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder' */
  codertarget_arduinobase_int_k_T obj_g;/* '<S4>/ENA1' */
  codertarget_arduinobase_block_T obj_d;/* '<S4>/IN2' */
  codertarget_arduinobase_block_T obj_e;/* '<S4>/IN1' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  boolean_T objisempty;                /* '<S4>/IN2' */
  boolean_T objisempty_j;              /* '<S4>/IN1' */
  boolean_T objisempty_a;              /* '<S4>/ENA1' */
  boolean_T objisempty_i;              /* '<S3>/Encoder' */
} DW_position_open_loop_T;

/* Parameters (default storage) */
struct P_position_open_loop_T_ {
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
  real_T radsToRPM1_Gain;              /* Expression: 180/pi
                                        * Referenced by: '<S1>/rad//s To RPM1'
                                        */
  int32_T Gear_Ratio_Gain;             /* Computed Parameter: Gear_Ratio_Gain
                                        * Referenced by: '<S3>/Gear_Ratio'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_position_open_loop_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

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
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_position_open_loop_T position_open_loop_P;

/* Block signals (default storage) */
extern B_position_open_loop_T position_open_loop_B;

/* Block states (default storage) */
extern DW_position_open_loop_T position_open_loop_DW;

/* External function called from main */
extern void position_open_loop_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void position_open_loop_initialize(void);
extern void position_open_loop_step0(void);
extern void position_open_loop_step2(void);
extern void position_open_loop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_position_open_loop_T *const position_open_loop_M;
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
 * '<Root>' : 'position_open_loop'
 * '<S1>'   : 'position_open_loop/Azimuth Motor'
 * '<S2>'   : 'position_open_loop/PID Controller'
 * '<S3>'   : 'position_open_loop/Azimuth Motor/Azimut Encoder'
 * '<S4>'   : 'position_open_loop/Azimuth Motor/Azimut Motor'
 * '<S5>'   : 'position_open_loop/Azimuth Motor/Azimut Encoder/Discrete Derivative'
 * '<S6>'   : 'position_open_loop/PID Controller/Anti-windup'
 * '<S7>'   : 'position_open_loop/PID Controller/D Gain'
 * '<S8>'   : 'position_open_loop/PID Controller/Filter'
 * '<S9>'   : 'position_open_loop/PID Controller/Filter ICs'
 * '<S10>'  : 'position_open_loop/PID Controller/I Gain'
 * '<S11>'  : 'position_open_loop/PID Controller/Ideal P Gain'
 * '<S12>'  : 'position_open_loop/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'position_open_loop/PID Controller/Integrator'
 * '<S14>'  : 'position_open_loop/PID Controller/Integrator ICs'
 * '<S15>'  : 'position_open_loop/PID Controller/N Copy'
 * '<S16>'  : 'position_open_loop/PID Controller/N Gain'
 * '<S17>'  : 'position_open_loop/PID Controller/P Copy'
 * '<S18>'  : 'position_open_loop/PID Controller/Parallel P Gain'
 * '<S19>'  : 'position_open_loop/PID Controller/Reset Signal'
 * '<S20>'  : 'position_open_loop/PID Controller/Saturation'
 * '<S21>'  : 'position_open_loop/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'position_open_loop/PID Controller/Sum'
 * '<S23>'  : 'position_open_loop/PID Controller/Sum Fdbk'
 * '<S24>'  : 'position_open_loop/PID Controller/Tracking Mode'
 * '<S25>'  : 'position_open_loop/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'position_open_loop/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'position_open_loop/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'position_open_loop/PID Controller/postSat Signal'
 * '<S29>'  : 'position_open_loop/PID Controller/preSat Signal'
 * '<S30>'  : 'position_open_loop/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'position_open_loop/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'position_open_loop/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'position_open_loop/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'position_open_loop/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'position_open_loop/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'position_open_loop/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'position_open_loop/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'position_open_loop/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'position_open_loop/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'position_open_loop/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'position_open_loop/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'position_open_loop/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'position_open_loop/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'position_open_loop/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'position_open_loop/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'position_open_loop/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'position_open_loop/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'position_open_loop/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'position_open_loop/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'position_open_loop/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'position_open_loop/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'position_open_loop/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'position_open_loop/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_position_open_loop_h_ */
