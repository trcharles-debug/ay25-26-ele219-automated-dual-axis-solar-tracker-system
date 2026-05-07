

        /*
    * Tracker_with_Position_Control.h
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


    #ifndef Tracker_with_Position_Control_h_
    #define Tracker_with_Position_Control_h_



                    #ifndef Tracker_with_Position_Control_COMMON_INCLUDES_
            #define Tracker_with_Position_Control_COMMON_INCLUDES_
                #include "rtwtypes.h"
        #include "rtw_extmode.h"
        #include "sysran_types.h"
        #include "rtw_continuous.h"
        #include "rtw_solver.h"
            #include "MW_ArduinoEncoder.h"

            #include "MW_PWM.h"

            #include "MW_arduino_digitalio.h"


            #endif /* Tracker_with_Position_Control_COMMON_INCLUDES_ */



#include "Tracker_with_Position_Control_types.h"

#include "multiword_types.h"

#include <math.h>

#include <string.h>

#include "rt_nonfinite.h"
    #include "MW_target_hardware_resources.h"


    

    

    

    
            /* Macros for accessing real-time model data structure */
                    #ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm) ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm) ((rtm)->extModeInfo)
#endif




        #ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx) ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm) ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm) (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm) ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm) ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm) (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx) ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif


    



                    #define Tracker_with_Position_Control_M (Tracker_with_Position_Contro_M)




    

    

    

    

                    /* Block signals (default storage) */
        
        typedef struct  {
        




                    
                    


                        




                                       int128m_T r; 

                        
                        
                        


                    






                    
                    


                        




                                       int128m_T r1; 

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       int64m_T Gain; /* '<S5>/Gain' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Constant; /* '<Root>/Constant' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Sum; /* '<Root>/Sum' */

                        
                        
                        


                    




        } B_Tracker_with_Position_Contr_T;

                /* Block states (default storage) for system '<Root>' */

        
        typedef struct  {
        




                    
                    


                        



                            
                            

                                       codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       codertarget_arduinobase_int_j_T obj_g; /* '<S4>/ENA1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       codertarget_arduinobase_block_T obj_d; /* '<S4>/IN2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       codertarget_arduinobase_block_T obj_e; /* '<S4>/IN1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Integrator_DSTATE; /* '<S41>/Integrator' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Filter_DSTATE; /* '<S36>/Filter' */

                        
                        
                        


                    






                    
                    


                        
                                    
                            
        struct {
                    void *LoggedData[3];
        } Scope_PWORK; /* '<Root>/Scope' */
    

            



                    






                    
                    


                        



                            
                            

                                       boolean_T objisempty; /* '<S4>/IN2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       boolean_T objisempty_j; /* '<S4>/IN1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       boolean_T objisempty_a; /* '<S4>/ENA1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       boolean_T objisempty_i; /* '<S3>/Encoder' */

                        
                        
                        


                    




        } DW_Tracker_with_Position_Cont_T;




                        /* Parameters (default storage) */
                struct P_Tracker_with_Position_Contr_T_ {
                    




                    
                    


                        



                            
                            

                                       real_T PIDController_D; /* Mask Parameter: PIDController_D
  * Referenced by: '<S34>/Derivative Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T PIDController_I; /* Mask Parameter: PIDController_I
  * Referenced by: '<S38>/Integral Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T PIDController_InitialConditionF; /* Mask Parameter: PIDController_InitialConditionF
  * Referenced by: '<S36>/Filter'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T PIDController_InitialConditio_f; /* Mask Parameter: PIDController_InitialConditio_f
  * Referenced by: '<S41>/Integrator'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T PIDController_N; /* Mask Parameter: PIDController_N
  * Referenced by: '<S44>/Filter Coefficient'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T PIDController_P; /* Mask Parameter: PIDController_P
  * Referenced by: '<S46>/Proportional Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Constant2_Value; /* Expression: 0
  * Referenced by: '<S4>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Constant1_Value; /* Expression: 1
  * Referenced by: '<S4>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Constant5_Value; /* Expression: 1
  * Referenced by: '<S4>/Constant5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Constant4_Value; /* Expression: 0
  * Referenced by: '<S4>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Constant_Value; /* Expression: 90
  * Referenced by: '<Root>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Integrator_gainval; /* Computed Parameter: Integrator_gainval
  * Referenced by: '<S41>/Integrator'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Filter_gainval; /* Computed Parameter: Filter_gainval
  * Referenced by: '<S36>/Filter'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Gain_Gain; /* Expression: 255
  * Referenced by: '<Root>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Saturation_UpperSat; /* Expression: 255
  * Referenced by: '<Root>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Saturation_LowerSat; /* Expression: -255
  * Referenced by: '<Root>/Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       real_T Switch_Threshold; /* Expression: 0
  * Referenced by: '<S4>/Switch'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       int64m_T Gain_Gain_j; /* Computed Parameter: Gain_Gain_j
  * Referenced by: '<S5>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            

                                       int32_T Gear_Ratio_Gain; /* Computed Parameter: Gear_Ratio_Gain
  * Referenced by: '<S3>/Gear_Ratio'
   */

                        
                        
                        


                    




                };

        


            /* Real-time Model Data Structure */
                        
    struct tag_RTM_Tracker_with_Position_T {
                    const char_T *errorStatus;
                    RTWExtModeInfo *extModeInfo;

                        /*
        * Sizes:
                * The following substructure contains sizes information
        * for many of the model attributes such as inputs, outputs,
        * dwork, sample times, etc.
         */
 
    struct  {
                    uint32_T checksums[4];
            


    } Sizes;

                        /*
        * SpecialInfo:
                * The following substructure contains special information
        * related to other components that are dependent on RTW.
         */
 
    struct  {
                    const void *mappingInfo;



    } SpecialInfo;

                        /*
        * Timing:
                * The following substructure contains information regarding
        * the timing information for the model.
         */
 
    struct  {
                    time_T taskTime0;
                    uint32_T clockTick0;
                    uint32_T clockTickH0;
                    time_T stepSize0;
                    uint32_T clockTick1;
                    uint32_T clockTickH1;
                        struct {
        uint8_T TID[2];
    }  TaskCounters;
        time_T tFinal;
                    boolean_T stopRequestedFlag;
            


    } Timing;



            
    };





    

    

    
            /* Block parameters (default storage) */
                        extern                 P_Tracker_with_Position_Contr_T Tracker_with_Position_Control_P;





            /* Block signals (default storage) */
                        extern                 B_Tracker_with_Position_Contr_T Tracker_with_Position_Control_B;





                /* Block states (default storage) */
                        extern                 DW_Tracker_with_Position_Cont_T Tracker_with_Position_Contro_DW;






            /* External function called from main */

            extern void Tracker_with_Position_Control_SetEventsForThisBaseStep(boolean_T *eventFlags);


        
            /* Model entry point functions */
                                        extern void Tracker_with_Position_Control_initialize(void);
                                                                                                            extern void Tracker_with_Position_Control_step0(void); /* Sample time: [0.005s, 0.0s] */
                                                                                                            extern void Tracker_with_Position_Control_step1(void); /* Sample time: [0.01s, 0.0s] */
                            




                                        extern void Tracker_with_Position_Control_terminate(void);
                        



    

    
                    /* Real-time Model object */

                                extern                         RT_MODEL_Tracker_with_Positio_T *const Tracker_with_Position_Contro_M;





    extern volatile boolean_T stopRequested;
    extern volatile boolean_T runModel;


    

    

    

        
            /*-
            * These blocks were eliminated from the model due to optimizations:
            *
                    * Block '<S6>/Data Type Duplicate' : Unused code path elimination
                    * Block '<S6>/Diff' : Unused code path elimination
                    * Block '<S6>/TSamp' : Unused code path elimination
                    * Block '<S6>/UD' : Unused code path elimination
                    * Block '<S1>/rad//s To RPM' : Unused code path elimination
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
            * '<Root>' : 'Tracker_with_Position_Control'
                * '<S1>'   : 'Tracker_with_Position_Control/Azimuth Motor'
                * '<S2>'   : 'Tracker_with_Position_Control/PID Controller'
                * '<S3>'   : 'Tracker_with_Position_Control/Azimuth Motor/Azimut Encoder'
                * '<S4>'   : 'Tracker_with_Position_Control/Azimuth Motor/Azimut Motor'
                * '<S5>'   : 'Tracker_with_Position_Control/Azimuth Motor/Radians to Degrees'
                * '<S6>'   : 'Tracker_with_Position_Control/Azimuth Motor/Azimut Encoder/Discrete Derivative'
                * '<S7>'   : 'Tracker_with_Position_Control/PID Controller/Anti-windup'
                * '<S8>'   : 'Tracker_with_Position_Control/PID Controller/D Gain'
                * '<S9>'   : 'Tracker_with_Position_Control/PID Controller/External Derivative'
                * '<S10>'  : 'Tracker_with_Position_Control/PID Controller/Filter'
                * '<S11>'  : 'Tracker_with_Position_Control/PID Controller/Filter ICs'
                * '<S12>'  : 'Tracker_with_Position_Control/PID Controller/I Gain'
                * '<S13>'  : 'Tracker_with_Position_Control/PID Controller/Ideal P Gain'
                * '<S14>'  : 'Tracker_with_Position_Control/PID Controller/Ideal P Gain Fdbk'
                * '<S15>'  : 'Tracker_with_Position_Control/PID Controller/Integrator'
                * '<S16>'  : 'Tracker_with_Position_Control/PID Controller/Integrator ICs'
                * '<S17>'  : 'Tracker_with_Position_Control/PID Controller/N Copy'
                * '<S18>'  : 'Tracker_with_Position_Control/PID Controller/N Gain'
                * '<S19>'  : 'Tracker_with_Position_Control/PID Controller/P Copy'
                * '<S20>'  : 'Tracker_with_Position_Control/PID Controller/Parallel P Gain'
                * '<S21>'  : 'Tracker_with_Position_Control/PID Controller/Reset Signal'
                * '<S22>'  : 'Tracker_with_Position_Control/PID Controller/Saturation'
                * '<S23>'  : 'Tracker_with_Position_Control/PID Controller/Saturation Fdbk'
                * '<S24>'  : 'Tracker_with_Position_Control/PID Controller/Sum'
                * '<S25>'  : 'Tracker_with_Position_Control/PID Controller/Sum Fdbk'
                * '<S26>'  : 'Tracker_with_Position_Control/PID Controller/Tracking Mode'
                * '<S27>'  : 'Tracker_with_Position_Control/PID Controller/Tracking Mode Sum'
                * '<S28>'  : 'Tracker_with_Position_Control/PID Controller/Tsamp - Integral'
                * '<S29>'  : 'Tracker_with_Position_Control/PID Controller/Tsamp - Ngain'
                * '<S30>'  : 'Tracker_with_Position_Control/PID Controller/postSat Signal'
                * '<S31>'  : 'Tracker_with_Position_Control/PID Controller/preInt Signal'
                * '<S32>'  : 'Tracker_with_Position_Control/PID Controller/preSat Signal'
                * '<S33>'  : 'Tracker_with_Position_Control/PID Controller/Anti-windup/Passthrough'
                * '<S34>'  : 'Tracker_with_Position_Control/PID Controller/D Gain/Internal Parameters'
                * '<S35>'  : 'Tracker_with_Position_Control/PID Controller/External Derivative/Error'
                * '<S36>'  : 'Tracker_with_Position_Control/PID Controller/Filter/Disc. Forward Euler Filter'
                * '<S37>'  : 'Tracker_with_Position_Control/PID Controller/Filter ICs/Internal IC - Filter'
                * '<S38>'  : 'Tracker_with_Position_Control/PID Controller/I Gain/Internal Parameters'
                * '<S39>'  : 'Tracker_with_Position_Control/PID Controller/Ideal P Gain/Passthrough'
                * '<S40>'  : 'Tracker_with_Position_Control/PID Controller/Ideal P Gain Fdbk/Disabled'
                * '<S41>'  : 'Tracker_with_Position_Control/PID Controller/Integrator/Discrete'
                * '<S42>'  : 'Tracker_with_Position_Control/PID Controller/Integrator ICs/Internal IC'
                * '<S43>'  : 'Tracker_with_Position_Control/PID Controller/N Copy/Disabled'
                * '<S44>'  : 'Tracker_with_Position_Control/PID Controller/N Gain/Internal Parameters'
                * '<S45>'  : 'Tracker_with_Position_Control/PID Controller/P Copy/Disabled'
                * '<S46>'  : 'Tracker_with_Position_Control/PID Controller/Parallel P Gain/Internal Parameters'
                * '<S47>'  : 'Tracker_with_Position_Control/PID Controller/Reset Signal/Disabled'
                * '<S48>'  : 'Tracker_with_Position_Control/PID Controller/Saturation/Passthrough'
                * '<S49>'  : 'Tracker_with_Position_Control/PID Controller/Saturation Fdbk/Disabled'
                * '<S50>'  : 'Tracker_with_Position_Control/PID Controller/Sum/Sum_PID'
                * '<S51>'  : 'Tracker_with_Position_Control/PID Controller/Sum Fdbk/Disabled'
                * '<S52>'  : 'Tracker_with_Position_Control/PID Controller/Tracking Mode/Disabled'
                * '<S53>'  : 'Tracker_with_Position_Control/PID Controller/Tracking Mode Sum/Passthrough'
                * '<S54>'  : 'Tracker_with_Position_Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
                * '<S55>'  : 'Tracker_with_Position_Control/PID Controller/Tsamp - Ngain/Passthrough'
                * '<S56>'  : 'Tracker_with_Position_Control/PID Controller/postSat Signal/Forward_Path'
                * '<S57>'  : 'Tracker_with_Position_Control/PID Controller/preInt Signal/Internal PreInt'
                * '<S58>'  : 'Tracker_with_Position_Control/PID Controller/preSat Signal/Forward_Path'
    */


    

    #endif /* Tracker_with_Position_Control_h_ */
