/*
 * File: arduino_motor_encoder_ESP32.c
 *
 * Code generated for Simulink model 'arduino_motor_encoder_ESP32'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Apr 30 13:08:46 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_motor_encoder_ESP32.h"
#include "arduino_motor_encoder_ESP32_private.h"
#include <math.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_arduino_motor_encoder_ESP3_T arduino_motor_encoder_ESP32_DW;

/* Real-time model */
static RT_MODEL_arduino_motor_encode_T arduino_motor_encoder_ESP32_M_;
RT_MODEL_arduino_motor_encode_T *const arduino_motor_encoder_ESP32_M =
  &arduino_motor_encoder_ESP32_M_;
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
void arduino_motor_encoder_ESP32_step(void)
{
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  int32_T tmp;
  uint8_T tmp_0;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  if (arduino_motor_encoder_ESP32_P.Constant_Value >
      arduino_motor_encoder_ESP32_P.Switch_Threshold) {
    rtb_Switch_idx_0 = arduino_motor_encoder_ESP32_P.Constant2_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_ESP32_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = arduino_motor_encoder_ESP32_P.Constant5_Value;
    rtb_Switch_idx_1 = arduino_motor_encoder_ESP32_P.Constant4_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/IN1' */
  rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_0);
  if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
      tmp_0 = (uint8_T)rtb_Switch_idx_0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(1, tmp_0);

  /* End of MATLABSystem: '<S2>/IN1' */

  /* MATLABSystem: '<S2>/IN2' */
  rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_1);
  if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
      tmp_0 = (uint8_T)rtb_Switch_idx_0;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(2, tmp_0);

  /* End of MATLABSystem: '<S2>/IN2' */

  /* MATLABSystem: '<S2>/ENA1' */
  arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(4U);

  /* Abs: '<S2>/Abs' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Switch_idx_1 = fabs(arduino_motor_encoder_ESP32_P.Constant_Value);

  /* Start for MATLABSystem: '<S2>/ENA1' */
  if (!(rtb_Switch_idx_1 <= 255.0)) {
    rtb_Switch_idx_1 = 255.0;
  }

  /* MATLABSystem: '<S2>/ENA1' */
  MW_PWM_SetDutyCycle
    (arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
     rtb_Switch_idx_1);

  /* MATLABSystem: '<S1>/Encoder' */
  if (arduino_motor_encoder_ESP32_DW.obj.SampleTime !=
      arduino_motor_encoder_ESP32_P.Encoder_SampleTime) {
    arduino_motor_encoder_ESP32_DW.obj.SampleTime =
      arduino_motor_encoder_ESP32_P.Encoder_SampleTime;
  }

  if (arduino_motor_encoder_ESP32_DW.obj.TunablePropsChanged) {
    arduino_motor_encoder_ESP32_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(arduino_motor_encoder_ESP32_DW.obj.Index, &tmp);

  /* End of MATLABSystem: '<S1>/Encoder' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  arduino_motor_encoder_ESP32_M->Timing.t[0] =
    ((time_T)(++arduino_motor_encoder_ESP32_M->Timing.clockTick0)) *
    arduino_motor_encoder_ESP32_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.05, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    arduino_motor_encoder_ESP32_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void arduino_motor_encoder_ESP32_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&arduino_motor_encoder_ESP32_M->solverInfo,
                          &arduino_motor_encoder_ESP32_M->Timing.simTimeStep);
    rtsiSetTPtr(&arduino_motor_encoder_ESP32_M->solverInfo, &rtmGetTPtr
                (arduino_motor_encoder_ESP32_M));
    rtsiSetStepSizePtr(&arduino_motor_encoder_ESP32_M->solverInfo,
                       &arduino_motor_encoder_ESP32_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&arduino_motor_encoder_ESP32_M->solverInfo,
                          (&rtmGetErrorStatus(arduino_motor_encoder_ESP32_M)));
    rtsiSetRTModelPtr(&arduino_motor_encoder_ESP32_M->solverInfo,
                      arduino_motor_encoder_ESP32_M);
  }

  rtsiSetSimTimeStep(&arduino_motor_encoder_ESP32_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&arduino_motor_encoder_ESP32_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(arduino_motor_encoder_ESP32_M,
             &arduino_motor_encoder_ESP32_M->Timing.tArray[0]);
  arduino_motor_encoder_ESP32_M->Timing.stepSize0 = 0.05;

  /* Start for MATLABSystem: '<S2>/IN1' */
  arduino_motor_encoder_ESP32_DW.obj_m.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_ESP32_DW.obj_m.isInitialized = 1;
  digitalIOSetup(1, 1);
  arduino_motor_encoder_ESP32_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/IN2' */
  arduino_motor_encoder_ESP32_DW.obj_j.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_ESP32_DW.obj_j.isInitialized = 1;
  digitalIOSetup(2, 1);
  arduino_motor_encoder_ESP32_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/ENA1' */
  arduino_motor_encoder_ESP32_DW.obj_g.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_ESP32_DW.obj_g.isInitialized = 1;
  arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (4U, 0.0, 0.0);
  arduino_motor_encoder_ESP32_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Encoder' */
  arduino_motor_encoder_ESP32_DW.obj.Index = 0U;
  arduino_motor_encoder_ESP32_DW.obj.matlabCodegenIsDeleted = false;
  arduino_motor_encoder_ESP32_DW.obj.SampleTime =
    arduino_motor_encoder_ESP32_P.Encoder_SampleTime;
  arduino_motor_encoder_ESP32_DW.obj.isInitialized = 1;
  MW_EncoderSetup(12U, 13U, &arduino_motor_encoder_ESP32_DW.obj.Index);
  arduino_motor_encoder_ESP32_DW.obj.isSetupComplete = true;
  arduino_motor_encoder_ESP32_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
  MW_EncoderReset(arduino_motor_encoder_ESP32_DW.obj.Index);
}

/* Model terminate function */
void arduino_motor_encoder_ESP32_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/IN1' */
  if (!arduino_motor_encoder_ESP32_DW.obj_m.matlabCodegenIsDeleted) {
    arduino_motor_encoder_ESP32_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN1' */

  /* Terminate for MATLABSystem: '<S2>/IN2' */
  if (!arduino_motor_encoder_ESP32_DW.obj_j.matlabCodegenIsDeleted) {
    arduino_motor_encoder_ESP32_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2' */

  /* Terminate for MATLABSystem: '<S2>/ENA1' */
  if (!arduino_motor_encoder_ESP32_DW.obj_g.matlabCodegenIsDeleted) {
    arduino_motor_encoder_ESP32_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_ESP32_DW.obj_g.isInitialized == 1) &&
        arduino_motor_encoder_ESP32_DW.obj_g.isSetupComplete) {
      arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4U);
      MW_PWM_SetDutyCycle
        (arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4U);
      MW_PWM_Close
        (arduino_motor_encoder_ESP32_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ENA1' */

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!arduino_motor_encoder_ESP32_DW.obj.matlabCodegenIsDeleted) {
    arduino_motor_encoder_ESP32_DW.obj.matlabCodegenIsDeleted = true;
    if ((arduino_motor_encoder_ESP32_DW.obj.isInitialized == 1) &&
        arduino_motor_encoder_ESP32_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
