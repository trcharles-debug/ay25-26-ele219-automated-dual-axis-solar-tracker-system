/*
 * arduino_motor_encoder_open_loop.c
 *
 * Code generation for model "arduino_motor_encoder_open_loop".
 *
 * Model version              : 1.96
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Apr 22 20:11:51 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_motor_encoder_open_loop.h"
#include "arduino_motor_encoder_open_loop_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_arduino_motor_encoder_open__T arduino_motor_encoder_open_lo_B;

/* Block states (default storage) */
DW_arduino_motor_encoder_open_T arduino_motor_encoder_open_l_DW;

/* Real-time model */
static RT_MODEL_arduino_motor_encode_T arduino_motor_encoder_open_l_M_;
RT_MODEL_arduino_motor_encode_T *const arduino_motor_encoder_open_l_M =
  &arduino_motor_encoder_open_l_M_;
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

/* Model step function */
void arduino_motor_encoder_open_loop_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  int32_T rtb_Encoder_0;
  uint8_T tmp;

  /* Step: '<Root>/Step' */
  if ((((arduino_motor_encoder_open_l_M->Timing.clockTick1+
         arduino_motor_encoder_open_l_M->Timing.clockTickH1* 4294967296.0)) *
       0.01) < arduino_motor_encoder_open_lo_P.Step_Time) {
    /* Step: '<Root>/Step' */
    arduino_motor_encoder_open_lo_B.Step =
      arduino_motor_encoder_open_lo_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    arduino_motor_encoder_open_lo_B.Step =
      arduino_motor_encoder_open_lo_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  if (arduino_motor_encoder_open_lo_B.Step >
      arduino_motor_encoder_open_lo_P.Switch_Threshold) {
    rtb_Switch_idx_0 = arduino_motor_encoder_open_lo_P.Constant2_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = arduino_motor_encoder_open_lo_P.Constant5_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Constant4_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/IN1' */
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

  /* End of MATLABSystem: '<S2>/IN1' */

  /* MATLABSystem: '<S2>/IN2' */
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

  /* End of MATLABSystem: '<S2>/IN2' */
  /* MATLABSystem: '<S1>/Encoder' */
  if (arduino_motor_encoder_open_l_DW.obj.SampleTime !=
      arduino_motor_encoder_open_lo_P.Encoder_SampleTime) {
    arduino_motor_encoder_open_l_DW.obj.SampleTime =
      arduino_motor_encoder_open_lo_P.Encoder_SampleTime;
  }

  if (arduino_motor_encoder_open_l_DW.obj.TunablePropsChanged) {
    arduino_motor_encoder_open_l_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(arduino_motor_encoder_open_l_DW.obj.Index, &rtb_Encoder_0);

  /* SampleTimeMath: '<S4>/TSamp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Gain: '<S1>/Gear_Ratio'
   *  MATLABSystem: '<S1>/Encoder'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = arduino_motor_encoder_open_lo_P.Gear_Ratio_Gain * (real_T)
    rtb_Encoder_0 * arduino_motor_encoder_open_lo_P.TSamp_WtEt;

  /* Gain: '<Root>/rad//sToRPM' incorporates:
   *  Sum: '<S4>/Diff'
   *  UnitDelay: '<S4>/UD'
   */
  arduino_motor_encoder_open_lo_B.radsToRPM = (rtb_TSamp -
    arduino_motor_encoder_open_l_DW.UD_DSTATE) *
    arduino_motor_encoder_open_lo_P.radsToRPM_Gain;

  /* MATLABSystem: '<S2>/ENA1' */
  arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(6UL);

  /* Abs: '<S2>/Abs' */
  rtb_Switch_idx_1 = fabs(arduino_motor_encoder_open_lo_B.Step);

  /* MATLABSystem: '<S2>/ENA1' */
  if (!(rtb_Switch_idx_1 <= 255.0)) {
    rtb_Switch_idx_1 = 255.0;
  }

  MW_PWM_SetDutyCycle
    (arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Switch_idx_1);

  /* Update for UnitDelay: '<S4>/UD' */
  arduino_motor_encoder_open_l_DW.UD_DSTATE = rtb_TSamp;

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      (((arduino_motor_encoder_open_l_M->Timing.clockTick0+
         arduino_motor_encoder_open_l_M->Timing.clockTickH0* 4294967296.0) * 1)
       + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      (((arduino_motor_encoder_open_l_M->Timing.clockTick1+
         arduino_motor_encoder_open_l_M->Timing.clockTickH1* 4294967296.0) * 1)
       + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++arduino_motor_encoder_open_l_M->Timing.clockTick0)) {
    ++arduino_motor_encoder_open_l_M->Timing.clockTickH0;
  }

  arduino_motor_encoder_open_l_M->Timing.t[0] =
    arduino_motor_encoder_open_l_M->Timing.clockTick0 *
    arduino_motor_encoder_open_l_M->Timing.stepSize0 +
    arduino_motor_encoder_open_l_M->Timing.clockTickH0 *
    arduino_motor_encoder_open_l_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    arduino_motor_encoder_open_l_M->Timing.clockTick1++;
    if (!arduino_motor_encoder_open_l_M->Timing.clockTick1) {
      arduino_motor_encoder_open_l_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void arduino_motor_encoder_open_loop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)arduino_motor_encoder_open_l_M, 0,
                sizeof(RT_MODEL_arduino_motor_encode_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&arduino_motor_encoder_open_l_M->solverInfo,
                          &arduino_motor_encoder_open_l_M->Timing.simTimeStep);
    rtsiSetTPtr(&arduino_motor_encoder_open_l_M->solverInfo, &rtmGetTPtr
                (arduino_motor_encoder_open_l_M));
    rtsiSetStepSizePtr(&arduino_motor_encoder_open_l_M->solverInfo,
                       &arduino_motor_encoder_open_l_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&arduino_motor_encoder_open_l_M->solverInfo,
                          (&rtmGetErrorStatus(arduino_motor_encoder_open_l_M)));
    rtsiSetRTModelPtr(&arduino_motor_encoder_open_l_M->solverInfo,
                      arduino_motor_encoder_open_l_M);
  }

  rtsiSetSimTimeStep(&arduino_motor_encoder_open_l_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&arduino_motor_encoder_open_l_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(arduino_motor_encoder_open_l_M,
             &arduino_motor_encoder_open_l_M->Timing.tArray[0]);
  rtmSetTFinal(arduino_motor_encoder_open_l_M, -1);
  arduino_motor_encoder_open_l_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  arduino_motor_encoder_open_l_M->Sizes.checksums[0] = (3984227725U);
  arduino_motor_encoder_open_l_M->Sizes.checksums[1] = (3345834699U);
  arduino_motor_encoder_open_l_M->Sizes.checksums[2] = (18470631U);
  arduino_motor_encoder_open_l_M->Sizes.checksums[3] = (3802559994U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    arduino_motor_encoder_open_l_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_motor_encoder_open_l_M->extModeInfo,
      &arduino_motor_encoder_open_l_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_motor_encoder_open_l_M->extModeInfo,
                        arduino_motor_encoder_open_l_M->Sizes.checksums);
    rteiSetTPtr(arduino_motor_encoder_open_l_M->extModeInfo, rtmGetTPtr
                (arduino_motor_encoder_open_l_M));
  }

  /* block I/O */
  (void) memset(((void *) &arduino_motor_encoder_open_lo_B), 0,
                sizeof(B_arduino_motor_encoder_open__T));

  /* states (dwork) */
  (void) memset((void *)&arduino_motor_encoder_open_l_DW, 0,
                sizeof(DW_arduino_motor_encoder_open_T));

  /* Start for MATLABSystem: '<S2>/IN1' */
  arduino_motor_encoder_open_l_DW.obj_m.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.objisempty_a = true;
  arduino_motor_encoder_open_l_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(7, 1);
  arduino_motor_encoder_open_l_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/IN2' */
  arduino_motor_encoder_open_l_DW.obj_j.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.objisempty = true;
  arduino_motor_encoder_open_l_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(8, 1);
  arduino_motor_encoder_open_l_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Encoder' */
  arduino_motor_encoder_open_l_DW.obj.Index = 0U;
  arduino_motor_encoder_open_l_DW.obj.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.objisempty_e = true;
  arduino_motor_encoder_open_l_DW.obj.SampleTime =
    arduino_motor_encoder_open_lo_P.Encoder_SampleTime;
  arduino_motor_encoder_open_l_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &arduino_motor_encoder_open_l_DW.obj.Index);
  arduino_motor_encoder_open_l_DW.obj.isSetupComplete = true;
  arduino_motor_encoder_open_l_DW.obj.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S2>/ENA1' */
  arduino_motor_encoder_open_l_DW.obj_g.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.objisempty_aw = true;
  arduino_motor_encoder_open_l_DW.obj_g.isInitialized = 1L;
  arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (6UL, 0.0, 0.0);
  arduino_motor_encoder_open_l_DW.obj_g.isSetupComplete = true;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  arduino_motor_encoder_open_l_DW.UD_DSTATE =
    arduino_motor_encoder_open_lo_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
  MW_EncoderReset(arduino_motor_encoder_open_l_DW.obj.Index);
}

/* Model terminate function */
void arduino_motor_encoder_open_loop_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/IN1' */
  if (!arduino_motor_encoder_open_l_DW.obj_m.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN1' */

  /* Terminate for MATLABSystem: '<S2>/IN2' */
  if (!arduino_motor_encoder_open_l_DW.obj_j.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2' */
  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!arduino_motor_encoder_open_l_DW.obj.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_open_l_DW.obj.isInitialized == 1L) &&
        arduino_motor_encoder_open_l_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S2>/ENA1' */
  if (!arduino_motor_encoder_open_l_DW.obj_g.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_open_l_DW.obj_g.isInitialized == 1L) &&
        arduino_motor_encoder_open_l_DW.obj_g.isSetupComplete) {
      arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close
        (arduino_motor_encoder_open_l_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENA1' */
}
