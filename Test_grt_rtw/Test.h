/*
 * Test.h
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

#ifndef RTW_HEADER_Test_h_
#define RTW_HEADER_Test_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Test_COMMON_INCLUDES_
# define Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Test_COMMON_INCLUDES_ */

#include "Test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<S6>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S6>/Enabled Subsystem' */
} DW_EnabledSubsystem_Test_T;

/* Block states (default storage) for system '<S27>/Kinetic Friction Behavior' */
typedef struct {
  boolean_T KineticFrictionBehavior_MODE;/* '<S27>/Kinetic Friction Behavior' */
} DW_KineticFrictionBehavior_Te_T;

/* Block states (default storage) for system '<S27>/Static Friction Behavior' */
typedef struct {
  boolean_T StaticFrictionBehavior_MODE;/* '<S27>/Static Friction Behavior' */
} DW_StaticFrictionBehavior_Tes_T;

/* Block signals (default storage) */
typedef struct {
  AplysiaBus UnitDelay;                /* '<Root>/Unit Delay' */
  AplysiaBus BusAssignment;            /* '<S1>/Bus Assignment' */
  AplysiaBus y;                        /* '<Root>/Neural Control' */
  real_T Product2[2];                  /* '<S31>/Product2' */
  real_T Product3;                     /* '<S31>/Product3' */
  real_T unbroken;
  real_T HiddenBuf_InsertedFor_Surfacefi;
  real_T Merge3;                       /* '<S7>/Merge3' */
  real_T Gain4[2];                     /* '<S11>/Gain4' */
  real_T Gain1;                        /* '<S11>/Gain1' */
  real_T Merge4;                       /* '<S7>/Merge4' */
  real_T HiddenBuf_InsertedFor_Surface_o;
  real_T Merge3_c;                     /* '<S5>/Merge3' */
  real_T HiddenBuf_InsertedFor_EnabledSu;
  real_T Merge4_a;                     /* '<S5>/Merge4' */
  real_T Merge1;                       /* '<S5>/Merge1' */
  real_T Merge2;                       /* '<S5>/Merge2' */
  real_T Merge5;                       /* '<S5>/Merge5' */
  real_T Merge6;                       /* '<S5>/Merge6' */
  real_T Merge6_d;                     /* '<S7>/Merge6' */
  real_T Gain1_b;                      /* '<S4>/Gain1' */
  real_T Gain2;                        /* '<S4>/Gain2' */
  real_T Merge1_l;                     /* '<S7>/Merge1' */
  real_T Merge2_l;                     /* '<S7>/Merge2' */
  real_T Merge5_e;                     /* '<S7>/Merge5' */
  real_T HiddenBuf_InsertedFor_unbrokens;
  real_T Merge4_e;                     /* '<S38>/Merge4' */
  real_T Merge;                        /* '<S6>/Merge' */
  real_T HiddenBuf_InsertedFor_unbroke_l;
  real_T Merge3_d;                     /* '<S16>/Merge3' */
  real_T Merge5_c[2];                  /* '<S19>/Merge5' */
  boolean_T NOT1;                      /* '<S7>/NOT1' */
  boolean_T HiddenBuf_InsertedFor_Notsurfac;/* '<S7>/NOT1' */
  boolean_T NOT;                       /* '<S5>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Notsurf_d;/* '<S5>/NOT' */
  boolean_T NOT_f;                     /* '<S34>/NOT' */
  boolean_T HiddenBuf_InsertedFor_brokensub;/* '<S34>/NOT' */
  boolean_T LessThanOrEqual;           /* '<S38>/LessThanOrEqual' */
  boolean_T HiddenBuf_InsertedFor_StaticFri;/* '<S38>/LessThanOrEqual' */
  boolean_T NOT_k;                     /* '<S38>/NOT' */
  boolean_T HiddenBuf_InsertedFor_KineticFr;/* '<S38>/NOT' */
  boolean_T LessThanOrEqual_l;         /* '<S37>/LessThanOrEqual' */
  boolean_T NOT_a;                     /* '<S37>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Kinetic_h;/* '<S37>/NOT' */
  boolean_T HiddenBuf_InsertedFor_StaticF_n;/* '<S37>/LessThanOrEqual' */
  boolean_T LessThanOrEqual_p;         /* '<S27>/LessThanOrEqual' */
  boolean_T NOT_p;                     /* '<S27>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Kineti_hz;/* '<S27>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Static_ng;/* '<S27>/LessThanOrEqual' */
  boolean_T NOT1_d;                    /* '<S6>/NOT1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_g;/* '<S6>/NOT1' */
  boolean_T NOT_b;                     /* '<S24>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Enabled_p;/* '<S24>/NOT' */
  boolean_T NOT_j;                     /* '<S12>/NOT' */
  boolean_T HiddenBuf_InsertedFor_brokens_e;/* '<S12>/NOT' */
  boolean_T LessThanOrEqual_h;         /* '<S16>/LessThanOrEqual' */
  boolean_T HiddenBuf_InsertedFor_Stati_ngi;/* '<S16>/LessThanOrEqual' */
  boolean_T NOT_fk;                    /* '<S16>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Kinetic_a;/* '<S16>/NOT' */
  boolean_T NOT_g;                     /* '<S19>/NOT' */
  boolean_T LessThanOrEqual_b;         /* '<S15>/LessThanOrEqual' */
  boolean_T NOT_h;                     /* '<S15>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Kinet_hz3;/* '<S15>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Stat_ngi2;/* '<S15>/LessThanOrEqual' */
  boolean_T LessThanOrEqual_f;         /* '<S8>/LessThanOrEqual' */
  boolean_T NOT_n;                     /* '<S8>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Kine_hz3r;/* '<S8>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Sta_ngi2y;/* '<S8>/LessThanOrEqual' */
} B_Test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  AplysiaBus UnitDelay_DSTATE;         /* '<Root>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T Surfacefixed_MODE;         /* '<S7>/Surface fixed' */
  boolean_T unbrokensubsystem_MODE;    /* '<S34>/unbroken subsystem' */
  boolean_T StaticFrictionBehavior_MODE;/* '<S38>/Static Friction Behavior' */
  boolean_T KineticFrictionBehavior_MODE;/* '<S38>/Kinetic Friction Behavior' */
  boolean_T brokensubsystem_MODE;      /* '<S34>/broken subsystem' */
  boolean_T Notsurfacefixed_MODE;      /* '<S7>/Not surface fixed' */
  boolean_T EnabledSubsystem_MODE;     /* '<S4>/Enabled Subsystem' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S6>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem1_MODE_d;  /* '<S24>/Enabled Subsystem1' */
  boolean_T Surfacefixed_MODE_b;       /* '<S5>/Surface fixed' */
  boolean_T unbrokensubsystem_MODE_e;  /* '<S12>/unbroken subsystem' */
  boolean_T StaticFrictionBehavior_MODE_m;/* '<S16>/Static Friction Behavior' */
  boolean_T KineticFrictionBehavior_MODE_a;/* '<S16>/Kinetic Friction Behavior' */
  boolean_T StaticGrasper_MODE;        /* '<S19>/Static Grasper' */
  boolean_T KineticGrasper_MODE;       /* '<S19>/Kinetic Grasper' */
  boolean_T brokensubsystem_MODE_p;    /* '<S12>/broken subsystem' */
  boolean_T StaticFrictionBehavior_MODE_k;/* '<S15>/Static Friction Behavior' */
  boolean_T KineticFrictionBehavior_MODE_p;/* '<S15>/Kinetic Friction Behavior' */
  boolean_T Notsurfacefixed_MODE_m;    /* '<S5>/Not surface fixed' */
  boolean_T StaticFrictionBehavior_MODE_n;/* '<S8>/Static Friction Behavior' */
  boolean_T KineticFrictionBehavior_MODE_k;/* '<S8>/Kinetic Friction Behavior' */
  DW_StaticFrictionBehavior_Tes_T StaticFrictionBehavior_i;/* '<S37>/Static Friction Behavior' */
  DW_KineticFrictionBehavior_Te_T KineticFrictionBehavior_f;/* '<S37>/Kinetic Friction Behavior' */
  DW_StaticFrictionBehavior_Tes_T StaticFrictionBehavior_f;/* '<S27>/Static Friction Behavior' */
  DW_KineticFrictionBehavior_Te_T KineticFrictionBehavior_mx;/* '<S27>/Kinetic Friction Behavior' */
  DW_EnabledSubsystem_Test_T EnabledSubsystem_n;/* '<S24>/Enabled Subsystem' */
  DW_EnabledSubsystem_Test_T EnabledSubsystem_o;/* '<S6>/Enabled Subsystem' */
} DW_Test_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator11_CSTATE;          /* '<S4>/Integrator11' */
  real_T Integrator10_CSTATE;          /* '<S4>/Integrator10' */
} X_Test_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator11_CSTATE;          /* '<S4>/Integrator11' */
  real_T Integrator10_CSTATE;          /* '<S4>/Integrator10' */
} XDot_Test_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator11_CSTATE;       /* '<S4>/Integrator11' */
  boolean_T Integrator10_CSTATE;       /* '<S4>/Integrator10' */
} XDis_Test_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S6>/Enabled Subsystem' */
struct P_EnabledSubsystem_Test_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
};

/* Parameters for system: '<S27>/Kinetic Friction Behavior' */
struct P_KineticFrictionBehavior_Tes_T_ {
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S35>/Constant'
                                        */
};

/* Parameters for system: '<S27>/Static Friction Behavior' */
struct P_StaticFrictionBehavior_Test_T_ {
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S36>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_Test_T_ {
  struct_onFJSroRbB20AxaUYMb93G init_obj;/* Variable: init_obj
                                          * Referenced by:
                                          *   '<Root>/Unit Delay'
                                          *   '<S4>/Gain1'
                                          *   '<S4>/Gain2'
                                          *   '<S4>/Integrator10'
                                          *   '<S4>/Integrator11'
                                          *   '<S6>/Constant'
                                          *   '<S9>/Constant1'
                                          *   '<S9>/Constant3'
                                          *   '<S10>/Constant3'
                                          *   '<S11>/Gain1'
                                          *   '<S11>/Gain2'
                                          *   '<S11>/Gain3'
                                          *   '<S11>/Gain4'
                                          *   '<S28>/Constant'
                                          *   '<S29>/Constant1'
                                          *   '<S30>/Constant2'
                                          *   '<S31>/Constant1'
                                          *   '<S31>/Constant4'
                                          *   '<S32>/Constant4'
                                          *   '<S33>/Gain'
                                          *   '<S33>/Gain1'
                                          *   '<S33>/Gain2'
                                          *   '<S33>/Gain3'
                                          *   '<S19>/Gain1'
                                          *   '<S19>/Gain2'
                                          *   '<S41>/Gain1'
                                          *   '<S21>/Gain1'
                                          *   '<S21>/Gain2'
                                          *   '<S21>/Gain3'
                                          *   '<S22>/Gain'
                                          *   '<S22>/Gain2'
                                          *   '<S22>/Gain3'
                                          *   '<S22>/Gain4'
                                          */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -1
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Constant_Value_cb;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant_Value_c1;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Merge5_InitialOutput;       /* Computed Parameter: Merge5_InitialOutput
                                      * Referenced by: '<S19>/Merge5'
                                      */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Merge3_InitialOutput;       /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S16>/Merge3'
                                      */
  real_T foo_Y0;                       /* Computed Parameter: foo_Y0
                                        * Referenced by: '<S6>/foo'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0.3
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S6>/Merge'
                                       */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S42>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T Merge4_InitialOutput;       /* Computed Parameter: Merge4_InitialOutput
                                      * Referenced by: '<S38>/Merge4'
                                      */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S28>/Constant4'
                                        */
  real_T Constant1_Value_o[2];         /* Expression: [1 -1]
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant2_Value[2];           /* Expression: [1 -1]
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant2_Value_j[2];         /* Expression: [-1 1]
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0.5
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: [-1 1]
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Merge3_InitialOutput_o;   /* Computed Parameter: Merge3_InitialOutput_o
                                    * Referenced by: '<S7>/Merge3'
                                    */
  real_T Constant2_Value_p[2];         /* Expression: [-1 0]
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Constant1_Value_jw;           /* Expression: 1
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_o[2];         /* Expression: [1 -1]
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Merge4_InitialOutput_e;   /* Computed Parameter: Merge4_InitialOutput_e
                                    * Referenced by: '<S7>/Merge4'
                                    */
  real_T Merge3_InitialOutput_l;   /* Computed Parameter: Merge3_InitialOutput_l
                                    * Referenced by: '<S5>/Merge3'
                                    */
  real_T Merge4_InitialOutput_g;   /* Computed Parameter: Merge4_InitialOutput_g
                                    * Referenced by: '<S5>/Merge4'
                                    */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S5>/Merge1'
                                      */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S5>/Merge2'
                                      */
  real_T Merge5_InitialOutput_e;   /* Computed Parameter: Merge5_InitialOutput_e
                                    * Referenced by: '<S5>/Merge5'
                                    */
  real_T Merge6_InitialOutput;       /* Computed Parameter: Merge6_InitialOutput
                                      * Referenced by: '<S5>/Merge6'
                                      */
  real_T Merge6_InitialOutput_b;   /* Computed Parameter: Merge6_InitialOutput_b
                                    * Referenced by: '<S7>/Merge6'
                                    */
  real_T Merge1_InitialOutput_n;   /* Computed Parameter: Merge1_InitialOutput_n
                                    * Referenced by: '<S7>/Merge1'
                                    */
  real_T Merge2_InitialOutput_e;   /* Computed Parameter: Merge2_InitialOutput_e
                                    * Referenced by: '<S7>/Merge2'
                                    */
  real_T Merge5_InitialOutput_n;   /* Computed Parameter: Merge5_InitialOutput_n
                                    * Referenced by: '<S7>/Merge5'
                                    */
  P_StaticFrictionBehavior_Test_T StaticFrictionBehavior_i;/* '<S37>/Static Friction Behavior' */
  P_KineticFrictionBehavior_Tes_T KineticFrictionBehavior_f;/* '<S37>/Kinetic Friction Behavior' */
  P_StaticFrictionBehavior_Test_T StaticFrictionBehavior_f;/* '<S27>/Static Friction Behavior' */
  P_KineticFrictionBehavior_Tes_T KineticFrictionBehavior_mx;/* '<S27>/Kinetic Friction Behavior' */
  P_EnabledSubsystem_Test_T EnabledSubsystem_n;/* '<S24>/Enabled Subsystem' */
  P_EnabledSubsystem_Test_T EnabledSubsystem_o;/* '<S6>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Test_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Test_T Test_P;

/* Block signals (default storage) */
extern B_Test_T Test_B;

/* Continuous states (default storage) */
extern X_Test_T Test_X;

/* Block states (default storage) */
extern DW_Test_T Test_DW;

/* Model entry point functions */
extern void Test_initialize(void);
extern void Test_step(void);
extern void Test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Test_T *const Test_M;

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
 * '<Root>' : 'Test'
 * '<S1>'   : 'Test/Biomechanics'
 * '<S2>'   : 'Test/Neural Control'
 * '<S3>'   : 'Test/setSensoryStates'
 * '<S4>'   : 'Test/Biomechanics/Subsystem'
 * '<S5>'   : 'Test/Biomechanics/Subsystem/Body Forces'
 * '<S6>'   : 'Test/Biomechanics/Subsystem/Enabled Subsystem'
 * '<S7>'   : 'Test/Biomechanics/Subsystem/Grasper Forces'
 * '<S8>'   : 'Test/Biomechanics/Subsystem/Body Forces/Not surface fixed'
 * '<S9>'   : 'Test/Biomechanics/Subsystem/Body Forces/Subsystem1'
 * '<S10>'  : 'Test/Biomechanics/Subsystem/Body Forces/Subsystem5'
 * '<S11>'  : 'Test/Biomechanics/Subsystem/Body Forces/Subsystem6'
 * '<S12>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed'
 * '<S13>'  : 'Test/Biomechanics/Subsystem/Body Forces/Not surface fixed/Kinetic Friction Behavior'
 * '<S14>'  : 'Test/Biomechanics/Subsystem/Body Forces/Not surface fixed/Static Friction Behavior'
 * '<S15>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/broken subsystem'
 * '<S16>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/unbroken subsystem'
 * '<S17>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/broken subsystem/Kinetic Friction Behavior'
 * '<S18>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/broken subsystem/Static Friction Behavior'
 * '<S19>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/unbroken subsystem/Kinetic Friction Behavior'
 * '<S20>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/unbroken subsystem/Static Friction Behavior'
 * '<S21>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/unbroken subsystem/Kinetic Friction Behavior/Kinetic Grasper'
 * '<S22>'  : 'Test/Biomechanics/Subsystem/Body Forces/Surface fixed/unbroken subsystem/Kinetic Friction Behavior/Static Grasper'
 * '<S23>'  : 'Test/Biomechanics/Subsystem/Enabled Subsystem/Enabled Subsystem'
 * '<S24>'  : 'Test/Biomechanics/Subsystem/Enabled Subsystem/Enabled Subsystem1'
 * '<S25>'  : 'Test/Biomechanics/Subsystem/Enabled Subsystem/Enabled Subsystem1/Enabled Subsystem'
 * '<S26>'  : 'Test/Biomechanics/Subsystem/Enabled Subsystem/Enabled Subsystem1/Enabled Subsystem1'
 * '<S27>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Not surface fixed'
 * '<S28>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Subsystem'
 * '<S29>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Subsystem1'
 * '<S30>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Subsystem2'
 * '<S31>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Subsystem3'
 * '<S32>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Subsystem4'
 * '<S33>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Subsystem6'
 * '<S34>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed'
 * '<S35>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Not surface fixed/Kinetic Friction Behavior'
 * '<S36>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Not surface fixed/Static Friction Behavior'
 * '<S37>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed/broken subsystem'
 * '<S38>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed/unbroken subsystem'
 * '<S39>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed/broken subsystem/Kinetic Friction Behavior'
 * '<S40>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed/broken subsystem/Static Friction Behavior'
 * '<S41>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed/unbroken subsystem/Kinetic Friction Behavior'
 * '<S42>'  : 'Test/Biomechanics/Subsystem/Grasper Forces/Surface fixed/unbroken subsystem/Static Friction Behavior'
 */
#endif                                 /* RTW_HEADER_Test_h_ */
