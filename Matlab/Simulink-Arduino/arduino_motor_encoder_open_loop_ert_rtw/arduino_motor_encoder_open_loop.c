/*
 * arduino_motor_encoder_open_loop.c
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
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_TSamp;
  int32_T rtb_Encoder_b_0;
  uint8_T tmp;

  /* Constant: '<Root>/Constant' */
  arduino_motor_encoder_open_lo_B.Constant =
    arduino_motor_encoder_open_lo_P.Constant_Value;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant5'
   */
  if (arduino_motor_encoder_open_lo_B.Constant >
      arduino_motor_encoder_open_lo_P.Switch_Threshold) {
    rtb_Switch_idx_0 = arduino_motor_encoder_open_lo_P.Constant2_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = arduino_motor_encoder_open_lo_P.Constant5_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Constant4_Value;
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

  writeDigitalPin(32, tmp);

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

  writeDigitalPin(33, tmp);

  /* End of MATLABSystem: '<S4>/IN2' */
  /* MATLABSystem: '<S3>/Encoder' */
  if (arduino_motor_encoder_open_l_DW.obj_b.TunablePropsChanged) {
    arduino_motor_encoder_open_l_DW.obj_b.TunablePropsChanged = false;
  }

  MW_EncoderRead(arduino_motor_encoder_open_l_DW.obj_b.Index, &rtb_Encoder_b_0);

  /* SampleTimeMath: '<S6>/TSamp' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gear_Ratio'
   *  MATLABSystem: '<S3>/Encoder'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = arduino_motor_encoder_open_lo_P.Gear_Ratio_Gain * (real_T)
    rtb_Encoder_b_0 * arduino_motor_encoder_open_lo_P.TSamp_WtEt;

  /* Gain: '<S1>/rad//s To RPM' incorporates:
   *  Sum: '<S6>/Diff'
   *  UnitDelay: '<S6>/UD'
   */
  arduino_motor_encoder_open_lo_B.radsToRPM = (rtb_TSamp -
    arduino_motor_encoder_open_l_DW.UD_DSTATE) *
    arduino_motor_encoder_open_lo_P.radsToRPM_Gain;

  /* MATLABSystem: '<S4>/ENA1' */
  arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(18U);

  /* Abs: '<S4>/Abs' */
  rtb_Switch_idx_0 = fabs(arduino_motor_encoder_open_lo_B.Constant);

  /* Start for MATLABSystem: '<S4>/ENA1' */
  if (!(rtb_Switch_idx_0 <= 255.0)) {
    rtb_Switch_idx_0 = 255.0;
  }

  /* MATLABSystem: '<S4>/ENA1' */
  MW_PWM_SetDutyCycle
    (arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Switch_idx_0);

  /* Constant: '<Root>/Constant1' */
  arduino_motor_encoder_open_lo_B.Constant1 =
    arduino_motor_encoder_open_lo_P.Constant1_Value_g;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/Constant5'
   */
  if (arduino_motor_encoder_open_lo_B.Constant1 >
      arduino_motor_encoder_open_lo_P.Switch_Threshold_k) {
    rtb_Switch_idx_0 = arduino_motor_encoder_open_lo_P.Constant2_Value_d;
    rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Constant1_Value_l;
  } else {
    rtb_Switch_idx_0 = arduino_motor_encoder_open_lo_P.Constant5_Value_e;
    rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Constant4_Value_p;
  }

  /* End of Switch: '<S8>/Switch' */

  /* MATLABSystem: '<S8>/IN3' */
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

  /* End of MATLABSystem: '<S8>/IN3' */

  /* MATLABSystem: '<S8>/IN4' */
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

  /* End of MATLABSystem: '<S8>/IN4' */
  /* MATLABSystem: '<S7>/Encoder' */
  if (arduino_motor_encoder_open_l_DW.obj_l.TunablePropsChanged) {
    arduino_motor_encoder_open_l_DW.obj_l.TunablePropsChanged = false;
  }

  MW_EncoderRead(arduino_motor_encoder_open_l_DW.obj_l.Index, &rtb_Encoder_b_0);

  /* SampleTimeMath: '<S10>/TSamp' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S7>/Gear_Ratio'
   *  MATLABSystem: '<S7>/Encoder'
   *
   * About '<S10>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_Switch_idx_1 = arduino_motor_encoder_open_lo_P.Gear_Ratio_Gain_m * (real_T)
    rtb_Encoder_b_0 * arduino_motor_encoder_open_lo_P.TSamp_WtEt_k;

  /* Gain: '<S2>/rad//s To RPM' incorporates:
   *  Sum: '<S10>/Diff'
   *  UnitDelay: '<S10>/UD'
   */
  arduino_motor_encoder_open_lo_B.radsToRPM_k = (rtb_Switch_idx_1 -
    arduino_motor_encoder_open_l_DW.UD_DSTATE_b) *
    arduino_motor_encoder_open_lo_P.radsToRPM_Gain_n;

  /* MATLABSystem: '<S8>/ENB' */
  arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(26U);

  /* Abs: '<S8>/Abs' */
  rtb_Switch_idx_0 = fabs(arduino_motor_encoder_open_lo_B.Constant1);

  /* Start for MATLABSystem: '<S8>/ENB' */
  if (!(rtb_Switch_idx_0 <= 255.0)) {
    rtb_Switch_idx_0 = 255.0;
  }

  /* MATLABSystem: '<S8>/ENB' */
  MW_PWM_SetDutyCycle
    (arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Switch_idx_0);

  /* Update for UnitDelay: '<S6>/UD' */
  arduino_motor_encoder_open_l_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S10>/UD' */
  arduino_motor_encoder_open_l_DW.UD_DSTATE_b = rtb_Switch_idx_1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  arduino_motor_encoder_open_l_M->Timing.taskTime0 =
    ((time_T)(++arduino_motor_encoder_open_l_M->Timing.clockTick0)) *
    arduino_motor_encoder_open_l_M->Timing.stepSize0;
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
  rtmSetTFinal(arduino_motor_encoder_open_l_M, -1);
  arduino_motor_encoder_open_l_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  arduino_motor_encoder_open_l_M->Sizes.checksums[0] = (4058607726U);
  arduino_motor_encoder_open_l_M->Sizes.checksums[1] = (1528498908U);
  arduino_motor_encoder_open_l_M->Sizes.checksums[2] = (3336934206U);
  arduino_motor_encoder_open_l_M->Sizes.checksums[3] = (4172841976U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    arduino_motor_encoder_open_l_M->extModeInfo = (&rt_ExtModeInfo);
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

  /* InitializeConditions for UnitDelay: '<S6>/UD' */
  arduino_motor_encoder_open_l_DW.UD_DSTATE =
    arduino_motor_encoder_open_lo_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S10>/UD' */
  arduino_motor_encoder_open_l_DW.UD_DSTATE_b =
    arduino_motor_encoder_open_lo_P.DiscreteDerivative_ICPrevScal_j;

  /* Start for MATLABSystem: '<S4>/IN1' */
  arduino_motor_encoder_open_l_DW.obj_o.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_o.isInitialized = 1;
  digitalIOSetup(32, 1);
  arduino_motor_encoder_open_l_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/IN2' */
  arduino_motor_encoder_open_l_DW.obj_e.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_e.isInitialized = 1;
  digitalIOSetup(33, 1);
  arduino_motor_encoder_open_l_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Encoder' */
  arduino_motor_encoder_open_l_DW.obj_b.Index = 0U;
  arduino_motor_encoder_open_l_DW.obj_b.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_b.isInitialized = 1;
  MW_EncoderSetup(15U, 16U, &arduino_motor_encoder_open_l_DW.obj_b.Index);
  arduino_motor_encoder_open_l_DW.obj_b.isSetupComplete = true;
  arduino_motor_encoder_open_l_DW.obj_b.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(arduino_motor_encoder_open_l_DW.obj_b.Index);

  /* Start for MATLABSystem: '<S4>/ENA1' */
  arduino_motor_encoder_open_l_DW.obj_d.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_d.isInitialized = 1;
  arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (18U, 0.0, 0.0);
  arduino_motor_encoder_open_l_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/IN3' */
  arduino_motor_encoder_open_l_DW.obj_c.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_c.isInitialized = 1;
  digitalIOSetup(19, 1);
  arduino_motor_encoder_open_l_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/IN4' */
  arduino_motor_encoder_open_l_DW.obj.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj.isInitialized = 1;
  digitalIOSetup(25, 1);
  arduino_motor_encoder_open_l_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Encoder' */
  arduino_motor_encoder_open_l_DW.obj_l.Index = 0U;
  arduino_motor_encoder_open_l_DW.obj_l.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_l.isInitialized = 1;
  MW_EncoderSetup(5U, 4U, &arduino_motor_encoder_open_l_DW.obj_l.Index);
  arduino_motor_encoder_open_l_DW.obj_l.isSetupComplete = true;
  arduino_motor_encoder_open_l_DW.obj_l.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S7>/Encoder' */
  MW_EncoderReset(arduino_motor_encoder_open_l_DW.obj_l.Index);

  /* Start for MATLABSystem: '<S8>/ENB' */
  arduino_motor_encoder_open_l_DW.obj_p.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_open_l_DW.obj_p.isInitialized = 1;
  arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (26U, 0.0, 0.0);
  arduino_motor_encoder_open_l_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void arduino_motor_encoder_open_loop_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/IN1' */
  if (!arduino_motor_encoder_open_l_DW.obj_o.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/IN1' */

  /* Terminate for MATLABSystem: '<S4>/IN2' */
  if (!arduino_motor_encoder_open_l_DW.obj_e.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/IN2' */
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!arduino_motor_encoder_open_l_DW.obj_b.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_open_l_DW.obj_b.isInitialized == 1) &&
        arduino_motor_encoder_open_l_DW.obj_b.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */
  /* Terminate for MATLABSystem: '<S4>/ENA1' */
  if (!arduino_motor_encoder_open_l_DW.obj_d.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_open_l_DW.obj_d.isInitialized == 1) &&
        arduino_motor_encoder_open_l_DW.obj_d.isSetupComplete) {
      arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(18U);
      MW_PWM_SetDutyCycle
        (arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(18U);
      MW_PWM_Close
        (arduino_motor_encoder_open_l_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/ENA1' */

  /* Terminate for MATLABSystem: '<S8>/IN3' */
  if (!arduino_motor_encoder_open_l_DW.obj_c.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/IN3' */

  /* Terminate for MATLABSystem: '<S8>/IN4' */
  if (!arduino_motor_encoder_open_l_DW.obj.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/IN4' */
  /* Terminate for MATLABSystem: '<S7>/Encoder' */
  if (!arduino_motor_encoder_open_l_DW.obj_l.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_open_l_DW.obj_l.isInitialized == 1) &&
        arduino_motor_encoder_open_l_DW.obj_l.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Encoder' */
  /* Terminate for MATLABSystem: '<S8>/ENB' */
  if (!arduino_motor_encoder_open_l_DW.obj_p.matlabCodegenIsDeleted) {
    arduino_motor_encoder_open_l_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_open_l_DW.obj_p.isInitialized == 1) &&
        arduino_motor_encoder_open_l_DW.obj_p.isSetupComplete) {
      arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(26U);
      MW_PWM_SetDutyCycle
        (arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(26U);
      MW_PWM_Close
        (arduino_motor_encoder_open_l_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/ENB' */
}
