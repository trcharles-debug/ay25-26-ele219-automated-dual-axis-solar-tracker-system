/*
 * arduino_encoder_inc.c
 *
 * Code generation for model "arduino_encoder_inc".
 *
 * Model version              : 1.54
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Fri Mar 22 20:00:54 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_encoder_inc.h"
#include "rtwtypes.h"
#include "arduino_encoder_inc_private.h"
#include <string.h>

/* Block signals (default storage) */
B_arduino_encoder_inc_T arduino_encoder_inc_B;

/* Block states (default storage) */
DW_arduino_encoder_inc_T arduino_encoder_inc_DW;

/* Real-time model */
static RT_MODEL_arduino_encoder_inc_T arduino_encoder_inc_M_;
RT_MODEL_arduino_encoder_inc_T *const arduino_encoder_inc_M =
  &arduino_encoder_inc_M_;

/* Model step function */
void arduino_encoder_inc_step(void)
{
  int16_T idxDelay;
  boolean_T c_value;

  /* MATLABSystem: '<S1>/Digital Input' */
  if (arduino_encoder_inc_DW.obj.SampleTime !=
      arduino_encoder_inc_P.DigitalInput_SampleTime) {
    arduino_encoder_inc_DW.obj.SampleTime =
      arduino_encoder_inc_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(10);

  /* Sum: '<S1>/Add' incorporates:
   *  Delay: '<S1>/Delay'
   *  MATLABSystem: '<S1>/Digital Input'
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<S2>/Delay Input1'
   */
  arduino_encoder_inc_B.TotalPulses = (uint8_T)((uint16_T)((int16_T)c_value >
    (int16_T)arduino_encoder_inc_DW.DelayInput1_DSTATE) +
    arduino_encoder_inc_DW.Delay_DSTATE);

  /* Sum: '<S1>/Add1' incorporates:
   *  Delay: '<S1>/Delay1'
   */
  arduino_encoder_inc_B.Add1 = (uint8_T)(arduino_encoder_inc_B.TotalPulses -
    arduino_encoder_inc_DW.Delay1_DSTATE[0]);

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  arduino_encoder_inc_B.Pulsessec = (real_T)arduino_encoder_inc_B.Add1 /
    arduino_encoder_inc_P.Constant2_Value;

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant3'
   *  Product: '<S1>/Product'
   */
  arduino_encoder_inc_B.rpm = arduino_encoder_inc_B.Pulsessec *
    arduino_encoder_inc_P.Constant1_Value *
    arduino_encoder_inc_P.Constant3_Value;

  /* Update for UnitDelay: '<S2>/Delay Input1' incorporates:
   *  MATLABSystem: '<S1>/Digital Input'
   */
  arduino_encoder_inc_DW.DelayInput1_DSTATE = c_value;

  /* Update for Delay: '<S1>/Delay' */
  arduino_encoder_inc_DW.Delay_DSTATE = arduino_encoder_inc_B.TotalPulses;

  /* Update for Delay: '<S1>/Delay1' */
  for (idxDelay = 0; idxDelay < 99; idxDelay++) {
    arduino_encoder_inc_DW.Delay1_DSTATE[idxDelay] =
      arduino_encoder_inc_DW.Delay1_DSTATE[idxDelay + 1];
  }

  arduino_encoder_inc_DW.Delay1_DSTATE[99] = arduino_encoder_inc_B.TotalPulses;

  /* End of Update for Delay: '<S1>/Delay1' */
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
  if (!(++arduino_encoder_inc_M->Timing.clockTick0)) {
    ++arduino_encoder_inc_M->Timing.clockTickH0;
  }

  arduino_encoder_inc_M->Timing.taskTime0 =
    arduino_encoder_inc_M->Timing.clockTick0 *
    arduino_encoder_inc_M->Timing.stepSize0 +
    arduino_encoder_inc_M->Timing.clockTickH0 *
    arduino_encoder_inc_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void arduino_encoder_inc_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)arduino_encoder_inc_M, 0,
                sizeof(RT_MODEL_arduino_encoder_inc_T));
  rtmSetTFinal(arduino_encoder_inc_M, -1);
  arduino_encoder_inc_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  arduino_encoder_inc_M->Sizes.checksums[0] = (2244638148U);
  arduino_encoder_inc_M->Sizes.checksums[1] = (3774803472U);
  arduino_encoder_inc_M->Sizes.checksums[2] = (4075625405U);
  arduino_encoder_inc_M->Sizes.checksums[3] = (42867193U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    arduino_encoder_inc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(arduino_encoder_inc_M->extModeInfo,
      &arduino_encoder_inc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(arduino_encoder_inc_M->extModeInfo,
                        arduino_encoder_inc_M->Sizes.checksums);
    rteiSetTPtr(arduino_encoder_inc_M->extModeInfo, rtmGetTPtr
                (arduino_encoder_inc_M));
  }

  /* block I/O */
  (void) memset(((void *) &arduino_encoder_inc_B), 0,
                sizeof(B_arduino_encoder_inc_T));

  /* states (dwork) */
  (void) memset((void *)&arduino_encoder_inc_DW, 0,
                sizeof(DW_arduino_encoder_inc_T));

  /* Start for MATLABSystem: '<S1>/Digital Input' */
  arduino_encoder_inc_DW.obj.matlabCodegenIsDeleted = false;
  arduino_encoder_inc_DW.objisempty = true;
  arduino_encoder_inc_DW.obj.SampleTime =
    arduino_encoder_inc_P.DigitalInput_SampleTime;
  arduino_encoder_inc_DW.obj.isInitialized = 1L;
  digitalIOSetup(10, 0);
  arduino_encoder_inc_DW.obj.isSetupComplete = true;

  {
    int16_T i;

    /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
    arduino_encoder_inc_DW.DelayInput1_DSTATE =
      arduino_encoder_inc_P.DetectIncrease_vinit;

    /* InitializeConditions for Delay: '<S1>/Delay' */
    arduino_encoder_inc_DW.Delay_DSTATE =
      arduino_encoder_inc_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    for (i = 0; i < 100; i++) {
      arduino_encoder_inc_DW.Delay1_DSTATE[i] =
        arduino_encoder_inc_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S1>/Delay1' */
  }
}

/* Model terminate function */
void arduino_encoder_inc_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  if (!arduino_encoder_inc_DW.obj.matlabCodegenIsDeleted) {
    arduino_encoder_inc_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input' */
}
