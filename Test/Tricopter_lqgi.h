/*
 * Tricopter_lqgi.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Tricopter_lqgi".
 *
 * Model version              : 1.28
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Wed Jun  3 14:13:48 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Tricopter_lqgi_h_
#define Tricopter_lqgi_h_
#ifndef Tricopter_lqgi_COMMON_INCLUDES_
#define Tricopter_lqgi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Tricopter_lqgi_COMMON_INCLUDES_ */

#include "Tricopter_lqgi_types.h"
#include <string.h>
#include <float.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Bd[12];                       /* '<S1>/Bd' */
  real_T dv[12];
  real_T dv1[12];
  real_T rtb_Output_m[12];
  real_T u_raw[4];                     /* '<S1>/Sum_control' */
  real_T dv2[4];
  real_T dv3[4];
  real_T Output;                       /* '<S2>/Output' */
  real_T xi_state;
} B_Tricopter_lqgi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Plant_DSTATE[12];             /* '<Root>/Plant' */
  real_T delay_xhat_DSTATE[12];        /* '<S1>/delay_xhat' */
  real_T NextOutput;                   /* '<S2>/White Noise' */
  real_T xi_state[4];                  /* '<S1>/MATLAB Function' */
  uint32_T RandSeed;                   /* '<S2>/White Noise' */
} DW_Tricopter_lqgi_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: zeros(12,1))
   * Referenced by:
   *   '<Root>/Plant'
   *   '<S1>/delay_xhat'
   */
  real_T pooled1[12];

  /* Expression: L_pred
   * Referenced by: '<S1>/L_pred'
   */
  real_T L_pred_Gain[144];

  /* Expression: A_kalman
   * Referenced by: '<S1>/A_kalman'
   */
  real_T A_kalman_Gain[144];

  /* Expression: K_x
   * Referenced by: '<S1>/Kx'
   */
  real_T Kx_Gain[48];

  /* Expression: K_i
   * Referenced by: '<S1>/Ki'
   */
  real_T Ki_Gain[16];

  /* Expression: Bd
   * Referenced by: '<S1>/Bd'
   */
  real_T Bd_Gain[48];
} ConstP_Tricopter_lqgi_T;

/* Real-time Model Data Structure */
struct tag_RTM_Tricopter_lqgi_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_Tricopter_lqgi_T Tricopter_lqgi_B;

/* Block states (default storage) */
extern DW_Tricopter_lqgi_T Tricopter_lqgi_DW;

/* Constant parameters (default storage) */
extern const ConstP_Tricopter_lqgi_T Tricopter_lqgi_ConstP;

/* Model entry point functions */
extern void Tricopter_lqgi_initialize(void);
extern void Tricopter_lqgi_step(void);
extern void Tricopter_lqgi_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Tricopter_lqgi_T *const Tricopter_lqgi_M;

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
 * '<Root>' : 'Tricopter_lqgi'
 * '<S1>'   : 'Tricopter_lqgi/Subsystem'
 * '<S2>'   : 'Tricopter_lqgi/noise'
 * '<S3>'   : 'Tricopter_lqgi/Subsystem/MATLAB Function'
 */
#endif                                 /* Tricopter_lqgi_h_ */
