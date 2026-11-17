/*
 * Tricopter_lqgi.c
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

#include "Tricopter_lqgi.h"
#include "Tricopter_lqgi_private.h"
#include <string.h>
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_Tricopter_lqgi_T Tricopter_lqgi_B;

/* Block states (default storage) */
DW_Tricopter_lqgi_T Tricopter_lqgi_DW;

/* Real-time model */
static RT_MODEL_Tricopter_lqgi_T Tricopter_lqgi_M_;
RT_MODEL_Tricopter_lqgi_T *const Tricopter_lqgi_M = &Tricopter_lqgi_M_;
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.656612875245797E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void Tricopter_lqgi_step(void)
{
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  int32_T i;
  int32_T i_0;

  /* DiscreteStateSpace: '<Root>/Plant' */
  {
    Tricopter_lqgi_B.Bd[0] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[0];
    Tricopter_lqgi_B.Bd[1] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[1];
    Tricopter_lqgi_B.Bd[2] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[2];
    Tricopter_lqgi_B.Bd[3] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[3];
    Tricopter_lqgi_B.Bd[4] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[4];
    Tricopter_lqgi_B.Bd[5] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[5];
    Tricopter_lqgi_B.Bd[6] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[6];
    Tricopter_lqgi_B.Bd[7] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[7];
    Tricopter_lqgi_B.Bd[8] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[8];
    Tricopter_lqgi_B.Bd[9] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[9];
    Tricopter_lqgi_B.Bd[10] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[10];
    Tricopter_lqgi_B.Bd[11] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[11];
  }

  /* Gain: '<S2>/Output' incorporates:
   *  RandomNumber: '<S2>/White Noise'
   */
  Tricopter_lqgi_B.Output = 0.0 * Tricopter_lqgi_DW.NextOutput;

  /* Sum: '<S1>/Sum' incorporates:
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   *  Step: '<Root>/Step2'
   *  Step: '<Root>/Step3'
   *  UnitDelay: '<S1>/delay_xhat'
   */
  if (Tricopter_lqgi_M->Timing.taskTime0 < 1.0) {
    Tricopter_lqgi_B.u_raw[0] = 0.0;
    Tricopter_lqgi_B.u_raw[1] = 0.0;
    Tricopter_lqgi_B.u_raw[2] = 0.0;
    Tricopter_lqgi_B.u_raw[3] = 0.0;
  } else {
    Tricopter_lqgi_B.u_raw[0] = 0.5;
    Tricopter_lqgi_B.u_raw[1] = 0.5;
    Tricopter_lqgi_B.u_raw[2] = 0.5;
    Tricopter_lqgi_B.u_raw[3] = 0.5;
  }

  Tricopter_lqgi_B.dv2[0] = Tricopter_lqgi_DW.delay_xhat_DSTATE[0];
  Tricopter_lqgi_B.dv2[1] = Tricopter_lqgi_DW.delay_xhat_DSTATE[1];
  Tricopter_lqgi_B.dv2[2] = Tricopter_lqgi_DW.delay_xhat_DSTATE[2];
  Tricopter_lqgi_B.dv2[3] = Tricopter_lqgi_DW.delay_xhat_DSTATE[5];

  /* Gain: '<S1>/Ki' */
  tmp = 0.0;
  tmp_0 = 0.0;
  tmp_1 = 0.0;
  tmp_2 = 0.0;
  for (i = 0; i < 4; i++) {
    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Sum: '<S1>/Sum'
     */
    Tricopter_lqgi_B.xi_state = (Tricopter_lqgi_B.u_raw[i] -
      Tricopter_lqgi_B.dv2[i]) * 0.01 + Tricopter_lqgi_DW.xi_state[i];
    Tricopter_lqgi_DW.xi_state[i] = Tricopter_lqgi_B.xi_state;
    if (Tricopter_lqgi_B.xi_state > 1.0) {
      Tricopter_lqgi_DW.xi_state[i] = 1.0;
    } else if (Tricopter_lqgi_B.xi_state < -1.0) {
      Tricopter_lqgi_DW.xi_state[i] = -1.0;
    }

    /* Sum: '<S1>/Sum_control' incorporates:
     *  Gain: '<S1>/Kx'
     *  UnitDelay: '<S1>/delay_xhat'
     */
    Tricopter_lqgi_B.xi_state = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      Tricopter_lqgi_B.xi_state += Tricopter_lqgi_ConstP.Kx_Gain[(i_0 << 2) + i]
        * Tricopter_lqgi_DW.delay_xhat_DSTATE[i_0];
    }

    Tricopter_lqgi_B.dv3[i] = 0.0 - Tricopter_lqgi_B.xi_state;

    /* Gain: '<S1>/Ki' incorporates:
     *  MATLAB Function: '<S1>/MATLAB Function'
     */
    Tricopter_lqgi_B.xi_state = Tricopter_lqgi_DW.xi_state[i];
    i_0 = i << 2;
    tmp += Tricopter_lqgi_ConstP.Ki_Gain[i_0] * Tricopter_lqgi_B.xi_state;
    tmp_0 += Tricopter_lqgi_ConstP.Ki_Gain[i_0 + 1] * Tricopter_lqgi_B.xi_state;
    tmp_1 += Tricopter_lqgi_ConstP.Ki_Gain[i_0 + 2] * Tricopter_lqgi_B.xi_state;
    tmp_2 += Tricopter_lqgi_ConstP.Ki_Gain[i_0 + 3] * Tricopter_lqgi_B.xi_state;
  }

  /* Sum: '<S1>/Sum_control' incorporates:
   *  Gain: '<S1>/Ki'
   */
  Tricopter_lqgi_B.u_raw[0] = Tricopter_lqgi_B.dv3[0] - tmp;
  Tricopter_lqgi_B.u_raw[1] = Tricopter_lqgi_B.dv3[1] - tmp_0;
  Tricopter_lqgi_B.u_raw[2] = Tricopter_lqgi_B.dv3[2] - tmp_1;
  Tricopter_lqgi_B.u_raw[3] = Tricopter_lqgi_B.dv3[3] - tmp_2;

  /* Update for DiscreteStateSpace: '<Root>/Plant' */
  {
    real_T xnew[12];
    xnew[0] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[0] + 0.0004905*
      Tricopter_lqgi_DW.Plant_DSTATE[4] + 0.01*Tricopter_lqgi_DW.Plant_DSTATE[6]
      + 1.635E-6*Tricopter_lqgi_DW.Plant_DSTATE[10];
    xnew[0] += 2.2536803219937156E-7*Tricopter_lqgi_B.u_raw[2];
    xnew[1] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[1] + (-0.0004905)*
      Tricopter_lqgi_DW.Plant_DSTATE[3] + 0.01*Tricopter_lqgi_DW.Plant_DSTATE[7]
      + (-1.635E-6)*Tricopter_lqgi_DW.Plant_DSTATE[9];
    xnew[1] += (-2.2536803219937156E-7)*Tricopter_lqgi_B.u_raw[1] + 0.0001635*
      Tricopter_lqgi_B.u_raw[3];
    xnew[2] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[2] + 0.01*
      Tricopter_lqgi_DW.Plant_DSTATE[8];
    xnew[2] += 5.8823529411764694E-5*Tricopter_lqgi_B.u_raw[0];
    xnew[3] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[3] + 0.01*
      Tricopter_lqgi_DW.Plant_DSTATE[9];
    xnew[3] += 0.0027567955009097428*Tricopter_lqgi_B.u_raw[1];
    xnew[4] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[4] + 0.01*
      Tricopter_lqgi_DW.Plant_DSTATE[10];
    xnew[4] += 0.0027567955009097428*Tricopter_lqgi_B.u_raw[2];
    xnew[5] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[5] + 0.01*
      Tricopter_lqgi_DW.Plant_DSTATE[11];
    xnew[5] += 0.001111064398742901*Tricopter_lqgi_B.u_raw[3];
    xnew[6] = 0.0981*Tricopter_lqgi_DW.Plant_DSTATE[4] + 1.0*
      Tricopter_lqgi_DW.Plant_DSTATE[6] + 0.0004905*
      Tricopter_lqgi_DW.Plant_DSTATE[10];
    xnew[6] += 9.0147212879748608E-5*Tricopter_lqgi_B.u_raw[2];
    xnew[7] = (-0.0981)*Tricopter_lqgi_DW.Plant_DSTATE[3] + 1.0*
      Tricopter_lqgi_DW.Plant_DSTATE[7] + (-0.0004905)*
      Tricopter_lqgi_DW.Plant_DSTATE[9];
    xnew[7] += (-9.0147212879748608E-5)*Tricopter_lqgi_B.u_raw[1] + 0.0327*
      Tricopter_lqgi_B.u_raw[3];
    xnew[8] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[8];
    xnew[8] += 0.011764705882352939*Tricopter_lqgi_B.u_raw[0];
    xnew[9] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[9];
    xnew[9] += 0.55135910018194856*Tricopter_lqgi_B.u_raw[1];
    xnew[10] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[10];
    xnew[10] += 0.55135910018194856*Tricopter_lqgi_B.u_raw[2];
    xnew[11] = 1.0*Tricopter_lqgi_DW.Plant_DSTATE[11];
    xnew[11] += 0.22221287974858023*Tricopter_lqgi_B.u_raw[3];
    (void) memcpy(Tricopter_lqgi_DW.Plant_DSTATE, xnew,
                  sizeof(real_T)*12);
  }

  /* Update for RandomNumber: '<S2>/White Noise' */
  Tricopter_lqgi_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&Tricopter_lqgi_DW.RandSeed);

  /* Gain: '<S1>/A_kalman' incorporates:
   *  UnitDelay: '<S1>/delay_xhat'
   */
  memset(&Tricopter_lqgi_B.dv[0], 0, 12U * sizeof(real_T));
  for (i_0 = 0; i_0 < 12; i_0++) {
    tmp = Tricopter_lqgi_DW.delay_xhat_DSTATE[i_0];
    for (i = 0; i < 12; i++) {
      Tricopter_lqgi_B.dv[i] += Tricopter_lqgi_ConstP.A_kalman_Gain[12 * i_0 + i]
        * tmp;
    }

    /* Gain: '<S1>/Bd' incorporates:
     *  UnitDelay: '<S1>/delay_xhat'
     */
    Tricopter_lqgi_B.dv1[i_0] = 0.0;
  }

  /* End of Gain: '<S1>/A_kalman' */

  /* Gain: '<S1>/Bd' incorporates:
   *  Sum: '<S1>/Sum_control'
   */
  for (i_0 = 0; i_0 < 4; i_0++) {
    tmp = Tricopter_lqgi_B.u_raw[i_0];
    for (i = 0; i < 12; i++) {
      Tricopter_lqgi_B.dv1[i] += Tricopter_lqgi_ConstP.Bd_Gain[12 * i_0 + i] *
        tmp;
    }
  }

  /* Sum: '<Root>/Sum_noise' incorporates:
   *  Gain: '<S1>/Bd'
   */
  for (i_0 = 0; i_0 < 12; i_0++) {
    Tricopter_lqgi_B.rtb_Output_m[i_0] = Tricopter_lqgi_B.Output +
      Tricopter_lqgi_B.Bd[i_0];
  }

  /* End of Sum: '<Root>/Sum_noise' */

  /* Update for UnitDelay: '<S1>/delay_xhat' incorporates:
   *  Gain: '<S1>/L_pred'
   *  Sum: '<S1>/Sum_kalman'
   */
  for (i_0 = 0; i_0 < 12; i_0++) {
    tmp = 0.0;
    for (i = 0; i < 12; i++) {
      tmp += Tricopter_lqgi_ConstP.L_pred_Gain[12 * i + i_0] *
        Tricopter_lqgi_B.rtb_Output_m[i];
    }

    Tricopter_lqgi_DW.delay_xhat_DSTATE[i_0] = (Tricopter_lqgi_B.dv[i_0] +
      Tricopter_lqgi_B.dv1[i_0]) + tmp;
  }

  /* End of Update for UnitDelay: '<S1>/delay_xhat' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Tricopter_lqgi_M->rtwLogInfo,
                      (&Tricopter_lqgi_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Tricopter_lqgi_M)!=-1) &&
        !((rtmGetTFinal(Tricopter_lqgi_M)-Tricopter_lqgi_M->Timing.taskTime0) >
          Tricopter_lqgi_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Tricopter_lqgi_M, "Simulation finished");
    }
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
  if (!(++Tricopter_lqgi_M->Timing.clockTick0)) {
    ++Tricopter_lqgi_M->Timing.clockTickH0;
  }

  Tricopter_lqgi_M->Timing.taskTime0 = Tricopter_lqgi_M->Timing.clockTick0 *
    Tricopter_lqgi_M->Timing.stepSize0 + Tricopter_lqgi_M->Timing.clockTickH0 *
    Tricopter_lqgi_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Tricopter_lqgi_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Tricopter_lqgi_M, 0,
                sizeof(RT_MODEL_Tricopter_lqgi_T));
  rtmSetTFinal(Tricopter_lqgi_M, 10.0);
  Tricopter_lqgi_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Tricopter_lqgi_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Tricopter_lqgi_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Tricopter_lqgi_M->rtwLogInfo, (NULL));
    rtliSetLogT(Tricopter_lqgi_M->rtwLogInfo, "tout");
    rtliSetLogX(Tricopter_lqgi_M->rtwLogInfo, "");
    rtliSetLogXFinal(Tricopter_lqgi_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Tricopter_lqgi_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Tricopter_lqgi_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Tricopter_lqgi_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Tricopter_lqgi_M->rtwLogInfo, 1);
    rtliSetLogY(Tricopter_lqgi_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Tricopter_lqgi_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Tricopter_lqgi_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Tricopter_lqgi_DW, 0,
                sizeof(DW_Tricopter_lqgi_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Tricopter_lqgi_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Tricopter_lqgi_M), Tricopter_lqgi_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Tricopter_lqgi_M)));

  {
    int32_T i;

    /* InitializeConditions for DiscreteStateSpace: '<Root>/Plant' */
    for (i = 0; i < 12; i++) {
      Tricopter_lqgi_DW.Plant_DSTATE[i] = Tricopter_lqgi_ConstP.pooled1[i];
    }

    /* InitializeConditions for RandomNumber: '<S2>/White Noise' */
    Tricopter_lqgi_DW.RandSeed = 1529675776U;
    Tricopter_lqgi_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Tricopter_lqgi_DW.RandSeed);

    /* InitializeConditions for UnitDelay: '<S1>/delay_xhat' */
    memset(&Tricopter_lqgi_DW.delay_xhat_DSTATE[0], 0, 12U * sizeof(real_T));

    /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
    Tricopter_lqgi_DW.xi_state[0] = 0.0;
    Tricopter_lqgi_DW.xi_state[1] = 0.0;
    Tricopter_lqgi_DW.xi_state[2] = 0.0;
    Tricopter_lqgi_DW.xi_state[3] = 0.0;
  }
}

/* Model terminate function */
void Tricopter_lqgi_terminate(void)
{
  /* (no terminate code required) */
}
