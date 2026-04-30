/*
 * motor_position_control.c
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

#include "motor_position_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "motor_position_control_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_motor_position_control_T motor_position_control_B;

/* Block states (default storage) */
DW_motor_position_control_T motor_position_control_DW;

/* Real-time model */
static RT_MODEL_motor_position_contr_T motor_position_control_M_;
RT_MODEL_motor_position_contr_T *const motor_position_control_M =
  &motor_position_control_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void motor_position_control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(motor_position_control_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (motor_position_control_M->Timing.TaskCounters.TID[2])++;
  if ((motor_position_control_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.01s, 0.0s] */
    motor_position_control_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void motor_position_control_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<Root>/Sum' */
  motor_position_control_B.TmpRTBAtSumInport2 =
    motor_position_control_B.radsToRPM1;

  /* Sum: '<Root>/Sum' incorporates:
   *  Sin: '<Root>/Azimut'
   */
  motor_position_control_B.Sum = (sin(motor_position_control_P.Azimut_Freq *
    motor_position_control_M->Timing.t[0] +
    motor_position_control_P.Azimut_Phase) * motor_position_control_P.Azimut_Amp
    + motor_position_control_P.Azimut_Bias) -
    motor_position_control_B.TmpRTBAtSumInport2;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++motor_position_control_M->Timing.clockTick0)) {
    ++motor_position_control_M->Timing.clockTickH0;
  }

  motor_position_control_M->Timing.t[0] =
    motor_position_control_M->Timing.clockTick0 *
    motor_position_control_M->Timing.stepSize0 +
    motor_position_control_M->Timing.clockTickH0 *
    motor_position_control_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  motor_position_control_M->Timing.clockTick1++;
  if (!motor_position_control_M->Timing.clockTick1) {
    motor_position_control_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void motor_position_control_step2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  real_T rtb_Gear_Ratio;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  int32_T rtb_Encoder_0;
  uint8_T tmp;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Gain: '<S31>/Derivative Gain'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (motor_position_control_P.PIDController_D *
    motor_position_control_B.Sum - motor_position_control_DW.Filter_DSTATE) *
    motor_position_control_P.PIDController_N;

  /* Gain: '<Root>/Gain' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   *  Sum: '<S46>/Sum'
   */
  rtb_Gear_Ratio = ((motor_position_control_P.PIDController_P *
                     motor_position_control_B.Sum +
                     motor_position_control_DW.Integrator_DSTATE) +
                    rtb_FilterCoefficient) * motor_position_control_P.Gain_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Gear_Ratio > motor_position_control_P.Saturation_UpperSat) {
    rtb_Gear_Ratio = motor_position_control_P.Saturation_UpperSat;
  } else if (rtb_Gear_Ratio < motor_position_control_P.Saturation_LowerSat) {
    rtb_Gear_Ratio = motor_position_control_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant5'
   */
  if (rtb_Gear_Ratio > motor_position_control_P.Switch_Threshold) {
    rtb_Switch_idx_0 = motor_position_control_P.Constant2_Value;
    rtb_Switch_idx_1 = motor_position_control_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = motor_position_control_P.Constant5_Value;
    rtb_Switch_idx_1 = motor_position_control_P.Constant4_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* MATLABSystem: '<S4>/IN1' */
  rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_0);
  if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
      tmp = (uint8_T)rtb_Switch_idx_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<S4>/IN1' */

  /* MATLABSystem: '<S4>/IN2' */
  rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_1);
  if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
      tmp = (uint8_T)rtb_Switch_idx_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp);

  /* End of MATLABSystem: '<S4>/IN2' */

  /* MATLABSystem: '<S4>/ENA1' */
  motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (6UL);

  /* Abs: '<S4>/Abs' */
  rtb_Gear_Ratio = fabs(rtb_Gear_Ratio);

  /* MATLABSystem: '<S4>/ENA1' */
  if (!(rtb_Gear_Ratio <= 255.0)) {
    rtb_Gear_Ratio = 255.0;
  }

  MW_PWM_SetDutyCycle(motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Gear_Ratio);

  /* MATLABSystem: '<S3>/Encoder' */
  if (motor_position_control_DW.obj.SampleTime !=
      motor_position_control_P.Encoder_SampleTime) {
    motor_position_control_DW.obj.SampleTime =
      motor_position_control_P.Encoder_SampleTime;
  }

  if (motor_position_control_DW.obj.TunablePropsChanged) {
    motor_position_control_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(motor_position_control_DW.obj.Index, &rtb_Encoder_0);

  /* Gain: '<S1>/rad//s To RPM1' incorporates:
   *  Gain: '<S3>/Gear_Ratio'
   *  MATLABSystem: '<S3>/Encoder'
   */
  motor_position_control_B.radsToRPM1 = motor_position_control_P.Gear_Ratio_Gain
    * (real_T)rtb_Encoder_0 * motor_position_control_P.radsToRPM1_Gain;

  /* Gain: '<S34>/Integral Gain' */
  rtb_IntegralGain = motor_position_control_P.PIDController_I *
    motor_position_control_B.Sum;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  motor_position_control_DW.Integrator_DSTATE +=
    motor_position_control_P.Integrator_gainval * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  motor_position_control_DW.Filter_DSTATE +=
    motor_position_control_P.Filter_gainval * rtb_FilterCoefficient;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  motor_position_control_M->Timing.clockTick2++;
  if (!motor_position_control_M->Timing.clockTick2) {
    motor_position_control_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void motor_position_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motor_position_control_M, 0,
                sizeof(RT_MODEL_motor_position_contr_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motor_position_control_M->solverInfo,
                          &motor_position_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&motor_position_control_M->solverInfo, &rtmGetTPtr
                (motor_position_control_M));
    rtsiSetStepSizePtr(&motor_position_control_M->solverInfo,
                       &motor_position_control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&motor_position_control_M->solverInfo,
                          (&rtmGetErrorStatus(motor_position_control_M)));
    rtsiSetRTModelPtr(&motor_position_control_M->solverInfo,
                      motor_position_control_M);
  }

  rtsiSetSimTimeStep(&motor_position_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&motor_position_control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(motor_position_control_M, &motor_position_control_M->Timing.tArray
             [0]);
  rtmSetTFinal(motor_position_control_M, -1);
  motor_position_control_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  motor_position_control_M->Sizes.checksums[0] = (3499009820U);
  motor_position_control_M->Sizes.checksums[1] = (4170882430U);
  motor_position_control_M->Sizes.checksums[2] = (1752202304U);
  motor_position_control_M->Sizes.checksums[3] = (600087900U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    motor_position_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_position_control_M->extModeInfo,
      &motor_position_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_position_control_M->extModeInfo,
                        motor_position_control_M->Sizes.checksums);
    rteiSetTPtr(motor_position_control_M->extModeInfo, rtmGetTPtr
                (motor_position_control_M));
  }

  /* block I/O */
  (void) memset(((void *) &motor_position_control_B), 0,
                sizeof(B_motor_position_control_T));

  /* states (dwork) */
  (void) memset((void *)&motor_position_control_DW, 0,
                sizeof(DW_motor_position_control_T));

  /* Start for MATLABSystem: '<S4>/IN1' */
  motor_position_control_DW.obj_e.matlabCodegenIsDeleted = false;
  motor_position_control_DW.objisempty_j = true;
  motor_position_control_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(7, 1);
  motor_position_control_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/IN2' */
  motor_position_control_DW.obj_d.matlabCodegenIsDeleted = false;
  motor_position_control_DW.objisempty = true;
  motor_position_control_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(8, 1);
  motor_position_control_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/ENA1' */
  motor_position_control_DW.obj_g.matlabCodegenIsDeleted = false;
  motor_position_control_DW.objisempty_a = true;
  motor_position_control_DW.obj_g.isInitialized = 1L;
  motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL,
    0.0, 0.0);
  motor_position_control_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Encoder' */
  motor_position_control_DW.obj.Index = 0U;
  motor_position_control_DW.obj.matlabCodegenIsDeleted = false;
  motor_position_control_DW.objisempty_i = true;
  motor_position_control_DW.obj.SampleTime =
    motor_position_control_P.Encoder_SampleTime;
  motor_position_control_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &motor_position_control_DW.obj.Index);
  motor_position_control_DW.obj.isSetupComplete = true;
  motor_position_control_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
  motor_position_control_DW.Integrator_DSTATE =
    motor_position_control_P.PIDController_InitialConditio_f;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Filter' */
  motor_position_control_DW.Filter_DSTATE =
    motor_position_control_P.PIDController_InitialConditionF;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(motor_position_control_DW.obj.Index);
}

/* Model terminate function */
void motor_position_control_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/IN1' */
  if (!motor_position_control_DW.obj_e.matlabCodegenIsDeleted) {
    motor_position_control_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/IN1' */

  /* Terminate for MATLABSystem: '<S4>/IN2' */
  if (!motor_position_control_DW.obj_d.matlabCodegenIsDeleted) {
    motor_position_control_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/IN2' */

  /* Terminate for MATLABSystem: '<S4>/ENA1' */
  if (!motor_position_control_DW.obj_g.matlabCodegenIsDeleted) {
    motor_position_control_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((motor_position_control_DW.obj_g.isInitialized == 1L) &&
        motor_position_control_DW.obj_g.isSetupComplete) {
      motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close(motor_position_control_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/ENA1' */

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!motor_position_control_DW.obj.matlabCodegenIsDeleted) {
    motor_position_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((motor_position_control_DW.obj.isInitialized == 1L) &&
        motor_position_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */
}
