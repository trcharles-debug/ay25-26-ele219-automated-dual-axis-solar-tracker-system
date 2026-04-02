#include "arduino_tcpip_receive.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  arduino_tcpip_receive_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.1;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_usbattach();
  MW_Arduino_Init();
  rtmSetErrorStatus(arduino_tcpip_receive_M, 0);
  arduino_tcpip_receive_initialize();
  noInterrupts();
  configureArduinoARM_M0plusTimer();
  runModel = rtmGetErrorStatus(arduino_tcpip_receive_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(arduino_tcpip_receive_M) == (NULL));
    MW_Arduino_Loop();
  }

  /* Terminate model */
  arduino_tcpip_receive_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}
