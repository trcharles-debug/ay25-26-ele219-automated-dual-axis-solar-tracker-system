/*
 * arduino_motor_encoder.c
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

#include "arduino_motor_encoder.h"
#include "arduino_motor_encoder_private.h"
#include <math.h>
#include "rtwtypes.h"
#include "multiword_types.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_arduino_motor_encoder_T arduino_motor_encoder_B;

/* Block states (default storage) */
DW_arduino_motor_encoder_T arduino_motor_encoder_DW;

/* Real-time model */
static RT_MODEL_arduino_motor_encode_T arduino_motor_encoder_M_;
RT_MODEL_arduino_motor_encode_T *const arduino_motor_encoder_M =
  &arduino_motor_encoder_M_;
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

void sMultiWord2sMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T y[],
  int16_T n)
{
  uint32_T ys;
  int16_T i;
  int16_T nm1;
  boolean_T doSaturation = false;
  nm1 = n - 1;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  if (n1 > n) {
    doSaturation = (((u1[n1 - 1] ^ u1[n - 1]) & 2147483648UL) != 0UL);
    i = n1 - 1;
    while ((!doSaturation) && (i >= n)) {
      doSaturation = (u1[i] != ys);
      i--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (i = 0; i < nm1; i++) {
      y[i] = ys;
    }

    y[i] = ys ^ 2147483648UL;
  } else {
    nm1 = n1 < n ? n1 : n;
    for (i = 0; i < nm1; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = ys;
      i++;
    }
  }
}

void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int16_T n)
{
  uint32_T borrow = 0UL;
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0UL ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
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

/* Model step function */
void arduino_motor_encoder_step(void)
{
  /* local block i/o variables */
  int64m_T rtb_TSamp;
  int128m_T tmp_1;
  int64m_T tmp_2;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  int32_T rtb_Encoder_0;
  uint32_T tmp;
  uint32_T tmp_0;
  uint8_T tmp_3;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  if (arduino_motor_encoder_P.Constant_Value >
      arduino_motor_encoder_P.Switch_Threshold) {
    rtb_Switch_idx_0 = arduino_motor_encoder_P.Constant2_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = arduino_motor_encoder_P.Constant5_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_P.Constant4_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/IN1' */
  rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_0);
  if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
      tmp_3 = (uint8_T)rtb_Switch_idx_0;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp_3);

  /* End of MATLABSystem: '<S2>/IN1' */

  /* MATLABSystem: '<S2>/IN2' */
  rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_1);
  if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
      tmp_3 = (uint8_T)rtb_Switch_idx_0;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp_3);

  /* End of MATLABSystem: '<S2>/IN2' */

  /* MATLABSystem: '<S2>/ENA1' */
  arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (6UL);

  /* Abs: '<S2>/Abs' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Switch_idx_1 = fabs(arduino_motor_encoder_P.Constant_Value);

  /* MATLABSystem: '<S2>/ENA1' */
  if (!(rtb_Switch_idx_1 <= 255.0)) {
    rtb_Switch_idx_1 = 255.0;
  }

  MW_PWM_SetDutyCycle(arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Switch_idx_1);

  /* MATLABSystem: '<S1>/Encoder' */
  if (arduino_motor_encoder_DW.obj.SampleTime !=
      arduino_motor_encoder_P.Encoder_SampleTime) {
    arduino_motor_encoder_DW.obj.SampleTime =
      arduino_motor_encoder_P.Encoder_SampleTime;
  }

  if (arduino_motor_encoder_DW.obj.TunablePropsChanged) {
    arduino_motor_encoder_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(arduino_motor_encoder_DW.obj.Index, &rtb_Encoder_0);

  /* Gain: '<S1>/Gear_Ratio' incorporates:
   *  MATLABSystem: '<S1>/Encoder'
   */
  tmp = (uint32_T)arduino_motor_encoder_P.Gear_Ratio_Gain_a;
  tmp_0 = (uint32_T)rtb_Encoder_0;
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &rtb_TSamp.chunks[0U], 2);

  /* Gain: '<S3>/Gain' */
  arduino_motor_encoder_B.Gain = arduino_motor_encoder_P.Gain_Gain;

  /* Gain: '<S3>/Gain' */
  sMultiWordMul(&arduino_motor_encoder_P.Gain_Gain.chunks[0U], 2,
                &rtb_TSamp.chunks[0U], 2, &tmp_1.chunks[0U], 4);
  sMultiWordShr(&tmp_1.chunks[0U], 4, 41U,
                &arduino_motor_encoder_B.Gear_Ratio.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&arduino_motor_encoder_B.Gear_Ratio.chunks[0U], 4,
    &arduino_motor_encoder_B.Gain.chunks[0U], 2);

  /* Sum: '<S4>/Diff' incorporates:
   *  SampleTimeMath: '<S4>/TSamp'
   *  UnitDelay: '<S4>/UD'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  MultiWordSub(&rtb_TSamp.chunks[0U],
               &arduino_motor_encoder_DW.UD_DSTATE.chunks[0U], &tmp_2.chunks[0U],
               2);

  /* Gain: '<Root>/Gear_Ratio' */
  sMultiWordMul(&arduino_motor_encoder_P.Gear_Ratio_Gain.chunks[0U], 2,
                &tmp_2.chunks[0U], 2,
                &arduino_motor_encoder_B.Gear_Ratio.chunks[0U], 4);

  /* Update for UnitDelay: '<S4>/UD' incorporates:
   *  SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  arduino_motor_encoder_DW.UD_DSTATE = rtb_TSamp;

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      (((arduino_motor_encoder_M->Timing.clockTick0+
         arduino_motor_encoder_M->Timing.clockTickH0* 4294967296.0) * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.05s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      (((arduino_motor_encoder_M->Timing.clockTick1+
         arduino_motor_encoder_M->Timing.clockTickH1* 4294967296.0) * 1) + 0)
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
  if (!(++arduino_motor_encoder_M->Timing.clockTick0)) {
    ++arduino_motor_encoder_M->Timing.clockTickH0;
  }

  arduino_motor_encoder_M->Timing.t[0] =
    arduino_motor_encoder_M->Timing.clockTick0 *
    arduino_motor_encoder_M->Timing.stepSize0 +
    arduino_motor_encoder_M->Timing.clockTickH0 *
    arduino_motor_encoder_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.05, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    arduino_motor_encoder_M->Timing.clockTick1++;
    if (!arduino_motor_encoder_M->Timing.clockTick1) {
      arduino_motor_encoder_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void arduino_motor_encoder_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)arduino_motor_encoder_M, 0,
                sizeof(RT_MODEL_arduino_motor_encode_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&arduino_motor_encoder_M->solverInfo,
                          &arduino_motor_encoder_M->Timing.simTimeStep);
    rtsiSetTPtr(&arduino_motor_encoder_M->solverInfo, &rtmGetTPtr
                (arduino_motor_encoder_M));
    rtsiSetStepSizePtr(&arduino_motor_encoder_M->solverInfo,
                       &arduino_motor_encoder_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&arduino_motor_encoder_M->solverInfo,
                          (&rtmGetErrorStatus(arduino_motor_encoder_M)));
    rtsiSetRTModelPtr(&arduino_motor_encoder_M->solverInfo,
                      arduino_motor_encoder_M);
  }

  rtsiSetSimTimeStep(&arduino_motor_encoder_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&arduino_motor_encoder_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(arduino_motor_encoder_M, &arduino_motor_encoder_M->Timing.tArray[0]);
  rtmSetTFinal(arduino_motor_encoder_M, -1);
  arduino_motor_encoder_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  arduino_motor_encoder_M->Sizes.checksums[0] = (385555881U);
  arduino_motor_encoder_M->Sizes.checksums[1] = (3736024426U);
  arduino_motor_encoder_M->Sizes.checksums[2] = (2492352069U);
  arduino_motor_encoder_M->Sizes.checksums[3] = (2623456421U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    arduino_motor_encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_motor_encoder_M->extModeInfo,
      &arduino_motor_encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_motor_encoder_M->extModeInfo,
                        arduino_motor_encoder_M->Sizes.checksums);
    rteiSetTPtr(arduino_motor_encoder_M->extModeInfo, rtmGetTPtr
                (arduino_motor_encoder_M));
  }

  /* block I/O */
  (void) memset(((void *) &arduino_motor_encoder_B), 0,
                sizeof(B_arduino_motor_encoder_T));

  /* states (dwork) */
  (void) memset((void *)&arduino_motor_encoder_DW, 0,
                sizeof(DW_arduino_motor_encoder_T));

  /* Start for MATLABSystem: '<S2>/IN1' */
  arduino_motor_encoder_DW.obj_m.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_DW.objisempty_a = true;
  arduino_motor_encoder_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(7, 1);
  arduino_motor_encoder_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/IN2' */
  arduino_motor_encoder_DW.obj_j.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_DW.objisempty = true;
  arduino_motor_encoder_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(8, 1);
  arduino_motor_encoder_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/ENA1' */
  arduino_motor_encoder_DW.obj_g.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_DW.objisempty_aw = true;
  arduino_motor_encoder_DW.obj_g.isInitialized = 1L;
  arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL,
    0.0, 0.0);
  arduino_motor_encoder_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Encoder' */
  arduino_motor_encoder_DW.obj.Index = 0U;
  arduino_motor_encoder_DW.obj.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_DW.objisempty_e = true;
  arduino_motor_encoder_DW.obj.SampleTime =
    arduino_motor_encoder_P.Encoder_SampleTime;
  arduino_motor_encoder_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &arduino_motor_encoder_DW.obj.Index);
  arduino_motor_encoder_DW.obj.isSetupComplete = true;
  arduino_motor_encoder_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  arduino_motor_encoder_DW.UD_DSTATE =
    arduino_motor_encoder_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
  MW_EncoderReset(arduino_motor_encoder_DW.obj.Index);
}

/* Model terminate function */
void arduino_motor_encoder_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/IN1' */
  if (!arduino_motor_encoder_DW.obj_m.matlabCodegenIsDeleted) {
    arduino_motor_encoder_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN1' */

  /* Terminate for MATLABSystem: '<S2>/IN2' */
  if (!arduino_motor_encoder_DW.obj_j.matlabCodegenIsDeleted) {
    arduino_motor_encoder_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2' */

  /* Terminate for MATLABSystem: '<S2>/ENA1' */
  if (!arduino_motor_encoder_DW.obj_g.matlabCodegenIsDeleted) {
    arduino_motor_encoder_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_DW.obj_g.isInitialized == 1L) &&
        arduino_motor_encoder_DW.obj_g.isSetupComplete) {
      arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close(arduino_motor_encoder_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENA1' */

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!arduino_motor_encoder_DW.obj.matlabCodegenIsDeleted) {
    arduino_motor_encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_DW.obj.isInitialized == 1L) &&
        arduino_motor_encoder_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
}
