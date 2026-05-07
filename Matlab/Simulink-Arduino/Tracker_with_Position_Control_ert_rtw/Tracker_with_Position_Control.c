

    

        /*
        * Tracker_with_Position_Control.c
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

#include "Tracker_with_Position_Control_private.h"

#include <math.h>

#include "rtwtypes.h"

#include "multiword_types.h"

#include <string.h>

#include "rt_nonfinite.h"


    

    

    

    

    

    

    

    

    

    

    
        /* Block signals (default storage) */
                                            B_Tracker_with_Position_Contr_T Tracker_with_Position_Control_B;


            
            /* Block states (default storage) */
                                            DW_Tracker_with_Position_Cont_T Tracker_with_Position_Contro_DW;


            
    




            
        
        
        
        
        
        

        

        


                /* Real-time model */
                        
                                static RT_MODEL_Tracker_with_Positio_T Tracker_with_Position_Contro_M_;


                            RT_MODEL_Tracker_with_Positio_T *const Tracker_with_Position_Contro_M = &Tracker_with_Position_Contro_M_;




    

    

    static void rate_monotonic_scheduler(void);

    

        
                         
void sMultiWord2sMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T n)
{
    uint32_T ys;
    int16_T i;
    int16_T nm1;
    boolean_T doSaturation = false;
    nm1 = n - 1;
    ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
    if (n1 > n) {
        doSaturation = (((u1[n1 - 1] ^ u1[n - 1]) & 2147483648UL) != 0UL);
        i = n1 - 1;
        while ((!doSaturation) && (i >= n)) {
            doSaturation = (u1[i] != ys);
            i--;
        }
    }
    if (doSaturation) {
        ys = ~ys;
        for (i = 0; i < nm1; i++) {
            y[i] = ys;
        }
        y[i] = ys ^ 2147483648UL;
    } else {
        nm1 = n1 < n ? n1 : n;
        for (i = 0; i < nm1; i++) {
            y[i] = u1[i];
        }
        while (i < n) {
            y[i] = ys;
            i++;
        }
    }
}
        
                 
void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[], int16_T n)
{
    uint32_T u1i;
    uint32_T yi;
    uint32_T ys;
    int16_T i;
    int16_T i1;
    int16_T nb;
    int16_T nc;
    uint16_T nr;
    nb = (int16_T)(n2 >> 5);
    i = 0;
    ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
    if (nb < n1) {
        nc = n + nb;
        if (nc > n1) {
            nc = n1;
        }
        nr = n2 - ((uint16_T)nb << 5);
        if (nr > 0U) {
            u1i = u1[nb];
            for (i1 = nb + 1; i1 < nc; i1++) {
                yi = u1i >> nr;
                u1i = u1[i1];
                y[i] = u1i << (32U - nr) | yi;
                i++;
            }
            y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
            i++;
        } else {
            for (i1 = nb; i1 < nc; i1++) {
                y[i] = u1[i1];
                i++;
            }
        }
    }
    while (i < n) {
        y[i] = ys;
        i++;
    }
}
        
                 
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T n2, uint32_T y[], int16_T n)
{
    uint32_T a0;
    uint32_T a1;
    uint32_T b1;
    uint32_T cb;
    uint32_T cb1;
    uint32_T cb2;
    uint32_T u1i;
    uint32_T w01;
    uint32_T w10;
    uint32_T yk;
    int16_T i;
    int16_T j;
    int16_T k;
    int16_T ni;
    boolean_T isNegative1;
    boolean_T isNegative2;
    isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
    isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
    cb1 = 1UL;
    /* Initialize output to zero */
    for (k = 0; k < n; k++) {
        y[k] = 0UL;
    }
    for (i = 0; i < n1; i++) {
        cb = 0UL;
        u1i = u1[i];
        if (isNegative1) {
            u1i = ~u1i + cb1;
            cb1 = (uint32_T)(u1i < cb1);
        }
        a1 = u1i >> 16U;
        a0 = u1i & 65535UL;
        cb2 = 1UL;
        ni = n - i;
        ni = n2 <= ni ? n2 : ni;
        k = i;
        for (j = 0; j < ni; j++) {
            u1i = u2[j];
            if (isNegative2) {
                u1i = ~u1i + cb2;
                cb2 = (uint32_T)(u1i < cb2);
            }
            b1 = u1i >> 16U;
            u1i &= 65535UL;
            w10 = a1 * u1i;
            w01 = a0 * b1;
            yk = y[k] + cb;
            cb = (uint32_T)(yk < cb);
            u1i *= a0;
            yk += u1i;
            cb += (uint32_T)(yk < u1i);
            u1i = w10 << 16U;
            yk += u1i;
            cb += (uint32_T)(yk < u1i);
            u1i = w01 << 16U;
            yk += u1i;
            cb += (uint32_T)(yk < u1i);
            y[k] = yk;
            cb += w10 >> 16U;
            cb += w01 >> 16U;
            cb += a1 * b1;
            k++;
        }
        if (k < n) {
            y[k] = cb;
        }
    }
    /* Apply sign */
    if (isNegative1 != isNegative2) {
        cb = 1UL;
        for (k = 0; k < n; k++) {
            yk = ~y[k] + cb;
            y[k] = yk;
            cb = (uint32_T)(yk < cb);
        }
    }
}
        
                 
real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
    real_T y;
    uint32_T cb;
    uint32_T u1i;
    int16_T exp_0;
    int16_T i;
    y = 0.0;
    exp_0 = e1;
    if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
        cb = 1UL;
        for (i = 0; i < n1; i++) {
            u1i = ~u1[i];
            cb += u1i;
            y -= ldexp(cb, exp_0);
            cb = (uint32_T)(cb < u1i);
            exp_0 += 32;
        }
    } else {
        for (i = 0; i < n1; i++) {
            y += ldexp(u1[i], exp_0);
            exp_0 += 32;
        }
    }
    return y;
}
        
                    


        /* 
 * Set which subrates need to run this base step (base rate always runs). 
 * This function must be called prior to calling the model step function 
 * in order to remember which rates need to run this base step.  The 
 * buffering of events allows for overlapping preemption.
 */

                void Tracker_with_Position_Control_SetEventsForThisBaseStep(boolean_T *eventFlags)
        {
            /* Task runs when its counter is zero, computed via rtmStepTask macro */
                eventFlags[1] = ((boolean_T)rtmStepTask(Tracker_with_Position_Contro_M, 1));
        }
        

        
        




        /* 
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */

                static void rate_monotonic_scheduler(void)
        {
                

    
    /* Compute which subrates run during the next base time step.  Subrates
    * are an integer multiple of the base rate counter.  Therefore, the subtask
    * counter is reset when it reaches its limit (zero means run).
    */
    
            (Tracker_with_Position_Contro_M->Timing.TaskCounters.TID[1])++;
            if ((Tracker_with_Position_Contro_M->Timing.TaskCounters.TID[1]) > 1) { /* Sample time: [0.01s, 0.0s] */
            Tracker_with_Position_Contro_M->Timing.TaskCounters.TID[1] = 0;
        }

        }
        

    

                
        
        
        
        
        

    

                        

                

         

                
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
            

                



        









                    




        /* Model step function for TID0 */
        
                    
        void Tracker_with_Position_Control_step0(void) /* Sample time: [0.005s, 0.0s] */
        {
            


        

                
        
            
            

        

        




                
            

        
                    { /* Sample time: [0.005s, 0.0s] */
                rate_monotonic_scheduler();
            }


    



        




                                                



                




                    



        
                                /* Update absolute time */
                        /* The "clockTick0" counts the number of times the code of this task has
        * been executed. The absolute time is the multiplication of "clockTick0"
        * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
        * overflow during the application lifespan selected.
            * Timer of this task consists of two 32 bit unsigned integers.
            * The two integers represent the low bits Timing.clockTick0 and the high bits
            * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
        */

        if(!(++Tracker_with_Position_Contro_M->Timing.clockTick0)) {
 ++Tracker_with_Position_Contro_M->Timing.clockTickH0; 
} Tracker_with_Position_Contro_M->Timing.taskTime0 = Tracker_with_Position_Contro_M->Timing.clockTick0 * Tracker_with_Position_Contro_M->Timing.stepSize0 + Tracker_with_Position_Contro_M->Timing.clockTickH0 * Tracker_with_Position_Contro_M->Timing.stepSize0 * 4294967296.0;


                    








                        

            

        
        



                            



                    } 
        
            







                    




        /* Model step function for TID1 */
        
                    
        void Tracker_with_Position_Control_step1(void) /* Sample time: [0.01s, 0.0s] */
        {
            


        

                
        
            
int64m_T tmp;
real_T rtb_FilterCoefficient;
real_T rtb_Saturation;
real_T rtb_Switch_idx_0;
real_T rtb_Switch_idx_1;
int32_T rtb_Encoder_0;
uint32_T tmp_0;
uint32_T tmp_1;
uint8_T tmp_2;

            

        

        




                
        




                                                    
                                    /* {S!d1882}Gain: '<S5>/Gain' */
Tracker_with_Position_Control_B.Gain = Tracker_with_Position_Control_P.Gain_Gain_j;
/* {S!d1884}Constant: '<Root>/Constant' */
Tracker_with_Position_Control_B.Constant = Tracker_with_Position_Control_P.Constant_Value;
/* {S!d1886}MATLABSystem: '<S3>/Encoder' */
if (Tracker_with_Position_Contro_DW.obj.TunablePropsChanged) {
    Tracker_with_Position_Contro_DW.obj.TunablePropsChanged = false;
}
MW_EncoderRead(Tracker_with_Position_Contro_DW.obj.Index, &rtb_Encoder_0);
/* {S!d1888}Gain: '<S3>/Gear_Ratio' incorporates:
 *  MATLABSystem: '<S3>/Encoder'
 */
tmp_0 = (uint32_T)Tracker_with_Position_Control_P.Gear_Ratio_Gain;
tmp_1 = (uint32_T)rtb_Encoder_0;
sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);
/* {S!d1890}Gain: '<S5>/Gain' */
sMultiWordMul(&Tracker_with_Position_Control_P.Gain_Gain_j.chunks[0U], 2, &tmp.chunks[0U], 2, &Tracker_with_Position_Control_B.r1.chunks[0U], 4);
sMultiWordShr(&Tracker_with_Position_Control_B.r1.chunks[0U], 4, 41U, &Tracker_with_Position_Control_B.r.chunks[0U], 4);
sMultiWord2sMultiWordSat(&Tracker_with_Position_Control_B.r.chunks[0U], 4, &Tracker_with_Position_Control_B.Gain.chunks[0U], 2);
/* {S!d1892}Sum: '<Root>/Sum' incorporates:
 *  Gain: '<S5>/Gain'
 */
Tracker_with_Position_Control_B.Sum = Tracker_with_Position_Control_B.Constant - sMultiWord2Double(&Tracker_with_Position_Control_B.Gain.chunks[0U], 2, 0) * 4.5474735088646412E-13;
/* {S!d1894}Gain: '<S44>/Filter Coefficient' incorporates:
 *  DiscreteIntegrator: '<S36>/Filter'
 *  Gain: '<S34>/Derivative Gain'
 *  Sum: '<S36>/SumD'
 */
rtb_FilterCoefficient = (Tracker_with_Position_Control_P.PIDController_D * Tracker_with_Position_Control_B.Sum - Tracker_with_Position_Contro_DW.Filter_DSTATE) * Tracker_with_Position_Control_P.PIDController_N;
/* {S!d1896}Gain: '<Root>/Gain' incorporates:
 *  DiscreteIntegrator: '<S41>/Integrator'
 *  Gain: '<S46>/Proportional Gain'
 *  Sum: '<S50>/Sum'
 */
rtb_Saturation = ((Tracker_with_Position_Control_P.PIDController_P * Tracker_with_Position_Control_B.Sum + Tracker_with_Position_Contro_DW.Integrator_DSTATE) + rtb_FilterCoefficient) * Tracker_with_Position_Control_P.Gain_Gain;
/* {S!d1898}Saturate: '<Root>/Saturation' */
if (rtb_Saturation > Tracker_with_Position_Control_P.Saturation_UpperSat) {
    rtb_Saturation = Tracker_with_Position_Control_P.Saturation_UpperSat;
} else if (rtb_Saturation < Tracker_with_Position_Control_P.Saturation_LowerSat) {
    rtb_Saturation = Tracker_with_Position_Control_P.Saturation_LowerSat;
}
/* {E!d1898}End of Saturate: '<Root>/Saturation' */

/* {S!d1900}Switch: '<S4>/Switch' incorporates:
 *  Constant: '<S4>/Constant1'
 *  Constant: '<S4>/Constant2'
 *  Constant: '<S4>/Constant4'
 *  Constant: '<S4>/Constant5'
 */
if (rtb_Saturation > Tracker_with_Position_Control_P.Switch_Threshold) {
    rtb_Switch_idx_0 = Tracker_with_Position_Control_P.Constant2_Value;
    rtb_Switch_idx_1 = Tracker_with_Position_Control_P.Constant1_Value;
} else {
    rtb_Switch_idx_0 = Tracker_with_Position_Control_P.Constant5_Value;
    rtb_Switch_idx_1 = Tracker_with_Position_Control_P.Constant4_Value;
}
/* {E!d1900}End of Switch: '<S4>/Switch' */

/* {S!d1902}MATLABSystem: '<S4>/IN1' */
rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_0);
if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
        tmp_2 = (uint8_T)rtb_Switch_idx_0;
    } else {
        tmp_2 = 0U;
    }
} else {
    tmp_2 = MAX_uint8_T;
}
writeDigitalPin(7, tmp_2);
/* {E!d1902}End of MATLABSystem: '<S4>/IN1' */

/* {S!d1904}MATLABSystem: '<S4>/IN2' */
rtb_Switch_idx_0 = rt_roundd_snf(rtb_Switch_idx_1);
if (rtb_Switch_idx_0 < 256.0) {
    if (rtb_Switch_idx_0 >= 0.0) {
        tmp_2 = (uint8_T)rtb_Switch_idx_0;
    } else {
        tmp_2 = 0U;
    }
} else {
    tmp_2 = MAX_uint8_T;
}
writeDigitalPin(8, tmp_2);
/* {E!d1904}End of MATLABSystem: '<S4>/IN2' */

/* {S!d1906}MATLABSystem: '<S4>/ENA1' */
Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
/* {S!d1908}Abs: '<S4>/Abs' */
rtb_Saturation = fabs(rtb_Saturation);
/* {S!d1910}Start for MATLABSystem: '<S4>/ENA1' */
if (!(rtb_Saturation <= 255.0)) {
    rtb_Saturation = 255.0;
}
/* {S!d1912}MATLABSystem: '<S4>/ENA1' */
MW_PWM_SetDutyCycle(Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, rtb_Saturation);
/* {S!d1922}Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
 *  Gain: '<S38>/Integral Gain'
 */
Tracker_with_Position_Contro_DW.Integrator_DSTATE += Tracker_with_Position_Control_P.PIDController_I * Tracker_with_Position_Control_B.Sum * Tracker_with_Position_Control_P.Integrator_gainval;
/* {S!d1924}Update for DiscreteIntegrator: '<S36>/Filter' */
Tracker_with_Position_Contro_DW.Filter_DSTATE += Tracker_with_Position_Control_P.Filter_gainval * rtb_FilterCoefficient;





        



                


                    



                                /* Update absolute time */
                        /* The "clockTick1" counts the number of times the code of this task has
        * been executed. The resolution of this integer timer is 0.01, which is the step size
        * of the task. Size of "clockTick1" ensures timer will not overflow during the
        * application lifespan selected.
            * Timer of this task consists of two 32 bit unsigned integers.
            * The two integers represent the low bits Timing.clockTick1 and the high bits
            * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
        */

        Tracker_with_Position_Contro_M->Timing.clockTick1++;
 if (!Tracker_with_Position_Contro_M->Timing.clockTick1) {
 Tracker_with_Position_Contro_M->Timing.clockTickH1++; 
}







                        

            

        
        



                            



                    } 
        
            
















    /* Model initialize function */
    
            void Tracker_with_Position_Control_initialize(void)
    {
            


    




    
        

        



            /* Registration code */
                
    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    
        


                        
                        /* initialize real-time model */
                        (void) memset((void *)Tracker_with_Position_Contro_M, 0,
sizeof(RT_MODEL_Tracker_with_Positio_T));
                        
                        












                            rtmSetTFinal(Tracker_with_Position_Contro_M, -1);
                                Tracker_with_Position_Contro_M->Timing.stepSize0  = 0.005;


                    





                            /* External mode info */
                                Tracker_with_Position_Contro_M->Sizes.checksums[0] = (1989255917U);
    Tracker_with_Position_Contro_M->Sizes.checksums[1] = (4176518604U);
    Tracker_with_Position_Contro_M->Sizes.checksums[2] = (4210381759U);
    Tracker_with_Position_Contro_M->Sizes.checksums[3] = (1073408411U);


                                {
                    static const sysRanDType  rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
                    static RTWExtModeInfo rt_ExtModeInfo;
                    static const sysRanDType *systemRan[7];



                Tracker_with_Position_Contro_M->extModeInfo = (&rt_ExtModeInfo);
                rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
                
                systemRan[0] = &rtAlwaysEnabled;
                systemRan[1] = &rtAlwaysEnabled;
                systemRan[2] = &rtAlwaysEnabled;
                systemRan[3] = &rtAlwaysEnabled;
                systemRan[4] = &rtAlwaysEnabled;
                systemRan[5] = &rtAlwaysEnabled;
                systemRan[6] = &rtAlwaysEnabled;


                rteiSetModelMappingInfoPtr(Tracker_with_Position_Contro_M->extModeInfo, &Tracker_with_Position_Contro_M->SpecialInfo.mappingInfo);

                rteiSetChecksumsPtr(Tracker_with_Position_Contro_M->extModeInfo, Tracker_with_Position_Contro_M->Sizes.checksums);


                    rteiSetTFinalTicks(Tracker_with_Position_Contro_M->extModeInfo, -1);

        }








        




        /* block I/O */
        
        


                
                (void) memset(((void *) &Tracker_with_Position_Control_B), 0,
sizeof(B_Tracker_with_Position_Contr_T));
                

                





        






        









        /* states (dwork) */
        
        



                                            (void) memset((void *)&Tracker_with_Position_Contro_DW,  0,
 sizeof(DW_Tracker_with_Position_Cont_T));
                        






        
    


        
        
        


        




        







        

    
            
    
        











            
        




                        




                
                                    
                                    /* Start for MATLABSystem: '<S3>/Encoder' */
Tracker_with_Position_Contro_DW.obj.Index = 0U;
Tracker_with_Position_Contro_DW.obj.matlabCodegenIsDeleted = false;
Tracker_with_Position_Contro_DW.objisempty_i = true;
Tracker_with_Position_Contro_DW.obj.isInitialized = 1L;
MW_EncoderSetup(2UL, 3UL, &Tracker_with_Position_Contro_DW.obj.Index);
Tracker_with_Position_Contro_DW.obj.isSetupComplete = true;
Tracker_with_Position_Contro_DW.obj.TunablePropsChanged = false;
/* Start for MATLABSystem: '<S4>/IN1' */
Tracker_with_Position_Contro_DW.obj_e.matlabCodegenIsDeleted = false;
Tracker_with_Position_Contro_DW.objisempty_j = true;
Tracker_with_Position_Contro_DW.obj_e.isInitialized = 1L;
digitalIOSetup(7, 1);
Tracker_with_Position_Contro_DW.obj_e.isSetupComplete = true;
/* Start for MATLABSystem: '<S4>/IN2' */
Tracker_with_Position_Contro_DW.obj_d.matlabCodegenIsDeleted = false;
Tracker_with_Position_Contro_DW.objisempty = true;
Tracker_with_Position_Contro_DW.obj_d.isInitialized = 1L;
digitalIOSetup(8, 1);
Tracker_with_Position_Contro_DW.obj_d.isSetupComplete = true;
/* Start for MATLABSystem: '<S4>/ENA1' */
Tracker_with_Position_Contro_DW.obj_g.matlabCodegenIsDeleted = false;
Tracker_with_Position_Contro_DW.objisempty_a = true;
Tracker_with_Position_Contro_DW.obj_g.isInitialized = 1L;
Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
Tracker_with_Position_Contro_DW.obj_g.isSetupComplete = true;




        




                




        




                




                                                
                                    

/* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
Tracker_with_Position_Contro_DW.Integrator_DSTATE = Tracker_with_Position_Control_P.PIDController_InitialConditio_f;
/* InitializeConditions for DiscreteIntegrator: '<S36>/Filter' */
Tracker_with_Position_Contro_DW.Filter_DSTATE = Tracker_with_Position_Control_P.PIDController_InitialConditionF;
/* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
MW_EncoderReset(Tracker_with_Position_Contro_DW.obj.Index);












                    

    





                



        
    }        






        




        
        /* Model terminate function */
                    void Tracker_with_Position_Control_terminate(void)

        {
            


                                                            




                        




                                                    

                        
                                    /* {S!d1926}Terminate for MATLABSystem: '<S3>/Encoder' */
if (!Tracker_with_Position_Contro_DW.obj.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj.matlabCodegenIsDeleted = true;
    if ((Tracker_with_Position_Contro_DW.obj.isInitialized == 1L) && Tracker_with_Position_Contro_DW.obj.isSetupComplete) {
        MW_EncoderRelease();
    }
}
/* {E!d1926}End of Terminate for MATLABSystem: '<S3>/Encoder' */

/* {S!d1928}Terminate for MATLABSystem: '<S4>/IN1' */
if (!Tracker_with_Position_Contro_DW.obj_e.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_e.matlabCodegenIsDeleted = true;
}
/* {E!d1928}End of Terminate for MATLABSystem: '<S4>/IN1' */

/* {S!d1930}Terminate for MATLABSystem: '<S4>/IN2' */
if (!Tracker_with_Position_Contro_DW.obj_d.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_d.matlabCodegenIsDeleted = true;
}
/* {E!d1930}End of Terminate for MATLABSystem: '<S4>/IN2' */

/* {S!d1932}Terminate for MATLABSystem: '<S4>/ENA1' */
if (!Tracker_with_Position_Contro_DW.obj_g.matlabCodegenIsDeleted) {
    Tracker_with_Position_Contro_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Tracker_with_Position_Contro_DW.obj_g.isInitialized == 1L) && Tracker_with_Position_Contro_DW.obj_g.isSetupComplete) {
        Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
        MW_PWM_SetDutyCycle(Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
        Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
        MW_PWM_Close(Tracker_with_Position_Contro_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
}
/* {E!d1932}End of Terminate for MATLABSystem: '<S4>/ENA1' */





                


                    




                




                                



                        }
            





    




    

    

    

    
