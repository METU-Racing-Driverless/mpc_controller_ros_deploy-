/*
 * Simulation.h
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

#ifndef RTW_HEADER_Simulation_h_
#define RTW_HEADER_Simulation_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "Simulation_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_Simulation_T {
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T QRManager;
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T CholManager;
  real_T A_data[44521];
  real_T y_data[44521];
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T WorkingSet;
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T b_WorkingSet;
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T c_WorkingSet;
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T memspace;
  real_T B_data[24054];
  real_T h_data[24054];
  real_T rhs_data[24054];
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T TrialState;
  real_T A_data_m[800];
  real_T JacCineqTrans_data[588];
  real_T a__4_data[588];
  real_T Jc_data[504];
  real_T d_data[504];
  real_T unusedExpr[441];
  real_T Jx[384];
  real_T Jx_data[384];
  real_T varargin_1_data[384];
  s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T FcnEvaluator;
  real_T JacCeqTrans[336];
  real_T JacEqTrans_tmp[336];
  SL_Bus_Simulation_rosestimation_Waypoints In1;/* '<S89>/In1' */
  SL_Bus_Simulation_rosestimation_Waypoints b_varargout_2;
  real_T VectorConcatenate[256];       /* '<S36>/Vector Concatenate' */
  real_T b_Jx[256];
  real_T Au[256];
  real_T Auf_data[256];
  s_ollgpvqodLtAhexvVgD8pB_Simu_T QPObjective;
  real_T y_data_c[211];
  real_T y_data_k[211];
  real_T y_data_cx[211];
  real_T y_data_b[211];
  real_T y_data_p[211];
  real_T y_data_cv[211];
  real_T work_data[211];
  real_T work_data_f[211];
  real_T vn1_data[211];
  real_T vn2_data[211];
  real_T y_data_g[211];
  real_T work_data_g[211];
  real_T y_data_m[211];
  real_T y_data_n[211];
  real_T tmp_data[192];
  s_p8D01swky5RV3KRPR0QFHD_Simu_T expl_temp;
  s_p8D01swky5RV3KRPR0QFHD_Simu_T expl_temp_p;
  real_T b_data[128];
  real_T X[128];
  real_T Jmv[128];
  real_T tmp_data_l[128];
  real_T tmp_data_j[128];
  real_T c_data[114];
  real_T varargin_2_data[96];
  real_T waypoints_data[80];
  real_T Jx_data_d[64];
  sGG2r25KPyhmOjq8dWjrTNG_Simul_T expl_temp_g;
  sGG2r25KPyhmOjq8dWjrTNG_Simul_T expl_temp_l;
  real_T B_data_d[32];
  real_T Ju_data[32];
  real_T b_Bu[32];
  real_T Cineq_data[28];
  real_T a__3_data[28];
  real_T b_c_data[28];
  real_T c_data_d[24];
  real_T b_c[24];
  real_T b_c_data_l[24];
  real_T Je_data[24];
  real_T c_c[24];
  real_T c_c_data[24];
  real_T z0[21];
  real_T zUB[21];
  real_T z[21];
  real_T dv[21];
  real_T b_x[21];
  real_T xseq[20];                     /* '<S12>/NLMPC' */
  real_T X_o[20];
  real_T xa[20];
  real_T X_b[20];
  real_T b_X[20];
  real_T X_n[20];
  real_T b_X_b[20];
  real_T rtb_Selector_l[16];
  real_T Ceq[16];
  real_T Gfxu[16];
  real_T Ak[16];
  real_T Ak1[16];
  real_T reshapes_f1[16];
  real_T z_h[16];
  real_T yseq[15];                     /* '<S12>/NLMPC' */
  sG8JZ69axY52WWR6RKyApQC_Simul_T MeritFunction;
  SL_Bus_Simulation_rosestimation_Mpcparam In1_e;/* '<S88>/In1' */
  SL_Bus_Simulation_rosestimation_Mpcparam b_varargout_2_b;
  real_T Selector[12];                 /* '<S13>/Selector' */
  real_T Ck[12];
  real_T val[12];
  boolean_T b[80];
  real_T ua[10];
  real_T c_x[10];
  real_T U[10];
  real_T b_U[10];
  real_T U_d[10];
  real_T b_U_e[10];
  real_T Umv[10];
  somzaGboVhDG7PNQS6E98jD_Simul_T expl_temp_b;
  somzaGboVhDG7PNQS6E98jD_Simul_T expl_temp_j;
  somzaGboVhDG7PNQS6E98jD_Simul_T qpoptions;
  somzaGboVhDG7PNQS6E98jD_Simul_T qpoptions_f;
  somzaGboVhDG7PNQS6E98jD_Simul_T qpoptions_a;
  somzaGboVhDG7PNQS6E98jD_Simul_T qpoptions_j;
  somzaGboVhDG7PNQS6E98jD_Simul_T qpoptions_jz;
  somzaGboVhDG7PNQS6E98jD_Simul_T qpoptions_o;
  real_T rtb_Selector1_n[8];
  real_T Gfuu[8];
  real_T Bk1[8];
  real_T val_i[8];
  real_T y_o[8];
  sttYSJM5GCi2c1Eu0R50efC_Simul_T Out;
  real_T Selector1[6];                 /* '<S13>/Selector1' */
  int8_T f_data[40];
  int8_T Ae[32];
  int8_T ii_data[32];
  boolean_T x[32];
  int8_T Ae_data[32];
  real_T TmpSignalConversionAtToWork[4];/* '<Root>/Bicycle Model' */
  real_T dv1[4];
  real_T ic[4];
  real_T fk[4];
  real_T fk1[4];
  real_T b_X_n[4];
  real_T xk[4];
  real_T xa_m[4];
  real_T tmp_data_c[4];
  char_T vehicleInputs_data[30];
  d_cell_wrap_Simulation_T f;
  d_cell_wrap_Simulation_T g;
  d_cell_wrap_Simulation_T f_h;
  d_cell_wrap_Simulation_T g_c;
  char_T b_m[25];
  char_T vehicleInputs[25];
  char_T b_m3[25];
  char_T vehicleInputs_data_j[25];
  char_T b_ct[25];
  boolean_T icf[24];
  int8_T Je[24];
  int8_T b_data_p[24];
  int8_T d_data_p[24];
  boolean_T icf_e[24];
  int8_T d_data_a[24];
  SL_Bus_Simulation_geometry_msgs_Pose2D BusAssignment1;/* '<Root>/Bus Assignment1' */
  real_T Integrator[3];                /* '<S10>/Integrator' */
  int32_T ic_a[6];
  int32_T b_ic[6];
  real_T lookaheadStartPt[2];
  real_T lookaheadEndPt[2];
  real_T waypoints[2];
  real_T waypoints_a[2];
  real_T b_U_i[2];
  real_T refPt[2];
  boolean_T bv[12];
  boolean_T bv1[12];
  int32_T Jx_size[3];
  int32_T Jx_size_l[3];
  s7RdrPWkr8UPAUyTdDJkLaG_Simul_T Flags;
  real_T v;                            /* '<S1>/Integrator' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T v_dot;                        /* '<S1>/Gain1' */
  real_T SteeringAngle;                /* '<S37>/Atan' */
  real_T FilterCoefficient;            /* '<S72>/Filter Coefficient' */
  real_T Sum;                          /* '<S78>/Sum' */
  real_T IntegralGain;                 /* '<S66>/Integral Gain' */
  real_T y[80];                        /* '<S36>/MATLAB Function' */
  real_T Product1[20];                 /* '<S13>/Product1' */
  real_T LeftParameters[4];
  real_T RightParameters[4];
  real_T TargetPoint[2];
  real_T FromWorkspace[3];             /* '<S4>/From Workspace' */
  real_T Reshape[4];                   /* '<S12>/Reshape' */
  real_T mv[2];                        /* '<S12>/NLMPC' */
  real_T mvseq[10];                    /* '<S12>/NLMPC' */
  real_T nlpstatus;                    /* '<S12>/NLMPC' */
  real_T e;                            /* '<S12>/NLMPC' */
  real_T MATLABSystem[3];              /* '<S10>/MATLAB System' */
  real_T minDistance;
  real_T dist;
  real_T i;
  real_T lookaheadIdx;
  real_T waypoints_tmp;
  real_T waypoints_tmp_f;
  real_T b_c_i;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T optimRelativeFactor;
  real_T dx;
  real_T d_x;
  real_T b_a;
  real_T d_a_tmp_tmp;
  real_T e_f;
  real_T dx_g;
  real_T fk_tmp_tmp;
  real_T fk1_tmp_tmp;
  real_T dx_c;
  real_T runtimedata_OutputMin;
  real_T runtimedata_OutputMax;
  real_T f_idx_0;
  real_T f_idx_1;
  real_T f_idx_2;
  real_T ic_idx_0;
  real_T ic_idx_1;
  real_T ic_idx_2;
  real_T yk_idx_0_tmp;
  real_T yk_idx_1_tmp;
  real_T yk_idx_2_tmp;
  real_T runtimedata_OutputMin_tmp;
  real_T runtimedata_OutputMax_tmp;
  real_T s;
  real_T nrmGradInf;
  real_T nrmDirInf;
  real_T u1;
  real_T beta;
  real_T rho;
  real_T qpfvalLinearExcess;
  real_T qpfvalQuadExcess;
  real_T y_o3;
  real_T maxConstr_new;
  real_T normDelta;
  real_T s_l;
  real_T temp;
  real_T tempMaxConstr;
  real_T constrViolation_basicX;
  real_T c;
  real_T b_atmp;
  real_T xnorm;
  real_T a;
  real_T scale_m;
  real_T absxk_m;
  real_T t_c;
  real_T runtimedata_MVRateMin;
  real_T runtimedata_MVRateMax;
  real_T runtimedata_MVMin;
  real_T runtimedata_MVMax;
  real_T ic_idx_0_f;
  real_T oldDirIdx;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T smax;
  real_T s_p;
  real_T temp_e;
  real_T phi_alpha;
  real_T e_o;
  real_T fk_tmp;
  real_T yk_idx_0;
  real_T yk_idx_1;
  real_T yk_idx_2;
  real_T ic_idx_0_h;
  real_T ic_idx_1_l;
  real_T ic_idx_2_h;
  real_T ic_idx_3;
  real_T reshapes_f1_tmp;
  real_T reshapes_f1_tmp_m;
  real_T penaltyParamTrial;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  real_T c_m;
  real_T optimRelativeFactor_h;
  real_T nlpComplErrorTmp;
  real_T nlpDualFeasErrorTmp;
  real_T d;
  real_T MeritFunction_c;
  real_T tol_k;
  real_T c_p;
  real_T u0;
  real_T y_p;
  real_T denomTol;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio;
  real_T c_p4;
  real_T c_a;
  real_T c_c_j;
  real_T b_s;
  real_T b_temp;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T x_e;
  real_T lcon_data_idx_1;
  real_T lcon_data_idx_0;
  real_T rcon_data_idx_1;
  real_T rcon_data_idx_0;
  real_T tol_o;
  real_T tol_b;
  real_T ssq;
  real_T c_ao;
  real_T allFinite_tmp;
  real_T u1_g;
  real_T u1_e;
  real_T u1_f;
  real_T scale_h;
  real_T allFinite_tmp_e;
  SL_Bus_Simulation_std_msgs_Float64 In1_d;/* '<S87>/In1' */
  SL_Bus_Simulation_std_msgs_Float64 b_varargout_2_c;
  int32_T A_size[2];
  int32_T Cineq_size[2];
  int32_T JacCineqTrans_size[2];
  int32_T a__3_size[2];
  int32_T a__4_size[2];
  int32_T c_size[2];
  int32_T Jc_size[2];
  int32_T d_size[2];
  int32_T Jx_o[2];
  int32_T tmp_size[2];
  int32_T h_size[2];
  int32_T b_o[2];
  int32_T A_size_i[2];
  boolean_T icf_a[6];
  int32_T i_d;
  int32_T rtb_Selector1_tmp;
  int32_T b_size;
  int32_T B_size;
  int32_T f_size_idx_0;
  int32_T i_a;
  int32_T mIneq;
  int32_T mConstrMax;
  int32_T maxDims;
  int32_T mLB;
  int32_T mUB;
  int32_T mFixed;
  int32_T k;
  int32_T ix;
  int32_T ia;
  int32_T c_k;
  int32_T loop_ub;
  int32_T tmp_size_p;
  int32_T tmp_size_m;
  int32_T y_size_idx_0;
  int32_T mFixed_o;
  int32_T mIneq_n;
  int32_T mLB_l;
  int32_T mUB_p;
  int32_T b_k;
  int32_T ix_p;
  int32_T iy;
  int32_T c_f;
  int32_T ia_i;
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_ia;
  int32_T u1_o;
  int32_T mConstr_tmp;
  int32_T nVar_tmp_tmp;
  int32_T mLinIneq_tmp_tmp;
  int32_T e_k;
  int32_T Gfxu_tmp;
  int32_T k_k;
  int32_T i_i;
  int32_T fk_tmp_o;
  int32_T fk_tmp_tmp_m;
  int32_T fk1_tmp;
  int32_T cu_size;
  int32_T Je_size;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T c_k_c;
  int32_T i_f;
  int32_T i5;
  int32_T b_c_size;
  int32_T nVar;
  int32_T b_k_h;
  int32_T iH0;
  int32_T y_size_idx_0_m;
  int32_T nVarOrig;
  int32_T temp_a;
  int32_T mIneq_k;
  int32_T mLBOrig;
  int32_T idx_positive_tmp;
  int32_T i6;
  int32_T nVar_p;
  int32_T b_idx;
  int32_T y_size_idx_0_b;
  int32_T PROBTYPE_ORIG;
  int32_T mConstr;
  int32_T mEqFixed;
  int32_T nVar_tmp;
  int32_T activeSetChangeID;
  int32_T nVar_c;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T idx;
  int32_T idxRotGCol;
  int32_T iyend;
  int32_T b_ix_n;
  int32_T b_iy_i;
  int32_T c_iy;
  int32_T g_m;
  int32_T ia_j;
  int32_T loop_ub_e;
  int32_T y_size_idx_0_mv;
  int32_T nVar_tmp_tmp_m;
  int32_T nVar_j;
  int32_T ldq;
  int32_T ix_f;
  int32_T iy_a;
  int32_T d_g;
  int32_T ia_n;
  int32_T iAcol;
  int32_T br;
  int32_T b_ia_d;
  int32_T g_n;
  int32_T b_ic_c;
  int32_T mWConstr_tmp_tmp;
  int32_T b_idx_f;
  int32_T ix0;
  int32_T nVar_pm;
  int32_T mConstrMax_p;
  int32_T idx_Aineq;
  int32_T idx_upper;
  int32_T idx_Partition;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  int32_T iy_n;
  int32_T iac;
  int32_T b_ia_k;
  int32_T idx_Aineq_tmp;
  int32_T b_n;
  int32_T mTotalWorkingEq;
  int32_T idx_row;
  int32_T k_o;
  int32_T c_idx;
  int32_T e_idx;
  int32_T nVar_tmp_tmp_g;
  int32_T totalRank;
  int32_T ix_c;
  int32_T iy_c;
  int32_T k_m;
  int32_T ma;
  int32_T minmana;
  int32_T minmn;
  int32_T nfxd;
  int32_T ma_j;
  int32_T minmn_k;
  int32_T ii;
  int32_T nmi;
  int32_T mmi;
  int32_T pvt;
  int32_T k_mx;
  int32_T iQR0;
  int32_T idx_p;
  int32_T nVar_d;
  int32_T mFixed_g;
  int32_T mIneq_c;
  int32_T mLB_c;
  int32_T mUB_i;
  int32_T mLambda;
  int32_T nActiveConstr;
  int32_T rankR;
  int32_T iQR_diag;
  int32_T minDim;
  int32_T b_k_d;
  int32_T nVar_g;
  int32_T c_idx_l;
  int32_T b_ldw;
  int32_T A_maxDiag_idx;
  int32_T LD_diagOffset;
  int32_T order;
  int32_T ix_f1;
  int32_T mNull_tmp;
  int32_T rhs_size_idx_0;
  int32_T rhs_size_idx_1;
  int32_T A_maxDiag_idx_d;
  int32_T LD_diagOffset_j;
  int32_T order_i;
  int32_T b_k_h2;
  int32_T LDimSizeP1_tmp_tmp;
  int32_T nFixedConstr;
  int32_T nVar_n;
  int32_T idx_o;
  int32_T nDepIneq;
  int32_T ix0_c;
  int32_T k_b;
  int32_T nFixedConstr_e;
  int32_T nVar_dd;
  int32_T idx_i;
  int32_T nDepIneq_g;
  int32_T ix0_n;
  int32_T k_l;
  int32_T iy0;
  int32_T k_c;
  int32_T minmana_n;
  int32_T minmn_p;
  int32_T lda;
  int32_T b_idx_d;
  int32_T nWFixed;
  int32_T i_o;
};

/* Block states (default storage) for system '<Root>' */
struct DW_Simulation_T {
  nav_slalgs_internal_PurePursu_T obj; /* '<S6>/Pure Pursuit1' */
  robotics_slmobile_internal_bl_T obj_p;/* '<S10>/MATLAB System' */
  ros_slroscpp_internal_block_P_T obj_h;/* '<S5>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_c;/* '<S9>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_j;/* '<S8>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_c4;/* '<S7>/SourceBlock' */
  real_T x_Delay_DSTATE[20];           /* '<S13>/x_Delay' */
  real_T mv_Delay_DSTATE[10];          /* '<S13>/mv_Delay' */
  real_T slack_delay_DSTATE;           /* '<S13>/slack_delay' */
  real_T Memory_PreviousInput[2];      /* '<Root>/Memory' */
  real_T Memory_PreviousInput_a[2];    /* '<S4>/Memory' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S3>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S3>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S3>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S3>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<S3>/To Workspace5' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_j;               /* '<S36>/To Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S4>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S4>/From Workspace' */

  boolean_T objisempty;                /* '<S9>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S8>/SourceBlock' */
  boolean_T objisempty_g;              /* '<S7>/SourceBlock' */
  boolean_T objisempty_a;              /* '<S6>/Pure Pursuit1' */
  boolean_T objisempty_i;              /* '<S5>/SinkBlock' */
  boolean_T icLoad;                    /* '<S13>/x_Delay' */
  boolean_T icLoad_n;                  /* '<S13>/mv_Delay' */
  boolean_T icLoad_b;                  /* '<S13>/slack_delay' */
  boolean_T objisempty_d;              /* '<S10>/MATLAB System' */
  boolean_T PurePursuitController_MODE;/* '<Root>/Pure Pursuit Controller' */
  boolean_T MPCController_MODE;        /* '<Root>/MPC Controller' */
};

/* Continuous states (default storage) */
struct X_Simulation_T {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_m[3];       /* '<S10>/Integrator' */
  real_T Filter_CSTATE;                /* '<S64>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S69>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_Simulation_T {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator_CSTATE_m[3];       /* '<S10>/Integrator' */
  real_T Filter_CSTATE;                /* '<S64>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S69>/Integrator' */
};

/* State disabled  */
struct XDis_Simulation_T {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator_CSTATE_m[3];    /* '<S10>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S64>/Filter' */
  boolean_T Integrator_CSTATE_i;       /* '<S69>/Integrator' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_Simulation_T_ {
  real_T L;                            /* Variable: L
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T ld;                           /* Variable: ld
                                        * Referenced by:
                                        *   '<S6>/Pure Pursuit1'
                                        *   '<S37>/Constant2'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S63>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S66>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S64>/Filter'
                               */
  real_T PIDController1_InitialConditi_n;
                              /* Mask Parameter: PIDController1_InitialConditi_n
                               * Referenced by: '<S69>/Integrator'
                               */
  real_T BicycleKinematicModel_InitialSt[3];
                              /* Mask Parameter: BicycleKinematicModel_InitialSt
                               * Referenced by: '<S10>/Integrator'
                               */
  real_T BicycleKinematicModel_MaxSteeri;
                              /* Mask Parameter: BicycleKinematicModel_MaxSteeri
                               * Referenced by: '<S10>/MATLAB System'
                               */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S72>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S74>/Proportional Gain'
                                        */
  real_T BicycleKinematicModel_VehicleSp[2];
                              /* Mask Parameter: BicycleKinematicModel_VehicleSp
                               * Referenced by: '<S10>/MATLAB System'
                               */
  real_T BicycleKinematicModel_WheelBase;
                              /* Mask Parameter: BicycleKinematicModel_WheelBase
                               * Referenced by: '<S10>/MATLAB System'
                               */
  SL_Bus_Simulation_rosestimation_Waypoints Out1_Y0;/* Computed Parameter: Out1_Y0
                                                     * Referenced by: '<S89>/Out1'
                                                     */
  SL_Bus_Simulation_rosestimation_Waypoints Constant_Value;/* Computed Parameter: Constant_Value
                                                            * Referenced by: '<S9>/Constant'
                                                            */
  struct_D2HXSDhz1X0GfO61QVLFHG LogData_Y0;/* Computed Parameter: LogData_Y0
                                            * Referenced by: '<S4>/Log Data'
                                            */
  SL_Bus_Simulation_rosestimation_Mpcparam Out1_Y0_h;/* Computed Parameter: Out1_Y0_h
                                                      * Referenced by: '<S88>/Out1'
                                                      */
  SL_Bus_Simulation_rosestimation_Mpcparam Constant_Value_o;/* Computed Parameter: Constant_Value_o
                                                             * Referenced by: '<S8>/Constant'
                                                             */
  SL_Bus_Simulation_geometry_msgs_Pose2D Constant_Value_p;/* Computed Parameter: Constant_Value_p
                                                           * Referenced by: '<S2>/Constant'
                                                           */
  SL_Bus_Simulation_std_msgs_Float64 Out1_Y0_m;/* Computed Parameter: Out1_Y0_m
                                                * Referenced by: '<S87>/Out1'
                                                */
  SL_Bus_Simulation_std_msgs_Float64 Constant_Value_d;/* Computed Parameter: Constant_Value_d
                                                       * Referenced by: '<S7>/Constant'
                                                       */
  real_T ControlCommands_Y0;           /* Computed Parameter: ControlCommands_Y0
                                        * Referenced by: '<S4>/Control Commands'
                                        */
  real_T ones_Value[5];               /* Expression: ones(PredictionHorizon+1,1)
                                       * Referenced by: '<S13>/ones'
                                       */
  real_T Constant1_Value[3];           /* Expression: [0 0 0]
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S11>/md_zero'
                                        */
  real_T mvtarget_zero_Value[2];       /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/mv.target_zero'
                                        */
  real_T mvmin_zero_Value[2];          /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/mv.min_zero'
                                        */
  real_T mvmax_zero_Value[2];          /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/mv.max_zero'
                                        */
  real_T ymin_zero_Value[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S11>/y.min_zero'
                                        */
  real_T ymax_zero_Value[3];           /* Expression: zeros(3,1)
                                        * Referenced by: '<S11>/y.max_zero'
                                        */
  real_T dmvmin_zero_Value[2];         /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/dmv.min_zero'
                                        */
  real_T dmvmax_zero_Value[2];         /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/dmv.max_zero'
                                        */
  real_T xmin_zero_Value[4];           /* Expression: zeros(4,1)
                                        * Referenced by: '<S11>/x.min_zero'
                                        */
  real_T xmax_zero_Value[4];           /* Expression: zeros(4,1)
                                        * Referenced by: '<S11>/x.max_zero'
                                        */
  real_T ywt_zero_Value[3];            /* Expression: zeros(3,1)
                                        * Referenced by: '<S11>/y.wt_zero'
                                        */
  real_T mvwt_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/mv.wt_zero'
                                        */
  real_T dmvwt_zero_Value[2];          /* Expression: zeros(2,1)
                                        * Referenced by: '<S11>/dmv.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S11>/ecr.wt_zero'
                                        */
  real_T Constant1_Value_p[3];         /* Expression: 2:max(2,PredictionHorizon)
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant_Value_di[3];
                 /* Expression: min(3,PredictionHorizon+1):(PredictionHorizon+1)
                  * Referenced by: '<S13>/Constant'
                  */
  real_T einit_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S11>/e.init_zero'
                                        */
  real_T PurePursuit1_DesiredLinearVeloc;/* Expression: 10
                                          * Referenced by: '<S6>/Pure Pursuit1'
                                          */
  real_T PurePursuit1_MaxAngularVelocity;/* Expression: 9*pi
                                          * Referenced by: '<S6>/Pure Pursuit1'
                                          */
  real_T ControlCommands_Y0_c;       /* Computed Parameter: ControlCommands_Y0_c
                                      * Referenced by: '<S6>/Control Commands'
                                      */
  real_T Constant_Value_k;             /* Expression: 2
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 2.3
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.3
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Simulation_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Simulation_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Simulation_T Simulation_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_Simulation_T Simulation_B;

#ifdef __cplusplus

}
#endif

/* Continuous states (default storage) */
extern X_Simulation_T Simulation_X;

/* Block states (default storage) */
extern struct DW_Simulation_T Simulation_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void Simulation_initialize(void);
  extern void Simulation_step(void);
  extern void Simulation_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Simulation_T *const Simulation_M;

#ifdef __cplusplus

}
#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S15>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S16>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S17>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S18>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S19>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S20>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S21>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S22>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S23>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S24>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S25>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S26>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S27>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S28>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S29>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S30>/Vector Dimension Check' : Unused code path elimination
 * Block '<S31>/Vector Dimension Check' : Unused code path elimination
 * Block '<S32>/Vector Dimension Check' : Unused code path elimination
 * Block '<S33>/Vector Dimension Check' : Unused code path elimination
 * Block '<S11>/mv.init_zero' : Unused code path elimination
 * Block '<S11>/x.init_zero' : Unused code path elimination
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S10>/Reshape' : Reshape block reduction
 * Block '<S12>/Reshape1' : Reshape block reduction
 * Block '<S12>/mo or x Conversion' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion1' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion10' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion11' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion12' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion13' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion14' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion15' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion16' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion17' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion18' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion19' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion2' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion3' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion4' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion5' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion6' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion7' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion8' : Eliminate redundant data type conversion
 * Block '<S12>/mo or x Conversion9' : Eliminate redundant data type conversion
 * Block '<S13>/reshape_mv' : Reshape block reduction
 */

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
 * '<Root>' : 'Simulation'
 * '<S1>'   : 'Simulation/Bicycle Model'
 * '<S2>'   : 'Simulation/Blank Message1'
 * '<S3>'   : 'Simulation/Log Data'
 * '<S4>'   : 'Simulation/MPC Controller'
 * '<S5>'   : 'Simulation/Publish1'
 * '<S6>'   : 'Simulation/Pure Pursuit Controller'
 * '<S7>'   : 'Simulation/Subscribe'
 * '<S8>'   : 'Simulation/Subscribe1'
 * '<S9>'   : 'Simulation/Subscribe2'
 * '<S10>'  : 'Simulation/Bicycle Model/Bicycle Kinematic Model'
 * '<S11>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller'
 * '<S12>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC'
 * '<S13>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/xmvs_router'
 * '<S14>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check'
 * '<S15>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S16>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check10'
 * '<S17>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check11'
 * '<S18>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check12'
 * '<S19>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check13'
 * '<S20>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check14'
 * '<S21>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check15'
 * '<S22>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check16'
 * '<S23>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check3'
 * '<S24>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check4'
 * '<S25>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check5'
 * '<S26>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check6'
 * '<S27>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check7'
 * '<S28>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check8'
 * '<S29>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Preview Signal Check9'
 * '<S30>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S31>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Scalar Signal Check2'
 * '<S32>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S33>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/MPC Vector Signal Check11'
 * '<S34>'  : 'Simulation/MPC Controller/Nonlinear MPC Controller/MPC/NLMPC'
 * '<S35>'  : 'Simulation/Pure Pursuit Controller/PID Controller1'
 * '<S36>'  : 'Simulation/Pure Pursuit Controller/Remove Zeros'
 * '<S37>'  : 'Simulation/Pure Pursuit Controller/TargetDir to Steering Angle'
 * '<S38>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Anti-windup'
 * '<S39>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/D Gain'
 * '<S40>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Filter'
 * '<S41>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Filter ICs'
 * '<S42>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/I Gain'
 * '<S43>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Ideal P Gain'
 * '<S44>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S45>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Integrator'
 * '<S46>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Integrator ICs'
 * '<S47>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/N Copy'
 * '<S48>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/N Gain'
 * '<S49>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/P Copy'
 * '<S50>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Parallel P Gain'
 * '<S51>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Reset Signal'
 * '<S52>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Saturation'
 * '<S53>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Saturation Fdbk'
 * '<S54>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Sum'
 * '<S55>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Sum Fdbk'
 * '<S56>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tracking Mode'
 * '<S57>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tracking Mode Sum'
 * '<S58>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tsamp - Integral'
 * '<S59>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tsamp - Ngain'
 * '<S60>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/postSat Signal'
 * '<S61>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/preSat Signal'
 * '<S62>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Anti-windup/Passthrough'
 * '<S63>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/D Gain/Internal Parameters'
 * '<S64>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Filter/Cont. Filter'
 * '<S65>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S66>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/I Gain/Internal Parameters'
 * '<S67>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S68>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S69>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Integrator/Continuous'
 * '<S70>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S71>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/N Copy/Disabled'
 * '<S72>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/N Gain/Internal Parameters'
 * '<S73>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/P Copy/Disabled'
 * '<S74>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S75>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Reset Signal/Disabled'
 * '<S76>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Saturation/Passthrough'
 * '<S77>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S78>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Sum/Sum_PID'
 * '<S79>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S80>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S81>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S82>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S83>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S84>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S85>'  : 'Simulation/Pure Pursuit Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S86>'  : 'Simulation/Pure Pursuit Controller/Remove Zeros/MATLAB Function'
 * '<S87>'  : 'Simulation/Subscribe/Enabled Subsystem'
 * '<S88>'  : 'Simulation/Subscribe1/Enabled Subsystem'
 * '<S89>'  : 'Simulation/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_Simulation_h_ */
