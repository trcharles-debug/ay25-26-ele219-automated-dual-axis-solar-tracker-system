

        /*
    * Tracker_with_Position_Control_data.c
    *
        * Code generation for model "Tracker_with_Position_Control".
    *
    * Model version              : 3.0
    * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
        * C source code generated on : Tue May  5 22:49:03 2026
 * 
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
    */




    
#include "Tracker_with_Position_Control.h"


    

    

    

    

    

    

    

    

    

    

            /* Block parameters (default storage) */
                                             P_Tracker_with_Position_Contr_T Tracker_with_Position_Control_P = {
                    

                        /* Mask Parameter: PIDController_D
  * Referenced by: '<S34>/Derivative Gain'
   */
          0.0             , 



                        /* Mask Parameter: PIDController_I
  * Referenced by: '<S38>/Integral Gain'
   */
          0.001             , 



                        /* Mask Parameter: PIDController_InitialConditionF
  * Referenced by: '<S36>/Filter'
   */
          0.0             , 



                        /* Mask Parameter: PIDController_InitialConditio_f
  * Referenced by: '<S41>/Integrator'
   */
          0.0             , 



                        /* Mask Parameter: PIDController_N
  * Referenced by: '<S44>/Filter Coefficient'
   */
          100.0             , 



                        /* Mask Parameter: PIDController_P
  * Referenced by: '<S46>/Proportional Gain'
   */
          0.01             , 



                        /* Expression: 0
  * Referenced by: '<S4>/Constant2'
   */
          0.0             , 



                        /* Expression: 1
  * Referenced by: '<S4>/Constant1'
   */
          1.0             , 



                        /* Expression: 1
  * Referenced by: '<S4>/Constant5'
   */
          1.0             , 



                        /* Expression: 0
  * Referenced by: '<S4>/Constant4'
   */
          0.0             , 



                        /* Expression: 90
  * Referenced by: '<Root>/Constant'
   */
          90.0             , 



                        /* Computed Parameter: Integrator_gainval
  * Referenced by: '<S41>/Integrator'
   */
          0.01             , 



                        /* Computed Parameter: Filter_gainval
  * Referenced by: '<S36>/Filter'
   */
          0.01             , 



                        /* Expression: 255
  * Referenced by: '<Root>/Gain'
   */
          255.0             , 



                        /* Expression: 255
  * Referenced by: '<Root>/Saturation'
   */
          255.0             , 



                        /* Expression: -255
  * Referenced by: '<Root>/Saturation'
   */
          -255.0             , 



                        /* Expression: 0
  * Referenced by: '<S4>/Switch'
   */
          0.0             , 



                        /* Computed Parameter: Gain_Gain_j
  * Referenced by: '<S5>/Gain'
   */
          { { 0x70698F08UL, 0x7297UL } }             , 



                        /* Computed Parameter: Gear_Ratio_Gain
  * Referenced by: '<S3>/Gear_Ratio'
   */
          1277447357 




                };


        
    



    

    

    

    

    

    

    

    

    
