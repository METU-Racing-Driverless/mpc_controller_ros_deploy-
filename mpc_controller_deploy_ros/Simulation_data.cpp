/*
 * Simulation_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulation".
 *
 * Model version              : 3.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Sat Feb 19 16:53:48 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Simulation.h"
#include "Simulation_private.h"

/* Block parameters (default storage) */
P_Simulation_T Simulation_P = {
  /* Variable: L
   * Referenced by: '<S37>/Constant1'
   */
  1.0,

  /* Variable: ld
   * Referenced by:
   *   '<S6>/Pure Pursuit1'
   *   '<S37>/Constant2'
   */
  6.0,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S63>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S66>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S64>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_n
   * Referenced by: '<S69>/Integrator'
   */
  0.0,

  /* Mask Parameter: BicycleKinematicModel_InitialSt
   * Referenced by: '<S10>/Integrator'
   */
  { 0.0, 0.0, 0.0 },

  /* Mask Parameter: BicycleKinematicModel_MaxSteeri
   * Referenced by: '<S10>/MATLAB System'
   */
  0.78539816339744828,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S72>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S74>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: BicycleKinematicModel_VehicleSp
   * Referenced by: '<S10>/MATLAB System'
   */
  { 0.0, 0.0 },

  /* Mask Parameter: BicycleKinematicModel_WheelBase
   * Referenced by: '<S10>/MATLAB System'
   */
  1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S89>/Out1'
   */
  {
    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  /* X */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    },                                 /* X_SL_Info */

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  /* Y */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    }                                  /* Y_SL_Info */
  },

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S9>/Constant'
   */
  {
    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  /* X */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    },                                 /* X_SL_Info */

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  /* Y */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    }                                  /* Y_SL_Info */
  },

  /* Computed Parameter: LogData_Y0
   * Referenced by: '<S4>/Log Data'
   */
  {
    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    }
    ,                                  /* yseq */
    0.0,                               /* nlpstatus */

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  /* LeftParameters */

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  /* RightParameters */

    {
      0.0, 0.0 }
    /* TargetPoint */
  },

  /* Computed Parameter: Out1_Y0_h
   * Referenced by: '<S88>/Out1'
   */
  {
    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  /* LeftParameters */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    },                                 /* LeftParameters_SL_Info */

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  /* RightParameters */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    },                                 /* RightParameters_SL_Info */

    {
      0.0, 0.0 }
    ,                                  /* TargetPoint */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    }                                  /* TargetPoint_SL_Info */
  },

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S8>/Constant'
   */
  {
    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  /* LeftParameters */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    },                                 /* LeftParameters_SL_Info */

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  /* RightParameters */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    },                                 /* RightParameters_SL_Info */

    {
      0.0, 0.0 }
    ,                                  /* TargetPoint */

    {
      0U,                              /* CurrentLength */
      0U                               /* ReceivedLength */
    }                                  /* TargetPoint_SL_Info */
  },

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S2>/Constant'
   */
  {
    0.0,                               /* X */
    0.0,                               /* Y */
    0.0                                /* Theta */
  },

  /* Computed Parameter: Out1_Y0_m
   * Referenced by: '<S87>/Out1'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S7>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: ControlCommands_Y0
   * Referenced by: '<S4>/Control Commands'
   */
  0.0,

  /* Expression: ones(PredictionHorizon+1,1)
   * Referenced by: '<S13>/ones'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: [0 0 0]
   * Referenced by: '<S4>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S4>/Memory'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S11>/md_zero'
   */
  0.0,

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/mv.target_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/mv.min_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/mv.max_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(3,1)
   * Referenced by: '<S11>/y.min_zero'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: zeros(3,1)
   * Referenced by: '<S11>/y.max_zero'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/dmv.min_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/dmv.max_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S11>/x.min_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S11>/x.max_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(3,1)
   * Referenced by: '<S11>/y.wt_zero'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/mv.wt_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S11>/dmv.wt_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S11>/ecr.wt_zero'
   */
  0.0,

  /* Expression: 2:max(2,PredictionHorizon)
   * Referenced by: '<S13>/Constant1'
   */
  { 2.0, 3.0, 4.0 },

  /* Expression: min(3,PredictionHorizon+1):(PredictionHorizon+1)
   * Referenced by: '<S13>/Constant'
   */
  { 3.0, 4.0, 5.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S11>/e.init_zero'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S6>/Pure Pursuit1'
   */
  10.0,

  /* Expression: 9*pi
   * Referenced by: '<S6>/Pure Pursuit1'
   */
  28.274333882308138,

  /* Computed Parameter: ControlCommands_Y0_c
   * Referenced by: '<S6>/Control Commands'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S37>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Expression: 2.3
   * Referenced by: '<S1>/Gain'
   */
  2.3,

  /* Expression: 0.3
   * Referenced by: '<S1>/Gain1'
   */
  0.3
};
