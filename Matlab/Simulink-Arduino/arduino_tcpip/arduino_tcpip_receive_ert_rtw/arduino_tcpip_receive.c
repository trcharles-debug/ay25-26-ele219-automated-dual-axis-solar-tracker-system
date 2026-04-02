/*
 * arduino_tcpip_receive.c
 *
 * Code generation for model "arduino_tcpip_receive".
 *
 * Model version              : 1.31
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Mar 21 14:16:37 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_tcpip_receive.h"
#include "arduino_tcpip_receive_types.h"
#include "rtwtypes.h"
#include <string.h>

/* Block states (default storage) */
DW_arduino_tcpip_receive_T arduino_tcpip_receive_DW;

/* Real-time model */
static RT_MODEL_arduino_tcpip_receiv_T arduino_tcpip_receive_M_;
RT_MODEL_arduino_tcpip_receiv_T *const arduino_tcpip_receive_M =
  &arduino_tcpip_receive_M_;

/* Forward declaration for local functions */
static void arduino_tcpip__SystemCore_setup(codertarget_arduinobase_inter_T *obj);
static void arduino_tcpip__SystemCore_setup(codertarget_arduinobase_inter_T *obj)
{
  obj->isInitialized = 1;
  obj->isServer_ = 1.0;
  MW_WifiAndWifiTCPServerBegin(0, 25000.0, obj->isServer_, 192, 168, 1, 2);
  obj->TunablePropsChanged = false;
}

/* Model step function */
void arduino_tcpip_receive_step(void)
{
  int32_T b_varargout_2;
  uint8_T b_varargout_1;

  /* MATLABSystem: '<Root>/WiFi TCP//IP Receive' */
  if (arduino_tcpip_receive_DW.obj_j.TunablePropsChanged) {
    arduino_tcpip_receive_DW.obj_j.TunablePropsChanged = false;
  }

  MW_WifiTCPFinalread(0, &b_varargout_1, 1, &b_varargout_2,
                      arduino_tcpip_receive_DW.obj_j.isServer_, 0U);

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  MATLABSystem: '<Root>/WiFi TCP//IP Receive'
   */
  writeDigitalPin(12, b_varargout_1);
}

/* Model initialize function */
void arduino_tcpip_receive_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arduino_tcpip_receive_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&arduino_tcpip_receive_DW, 0,
                sizeof(DW_arduino_tcpip_receive_T));

  /* Start for MATLABSystem: '<Root>/WiFi TCP//IP Receive' */
  arduino_tcpip_receive_DW.obj_j.isInitialized = 0;
  arduino_tcpip_receive_DW.objisempty = true;
  arduino_tcpip__SystemCore_setup(&arduino_tcpip_receive_DW.obj_j);

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  arduino_tcpip_receive_DW.obj.matlabCodegenIsDeleted = false;
  arduino_tcpip_receive_DW.objisempty_b = true;
  arduino_tcpip_receive_DW.obj.isInitialized = 1;
  digitalIOSetup(12, 1);
  arduino_tcpip_receive_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void arduino_tcpip_receive_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!arduino_tcpip_receive_DW.obj.matlabCodegenIsDeleted) {
    arduino_tcpip_receive_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}
