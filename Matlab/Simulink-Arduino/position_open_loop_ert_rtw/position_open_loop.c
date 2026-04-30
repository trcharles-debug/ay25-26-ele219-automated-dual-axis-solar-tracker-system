/*
 * position_open_loop.c
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

#include "position_open_loop.h"
#include "rtwtypes.h"
#include <math.h>
#include "position_open_loop_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_position_open_loop_T position_open_loop_B;

/* Block states (default storage) */
DW_position_open_loop_T position_open_loop_DW;

/* Real-time model */
static RT_MODEL_position_open_loop_T position_open_loop_M_;
RT_MODEL_position_open_loop_T *const position_open_loop_M =
  &position_open_loop_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void position_open_loop_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(position_open_loop_M, 2));
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
  (position_open_loop_M->Timing.TaskCounters.TID[2])++;
  if ((position_open_loop_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.01s, 0.0s] */
    position_open_loop_M->Timing.TaskCounters.TID[2] = 0;
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
void position_open_loop_step0(void)    /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Sin: '<Root>/Azimut' */
  position_open_loop_B.Azimut = sin(position_open_loop_P.Azimut_Freq *
    position_open_loop_M->Timing.t[0] + position_open_loop_P.Azimut_Phase) *
    position_open_loop_P.Azimut_Amp + position_open_loop_P.Azimut_Bias;

  /* Sum: '<Root>/Sum' */
  position_open_loop_B.Sum = position_open_loop_B.Azimut;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++position_open_loop_M->Timing.clockTick0)) {
    ++position_open_loop_M->Timing.clockTickH0;
  }

  position_open_loop_M->Timing.t[0] = position_open_loop_M->Timing.clockTick0 *
    position_open_loop_M->Timing.stepSize0 +
    position_open_loop_M->Timing.clockTickH0 *
    position_open_loop_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  position_open_loop_M->Timing.clockTick1++;
  if (!position_open_loop_M->Timing.clockTick1) {
    position_open_loop_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void position_open_loop_step2(void)    /* Sample time: [0.01s, 0.0s] */
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
  rtb_FilterCoefficient = (position_open_loop_P.PIDController_D *
    position_open_loop_B.Sum - position_open_loop_DW.Filter_DSTATE) *
    position_open_loop_P.PIDController_N;

  /* Gain: '<Root>/Gain' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   *  Sum: '<S46>/Sum'
   */
  rtb_Gear_Ratio = ((position_open_loop_P.PIDController_P *
                     position_open_loop_B.Sum +
                     position_open_loop_DW.Integrator_DSTATE) +
                    rtb_FilterCoefficient) * position_open_loop_P.Gain_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Gear_Ratio > position_open_loop_P.Saturation_UpperSat) {
    rtb_Gear_Ratio = position_open_loop_P.Saturation_UpperSat;
  } else if (rtb_Gear_Ratio < position_open_loop_P.Saturation_LowerSat) {
    rtb_Gear_Ratio = position_open_loop_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant5'
   */
  if (rtb_Gear_Ratio > position_open_loop_P.Switch_Threshold) {
    rtb_Switch_idx_0 = position_open_loop_P.Constant2_Value;
    rtb_Switch_idx_1 = position_open_loop_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = position_open_loop_P.Constant5_Value;
    rtb_Switch_idx_1 = position_open_loop_P.Constant4_Value;
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
  position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Abs: '<S4>/Abs' */
  rtb_Gear_Ratio = fabs(rtb_Gear_Ratio);

  /* MATLABSystem: '<S4>/ENA1' */
  if (!(rtb_Gear_Ratio <= 255.0)) {
    rtb_Gear_Ratio = 255.0;
  }

  MW_PWM_SetDutyCycle(position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Gear_Ratio);

  /* MATLABSystem: '<S3>/Encoder' */
  if (position_open_loop_DW.obj.SampleTime !=
      position_open_loop_P.Encoder_SampleTime) {
    position_open_loop_DW.obj.SampleTime =
      position_open_loop_P.Encoder_SampleTime;
  }

  if (position_open_loop_DW.obj.TunablePropsChanged) {
    position_open_loop_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(position_open_loop_DW.obj.Index, &rtb_Encoder_0);

  /* Gain: '<S1>/rad//s To RPM1' incorporates:
   *  Gain: '<S3>/Gear_Ratio'
   *  MATLABSystem: '<S3>/Encoder'
   */
  position_open_loop_B.radsToRPM1 = (real_T)position_open_loop_P.Gear_Ratio_Gain
    * 4.5474735088646412E-13 * (real_T)rtb_Encoder_0 *
    position_open_loop_P.radsToRPM1_Gain;

  /* Gain: '<S34>/Integral Gain' */
  rtb_IntegralGain = position_open_loop_P.PIDController_I *
    position_open_loop_B.Sum;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  position_open_loop_DW.Integrator_DSTATE +=
    position_open_loop_P.Integrator_gainval * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  position_open_loop_DW.Filter_DSTATE += position_open_loop_P.Filter_gainval *
    rtb_FilterCoefficient;
}

/* Model initialize function */
void position_open_loop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)position_open_loop_M, 0,
                sizeof(RT_MODEL_position_open_loop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&position_open_loop_M->solverInfo,
                          &position_open_loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&position_open_loop_M->solverInfo, &rtmGetTPtr
                (position_open_loop_M));
    rtsiSetStepSizePtr(&position_open_loop_M->solverInfo,
                       &position_open_loop_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&position_open_loop_M->solverInfo, (&rtmGetErrorStatus
      (position_open_loop_M)));
    rtsiSetRTModelPtr(&position_open_loop_M->solverInfo, position_open_loop_M);
  }

  rtsiSetSimTimeStep(&position_open_loop_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&position_open_loop_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(position_open_loop_M, &position_open_loop_M->Timing.tArray[0]);
  position_open_loop_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &position_open_loop_B), 0,
                sizeof(B_position_open_loop_T));

  /* states (dwork) */
  (void) memset((void *)&position_open_loop_DW, 0,
                sizeof(DW_position_open_loop_T));

  /* Start for MATLABSystem: '<S4>/IN1' */
  position_open_loop_DW.obj_e.matlabCodegenIsDeleted = false;
  position_open_loop_DW.objisempty_j = true;
  position_open_loop_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(7, 1);
  position_open_loop_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/IN2' */
  position_open_loop_DW.obj_d.matlabCodegenIsDeleted = false;
  position_open_loop_DW.objisempty = true;
  position_open_loop_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(8, 1);
  position_open_loop_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/ENA1' */
  position_open_loop_DW.obj_g.matlabCodegenIsDeleted = false;
  position_open_loop_DW.objisempty_a = true;
  position_open_loop_DW.obj_g.isInitialized = 1L;
  position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0,
    0.0);
  position_open_loop_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Encoder' */
  position_open_loop_DW.obj.Index = 0U;
  position_open_loop_DW.obj.matlabCodegenIsDeleted = false;
  position_open_loop_DW.objisempty_i = true;
  position_open_loop_DW.obj.SampleTime = position_open_loop_P.Encoder_SampleTime;
  position_open_loop_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &position_open_loop_DW.obj.Index);
  position_open_loop_DW.obj.isSetupComplete = true;
  position_open_loop_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
  position_open_loop_DW.Integrator_DSTATE =
    position_open_loop_P.PIDController_InitialConditio_f;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Filter' */
  position_open_loop_DW.Filter_DSTATE =
    position_open_loop_P.PIDController_InitialConditionF;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(position_open_loop_DW.obj.Index);
}

/* Model terminate function */
void position_open_loop_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/IN1' */
  if (!position_open_loop_DW.obj_e.matlabCodegenIsDeleted) {
    position_open_loop_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/IN1' */

  /* Terminate for MATLABSystem: '<S4>/IN2' */
  if (!position_open_loop_DW.obj_d.matlabCodegenIsDeleted) {
    position_open_loop_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/IN2' */

  /* Terminate for MATLABSystem: '<S4>/ENA1' */
  if (!position_open_loop_DW.obj_g.matlabCodegenIsDeleted) {
    position_open_loop_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((position_open_loop_DW.obj_g.isInitialized == 1L) &&
        position_open_loop_DW.obj_g.isSetupComplete) {
      position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6UL);
      MW_PWM_SetDutyCycle(position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6UL);
      MW_PWM_Close(position_open_loop_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/ENA1' */

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!position_open_loop_DW.obj.matlabCodegenIsDeleted) {
    position_open_loop_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_open_loop_DW.obj.isInitialized == 1L) &&
        position_open_loop_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */
}
