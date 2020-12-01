/*
 * Test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test".
 *
 * Model version              : 1.65
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Nov 30 18:21:41 2020
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

/* Block states (default storage) */
DW_Test_T Test_DW;

/* Real-time model */
RT_MODEL_Test_T Test_M_;
RT_MODEL_Test_T *const Test_M = &Test_M_;

/* Model step function */
void Test_step(void)
{
  real_T on_thresh;
  real_T off_thresh;
  int32_T B40B30_excite;
  real_T F_f_g;
  real_T F_f_h;
  real_T A11;
  real_T B1;
  real_T B2;
  real_T F_I2;
  real_T F_I3;
  real_T F_hinge;
  real_T F_sp_g;
  real_T F_I4;
  real_T F_I3_ant;
  real_T F_sp_h;
  real_T rtb_Clock;
  real_T rtb_y_fixation_type;
  real_T rtb_y_sens_mechanical_grasper;
  real_T rtb_y_a_P_I3_anterior;
  real_T rtb_y_a_T_I3;
  real_T rtb_y_a_T_I2;
  real_T rtb_y_a_T_hinge;
  real_T A2;
  real_T A2_idx_0;
  real_T A2_idx_1;
  real_T rtb_y_a_T_I2_tmp;
  real_T rtb_y_a_P_I3_anterior_tmp;
  real_T x_gh_tmp;
  real_T F_I3_tmp;
  real_T F_I3_tmp_0;

  /* UnitDelay: '<Root>/Unit Delay' */
  Test_B.UnitDelay = Test_DW.UnitDelay_DSTATE;

  /* Clock: '<Root>/Clock' */
  rtb_Clock = Test_M->Timing.t[0];

  /* MATLAB Function: '<Root>/setSensoryStates' */
  rtb_y_fixation_type = Test_B.UnitDelay.fixation_type;
  F_f_h = Test_B.UnitDelay.sens_chemical_lips;
  F_f_g = Test_B.UnitDelay.sens_mechanical_lips;
  rtb_y_sens_mechanical_grasper = Test_B.UnitDelay.sens_mechanical_grasper;
  if (Test_B.UnitDelay.switchBehavior == 0.0) {
    if (Test_B.UnitDelay.behavior_1 == 1.0) {
      F_f_h = 1.0;
      F_f_g = 1.0;
      rtb_y_sens_mechanical_grasper = 0.0;
      rtb_y_fixation_type = 0.0;
    } else if (Test_B.UnitDelay.behavior_1 == 2.0) {
      F_f_h = 1.0;
      F_f_g = 1.0;
      rtb_y_sens_mechanical_grasper = 1.0;
      rtb_y_fixation_type = 1.0;
    } else {
      if (Test_B.UnitDelay.behavior_1 == 2.0) {
        F_f_h = 0.0;
        F_f_g = 1.0;
        rtb_y_sens_mechanical_grasper = 1.0;
        rtb_y_fixation_type = 0.0;
      }
    }
  } else {
    if (Test_B.UnitDelay.switchBehavior == 1.0) {
      if (Test_B.UnitDelay.behavior_1 == 1.0) {
        F_f_h = 1.0;
        F_f_g = 1.0;
        rtb_y_sens_mechanical_grasper = 0.0;
        rtb_y_fixation_type = 0.0;
      } else if (Test_B.UnitDelay.behavior_1 == 2.0) {
        F_f_h = 1.0;
        F_f_g = 1.0;
        rtb_y_sens_mechanical_grasper = 1.0;
        rtb_y_fixation_type = 1.0;
      } else {
        if (Test_B.UnitDelay.behavior_1 == 2.0) {
          F_f_h = 0.0;
          F_f_g = 1.0;
          rtb_y_sens_mechanical_grasper = 1.0;
          rtb_y_fixation_type = 0.0;
        }
      }

      if (rtb_Clock > Test_B.UnitDelay.t_switch) {
        if (Test_B.UnitDelay.behavior_1 == 1.0) {
          F_f_h = 1.0;
          F_f_g = 1.0;
          rtb_y_sens_mechanical_grasper = 0.0;
          rtb_y_fixation_type = 0.0;
        } else if (Test_B.UnitDelay.behavior_1 == 2.0) {
          F_f_h = 1.0;
          F_f_g = 1.0;
          rtb_y_sens_mechanical_grasper = 1.0;
          rtb_y_fixation_type = 1.0;
        } else {
          if (Test_B.UnitDelay.behavior_1 == 2.0) {
            F_f_h = 0.0;
            F_f_g = 1.0;
            rtb_y_sens_mechanical_grasper = 1.0;
            rtb_y_fixation_type = 0.0;
          }
        }
      }
    }
  }

  /* MATLAB Function: '<Root>/Neural Control' incorporates:
   *  MATLAB Function: '<Root>/Biomechanics'
   *  MATLAB Function: '<Root>/setSensoryStates'
   */
  A11 = Test_B.UnitDelay.CBI3_stimON;
  A2_idx_1 = Test_B.UnitDelay.CBI3_stimOFF;
  B1 = Test_B.UnitDelay.CBI3_refractory;
  F_I2 = Test_B.UnitDelay.B40B30_offTime;
  x_gh_tmp = Test_B.UnitDelay.x_g - Test_B.UnitDelay.x_h;
  if ((Test_B.UnitDelay.B4B5 >= 2.0) && (Test_B.UnitDelay.CBI3_stimON == 0.0)) {
    A11 = rtb_Clock;
  }

  if ((A11 != 0.0) && (Test_B.UnitDelay.B4B5 < 2.0)) {
    B1 = 1.0;
    A2_idx_1 = rtb_Clock;
    A11 = 0.0;
  }

  if ((B1 != 0.0) && (rtb_Clock < Test_B.UnitDelay.refractory_CBI3 / 1000.0 +
                      A2_idx_1)) {
    B1 = 1.0;
  } else {
    A2_idx_1 = 0.0;
    B1 = 0.0;
  }

  F_I3 = (real_T)((Test_B.UnitDelay.CBI2 != 0.0) || (Test_B.UnitDelay.CBI4 !=
    0.0) || (Test_B.UnitDelay.B31B32 != 0.0)) * Test_B.UnitDelay.MCC * (real_T)
    !(Test_B.UnitDelay.B64 != 0.0);
  if ((Test_B.UnitDelay.B40B30 == 1.0) && (F_I3 == 0.0)) {
    F_I2 = rtb_Clock;
  }

  if ((rtb_y_sens_mechanical_grasper != 0.0) && (Test_B.UnitDelay.CBI3 != 0.0))
  {
    on_thresh = Test_B.UnitDelay.thresh_B31_swallow_on;
    off_thresh = Test_B.UnitDelay.thresh_B31_swallow_off;
  } else if ((rtb_y_sens_mechanical_grasper != 0.0) && (!(Test_B.UnitDelay.CBI3
               != 0.0))) {
    on_thresh = Test_B.UnitDelay.thresh_B31_reject_on;
    off_thresh = Test_B.UnitDelay.thresh_B31_reject_off;
  } else {
    on_thresh = Test_B.UnitDelay.thresh_B31_bite_on;
    off_thresh = Test_B.UnitDelay.thresh_B31_bite_off;
  }

  if ((Test_B.UnitDelay.B40B30 == 0.0) && (rtb_Clock <
       Test_B.UnitDelay.postActivityExcitation_B40B30 / 1000.0 + F_I2)) {
    B40B30_excite = 1;
  } else {
    B40B30_excite = 0;
  }

  B2 = Test_B.UnitDelay.tau_I4 + Test_B.UnitDelay.TimeStep;
  F_I4 = (Test_B.UnitDelay.tau_I4 * Test_B.UnitDelay.P_I4 +
          Test_B.UnitDelay.A_I4 * Test_B.UnitDelay.TimeStep) / B2;
  rtb_y_a_P_I3_anterior_tmp = Test_B.UnitDelay.tau_I3anterior +
    Test_B.UnitDelay.TimeStep;
  rtb_y_a_P_I3_anterior = (Test_B.UnitDelay.tau_I3anterior *
    Test_B.UnitDelay.P_I3_anterior + Test_B.UnitDelay.A_I3_anterior *
    Test_B.UnitDelay.TimeStep) / rtb_y_a_P_I3_anterior_tmp;
  A2_idx_0 = Test_B.UnitDelay.tau_I3 + Test_B.UnitDelay.TimeStep;
  rtb_y_a_T_I3 = (Test_B.UnitDelay.tau_I3 * Test_B.UnitDelay.T_I3 +
                  Test_B.UnitDelay.TimeStep * Test_B.UnitDelay.A_I3) / A2_idx_0;
  rtb_y_a_T_I2_tmp = (1.0 - Test_B.UnitDelay.CBI3) *
    Test_B.UnitDelay.tau_I2_egestion + Test_B.UnitDelay.tau_I2_ingestion *
    Test_B.UnitDelay.CBI3;
  F_hinge = rtb_y_a_T_I2_tmp + Test_B.UnitDelay.TimeStep;
  rtb_y_a_T_I2 = (rtb_y_a_T_I2_tmp * Test_B.UnitDelay.T_I2 +
                  Test_B.UnitDelay.TimeStep * Test_B.UnitDelay.A_I2) / F_hinge;
  F_sp_g = Test_B.UnitDelay.tau_hinge + Test_B.UnitDelay.TimeStep;
  rtb_y_a_T_hinge = (Test_B.UnitDelay.tau_hinge * Test_B.UnitDelay.T_hinge +
                     Test_B.UnitDelay.TimeStep * Test_B.UnitDelay.A_hinge) /
    F_sp_g;

  /* MATLAB Function: '<Root>/Biomechanics' incorporates:
   *  MATLAB Function: '<Root>/setSensoryStates'
   */
  rtb_Clock = Test_B.UnitDelay.unbroken;
  Test_B.y.TimeStep = Test_B.UnitDelay.TimeStep;
  Test_B.y.StartingTime = Test_B.UnitDelay.StartingTime;
  Test_B.y.EndTime = Test_B.UnitDelay.EndTime;
  Test_B.y.max_I4 = Test_B.UnitDelay.max_I4;
  Test_B.y.max_I3ant = Test_B.UnitDelay.max_I3ant;
  Test_B.y.max_I3 = Test_B.UnitDelay.max_I3;
  Test_B.y.max_I2 = Test_B.UnitDelay.max_I2;
  Test_B.y.max_hinge = Test_B.UnitDelay.max_hinge;
  Test_B.y.tau_I4 = Test_B.UnitDelay.tau_I4;
  Test_B.y.tau_I3anterior = Test_B.UnitDelay.tau_I3anterior;
  Test_B.y.tau_I2_ingestion = Test_B.UnitDelay.tau_I2_ingestion;
  Test_B.y.tau_I2_egestion = Test_B.UnitDelay.tau_I2_egestion;
  Test_B.y.tau_I3 = Test_B.UnitDelay.tau_I3;
  Test_B.y.tau_hinge = Test_B.UnitDelay.tau_hinge;
  Test_B.y.c_g = Test_B.UnitDelay.c_g;
  Test_B.y.c_h = Test_B.UnitDelay.c_h;
  Test_B.y.K_sp_h = Test_B.UnitDelay.K_sp_h;
  Test_B.y.K_sp_g = Test_B.UnitDelay.K_sp_g;
  Test_B.y.x_h_ref = Test_B.UnitDelay.x_h_ref;
  Test_B.y.x_gh_ref = Test_B.UnitDelay.x_gh_ref;
  Test_B.y.mu_s_g = Test_B.UnitDelay.mu_s_g;
  Test_B.y.mu_k_g = Test_B.UnitDelay.mu_k_g;
  Test_B.y.mu_s_h = Test_B.UnitDelay.mu_s_h;
  Test_B.y.mu_k_h = Test_B.UnitDelay.mu_k_h;
  Test_B.y.thresh_B64_bite_protract = Test_B.UnitDelay.thresh_B64_bite_protract;
  Test_B.y.thresh_B64_swallow_protract =
    Test_B.UnitDelay.thresh_B64_swallow_protract;
  Test_B.y.thresh_B64_reject_protract =
    Test_B.UnitDelay.thresh_B64_reject_protract;
  Test_B.y.thresh_B4B5_protract = Test_B.UnitDelay.thresh_B4B5_protract;
  Test_B.y.thresh_B31_bite_off = Test_B.UnitDelay.thresh_B31_bite_off;
  Test_B.y.thresh_B31_swallow_off = Test_B.UnitDelay.thresh_B31_swallow_off;
  Test_B.y.thresh_B31_reject_off = Test_B.UnitDelay.thresh_B31_reject_off;
  Test_B.y.thresh_B31_bite_on = Test_B.UnitDelay.thresh_B31_bite_on;
  Test_B.y.thresh_B31_swallow_on = Test_B.UnitDelay.thresh_B31_swallow_on;
  Test_B.y.thresh_B31_reject_on = Test_B.UnitDelay.thresh_B31_reject_on;
  Test_B.y.thresh_B7_bite_protract = Test_B.UnitDelay.thresh_B7_bite_protract;
  Test_B.y.thresh_B7_reject_protract =
    Test_B.UnitDelay.thresh_B7_reject_protract;
  Test_B.y.thresh_B6B9B3_bite_pressure =
    Test_B.UnitDelay.thresh_B6B9B3_bite_pressure;
  Test_B.y.thresh_B6B9B3_swallow_pressure =
    Test_B.UnitDelay.thresh_B6B9B3_swallow_pressure;
  Test_B.y.thresh_B6B9B3_reject_pressure =
    Test_B.UnitDelay.thresh_B6B9B3_reject_pressure;
  Test_B.y.thresh_B38_retract = Test_B.UnitDelay.thresh_B38_retract;
  Test_B.y.MCC = Test_B.UnitDelay.MCC;

  /* MATLAB Function: '<Root>/Neural Control' incorporates:
   *  MATLAB Function: '<Root>/setSensoryStates'
   */
  if (Test_B.UnitDelay.use_hypothesized_connections == 1.0) {
    /* MATLAB Function: '<Root>/Biomechanics' */
    Test_B.y.CBI2 = (real_T)(((F_f_g != 0.0) && (F_f_h != 0.0) &&
      (!(rtb_y_sens_mechanical_grasper != 0.0))) ||
      ((rtb_y_sens_mechanical_grasper != 0.0) && (!(F_f_h != 0.0))) ||
      (Test_B.UnitDelay.B4B5 >= 2.0)) * ((real_T)(Test_B.UnitDelay.stim_CBI2 ==
      0.0) * Test_B.UnitDelay.MCC * (real_T)!(Test_B.UnitDelay.B64 != 0.0)) +
      (real_T)(Test_B.UnitDelay.stim_CBI2 == 1.0);
  } else {
    /* MATLAB Function: '<Root>/Biomechanics' */
    Test_B.y.CBI2 = (real_T)(((F_f_g != 0.0) && (F_f_h != 0.0) &&
      (!(rtb_y_sens_mechanical_grasper != 0.0))) ||
      ((rtb_y_sens_mechanical_grasper != 0.0) && (!(F_f_h != 0.0)))) * ((real_T)
      (Test_B.UnitDelay.stim_CBI2 == 0.0) * Test_B.UnitDelay.MCC * (real_T)
      !(Test_B.UnitDelay.B64 != 0.0)) + (real_T)(Test_B.UnitDelay.stim_CBI2 ==
      1.0);
  }

  if (Test_B.UnitDelay.use_hypothesized_connections == 1.0) {
    /* MATLAB Function: '<Root>/Biomechanics' */
    Test_B.y.CBI3 = F_f_g * F_f_h * Test_B.UnitDelay.MCC * (real_T)
      (Test_B.UnitDelay.B4B5 < 2.0) * (real_T)!(B1 != 0.0);
  } else {
    /* MATLAB Function: '<Root>/Biomechanics' */
    Test_B.y.CBI3 = F_f_g * F_f_h * Test_B.UnitDelay.MCC;
  }

  /* MATLAB Function: '<Root>/Biomechanics' incorporates:
   *  MATLAB Function: '<Root>/Neural Control'
   *  MATLAB Function: '<Root>/setSensoryStates'
   */
  Test_B.y.CBI4 = (real_T)((F_f_g != 0.0) || (F_f_h != 0.0)) *
    Test_B.UnitDelay.MCC * rtb_y_sens_mechanical_grasper;
  Test_B.y.B64 = (real_T)(((real_T)(((real_T)(x_gh_tmp >
    Test_B.UnitDelay.thresh_B64_swallow_protract) *
    rtb_y_sens_mechanical_grasper != 0.0) || (!(rtb_y_sens_mechanical_grasper !=
    0.0) * (x_gh_tmp > Test_B.UnitDelay.thresh_B64_bite_protract) != 0)) *
    Test_B.UnitDelay.CBI3 != 0.0) || (!(Test_B.UnitDelay.CBI3 != 0.0) *
    (x_gh_tmp > Test_B.UnitDelay.thresh_B64_reject_protract) != 0)) * ((real_T)
    !(Test_B.UnitDelay.B31B32 != 0.0) * Test_B.UnitDelay.MCC);
  Test_B.y.B4B5 = ((real_T)!(Test_B.UnitDelay.CBI3 != 0.0) * 2.0 *
                   Test_B.UnitDelay.B64 * (real_T)(x_gh_tmp >
    Test_B.UnitDelay.thresh_B4B5_protract) * (real_T)
                   !(Test_B.UnitDelay.stim_B4B5 != 0.0) + Test_B.UnitDelay.CBI3 *
                   rtb_y_sens_mechanical_grasper * Test_B.UnitDelay.B64) *
    Test_B.UnitDelay.MCC + 2.0 * Test_B.UnitDelay.stim_B4B5;
  Test_B.y.B40B30 = F_I3;
  Test_B.y.B31B32 = ((real_T)((Test_B.UnitDelay.P_I4 < 0.5) ||
    (Test_B.UnitDelay.CBI2 != 0.0)) * (real_T)!(Test_B.UnitDelay.B64 != 0.0) *
                     ((real_T)!(Test_B.UnitDelay.B31B32 != 0.0) * (real_T)
                      (x_gh_tmp < off_thresh) + (real_T)(x_gh_tmp < on_thresh) *
                      Test_B.UnitDelay.B31B32) * Test_B.UnitDelay.CBI3 + (real_T)
                     !(Test_B.UnitDelay.B64 != 0.0) * (real_T)
                     (Test_B.UnitDelay.P_I4 > 0.25) * (real_T)
                     ((Test_B.UnitDelay.CBI2 != 0.0) || (Test_B.UnitDelay.CBI4
    != 0.0)) * ((real_T)!(Test_B.UnitDelay.B31B32 != 0.0) * (real_T)(x_gh_tmp <
    off_thresh) + (real_T)(x_gh_tmp < on_thresh) * Test_B.UnitDelay.B31B32) *
                     (real_T)!(Test_B.UnitDelay.CBI3 != 0.0)) *
    Test_B.UnitDelay.MCC;
  Test_B.y.B6B9B3 = ((real_T)(((Test_B.UnitDelay.CBI3 != 0.0) &&
    (!(rtb_y_sens_mechanical_grasper != 0.0))) * (Test_B.UnitDelay.P_I4 >
    Test_B.UnitDelay.thresh_B6B9B3_bite_pressure) + ((Test_B.UnitDelay.CBI3 !=
    0.0) && (rtb_y_sens_mechanical_grasper != 0.0)) * (Test_B.UnitDelay.P_I4 >
    Test_B.UnitDelay.thresh_B6B9B3_swallow_pressure)) + (real_T)
                     !(Test_B.UnitDelay.CBI3 != 0.0) * (real_T)
                     !(Test_B.UnitDelay.P_I4 >
                       Test_B.UnitDelay.thresh_B6B9B3_reject_pressure)) *
    (Test_B.UnitDelay.MCC * Test_B.UnitDelay.B64 * (real_T)
     !(Test_B.UnitDelay.B4B5 >= 2.0));
  Test_B.y.B8 = ((real_T)((Test_B.UnitDelay.B20 != 0.0) ||
    (!(Test_B.UnitDelay.B31B32 != 0.0) * B40B30_excite != 0)) *
                 Test_B.UnitDelay.CBI3 + (real_T)!(Test_B.UnitDelay.CBI3 != 0.0)
                 * Test_B.UnitDelay.B20) * ((real_T)!(Test_B.UnitDelay.B4B5 >=
    2.0) * Test_B.UnitDelay.MCC);
  Test_B.y.B7 = ((real_T)((!(Test_B.UnitDelay.CBI3 != 0.0)) ||
    (rtb_y_sens_mechanical_grasper != 0.0)) * (real_T)((x_gh_tmp >=
    Test_B.UnitDelay.thresh_B7_reject_protract) || (Test_B.UnitDelay.P_I4 > 0.97))
                 + (real_T)((Test_B.UnitDelay.CBI3 != 0.0) &&
    (!(rtb_y_sens_mechanical_grasper != 0.0))) * (real_T)((x_gh_tmp >=
    Test_B.UnitDelay.thresh_B7_bite_protract) || (Test_B.UnitDelay.P_I4 > 0.97)))
    * Test_B.UnitDelay.MCC;
  Test_B.y.B38 = (real_T)(x_gh_tmp < Test_B.UnitDelay.thresh_B38_retract) *
    Test_B.UnitDelay.CBI3 * (Test_B.UnitDelay.MCC *
    rtb_y_sens_mechanical_grasper);
  Test_B.y.B20 = (real_T)((Test_B.UnitDelay.CBI2 != 0.0) ||
    (Test_B.UnitDelay.CBI4 != 0.0) || (Test_B.UnitDelay.B31B32 != 0.0)) *
    Test_B.UnitDelay.MCC * (real_T)!(Test_B.UnitDelay.CBI3 != 0.0) * (real_T)
    !(Test_B.UnitDelay.B64 != 0.0);
  Test_B.y.refractory_CBI3 = Test_B.UnitDelay.refractory_CBI3;
  Test_B.y.postActivityExcitation_B40B30 =
    Test_B.UnitDelay.postActivityExcitation_B40B30;
  Test_B.y.P_I4 = F_I4;
  Test_B.y.A_I4 = (Test_B.UnitDelay.tau_I4 * Test_B.UnitDelay.A_I4 +
                   Test_B.UnitDelay.B8 * Test_B.UnitDelay.TimeStep) / B2;
  Test_B.y.P_I3_anterior = rtb_y_a_P_I3_anterior;
  Test_B.y.A_I3_anterior = ((Test_B.UnitDelay.B38 + Test_B.UnitDelay.B6B9B3) *
    Test_B.UnitDelay.TimeStep + Test_B.UnitDelay.tau_I3anterior *
    Test_B.UnitDelay.A_I3_anterior) / rtb_y_a_P_I3_anterior_tmp;
  Test_B.y.T_I3 = rtb_y_a_T_I3;
  Test_B.y.A_I3 = (Test_B.UnitDelay.tau_I3 * Test_B.UnitDelay.A_I3 +
                   Test_B.UnitDelay.TimeStep * Test_B.UnitDelay.B6B9B3) /
    A2_idx_0;
  Test_B.y.T_I2 = rtb_y_a_T_I2;
  Test_B.y.A_I2 = (rtb_y_a_T_I2_tmp * Test_B.UnitDelay.A_I2 +
                   Test_B.UnitDelay.TimeStep * Test_B.UnitDelay.B31B32) /
    F_hinge;
  Test_B.y.T_hinge = rtb_y_a_T_hinge;
  Test_B.y.A_hinge = (Test_B.UnitDelay.tau_hinge * Test_B.UnitDelay.A_hinge +
                      Test_B.UnitDelay.TimeStep * Test_B.UnitDelay.B7) / F_sp_g;
  Test_B.y.grasper_friction_state = Test_B.UnitDelay.grasper_friction_state;
  Test_B.y.jaw_friction_state = Test_B.UnitDelay.jaw_friction_state;
  Test_B.y.seaweed_strength = Test_B.UnitDelay.seaweed_strength;
  Test_B.y.fixation_type = rtb_y_fixation_type;
  Test_B.y.sens_chemical_lips = F_f_h;
  Test_B.y.sens_mechanical_lips = F_f_g;
  Test_B.y.sens_mechanical_grasper = rtb_y_sens_mechanical_grasper;
  Test_B.y.use_hypothesized_connections =
    Test_B.UnitDelay.use_hypothesized_connections;
  Test_B.y.stim_B4B5 = Test_B.UnitDelay.stim_B4B5;
  Test_B.y.stim_CBI2 = Test_B.UnitDelay.stim_CBI2;
  Test_B.y.CBI3_stimON = A11;
  Test_B.y.CBI3_stimOFF = A2_idx_1;
  Test_B.y.CBI3_refractory = B1;
  Test_B.y.B40B30_offTime = F_I2;
  Test_B.y.unbroken = Test_B.UnitDelay.unbroken;
  Test_B.y.switchBehavior = Test_B.UnitDelay.switchBehavior;
  Test_B.y.behavior_1 = Test_B.UnitDelay.behavior_1;
  Test_B.y.behavior_2 = Test_B.UnitDelay.behavior_2;
  Test_B.y.t_switch = Test_B.UnitDelay.t_switch;
  F_f_g = 0.0;
  F_f_h = 0.0;
  A11 = 0.0;
  A2_idx_1 = 0.0;
  on_thresh = 0.0;
  off_thresh = 0.0;
  B1 = 0.0;
  B2 = 0.0;
  rtb_y_a_T_I2_tmp = Test_B.UnitDelay.max_I2 * rtb_y_a_T_I2;
  F_I2 = (rtb_y_a_T_I2_tmp * Test_B.UnitDelay.x_h + -rtb_y_a_T_I2_tmp *
          Test_B.UnitDelay.x_g) + rtb_y_a_T_I2_tmp;
  F_I3_tmp = Test_B.UnitDelay.max_I3 * rtb_y_a_T_I3;
  F_I3_tmp_0 = F_I3_tmp * 0.0;
  F_I3 = (-F_I3_tmp * Test_B.UnitDelay.x_h + F_I3_tmp * Test_B.UnitDelay.x_g) -
    F_I3_tmp_0;
  F_hinge = (real_T)(x_gh_tmp > 0.5) * Test_B.UnitDelay.max_hinge *
    rtb_y_a_T_hinge;
  F_hinge = (-F_hinge * Test_B.UnitDelay.x_h + F_hinge * Test_B.UnitDelay.x_g) -
    (real_T)(x_gh_tmp > 0.5) * Test_B.UnitDelay.max_hinge * rtb_y_a_T_hinge *
    0.5;
  rtb_y_a_P_I3_anterior_tmp = Test_B.UnitDelay.K_sp_g *
    Test_B.UnitDelay.x_gh_ref;
  F_sp_g = (Test_B.UnitDelay.K_sp_g * Test_B.UnitDelay.x_h +
            -Test_B.UnitDelay.K_sp_g * Test_B.UnitDelay.x_g) +
    rtb_y_a_P_I3_anterior_tmp;
  F_I4 *= Test_B.UnitDelay.max_I4;
  A2_idx_0 = Test_B.UnitDelay.max_I3ant * rtb_y_a_P_I3_anterior;
  F_I3_ant = (A2_idx_0 * Test_B.UnitDelay.x_h + -A2_idx_0 * Test_B.UnitDelay.x_g)
    + A2_idx_0;
  if (rtb_y_fixation_type == 0.0) {
    off_thresh = Test_B.UnitDelay.max_hinge * rtb_y_a_T_hinge * (real_T)
      (x_gh_tmp > 0.5);
    on_thresh = 1.0 / Test_B.UnitDelay.c_g;
    A2_idx_0 = (((rtb_y_a_T_I2_tmp + Test_B.UnitDelay.K_sp_g) - (-F_I3_tmp)) - (
      -off_thresh)) * on_thresh;
    off_thresh = (((-rtb_y_a_T_I2_tmp + -Test_B.UnitDelay.K_sp_g) - F_I3_tmp) -
                  off_thresh) * on_thresh;
    B2 = ((real_T)(x_gh_tmp > 0.5) * Test_B.UnitDelay.max_hinge *
          rtb_y_a_T_hinge * 0.5 + ((rtb_y_a_T_I2_tmp + rtb_y_a_P_I3_anterior_tmp)
           + F_I3_tmp_0)) * on_thresh;
    on_thresh = A2_idx_0;
    F_f_g = fabs(((F_I2 + F_sp_g) - F_I3) - F_hinge);
    if (F_f_g <= fabs(Test_B.UnitDelay.mu_s_g * F_I4)) {
      F_f_g = (((F_I2 + F_sp_g) - F_I3) - F_hinge) *
        -rtb_y_sens_mechanical_grasper;
      Test_B.y.grasper_friction_state = 1.0;
    } else {
      F_f_g = -(((F_I2 + F_sp_g) - F_I3) - F_hinge) / F_f_g *
        (rtb_y_sens_mechanical_grasper * Test_B.UnitDelay.mu_k_g * F_I4);
      Test_B.y.grasper_friction_state = 0.0;
    }
  } else {
    if (rtb_y_fixation_type == 1.0) {
      if (Test_B.UnitDelay.unbroken != 0.0) {
        F_I3_tmp_0 = ((F_I2 + F_sp_g) - F_I3) - F_hinge;
        if (fabs(F_I3_tmp_0) <= fabs(Test_B.UnitDelay.mu_s_g * F_I4)) {
          F_f_g = F_I3_tmp_0 * -rtb_y_sens_mechanical_grasper;
          Test_B.y.grasper_friction_state = 1.0;
        } else {
          if (F_I3_tmp_0 < 0.0) {
            F_I3_tmp_0 = -1.0;
          } else if (F_I3_tmp_0 > 0.0) {
            F_I3_tmp_0 = 1.0;
          } else if (F_I3_tmp_0 == 0.0) {
            F_I3_tmp_0 = 0.0;
          } else {
            F_I3_tmp_0 = (rtNaN);
          }

          F_f_g = -F_I3_tmp_0 * rtb_y_sens_mechanical_grasper *
            Test_B.UnitDelay.mu_k_g * F_I4;
          Test_B.y.grasper_friction_state = 0.0;
          B2 = Test_B.UnitDelay.max_hinge * rtb_y_a_T_hinge * (real_T)(x_gh_tmp >
            0.5);
          F_sp_h = 1.0 / Test_B.UnitDelay.c_g;
          A2_idx_0 = (((rtb_y_a_T_I2_tmp + Test_B.UnitDelay.K_sp_g) - (-F_I3_tmp))
                      - (-B2)) * F_sp_h;
          off_thresh = (((-rtb_y_a_T_I2_tmp + -Test_B.UnitDelay.K_sp_g) -
                         F_I3_tmp) - B2) * F_sp_h;
          B2 = (((real_T)(x_gh_tmp > 0.5) * Test_B.UnitDelay.max_hinge *
                 rtb_y_a_T_hinge * 0.5 + ((Test_B.UnitDelay.max_I2 *
                   rtb_y_a_T_I2 + Test_B.UnitDelay.K_sp_g *
                   Test_B.UnitDelay.x_gh_ref) + Test_B.UnitDelay.max_I3 *
                  rtb_y_a_T_I3 * 0.0)) + F_f_g) * (1.0 / Test_B.UnitDelay.c_g);
          on_thresh = A2_idx_0;
        }
      } else {
        off_thresh = Test_B.UnitDelay.max_hinge * rtb_y_a_T_hinge * (real_T)
          (x_gh_tmp > 0.5);
        B2 = 1.0 / Test_B.UnitDelay.c_g;
        A2_idx_0 = (((rtb_y_a_T_I2_tmp + Test_B.UnitDelay.K_sp_g) - (-F_I3_tmp))
                    - (-off_thresh)) * B2;
        off_thresh = (((-rtb_y_a_T_I2_tmp + -Test_B.UnitDelay.K_sp_g) - F_I3_tmp)
                      - off_thresh) * B2;
        B2 = ((real_T)(x_gh_tmp > 0.5) * Test_B.UnitDelay.max_hinge *
              rtb_y_a_T_hinge * 0.5 + ((Test_B.UnitDelay.max_I2 * rtb_y_a_T_I2 +
                Test_B.UnitDelay.K_sp_g * Test_B.UnitDelay.x_gh_ref) +
               Test_B.UnitDelay.max_I3 * rtb_y_a_T_I3 * 0.0)) * (1.0 /
          Test_B.UnitDelay.c_g);
        on_thresh = A2_idx_0;
        F_f_g = fabs(((F_I2 + F_sp_g) - F_I3) - F_hinge);
        if (F_f_g <= fabs(Test_B.UnitDelay.mu_s_g * F_I4)) {
          F_f_g = (((F_I2 + F_sp_g) - F_I3) - F_hinge) *
            -rtb_y_sens_mechanical_grasper;
          Test_B.y.grasper_friction_state = 1.0;
        } else {
          F_f_g = -(((F_I2 + F_sp_g) - F_I3) - F_hinge) / F_f_g *
            (rtb_y_sens_mechanical_grasper * Test_B.UnitDelay.mu_k_g * F_I4);
          Test_B.y.grasper_friction_state = 0.0;
        }
      }
    }
  }

  A2 = Test_B.UnitDelay.K_sp_h * 0.0;
  F_I3_tmp = Test_B.UnitDelay.x_h_ref * Test_B.UnitDelay.K_sp_h;
  F_sp_h = (-Test_B.UnitDelay.K_sp_h * Test_B.UnitDelay.x_h + A2 *
            Test_B.UnitDelay.x_g) + F_I3_tmp;
  if (rtb_y_fixation_type == 0.0) {
    rtb_y_a_P_I3_anterior_tmp = 1.0 / Test_B.UnitDelay.c_h;
    rtb_y_a_P_I3_anterior = rtb_y_a_P_I3_anterior_tmp * Test_B.UnitDelay.K_sp_h;
    B1 = rtb_y_a_P_I3_anterior_tmp * Test_B.UnitDelay.x_h_ref *
      Test_B.UnitDelay.K_sp_h;
    A11 = -rtb_y_a_P_I3_anterior;
    A2_idx_1 = rtb_y_a_P_I3_anterior * 0.0;
    if (fabs(F_sp_h + F_f_g) <= fabs(Test_B.UnitDelay.mu_s_h * F_I3_ant)) {
      F_f_h = (F_sp_h + F_f_g) * -rtb_y_sens_mechanical_grasper;
      Test_B.y.jaw_friction_state = 1.0;
    } else {
      F_I3_tmp_0 = F_sp_h + F_f_g;
      if (F_I3_tmp_0 < 0.0) {
        F_I3_tmp_0 = -1.0;
      } else if (F_I3_tmp_0 > 0.0) {
        F_I3_tmp_0 = 1.0;
      } else if (F_I3_tmp_0 == 0.0) {
        F_I3_tmp_0 = 0.0;
      } else {
        F_I3_tmp_0 = (rtNaN);
      }

      F_f_h = -F_I3_tmp_0 * rtb_y_sens_mechanical_grasper *
        Test_B.UnitDelay.mu_k_h * F_I3_ant;
      Test_B.y.jaw_friction_state = 0.0;
    }
  } else {
    if (rtb_y_fixation_type == 1.0) {
      if (Test_B.UnitDelay.unbroken != 0.0) {
        if (fabs(F_sp_h + F_f_g) <= fabs(Test_B.UnitDelay.mu_s_h * F_I3_ant)) {
          F_f_h = (F_sp_h + F_f_g) * -rtb_y_sens_mechanical_grasper;
          Test_B.y.jaw_friction_state = 1.0;
        } else {
          F_I3_tmp_0 = F_sp_h + F_f_g;
          if (F_I3_tmp_0 < 0.0) {
            A11 = -1.0;
          } else if (F_I3_tmp_0 > 0.0) {
            A11 = 1.0;
          } else {
            if (!(F_I3_tmp_0 == 0.0)) {
              A11 = (rtNaN);
            }
          }

          F_f_h = -A11 * rtb_y_sens_mechanical_grasper * Test_B.UnitDelay.mu_k_h
            * F_I3_ant;
          Test_B.y.jaw_friction_state = 0.0;
          if (Test_B.y.grasper_friction_state == 1.0) {
            F_I4 = Test_B.UnitDelay.max_I3 * rtb_y_a_T_I3;
            B1 = Test_B.UnitDelay.max_hinge * rtb_y_a_T_hinge * (real_T)
              (x_gh_tmp > 0.5);
            A11 = F_sp_h + F_f_g;
            if (A11 < 0.0) {
              F_I3_tmp_0 = -1.0;
            } else if (A11 > 0.0) {
              F_I3_tmp_0 = 1.0;
            } else if (A11 == 0.0) {
              F_I3_tmp_0 = 0.0;
            } else {
              F_I3_tmp_0 = (rtNaN);
            }

            F_I2 = F_I3_tmp_0 * rtb_y_sens_mechanical_grasper *
              Test_B.UnitDelay.mu_k_h * Test_B.UnitDelay.max_I3ant *
              rtb_y_a_P_I3_anterior;
            F_I3 = 1.0 / Test_B.UnitDelay.c_h;
            A2_idx_0 = (((((rtb_y_a_T_I2_tmp + Test_B.UnitDelay.K_sp_g) - (-F_I4))
                          - (-B1)) * -rtb_y_sens_mechanical_grasper +
                         -Test_B.UnitDelay.K_sp_h) - F_I2) * F_I3;
            A2_idx_1 = (((((-rtb_y_a_T_I2_tmp + -Test_B.UnitDelay.K_sp_g) - F_I4)
                          - B1) * -rtb_y_sens_mechanical_grasper + A2) - (-F_I2))
              * F_I3;
            if (A11 < 0.0) {
              F_I3_tmp_0 = -1.0;
            } else if (A11 > 0.0) {
              F_I3_tmp_0 = 1.0;
            } else if (A11 == 0.0) {
              F_I3_tmp_0 = 0.0;
            } else {
              F_I3_tmp_0 = (rtNaN);
            }

            B1 = ((((real_T)(x_gh_tmp > 0.5) * Test_B.UnitDelay.max_hinge *
                    rtb_y_a_T_hinge * 0.5 + ((Test_B.UnitDelay.max_I2 *
                      rtb_y_a_T_I2 + rtb_y_a_P_I3_anterior_tmp) + F_I4 * 0.0)) *
                   -rtb_y_sens_mechanical_grasper + F_I3_tmp) - F_I3_tmp_0 *
                  rtb_y_sens_mechanical_grasper * Test_B.UnitDelay.mu_k_h *
                  Test_B.UnitDelay.max_I3ant * rtb_y_a_P_I3_anterior) * (1.0 /
              Test_B.UnitDelay.c_h);
          } else {
            rtb_y_a_T_I3 = A11 * rtb_y_sens_mechanical_grasper *
              Test_B.UnitDelay.mu_k_h * Test_B.UnitDelay.max_I3ant *
              rtb_y_a_P_I3_anterior;
            rtb_y_a_T_I2_tmp = 1.0 / Test_B.UnitDelay.c_h;
            A2_idx_0 = (-Test_B.UnitDelay.K_sp_h - rtb_y_a_T_I3) *
              rtb_y_a_T_I2_tmp;
            A2_idx_1 = (A2 - (-rtb_y_a_T_I3)) * rtb_y_a_T_I2_tmp;
            F_I3_tmp_0 = ((F_I2 + F_sp_g) - F_I3) - F_hinge;
            B1 = F_sp_h + F_f_g;
            if (F_I3_tmp_0 < 0.0) {
              F_I3_tmp_0 = -1.0;
            } else if (F_I3_tmp_0 > 0.0) {
              F_I3_tmp_0 = 1.0;
            } else if (F_I3_tmp_0 == 0.0) {
              F_I3_tmp_0 = 0.0;
            } else {
              F_I3_tmp_0 = (rtNaN);
            }

            if (B1 < 0.0) {
              B1 = -1.0;
            } else if (B1 > 0.0) {
              B1 = 1.0;
            } else if (B1 == 0.0) {
              B1 = 0.0;
            } else {
              B1 = (rtNaN);
            }

            B1 = ((F_I3_tmp - F_I3_tmp_0 * rtb_y_sens_mechanical_grasper *
                   Test_B.UnitDelay.mu_k_g * F_I4) - B1 *
                  rtb_y_sens_mechanical_grasper * Test_B.UnitDelay.mu_k_h *
                  Test_B.UnitDelay.max_I3ant * rtb_y_a_P_I3_anterior) *
              rtb_y_a_T_I2_tmp;
          }

          A11 = A2_idx_0;
        }
      } else {
        F_I3_tmp_0 = F_sp_h + F_f_g;
        if (fabs(F_I3_tmp_0) <= fabs(Test_B.UnitDelay.mu_s_h * F_I3_ant)) {
          F_f_h = F_I3_tmp_0 * -rtb_y_sens_mechanical_grasper;
        } else {
          if (F_I3_tmp_0 < 0.0) {
            F_I3_tmp_0 = -1.0;
          } else if (F_I3_tmp_0 > 0.0) {
            F_I3_tmp_0 = 1.0;
          } else if (F_I3_tmp_0 == 0.0) {
            F_I3_tmp_0 = 0.0;
          } else {
            F_I3_tmp_0 = (rtNaN);
          }

          F_f_h = -F_I3_tmp_0 * rtb_y_sens_mechanical_grasper *
            Test_B.UnitDelay.mu_k_h * F_I3_ant;
        }

        rtb_y_sens_mechanical_grasper = 1.0 / Test_B.UnitDelay.c_h *
          Test_B.UnitDelay.K_sp_h;
        B1 = 1.0 / Test_B.UnitDelay.c_h * Test_B.UnitDelay.x_h_ref *
          Test_B.UnitDelay.K_sp_h;
        A11 = -rtb_y_sens_mechanical_grasper;
        A2_idx_1 = rtb_y_sens_mechanical_grasper * 0.0;
        Test_B.y.jaw_friction_state = 0.0;
      }
    }
  }

  rtb_y_sens_mechanical_grasper = 1.0 / (1.0 - (A11 + off_thresh) *
    Test_B.UnitDelay.TimeStep);
  Test_B.y.x_g = (((Test_B.UnitDelay.TimeStep * -A11 + 1.0) *
                   Test_B.UnitDelay.x_g + Test_B.UnitDelay.TimeStep * on_thresh *
                   Test_B.UnitDelay.x_h) + Test_B.UnitDelay.TimeStep * B2) *
    rtb_y_sens_mechanical_grasper;
  Test_B.y.x_h = (((Test_B.UnitDelay.TimeStep * -off_thresh + 1.0) *
                   Test_B.UnitDelay.x_h + Test_B.UnitDelay.TimeStep * A2_idx_1 *
                   Test_B.UnitDelay.x_g) + Test_B.UnitDelay.TimeStep * B1) *
    rtb_y_sens_mechanical_grasper;
  Test_B.y.force_on_object = F_f_g + F_f_h;
  if (rtb_y_fixation_type == 1.0) {
    if (Test_B.y.force_on_object > Test_B.UnitDelay.seaweed_strength) {
      rtb_Clock = 0.0;
    }

    if ((!(rtb_Clock != 0.0)) && (x_gh_tmp < 0.3) && (Test_B.y.x_g -
         Test_B.y.x_h > x_gh_tmp)) {
      Test_B.y.unbroken = 1.0;
    }

    Test_B.y.force_on_object *= Test_B.y.unbroken;
  }

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  Test_B.CBI3 = Test_B.y.CBI3;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Test_M->rtwLogInfo, (Test_M->Timing.t));

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  Test_DW.UnitDelay_DSTATE = Test_B.y;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Test_M)!=-1) &&
        !((rtmGetTFinal(Test_M)-Test_M->Timing.t[0]) > Test_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(Test_M, "Simulation finished");
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
  if (!(++Test_M->Timing.clockTick0)) {
    ++Test_M->Timing.clockTickH0;
  }

  Test_M->Timing.t[0] = Test_M->Timing.clockTick0 * Test_M->Timing.stepSize0 +
    Test_M->Timing.clockTickH0 * Test_M->Timing.stepSize0 * 4294967296.0;

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
    rtsiSetErrorStatusPtr(&Test_M->solverInfo, (&rtmGetErrorStatus(Test_M)));
    rtsiSetRTModelPtr(&Test_M->solverInfo, Test_M);
  }

  rtsiSetSimTimeStep(&Test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Test_M->solverInfo,"FixedStepDiscrete");
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
    Test_DW.UnitDelay_DSTATE.A_I2 = Test_P.obj.A_I2;
    Test_DW.UnitDelay_DSTATE.A_I3 = Test_P.obj.A_I3;
    Test_DW.UnitDelay_DSTATE.A_I3_anterior = Test_P.obj.A_I3_anterior;
    Test_DW.UnitDelay_DSTATE.A_I4 = Test_P.obj.A_I4;
    Test_DW.UnitDelay_DSTATE.A_hinge = Test_P.obj.A_hinge;
    Test_DW.UnitDelay_DSTATE.B20 = Test_P.obj.B20;
    Test_DW.UnitDelay_DSTATE.B31B32 = Test_P.obj.B31B32;
    Test_DW.UnitDelay_DSTATE.B38 = Test_P.obj.B38;
    Test_DW.UnitDelay_DSTATE.B40B30 = Test_P.obj.B40B30;
    Test_DW.UnitDelay_DSTATE.B40B30_offTime = Test_P.obj.B40B30_offTime;
    Test_DW.UnitDelay_DSTATE.B4B5 = Test_P.obj.B4B5;
    Test_DW.UnitDelay_DSTATE.B64 = Test_P.obj.B64;
    Test_DW.UnitDelay_DSTATE.B6B9B3 = Test_P.obj.B6B9B3;
    Test_DW.UnitDelay_DSTATE.B7 = Test_P.obj.B7;
    Test_DW.UnitDelay_DSTATE.B8 = Test_P.obj.B8;
    Test_DW.UnitDelay_DSTATE.CBI2 = Test_P.obj.CBI2;
    Test_DW.UnitDelay_DSTATE.CBI3 = Test_P.obj.CBI3;
    Test_DW.UnitDelay_DSTATE.CBI3_refractory = Test_P.obj.CBI3_refractory;
    Test_DW.UnitDelay_DSTATE.CBI3_stimOFF = Test_P.obj.CBI3_stimOFF;
    Test_DW.UnitDelay_DSTATE.CBI3_stimON = Test_P.obj.CBI3_stimON;
    Test_DW.UnitDelay_DSTATE.CBI4 = Test_P.obj.CBI4;
    Test_DW.UnitDelay_DSTATE.EndTime = Test_P.obj.EndTime;
    Test_DW.UnitDelay_DSTATE.K_sp_g = Test_P.obj.K_sp_g;
    Test_DW.UnitDelay_DSTATE.K_sp_h = Test_P.obj.K_sp_h;
    Test_DW.UnitDelay_DSTATE.MCC = Test_P.obj.MCC;
    Test_DW.UnitDelay_DSTATE.P_I3_anterior = Test_P.obj.P_I3_anterior;
    Test_DW.UnitDelay_DSTATE.P_I4 = Test_P.obj.P_I4;
    Test_DW.UnitDelay_DSTATE.StartingTime = Test_P.obj.StartingTime;
    Test_DW.UnitDelay_DSTATE.T_I2 = Test_P.obj.T_I2;
    Test_DW.UnitDelay_DSTATE.T_I3 = Test_P.obj.T_I3;
    Test_DW.UnitDelay_DSTATE.T_hinge = Test_P.obj.T_hinge;
    Test_DW.UnitDelay_DSTATE.TimeStep = Test_P.obj.TimeStep;
    Test_DW.UnitDelay_DSTATE.behavior_1 = Test_P.obj.behavior_1;
    Test_DW.UnitDelay_DSTATE.behavior_2 = Test_P.obj.behavior_2;
    Test_DW.UnitDelay_DSTATE.fixation_type = Test_P.obj.fixation_type;
    Test_DW.UnitDelay_DSTATE.force_on_object = Test_P.obj.force_on_object;
    Test_DW.UnitDelay_DSTATE.grasper_friction_state =
      Test_P.obj.grasper_friction_state;
    Test_DW.UnitDelay_DSTATE.jaw_friction_state = Test_P.obj.jaw_friction_state;
    Test_DW.UnitDelay_DSTATE.max_I2 = Test_P.obj.max_I2;
    Test_DW.UnitDelay_DSTATE.max_I3 = Test_P.obj.max_I3;
    Test_DW.UnitDelay_DSTATE.max_I3ant = Test_P.obj.max_I3ant;
    Test_DW.UnitDelay_DSTATE.max_I4 = Test_P.obj.max_I4;
    Test_DW.UnitDelay_DSTATE.max_hinge = Test_P.obj.max_hinge;
    Test_DW.UnitDelay_DSTATE.mu_k_g = Test_P.obj.mu_k_g;
    Test_DW.UnitDelay_DSTATE.mu_k_h = Test_P.obj.mu_k_h;
    Test_DW.UnitDelay_DSTATE.mu_s_g = Test_P.obj.mu_s_g;
    Test_DW.UnitDelay_DSTATE.mu_s_h = Test_P.obj.mu_s_h;
    Test_DW.UnitDelay_DSTATE.postActivityExcitation_B40B30 =
      Test_P.obj.postActivityExcitation_B40B30;
    Test_DW.UnitDelay_DSTATE.refractory_CBI3 = Test_P.obj.refractory_CBI3;
    Test_DW.UnitDelay_DSTATE.seaweed_strength = Test_P.obj.seaweed_strength;
    Test_DW.UnitDelay_DSTATE.stim_B4B5 = Test_P.obj.stim_B4B5;
    Test_DW.UnitDelay_DSTATE.stim_CBI2 = Test_P.obj.stim_CBI2;
    Test_DW.UnitDelay_DSTATE.switchBehavior = Test_P.obj.switchBehavior;
    Test_DW.UnitDelay_DSTATE.t_switch = Test_P.obj.t_switch;
    Test_DW.UnitDelay_DSTATE.tau_I2_egestion = Test_P.obj.tau_I2_egestion;
    Test_DW.UnitDelay_DSTATE.tau_I2_ingestion = Test_P.obj.tau_I2_ingestion;
    Test_DW.UnitDelay_DSTATE.tau_I3 = Test_P.obj.tau_I3;
    Test_DW.UnitDelay_DSTATE.tau_I3anterior = Test_P.obj.tau_I3anterior;
    Test_DW.UnitDelay_DSTATE.tau_I4 = Test_P.obj.tau_I4;
    Test_DW.UnitDelay_DSTATE.tau_hinge = Test_P.obj.tau_hinge;
    Test_DW.UnitDelay_DSTATE.thresh_B31_bite_off =
      Test_P.obj.thresh_B31_bite_off;
    Test_DW.UnitDelay_DSTATE.thresh_B31_bite_on = Test_P.obj.thresh_B31_bite_on;
    Test_DW.UnitDelay_DSTATE.thresh_B31_reject_off =
      Test_P.obj.thresh_B31_reject_off;
    Test_DW.UnitDelay_DSTATE.thresh_B31_reject_on =
      Test_P.obj.thresh_B31_reject_on;
    Test_DW.UnitDelay_DSTATE.thresh_B31_swallow_off =
      Test_P.obj.thresh_B31_swallow_off;
    Test_DW.UnitDelay_DSTATE.thresh_B31_swallow_on =
      Test_P.obj.thresh_B31_swallow_on;
    Test_DW.UnitDelay_DSTATE.thresh_B38_retract = Test_P.obj.thresh_B38_retract;
    Test_DW.UnitDelay_DSTATE.thresh_B4B5_protract =
      Test_P.obj.thresh_B4B5_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B64_bite_protract =
      Test_P.obj.thresh_B64_bite_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B64_reject_protract =
      Test_P.obj.thresh_B64_reject_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B64_swallow_protract =
      Test_P.obj.thresh_B64_swallow_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B6B9B3_bite_pressure =
      Test_P.obj.thresh_B6B9B3_bite_pressure;
    Test_DW.UnitDelay_DSTATE.thresh_B6B9B3_reject_pressure =
      Test_P.obj.thresh_B6B9B3_reject_pressure;
    Test_DW.UnitDelay_DSTATE.thresh_B6B9B3_swallow_pressure =
      Test_P.obj.thresh_B6B9B3_swallow_pressure;
    Test_DW.UnitDelay_DSTATE.thresh_B7_bite_protract =
      Test_P.obj.thresh_B7_bite_protract;
    Test_DW.UnitDelay_DSTATE.thresh_B7_reject_protract =
      Test_P.obj.thresh_B7_reject_protract;
    Test_DW.UnitDelay_DSTATE.unbroken = Test_P.obj.unbroken;
    Test_DW.UnitDelay_DSTATE.x_g = Test_P.obj.x_g;
    Test_DW.UnitDelay_DSTATE.x_gh_ref = Test_P.obj.x_gh_ref;
    Test_DW.UnitDelay_DSTATE.x_h = Test_P.obj.x_h;
    Test_DW.UnitDelay_DSTATE.x_h_ref = Test_P.obj.x_h_ref;
  }
}

/* Model terminate function */
void Test_terminate(void)
{
  /* (no terminate code required) */
}
