/*
 * Test_data.c
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

/* Block parameters (default storage) */
P_Test_T Test_P = {
  /* Variable: init_obj
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
  {
    1.0,
    1.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0,
    0.0,
    0.0,
    0.0,
    1.0,
    0.0,
    0.0,
    0.05,
    0.0,
    0.05,
    0.05,
    0.05,
    0.05,
    0.05,
    0.0,
    0.05,
    0.0,
    0.1,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.05,
    0.0,
    40.0,
    1.75,
    0.6,
    1.0,
    1.5,
    0.2,
    0.70710678118654746,
    1.4142135623730949,
    0.35355339059327373,
    0.98994949366116636,
    0.70710678118654746,
    0.70710678118654746,
    1.0,
    1.0,
    2.0,
    0.1,
    0.0,
    0.4,
    0.4,
    0.3,
    0.3,
    0.3,
    0.89,
    0.4,
    0.5,
    0.7,
    0.55,
    0.4,
    0.6,
    0.9,
    0.75,
    0.89,
    0.9,
    0.7,
    0.2,
    0.25,
    0.75,
    0.4,
    5000.0,
    3000.0,
    10.0,
    1.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1.0,
    0.0,
    2.0,
    2.0,
    0.0
  },

  /* Expression: -1
   * Referenced by: '<S13>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S14>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S14>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S17>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S18>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S21>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S22>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S19>/Gain'
   */
  -1.0,

  /* Computed Parameter: Merge5_InitialOutput
   * Referenced by: '<S19>/Merge5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S20>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S20>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput
   * Referenced by: '<S16>/Merge3'
   */
  0.0,

  /* Computed Parameter: foo_Y0
   * Referenced by: '<S6>/foo'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S6>/Constant1'
   */
  0.3,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S6>/Merge'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S41>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S41>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S42>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S42>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S42>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge4_InitialOutput
   * Referenced by: '<S38>/Merge4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S28>/Constant4'
   */
  1.0,

  /* Expression: [1 -1]
   * Referenced by: '<S28>/Constant1'
   */
  { 1.0, -1.0 },

  /* Expression: [1 -1]
   * Referenced by: '<S31>/Constant2'
   */
  { 1.0, -1.0 },

  /* Expression: [-1 1]
   * Referenced by: '<S29>/Constant2'
   */
  { -1.0, 1.0 },

  /* Expression: 0.5
   * Referenced by: '<S30>/Constant3'
   */
  0.5,

  /* Expression: [-1 1]
   * Referenced by: '<S30>/Constant1'
   */
  { -1.0, 1.0 },

  /* Computed Parameter: Merge3_InitialOutput_o
   * Referenced by: '<S7>/Merge3'
   */
  0.0,

  /* Expression: [-1 0]
   * Referenced by: '<S9>/Constant2'
   */
  { -1.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S10>/Constant1'
   */
  1.0,

  /* Expression: [1 -1]
   * Referenced by: '<S10>/Constant2'
   */
  { 1.0, -1.0 },

  /* Computed Parameter: Merge4_InitialOutput_e
   * Referenced by: '<S7>/Merge4'
   */
  0.0,

  /* Computed Parameter: Merge3_InitialOutput_l
   * Referenced by: '<S5>/Merge3'
   */
  0.0,

  /* Computed Parameter: Merge4_InitialOutput_g
   * Referenced by: '<S5>/Merge4'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S5>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S5>/Merge2'
   */
  0.0,

  /* Computed Parameter: Merge5_InitialOutput_e
   * Referenced by: '<S5>/Merge5'
   */
  0.0,

  /* Computed Parameter: Merge6_InitialOutput
   * Referenced by: '<S5>/Merge6'
   */
  0.0,

  /* Computed Parameter: Merge6_InitialOutput_b
   * Referenced by: '<S7>/Merge6'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput_n
   * Referenced by: '<S7>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput_e
   * Referenced by: '<S7>/Merge2'
   */
  0.0,

  /* Computed Parameter: Merge5_InitialOutput_n
   * Referenced by: '<S7>/Merge5'
   */
  0.0,

  /* Start of '<S37>/Static Friction Behavior' */
  {
    /* Expression: -1
     * Referenced by: '<S40>/Gain'
     */
    -1.0,

    /* Expression: 1
     * Referenced by: '<S40>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S37>/Static Friction Behavior' */

  /* Start of '<S37>/Kinetic Friction Behavior' */
  {
    /* Expression: -1
     * Referenced by: '<S39>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S39>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S37>/Kinetic Friction Behavior' */

  /* Start of '<S27>/Static Friction Behavior' */
  {
    /* Expression: -1
     * Referenced by: '<S36>/Gain'
     */
    -1.0,

    /* Expression: 1
     * Referenced by: '<S36>/Constant'
     */
    1.0
  }
  ,

  /* End of '<S27>/Static Friction Behavior' */

  /* Start of '<S27>/Kinetic Friction Behavior' */
  {
    /* Expression: -1
     * Referenced by: '<S35>/Gain'
     */
    -1.0,

    /* Expression: 0
     * Referenced by: '<S35>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S27>/Kinetic Friction Behavior' */

  /* Start of '<S24>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S25>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S24>/Enabled Subsystem' */

  /* Start of '<S6>/Enabled Subsystem' */
  {
    /* Expression: 1
     * Referenced by: '<S23>/Constant'
     */
    1.0
  }
  /* End of '<S6>/Enabled Subsystem' */
};
