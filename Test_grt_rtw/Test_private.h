/*
 * Test_private.h
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

#ifndef RTW_HEADER_Test_private_h_
#define RTW_HEADER_Test_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Test.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void Test_EnabledSubsystem_Disable(DW_EnabledSubsystem_Test_T *localDW);
extern void Test_EnabledSubsystem(RT_MODEL_Test_T * const Test_M, boolean_T
  rtu_Enable, real_T *rty_Out1, DW_EnabledSubsystem_Test_T *localDW,
  P_EnabledSubsystem_Test_T *localP);
extern void KineticFrictionBehavior_Disable(DW_KineticFrictionBehavior_Te_T
  *localDW);
extern void Test_KineticFrictionBehavior(RT_MODEL_Test_T * const Test_M,
  boolean_T rtu_Enable, real_T rtu_sens_mechanical_grasper, real_T rtu_F_comb,
  real_T rtu_F_kf_range, real_T *rty_F_f_g, real_T *rty_grasper_friction_state,
  DW_KineticFrictionBehavior_Te_T *localDW, P_KineticFrictionBehavior_Tes_T
  *localP);
extern void StaticFrictionBehavior_Disable(DW_StaticFrictionBehavior_Tes_T
  *localDW);
extern void Test_StaticFrictionBehavior(RT_MODEL_Test_T * const Test_M,
  boolean_T rtu_Enable, real_T rtu_sens_mechanical_grasper, real_T rtu_F_comb,
  real_T *rty_F_f_g, real_T *rty_grasper_friction_state,
  DW_StaticFrictionBehavior_Tes_T *localDW, P_StaticFrictionBehavior_Test_T
  *localP);

/* private model entry point functions */
extern void Test_derivatives(void);

#endif                                 /* RTW_HEADER_Test_private_h_ */
