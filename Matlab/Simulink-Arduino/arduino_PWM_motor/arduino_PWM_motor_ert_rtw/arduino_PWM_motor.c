/*
 * arduino_PWM_motor.c
 *
 * Code generation for model "arduino_PWM_motor".
 *
 * Model version              : 1.11
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Mar 21 13:14:31 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_PWM_motor.h"
#include "arduino_PWM_motor_private.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>

/* Block states (default storage) */
DW_arduino_PWM_motor_T arduino_PWM_motor_DW;

/* Real-time model */
static RT_MODEL_arduino_PWM_motor_T arduino_PWM_motor_M_;
RT_MODEL_arduino_PWM_motor_T *const arduino_PWM_motor_M = &arduino_PWM_motor_M_;
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
void arduino_PWM_motor_step(void)
{
  real_T y;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/ENA1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
  if (arduino_PWM_motor_P.Constant_Value <= 255.0) {
    y = arduino_PWM_motor_P.Constant_Value;
  } else {
    y = 255.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  MW_PWM_SetDutyCycle(arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, y);

  /* End of MATLABSystem: '<Root>/ENA1' */

  /* MATLABSystem: '<Root>/IN1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  y = rt_roundd_snf(arduino_PWM_motor_P.Constant1_Value);
  if (y < 256.0) {
    if (y >= 0.0) {
      tmp = (uint8_T)y;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp);

  /* End of MATLABSystem: '<Root>/IN1' */

  /* MATLABSystem: '<Root>/IN2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  y = rt_roundd_snf(arduino_PWM_motor_P.Constant2_Value);
  if (y < 256.0) {
    if (y >= 0.0) {
      tmp = (uint8_T)y;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp);

  /* End of MATLABSystem: '<Root>/IN2' */
  {                                    /* Sample time: [0.2s, 0.0s] */
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
  if (!(++arduino_PWM_motor_M->Timing.clockTick0)) {
    ++arduino_PWM_motor_M->Timing.clockTickH0;
  }

  arduino_PWM_motor_M->Timing.taskTime0 = arduino_PWM_motor_M->Timing.clockTick0
    * arduino_PWM_motor_M->Timing.stepSize0 +
    arduino_PWM_motor_M->Timing.clockTickH0 *
    arduino_PWM_motor_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void arduino_PWM_motor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)arduino_PWM_motor_M, 0,
                sizeof(RT_MODEL_arduino_PWM_motor_T));
  rtmSetTFinal(arduino_PWM_motor_M, -1);
  arduino_PWM_motor_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  arduino_PWM_motor_M->Sizes.checksums[0] = (2974142736U);
  arduino_PWM_motor_M->Sizes.checksums[1] = (3314509526U);
  arduino_PWM_motor_M->Sizes.checksums[2] = (4164224287U);
  arduino_PWM_motor_M->Sizes.checksums[3] = (1614115224U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    arduino_PWM_motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_PWM_motor_M->extModeInfo,
      &arduino_PWM_motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_PWM_motor_M->extModeInfo,
                        arduino_PWM_motor_M->Sizes.checksums);
    rteiSetTPtr(arduino_PWM_motor_M->extModeInfo, rtmGetTPtr(arduino_PWM_motor_M));
  }

  /* states (dwork) */
  (void) memset((void *)&arduino_PWM_motor_DW, 0,
                sizeof(DW_arduino_PWM_motor_T));

  /* Start for MATLABSystem: '<Root>/ENA1' */
  arduino_PWM_motor_DW.obj_e.matlabCodegenIsDeleted = false;
  arduino_PWM_motor_DW.objisempty_h = true;
  arduino_PWM_motor_DW.obj_e.isInitialized = 1;
  arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0,
    0.0);
  arduino_PWM_motor_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/IN1' */
  arduino_PWM_motor_DW.obj_i.matlabCodegenIsDeleted = false;
  arduino_PWM_motor_DW.objisempty_o = true;
  arduino_PWM_motor_DW.obj_i.isInitialized = 1;
  digitalIOSetup(4, 1);
  arduino_PWM_motor_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/IN2' */
  arduino_PWM_motor_DW.obj.matlabCodegenIsDeleted = false;
  arduino_PWM_motor_DW.objisempty = true;
  arduino_PWM_motor_DW.obj.isInitialized = 1;
  digitalIOSetup(2, 1);
  arduino_PWM_motor_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void arduino_PWM_motor_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ENA1' */
  if (!arduino_PWM_motor_DW.obj_e.matlabCodegenIsDeleted) {
    arduino_PWM_motor_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((arduino_PWM_motor_DW.obj_e.isInitialized == 1) &&
        arduino_PWM_motor_DW.obj_e.isSetupComplete) {
      arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6U);
      MW_PWM_SetDutyCycle(arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6U);
      MW_PWM_Close(arduino_PWM_motor_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ENA1' */

  /* Terminate for MATLABSystem: '<Root>/IN1' */
  if (!arduino_PWM_motor_DW.obj_i.matlabCodegenIsDeleted) {
    arduino_PWM_motor_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN1' */

  /* Terminate for MATLABSystem: '<Root>/IN2' */
  if (!arduino_PWM_motor_DW.obj.matlabCodegenIsDeleted) {
    arduino_PWM_motor_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN2' */
}
