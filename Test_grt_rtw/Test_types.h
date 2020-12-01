/*
 * Test_types.h
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

#ifndef RTW_HEADER_Test_types_h_
#define RTW_HEADER_Test_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_AplysiaBus_
#define DEFINED_TYPEDEF_FOR_AplysiaBus_

typedef struct {
  real_T TimeStep;
  real_T StartingTime;
  real_T EndTime;
  real_T max_I4;
  real_T max_I3ant;
  real_T max_I3;
  real_T max_I2;
  real_T max_hinge;
  real_T tau_I4;
  real_T tau_I3anterior;
  real_T tau_I2_ingestion;
  real_T tau_I2_egestion;
  real_T tau_I3;
  real_T tau_hinge;
  real_T c_g;
  real_T c_h;
  real_T K_sp_h;
  real_T K_sp_g;
  real_T x_h_ref;
  real_T x_gh_ref;
  real_T mu_s_g;
  real_T mu_k_g;
  real_T mu_s_h;
  real_T mu_k_h;
  real_T thresh_B64_bite_protract;
  real_T thresh_B64_swallow_protract;
  real_T thresh_B64_reject_protract;
  real_T thresh_B4B5_protract;
  real_T thresh_B31_bite_off;
  real_T thresh_B31_swallow_off;
  real_T thresh_B31_reject_off;
  real_T thresh_B31_bite_on;
  real_T thresh_B31_swallow_on;
  real_T thresh_B31_reject_on;
  real_T thresh_B7_bite_protract;
  real_T thresh_B7_reject_protract;
  real_T thresh_B6B9B3_bite_pressure;
  real_T thresh_B6B9B3_swallow_pressure;
  real_T thresh_B6B9B3_reject_pressure;
  real_T thresh_B38_retract;
  real_T MCC;
  real_T CBI2;
  real_T CBI3;
  real_T CBI4;
  real_T B64;
  real_T B4B5;
  real_T B40B30;
  real_T B31B32;
  real_T B6B9B3;
  real_T B8;
  real_T B7;
  real_T B38;
  real_T B20;
  real_T refractory_CBI3;
  real_T postActivityExcitation_B40B30;
  real_T P_I4;
  real_T A_I4;
  real_T P_I3_anterior;
  real_T A_I3_anterior;
  real_T T_I3;
  real_T A_I3;
  real_T T_I2;
  real_T A_I2;
  real_T T_hinge;
  real_T A_hinge;
  real_T x_h;
  real_T x_g;
  real_T grasper_friction_state;
  real_T jaw_friction_state;
  real_T seaweed_strength;
  real_T fixation_type;
  real_T force_on_object;
  real_T sens_chemical_lips;
  real_T sens_mechanical_lips;
  real_T sens_mechanical_grasper;
  real_T use_hypothesized_connections;
  real_T stim_B4B5;
  real_T stim_CBI2;
  real_T CBI3_stimON;
  real_T CBI3_stimOFF;
  real_T CBI3_refractory;
  real_T B40B30_offTime;
  real_T unbroken;
  real_T switchBehavior;
  real_T behavior_1;
  real_T behavior_2;
  real_T t_switch;
} AplysiaBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_GCi64OmJNeKqyk0PC55G2E_
#define DEFINED_TYPEDEF_FOR_struct_GCi64OmJNeKqyk0PC55G2E_

typedef struct {
  real_T MCC;
  real_T CBI2;
  real_T CBI3;
  real_T CBI4;
  real_T B64;
  real_T B4B5;
  real_T B40B30;
  real_T B31B32;
  real_T B6B9B3;
  real_T B8;
  real_T B7;
  real_T B38;
  real_T B20;
  real_T P_I4;
  real_T A_I4;
  real_T P_I3_anterior;
  real_T A_I3_anterior;
  real_T T_I3;
  real_T A_I3;
  real_T T_I2;
  real_T A_I2;
  real_T T_hinge;
  real_T A_hinge;
  real_T x_h;
  real_T x_g;
  real_T grasper_friction_state;
  real_T jaw_friction_state;
  real_T force_on_object;
  real_T stim_B4B5;
  real_T stim_CBI2;
  real_T TimeStep;
  real_T StartingTime;
  real_T EndTime;
  real_T max_I4;
  real_T max_I3ant;
  real_T max_I3;
  real_T max_I2;
  real_T max_hinge;
  real_T tau_I4;
  real_T tau_I3anterior;
  real_T tau_I2_ingestion;
  real_T tau_I2_egestion;
  real_T tau_I3;
  real_T tau_hinge;
  real_T K_sp_h;
  real_T K_sp_g;
  real_T x_h_ref;
  real_T x_gh_ref;
  real_T mu_s_g;
  real_T mu_k_g;
  real_T mu_s_h;
  real_T mu_k_h;
  real_T thresh_B64_bite_protract;
  real_T thresh_B64_swallow_protract;
  real_T thresh_B64_reject_protract;
  real_T thresh_B4B5_protract;
  real_T thresh_B31_bite_off;
  real_T thresh_B31_swallow_off;
  real_T thresh_B31_reject_off;
  real_T thresh_B31_bite_on;
  real_T thresh_B31_swallow_on;
  real_T thresh_B31_reject_on;
  real_T thresh_B7_bite_protract;
  real_T thresh_B7_reject_protract;
  real_T thresh_B6B9B3_bite_pressure;
  real_T thresh_B6B9B3_swallow_pressure;
  real_T thresh_B6B9B3_reject_pressure;
  real_T thresh_B38_retract;
  real_T refractory_CBI3;
  real_T postActivityExcitation_B40B30;
  real_T seaweed_strength;
  real_T fixation_type;
  real_T CBI3_stimON;
  real_T CBI3_stimOFF;
  real_T CBI3_refractory;
  real_T B40B30_offTime;
  real_T unbroken;
  real_T switchBehavior;
  real_T behavior_1;
  real_T behavior_2;
  real_T t_switch;
} struct_GCi64OmJNeKqyk0PC55G2E;

#endif

/* Parameters (default storage) */
typedef struct P_Test_T_ P_Test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Test_T RT_MODEL_Test_T;

#endif                                 /* RTW_HEADER_Test_types_h_ */
