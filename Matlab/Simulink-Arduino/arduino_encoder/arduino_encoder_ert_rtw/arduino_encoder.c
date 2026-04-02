/*
 * arduino_encoder.c
 *
 * Code generation for model "arduino_encoder".
 *
 * Model version              : 1.5
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Mar 21 10:03:27 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_encoder.h"
#include "rtwtypes.h"
#include "arduino_encoder_private.h"
#include <string.h>

/* Block signals (default storage) */
B_arduino_encoder_T arduino_encoder_B;

/* Block states (default storage) */
DW_arduino_encoder_T arduino_encoder_DW;

/* Real-time model */
static RT_MODEL_arduino_encoder_T arduino_encoder_M_;
RT_MODEL_arduino_encoder_T *const arduino_encoder_M = &arduino_encoder_M_;

/* Model step function */
void arduino_encoder_step(void)
{
  uint32_T rtb_Tachometer1_0;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  arduino_encoder_B.DiscreteTimeIntegrator =
    arduino_encoder_DW.DiscreteTimeIntegrator_DSTATE;

  /* MATLABSystem: '<S1>/Tachometer1' */
  rtb_Tachometer1_0 = MW_Tachometer_GetSpeed(64.0);

  /* MATLABSystem: '<S1>/Tachometer' */
  MW_Tachometer_GetSpeed(67.0);

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  MATLABSystem: '<S1>/Tachometer1'
   */
  arduino_encoder_DW.DiscreteTimeIntegrator_DSTATE += rtb_Tachometer1_0;

  {                                    /* Sample time: [0.5s, 0.0s] */
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
  if (!(++arduino_encoder_M->Timing.clockTick0)) {
    ++arduino_encoder_M->Timing.clockTickH0;
  }

  arduino_encoder_M->Timing.taskTime0 = arduino_encoder_M->Timing.clockTick0 *
    arduino_encoder_M->Timing.stepSize0 + arduino_encoder_M->Timing.clockTickH0 *
    arduino_encoder_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void arduino_encoder_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)arduino_encoder_M, 0,
                sizeof(RT_MODEL_arduino_encoder_T));
  rtmSetTFinal(arduino_encoder_M, -1);
  arduino_encoder_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  arduino_encoder_M->Sizes.checksums[0] = (2517616212U);
  arduino_encoder_M->Sizes.checksums[1] = (3944069335U);
  arduino_encoder_M->Sizes.checksums[2] = (964556311U);
  arduino_encoder_M->Sizes.checksums[3] = (559590894U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    arduino_encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_encoder_M->extModeInfo,
      &arduino_encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_encoder_M->extModeInfo,
                        arduino_encoder_M->Sizes.checksums);
    rteiSetTPtr(arduino_encoder_M->extModeInfo, rtmGetTPtr(arduino_encoder_M));
  }

  /* block I/O */
  (void) memset(((void *) &arduino_encoder_B), 0,
                sizeof(B_arduino_encoder_T));

  /* states (dwork) */
  (void) memset((void *)&arduino_encoder_DW, 0,
                sizeof(DW_arduino_encoder_T));

  /* Start for MATLABSystem: '<S1>/Tachometer1' */
  arduino_encoder_DW.obj.matlabCodegenIsDeleted = false;
  arduino_encoder_DW.objisempty = true;
  arduino_encoder_DW.obj.isInitialized = 1;
  MW_Tachometer_Init(11, 0);
  arduino_encoder_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/Tachometer' */
  arduino_encoder_DW.obj_i.matlabCodegenIsDeleted = false;
  arduino_encoder_DW.objisempty_b = true;
  arduino_encoder_DW.obj_i.isInitialized = 1;
  MW_Tachometer_Init(10, 0);
  arduino_encoder_DW.obj_i.isSetupComplete = true;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  arduino_encoder_DW.DiscreteTimeIntegrator_DSTATE =
    arduino_encoder_P.DiscreteTimeIntegrator_IC;
}

/* Model terminate function */
void arduino_encoder_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Tachometer1' */
  if (!arduino_encoder_DW.obj.matlabCodegenIsDeleted) {
    arduino_encoder_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Tachometer1' */

  /* Terminate for MATLABSystem: '<S1>/Tachometer' */
  if (!arduino_encoder_DW.obj_i.matlabCodegenIsDeleted) {
    arduino_encoder_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Tachometer' */
}
