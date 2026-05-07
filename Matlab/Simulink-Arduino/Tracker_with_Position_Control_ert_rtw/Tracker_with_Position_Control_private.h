

    /*
* Tracker_with_Position_Control_private.h
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


    #ifndef Tracker_with_Position_Control_private_h_
    #define Tracker_with_Position_Control_private_h_



                #include "rtwtypes.h"
            #include "multiword_types.h"


#include "Tracker_with_Position_Control_types.h"

#include "Tracker_with_Position_Control.h"

#include "rtw_continuous.h"

#include "rtw_solver.h"


    

    

    

                /* Private macros used by the generated code to access rtModel */
            

        #ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val) ((rtm)->Timing.tFinal = (val))
#endif


    


        

        #ifndef UCHAR_MAX
        #include <limits.h>
        #endif



            #if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
            #error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
            #endif

            #if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
            #error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
            #endif

            #if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
            #error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
            #endif

            #if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
            #error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
            #endif





    

    

    

    

    

    

    

    

    

                

                                 extern real_T rt_roundd_snf(real_T u);
                



            extern void sMultiWord2sMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T n);

      extern void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[], int16_T n);

      extern void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T n2, uint32_T y[], int16_T n);

      extern real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1);

  

    

    

    

    

    

    

    

    #endif /* Tracker_with_Position_Control_private_h_ */
