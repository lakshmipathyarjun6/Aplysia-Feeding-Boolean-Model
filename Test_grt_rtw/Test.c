/*
 * Test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test".
 *
 * Model version              : 1.77
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Dec  1 12:05:10 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test.h"
#include "Test_private.h"

/* Block signals (default storage) */
B_Test_T Test_B;

/* Continuous states */
X_Test_T Test_X;

/* Block states (default storage) */
DW_Test_T Test_DW;

/* Real-time model */
RT_MODEL_Test_T Test_M_;
RT_MODEL_Test_T *const Test_M = &Test_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Test_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Test_step();
  Test_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Test_step();
  Test_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Disable for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S24>/Enabled Subsystem'
 */
void Test_EnabledSubsystem_Disable(DW_EnabledSubsystem_Test_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S24>/Enabled Subsystem'
 */
void Test_EnabledSubsystem(RT_MODEL_Test_T * const Test_M, boolean_T rtu_Enable,
  real_T *rty_Out1, DW_EnabledSubsystem_Test_T *localDW,
  P_EnabledSubsystem_Test_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  if (rtmIsMajorTimeStep(Test_M)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem_MODE = true;
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        Test_EnabledSubsystem_Disable(localDW);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE && rtmIsMajorTimeStep(Test_M)) {
    /* SignalConversion generated from: '<S23>/Out1' incorporates:
     *  Constant: '<S23>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
}

/*
 * Disable for enable system:
 *    '<S27>/Kinetic Friction Behavior'
 *    '<S37>/Kinetic Friction Behavior'
 */
void KineticFrictionBehavior_Disable(DW_KineticFrictionBehavior_Te_T *localDW)
{
  localDW->KineticFrictionBehavior_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S27>/Kinetic Friction Behavior'
 *    '<S37>/Kinetic Friction Behavior'
 */
void Test_KineticFrictionBehavior(RT_MODEL_Test_T * const Test_M, boolean_T
  rtu_Enable, real_T rtu_sens_mechanical_grasper, real_T rtu_F_comb, real_T
  rtu_F_kf_range, real_T *rty_F_f_g, real_T *rty_grasper_friction_state,
  DW_KineticFrictionBehavior_Te_T *localDW, P_KineticFrictionBehavior_Tes_T
  *localP)
{
  /* Outputs for Enabled SubSystem: '<S27>/Kinetic Friction Behavior' incorporates:
   *  EnablePort: '<S35>/Enable'
   */
  if (rtmIsMajorTimeStep(Test_M) && rtmIsMajorTimeStep(Test_M)) {
    if (rtu_Enable) {
      localDW->KineticFrictionBehavior_MODE = true;
    } else {
      if (localDW->KineticFrictionBehavior_MODE) {
        KineticFrictionBehavior_Disable(localDW);
      }
    }
  }

  if (localDW->KineticFrictionBehavior_MODE) {
    /* Product: '<S35>/Product1' incorporates:
     *  Abs: '<S35>/Abs'
     *  Gain: '<S35>/Gain'
     *  Product: '<S35>/Divide'
     *  Product: '<S35>/Product'
     */
    *rty_F_f_g = localP->Gain_Gain * rtu_F_comb / fabs(rtu_F_comb) *
      (rtu_sens_mechanical_grasper * rtu_F_kf_range);
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S35>/grasper_friction_state' incorporates:
       *  Constant: '<S35>/Constant'
       */
      *rty_grasper_friction_state = localP->Constant_Value;
    }
  }

  /* End of Outputs for SubSystem: '<S27>/Kinetic Friction Behavior' */
}

/*
 * Disable for enable system:
 *    '<S27>/Static Friction Behavior'
 *    '<S37>/Static Friction Behavior'
 */
void StaticFrictionBehavior_Disable(DW_StaticFrictionBehavior_Tes_T *localDW)
{
  localDW->StaticFrictionBehavior_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S27>/Static Friction Behavior'
 *    '<S37>/Static Friction Behavior'
 */
void Test_StaticFrictionBehavior(RT_MODEL_Test_T * const Test_M, boolean_T
  rtu_Enable, real_T rtu_sens_mechanical_grasper, real_T rtu_F_comb, real_T
  *rty_F_f_g, real_T *rty_grasper_friction_state,
  DW_StaticFrictionBehavior_Tes_T *localDW, P_StaticFrictionBehavior_Test_T
  *localP)
{
  /* Outputs for Enabled SubSystem: '<S27>/Static Friction Behavior' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  if (rtmIsMajorTimeStep(Test_M) && rtmIsMajorTimeStep(Test_M)) {
    if (rtu_Enable) {
      localDW->StaticFrictionBehavior_MODE = true;
    } else {
      if (localDW->StaticFrictionBehavior_MODE) {
        StaticFrictionBehavior_Disable(localDW);
      }
    }
  }

  if (localDW->StaticFrictionBehavior_MODE) {
    /* Product: '<S36>/Product' incorporates:
     *  Gain: '<S36>/Gain'
     */
    *rty_F_f_g = localP->Gain_Gain * rtu_sens_mechanical_grasper * rtu_F_comb;
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S36>/grasper_friction_state' incorporates:
       *  Constant: '<S36>/Constant'
       */
      *rty_grasper_friction_state = localP->Constant_Value;
    }
  }

  /* End of Outputs for SubSystem: '<S27>/Static Friction Behavior' */
}

/* Model step function */
void Test_step(void)
{
  /* local block i/o variables */
  real_T rtb_Gain3;
  real_T rtb_F_comb;
  real_T rtb_F_comb_n;
  boolean_T rtb_AND;
  boolean_T rtb_GreaterThan;
  real_T x_gh;
  real_T on_thresh;
  real_T off_thresh;
  int32_T B40B30_excite;
  boolean_T rtb_GreaterThan1;
  real_T rtb_Gain2;
  real_T rtb_Gain2_m5;
  real_T rtb_Gain3_o;
  real_T rtb_Clock;
  real_T rtb_Add2;
  AplysiaBus rtb_y;
  real_T rtb_Product2_n;
  real_T rtb_Abs1_0;
  real_T rtb_TmpSignalConversionAtDotP_0;
  real_T rtb_TmpSignalConversionAtDotP_1;
  real_T rtb_Gain_idx_0;
  real_T rtb_Gain_idx_1;
  real_T x_gh_tmp;
  real_T rtb_Gain3_tmp;
  if (rtmIsMajorTimeStep(Test_M)) {
    /* set solver stop time */
    if (!(Test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Test_M->solverInfo, ((Test_M->Timing.clockTickH0 +
        1) * Test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Test_M->solverInfo, ((Test_M->Timing.clockTick0 + 1)
        * Test_M->Timing.stepSize0 + Test_M->Timing.clockTickH0 *
        Test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Test_M)) {
    Test_M->Timing.t[0] = rtsiGetT(&Test_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Test_M)) {
    /* UnitDelay: '<Root>/Unit Delay' */
    Test_B.UnitDelay = Test_DW.UnitDelay_DSTATE;
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Test_M->Timing.t[0];

  /* MATLAB Function: '<Root>/setSensoryStates' */
  rtb_y = Test_B.UnitDelay;
  if (Test_B.UnitDelay.switchBehavior == 0.0) {
    if (Test_B.UnitDelay.behavior_1 == 1.0) {
      rtb_y.sens_chemical_lips = 1.0;
      rtb_y.sens_mechanical_lips = 1.0;
      rtb_y.sens_mechanical_grasper = 0.0;
      rtb_y.fixation_type = 0.0;
    } else if (Test_B.UnitDelay.behavior_1 == 2.0) {
      rtb_y.sens_chemical_lips = 1.0;
      rtb_y.sens_mechanical_lips = 1.0;
      rtb_y.sens_mechanical_grasper = 1.0;
      rtb_y.fixation_type = 1.0;
    } else {
      if (Test_B.UnitDelay.behavior_1 == 2.0) {
        rtb_y.sens_chemical_lips = 0.0;
        rtb_y.sens_mechanical_lips = 1.0;
        rtb_y.sens_mechanical_grasper = 1.0;
        rtb_y.fixation_type = 0.0;
      }
    }
  } else {
    if (Test_B.UnitDelay.switchBehavior == 1.0) {
      if (Test_B.UnitDelay.behavior_1 == 1.0) {
        rtb_y.sens_chemical_lips = 1.0;
        rtb_y.sens_mechanical_lips = 1.0;
        rtb_y.sens_mechanical_grasper = 0.0;
        rtb_y.fixation_type = 0.0;
      } else if (Test_B.UnitDelay.behavior_1 == 2.0) {
        rtb_y.sens_chemical_lips = 1.0;
        rtb_y.sens_mechanical_lips = 1.0;
        rtb_y.sens_mechanical_grasper = 1.0;
        rtb_y.fixation_type = 1.0;
      } else {
        if (Test_B.UnitDelay.behavior_1 == 2.0) {
          rtb_y.sens_chemical_lips = 0.0;
          rtb_y.sens_mechanical_lips = 1.0;
          rtb_y.sens_mechanical_grasper = 1.0;
          rtb_y.fixation_type = 0.0;
        }
      }

      if (rtb_Clock > Test_B.UnitDelay.t_switch) {
        if (Test_B.UnitDelay.behavior_1 == 1.0) {
          rtb_y.sens_chemical_lips = 1.0;
          rtb_y.sens_mechanical_lips = 1.0;
          rtb_y.sens_mechanical_grasper = 0.0;
          rtb_y.fixation_type = 0.0;
        } else if (Test_B.UnitDelay.behavior_1 == 2.0) {
          rtb_y.sens_chemical_lips = 1.0;
          rtb_y.sens_mechanical_lips = 1.0;
          rtb_y.sens_mechanical_grasper = 1.0;
          rtb_y.fixation_type = 1.0;
        } else {
          if (Test_B.UnitDelay.behavior_1 == 2.0) {
            rtb_y.sens_chemical_lips = 0.0;
            rtb_y.sens_mechanical_lips = 1.0;
            rtb_y.sens_mechanical_grasper = 1.0;
            rtb_y.fixation_type = 0.0;
          }
        }
      }
    }
  }

  /* End of MATLAB Function: '<Root>/setSensoryStates' */

  /* MATLAB Function: '<Root>/Neural Control' */
  Test_B.y = rtb_y;
  x_gh = rtb_y.x_g - rtb_y.x_h;
  Test_B.y.MCC = rtb_y.MCC;
  if (rtb_y.use_hypothesized_connections == 1.0) {
    Test_B.y.CBI2 = (real_T)(((rtb_y.sens_mechanical_lips != 0.0) &&
      (rtb_y.sens_chemical_lips != 0.0) && (!(rtb_y.sens_mechanical_grasper !=
      0.0))) || ((rtb_y.sens_mechanical_grasper != 0.0) &&
                 (!(rtb_y.sens_chemical_lips != 0.0))) || (rtb_y.B4B5 >= 2.0)) *
      ((real_T)(rtb_y.stim_CBI2 == 0.0) * rtb_y.MCC * (real_T)!(rtb_y.B64 != 0.0))
      + (real_T)(rtb_y.stim_CBI2 == 1.0);
  } else {
    Test_B.y.CBI2 = (real_T)(((rtb_y.sens_mechanical_lips != 0.0) &&
      (rtb_y.sens_chemical_lips != 0.0) && (!(rtb_y.sens_mechanical_grasper !=
      0.0))) || ((rtb_y.sens_mechanical_grasper != 0.0) &&
                 (!(rtb_y.sens_chemical_lips != 0.0)))) * ((real_T)
      (rtb_y.stim_CBI2 == 0.0) * rtb_y.MCC * (real_T)!(rtb_y.B64 != 0.0)) +
      (real_T)(rtb_y.stim_CBI2 == 1.0);
  }

  if ((rtb_y.B4B5 >= 2.0) && (Test_B.y.CBI3_stimON == 0.0)) {
    Test_B.y.CBI3_stimON = rtb_Clock;
  }

  if ((Test_B.y.CBI3_stimON != 0.0) && (rtb_y.B4B5 < 2.0)) {
    Test_B.y.CBI3_refractory = 1.0;
    Test_B.y.CBI3_stimOFF = rtb_Clock;
    Test_B.y.CBI3_stimON = 0.0;
  }

  if ((Test_B.y.CBI3_refractory != 0.0) && (rtb_Clock < rtb_y.refractory_CBI3 /
       1000.0 + Test_B.y.CBI3_stimOFF)) {
    Test_B.y.CBI3_refractory = 1.0;
  } else {
    Test_B.y.CBI3_stimOFF = 0.0;
    Test_B.y.CBI3_refractory = 0.0;
  }

  if (rtb_y.use_hypothesized_connections == 1.0) {
    Test_B.y.CBI3 = rtb_y.sens_mechanical_lips * rtb_y.sens_chemical_lips *
      rtb_y.MCC * (real_T)(rtb_y.B4B5 < 2.0) * (real_T)
      !(Test_B.y.CBI3_refractory != 0.0);
  } else {
    Test_B.y.CBI3 = rtb_y.sens_mechanical_lips * rtb_y.sens_chemical_lips *
      rtb_y.MCC;
  }

  Test_B.y.CBI4 = (real_T)((rtb_y.sens_mechanical_lips != 0.0) ||
    (rtb_y.sens_chemical_lips != 0.0)) * rtb_y.MCC *
    rtb_y.sens_mechanical_grasper;
  Test_B.y.B64 = (real_T)(((real_T)(((real_T)(x_gh >
    rtb_y.thresh_B64_swallow_protract) * rtb_y.sens_mechanical_grasper != 0.0) ||
    (!(rtb_y.sens_mechanical_grasper != 0.0) * (x_gh >
    rtb_y.thresh_B64_bite_protract) != 0)) * rtb_y.CBI3 != 0.0) || (!(rtb_y.CBI3
    != 0.0) * (x_gh > rtb_y.thresh_B64_reject_protract) != 0)) * ((real_T)
    !(rtb_y.B31B32 != 0.0) * rtb_y.MCC);
  Test_B.y.B4B5 = ((real_T)!(rtb_y.CBI3 != 0.0) * 2.0 * rtb_y.B64 * (real_T)
                   (x_gh > rtb_y.thresh_B4B5_protract) * (real_T)
                   !(rtb_y.stim_B4B5 != 0.0) + rtb_y.CBI3 *
                   rtb_y.sens_mechanical_grasper * rtb_y.B64) * rtb_y.MCC + 2.0 *
    rtb_y.stim_B4B5;
  Test_B.y.B20 = (real_T)((rtb_y.CBI2 != 0.0) || (rtb_y.CBI4 != 0.0) ||
    (rtb_y.B31B32 != 0.0)) * rtb_y.MCC * (real_T)!(rtb_y.CBI3 != 0.0) * (real_T)
    !(rtb_y.B64 != 0.0);
  Test_B.y.B40B30 = (real_T)((rtb_y.CBI2 != 0.0) || (rtb_y.CBI4 != 0.0) ||
    (rtb_y.B31B32 != 0.0)) * rtb_y.MCC * (real_T)!(rtb_y.B64 != 0.0);
  if ((rtb_y.B40B30 == 1.0) && (Test_B.y.B40B30 == 0.0)) {
    Test_B.y.B40B30_offTime = rtb_Clock;
  }

  if ((rtb_y.sens_mechanical_grasper != 0.0) && (rtb_y.CBI3 != 0.0)) {
    on_thresh = rtb_y.thresh_B31_swallow_on;
    off_thresh = rtb_y.thresh_B31_swallow_off;
  } else if ((rtb_y.sens_mechanical_grasper != 0.0) && (!(rtb_y.CBI3 != 0.0))) {
    on_thresh = rtb_y.thresh_B31_reject_on;
    off_thresh = rtb_y.thresh_B31_reject_off;
  } else {
    on_thresh = rtb_y.thresh_B31_bite_on;
    off_thresh = rtb_y.thresh_B31_bite_off;
  }

  Test_B.y.B31B32 = ((real_T)((rtb_y.P_I4 < 0.5) || (rtb_y.CBI2 != 0.0)) *
                     (real_T)!(rtb_y.B64 != 0.0) * ((real_T)!(rtb_y.B31B32 !=
    0.0) * (real_T)(x_gh < off_thresh) + (real_T)(x_gh < on_thresh) *
    rtb_y.B31B32) * rtb_y.CBI3 + (real_T)!(rtb_y.B64 != 0.0) * (real_T)
                     (rtb_y.P_I4 > 0.25) * (real_T)((rtb_y.CBI2 != 0.0) ||
    (rtb_y.CBI4 != 0.0)) * ((real_T)!(rtb_y.B31B32 != 0.0) * (real_T)(x_gh <
    off_thresh) + (real_T)(x_gh < on_thresh) * rtb_y.B31B32) * (real_T)
                     !(rtb_y.CBI3 != 0.0)) * rtb_y.MCC;
  Test_B.y.B6B9B3 = ((real_T)(((rtb_y.CBI3 != 0.0) &&
    (!(rtb_y.sens_mechanical_grasper != 0.0))) * (rtb_y.P_I4 >
    rtb_y.thresh_B6B9B3_bite_pressure) + ((rtb_y.CBI3 != 0.0) &&
    (rtb_y.sens_mechanical_grasper != 0.0)) * (rtb_y.P_I4 >
    rtb_y.thresh_B6B9B3_swallow_pressure)) + (real_T)!(rtb_y.CBI3 != 0.0) *
                     (real_T)!(rtb_y.P_I4 > rtb_y.thresh_B6B9B3_reject_pressure))
    * (rtb_y.MCC * rtb_y.B64 * (real_T)!(rtb_y.B4B5 >= 2.0));
  if ((rtb_y.B40B30 == 0.0) && (rtb_Clock < rtb_y.postActivityExcitation_B40B30 /
       1000.0 + Test_B.y.B40B30_offTime)) {
    B40B30_excite = 1;
  } else {
    B40B30_excite = 0;
  }

  Test_B.y.B8 = ((real_T)((rtb_y.B20 != 0.0) || (!(rtb_y.B31B32 != 0.0) *
    B40B30_excite != 0)) * rtb_y.CBI3 + (real_T)!(rtb_y.CBI3 != 0.0) * rtb_y.B20)
    * ((real_T)!(rtb_y.B4B5 >= 2.0) * rtb_y.MCC);
  Test_B.y.B7 = ((real_T)((!(rtb_y.CBI3 != 0.0)) ||
    (rtb_y.sens_mechanical_grasper != 0.0)) * (real_T)((x_gh >=
    rtb_y.thresh_B7_reject_protract) || (rtb_y.P_I4 > 0.97)) + (real_T)
                 ((rtb_y.CBI3 != 0.0) && (!(rtb_y.sens_mechanical_grasper != 0.0)))
                 * (real_T)((x_gh >= rtb_y.thresh_B7_bite_protract) ||
    (rtb_y.P_I4 > 0.97))) * rtb_y.MCC;
  Test_B.y.B38 = (real_T)(x_gh < rtb_y.thresh_B38_retract) * rtb_y.CBI3 *
    (rtb_y.MCC * rtb_y.sens_mechanical_grasper);
  rtb_Add2 = rtb_y.tau_I4 + rtb_y.TimeStep;
  Test_B.y.P_I4 = (rtb_y.tau_I4 * rtb_y.P_I4 + rtb_y.A_I4 * rtb_y.TimeStep) /
    rtb_Add2;
  Test_B.y.A_I4 = (rtb_y.tau_I4 * rtb_y.A_I4 + rtb_y.B8 * rtb_y.TimeStep) /
    rtb_Add2;
  rtb_Add2 = rtb_y.tau_I3anterior + rtb_y.TimeStep;
  Test_B.y.P_I3_anterior = (rtb_y.tau_I3anterior * rtb_y.P_I3_anterior +
    rtb_y.A_I3_anterior * rtb_y.TimeStep) / rtb_Add2;
  Test_B.y.A_I3_anterior = ((rtb_y.B38 + rtb_y.B6B9B3) * rtb_y.TimeStep +
    rtb_y.tau_I3anterior * rtb_y.A_I3_anterior) / rtb_Add2;
  rtb_Add2 = rtb_y.tau_I3 + rtb_y.TimeStep;
  Test_B.y.T_I3 = (rtb_y.tau_I3 * rtb_y.T_I3 + rtb_y.TimeStep * rtb_y.A_I3) /
    rtb_Add2;
  Test_B.y.A_I3 = (rtb_y.tau_I3 * rtb_y.A_I3 + rtb_y.TimeStep * rtb_y.B6B9B3) /
    rtb_Add2;
  rtb_Add2 = (1.0 - rtb_y.CBI3) * rtb_y.tau_I2_egestion + rtb_y.tau_I2_ingestion
    * rtb_y.CBI3;
  rtb_Gain2 = rtb_Add2 + rtb_y.TimeStep;
  Test_B.y.T_I2 = (rtb_Add2 * rtb_y.T_I2 + rtb_y.TimeStep * rtb_y.A_I2) /
    rtb_Gain2;
  Test_B.y.A_I2 = (rtb_Add2 * rtb_y.A_I2 + rtb_y.TimeStep * rtb_y.B31B32) /
    rtb_Gain2;
  rtb_Add2 = rtb_y.tau_hinge + rtb_y.TimeStep;
  Test_B.y.T_hinge = (rtb_y.tau_hinge * rtb_y.T_hinge + rtb_y.TimeStep *
                      rtb_y.A_hinge) / rtb_Add2;
  Test_B.y.A_hinge = (rtb_y.tau_hinge * rtb_y.A_hinge + rtb_y.TimeStep *
                      rtb_y.B7) / rtb_Add2;

  /* End of MATLAB Function: '<Root>/Neural Control' */

  /* Product: '<S29>/Product' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant2'
   *  DotProduct: '<S29>/Dot Product1'
   *  SignalConversion generated from: '<S9>/Dot Product1'
   */
  rtb_Clock = (Test_P.Constant2_Value_j[0] * Test_B.y.x_h +
               Test_P.Constant2_Value_j[1] * Test_B.y.x_g) *
    Test_P.init_obj.max_I3 * Test_B.y.T_I3;

  /* DotProduct: '<S30>/Dot Product1' incorporates:
   *  Constant: '<S30>/Constant1'
   *  SignalConversion generated from: '<S9>/Dot Product1'
   */
  rtb_Abs1_0 = Test_P.Constant1_Value_j[0] * Test_B.y.x_h +
    Test_P.Constant1_Value_j[1] * Test_B.y.x_g;

  /* RelationalOperator: '<S30>/GreaterThan1' incorporates:
   *  Constant: '<S30>/Constant3'
   *  DotProduct: '<S30>/Dot Product1'
   */
  rtb_GreaterThan1 = (rtb_Abs1_0 > Test_P.Constant3_Value);

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  DotProduct: '<S30>/Dot Product1'
   *  Sum: '<S30>/Add2'
   */
  rtb_Abs1_0 = (rtb_Abs1_0 - Test_P.Constant3_Value) * Test_P.init_obj.max_hinge
    * (real_T)rtb_GreaterThan1 * Test_B.y.T_hinge;

  /* Sum: '<S33>/Add2' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant4'
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant2'
   *  Constant: '<S31>/Constant4'
   *  DotProduct: '<S28>/Dot Product'
   *  DotProduct: '<S31>/Dot Product1'
   *  Product: '<S28>/Product'
   *  Product: '<S31>/Product'
   *  SignalConversion generated from: '<S9>/Dot Product1'
   *  Sum: '<S28>/Add'
   *  Sum: '<S31>/Add'
   */
  rtb_Add2 = ((((Test_P.Constant1_Value_o[0] * Test_B.y.x_h +
                 Test_P.Constant1_Value_o[1] * Test_B.y.x_g) +
                Test_P.Constant4_Value) * Test_P.init_obj.max_I2 * Test_B.y.T_I2
               + ((Test_P.Constant2_Value[0] * Test_B.y.x_h +
                   Test_P.Constant2_Value[1] * Test_B.y.x_g) +
                  Test_P.init_obj.x_gh_ref) * Test_P.init_obj.K_sp_g) -
              rtb_Clock) - rtb_Abs1_0;

  /* Product: '<S32>/Product' incorporates:
   *  Constant: '<S32>/Constant4'
   */
  on_thresh = Test_P.init_obj.max_I4 * Test_B.y.P_I4;

  /* Gain: '<S33>/Gain2' */
  rtb_Gain2 = Test_P.init_obj.mu_s_g * on_thresh;

  /* Outputs for Enabled SubSystem: '<S5>/Surface fixed' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S12>/unbroken subsystem' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S16>/Kinetic Friction Behavior' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S19>/Kinetic Grasper' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  /* Gain: '<S33>/Gain3' incorporates:
   *  Gain: '<S21>/Gain3'
   */
  rtb_Gain3_tmp = Test_P.init_obj.mu_k_g * on_thresh;

  /* End of Outputs for SubSystem: '<S19>/Kinetic Grasper' */
  /* End of Outputs for SubSystem: '<S16>/Kinetic Friction Behavior' */
  /* End of Outputs for SubSystem: '<S12>/unbroken subsystem' */
  /* End of Outputs for SubSystem: '<S5>/Surface fixed' */
  rtb_Gain3 = rtb_Gain3_tmp;
  if (rtmIsMajorTimeStep(Test_M)) {
    /* Product: '<S31>/Product2' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant2'
     */
    Test_B.Product2[0] = Test_P.Constant2_Value[0] * Test_P.init_obj.K_sp_g;
    Test_B.Product2[1] = Test_P.Constant2_Value[1] * Test_P.init_obj.K_sp_g;
  }

  /* Outputs for Enabled SubSystem: '<S7>/Surface fixed' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S34>/unbroken subsystem' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S38>/Kinetic Friction Behavior' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  /* Gain: '<S33>/Gain' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant2'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant2'
   *  Gain: '<S33>/Gain1'
   *  Gain: '<S41>/Gain1'
   *  Gain: '<S4>/Gain1'
   *  Product: '<S28>/Product2'
   *  Product: '<S29>/Product2'
   *  Product: '<S30>/Product2'
   *  Sum: '<S33>/Add'
   */
  x_gh_tmp = 1.0 / Test_P.init_obj.c_g;

  /* End of Outputs for SubSystem: '<S38>/Kinetic Friction Behavior' */
  /* End of Outputs for SubSystem: '<S34>/unbroken subsystem' */
  /* End of Outputs for SubSystem: '<S7>/Surface fixed' */
  rtb_Gain_idx_0 = (((Test_P.init_obj.max_I2 * Test_P.Constant1_Value_o[0] *
                      Test_B.y.T_I2 + Test_B.Product2[0]) -
                     Test_P.init_obj.max_I3 * Test_P.Constant2_Value_j[0] *
                     Test_B.y.T_I3) - Test_P.init_obj.max_hinge *
                    Test_P.Constant1_Value_j[0] * (real_T)rtb_GreaterThan1 *
                    Test_B.y.T_hinge) * x_gh_tmp;
  rtb_Gain_idx_1 = (((Test_P.init_obj.max_I2 * Test_P.Constant1_Value_o[1] *
                      Test_B.y.T_I2 + Test_B.Product2[1]) -
                     Test_P.init_obj.max_I3 * Test_P.Constant2_Value_j[1] *
                     Test_B.y.T_I3) - Test_P.init_obj.max_hinge *
                    Test_P.Constant1_Value_j[1] * (real_T)rtb_GreaterThan1 *
                    Test_B.y.T_hinge) * x_gh_tmp;
  if (rtmIsMajorTimeStep(Test_M)) {
    /* Product: '<S31>/Product3' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant4'
     */
    Test_B.Product3 = Test_P.init_obj.x_gh_ref * Test_P.init_obj.K_sp_g;
  }

  /* Gain: '<S33>/Gain1' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant4'
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  Product: '<S28>/Product3'
   *  Product: '<S30>/Product3'
   *  Sum: '<S33>/Add1'
   */
  on_thresh = ((Test_P.init_obj.max_I2 * Test_P.Constant4_Value * Test_B.y.T_I2
                + Test_B.Product3) + Test_P.init_obj.max_hinge *
               Test_P.Constant3_Value * (real_T)rtb_GreaterThan1 *
               Test_B.y.T_hinge) * x_gh_tmp;

  /* Logic: '<S7>/NOT1' */
  Test_B.NOT1 = !(Test_B.y.fixation_type != 0.0);
  if (rtmIsMajorTimeStep(Test_M)) {
    /* SignalConversion generated from: '<S27>/Enable' */
    Test_B.HiddenBuf_InsertedFor_Notsurfac = Test_B.NOT1;

    /* Outputs for Enabled SubSystem: '<S7>/Not surface fixed' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      if (Test_B.HiddenBuf_InsertedFor_Notsurfac) {
        Test_DW.Notsurfacefixed_MODE = true;
      } else {
        if (Test_DW.Notsurfacefixed_MODE) {
          /* Disable for Enabled SubSystem: '<S27>/Kinetic Friction Behavior' */
          if (Test_DW.KineticFrictionBehavior_mx.KineticFrictionBehavior_MODE) {
            KineticFrictionBehavior_Disable(&Test_DW.KineticFrictionBehavior_mx);
          }

          /* End of Disable for SubSystem: '<S27>/Kinetic Friction Behavior' */

          /* Disable for Enabled SubSystem: '<S27>/Static Friction Behavior' */
          if (Test_DW.StaticFrictionBehavior_f.StaticFrictionBehavior_MODE) {
            StaticFrictionBehavior_Disable(&Test_DW.StaticFrictionBehavior_f);
          }

          /* End of Disable for SubSystem: '<S27>/Static Friction Behavior' */
          Test_DW.Notsurfacefixed_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Not surface fixed' */
  }

  /* Outputs for Enabled SubSystem: '<S7>/Not surface fixed' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  if (Test_DW.Notsurfacefixed_MODE) {
    /* Inport: '<S27>/F_comb' */
    rtb_F_comb_n = rtb_Add2;

    /* RelationalOperator: '<S27>/LessThanOrEqual' incorporates:
     *  Abs: '<S27>/Abs'
     *  Abs: '<S27>/Abs1'
     */
    Test_B.LessThanOrEqual_p = (fabs(rtb_F_comb_n) <= fabs(rtb_Gain2));

    /* Logic: '<S27>/NOT' */
    Test_B.NOT_p = !Test_B.LessThanOrEqual_p;
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S35>/Enable' */
      Test_B.HiddenBuf_InsertedFor_Kineti_hz = Test_B.NOT_p;

      /* SignalConversion generated from: '<S36>/Enable' */
      Test_B.HiddenBuf_InsertedFor_Static_ng = Test_B.LessThanOrEqual_p;
    }

    /* Outputs for Enabled SubSystem: '<S27>/Kinetic Friction Behavior' */
    Test_KineticFrictionBehavior(Test_M, Test_B.HiddenBuf_InsertedFor_Kineti_hz,
      Test_B.y.sens_mechanical_grasper, rtb_F_comb_n, rtb_Gain3, &Test_B.Merge3,
      &Test_B.Merge4, &Test_DW.KineticFrictionBehavior_mx,
      &Test_P.KineticFrictionBehavior_mx);

    /* End of Outputs for SubSystem: '<S27>/Kinetic Friction Behavior' */

    /* Outputs for Enabled SubSystem: '<S27>/Static Friction Behavior' */
    Test_StaticFrictionBehavior(Test_M, Test_B.HiddenBuf_InsertedFor_Static_ng,
      Test_B.y.sens_mechanical_grasper, rtb_F_comb_n, &Test_B.Merge3,
      &Test_B.Merge4, &Test_DW.StaticFrictionBehavior_f,
      &Test_P.StaticFrictionBehavior_f);

    /* End of Outputs for SubSystem: '<S27>/Static Friction Behavior' */

    /* SignalConversion generated from: '<S27>/F_g' */
    Test_B.Merge6_d = rtb_F_comb_n;

    /* SignalConversion generated from: '<S27>/A21' incorporates:
     *  Inport: '<S27>/A2'
     */
    Test_B.Merge1_l = rtb_Gain_idx_0;

    /* SignalConversion generated from: '<S27>/A22' incorporates:
     *  Inport: '<S27>/A2'
     */
    Test_B.Merge2_l = rtb_Gain_idx_1;

    /* Inport: '<S27>/B2_in' */
    Test_B.Merge5_e = on_thresh;
  }

  /* End of Outputs for SubSystem: '<S7>/Not surface fixed' */

  /* SignalConversion generated from: '<S1>/Bus Selector4' */
  Test_B.unbroken = Test_B.y.unbroken;
  if (rtmIsMajorTimeStep(Test_M)) {
    /* SignalConversion generated from: '<S34>/Enable' */
    Test_B.HiddenBuf_InsertedFor_Surfacefi = Test_B.y.fixation_type;

    /* Outputs for Enabled SubSystem: '<S7>/Surface fixed' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      if (Test_B.HiddenBuf_InsertedFor_Surfacefi > 0.0) {
        Test_DW.Surfacefixed_MODE = true;
      } else {
        if (Test_DW.Surfacefixed_MODE) {
          /* Disable for Enabled SubSystem: '<S34>/unbroken subsystem' */
          if (Test_DW.unbrokensubsystem_MODE) {
            /* Disable for Enabled SubSystem: '<S38>/Static Friction Behavior' */
            Test_DW.StaticFrictionBehavior_MODE = false;

            /* End of Disable for SubSystem: '<S38>/Static Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S38>/Kinetic Friction Behavior' */
            Test_DW.KineticFrictionBehavior_MODE = false;

            /* End of Disable for SubSystem: '<S38>/Kinetic Friction Behavior' */
            Test_DW.unbrokensubsystem_MODE = false;
          }

          /* End of Disable for SubSystem: '<S34>/unbroken subsystem' */

          /* Disable for Enabled SubSystem: '<S34>/broken subsystem' */
          if (Test_DW.brokensubsystem_MODE) {
            /* Disable for Enabled SubSystem: '<S37>/Kinetic Friction Behavior' */
            if (Test_DW.KineticFrictionBehavior_f.KineticFrictionBehavior_MODE)
            {
              KineticFrictionBehavior_Disable(&Test_DW.KineticFrictionBehavior_f);
            }

            /* End of Disable for SubSystem: '<S37>/Kinetic Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S37>/Static Friction Behavior' */
            if (Test_DW.StaticFrictionBehavior_i.StaticFrictionBehavior_MODE) {
              StaticFrictionBehavior_Disable(&Test_DW.StaticFrictionBehavior_i);
            }

            /* End of Disable for SubSystem: '<S37>/Static Friction Behavior' */
            Test_DW.brokensubsystem_MODE = false;
          }

          /* End of Disable for SubSystem: '<S34>/broken subsystem' */
          Test_DW.Surfacefixed_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Surface fixed' */
  }

  /* Outputs for Enabled SubSystem: '<S7>/Surface fixed' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (Test_DW.Surfacefixed_MODE) {
    /* Logic: '<S34>/NOT' */
    Test_B.NOT_f = !(Test_B.unbroken != 0.0);
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S37>/Enable' */
      Test_B.HiddenBuf_InsertedFor_brokensub = Test_B.NOT_f;

      /* SignalConversion generated from: '<S38>/Enable' */
      Test_B.HiddenBuf_InsertedFor_unbrokens = Test_B.unbroken;

      /* Outputs for Enabled SubSystem: '<S34>/unbroken subsystem' incorporates:
       *  EnablePort: '<S38>/Enable'
       */
      if (rtmIsMajorTimeStep(Test_M)) {
        if (Test_B.HiddenBuf_InsertedFor_unbrokens > 0.0) {
          Test_DW.unbrokensubsystem_MODE = true;
        } else {
          if (Test_DW.unbrokensubsystem_MODE) {
            /* Disable for Enabled SubSystem: '<S38>/Static Friction Behavior' */
            Test_DW.StaticFrictionBehavior_MODE = false;

            /* End of Disable for SubSystem: '<S38>/Static Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S38>/Kinetic Friction Behavior' */
            Test_DW.KineticFrictionBehavior_MODE = false;

            /* End of Disable for SubSystem: '<S38>/Kinetic Friction Behavior' */
            Test_DW.unbrokensubsystem_MODE = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S34>/unbroken subsystem' */
    }

    /* Outputs for Enabled SubSystem: '<S34>/unbroken subsystem' incorporates:
     *  EnablePort: '<S38>/Enable'
     */
    if (Test_DW.unbrokensubsystem_MODE) {
      /* RelationalOperator: '<S38>/LessThanOrEqual' incorporates:
       *  Abs: '<S38>/Abs'
       *  Abs: '<S38>/Abs1'
       */
      Test_B.LessThanOrEqual = (fabs(rtb_Add2) <= fabs(rtb_Gain2));
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S42>/Enable' */
        Test_B.HiddenBuf_InsertedFor_StaticFri = Test_B.LessThanOrEqual;

        /* Outputs for Enabled SubSystem: '<S38>/Static Friction Behavior' incorporates:
         *  EnablePort: '<S42>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          Test_DW.StaticFrictionBehavior_MODE =
            Test_B.HiddenBuf_InsertedFor_StaticFri;
        }

        /* End of Outputs for SubSystem: '<S38>/Static Friction Behavior' */
      }

      /* Outputs for Enabled SubSystem: '<S38>/Static Friction Behavior' incorporates:
       *  EnablePort: '<S42>/Enable'
       */
      if (Test_DW.StaticFrictionBehavior_MODE) {
        /* Product: '<S42>/Product1' incorporates:
         *  Gain: '<S42>/Gain'
         */
        Test_B.Merge4_e = Test_P.Gain_Gain_d * Test_B.y.sens_mechanical_grasper *
          rtb_Add2;
        if (rtmIsMajorTimeStep(Test_M)) {
          /* SignalConversion generated from: '<S42>/grasper_friction_state' incorporates:
           *  Constant: '<S42>/Constant'
           */
          Test_B.Merge4 = Test_P.Constant_Value_l;

          /* SignalConversion generated from: '<S42>/A21' incorporates:
           *  Constant: '<S42>/Constant1'
           */
          Test_B.Merge1_l = Test_P.Constant1_Value_i;

          /* SignalConversion generated from: '<S42>/A22' incorporates:
           *  Constant: '<S42>/Constant1'
           */
          Test_B.Merge2_l = Test_P.Constant1_Value_i;

          /* SignalConversion generated from: '<S42>/B2' incorporates:
           *  Constant: '<S42>/Constant1'
           */
          Test_B.Merge5_e = Test_P.Constant1_Value_i;
        }
      }

      /* End of Outputs for SubSystem: '<S38>/Static Friction Behavior' */

      /* Logic: '<S38>/NOT' */
      Test_B.NOT_k = !Test_B.LessThanOrEqual;
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S41>/Enable' */
        Test_B.HiddenBuf_InsertedFor_KineticFr = Test_B.NOT_k;

        /* Outputs for Enabled SubSystem: '<S38>/Kinetic Friction Behavior' incorporates:
         *  EnablePort: '<S41>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          Test_DW.KineticFrictionBehavior_MODE =
            Test_B.HiddenBuf_InsertedFor_KineticFr;
        }

        /* End of Outputs for SubSystem: '<S38>/Kinetic Friction Behavior' */
      }

      /* Outputs for Enabled SubSystem: '<S38>/Kinetic Friction Behavior' incorporates:
       *  EnablePort: '<S41>/Enable'
       */
      if (Test_DW.KineticFrictionBehavior_MODE) {
        /* Signum: '<S41>/Sign' */
        if (rtb_Add2 < 0.0) {
          rtb_Gain2_m5 = -1.0;
        } else if (rtb_Add2 > 0.0) {
          rtb_Gain2_m5 = 1.0;
        } else if (rtb_Add2 == 0.0) {
          rtb_Gain2_m5 = 0.0;
        } else {
          rtb_Gain2_m5 = (rtNaN);
        }

        /* End of Signum: '<S41>/Sign' */

        /* Product: '<S41>/Product1' incorporates:
         *  Gain: '<S41>/Gain'
         *  Product: '<S41>/Product'
         */
        off_thresh = Test_B.y.sens_mechanical_grasper * rtb_Gain3 *
          (Test_P.Gain_Gain_e * rtb_Gain2_m5);

        /* Sum: '<S41>/Add' incorporates:
         *  Gain: '<S41>/Gain1'
         */
        Test_B.Merge5_e = x_gh_tmp * off_thresh + on_thresh;

        /* SignalConversion generated from: '<S41>/F_f_g' */
        Test_B.Merge4_e = off_thresh;
        if (rtmIsMajorTimeStep(Test_M)) {
          /* SignalConversion generated from: '<S41>/grasper_friction_state' incorporates:
           *  Constant: '<S41>/Constant'
           */
          Test_B.Merge4 = Test_P.Constant_Value_d;
        }

        /* SignalConversion generated from: '<S41>/A21' incorporates:
         *  Inport: '<S41>/A2'
         */
        Test_B.Merge1_l = rtb_Gain_idx_0;

        /* SignalConversion generated from: '<S41>/A22' incorporates:
         *  Inport: '<S41>/A2'
         */
        Test_B.Merge2_l = rtb_Gain_idx_1;
      }

      /* End of Outputs for SubSystem: '<S38>/Kinetic Friction Behavior' */

      /* Sum: '<S38>/Add' */
      Test_B.Merge6_d = Test_B.Merge4_e + rtb_Add2;

      /* SignalConversion generated from: '<S38>/F_f_g' */
      Test_B.Merge3 = Test_B.Merge4_e;
    }

    /* End of Outputs for SubSystem: '<S34>/unbroken subsystem' */

    /* Outputs for Enabled SubSystem: '<S34>/broken subsystem' incorporates:
     *  EnablePort: '<S37>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M) && rtmIsMajorTimeStep(Test_M)) {
      if (Test_B.HiddenBuf_InsertedFor_brokensub) {
        Test_DW.brokensubsystem_MODE = true;
      } else {
        if (Test_DW.brokensubsystem_MODE) {
          /* Disable for Enabled SubSystem: '<S37>/Kinetic Friction Behavior' */
          if (Test_DW.KineticFrictionBehavior_f.KineticFrictionBehavior_MODE) {
            KineticFrictionBehavior_Disable(&Test_DW.KineticFrictionBehavior_f);
          }

          /* End of Disable for SubSystem: '<S37>/Kinetic Friction Behavior' */

          /* Disable for Enabled SubSystem: '<S37>/Static Friction Behavior' */
          if (Test_DW.StaticFrictionBehavior_i.StaticFrictionBehavior_MODE) {
            StaticFrictionBehavior_Disable(&Test_DW.StaticFrictionBehavior_i);
          }

          /* End of Disable for SubSystem: '<S37>/Static Friction Behavior' */
          Test_DW.brokensubsystem_MODE = false;
        }
      }
    }

    if (Test_DW.brokensubsystem_MODE) {
      /* Inport: '<S37>/F_comb' */
      rtb_F_comb = rtb_Add2;

      /* RelationalOperator: '<S37>/LessThanOrEqual' incorporates:
       *  Abs: '<S37>/Abs'
       *  Abs: '<S37>/Abs1'
       */
      Test_B.LessThanOrEqual_l = (fabs(rtb_F_comb) <= fabs(rtb_Gain2));

      /* Logic: '<S37>/NOT' */
      Test_B.NOT_a = !Test_B.LessThanOrEqual_l;
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S39>/Enable' */
        Test_B.HiddenBuf_InsertedFor_Kinetic_h = Test_B.NOT_a;

        /* SignalConversion generated from: '<S40>/Enable' */
        Test_B.HiddenBuf_InsertedFor_StaticF_n = Test_B.LessThanOrEqual_l;
      }

      /* Outputs for Enabled SubSystem: '<S37>/Kinetic Friction Behavior' */
      Test_KineticFrictionBehavior(Test_M,
        Test_B.HiddenBuf_InsertedFor_Kinetic_h, Test_B.y.sens_mechanical_grasper,
        rtb_F_comb, rtb_Gain3, &Test_B.Merge3, &Test_B.Merge4,
        &Test_DW.KineticFrictionBehavior_f, &Test_P.KineticFrictionBehavior_f);

      /* End of Outputs for SubSystem: '<S37>/Kinetic Friction Behavior' */

      /* Outputs for Enabled SubSystem: '<S37>/Static Friction Behavior' */
      Test_StaticFrictionBehavior(Test_M, Test_B.HiddenBuf_InsertedFor_StaticF_n,
        Test_B.y.sens_mechanical_grasper, rtb_F_comb, &Test_B.Merge3,
        &Test_B.Merge4, &Test_DW.StaticFrictionBehavior_i,
        &Test_P.StaticFrictionBehavior_i);

      /* End of Outputs for SubSystem: '<S37>/Static Friction Behavior' */

      /* SignalConversion generated from: '<S37>/F_g' */
      Test_B.Merge6_d = rtb_F_comb;

      /* SignalConversion generated from: '<S37>/A21' incorporates:
       *  Inport: '<S37>/A2'
       */
      Test_B.Merge1_l = rtb_Gain_idx_0;

      /* SignalConversion generated from: '<S37>/A22' incorporates:
       *  Inport: '<S37>/A2'
       */
      Test_B.Merge2_l = rtb_Gain_idx_1;

      /* Inport: '<S37>/B2_in' */
      Test_B.Merge5_e = on_thresh;
    }

    /* End of Outputs for SubSystem: '<S34>/broken subsystem' */
  }

  /* End of Outputs for SubSystem: '<S7>/Surface fixed' */

  /* Product: '<S9>/Product2' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  DotProduct: '<S9>/Dot Product1'
   *  SignalConversion generated from: '<S9>/Dot Product1'
   *  Sum: '<S9>/Add2'
   */
  rtb_Add2 = ((Test_P.Constant2_Value_p[0] * Test_B.y.x_h +
               Test_P.Constant2_Value_p[1] * Test_B.y.x_g) +
              Test_P.init_obj.x_h_ref) * Test_P.init_obj.K_sp_h;

  /* Sum: '<S11>/Add' */
  rtb_Gain2 = rtb_Add2 + Test_B.Merge3;

  /* Product: '<S10>/Product2' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  DotProduct: '<S10>/Dot Product'
   *  SignalConversion generated from: '<S9>/Dot Product1'
   *  Sum: '<S10>/Add2'
   */
  off_thresh = ((Test_P.Constant2_Value_o[0] * Test_B.y.x_h +
                 Test_P.Constant2_Value_o[1] * Test_B.y.x_g) +
                Test_P.Constant1_Value_jw) * Test_P.init_obj.max_I3ant *
    Test_B.y.P_I3_anterior;

  /* Gain: '<S11>/Gain2' */
  rtb_Gain2_m5 = Test_P.init_obj.mu_s_h * off_thresh;

  /* Gain: '<S11>/Gain3' */
  rtb_Gain3_o = Test_P.init_obj.mu_k_h * off_thresh;

  /* Logic: '<S5>/NOT' */
  Test_B.NOT = !(Test_B.y.fixation_type != 0.0);
  if (rtmIsMajorTimeStep(Test_M)) {
    /* Gain: '<S11>/Gain4' incorporates:
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant3'
     *  Gain: '<S11>/Gain1'
     *  Product: '<S9>/Product1'
     */
    off_thresh = 1.0 / Test_P.init_obj.c_h;
    Test_B.Gain4[0] = Test_P.Constant2_Value_p[0] * Test_P.init_obj.K_sp_h *
      off_thresh;
    Test_B.Gain4[1] = Test_P.Constant2_Value_p[1] * Test_P.init_obj.K_sp_h *
      off_thresh;

    /* Gain: '<S11>/Gain1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant3'
     *  Product: '<S9>/Product3'
     */
    Test_B.Gain1 = off_thresh * (Test_P.init_obj.x_h_ref *
      Test_P.init_obj.K_sp_h);

    /* SignalConversion generated from: '<S8>/Enable' */
    Test_B.HiddenBuf_InsertedFor_Notsurf_d = Test_B.NOT;

    /* Outputs for Enabled SubSystem: '<S5>/Not surface fixed' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      if (Test_B.HiddenBuf_InsertedFor_Notsurf_d) {
        Test_DW.Notsurfacefixed_MODE_m = true;
      } else {
        if (Test_DW.Notsurfacefixed_MODE_m) {
          /* Disable for Enabled SubSystem: '<S8>/Kinetic Friction Behavior' */
          Test_DW.KineticFrictionBehavior_MODE_k = false;

          /* End of Disable for SubSystem: '<S8>/Kinetic Friction Behavior' */

          /* Disable for Enabled SubSystem: '<S8>/Static Friction Behavior' */
          Test_DW.StaticFrictionBehavior_MODE_n = false;

          /* End of Disable for SubSystem: '<S8>/Static Friction Behavior' */
          Test_DW.Notsurfacefixed_MODE_m = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Not surface fixed' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/Not surface fixed' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (Test_DW.Notsurfacefixed_MODE_m) {
    /* RelationalOperator: '<S8>/LessThanOrEqual' incorporates:
     *  Abs: '<S8>/Abs'
     *  Abs: '<S8>/Abs1'
     */
    Test_B.LessThanOrEqual_f = (fabs(rtb_Gain2) <= fabs(rtb_Gain2_m5));

    /* Logic: '<S8>/NOT' */
    Test_B.NOT_n = !Test_B.LessThanOrEqual_f;

    /* Outputs for Enabled SubSystem: '<S8>/Static Friction Behavior' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S13>/Enable' */
      Test_B.HiddenBuf_InsertedFor_Kine_hz3r = Test_B.NOT_n;

      /* SignalConversion generated from: '<S14>/Enable' */
      Test_B.HiddenBuf_InsertedFor_Sta_ngi2y = Test_B.LessThanOrEqual_f;

      /* Outputs for Enabled SubSystem: '<S8>/Kinetic Friction Behavior' incorporates:
       *  EnablePort: '<S13>/Enable'
       */
      if (rtmIsMajorTimeStep(Test_M)) {
        Test_DW.KineticFrictionBehavior_MODE_k =
          Test_B.HiddenBuf_InsertedFor_Kine_hz3r;
      }

      /* End of Outputs for SubSystem: '<S8>/Kinetic Friction Behavior' */
      if (rtmIsMajorTimeStep(Test_M)) {
        Test_DW.StaticFrictionBehavior_MODE_n =
          Test_B.HiddenBuf_InsertedFor_Sta_ngi2y;
      }
    }

    /* End of Outputs for SubSystem: '<S8>/Static Friction Behavior' */

    /* Outputs for Enabled SubSystem: '<S8>/Kinetic Friction Behavior' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if (Test_DW.KineticFrictionBehavior_MODE_k) {
      /* Signum: '<S13>/Sign' */
      if (rtb_Gain2 < 0.0) {
        off_thresh = -1.0;
      } else if (rtb_Gain2 > 0.0) {
        off_thresh = 1.0;
      } else if (rtb_Gain2 == 0.0) {
        off_thresh = 0.0;
      } else {
        off_thresh = (rtNaN);
      }

      /* End of Signum: '<S13>/Sign' */

      /* Product: '<S13>/Product1' incorporates:
       *  Gain: '<S13>/Gain1'
       *  Product: '<S13>/Product'
       */
      Test_B.Merge3_c = Test_B.y.sens_mechanical_grasper * rtb_Gain3_o *
        (Test_P.Gain1_Gain * off_thresh);
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S13>/jaw_friction_state' incorporates:
         *  Constant: '<S13>/Constant'
         */
        Test_B.Merge4_a = Test_P.Constant_Value;
      }
    }

    /* End of Outputs for SubSystem: '<S8>/Kinetic Friction Behavior' */

    /* Outputs for Enabled SubSystem: '<S8>/Static Friction Behavior' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    if (Test_DW.StaticFrictionBehavior_MODE_n) {
      /* Product: '<S14>/Product' incorporates:
       *  Gain: '<S14>/Gain'
       */
      Test_B.Merge3_c = Test_P.Gain_Gain * Test_B.y.sens_mechanical_grasper *
        rtb_Gain2;
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S14>/jaw_friction_state' incorporates:
         *  Constant: '<S14>/Constant'
         */
        Test_B.Merge4_a = Test_P.Constant_Value_c;
      }
    }

    /* End of Outputs for SubSystem: '<S8>/Static Friction Behavior' */
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S8>/A11' incorporates:
       *  Inport: '<S8>/A1'
       */
      Test_B.Merge1 = Test_B.Gain4[0];

      /* SignalConversion generated from: '<S8>/A12' incorporates:
       *  Inport: '<S8>/A1'
       */
      Test_B.Merge2 = Test_B.Gain4[1];

      /* Inport: '<S8>/B1_in' */
      Test_B.Merge5 = Test_B.Gain1;
    }

    /* Inport: '<S8>/F_sp_h' */
    Test_B.Merge6 = rtb_Add2;
  }

  /* End of Outputs for SubSystem: '<S5>/Not surface fixed' */
  if (rtmIsMajorTimeStep(Test_M)) {
    /* SignalConversion generated from: '<S12>/Enable' */
    Test_B.HiddenBuf_InsertedFor_Surface_o = Test_B.y.fixation_type;

    /* Outputs for Enabled SubSystem: '<S5>/Surface fixed' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      if (Test_B.HiddenBuf_InsertedFor_Surface_o > 0.0) {
        Test_DW.Surfacefixed_MODE_b = true;
      } else {
        if (Test_DW.Surfacefixed_MODE_b) {
          /* Disable for Enabled SubSystem: '<S12>/unbroken subsystem' */
          if (Test_DW.unbrokensubsystem_MODE_e) {
            /* Disable for Enabled SubSystem: '<S16>/Static Friction Behavior' */
            Test_DW.StaticFrictionBehavior_MODE_m = false;

            /* End of Disable for SubSystem: '<S16>/Static Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S16>/Kinetic Friction Behavior' */
            if (Test_DW.KineticFrictionBehavior_MODE_a) {
              /* Disable for Enabled SubSystem: '<S19>/Kinetic Grasper' */
              Test_DW.KineticGrasper_MODE = false;

              /* End of Disable for SubSystem: '<S19>/Kinetic Grasper' */

              /* Disable for Enabled SubSystem: '<S19>/Static Grasper' */
              Test_DW.StaticGrasper_MODE = false;

              /* End of Disable for SubSystem: '<S19>/Static Grasper' */
              Test_DW.KineticFrictionBehavior_MODE_a = false;
            }

            /* End of Disable for SubSystem: '<S16>/Kinetic Friction Behavior' */
            Test_DW.unbrokensubsystem_MODE_e = false;
          }

          /* End of Disable for SubSystem: '<S12>/unbroken subsystem' */

          /* Disable for Enabled SubSystem: '<S12>/broken subsystem' */
          if (Test_DW.brokensubsystem_MODE_p) {
            /* Disable for Enabled SubSystem: '<S15>/Kinetic Friction Behavior' */
            Test_DW.KineticFrictionBehavior_MODE_p = false;

            /* End of Disable for SubSystem: '<S15>/Kinetic Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S15>/Static Friction Behavior' */
            Test_DW.StaticFrictionBehavior_MODE_k = false;

            /* End of Disable for SubSystem: '<S15>/Static Friction Behavior' */
            Test_DW.brokensubsystem_MODE_p = false;
          }

          /* End of Disable for SubSystem: '<S12>/broken subsystem' */
          Test_DW.Surfacefixed_MODE_b = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Surface fixed' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/Surface fixed' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (Test_DW.Surfacefixed_MODE_b) {
    /* Logic: '<S12>/NOT' */
    Test_B.NOT_j = !(Test_B.unbroken != 0.0);

    /* Outputs for Enabled SubSystem: '<S12>/broken subsystem' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S15>/Enable' */
      Test_B.HiddenBuf_InsertedFor_brokens_e = Test_B.NOT_j;

      /* SignalConversion generated from: '<S16>/Enable' */
      Test_B.HiddenBuf_InsertedFor_unbroke_l = Test_B.unbroken;

      /* Outputs for Enabled SubSystem: '<S12>/unbroken subsystem' incorporates:
       *  EnablePort: '<S16>/Enable'
       */
      if (rtmIsMajorTimeStep(Test_M)) {
        if (Test_B.HiddenBuf_InsertedFor_unbroke_l > 0.0) {
          Test_DW.unbrokensubsystem_MODE_e = true;
        } else {
          if (Test_DW.unbrokensubsystem_MODE_e) {
            /* Disable for Enabled SubSystem: '<S16>/Static Friction Behavior' */
            Test_DW.StaticFrictionBehavior_MODE_m = false;

            /* End of Disable for SubSystem: '<S16>/Static Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S16>/Kinetic Friction Behavior' */
            if (Test_DW.KineticFrictionBehavior_MODE_a) {
              /* Disable for Enabled SubSystem: '<S19>/Kinetic Grasper' */
              Test_DW.KineticGrasper_MODE = false;

              /* End of Disable for SubSystem: '<S19>/Kinetic Grasper' */

              /* Disable for Enabled SubSystem: '<S19>/Static Grasper' */
              Test_DW.StaticGrasper_MODE = false;

              /* End of Disable for SubSystem: '<S19>/Static Grasper' */
              Test_DW.KineticFrictionBehavior_MODE_a = false;
            }

            /* End of Disable for SubSystem: '<S16>/Kinetic Friction Behavior' */
            Test_DW.unbrokensubsystem_MODE_e = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S12>/unbroken subsystem' */
      if (rtmIsMajorTimeStep(Test_M)) {
        if (Test_B.HiddenBuf_InsertedFor_brokens_e) {
          Test_DW.brokensubsystem_MODE_p = true;
        } else {
          if (Test_DW.brokensubsystem_MODE_p) {
            /* Disable for Enabled SubSystem: '<S15>/Kinetic Friction Behavior' */
            Test_DW.KineticFrictionBehavior_MODE_p = false;

            /* End of Disable for SubSystem: '<S15>/Kinetic Friction Behavior' */

            /* Disable for Enabled SubSystem: '<S15>/Static Friction Behavior' */
            Test_DW.StaticFrictionBehavior_MODE_k = false;

            /* End of Disable for SubSystem: '<S15>/Static Friction Behavior' */
            Test_DW.brokensubsystem_MODE_p = false;
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S12>/broken subsystem' */

    /* Outputs for Enabled SubSystem: '<S12>/unbroken subsystem' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (Test_DW.unbrokensubsystem_MODE_e) {
      /* RelationalOperator: '<S16>/LessThanOrEqual' incorporates:
       *  Abs: '<S16>/Abs'
       *  Abs: '<S16>/Abs1'
       */
      Test_B.LessThanOrEqual_h = (fabs(rtb_Gain2) <= fabs(rtb_Gain2_m5));
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S20>/Enable' */
        Test_B.HiddenBuf_InsertedFor_Stati_ngi = Test_B.LessThanOrEqual_h;

        /* Outputs for Enabled SubSystem: '<S16>/Static Friction Behavior' incorporates:
         *  EnablePort: '<S20>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          Test_DW.StaticFrictionBehavior_MODE_m =
            Test_B.HiddenBuf_InsertedFor_Stati_ngi;
        }

        /* End of Outputs for SubSystem: '<S16>/Static Friction Behavior' */
      }

      /* Outputs for Enabled SubSystem: '<S16>/Static Friction Behavior' incorporates:
       *  EnablePort: '<S20>/Enable'
       */
      if (Test_DW.StaticFrictionBehavior_MODE_m) {
        /* Product: '<S20>/Product1' incorporates:
         *  Gain: '<S20>/Gain'
         */
        Test_B.Merge3_d = Test_P.Gain_Gain_f * Test_B.y.sens_mechanical_grasper *
          rtb_Gain2;
        if (rtmIsMajorTimeStep(Test_M)) {
          /* SignalConversion generated from: '<S20>/jaw_friction_state' incorporates:
           *  Constant: '<S20>/Constant'
           */
          Test_B.Merge4_a = Test_P.Constant_Value_j;

          /* SignalConversion generated from: '<S20>/A11' incorporates:
           *  Constant: '<S20>/Constant1'
           */
          Test_B.Merge1 = Test_P.Constant1_Value;

          /* SignalConversion generated from: '<S20>/A12' incorporates:
           *  Constant: '<S20>/Constant1'
           */
          Test_B.Merge2 = Test_P.Constant1_Value;

          /* SignalConversion generated from: '<S20>/B1' incorporates:
           *  Constant: '<S20>/Constant1'
           */
          Test_B.Merge5 = Test_P.Constant1_Value;
        }
      }

      /* End of Outputs for SubSystem: '<S16>/Static Friction Behavior' */

      /* Logic: '<S16>/NOT' */
      Test_B.NOT_fk = !Test_B.LessThanOrEqual_h;
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S19>/Enable' */
        Test_B.HiddenBuf_InsertedFor_Kinetic_a = Test_B.NOT_fk;

        /* Outputs for Enabled SubSystem: '<S16>/Kinetic Friction Behavior' incorporates:
         *  EnablePort: '<S19>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          if (Test_B.HiddenBuf_InsertedFor_Kinetic_a) {
            Test_DW.KineticFrictionBehavior_MODE_a = true;
          } else {
            if (Test_DW.KineticFrictionBehavior_MODE_a) {
              /* Disable for Enabled SubSystem: '<S19>/Kinetic Grasper' */
              Test_DW.KineticGrasper_MODE = false;

              /* End of Disable for SubSystem: '<S19>/Kinetic Grasper' */

              /* Disable for Enabled SubSystem: '<S19>/Static Grasper' */
              Test_DW.StaticGrasper_MODE = false;

              /* End of Disable for SubSystem: '<S19>/Static Grasper' */
              Test_DW.KineticFrictionBehavior_MODE_a = false;
            }
          }
        }

        /* End of Outputs for SubSystem: '<S16>/Kinetic Friction Behavior' */
      }

      /* Outputs for Enabled SubSystem: '<S16>/Kinetic Friction Behavior' incorporates:
       *  EnablePort: '<S19>/Enable'
       */
      if (Test_DW.KineticFrictionBehavior_MODE_a) {
        /* Signum: '<S19>/Sign' */
        if (rtb_Gain2 < 0.0) {
          off_thresh = -1.0;
        } else if (rtb_Gain2 > 0.0) {
          off_thresh = 1.0;
        } else if (rtb_Gain2 == 0.0) {
          off_thresh = 0.0;
        } else {
          off_thresh = (rtNaN);
        }

        /* End of Signum: '<S19>/Sign' */

        /* Gain: '<S19>/Gain' */
        off_thresh *= Test_P.Gain_Gain_g;

        /* Product: '<S19>/Product1' incorporates:
         *  Constant: '<S10>/Constant2'
         *  Constant: '<S10>/Constant3'
         *  Gain: '<S19>/Gain1'
         *  Product: '<S10>/Product1'
         */
        rtb_TmpSignalConversionAtDotP_0 = Test_P.init_obj.max_I3ant *
          Test_P.Constant2_Value_o[0] * Test_B.y.P_I3_anterior *
          Test_P.init_obj.mu_k_h * off_thresh * Test_B.y.sens_mechanical_grasper;
        rtb_TmpSignalConversionAtDotP_1 = Test_P.init_obj.max_I3ant *
          Test_P.Constant2_Value_o[1] * Test_B.y.P_I3_anterior *
          Test_P.init_obj.mu_k_h * off_thresh * Test_B.y.sens_mechanical_grasper;

        /* Product: '<S19>/Product2' incorporates:
         *  Constant: '<S10>/Constant1'
         *  Constant: '<S10>/Constant3'
         *  Gain: '<S19>/Gain2'
         *  Product: '<S10>/Product3'
         */
        rtb_Product2_n = Test_P.init_obj.max_I3ant * Test_P.Constant1_Value_jw *
          Test_B.y.P_I3_anterior * Test_P.init_obj.mu_k_h * off_thresh *
          Test_B.y.sens_mechanical_grasper;

        /* Outputs for Enabled SubSystem: '<S19>/Static Grasper' incorporates:
         *  EnablePort: '<S22>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          /* Logic: '<S19>/NOT' */
          Test_B.NOT_g = !(Test_B.Merge4 != 0.0);

          /* Outputs for Enabled SubSystem: '<S19>/Kinetic Grasper' incorporates:
           *  EnablePort: '<S21>/Enable'
           */
          if (rtmIsMajorTimeStep(Test_M)) {
            Test_DW.KineticGrasper_MODE = Test_B.NOT_g;
          }

          /* End of Outputs for SubSystem: '<S19>/Kinetic Grasper' */
          if (rtmIsMajorTimeStep(Test_M)) {
            Test_DW.StaticGrasper_MODE = (Test_B.Merge4 > 0.0);
          }
        }

        /* End of Outputs for SubSystem: '<S19>/Static Grasper' */

        /* Outputs for Enabled SubSystem: '<S19>/Kinetic Grasper' incorporates:
         *  EnablePort: '<S21>/Enable'
         */
        if (Test_DW.KineticGrasper_MODE) {
          /* Gain: '<S21>/Gain2' */
          x_gh = 1.0 / Test_P.init_obj.c_h;

          /* Sum: '<S21>/Add1' incorporates:
           *  Gain: '<S21>/Gain2'
           */
          Test_B.Merge5_c[0] = x_gh * rtb_TmpSignalConversionAtDotP_0 +
            Test_B.Gain4[0];
          Test_B.Merge5_c[1] = x_gh * rtb_TmpSignalConversionAtDotP_1 +
            Test_B.Gain4[1];

          /* Sum: '<S21>/Add' */
          rtb_Clock = (rtb_Gain2 - rtb_Clock) - rtb_Abs1_0;

          /* Signum: '<S21>/Sign' */
          if (rtb_Clock < 0.0) {
            rtb_Clock = -1.0;
          } else if (rtb_Clock > 0.0) {
            rtb_Clock = 1.0;
          } else if (rtb_Clock == 0.0) {
            rtb_Clock = 0.0;
          } else {
            rtb_Clock = (rtNaN);
          }

          /* End of Signum: '<S21>/Sign' */

          /* Sum: '<S21>/Add3' incorporates:
           *  Gain: '<S21>/Gain'
           *  Gain: '<S21>/Gain1'
           *  Product: '<S21>/Product'
           *  Sum: '<S21>/Add2'
           */
          Test_B.Merge5 = (Test_P.Gain_Gain_c * rtb_Clock *
                           Test_B.y.sens_mechanical_grasper * rtb_Gain3_tmp +
                           rtb_Product2_n) * (1.0 / Test_P.init_obj.c_h) +
            Test_B.Gain1;
        }

        /* End of Outputs for SubSystem: '<S19>/Kinetic Grasper' */

        /* Outputs for Enabled SubSystem: '<S19>/Static Grasper' incorporates:
         *  EnablePort: '<S22>/Enable'
         */
        if (Test_DW.StaticGrasper_MODE) {
          /* Gain: '<S22>/Gain1' */
          rtb_Abs1_0 = Test_P.Gain1_Gain_j * Test_B.y.sens_mechanical_grasper;

          /* Gain: '<S22>/Gain2' */
          x_gh = 1.0 / Test_P.init_obj.c_h;

          /* Sum: '<S22>/Add1' incorporates:
           *  Gain: '<S22>/Gain'
           *  Gain: '<S22>/Gain2'
           *  Product: '<S22>/Product'
           *  Sum: '<S22>/Add'
           */
          Test_B.Merge5_c[0] = (Test_P.init_obj.c_g * rtb_Gain_idx_0 *
                                rtb_Abs1_0 + rtb_TmpSignalConversionAtDotP_0) *
            x_gh + Test_B.Gain4[0];
          Test_B.Merge5_c[1] = (Test_P.init_obj.c_g * rtb_Gain_idx_1 *
                                rtb_Abs1_0 + rtb_TmpSignalConversionAtDotP_1) *
            x_gh + Test_B.Gain4[1];

          /* Sum: '<S22>/Add3' incorporates:
           *  Gain: '<S22>/Gain3'
           *  Gain: '<S22>/Gain4'
           *  Product: '<S22>/Product1'
           *  Sum: '<S22>/Add2'
           */
          Test_B.Merge5 = (Test_P.init_obj.c_g * on_thresh * rtb_Abs1_0 +
                           rtb_Product2_n) * (1.0 / Test_P.init_obj.c_h) +
            Test_B.Gain1;
        }

        /* End of Outputs for SubSystem: '<S19>/Static Grasper' */

        /* SignalConversion generated from: '<S19>/A11' */
        Test_B.Merge1 = Test_B.Merge5_c[0];

        /* SignalConversion generated from: '<S19>/A12' */
        Test_B.Merge2 = Test_B.Merge5_c[1];

        /* Product: '<S19>/Product' */
        Test_B.Merge3_d = Test_B.y.sens_mechanical_grasper * rtb_Gain3_o *
          off_thresh;
        if (rtmIsMajorTimeStep(Test_M)) {
          /* SignalConversion generated from: '<S19>/jaw_friction_state' incorporates:
           *  Constant: '<S19>/Constant'
           */
          Test_B.Merge4_a = Test_P.Constant_Value_p;
        }
      }

      /* End of Outputs for SubSystem: '<S16>/Kinetic Friction Behavior' */

      /* Sum: '<S16>/Add' incorporates:
       *  Sum: '<S12>/Add'
       */
      Test_B.Merge6 = (rtb_Add2 - Test_B.Merge3) + Test_B.Merge3_d;

      /* SignalConversion generated from: '<S16>/F_f_h' */
      Test_B.Merge3_c = Test_B.Merge3_d;
    }

    /* End of Outputs for SubSystem: '<S12>/unbroken subsystem' */

    /* Outputs for Enabled SubSystem: '<S12>/broken subsystem' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    if (Test_DW.brokensubsystem_MODE_p) {
      /* RelationalOperator: '<S15>/LessThanOrEqual' incorporates:
       *  Abs: '<S15>/Abs'
       *  Abs: '<S15>/Abs1'
       */
      Test_B.LessThanOrEqual_b = (fabs(rtb_Gain2) <= fabs(rtb_Gain2_m5));

      /* Logic: '<S15>/NOT' */
      Test_B.NOT_h = !Test_B.LessThanOrEqual_b;

      /* Outputs for Enabled SubSystem: '<S15>/Static Friction Behavior' incorporates:
       *  EnablePort: '<S18>/Enable'
       */
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S17>/Enable' */
        Test_B.HiddenBuf_InsertedFor_Kinet_hz3 = Test_B.NOT_h;

        /* SignalConversion generated from: '<S18>/Enable' */
        Test_B.HiddenBuf_InsertedFor_Stat_ngi2 = Test_B.LessThanOrEqual_b;

        /* Outputs for Enabled SubSystem: '<S15>/Kinetic Friction Behavior' incorporates:
         *  EnablePort: '<S17>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          Test_DW.KineticFrictionBehavior_MODE_p =
            Test_B.HiddenBuf_InsertedFor_Kinet_hz3;
        }

        /* End of Outputs for SubSystem: '<S15>/Kinetic Friction Behavior' */
        if (rtmIsMajorTimeStep(Test_M)) {
          Test_DW.StaticFrictionBehavior_MODE_k =
            Test_B.HiddenBuf_InsertedFor_Stat_ngi2;
        }
      }

      /* End of Outputs for SubSystem: '<S15>/Static Friction Behavior' */

      /* Outputs for Enabled SubSystem: '<S15>/Kinetic Friction Behavior' incorporates:
       *  EnablePort: '<S17>/Enable'
       */
      if (Test_DW.KineticFrictionBehavior_MODE_p) {
        /* Signum: '<S17>/Sign' */
        if (rtb_Gain2 < 0.0) {
          off_thresh = -1.0;
        } else if (rtb_Gain2 > 0.0) {
          off_thresh = 1.0;
        } else if (rtb_Gain2 == 0.0) {
          off_thresh = 0.0;
        } else {
          off_thresh = (rtNaN);
        }

        /* End of Signum: '<S17>/Sign' */

        /* Product: '<S17>/Product1' incorporates:
         *  Gain: '<S17>/Gain1'
         *  Product: '<S17>/Product'
         */
        Test_B.Merge3_c = Test_B.y.sens_mechanical_grasper * rtb_Gain3_o *
          (Test_P.Gain1_Gain_g * off_thresh);
        if (rtmIsMajorTimeStep(Test_M)) {
          /* SignalConversion generated from: '<S17>/jaw_friction_state' incorporates:
           *  Constant: '<S17>/Constant'
           */
          Test_B.Merge4_a = Test_P.Constant_Value_cb;
        }
      }

      /* End of Outputs for SubSystem: '<S15>/Kinetic Friction Behavior' */

      /* Outputs for Enabled SubSystem: '<S15>/Static Friction Behavior' incorporates:
       *  EnablePort: '<S18>/Enable'
       */
      if (Test_DW.StaticFrictionBehavior_MODE_k) {
        /* Product: '<S18>/Product' incorporates:
         *  Gain: '<S18>/Gain'
         */
        Test_B.Merge3_c = Test_P.Gain_Gain_a * Test_B.y.sens_mechanical_grasper *
          rtb_Gain2;
        if (rtmIsMajorTimeStep(Test_M)) {
          /* SignalConversion generated from: '<S18>/jaw_friction_state' incorporates:
           *  Constant: '<S18>/Constant'
           */
          Test_B.Merge4_a = Test_P.Constant_Value_c1;
        }
      }

      /* End of Outputs for SubSystem: '<S15>/Static Friction Behavior' */
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S15>/A11' incorporates:
         *  Inport: '<S15>/A1'
         */
        Test_B.Merge1 = Test_B.Gain4[0];

        /* SignalConversion generated from: '<S15>/A12' incorporates:
         *  Inport: '<S15>/A1'
         */
        Test_B.Merge2 = Test_B.Gain4[1];

        /* Inport: '<S15>/B1_in' */
        Test_B.Merge5 = Test_B.Gain1;
      }

      /* Inport: '<S15>/F_sp_h' */
      Test_B.Merge6 = rtb_Add2;
    }

    /* End of Outputs for SubSystem: '<S12>/broken subsystem' */
  }

  /* End of Outputs for SubSystem: '<S5>/Surface fixed' */

  /* Sum: '<S4>/Add' */
  rtb_Clock = Test_B.Merge3 + Test_B.Merge3_c;
  if (rtmIsMajorTimeStep(Test_M)) {
    /* SignalConversion generated from: '<S6>/Enable' */
    Test_B.HiddenBuf_InsertedFor_EnabledSu = Test_B.y.fixation_type;

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (rtmIsMajorTimeStep(Test_M)) {
      if (Test_B.HiddenBuf_InsertedFor_EnabledSu > 0.0) {
        Test_DW.EnabledSubsystem_MODE = true;
      } else {
        if (Test_DW.EnabledSubsystem_MODE) {
          /* Disable for Enabled SubSystem: '<S6>/Enabled Subsystem' */
          if (Test_DW.EnabledSubsystem_o.EnabledSubsystem_MODE) {
            Test_EnabledSubsystem_Disable(&Test_DW.EnabledSubsystem_o);
          }

          /* End of Disable for SubSystem: '<S6>/Enabled Subsystem' */

          /* Disable for Enabled SubSystem: '<S6>/Enabled Subsystem1' */
          if (Test_DW.EnabledSubsystem1_MODE) {
            /* Disable for Enabled SubSystem: '<S24>/Enabled Subsystem' */
            if (Test_DW.EnabledSubsystem_n.EnabledSubsystem_MODE) {
              Test_EnabledSubsystem_Disable(&Test_DW.EnabledSubsystem_n);
            }

            /* End of Disable for SubSystem: '<S24>/Enabled Subsystem' */

            /* Disable for Enabled SubSystem: '<S24>/Enabled Subsystem1' */
            Test_DW.EnabledSubsystem1_MODE_d = false;

            /* End of Disable for SubSystem: '<S24>/Enabled Subsystem1' */
            Test_DW.EnabledSubsystem1_MODE = false;
          }

          /* End of Disable for SubSystem: '<S6>/Enabled Subsystem1' */
          Test_DW.EnabledSubsystem_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  }

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (Test_DW.EnabledSubsystem_MODE) {
    /* Logic: '<S6>/AND' incorporates:
     *  RelationalOperator: '<S6>/Less Than1'
     *  Sum: '<S4>/Add1'
     *  Sum: '<S6>/Add'
     */
    rtb_AND = false;

    /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
    Test_EnabledSubsystem(Test_M, rtb_AND, &Test_B.Merge,
                          &Test_DW.EnabledSubsystem_o,
                          &Test_P.EnabledSubsystem_o);

    /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */

    /* RelationalOperator: '<S6>/GreaterThan' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_GreaterThan = (rtb_Clock > Test_P.init_obj.seaweed_strength);

    /* Logic: '<S6>/NOT1' */
    Test_B.NOT1_d = !rtb_AND;
    if (rtmIsMajorTimeStep(Test_M)) {
      /* SignalConversion generated from: '<S24>/Enable' */
      Test_B.HiddenBuf_InsertedFor_Enabled_g = Test_B.NOT1_d;

      /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem1' incorporates:
       *  EnablePort: '<S24>/Enable'
       */
      if (rtmIsMajorTimeStep(Test_M)) {
        if (Test_B.HiddenBuf_InsertedFor_Enabled_g) {
          Test_DW.EnabledSubsystem1_MODE = true;
        } else {
          if (Test_DW.EnabledSubsystem1_MODE) {
            /* Disable for Enabled SubSystem: '<S24>/Enabled Subsystem' */
            if (Test_DW.EnabledSubsystem_n.EnabledSubsystem_MODE) {
              Test_EnabledSubsystem_Disable(&Test_DW.EnabledSubsystem_n);
            }

            /* End of Disable for SubSystem: '<S24>/Enabled Subsystem' */

            /* Disable for Enabled SubSystem: '<S24>/Enabled Subsystem1' */
            Test_DW.EnabledSubsystem1_MODE_d = false;

            /* End of Disable for SubSystem: '<S24>/Enabled Subsystem1' */
            Test_DW.EnabledSubsystem1_MODE = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem1' */
    }

    /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S24>/Enable'
     */
    if (Test_DW.EnabledSubsystem1_MODE) {
      /* Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' */
      Test_EnabledSubsystem(Test_M, rtb_GreaterThan, &Test_B.Merge,
                            &Test_DW.EnabledSubsystem_n,
                            &Test_P.EnabledSubsystem_n);

      /* End of Outputs for SubSystem: '<S24>/Enabled Subsystem' */

      /* Logic: '<S24>/NOT' */
      Test_B.NOT_b = !rtb_GreaterThan;
      if (rtmIsMajorTimeStep(Test_M)) {
        /* SignalConversion generated from: '<S26>/Enable' */
        Test_B.HiddenBuf_InsertedFor_Enabled_p = Test_B.NOT_b;

        /* Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem1' incorporates:
         *  EnablePort: '<S26>/Enable'
         */
        if (rtmIsMajorTimeStep(Test_M)) {
          Test_DW.EnabledSubsystem1_MODE_d =
            Test_B.HiddenBuf_InsertedFor_Enabled_p;
        }

        /* End of Outputs for SubSystem: '<S24>/Enabled Subsystem1' */
      }

      /* Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem1' incorporates:
       *  EnablePort: '<S26>/Enable'
       */
      if (Test_DW.EnabledSubsystem1_MODE_d) {
        /* Inport: '<S26>/unbroken_in' */
        Test_B.Merge = Test_B.unbroken;
      }

      /* End of Outputs for SubSystem: '<S24>/Enabled Subsystem1' */
    }

    /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem1' */
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */

  /* BusAssignment: '<S1>/Bus Assignment' incorporates:
   *  Integrator: '<S4>/Integrator10'
   *  Integrator: '<S4>/Integrator11'
   */
  Test_B.BusAssignment = Test_B.y;
  Test_B.BusAssignment.x_g = Test_X.Integrator11_CSTATE;
  Test_B.BusAssignment.x_h = Test_X.Integrator10_CSTATE;
  Test_B.BusAssignment.force_on_object = rtb_Clock;
  Test_B.BusAssignment.unbroken = Test_B.Merge;
  Test_B.BusAssignment.jaw_friction_state = Test_B.Merge4_a;
  Test_B.BusAssignment.grasper_friction_state = Test_B.Merge4;
  if (rtmIsMajorTimeStep(Test_M)) {
  }

  /* Gain: '<S4>/Gain1' */
  Test_B.Gain1_b = x_gh_tmp * Test_B.Merge6_d;

  /* Gain: '<S4>/Gain2' */
  Test_B.Gain2 = 1.0 / Test_P.init_obj.c_h * Test_B.Merge6;
  if (rtmIsMajorTimeStep(Test_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Test_M->rtwLogInfo, (Test_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Test_M)) {
    if (rtmIsMajorTimeStep(Test_M)) {
      /* Update for UnitDelay: '<Root>/Unit Delay' */
      Test_DW.UnitDelay_DSTATE = Test_B.BusAssignment;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Test_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Test_M)!=-1) &&
          !((rtmGetTFinal(Test_M)-(((Test_M->Timing.clockTick1+
               Test_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((Test_M->Timing.clockTick1+Test_M->Timing.clockTickH1*
               4294967296.0)) * 0.005) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Test_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Test_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Test_M->Timing.clockTick0)) {
      ++Test_M->Timing.clockTickH0;
    }

    Test_M->Timing.t[0] = rtsiGetSolverStopTime(&Test_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Test_M->Timing.clockTick1++;
      if (!Test_M->Timing.clockTick1) {
        Test_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Test_derivatives(void)
{
  XDot_Test_T *_rtXdot;
  _rtXdot = ((XDot_Test_T *) Test_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = Test_B.Gain1_b;

  /* Derivatives for Integrator: '<S4>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = Test_B.Gain2;
}

/* Model initialize function */
void Test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Test_M, 0,
                sizeof(RT_MODEL_Test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Test_M->solverInfo, &Test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Test_M->solverInfo, &rtmGetTPtr(Test_M));
    rtsiSetStepSizePtr(&Test_M->solverInfo, &Test_M->Timing.stepSize0);
    rtsiSetdXPtr(&Test_M->solverInfo, &Test_M->derivs);
    rtsiSetContStatesPtr(&Test_M->solverInfo, (real_T **) &Test_M->contStates);
    rtsiSetNumContStatesPtr(&Test_M->solverInfo, &Test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Test_M->solverInfo,
      &Test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Test_M->solverInfo,
      &Test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Test_M->solverInfo,
      &Test_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Test_M->solverInfo, (&rtmGetErrorStatus(Test_M)));
    rtsiSetRTModelPtr(&Test_M->solverInfo, Test_M);
  }

  rtsiSetSimTimeStep(&Test_M->solverInfo, MAJOR_TIME_STEP);
  Test_M->intgData.y = Test_M->odeY;
  Test_M->intgData.f[0] = Test_M->odeF[0];
  Test_M->intgData.f[1] = Test_M->odeF[1];
  Test_M->intgData.f[2] = Test_M->odeF[2];
  Test_M->contStates = ((X_Test_T *) &Test_X);
  rtsiSetSolverData(&Test_M->solverInfo, (void *)&Test_M->intgData);
  rtsiSetSolverName(&Test_M->solverInfo,"ode3");
  rtmSetTPtr(Test_M, &Test_M->Timing.tArray[0]);
  rtmSetTFinal(Test_M, 10.0);
  Test_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Test_M->rtwLogInfo, (NULL));
    rtliSetLogT(Test_M->rtwLogInfo, "tout");
    rtliSetLogX(Test_M->rtwLogInfo, "");
    rtliSetLogXFinal(Test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Test_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Test_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Test_M->rtwLogInfo, 1);
    rtliSetLogY(Test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Test_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Test_B), 0,
                sizeof(B_Test_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Test_X, 0,
                  sizeof(X_Test_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Test_DW, 0,
                sizeof(DW_Test_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Test_M->rtwLogInfo, 0.0, rtmGetTFinal(Test_M),
    Test_M->Timing.stepSize0, (&rtmGetErrorStatus(Test_M)));

  {
    static const AplysiaBus tmp = { 0.0,/* TimeStep */
      0.0,                             /* StartingTime */
      0.0,                             /* EndTime */
      0.0,                             /* max_I4 */
      0.0,                             /* max_I3ant */
      0.0,                             /* max_I3 */
      0.0,                             /* max_I2 */
      0.0,                             /* max_hinge */
      0.0,                             /* tau_I4 */
      0.0,                             /* tau_I3anterior */
      0.0,                             /* tau_I2_ingestion */
      0.0,                             /* tau_I2_egestion */
      0.0,                             /* tau_I3 */
      0.0,                             /* tau_hinge */
      0.0,                             /* c_g */
      0.0,                             /* c_h */
      0.0,                             /* K_sp_h */
      0.0,                             /* K_sp_g */
      0.0,                             /* x_h_ref */
      0.0,                             /* x_gh_ref */
      0.0,                             /* mu_s_g */
      0.0,                             /* mu_k_g */
      0.0,                             /* mu_s_h */
      0.0,                             /* mu_k_h */
      0.0,                             /* thresh_B64_bite_protract */
      0.0,                             /* thresh_B64_swallow_protract */
      0.0,                             /* thresh_B64_reject_protract */
      0.0,                             /* thresh_B4B5_protract */
      0.0,                             /* thresh_B31_bite_off */
      0.0,                             /* thresh_B31_swallow_off */
      0.0,                             /* thresh_B31_reject_off */
      0.0,                             /* thresh_B31_bite_on */
      0.0,                             /* thresh_B31_swallow_on */
      0.0,                             /* thresh_B31_reject_on */
      0.0,                             /* thresh_B7_bite_protract */
      0.0,                             /* thresh_B7_reject_protract */
      0.0,                             /* thresh_B6B9B3_bite_pressure */
      0.0,                             /* thresh_B6B9B3_swallow_pressure */
      0.0,                             /* thresh_B6B9B3_reject_pressure */
      0.0,                             /* thresh_B38_retract */
      0.0,                             /* MCC */
      0.0,                             /* CBI2 */
      0.0,                             /* CBI3 */
      0.0,                             /* CBI4 */
      0.0,                             /* B64 */
      0.0,                             /* B4B5 */
      0.0,                             /* B40B30 */
      0.0,                             /* B31B32 */
      0.0,                             /* B6B9B3 */
      0.0,                             /* B8 */
      0.0,                             /* B7 */
      0.0,                             /* B38 */
      0.0,                             /* B20 */
      0.0,                             /* refractory_CBI3 */
      0.0,                             /* postActivityExcitation_B40B30 */
      0.0,                             /* P_I4 */
      0.0,                             /* A_I4 */
      0.0,                             /* P_I3_anterior */
      0.0,                             /* A_I3_anterior */
      0.0,                             /* T_I3 */
      0.0,                             /* A_I3 */
      0.0,                             /* T_I2 */
      0.0,                             /* A_I2 */
      0.0,                             /* T_hinge */
      0.0,                             /* A_hinge */
      0.0,                             /* x_h */
      0.0,                             /* x_g */
      0.0,                             /* grasper_friction_state */
      0.0,                             /* jaw_friction_state */
      0.0,                             /* seaweed_strength */
      0.0,                             /* fixation_type */
      0.0,                             /* force_on_object */
      0.0,                             /* sens_chemical_lips */
      0.0,                             /* sens_mechanical_lips */
      0.0,                             /* sens_mechanical_grasper */
      0.0,                             /* use_hypothesized_connections */
      0.0,                             /* stim_B4B5 */
      0.0,                             /* stim_CBI2 */
      0.0,                             /* CBI3_stimON */
      0.0,                             /* CBI3_stimOFF */
      0.0,                             /* CBI3_refractory */
      0.0,                             /* B40B30_offTime */
      0.0,                             /* unbroken */
      0.0,                             /* switchBehavior */
      0.0,                             /* behavior_1 */
      0.0,                             /* behavior_2 */
      0.0                              /* t_switch */
    };

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    Test_DW.UnitDelay_DSTATE = tmp;
    Test_DW.UnitDelay_DSTATE.A_I2 = Test_P.init_obj.A_I2;
    Test_DW.UnitDelay_DSTATE.A_I3 = Test_P.init_obj.A_I3;
    Test_DW.UnitDelay_DSTATE.A_I3_anterior = Test_P.init_obj.A_I3_anterior;
    Test_DW.UnitDelay_DSTATE.A_I4 = Test_P.init_obj.A_I4;
    Test_DW.UnitDelay_DSTATE.A_hinge = Test_P.init_obj.A_hinge;
    Test_DW.UnitDelay_DSTATE.B20 = Test_P.init_obj.B20;
    Test_DW.UnitDelay_DSTATE.B31B32 = Test_P.init_obj.B31B32;
    Test_DW.UnitDelay_DSTATE.B38 = Test_P.init_obj.B38;
    Test_DW.UnitDelay_DSTATE.B40B30 = Test_P.init_obj.B40B30;
    Test_DW.UnitDelay_DSTATE.B40B30_offTime = Test_P.init_obj.B40B30_offTime;
    Test_DW.UnitDelay_DSTATE.B4B5 = Test_P.init_obj.B4B5;
    Test_DW.UnitDelay_DSTATE.B64 = Test_P.init_obj.B64;
    Test_DW.UnitDelay_DSTATE.B6B9B3 = Test_P.init_obj.B6B9B3;
    Test_DW.UnitDelay_DSTATE.B7 = Test_P.init_obj.B7;
    Test_DW.UnitDelay_DSTATE.B8 = Test_P.init_obj.B8;
    Test_DW.UnitDelay_DSTATE.CBI2 = Test_P.init_obj.CBI2;
    Test_DW.UnitDelay_DSTATE.CBI3 = Test_P.init_obj.CBI3;
    Test_DW.UnitDelay_DSTATE.CBI3_refractory = Test_P.init_obj.CBI3_refractory;
    Test_DW.UnitDelay_DSTATE.CBI3_stimOFF = Test_P.init_obj.CBI3_stimOFF;
    Test_DW.UnitDelay_DSTATE.CBI3_stimON = Test_P.init_obj.CBI3_stimON;
    Test_DW.UnitDelay_DSTATE.CBI4 = Test_P.init_obj.CBI4;
    Test_DW.UnitDelay_DSTATE.EndTime = Test_P.init_obj.EndTime;
    Test_DW.UnitDelay_DSTATE.K_sp_g = Test_P.init_obj.K_sp_g;
    Test_DW.UnitDelay_DSTATE.K_sp_h = Test_P.init_obj.K_sp_h;
    Test_DW.UnitDelay_DSTATE.MCC = Test_P.init_obj.MCC;
    Test_DW.UnitDelay_DSTATE.P_I3_anterior = Test_P.init_obj.P_I3_anterior;
    Test_DW.UnitDelay_DSTATE.P_I4 = Test_P.init_obj.P_I4;
    Test_DW.UnitDelay_DSTATE.StartingTime = Test_P.init_obj.StartingTime;
    Test_DW.UnitDelay_DSTATE.T_I2 = Test_P.init_obj.T_I2;
    Test_DW.UnitDelay_DSTATE.T_I3 = Test_P.init_obj.T_I3;
    Test_DW.UnitDelay_DSTATE.T_hinge = Test_P.init_obj.T_hinge;
    Test_DW.UnitDelay_DSTATE.TimeStep = Test_P.init_obj.TimeStep;
    Test_DW.UnitDelay_DSTATE.behavior_1 = Test_P.init_obj.behavior_1;
    Test_DW.UnitDelay_DSTATE.behavior_2 = Test_P.init_obj.behavior_2;
    Test_DW.UnitDelay_DSTATE.c_g = Test_P.init_obj.c_g;
    Test_DW.UnitDelay_DSTATE.c_h = Test_P.init_obj.c_h;
    Test_DW.UnitDelay_DSTATE.fixation_type = Test_P.init_obj.fixation_type;
    Test_DW.UnitDelay_DSTATE.force_on_object = Test_P.init_obj.force_on_object;
    Test_DW.UnitDelay_DSTATE.grasper_friction_state =
      Test_P.init_obj.grasper_friction_state;
    Test_DW.UnitDelay_DSTATE.jaw_friction_state =
      Test_P.init_obj.jaw_friction_state;
    Test_DW.UnitDelay_DSTATE.max_I2 = Test_P.init_obj.max_I2;
    Test_DW.UnitDelay_DSTATE.max_I3 = Test_P.init_obj.max_I3;
    Test_DW.UnitDelay_DSTATE.max_I3ant = Test_P.init_obj.max_I3ant;
    Test_DW.UnitDelay_DSTATE.max_I4 = Test_P.init_obj.max_I4;
    Test_DW.UnitDelay_DSTATE.max_hinge = Test_P.init_obj.max_hinge;
    Test_DW.UnitDelay_DSTATE.mu_k_g = Test_P.init_obj.mu_k_g;
    Test_DW.UnitDelay_DSTATE.mu_k_h = Test_P.init_obj.mu_k_h;
    Test_DW.UnitDelay_DSTATE.mu_s_g = Test_P.init_obj.mu_s_g;
    Test_DW.UnitDelay_DSTATE.mu_s_h = Test_P.init_obj.mu_s_h;
    Test_DW.UnitDelay_DSTATE.postActivityExcitation_B40B30 =
      Test_P.init_obj.postActivityExcitation_B40B30;
    Test_DW.UnitDelay_DSTATE.refractory_CBI3 = Test_P.init_obj.refractory_CBI3;
    Test_DW.UnitDelay_DSTATE.seaweed_strength = Test_P.init_obj.seaweed_strength;
    Test_DW.UnitDelay_DSTATE.stim_B4B5 = Test_P.init_obj.stim_B4B5;
    Test_DW.UnitDelay_DSTATE.stim_CBI2 = Test_P.init_obj.stim_CBI2;
    Test_DW.UnitDelay_DSTATE.switchBehavior = Test_P.init_obj.switchBehavior;
    Test_DW.UnitDelay_DSTATE.t_switch = Test_P.init_obj.t_switch;
    Test_DW.UnitDelay_DSTATE.tau_I2_egestion = Test_P.init_obj.tau_I2_egestion;
    Test_DW.UnitDelay_DSTATE.tau_I2_ingestion = Test_P.init_obj.tau_I2_ingestion;
    Test_DW.UnitDelay_DSTATE.tau_I3 = Test_P.init_obj.tau_I3;
    Test_DW.UnitDelay_DSTATE.tau_I3anterior = Test_P.init_obj.tau_I3anterior;
    Test_DW.UnitDelay_DSTATE.tau_I4 = Test_P.init_obj.tau_I4;
    Test_DW.UnitDelay_DSTATE.tau_hinge = Test_P.init_obj.tau_hinge;
    Test_DW.UnitDelay_DSTATE.thresh_B31_bite_off =
      Test_P.init_obj.thresh_B31_bite_off;
    Test_DW.UnitDelay_DSTATE.thresh_B31_bite_on =
      Test_P.init_obj.thresh_B31_bite_on;
    Test_DW.UnitDelay_DSTATE.thresh_B31_reject_off =
      Test_P.init_obj.thresh_B31_reject_off;
    Test_DW.UnitDelay_DSTATE.thresh_B31_reject_on =
      Test_P.init_obj.thresh_B31_reject_on;
    Test_DW.UnitDelay_DSTATE.thresh_B31_swallow_off =
      Test_P.init_obj.thresh_B31_swallow_off;
    Test_DW.UnitDelay_DSTATE.thresh_B31_swallow_on =
      Test_P.init_obj.thresh_B31_swallow_on;
    Test_DW.UnitDelay_DSTATE.thresh_B38_retract =
      Test_P.init_obj.thresh_B38_retract;
    Test_DW.UnitDelay_DSTATE.thresh_B4B5_protract =
      Test_P.init_obj.thresh_B4B5_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B64_bite_protract =
      Test_P.init_obj.thresh_B64_bite_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B64_reject_protract =
      Test_P.init_obj.thresh_B64_reject_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B64_swallow_protract =
      Test_P.init_obj.thresh_B64_swallow_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B6B9B3_bite_pressure =
      Test_P.init_obj.thresh_B6B9B3_bite_pressure;
    Test_DW.UnitDelay_DSTATE.thresh_B6B9B3_reject_pressure =
      Test_P.init_obj.thresh_B6B9B3_reject_pressure;
    Test_DW.UnitDelay_DSTATE.thresh_B6B9B3_swallow_pressure =
      Test_P.init_obj.thresh_B6B9B3_swallow_pressure;
    Test_DW.UnitDelay_DSTATE.thresh_B7_bite_protract =
      Test_P.init_obj.thresh_B7_bite_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B7_reject_protract =
      Test_P.init_obj.thresh_B7_reject_protract;
    Test_DW.UnitDelay_DSTATE.unbroken = Test_P.init_obj.unbroken;
    Test_DW.UnitDelay_DSTATE.use_hypothesized_connections =
      Test_P.init_obj.use_hypothesized_connections;
    Test_DW.UnitDelay_DSTATE.x_g = Test_P.init_obj.x_g;
    Test_DW.UnitDelay_DSTATE.x_gh_ref = Test_P.init_obj.x_gh_ref;
    Test_DW.UnitDelay_DSTATE.x_h = Test_P.init_obj.x_h;
    Test_DW.UnitDelay_DSTATE.x_h_ref = Test_P.init_obj.x_h_ref;

    /* InitializeConditions for Integrator: '<S4>/Integrator11' */
    Test_X.Integrator11_CSTATE = Test_P.init_obj.x_g;

    /* InitializeConditions for Integrator: '<S4>/Integrator10' */
    Test_X.Integrator10_CSTATE = Test_P.init_obj.x_h;

    /* SystemInitialize for Enabled SubSystem: '<S7>/Surface fixed' */
    /* SystemInitialize for Enabled SubSystem: '<S34>/unbroken subsystem' */
    /* SystemInitialize for Merge: '<S38>/Merge4' */
    Test_B.Merge4_e = Test_P.Merge4_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S34>/unbroken subsystem' */
    /* End of SystemInitialize for SubSystem: '<S7>/Surface fixed' */

    /* SystemInitialize for Merge: '<S7>/Merge3' */
    Test_B.Merge3 = Test_P.Merge3_InitialOutput_o;

    /* SystemInitialize for Merge: '<S7>/Merge4' */
    Test_B.Merge4 = Test_P.Merge4_InitialOutput_e;

    /* SystemInitialize for Enabled SubSystem: '<S5>/Surface fixed' */
    /* SystemInitialize for Enabled SubSystem: '<S12>/unbroken subsystem' */
    /* SystemInitialize for Enabled SubSystem: '<S16>/Kinetic Friction Behavior' */
    /* SystemInitialize for Merge: '<S19>/Merge5' */
    Test_B.Merge5_c[0] = Test_P.Merge5_InitialOutput;
    Test_B.Merge5_c[1] = Test_P.Merge5_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S16>/Kinetic Friction Behavior' */

    /* SystemInitialize for Merge: '<S16>/Merge3' */
    Test_B.Merge3_d = Test_P.Merge3_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S12>/unbroken subsystem' */
    /* End of SystemInitialize for SubSystem: '<S5>/Surface fixed' */

    /* SystemInitialize for Merge: '<S5>/Merge3' */
    Test_B.Merge3_c = Test_P.Merge3_InitialOutput_l;

    /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
    /* SystemInitialize for Merge: '<S6>/Merge' */
    Test_B.Merge = Test_P.Merge_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */

    /* SystemInitialize for Merge: '<S5>/Merge4' */
    Test_B.Merge4_a = Test_P.Merge4_InitialOutput_g;

    /* SystemInitialize for Merge: '<S5>/Merge1' */
    Test_B.Merge1 = Test_P.Merge1_InitialOutput;

    /* SystemInitialize for Merge: '<S5>/Merge2' */
    Test_B.Merge2 = Test_P.Merge2_InitialOutput;

    /* SystemInitialize for Merge: '<S5>/Merge5' */
    Test_B.Merge5 = Test_P.Merge5_InitialOutput_e;

    /* SystemInitialize for Merge: '<S5>/Merge6' */
    Test_B.Merge6 = Test_P.Merge6_InitialOutput;

    /* SystemInitialize for Merge: '<S7>/Merge6' */
    Test_B.Merge6_d = Test_P.Merge6_InitialOutput_b;

    /* SystemInitialize for Merge: '<S7>/Merge1' */
    Test_B.Merge1_l = Test_P.Merge1_InitialOutput_n;

    /* SystemInitialize for Merge: '<S7>/Merge2' */
    Test_B.Merge2_l = Test_P.Merge2_InitialOutput_e;

    /* SystemInitialize for Merge: '<S7>/Merge5' */
    Test_B.Merge5_e = Test_P.Merge5_InitialOutput_n;
  }
}

/* Model terminate function */
void Test_terminate(void)
{
  /* (no terminate code required) */
}
