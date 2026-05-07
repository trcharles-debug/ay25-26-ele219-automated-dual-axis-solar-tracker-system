/*
 * Tracker_with_Position_ControlNoGain_ESP32.c
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

#include "Tracker_with_Position_ControlNoGain_ESP32.h"
#include "Tracker_with_Position_ControlNoGain_ESP32_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Tracker_with_Position_Contr_T Tracker_with_Position_Control_B;

/* Block states (default storage) */
DW_Tracker_with_Position_Cont_T Tracker_with_Position_Contro_DW;

/* Real-time model */
static RT_MODEL_Tracker_with_Positio_T Tracker_with_Position_Contro_M_;
RT_MODEL_Tracker_with_Positio_T *const Tracker_with_Position_Contro_M =
  &Tracker_with_Position_Contro_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Tracker_with_Position_ControlNoGain_ESP32_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Tracker_with_Position_Contro_M, 1));
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
  (Tracker_with_Position_Contro_M->Timing.TaskCounters.TID[1])++;
  if ((Tracker_with_Position_Contro_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.01s, 0.0s] */
    Tracker_with_Position_Contro_M->Timing.TaskCounters.TID[1] = 0;
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
void Tracker_with_Position_ControlNoGain_ESP32_step0(void) /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Tracker_with_Position_Contro_M->Timing.taskTime0 =
    ((time_T)(++Tracker_with_Position_Contro_M->Timing.clockTick0)) *
    Tracker_with_Position_Contro_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Tracker_with_Position_ControlNoGain_ESP32_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_FilterCoefficient;
  real_T rtb_Integrator_l;
  real_T rtb_Saturation1;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  int32_T rtb_Encoder_b_0;
  uint8_T tmp;

  /* Constant: '<Root>/Constant' */
  Tracker_with_Position_Control_B.Constant =
    Tracker_with_Position_Control_P.Constant_Value;

  /* MATLABSystem: '<S5>/Encoder' */
  if (Tracker_with_Position_Contro_DW.obj_os.TunablePropsChanged) {
    Tracker_with_Position_Contro_DW.obj_os.TunablePropsChanged = false;
  }

  MW_EncoderRead(Tracker_with_Position_Contro_DW.obj_os.Index, &rtb_Encoder_b_0);

  /* Gain: '<S7>/Gain' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S5>/Gear_Ratio'
   *  MATLABSystem: '<S5>/Encoder'
   */
  Tracker_with_Position_Control_B.Gain =
    Tracker_with_Position_Control_P.Gear_Ratio_Gain * (real_T)rtb_Encoder_b_0 *
    Tracker_with_Position_Control_P.Gain_Gain;

  /* SignalConversion generated from: '<Root>/Mux' */
  Tracker_with_Position_Control_B.TmpSignalConversionAtTAQSigLogg[0] =
    Tracker_with_Position_Control_B.Constant;
  Tracker_with_Position_Control_B.TmpSignalConversionAtTAQSigLogg[1] =
    Tracker_with_Position_Control_B.Gain;

  /* Sum: '<Root>/Sum' */
  Tracker_with_Position_Control_B.Sum = Tracker_with_Position_Control_B.Constant
    - Tracker_with_Position_Control_B.Gain;

  /* Gain: '<S50>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S42>/Filter'
   *  Gain: '<S40>/Derivative Gain'
   *  Sum: '<S42>/SumD'
   */
  rtb_FilterCoefficient = (Tracker_with_Position_Control_P.PIDController_D *
    Tracker_with_Position_Control_B.Sum -
    Tracker_with_Position_Contro_DW.Filter_DSTATE) *
    Tracker_with_Position_Control_P.PIDController_N;

  /* Sum: '<S56>/Sum' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Gain: '<S52>/Proportional Gain'
   */
  rtb_Integrator_l = (Tracker_with_Position_Control_P.PIDController_P *
                      Tracker_with_Position_Control_B.Sum +
                      Tracker_with_Position_Contro_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Integrator_l > Tracker_with_Position_Control_P.Saturation_UpperSat) {
    rtb_Integrator_l = Tracker_with_Position_Control_P.Saturation_UpperSat;
  } else if (rtb_Integrator_l <
             Tracker_with_Position_Control_P.Saturation_LowerSat) {
    rtb_Integrator_l = Tracker_with_Position_Control_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   */
  if (rtb_Integrator_l > Tracker_with_Position_Control_P.Switch_Threshold) {
    rtb_Switch_idx_0 = Tracker_with_Position_Control_P.Constant2_Value;
    rtb_Switch_idx_1 = Tracker_with_Position_Control_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = Tracker_with_Position_Control_P.Constant5_Value;
    rtb_Switch_idx_1 = Tracker_with_Position_Control_P.Constant4_Value;
  }

  /* End of Switch: '<S6>/Switch' */

  /* MATLABSystem: '<S6>/IN1' */
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

  writeDigitalPin(32, tmp);

  /* End of MATLABSystem: '<S6>/IN1' */

  /* MATLABSystem: '<S6>/IN2' */
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

  writeDigitalPin(33, tmp);

  /* End of MATLABSystem: '<S6>/IN2' */

  /* MATLABSystem: '<S6>/ENA1' */
  Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(18U);

  /* Abs: '<S6>/Abs' */
  rtb_Switch_idx_1 = fabs(rtb_Integrator_l);

  /* Start for MATLABSystem: '<S6>/ENA1' */
  if (!(rtb_Switch_idx_1 <= 255.0)) {
    rtb_Switch_idx_1 = 255.0;
  }

  /* MATLABSystem: '<S6>/ENA1' */
  MW_PWM_SetDutyCycle
    (Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Switch_idx_1);

  /* Constant: '<Root>/Constant1' */
  Tracker_with_Position_Control_B.Constant1 =
    Tracker_with_Position_Control_P.Constant1_Value_n;

  /* MATLABSystem: '<S9>/Encoder' */
  if (Tracker_with_Position_Contro_DW.obj_o.TunablePropsChanged) {
    Tracker_with_Position_Contro_DW.obj_o.TunablePropsChanged = false;
  }

  MW_EncoderRead(Tracker_with_Position_Contro_DW.obj_o.Index, &rtb_Encoder_b_0);
  MW_EncoderReset(Tracker_with_Position_Contro_DW.obj_o.Index);

  /* Gain: '<S11>/Gain' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Gain: '<S9>/Gear_Ratio'
   *  MATLABSystem: '<S9>/Encoder'
   */
  Tracker_with_Position_Control_B.Gain_l =
    Tracker_with_Position_Control_P.Gear_Ratio_Gain_b * (real_T)rtb_Encoder_b_0 *
    Tracker_with_Position_Control_P.Gain_Gain_h;

  /* SignalConversion generated from: '<Root>/Mux1' */
  Tracker_with_Position_Control_B.TmpSignalConversionAtTAQSigLo_e[0] =
    Tracker_with_Position_Control_B.Constant1;
  Tracker_with_Position_Control_B.TmpSignalConversionAtTAQSigLo_e[1] =
    Tracker_with_Position_Control_B.Gain_l;

  /* Sum: '<Root>/Sum1' */
  Tracker_with_Position_Control_B.Sum1 =
    Tracker_with_Position_Control_B.Constant1 -
    Tracker_with_Position_Control_B.Gain_l;

  /* Gain: '<S102>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S94>/Filter'
   *  Gain: '<S92>/Derivative Gain'
   *  Sum: '<S94>/SumD'
   */
  rtb_Integrator_l = (Tracker_with_Position_Control_P.PIDController1_D *
                      Tracker_with_Position_Control_B.Sum1 -
                      Tracker_with_Position_Contro_DW.Filter_DSTATE_b) *
    Tracker_with_Position_Control_P.PIDController1_N;

  /* Sum: '<S108>/Sum' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator'
   *  Gain: '<S104>/Proportional Gain'
   */
  rtb_Saturation1 = (Tracker_with_Position_Control_P.PIDController1_P *
                     Tracker_with_Position_Control_B.Sum1 +
                     Tracker_with_Position_Contro_DW.Integrator_DSTATE_j) +
    rtb_Integrator_l;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Saturation1 > Tracker_with_Position_Control_P.Saturation1_UpperSat) {
    rtb_Saturation1 = Tracker_with_Position_Control_P.Saturation1_UpperSat;
  } else if (rtb_Saturation1 <
             Tracker_with_Position_Control_P.Saturation1_LowerSat) {
    rtb_Saturation1 = Tracker_with_Position_Control_P.Saturation1_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant4'
   *  Constant: '<S10>/Constant5'
   */
  if (rtb_Saturation1 > Tracker_with_Position_Control_P.Switch_Threshold_j) {
    rtb_Switch_idx_0 = Tracker_with_Position_Control_P.Constant2_Value_e;
    rtb_Switch_idx_1 = Tracker_with_Position_Control_P.Constant1_Value_d;
  } else {
    rtb_Switch_idx_0 = Tracker_with_Position_Control_P.Constant5_Value_k;
    rtb_Switch_idx_1 = Tracker_with_Position_Control_P.Constant4_Value_e;
  }

  /* End of Switch: '<S10>/Switch' */

  /* MATLABSystem: '<S10>/IN3' */
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

  writeDigitalPin(19, tmp);

  /* End of MATLABSystem: '<S10>/IN3' */

  /* MATLABSystem: '<S10>/IN4' */
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

  writeDigitalPin(25, tmp);

  /* End of MATLABSystem: '<S10>/IN4' */

  /* MATLABSystem: '<S10>/ENB' */
  Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(26U);

  /* Abs: '<S10>/Abs' */
  rtb_Switch_idx_1 = fabs(rtb_Saturation1);

  /* Start for MATLABSystem: '<S10>/ENB' */
  if (!(rtb_Switch_idx_1 <= 255.0)) {
    rtb_Switch_idx_1 = 255.0;
  }

  /* MATLABSystem: '<S10>/ENB' */
  MW_PWM_SetDutyCycle
    (Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Switch_idx_1);

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Gain: '<S44>/Integral Gain'
   */
  Tracker_with_Position_Contro_DW.Integrator_DSTATE +=
    Tracker_with_Position_Control_P.PIDController_I *
    Tracker_with_Position_Control_B.Sum *
    Tracker_with_Position_Control_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S42>/Filter' */
  Tracker_with_Position_Contro_DW.Filter_DSTATE +=
    Tracker_with_Position_Control_P.Filter_gainval * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S99>/Integrator' incorporates:
   *  Gain: '<S96>/Integral Gain'
   */
  Tracker_with_Position_Contro_DW.Integrator_DSTATE_j +=
    Tracker_with_Position_Control_P.PIDController1_I *
    Tracker_with_Position_Control_B.Sum1 *
    Tracker_with_Position_Control_P.Integrator_gainval_p;

  /* Update for DiscreteIntegrator: '<S94>/Filter' */
  Tracker_with_Position_Contro_DW.Filter_DSTATE_b +=
    Tracker_with_Position_Control_P.Filter_gainval_n * rtb_Integrator_l;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Tracker_with_Position_Contro_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Tracker_with_Position_ControlNoGain_ESP32_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Tracker_with_Position_ControlNoGain_ESP32_step0();
    break;

   case 1 :
    Tracker_with_Position_ControlNoGain_ESP32_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Tracker_with_Position_ControlNoGain_ESP32_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Tracker_with_Position_Contro_M, 0,
                sizeof(RT_MODEL_Tracker_with_Positio_T));
  rtmSetTFinal(Tracker_with_Position_Contro_M, -1);
  Tracker_with_Position_Contro_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  Tracker_with_Position_Contro_M->Sizes.checksums[0] = (2559922148U);
  Tracker_with_Position_Contro_M->Sizes.checksums[1] = (3501227630U);
  Tracker_with_Position_Contro_M->Sizes.checksums[2] = (2792399865U);
  Tracker_with_Position_Contro_M->Sizes.checksums[3] = (1432446478U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Tracker_with_Position_Contro_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Tracker_with_Position_Contro_M->extModeInfo,
      &Tracker_with_Position_Contro_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Tracker_with_Position_Contro_M->extModeInfo,
                        Tracker_with_Position_Contro_M->Sizes.checksums);
    rteiSetTPtr(Tracker_with_Position_Contro_M->extModeInfo, rtmGetTPtr
                (Tracker_with_Position_Contro_M));
  }

  /* block I/O */
  (void) memset(((void *) &Tracker_with_Position_Control_B), 0,
                sizeof(B_Tracker_with_Position_Contr_T));

  /* states (dwork) */
  (void) memset((void *)&Tracker_with_Position_Contro_DW, 0,
                sizeof(DW_Tracker_with_Position_Cont_T));

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Integrator' */
  Tracker_with_Position_Contro_DW.Integrator_DSTATE =
    Tracker_with_Position_Control_P.PIDController_InitialConditio_f;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Filter' */
  Tracker_with_Position_Contro_DW.Filter_DSTATE =
    Tracker_with_Position_Control_P.PIDController_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Integrator' */
  Tracker_with_Position_Contro_DW.Integrator_DSTATE_j =
    Tracker_with_Position_Control_P.PIDController1_InitialConditi_j;

  /* InitializeConditions for DiscreteIntegrator: '<S94>/Filter' */
  Tracker_with_Position_Contro_DW.Filter_DSTATE_b =
    Tracker_with_Position_Control_P.PIDController1_InitialCondition;

  /* Start for MATLABSystem: '<S5>/Encoder' */
  Tracker_with_Position_Contro_DW.obj_os.Index = 0U;
  Tracker_with_Position_Contro_DW.obj_os.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_os.isInitialized = 1;
  MW_EncoderSetup(15U, 16U, &Tracker_with_Position_Contro_DW.obj_os.Index);
  Tracker_with_Position_Contro_DW.obj_os.isSetupComplete = true;
  Tracker_with_Position_Contro_DW.obj_os.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S5>/Encoder' */
  MW_EncoderReset(Tracker_with_Position_Contro_DW.obj_os.Index);

  /* Start for MATLABSystem: '<S6>/IN1' */
  Tracker_with_Position_Contro_DW.obj_e.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_e.isInitialized = 1;
  digitalIOSetup(32, 1);
  Tracker_with_Position_Contro_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/IN2' */
  Tracker_with_Position_Contro_DW.obj_k.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_k.isInitialized = 1;
  digitalIOSetup(33, 1);
  Tracker_with_Position_Contro_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/ENA1' */
  Tracker_with_Position_Contro_DW.obj_ki.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_ki.isInitialized = 1;
  Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_Open(18U, 0.0, 0.0);
  Tracker_with_Position_Contro_DW.obj_ki.isSetupComplete = true;

  /* Start for MATLABSystem: '<S9>/Encoder' */
  Tracker_with_Position_Contro_DW.obj_o.Index = 0U;
  Tracker_with_Position_Contro_DW.obj_o.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_o.isInitialized = 1;
  MW_EncoderSetup(5U, 4U, &Tracker_with_Position_Contro_DW.obj_o.Index);
  Tracker_with_Position_Contro_DW.obj_o.isSetupComplete = true;
  Tracker_with_Position_Contro_DW.obj_o.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S9>/Encoder' */
  MW_EncoderReset(Tracker_with_Position_Contro_DW.obj_o.Index);

  /* Start for MATLABSystem: '<S10>/IN3' */
  Tracker_with_Position_Contro_DW.obj_m.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_m.isInitialized = 1;
  digitalIOSetup(19, 1);
  Tracker_with_Position_Contro_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/IN4' */
  Tracker_with_Position_Contro_DW.obj.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj.isInitialized = 1;
  digitalIOSetup(25, 1);
  Tracker_with_Position_Contro_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/ENB' */
  Tracker_with_Position_Contro_DW.obj_b.matlabCodegenIsDeleted = false;
  Tracker_with_Position_Contro_DW.obj_b.isInitialized = 1;
  Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (26U, 0.0, 0.0);
  Tracker_with_Position_Contro_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void Tracker_with_Position_ControlNoGain_ESP32_terminate(void)
{
  /* Terminate for MATLABSystem: '<S5>/Encoder' */
  if (!Tracker_with_Position_Contro_DW.obj_os.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_os.matlabCodegenIsDeleted = true;
    if ((Tracker_with_Position_Contro_DW.obj_os.isInitialized == 1) &&
        Tracker_with_Position_Contro_DW.obj_os.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Encoder' */
  /* Terminate for MATLABSystem: '<S6>/IN1' */
  if (!Tracker_with_Position_Contro_DW.obj_e.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/IN1' */

  /* Terminate for MATLABSystem: '<S6>/IN2' */
  if (!Tracker_with_Position_Contro_DW.obj_k.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/IN2' */

  /* Terminate for MATLABSystem: '<S6>/ENA1' */
  if (!Tracker_with_Position_Contro_DW.obj_ki.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_ki.matlabCodegenIsDeleted = true;
    if ((Tracker_with_Position_Contro_DW.obj_ki.isInitialized == 1) &&
        Tracker_with_Position_Contro_DW.obj_ki.isSetupComplete) {
      Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(18U);
      MW_PWM_SetDutyCycle
        (Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(18U);
      MW_PWM_Close
        (Tracker_with_Position_Contro_DW.obj_ki.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/ENA1' */
  /* Terminate for MATLABSystem: '<S9>/Encoder' */
  if (!Tracker_with_Position_Contro_DW.obj_o.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Tracker_with_Position_Contro_DW.obj_o.isInitialized == 1) &&
        Tracker_with_Position_Contro_DW.obj_o.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Encoder' */
  /* Terminate for MATLABSystem: '<S10>/IN3' */
  if (!Tracker_with_Position_Contro_DW.obj_m.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/IN3' */

  /* Terminate for MATLABSystem: '<S10>/IN4' */
  if (!Tracker_with_Position_Contro_DW.obj.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/IN4' */

  /* Terminate for MATLABSystem: '<S10>/ENB' */
  if (!Tracker_with_Position_Contro_DW.obj_b.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Tracker_with_Position_Contro_DW.obj_b.isInitialized == 1) &&
        Tracker_with_Position_Contro_DW.obj_b.isSetupComplete) {
      Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(26U);
      MW_PWM_SetDutyCycle
        (Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(26U);
      MW_PWM_Close
        (Tracker_with_Position_Contro_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/ENB' */
}
