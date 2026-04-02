/*
 * arduino_tcpip_receive.h
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

#ifndef RTW_HEADER_arduino_tcpip_receive_h_
#define RTW_HEADER_arduino_tcpip_receive_h_
#ifndef arduino_tcpip_receive_COMMON_INCLUDES_
#define arduino_tcpip_receive_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_WiFiTCP.h"
#endif                              /* arduino_tcpip_receive_COMMON_INCLUDES_ */

#include "arduino_tcpip_receive_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_j;/* '<Root>/WiFi TCP//IP Receive' */
  boolean_T objisempty;                /* '<Root>/WiFi TCP//IP Receive' */
  boolean_T objisempty_b;              /* '<Root>/Digital Output' */
} DW_arduino_tcpip_receive_T;

/* Real-time Model Data Structure */
struct tag_RTM_arduino_tcpip_receive_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_arduino_tcpip_receive_T arduino_tcpip_receive_DW;

/* Model entry point functions */
extern void arduino_tcpip_receive_initialize(void);
extern void arduino_tcpip_receive_step(void);
extern void arduino_tcpip_receive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduino_tcpip_receiv_T *const arduino_tcpip_receive_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'arduino_tcpip_receive'
 */
#endif                                 /* RTW_HEADER_arduino_tcpip_receive_h_ */
