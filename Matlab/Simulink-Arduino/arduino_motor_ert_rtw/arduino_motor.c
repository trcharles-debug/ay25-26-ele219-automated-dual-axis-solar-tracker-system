/*
 * arduino_motor.c
 *
 * Code generation for model "arduino_motor".
 *
 * Model version              : 1.80
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Apr 21 19:55:35 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_motor.h"
#include "arduino_motor_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_arduino_motor_T arduino_motor_DW;

/* Real-time model */
static RT_MODEL_arduino_motor_T arduino_motor_M_;
RT_MODEL_arduino_motor_T *const arduino_motor_M = &arduino_motor_M_;
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
void arduino_motor_step(void)
{
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  uint8_T tmp;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   */
  if (arduino_motor_P.Constant_Value > arduino_motor_P.Switch_Threshold) {
    rtb_Switch_idx_0 = arduino_motor_P.Constant2_Value;
    rtb_Switch_idx_1 = arduino_motor_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = arduino_motor_P.Constant5_Value;
    rtb_Switch_idx_1 = arduino_motor_P.Constant4_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLABSystem: '<S1>/IN1' */
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

  /* End of MATLABSystem: '<S1>/IN1' */

  /* MATLABSystem: '<S1>/IN2' */
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

  /* End of MATLABSystem: '<S1>/IN2' */

  /* MATLABSystem: '<S1>/ENA1' */
  arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Abs: '<S1>/Abs' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Switch_idx_1 = fabs(arduino_motor_P.Constant_Value);

  /* MATLABSystem: '<S1>/ENA1' */
  if (!(rtb_Switch_idx_1 <= 255.0)) {
    rtb_Switch_idx_1 = 255.0;
  }

  MW_PWM_SetDutyCycle(arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Switch_idx_1);

  {                                    /* Sample time: [0.005s, 0.0s] */
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
  if (!(++arduino_motor_M->Timing.clockTick0)) {
    ++arduino_motor_M->Timing.clockTickH0;
  }

  arduino_motor_M->Timing.taskTime0 = arduino_motor_M->Timing.clockTick0 *
    arduino_motor_M->Timing.stepSize0 + arduino_motor_M->Timing.clockTickH0 *
    arduino_motor_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void arduino_motor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)arduino_motor_M, 0,
                sizeof(RT_MODEL_arduino_motor_T));
  rtmSetTFinal(arduino_motor_M, -1);
  arduino_motor_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  arduino_motor_M->Sizes.checksums[0] = (1328072275U);
  arduino_motor_M->Sizes.checksums[1] = (219347053U);
  arduino_motor_M->Sizes.checksums[2] = (1337861604U);
  arduino_motor_M->Sizes.checksums[3] = (3380741106U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    arduino_motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_motor_M->extModeInfo,
      &arduino_motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_motor_M->extModeInfo,
                        arduino_motor_M->Sizes.checksums);
    rteiSetTPtr(arduino_motor_M->extModeInfo, rtmGetTPtr(arduino_motor_M));
  }

  /* states (dwork) */
  (void) memset((void *)&arduino_motor_DW, 0,
                sizeof(DW_arduino_motor_T));

  /* Start for MATLABSystem: '<S1>/IN1' */
  arduino_motor_DW.obj_m.matlabCodegenIsDeleted = false;
  arduino_motor_DW.objisempty_a = true;
  arduino_motor_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(7, 1);
  arduino_motor_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/IN2' */
  arduino_motor_DW.obj_j.matlabCodegenIsDeleted = false;
  arduino_motor_DW.objisempty = true;
  arduino_motor_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(8, 1);
  arduino_motor_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/ENA1' */
  arduino_motor_DW.obj.matlabCodegenIsDeleted = false;
  arduino_motor_DW.objisempty_aw = true;
  arduino_motor_DW.obj.isInitialized = 1L;
  arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
  arduino_motor_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void arduino_motor_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/IN1' */
  if (!arduino_motor_DW.obj_m.matlabCodegenIsDeleted) {
    arduino_motor_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/IN1' */

  /* Terminate for MATLABSystem: '<S1>/IN2' */
  if (!arduino_motor_DW.obj_j.matlabCodegenIsDeleted) {
    arduino_motor_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/IN2' */

  /* Terminate for MATLABSystem: '<S1>/ENA1' */
  if (!arduino_motor_DW.obj.matlabCodegenIsDeleted) {
    arduino_motor_DW.obj.matlabCodegenIsDeleted = true;
    if ((arduino_motor_DW.obj.isInitialized == 1L) &&
        arduino_motor_DW.obj.isSetupComplete) {
      arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(arduino_motor_DW.obj.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ENA1' */
}
