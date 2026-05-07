/*
 * File: arduino_encoder.c
 *
 * Code generated for Simulink model 'arduino_encoder'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed May  6 01:24:42 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_encoder.h"
#include "arduino_encoder_private.h"

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
  /* MATLABSystem: '<Root>/Encoder' */
  if (arduino_encoder_DW.obj.TunablePropsChanged) {
    arduino_encoder_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder' */
  MW_EncoderRead(arduino_encoder_DW.obj.Index, &arduino_encoder_B.Encoder);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  arduino_encoder_M->Timing.taskTime0 =
    ((time_T)(++arduino_encoder_M->Timing.clockTick0)) *
    arduino_encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void arduino_encoder_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(arduino_encoder_M, -1);
  arduino_encoder_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  arduino_encoder_M->Sizes.checksums[0] = (1048465822U);
  arduino_encoder_M->Sizes.checksums[1] = (1674068102U);
  arduino_encoder_M->Sizes.checksums[2] = (401266174U);
  arduino_encoder_M->Sizes.checksums[3] = (1594542694U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    arduino_encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_encoder_M->extModeInfo,
      &arduino_encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_encoder_M->extModeInfo,
                        arduino_encoder_M->Sizes.checksums);
    rteiSetTPtr(arduino_encoder_M->extModeInfo, rtmGetTPtr(arduino_encoder_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder' */
  arduino_encoder_DW.obj.Index = 0U;
  arduino_encoder_DW.obj.matlabCodegenIsDeleted = false;
  arduino_encoder_DW.obj.isInitialized = 1;
  MW_EncoderSetup(5U, 4U, &arduino_encoder_DW.obj.Index);
  arduino_encoder_DW.obj.isSetupComplete = true;
  arduino_encoder_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(arduino_encoder_DW.obj.Index);
}

/* Model terminate function */
void arduino_encoder_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!arduino_encoder_DW.obj.matlabCodegenIsDeleted) {
    arduino_encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((arduino_encoder_DW.obj.isInitialized == 1) &&
        arduino_encoder_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
