/*
 * Simulation.cpp
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

/* Block signals (default storage) */
B_Simulation_T Simulation_B;

/* Continuous states */
X_Simulation_T Simulation_X;

/* Block states (default storage) */
DW_Simulation_T Simulation_DW;

/* Real-time model */
RT_MODEL_Simulation_T Simulation_M_ = RT_MODEL_Simulation_T();
RT_MODEL_Simulation_T *const Simulation_M = &Simulation_M_;

/* Forward declaration for local functions */
static void BicycleKinematics_assignModelPr(robotics_slmobile_internal_bl_T *obj);
static void Simulation_SystemCore_setup(robotics_slmobile_internal_bl_T *obj);
static void Simulation_znlmpc_getXUe(const real_T z[21], const real_T x[4],
  real_T X[20], real_T U[10], real_T *e);
static void Simulation_mtimes(const real_T A_data[], const int32_T A_size[2],
  real_T C_data[], int32_T C_size[2]);
static void Simulation_znlmpc_getUBounds(const real_T runtimedata_lastMV[2],
  const real_T runtimedata_MVMin[8], const real_T runtimedata_MVMax[8], const
  real_T runtimedata_MVRateMin[8], const real_T runtimedata_MVRateMax[8], real_T
  A_data[], int32_T A_size[2], real_T Bu_data[], int32_T *Bu_size);
static void Sim_znlmpc_computeJacobianState(const real_T f0[4], real_T x0[4],
  real_T u0[2], real_T Jx[16], real_T Jmv[8]);
static void Simulation_all(const boolean_T x[12], boolean_T y[3]);
static boolean_T Simulation_any(const boolean_T x[6]);
static void Simulatio_znlmpc_reformJacobian(const real_T Jx_data[], const
  int32_T Jx_size[3], const real_T Jmv_data[], const real_T Je_data[], const
  int32_T *Je_size, real_T Jc_data[], int32_T Jc_size[2]);
static void Simulation_outputBounds(const real_T runtimedata_OutputMin[12],
  const real_T runtimedata_OutputMax[12], const real_T X[20], real_T e, real_T
  c_data[], int32_T c_size[2], real_T Jc_data[], int32_T Jc_size[2]);
static void Simulation_ConstraintFunction(const real_T X[20], const real_T
  lcircle[4], const real_T rcircle[4], real_T cineq_data[], int32_T *cineq_size);
static void Simulat_eML_blk_kernel_anonFcn2(const real_T runtimedata_x[4], const
  real_T runtimedata_OutputMin[12], const real_T runtimedata_OutputMax[12],
  const real_T runtimedata_Parameters_f1[4], const real_T
  runtimedata_Parameters_f2[4], const real_T z[21], real_T varargout_1_data[],
  int32_T varargout_1_size[2], real_T varargout_2[16], real_T varargout_3_data[],
  int32_T varargout_3_size[2], real_T varargout_4[336]);
static void Simulation_factoryConstruct(int32_T nVarMax, int32_T mConstrMax,
  int32_T mIneq, int32_T mNonlinIneq, s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *obj);
static void Simulatio_factoryConstruct_cyd0(int32_T MaxVars, int32_T
  *obj_grad_size, int32_T *obj_Hx_size, boolean_T *obj_hasLinear, int32_T
  *obj_nvar, int32_T *obj_maxVar, real_T *obj_beta, real_T *obj_rho, int32_T
  *obj_objtype, int32_T *obj_prev_objtype, int32_T *obj_prev_nvar, boolean_T
  *obj_prev_hasLinear, real_T *obj_gammaScalar);
static void Simulati_factoryConstruct_cyd03(int32_T mIneqMax, int32_T nVarMax,
  int32_T mConstrMax, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj);
static void Simulation_loadProblem(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj, int32_T
  mIneq, int32_T mLinIneq, const real_T Aineq_data[], int32_T mLB, int32_T mUB,
  int32_T mFixed, int32_T mConstrMax);
static int32_T Simulation_checkVectorNonFinite(int32_T N, const real_T vec_data[],
  int32_T iv0);
static int32_T Simulati_checkVectorNonFinite_c(const real_T vec[16]);
static int32_T Simulation_checkMatrixNonFinite(int32_T ncols, const real_T
  mat_data[], int32_T col0, int32_T ldm);
static void evalObjAndConstrAndDerivatives(const real_T
  obj_objfun_workspace_runtimedat[4], const real_T
  obj_objfun_workspace_runtimed_0[2], const real_T
  obj_nonlcon_workspace_runtimeda[4], const real_T
  obj_nonlcon_workspace_runtime_0[12], const real_T
  obj_nonlcon_workspace_runtime_1[12], const real_T
  obj_nonlcon_workspace_runtime_2[4], const real_T
  obj_nonlcon_workspace_runtime_3[4], int32_T obj_mCineq, const real_T x[21],
  real_T grad_workspace_data[], real_T Cineq_workspace_data[], int32_T ineq0,
  real_T Ceq_workspace[16], real_T JacIneqTrans_workspace_data[], int32_T
  iJI_col, int32_T ldJI, real_T JacEqTrans_workspace_data[], int32_T ldJE,
  real_T *fval, int32_T *status);
static void Simula_updateWorkingSetForNewQP(const real_T xk[21],
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet, int32_T mIneq, const real_T
  cIneq_data[], const real_T cEq[16], int32_T mLB, const real_T lb[21], int32_T
  mUB, const real_T ub[21], int32_T mFixed);
static void Simulat_modifyOverheadPhaseOne_(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj);
static void Simulation_setProblemType(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T PROBLEM_TYPE);
static void Simulation_initActiveSet(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj);
static void Simulation_factoryConstruct_cy(int32_T maxRows, int32_T maxCols,
  int32_T *obj_ldq, int32_T obj_QR_size[2], real_T obj_Q_data[], int32_T
  obj_Q_size[2], int32_T obj_jpvt_data[], int32_T *obj_jpvt_size, int32_T
  *obj_mrows, int32_T *obj_ncols, int32_T *obj_tau_size, int32_T *obj_minRowCol,
  boolean_T *obj_usedPivoting);
static void Simulation_factoryConstruct_cyd(int32_T MaxDims, int32_T
  obj_FMat_size[2], int32_T *obj_ldm, int32_T *obj_ndims, int32_T *obj_info,
  real_T *obj_scaleFactor, boolean_T *obj_ConvexCheck, real_T *obj_regTol_,
  real_T *obj_workspace_, real_T *obj_workspace2_);
static void Simulation_xgemv(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
static void Simulation_computeGradLag(real_T workspace_data[], int32_T ldA,
  int32_T nVar, const real_T grad_data[], int32_T mIneq, const real_T
  AineqTrans_data[], const real_T AeqTrans_data[], const int32_T
  finiteFixed_data[], int32_T mFixed, const int32_T finiteLB_data[], int32_T mLB,
  const int32_T finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
static real_T Simulati_computePrimalFeasError(const real_T x[21], int32_T
  mLinIneq, int32_T mNonlinIneq, const real_T cIneq_data[], const real_T cEq[16],
  const int32_T finiteLB_data[], int32_T mLB, const real_T lb[21], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[21]);
static void Simulation_computeDualFeasError(int32_T nVar, const real_T
  gradLag_data[], boolean_T *gradOK, real_T *val);
static void Simulation_saveJacobian(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *obj,
  int32_T nVar, int32_T mIneq, const real_T JacCineqTrans_data[], int32_T
  ineqCol0, const real_T JacCeqTrans_data[], int32_T ldJ);
static void Simulation_saveState(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *obj);
static real_T Simulation_computeComplError(const int32_T
  *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
  const real_T xCurrent[21], int32_T mIneq, const real_T cIneq_data[], const
  int32_T finiteLB_data[], int32_T mLB, const real_T lb[21], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[21], const real_T lambda_data[],
  int32_T iL0);
static void Simulation_xgemv_l(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
static void Simulation_computeGradLag_p(real_T workspace_data[], int32_T ldA,
  int32_T nVar, const real_T grad_data[], int32_T mIneq, const real_T
  AineqTrans_data[], const real_T AeqTrans_data[], const int32_T
  finiteFixed_data[], int32_T mFixed, const int32_T finiteLB_data[], int32_T mLB,
  const int32_T finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
static void Simulati_computeDualFeasError_l(int32_T nVar, const real_T
  gradLag_data[], boolean_T *gradOK, real_T *val);
static void Simu_updateWorkingSetForNewQP_m(const real_T xk[21],
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet, int32_T mIneq, int32_T
  mNonlinIneq, const real_T cIneq_data[], const real_T cEq[16], int32_T mLB,
  const real_T lb[21], int32_T mUB, const real_T ub[21], int32_T mFixed);
static real_T Simulation_xnrm2(int32_T n, const real_T x_data[], int32_T ix0);
static real_T Simulation_xzlarfg(int32_T n, real_T *alpha1, real_T x_data[],
  int32_T ix0);
static void Simulation_xgemv_la(int32_T m, int32_T n, const real_T A_data[],
  int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
static void Simulation_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y_data[], real_T A_data[], int32_T ia0, int32_T lda);
static void Simulation_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C_data[], int32_T ic0, int32_T ldc, real_T work_data[]);
static void Simulation_qrf(real_T A_data[], const int32_T A_size[2], int32_T m,
  int32_T n, int32_T nfxd, real_T tau_data[]);
static void Simulation_xswap(int32_T n, real_T x_data[], int32_T ix0, int32_T
  iy0);
static void Simulation_qrpf(real_T A_data[], const int32_T A_size[2], int32_T m,
  int32_T n, int32_T nfxd, real_T tau_data[], int32_T jpvt_data[]);
static void Simulation_xgeqp3(real_T A_data[], const int32_T A_size[2], int32_T
  m, int32_T n, int32_T jpvt_data[], real_T tau_data[], int32_T *tau_size);
static void Simulation_computeQ_(s_ASr52t7t39LT7rtZ8hZCX_Simul_T *obj, int32_T
  nrows);
static void Simulation_xgemv_la4(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], real_T y_data[]);
static void Simulation_xtrsv(int32_T n, const real_T A_data[], int32_T lda,
  real_T x_data[]);
static void Simulation_computeLambdaLSQ(int32_T nVar, int32_T mConstr,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager, const real_T ATwset_data[],
  int32_T ldA, const real_T grad_data[], real_T lambdaLSQ_data[], real_T
  workspace_data[]);
static void Simulation_sortLambdaQP(real_T lambda_data[], int32_T
  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[], const int32_T
  WorkingSet_Wlocalidx_data[], real_T workspace_data[]);
static int32_T Simulation_ixamax(int32_T n, const real_T x_data[]);
static void Simulation_test_exit(s7RdrPWkr8UPAUyTdDJkLaG_Simul_T *Flags,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, sG8JZ69axY52WWR6RKyApQC_Simul_T
  *MeritFunction, const int32_T *fscales_lineq_constraint_size, const int32_T
  *fscales_cineq_constraint_size, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet,
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *QRManager, const real_T lb[21], const real_T ub[21]);
static void Simulation_xgemv_la4x4rhx2l0j(int32_T m, int32_T n, const real_T
  A_data[], int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0, real_T
  y_data[]);
static boolean_T Simulation_BFGSUpdate(int32_T nvar, real_T Bk[441], const
  real_T sk_data[], real_T yk_data[], real_T workspace_data[]);
static int32_T Simulati_ComputeNumDependentEq_(s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *qrmanager, const real_T beqf_data[], int32_T mConstr, int32_T nVar);
static void Simulation_IndexOfDependentEq_(int32_T depIdx_data[], int32_T mFixed,
  int32_T nDep, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, int32_T mRows,
  int32_T nCols);
static void Simulation_countsort(int32_T x_data[], int32_T xLen, int32_T
  workspace_data[], int32_T xMin, int32_T xMax);
static void Simulation_removeConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T idx_global);
static int32_T Simulation_RemoveDependentEq_(s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager);
static void Simulation_removeAllIneqConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj);
static void Simulation_RemoveDependentIneq_(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace);
static void Simulation_xgeqrf(real_T A_data[], const int32_T A_size[2], int32_T
  m, int32_T n, real_T tau_data[], int32_T *tau_size);
static void Simulation_factorQR(s_ASr52t7t39LT7rtZ8hZCX_Simul_T *obj, const
  real_T A_data[], int32_T mrows, int32_T ncols, int32_T ldA);
static void Simulation_xgemv_la4x4(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], real_T y_data[]);
static void Simulation_xgemv_la4x(int32_T n, const real_T A_data[], int32_T lda,
  const real_T x_data[], real_T y_data[]);
static real_T Simulati_maxConstraintViolation(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *obj, const real_T x_data[]);
static void Simulation_xgemv_la4x4r(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[]);
static real_T Simula_maxConstraintViolation_e(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *obj, const real_T x_data[], int32_T ix0);
static boolean_T Simulat_feasibleX0ForWorkingSet(real_T workspace_data[], const
  int32_T workspace_size[2], real_T xCurrent_data[],
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *qrmanager);
static void Simulati_RemoveDependentIneq__a(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace);
static void Simulation_xgemv_la4x4rhx(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], real_T y_data[]);
static void Simulation_xgemv_la4x4rh(int32_T n, const real_T A_data[], int32_T
  lda, const real_T x_data[], real_T y_data[]);
static real_T Simul_maxConstraintViolation_e4(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *obj, const real_T x_data[]);
static void Simulation_PresolveWorkingSet(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
  *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace,
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *qrmanager);
static void Simulation_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace_data[], const real_T H[441], const real_T f_data[], const
  real_T x_data[]);
static real_T Simulation_computeFval(const s_ollgpvqodLtAhexvVgD8pB_Simu_T *obj,
  real_T workspace_data[], const real_T H[441], const real_T f_data[], const
  real_T x_data[]);
static void Simulation_xgemv_la4x4rhx2(int32_T m, int32_T n, const real_T A[441],
  int32_T lda, const real_T x_data[], real_T y_data[]);
static void Simulation_computeGrad_StoreHx(s_ollgpvqodLtAhexvVgD8pB_Simu_T *obj,
  const real_T H[441], const real_T f_data[], const real_T x_data[]);
static real_T Simulation_computeFval_ReuseHx(const
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *obj, real_T workspace_data[], const real_T
  f_data[], const real_T x_data[]);
static void Simulation_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void Simulation_deleteColMoveEnd(s_ASr52t7t39LT7rtZ8hZCX_Simul_T *obj,
  int32_T idx);
static boolean_T Simulation_strcmp(const char_T a[7]);
static void Simulation_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[441],
  int32_T lda, const real_T B_data[], int32_T ib0, int32_T ldb, real_T C_data[],
  int32_T ldc);
static void Simulation_xgemm_b(int32_T m, int32_T n, int32_T k, const real_T
  A_data[], int32_T ia0, int32_T lda, const real_T B_data[], int32_T ldb, real_T
  C_data[], int32_T ldc);
static int32_T Simulation_ixamax_k(int32_T n, const real_T x_data[], int32_T
  incx);
static void Simulation_fullColLDL2_(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj,
  int32_T LD_offset, int32_T NColsRemain);
static void Simulation_partialColLDL3_(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj,
  int32_T LD_offset, int32_T NColsRemain);
static int32_T Simulation_xpotrf(int32_T n, real_T A_data[], int32_T lda);
static void Simulation_xgemv_la4x4rhx2l(int32_T m, int32_T n, const real_T
  A_data[], int32_T ia0, int32_T lda, const real_T x_data[], real_T y_data[]);
static void Simulation_factor(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj, const real_T
  A[441], int32_T ndims, int32_T ldA);
static void Simulation_solve(const s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj, real_T
  rhs_data[]);
static void Simulation_factor_b(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj, const
  real_T A[441], int32_T ndims, int32_T ldA);
static void Simulation_solve_b(const s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj,
  real_T rhs_data[]);
static void Simulation_compute_deltax(const real_T H[441],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, const s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *cholmanager, const
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective, boolean_T alwaysPositiveDef);
static real_T Simulation_xnrm2_e(int32_T n, const real_T x_data[]);
static void Simulation_xgemv_la4x4rhx2l0(int32_T m, int32_T n, const real_T
  A_data[], int32_T lda, const real_T x_data[], real_T y_data[]);
static void Simulation_feasibleratiotest(const real_T solution_xstar_data[],
  const real_T solution_searchDir_data[], real_T workspace_data[], const int32_T
  workspace_size[2], int32_T workingset_nVar, int32_T workingset_ldA, const
  real_T workingset_Aineq_data[], const real_T workingset_bineq_data[], const
  real_T workingset_lb_data[], const real_T workingset_ub_data[], const int32_T
  workingset_indexLB_data[], const int32_T workingset_indexUB_data[], const
  int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const
  boolean_T workingset_isActiveConstr_data[], const int32_T workingset_nWConstr
  [5], boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
  *constrType, int32_T *constrIdx);
static void Simula_checkUnboundedOrIllPosed(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
  *solution, const s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective);
static void Simu_addBoundToActiveSetMatrix_(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T TYPE, int32_T idx_local);
static void Simulation_addAineqConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T idx_local);
static void Simu_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, const
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval);
static void Simulation_iterate(const real_T H[441], const real_T f_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *cholmanager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective, const char_T
  options_SolverName[7], real_T options_StepTolerance, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations);
static void Simulation_phaseone(const real_T H[441], const real_T f_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *cholmanager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective,
  somzaGboVhDG7PNQS6E98jD_Simul_T *options, const
  somzaGboVhDG7PNQS6E98jD_Simul_T *runTimeOptions);
static void Simulation_driver_b(const real_T H[441], const real_T f_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *cholmanager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective,
  somzaGboVhDG7PNQS6E98jD_Simul_T *options, somzaGboVhDG7PNQS6E98jD_Simul_T
  *runTimeOptions);
static void Simulation_addAeqConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T idx_local);
static boolean_T Simulation_soc(const real_T Hessian[441], const real_T
  grad_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *
  QPObjective, const somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions);
static void Simulation_normal(const real_T Hessian[441], const real_T grad_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState, sG8JZ69axY52WWR6RKyApQC_Simul_T
  *MeritFunction, s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace,
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *QRManager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager,
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *QPObjective, const
  somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions);
static void Simulation_relaxed(const real_T Hessian[441], const real_T
  grad_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Simul_T *MeritFunction,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions);
static boolean_T Simulation_step_h(int32_T *STEP_TYPE, real_T Hessian[441],
  const real_T lb[21], const real_T ub[21], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
  *TrialState, sG8JZ69axY52WWR6RKyApQC_Simul_T *MeritFunction,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions);
static void Simulation_evalObjAndConstr(const real_T
  obj_objfun_workspace_runtimedat[4], const real_T
  obj_objfun_workspace_runtimed_0[2], const real_T
  obj_nonlcon_workspace_runtimeda[4], const real_T
  obj_nonlcon_workspace_runtime_0[12], const real_T
  obj_nonlcon_workspace_runtime_1[12], const real_T
  obj_nonlcon_workspace_runtime_2[4], const real_T
  obj_nonlcon_workspace_runtime_3[4], int32_T obj_mCineq, const real_T x[21],
  real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[16], real_T
  *fval, int32_T *status);
static void Simulati_computeLinearResiduals(const real_T x[21], int32_T nVar,
  real_T workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T
  mLinIneq, const real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi);
static real_T Simulation_computeMeritFcn(real_T obj_penaltyParam, real_T fval,
  const real_T Cineq_workspace_data[], int32_T mIneq, const real_T
  Ceq_workspace[16], boolean_T evalWellDefined);
static void Simulation_linesearch(boolean_T *evalWellDefined, const real_T
  bineq_data[], int32_T WorkingSet_nVar, int32_T WorkingSet_ldA, const real_T
  WorkingSet_Aineq_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState, real_T
  MeritFunction_penaltyParam, real_T MeritFunction_phi, real_T
  MeritFunction_phiPrimePlus, real_T MeritFunction_phiFullStep, const real_T
  FcnEvaluator_objfun_workspace_r[4], const real_T
  FcnEvaluator_objfun_workspace_0[2], const real_T
  FcnEvaluator_nonlcon_workspace_[4], const real_T
  FcnEvaluator_nonlcon_workspac_0[12], const real_T
  FcnEvaluator_nonlcon_workspac_1[12], const cell_0_Simulation_T
  *FcnEvaluator_nonlcon_workspac_2, int32_T FcnEvaluator_mCineq, boolean_T
  socTaken, real_T *alpha, int32_T *exitflag);
static void Simulation_driver(const real_T bineq_data[], const real_T lb[21],
  const real_T ub[21], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Simul_T *MeritFunction, const
  s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T *FcnEvaluator, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *QPObjective, const int32_T
  *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
  real_T Hessian[441]);
static void Simulation_fmincon(const s_p8D01swky5RV3KRPR0QFHD_Simu_T
  *fun_workspace_runtimedata, const sGG2r25KPyhmOjq8dWjrTNG_Simul_T
  *fun_workspace_userdata, const real_T x0[21], const real_T Aineq_data[], const
  real_T bineq_data[], const int32_T *bineq_size, const real_T lb[21], const
  real_T ub[21], const s_p8D01swky5RV3KRPR0QFHD_Simu_T
  *nonlcon_workspace_runtimedata, const sGG2r25KPyhmOjq8dWjrTNG_Simul_T
  *nonlcon_workspace_userdata, real_T x[21], real_T *fval, real_T *exitflag,
  sttYSJM5GCi2c1Eu0R50efC_Simul_T *output);
static void Simulation_nonzeros(const real_T s[128], real_T v_data[], int32_T
  *v_size);
static real_T Simulation_norm(const real_T x[2]);
static void Simulation_closestPointOnLine(const real_T pt1[2], const real_T pt2
  [2], const real_T refPt[2], real_T closestPoint[2], real_T *distance);
int32_T div_nzp_s32(int32_T numerator, int32_T denominator)
{
  uint32_T tempAbsQuotient;
  tempAbsQuotient = (numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
                     static_cast<uint32_T>(numerator)) / (denominator < 0 ? ~
    static_cast<uint32_T>(denominator) + 1U : static_cast<uint32_T>(denominator));
  return (numerator < 0) != (denominator < 0) ? -static_cast<int32_T>
    (tempAbsQuotient) : static_cast<int32_T>(tempAbsQuotient);
}

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
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Simulation_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Simulation_step();
  Simulation_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Simulation_step();
  Simulation_derivatives();

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

static void BicycleKinematics_assignModelPr(robotics_slmobile_internal_bl_T *obj)
{
  int32_T b_kstr;
  int32_T nmatched;
  boolean_T b_bool;
  static const char_T tmp_0[25] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'S', 't', 'e', 'e', 'r', 'i', 'n', 'g', 'A', 'n', 'g', 'l',
    'e' };

  static const char_T tmp_1[128] = { '\x00', '\x01', '\x02', '\x03', '\x04',
    '\x05', '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d',
    '\x0e', '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16',
    '\x17', '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>',
    '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\',
    ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '{', '|', '}', '~', '\x7f' };

  static const char_T tmp_2[25] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'H', 'e', 'a', 'd', 'i', 'n', 'g', 'R', 'a', 't', 'e', '-',
    '-' };

  int32_T exitg1;
  nmatched = 0;
  for (b_kstr = 0; b_kstr < 25; b_kstr++) {
    char_T tmp;
    tmp = tmp_0[b_kstr];
    Simulation_B.vehicleInputs_data[b_kstr] = tmp;
    Simulation_B.b_ct[b_kstr] = tmp;
  }

  b_bool = false;
  b_kstr = 1;
  do {
    exitg1 = 0;
    if (b_kstr - 1 < 25) {
      if (tmp_1[static_cast<int32_T>(Simulation_B.vehicleInputs_data[b_kstr - 1])]
          != tmp_1[static_cast<int32_T>(Simulation_B.b_ct[b_kstr - 1])]) {
        exitg1 = 1;
      } else {
        b_kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (b_bool) {
    nmatched = 1;
    for (b_kstr = 0; b_kstr < 25; b_kstr++) {
      Simulation_B.b_ct[b_kstr] = tmp_0[b_kstr];
    }
  } else {
    for (b_kstr = 0; b_kstr < 25; b_kstr++) {
      Simulation_B.b_ct[b_kstr] = ' ';
    }
  }

  if (nmatched == 0) {
    for (b_kstr = 0; b_kstr < 25; b_kstr++) {
      Simulation_B.vehicleInputs_data_j[b_kstr] = ' ';
    }
  } else {
    for (b_kstr = 0; b_kstr < 25; b_kstr++) {
      Simulation_B.vehicleInputs_data_j[b_kstr] = Simulation_B.b_ct[b_kstr];
    }
  }

  for (b_kstr = 0; b_kstr < 25; b_kstr++) {
    Simulation_B.b_ct[b_kstr] = tmp_0[b_kstr];
  }

  b_bool = false;
  b_kstr = 1;
  do {
    exitg1 = 0;
    if (b_kstr - 1 < 25) {
      if (Simulation_B.vehicleInputs_data_j[b_kstr - 1] !=
          Simulation_B.b_ct[b_kstr - 1]) {
        exitg1 = 1;
      } else {
        b_kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  for (b_kstr = 0; b_kstr < 25; b_kstr++) {
    if (b_bool) {
      Simulation_B.f_h.f1[b_kstr] = tmp_0[b_kstr];
      obj->KinModel.VehicleInputsInternal[b_kstr] = Simulation_B.f_h.f1[b_kstr];
    } else {
      Simulation_B.g_c.f1[b_kstr] = tmp_2[b_kstr];
      obj->KinModel.VehicleInputsInternal[b_kstr] = Simulation_B.g_c.f1[b_kstr];
    }
  }

  obj->KinModel.WheelBase = obj->WheelBase;
  obj->KinModel.VehicleSpeedRange[0] = obj->VehicleSpeedRange[0];
  obj->KinModel.VehicleSpeedRange[1] = obj->VehicleSpeedRange[1];
  obj->KinModel.MaxSteeringAngle = obj->MaxSteeringAngle;
}

static void Simulation_SystemCore_setup(robotics_slmobile_internal_bl_T *obj)
{
  int32_T b_kstr;
  int32_T ret;
  char_T vehicleInputs;
  boolean_T b_bool;
  static const char_T tmp[25] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'S', 't', 'e', 'e', 'r', 'i', 'n', 'g', 'A', 'n', 'g', 'l',
    'e' };

  static const char_T tmp_0[128] = { '\x00', '\x01', '\x02', '\x03', '\x04',
    '\x05', '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d',
    '\x0e', '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16',
    '\x17', '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>',
    '?', '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\',
    ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '{', '|', '}', '~', '\x7f' };

  static const char_T tmp_1[25] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'H', 'e', 'a', 'd', 'i', 'n', 'g', 'R', 'a', 't', 'e', '-',
    '-' };

  obj->isInitialized = 1;
  obj->KinModel.WheelBase = 1.0;
  obj->KinModel.VehicleSpeedRange[0] = (rtMinusInf);
  obj->KinModel.VehicleSpeedRange[1] = (rtInf);
  obj->KinModel.MaxSteeringAngle = 0.78539816339744828;
  ret = 0;
  for (b_kstr = 0; b_kstr < 25; b_kstr++) {
    vehicleInputs = tmp[b_kstr];
    Simulation_B.vehicleInputs[b_kstr] = vehicleInputs;
    Simulation_B.b_m3[b_kstr] = vehicleInputs;
  }

  b_bool = false;
  b_kstr = 1;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (b_kstr - 1 < 25) {
      if (tmp_0[static_cast<int32_T>(Simulation_B.vehicleInputs[b_kstr - 1])] !=
          tmp_0[static_cast<int32_T>(Simulation_B.b_m3[b_kstr - 1])]) {
        exitg1 = 1;
      } else {
        b_kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (b_bool) {
    ret = 1;
    for (b_kstr = 0; b_kstr < 25; b_kstr++) {
      Simulation_B.vehicleInputs[b_kstr] = tmp[b_kstr];
    }
  } else {
    for (b_kstr = 0; b_kstr < 25; b_kstr++) {
      Simulation_B.vehicleInputs[b_kstr] = ' ';
    }
  }

  b_bool = (ret == 0);
  for (b_kstr = 0; b_kstr < 25; b_kstr++) {
    vehicleInputs = Simulation_B.vehicleInputs[b_kstr];
    if (b_bool) {
      vehicleInputs = ' ';
    }

    Simulation_B.b_m3[b_kstr] = tmp[b_kstr];
    Simulation_B.vehicleInputs[b_kstr] = vehicleInputs;
  }

  ret = memcmp(&Simulation_B.vehicleInputs[0], &Simulation_B.b_m3[0], 25);
  for (b_kstr = 0; b_kstr < 25; b_kstr++) {
    if (ret == 0) {
      Simulation_B.f.f1[b_kstr] = tmp[b_kstr];
      obj->KinModel.VehicleInputsInternal[b_kstr] = Simulation_B.f.f1[b_kstr];
    } else {
      Simulation_B.g.f1[b_kstr] = tmp_1[b_kstr];
      obj->KinModel.VehicleInputsInternal[b_kstr] = Simulation_B.g.f1[b_kstr];
    }
  }

  BicycleKinematics_assignModelPr(obj);
  obj->TunablePropsChanged = false;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_znlmpc_getXUe(const real_T z[21], const real_T x[4],
  real_T X[20], real_T U[10], real_T *e)
{
  int32_T i;
  static const int8_T y[32] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 };

  memset(&X[0], 0, 20U * sizeof(real_T));
  memset(&Simulation_B.Umv[0], 0, 10U * sizeof(real_T));
  for (i = 0; i < 8; i++) {
    Simulation_B.y_o[i] = ((static_cast<real_T>(y[i + 8]) * z[17] +
      static_cast<real_T>(y[i]) * z[16]) + static_cast<real_T>(y[i + 16]) * z[18])
      + static_cast<real_T>(y[i + 24]) * z[19];
  }

  for (i = 0; i < 2; i++) {
    Simulation_B.Umv[5 * i] = Simulation_B.y_o[i];
    Simulation_B.Umv[5 * i + 1] = Simulation_B.y_o[i + 2];
    Simulation_B.Umv[5 * i + 2] = Simulation_B.y_o[i + 4];
    Simulation_B.Umv[5 * i + 3] = Simulation_B.y_o[i + 6];
  }

  *e = z[20];
  memcpy(&Simulation_B.z_h[0], &z[0], sizeof(real_T) << 4U);
  for (i = 0; i < 4; i++) {
    X[5 * i + 1] = Simulation_B.z_h[i];
    X[5 * i + 2] = Simulation_B.z_h[i + 4];
    X[5 * i + 3] = Simulation_B.z_h[i + 8];
    X[5 * i + 4] = Simulation_B.z_h[i + 12];
    X[5 * i] = x[i];
  }

  for (int32_T i_0 = 0; i_0 < 2; i_0++) {
    Simulation_B.Umv[5 * i_0 + 4] = Simulation_B.Umv[5 * i_0 + 3];
    for (i = 0; i < 5; i++) {
      U[i + 5 * i_0] = Simulation_B.Umv[5 * i_0 + i];
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_mtimes(const real_T A_data[], const int32_T A_size[2],
  real_T C_data[], int32_T C_size[2])
{
  int32_T m;
  static const int8_T b[32] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 };

  m = A_size[0];
  C_size[0] = A_size[0];
  C_size[1] = 4;
  for (int32_T j = 0; j < 4; j++) {
    int32_T boffset;
    int32_T coffset;
    coffset = j * m;
    boffset = j << 3;
    for (int32_T i = 0; i < m; i++) {
      Simulation_B.s = 0.0;
      for (int32_T k = 0; k < 8; k++) {
        Simulation_B.s += A_data[k * A_size[0] + i] * static_cast<real_T>
          (b[boffset + k]);
      }

      C_data[coffset + i] = Simulation_B.s;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_znlmpc_getUBounds(const real_T runtimedata_lastMV[2],
  const real_T runtimedata_MVMin[8], const real_T runtimedata_MVMax[8], const
  real_T runtimedata_MVRateMin[8], const real_T runtimedata_MVRateMax[8], real_T
  A_data[], int32_T A_size[2], real_T Bu_data[], int32_T *Bu_size)
{
  real_T ic_idx_1;
  int32_T tmp_size[2];
  int32_T Au_tmp;
  int32_T Au_tmp_0;
  int32_T Au_tmp_1;
  int32_T i;
  boolean_T exitg1;
  memset(&Simulation_B.Au[0], 0, sizeof(real_T) << 8U);
  memset(&Simulation_B.b_Bu[0], 0, sizeof(real_T) << 5U);
  for (i = 0; i < 32; i++) {
    Simulation_B.Ae[i] = 0;
    Simulation_B.x[i] = false;
  }

  Simulation_B.ic_idx_0_f = 1.0;
  ic_idx_1 = 2.0;
  for (i = 0; i < 4; i++) {
    Simulation_B.runtimedata_MVRateMin = runtimedata_MVRateMin[i];
    Simulation_B.x[static_cast<int32_T>(Simulation_B.ic_idx_0_f) - 1] =
      ((!rtIsInf(Simulation_B.runtimedata_MVRateMin)) && (!rtIsNaN
        (Simulation_B.runtimedata_MVRateMin)));
    Simulation_B.runtimedata_MVRateMin = runtimedata_MVRateMin[i + 4];
    Simulation_B.x[static_cast<int32_T>(ic_idx_1) - 1] = ((!rtIsInf
      (Simulation_B.runtimedata_MVRateMin)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVRateMin)));
    Simulation_B.runtimedata_MVRateMax = runtimedata_MVRateMax[i];
    Simulation_B.x[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 2.0) - 1] = ((
      !rtIsInf(Simulation_B.runtimedata_MVRateMax)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVRateMax)));
    Simulation_B.runtimedata_MVRateMax = runtimedata_MVRateMax[i + 4];
    Simulation_B.x[static_cast<int32_T>(ic_idx_1 + 2.0) - 1] = ((!rtIsInf
      (Simulation_B.runtimedata_MVRateMax)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVRateMax)));
    Simulation_B.runtimedata_MVMin = runtimedata_MVMin[i];
    Simulation_B.x[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 4.0) - 1] = ((
      !rtIsInf(Simulation_B.runtimedata_MVMin)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVMin)));
    Simulation_B.runtimedata_MVMin = runtimedata_MVMin[i + 4];
    Simulation_B.x[static_cast<int32_T>(ic_idx_1 + 4.0) - 1] = ((!rtIsInf
      (Simulation_B.runtimedata_MVMin)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVMin)));
    Simulation_B.runtimedata_MVMax = runtimedata_MVMax[i];
    Simulation_B.x[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 6.0) - 1] = ((
      !rtIsInf(Simulation_B.runtimedata_MVMax)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVMax)));
    Simulation_B.runtimedata_MVMax = runtimedata_MVMax[i + 4];
    Simulation_B.x[static_cast<int32_T>(ic_idx_1 + 6.0) - 1] = ((!rtIsInf
      (Simulation_B.runtimedata_MVMax)) && (!rtIsNaN
      (Simulation_B.runtimedata_MVMax)));
    Au_tmp = i << 6;
    Au_tmp_0 = static_cast<int32_T>(Simulation_B.ic_idx_0_f) + Au_tmp;
    Simulation_B.Au[Au_tmp_0 - 1] = -1.0;
    Au_tmp_1 = static_cast<int32_T>(ic_idx_1) + Au_tmp;
    Simulation_B.Au[Au_tmp_1 - 1] = -0.0;
    Simulation_B.Au[Au_tmp_0 + 31] = -0.0;
    Simulation_B.Au[Au_tmp_1 + 31] = -1.0;
    Au_tmp_0 = static_cast<int32_T>(Simulation_B.ic_idx_0_f + 2.0) + Au_tmp;
    Simulation_B.Au[Au_tmp_0 - 1] = 1.0;
    Au_tmp_1 = static_cast<int32_T>(ic_idx_1 + 2.0) + Au_tmp;
    Simulation_B.Au[Au_tmp_1 - 1] = 0.0;
    Simulation_B.Au[Au_tmp_0 + 31] = 0.0;
    Simulation_B.Au[Au_tmp_1 + 31] = 1.0;
    Au_tmp_0 = static_cast<int32_T>(Simulation_B.ic_idx_0_f + 4.0) + Au_tmp;
    Simulation_B.Au[Au_tmp_0 - 1] = -1.0;
    Au_tmp_1 = static_cast<int32_T>(ic_idx_1 + 4.0) + Au_tmp;
    Simulation_B.Au[Au_tmp_1 - 1] = -0.0;
    Simulation_B.Au[Au_tmp_0 + 31] = -0.0;
    Simulation_B.Au[Au_tmp_1 + 31] = -1.0;
    Au_tmp_0 = static_cast<int32_T>(Simulation_B.ic_idx_0_f + 6.0) + Au_tmp;
    Simulation_B.Au[Au_tmp_0 - 1] = 1.0;
    Au_tmp += static_cast<int32_T>(ic_idx_1 + 6.0);
    Simulation_B.Au[Au_tmp - 1] = 0.0;
    Simulation_B.Ae[static_cast<int32_T>(Simulation_B.ic_idx_0_f) - 1] = -10;
    Simulation_B.Au[Au_tmp_0 + 31] = 0.0;
    Simulation_B.Au[Au_tmp + 31] = 1.0;
    Simulation_B.Ae[static_cast<int32_T>(ic_idx_1) - 1] = -10;
    Simulation_B.Ae[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 2.0) - 1] =
      -10;
    Simulation_B.Ae[static_cast<int32_T>(ic_idx_1 + 2.0) - 1] = -10;
    Simulation_B.Ae[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 4.0) - 1] = 0;
    Simulation_B.Ae[static_cast<int32_T>(ic_idx_1 + 4.0) - 1] = 0;
    Simulation_B.Ae[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 6.0) - 1] = 0;
    Simulation_B.b_Bu[static_cast<int32_T>(Simulation_B.ic_idx_0_f) - 1] =
      -runtimedata_MVRateMin[i];
    Simulation_B.Ae[static_cast<int32_T>(ic_idx_1 + 6.0) - 1] = 0;
    Simulation_B.b_Bu[static_cast<int32_T>(ic_idx_1) - 1] =
      -Simulation_B.runtimedata_MVRateMin;
    Simulation_B.b_Bu[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 2.0) - 1] =
      runtimedata_MVRateMax[i];
    Simulation_B.b_Bu[static_cast<int32_T>(ic_idx_1 + 2.0) - 1] =
      Simulation_B.runtimedata_MVRateMax;
    Simulation_B.b_Bu[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 4.0) - 1] =
      -runtimedata_MVMin[i];
    Simulation_B.b_Bu[static_cast<int32_T>(ic_idx_1 + 4.0) - 1] =
      -Simulation_B.runtimedata_MVMin;
    Simulation_B.b_Bu[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 6.0) - 1] =
      runtimedata_MVMax[i];
    Simulation_B.b_Bu[static_cast<int32_T>(ic_idx_1 + 6.0) - 1] =
      Simulation_B.runtimedata_MVMax;
    if (i + 1 == 1) {
      Simulation_B.runtimedata_MVRateMin = Simulation_B.b_Bu[static_cast<int32_T>
        (ic_idx_1) - 1] - runtimedata_lastMV[1];
      Simulation_B.b_Bu[static_cast<int32_T>(Simulation_B.ic_idx_0_f) - 1] -=
        runtimedata_lastMV[0];
      Simulation_B.b_Bu[static_cast<int32_T>(ic_idx_1) - 1] =
        Simulation_B.runtimedata_MVRateMin;
      Simulation_B.runtimedata_MVRateMin = Simulation_B.b_Bu[static_cast<int32_T>
        (ic_idx_1 + 2.0) - 1] + runtimedata_lastMV[1];
      Simulation_B.b_Bu[static_cast<int32_T>(Simulation_B.ic_idx_0_f + 2.0) - 1]
        += runtimedata_lastMV[0];
      Simulation_B.b_Bu[static_cast<int32_T>(ic_idx_1 + 2.0) - 1] =
        Simulation_B.runtimedata_MVRateMin;
    } else {
      Au_tmp = (i - 1) << 6;
      Au_tmp_0 = static_cast<int32_T>(Simulation_B.ic_idx_0_f) + Au_tmp;
      Simulation_B.Au[Au_tmp_0 - 1] = 1.0;
      Au_tmp_1 = static_cast<int32_T>(ic_idx_1) + Au_tmp;
      Simulation_B.Au[Au_tmp_1 - 1] = 0.0;
      Simulation_B.Au[Au_tmp_0 + 31] = 0.0;
      Simulation_B.Au[Au_tmp_1 + 31] = 1.0;
      Au_tmp_0 = static_cast<int32_T>(Simulation_B.ic_idx_0_f + 2.0) + Au_tmp;
      Simulation_B.Au[Au_tmp_0 - 1] = -1.0;
      Au_tmp += static_cast<int32_T>(ic_idx_1 + 2.0);
      Simulation_B.Au[Au_tmp - 1] = -0.0;
      Simulation_B.Au[Au_tmp_0 + 31] = -0.0;
      Simulation_B.Au[Au_tmp + 31] = -1.0;
    }

    Simulation_B.ic_idx_0_f += 8.0;
    ic_idx_1 += 8.0;
  }

  i = 0;
  Au_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (Au_tmp < 32)) {
    if (Simulation_B.x[Au_tmp]) {
      i++;
      Simulation_B.ii_data[i - 1] = static_cast<int8_T>(Au_tmp + 1);
      if (i >= 32) {
        exitg1 = true;
      } else {
        Au_tmp++;
      }
    } else {
      Au_tmp++;
    }
  }

  if (1 > i) {
    i = 0;
  }

  if (i > 0) {
    *Bu_size = i;
    for (Au_tmp = 0; Au_tmp < i; Au_tmp++) {
      Bu_data[Au_tmp] = Simulation_B.b_Bu[Simulation_B.ii_data[Au_tmp] - 1];
    }

    for (Au_tmp = 0; Au_tmp < 2; Au_tmp++) {
      for (Au_tmp_0 = 0; Au_tmp_0 < i; Au_tmp_0++) {
        Simulation_B.Auf_data[Au_tmp_0 + i * Au_tmp] = Simulation_B.Au[((Au_tmp <<
          5) + Simulation_B.ii_data[Au_tmp_0]) - 1];
      }

      for (Au_tmp_0 = 0; Au_tmp_0 < i; Au_tmp_0++) {
        Simulation_B.Auf_data[(Au_tmp_0 + i * Au_tmp) + (i << 1)] =
          Simulation_B.Au[((Au_tmp << 5) + Simulation_B.ii_data[Au_tmp_0]) + 63];
      }

      for (Au_tmp_0 = 0; Au_tmp_0 < i; Au_tmp_0++) {
        Simulation_B.Auf_data[(Au_tmp_0 + i * Au_tmp) + ((i << 1) << 1)] =
          Simulation_B.Au[((Au_tmp << 5) + Simulation_B.ii_data[Au_tmp_0]) + 127];
      }

      for (Au_tmp_0 = 0; Au_tmp_0 < i; Au_tmp_0++) {
        Simulation_B.Auf_data[(Au_tmp_0 + i * Au_tmp) + (i << 1) * 3] =
          Simulation_B.Au[((Au_tmp << 5) + Simulation_B.ii_data[Au_tmp_0]) + 191];
      }
    }

    Simulation_B.b_o[0] = i;
    Simulation_B.b_o[1] = 8;
    Simulation_mtimes(Simulation_B.Auf_data, Simulation_B.b_o,
                      Simulation_B.tmp_data_j, tmp_size);
    for (Au_tmp = 0; Au_tmp < i; Au_tmp++) {
      Simulation_B.Ae_data[Au_tmp] = Simulation_B.Ae[Simulation_B.ii_data[Au_tmp]
        - 1];
    }

    A_size[0] = i;
    A_size[1] = 21;
    Au_tmp_0 = i << 4;
    if (0 <= Au_tmp_0 - 1) {
      memset(&A_data[0], 0, Au_tmp_0 * sizeof(real_T));
    }

    Au_tmp_1 = i << 2;
    for (Au_tmp = 0; Au_tmp < Au_tmp_1; Au_tmp++) {
      A_data[Au_tmp + Au_tmp_0] = Simulation_B.tmp_data_j[Au_tmp];
    }

    for (Au_tmp = 0; Au_tmp < i; Au_tmp++) {
      A_data[(Au_tmp + Au_tmp_0) + Au_tmp_1] = Simulation_B.Ae_data[Au_tmp];
    }
  } else {
    *Bu_size = 0;
    A_size[0] = 0;
    A_size[1] = 25;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Sim_znlmpc_computeJacobianState(const real_T f0[4], real_T x0[4],
  real_T u0[2], real_T Jx[16], real_T Jmv[8])
{
  real_T dx;
  real_T f_idx_2;
  real_T f_idx_3;
  int32_T Jx_tmp;
  int32_T k;
  for (k = 0; k < 4; k++) {
    real_T f_idx_0;
    real_T f_idx_1;
    f_idx_2 = fabs(x0[k]);
    if (f_idx_2 < 1.0) {
      f_idx_2 = 1.0;
    }

    dx = 1.0E-6 * f_idx_2;
    x0[k] += dx;
    f_idx_0 = x0[3] * cos(x0[2]);
    f_idx_1 = x0[3] * sin(x0[2]);
    f_idx_2 = x0[3] * tan(u0[1]);
    f_idx_3 = (u0[0] - 2.3 * x0[3]) * 0.2;
    x0[k] -= dx;
    Jx_tmp = k << 2;
    Jx[Jx_tmp] = (f_idx_0 - f0[0]) / dx;
    Jx[Jx_tmp + 1] = (f_idx_1 - f0[1]) / dx;
    Jx[Jx_tmp + 2] = (f_idx_2 - f0[2]) / dx;
    Jx[Jx_tmp + 3] = (f_idx_3 - f0[3]) / dx;
  }

  for (k = 0; k < 2; k++) {
    f_idx_2 = fabs(u0[k]);
    if (f_idx_2 < 1.0) {
      f_idx_2 = 1.0;
    }

    dx = 1.0E-6 * f_idx_2;
    u0[k] += dx;
    f_idx_2 = x0[3] * tan(u0[1]);
    f_idx_3 = (u0[0] - 2.3 * x0[3]) * 0.2;
    u0[k] -= dx;
    Jx_tmp = k << 2;
    Jmv[Jx_tmp] = (x0[3] * cos(x0[2]) - f0[0]) / dx;
    Jmv[Jx_tmp + 1] = (x0[3] * sin(x0[2]) - f0[1]) / dx;
    Jmv[Jx_tmp + 2] = (f_idx_2 - f0[2]) / dx;
    Jmv[Jx_tmp + 3] = (f_idx_3 - f0[3]) / dx;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_all(const boolean_T x[12], boolean_T y[3])
{
  int32_T ix;
  boolean_T exitg1;
  y[0] = true;
  y[1] = true;
  y[2] = true;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= 4)) {
    if (!x[ix - 1]) {
      y[0] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 5;
  exitg1 = false;
  while ((!exitg1) && (ix <= 8)) {
    if (!x[ix - 1]) {
      y[1] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 9;
  exitg1 = false;
  while ((!exitg1) && (ix <= 12)) {
    if (!x[ix - 1]) {
      y[2] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static boolean_T Simulation_any(const boolean_T x[6])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 5)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulatio_znlmpc_reformJacobian(const real_T Jx_data[], const
  int32_T Jx_size[3], const real_T Jmv_data[], const real_T Je_data[], const
  int32_T *Je_size, real_T Jc_data[], int32_T Jc_size[2])
{
  int8_T Jx[2];
  int8_T b_input_sizes[2];
  if (Jx_size[0] == 0) {
    Jc_size[0] = 0;
    Jc_size[1] = 0;
  } else {
    int32_T i;
    int32_T input_sizes_idx_0_0;
    int32_T loop_ub;
    int32_T varargin_1_size_idx_1_tmp;
    int8_T b_input_sizes_idx_0;
    int8_T input_sizes_idx_0;
    Jx[0] = static_cast<int8_T>(Jx_size[0]);
    Jx[1] = 16;
    varargin_1_size_idx_1_tmp = static_cast<int8_T>(Jx_size[0]);
    for (i = 0; i < varargin_1_size_idx_1_tmp; i++) {
      for (loop_ub = 0; loop_ub < 16; loop_ub++) {
        Simulation_B.varargin_1_data[loop_ub + (i << 4)] = Jx_data[Jx[0] *
          loop_ub + i];
      }
    }

    Simulation_B.Jx_o[0] = Jx_size[0];
    Simulation_B.Jx_o[1] = 8;
    Simulation_mtimes(Jmv_data, Simulation_B.Jx_o, Simulation_B.tmp_data_l,
                      Simulation_B.tmp_size);
    loop_ub = Simulation_B.tmp_size[0];
    for (i = 0; i < loop_ub; i++) {
      Simulation_B.varargin_2_data[i << 2] = Simulation_B.tmp_data_l[i];
      Simulation_B.varargin_2_data[1 + (i << 2)] = Simulation_B.tmp_data_l[i +
        Simulation_B.tmp_size[0]];
      Simulation_B.varargin_2_data[2 + (i << 2)] = Simulation_B.tmp_data_l
        [(Simulation_B.tmp_size[0] << 1) + i];
      Simulation_B.varargin_2_data[3 + (i << 2)] =
        Simulation_B.tmp_data_l[Simulation_B.tmp_size[0] * 3 + i];
    }

    if (Simulation_B.tmp_size[0] != 0) {
      input_sizes_idx_0 = 4;
    } else {
      input_sizes_idx_0 = 0;
    }

    if (static_cast<int8_T>(*Je_size) != 0) {
      b_input_sizes_idx_0 = 1;
    } else {
      b_input_sizes_idx_0 = 0;
    }

    if (Simulation_B.tmp_size[0] != 0) {
      input_sizes_idx_0_0 = 4;
    } else {
      input_sizes_idx_0_0 = 0;
    }

    if (0 <= *Je_size - 1) {
      memcpy(&Simulation_B.Je_data[0], &Je_data[0], *Je_size * sizeof(real_T));
    }

    if (static_cast<int8_T>(*Je_size) != 0) {
      b_input_sizes[0] = 1;
    } else {
      b_input_sizes[0] = 0;
    }

    b_input_sizes[1] = static_cast<int8_T>(Jx_size[0]);
    Jc_size[0] = (input_sizes_idx_0 + b_input_sizes_idx_0) + 16;
    Jc_size[1] = static_cast<int8_T>(Jx_size[0]);
    for (i = 0; i < varargin_1_size_idx_1_tmp; i++) {
      for (loop_ub = 0; loop_ub < 16; loop_ub++) {
        Jc_data[loop_ub + Jc_size[0] * i] = Simulation_B.varargin_1_data[(i << 4)
          + loop_ub];
      }
    }

    for (i = 0; i < varargin_1_size_idx_1_tmp; i++) {
      for (loop_ub = 0; loop_ub < input_sizes_idx_0_0; loop_ub++) {
        Jc_data[(loop_ub + Jc_size[0] * i) + 16] = Simulation_B.varargin_2_data
          [(i << 2) + loop_ub];
      }
    }

    loop_ub = static_cast<int8_T>(Jx_size[0]);
    if (0 <= b_input_sizes_idx_0 - 1) {
      for (i = 0; i < loop_ub; i++) {
        Jc_data[(input_sizes_idx_0 + Jc_size[0] * i) + 16] =
          Simulation_B.Je_data[b_input_sizes[0] * i];
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_outputBounds(const real_T runtimedata_OutputMin[12],
  const real_T runtimedata_OutputMax[12], const real_T X[20], real_T e, real_T
  c_data[], int32_T c_size[2], real_T Jc_data[], int32_T Jc_size[2])
{
  boolean_T x[3];
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T y;
  for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 12; Simulation_B.c_k_c++) {
    Simulation_B.bv[Simulation_B.c_k_c] = rtIsInf
      (runtimedata_OutputMin[Simulation_B.c_k_c]);
  }

  Simulation_all(Simulation_B.bv, x);
  y = true;
  Simulation_B.c_k_c = 0;
  exitg1 = false;
  while ((!exitg1) && (Simulation_B.c_k_c < 3)) {
    if (!x[Simulation_B.c_k_c]) {
      y = false;
      exitg1 = true;
    } else {
      Simulation_B.c_k_c++;
    }
  }

  guard1 = false;
  if (y) {
    for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 12; Simulation_B.c_k_c++)
    {
      Simulation_B.bv[Simulation_B.c_k_c] = rtIsInf
        (runtimedata_OutputMax[Simulation_B.c_k_c]);
    }

    Simulation_all(Simulation_B.bv, x);
    y = true;
    Simulation_B.c_k_c = 0;
    exitg1 = false;
    while ((!exitg1) && (Simulation_B.c_k_c < 3)) {
      if (!x[Simulation_B.c_k_c]) {
        y = false;
        exitg1 = true;
      } else {
        Simulation_B.c_k_c++;
      }
    }

    if (y) {
      c_size[0] = 0;
      c_size[1] = 0;
      Jc_size[0] = 0;
      Jc_size[1] = 0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    int32_T b_size_idx_0;
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 24; Simulation_B.i_f++) {
      Simulation_B.b_c[Simulation_B.i_f] = 0.0;
      Simulation_B.icf[Simulation_B.i_f] = true;
    }

    memset(&Simulation_B.Jx[0], 0, 384U * sizeof(real_T));
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 24; Simulation_B.i_f++) {
      Simulation_B.Je[Simulation_B.i_f] = 0;
    }

    Simulation_B.ic_idx_0 = 1.0;
    Simulation_B.ic_idx_1 = 2.0;
    Simulation_B.ic_idx_2 = 3.0;
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 4; Simulation_B.i_f++) {
      Simulation_B.runtimedata_OutputMin =
        runtimedata_OutputMin[Simulation_B.i_f];
      Simulation_B.icf[static_cast<int32_T>(Simulation_B.ic_idx_0) - 1] =
        ((!rtIsInf(Simulation_B.runtimedata_OutputMin)) && (!rtIsNaN
          (Simulation_B.runtimedata_OutputMin)));
      Simulation_B.runtimedata_OutputMin =
        runtimedata_OutputMin[Simulation_B.i_f + 4];
      Simulation_B.icf[static_cast<int32_T>(Simulation_B.ic_idx_1) - 1] =
        ((!rtIsInf(Simulation_B.runtimedata_OutputMin)) && (!rtIsNaN
          (Simulation_B.runtimedata_OutputMin)));
      Simulation_B.runtimedata_OutputMin_tmp =
        runtimedata_OutputMin[Simulation_B.i_f + 8];
      Simulation_B.icf[static_cast<int32_T>(Simulation_B.ic_idx_2) - 1] =
        ((!rtIsInf(Simulation_B.runtimedata_OutputMin_tmp)) && (!rtIsNaN
          (Simulation_B.runtimedata_OutputMin_tmp)));
      Simulation_B.runtimedata_OutputMax =
        runtimedata_OutputMax[Simulation_B.i_f];
      Simulation_B.icf[static_cast<int32_T>(Simulation_B.ic_idx_0 + 3.0) - 1] =
        ((!rtIsInf(Simulation_B.runtimedata_OutputMax)) && (!rtIsNaN
          (Simulation_B.runtimedata_OutputMax)));
      Simulation_B.ic_a[0] = static_cast<int32_T>(Simulation_B.ic_idx_0) - 1;
      Simulation_B.ic_a[3] = static_cast<int32_T>(Simulation_B.ic_idx_0 + 3.0) -
        1;
      Simulation_B.runtimedata_OutputMax =
        runtimedata_OutputMax[Simulation_B.i_f + 4];
      Simulation_B.icf[static_cast<int32_T>(Simulation_B.ic_idx_1 + 3.0) - 1] =
        ((!rtIsInf(Simulation_B.runtimedata_OutputMax)) && (!rtIsNaN
          (Simulation_B.runtimedata_OutputMax)));
      Simulation_B.ic_a[1] = static_cast<int32_T>(Simulation_B.ic_idx_1) - 1;
      Simulation_B.ic_a[4] = static_cast<int32_T>(Simulation_B.ic_idx_1 + 3.0) -
        1;
      Simulation_B.runtimedata_OutputMax_tmp =
        runtimedata_OutputMax[Simulation_B.i_f + 8];
      Simulation_B.icf[static_cast<int32_T>(Simulation_B.ic_idx_2 + 3.0) - 1] =
        ((!rtIsInf(Simulation_B.runtimedata_OutputMax_tmp)) && (!rtIsNaN
          (Simulation_B.runtimedata_OutputMax_tmp)));
      Simulation_B.ic_a[2] = static_cast<int32_T>(Simulation_B.ic_idx_2) - 1;
      Simulation_B.ic_a[5] = static_cast<int32_T>(Simulation_B.ic_idx_2 + 3.0) -
        1;
      for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 6; Simulation_B.c_k_c++)
      {
        Simulation_B.icf_a[Simulation_B.c_k_c] =
          Simulation_B.icf[Simulation_B.ic_a[Simulation_B.c_k_c]];
      }

      if (Simulation_any(Simulation_B.icf_a)) {
        Simulation_B.yk_idx_0_tmp = X[Simulation_B.i_f + 1];
        Simulation_B.yk_idx_1_tmp = X[Simulation_B.i_f + 6];
        Simulation_B.yk_idx_2_tmp = X[Simulation_B.i_f + 11];
        Simulation_B.xk[0] = Simulation_B.yk_idx_0_tmp;
        Simulation_B.dx_c = fabs(Simulation_B.yk_idx_0_tmp);
        if (Simulation_B.dx_c < 1.0) {
          Simulation_B.dx_c = 1.0;
        }

        Simulation_B.xa_m[0] = Simulation_B.dx_c;
        Simulation_B.xk[1] = Simulation_B.yk_idx_1_tmp;
        Simulation_B.dx_c = fabs(Simulation_B.yk_idx_1_tmp);
        if (Simulation_B.dx_c < 1.0) {
          Simulation_B.dx_c = 1.0;
        }

        Simulation_B.xa_m[1] = Simulation_B.dx_c;
        Simulation_B.xk[2] = Simulation_B.yk_idx_2_tmp;
        Simulation_B.dx_c = fabs(Simulation_B.yk_idx_2_tmp);
        if (Simulation_B.dx_c < 1.0) {
          Simulation_B.dx_c = 1.0;
        }

        Simulation_B.xa_m[2] = Simulation_B.dx_c;
        Simulation_B.dx_c = X[Simulation_B.i_f + 16];
        Simulation_B.xk[3] = Simulation_B.dx_c;
        Simulation_B.dx_c = fabs(Simulation_B.dx_c);
        if (Simulation_B.dx_c < 1.0) {
          Simulation_B.dx_c = 1.0;
        }

        Simulation_B.xa_m[3] = Simulation_B.dx_c;
        for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 4; Simulation_B.c_k_c
             ++) {
          Simulation_B.dx_c = 1.0E-6 * Simulation_B.xa_m[Simulation_B.c_k_c];
          Simulation_B.xk[Simulation_B.c_k_c] += Simulation_B.dx_c;
          Simulation_B.f_idx_0 = Simulation_B.xk[0];
          Simulation_B.f_idx_1 = Simulation_B.xk[1];
          Simulation_B.f_idx_2 = Simulation_B.xk[2];
          Simulation_B.xk[Simulation_B.c_k_c] -= Simulation_B.dx_c;
          Simulation_B.Ck[3 * Simulation_B.c_k_c] = (Simulation_B.f_idx_0 -
            Simulation_B.yk_idx_0_tmp) / Simulation_B.dx_c;
          Simulation_B.Ck[3 * Simulation_B.c_k_c + 1] = (Simulation_B.f_idx_1 -
            Simulation_B.yk_idx_1_tmp) / Simulation_B.dx_c;
          Simulation_B.Ck[3 * Simulation_B.c_k_c + 2] = (Simulation_B.f_idx_2 -
            Simulation_B.yk_idx_2_tmp) / Simulation_B.dx_c;
        }

        Simulation_B.b_c[static_cast<int32_T>(Simulation_B.ic_idx_0) - 1] =
          (runtimedata_OutputMin[Simulation_B.i_f] - e) -
          Simulation_B.yk_idx_0_tmp;
        Simulation_B.b_c[static_cast<int32_T>(Simulation_B.ic_idx_1) - 1] =
          (Simulation_B.runtimedata_OutputMin - e) - Simulation_B.yk_idx_1_tmp;
        Simulation_B.b_c[static_cast<int32_T>(Simulation_B.ic_idx_2) - 1] =
          (Simulation_B.runtimedata_OutputMin_tmp - e) -
          Simulation_B.yk_idx_2_tmp;
        Simulation_B.b_c[static_cast<int32_T>(Simulation_B.ic_idx_0 + 3.0) - 1] =
          (Simulation_B.yk_idx_0_tmp - runtimedata_OutputMax[Simulation_B.i_f])
          - e;
        Simulation_B.b_c[static_cast<int32_T>(Simulation_B.ic_idx_1 + 3.0) - 1] =
          (Simulation_B.yk_idx_1_tmp - Simulation_B.runtimedata_OutputMax) - e;
        Simulation_B.b_c[static_cast<int32_T>(Simulation_B.ic_idx_2 + 3.0) - 1] =
          (Simulation_B.yk_idx_2_tmp - Simulation_B.runtimedata_OutputMax_tmp) -
          e;
        for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 12; Simulation_B.c_k_c
             ++) {
          Simulation_B.val[Simulation_B.c_k_c] =
            -Simulation_B.Ck[Simulation_B.c_k_c];
        }

        for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 4; Simulation_B.c_k_c
             ++) {
          Simulation_B.Jx[((static_cast<int32_T>(Simulation_B.ic_idx_0) + 24 *
                            Simulation_B.c_k_c) + 96 * Simulation_B.i_f) - 1] =
            Simulation_B.val[3 * Simulation_B.c_k_c];
          Simulation_B.Jx[((static_cast<int32_T>(Simulation_B.ic_idx_1) + 24 *
                            Simulation_B.c_k_c) + 96 * Simulation_B.i_f) - 1] =
            Simulation_B.val[3 * Simulation_B.c_k_c + 1];
          Simulation_B.Jx[((static_cast<int32_T>(Simulation_B.ic_idx_2) + 24 *
                            Simulation_B.c_k_c) + 96 * Simulation_B.i_f) - 1] =
            Simulation_B.val[3 * Simulation_B.c_k_c + 2];
        }

        for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 4; Simulation_B.c_k_c
             ++) {
          Simulation_B.Jx[((static_cast<int32_T>(Simulation_B.ic_idx_0 + 3.0) +
                            24 * Simulation_B.c_k_c) + 96 * Simulation_B.i_f) -
            1] = Simulation_B.Ck[3 * Simulation_B.c_k_c];
          Simulation_B.Jx[((static_cast<int32_T>(Simulation_B.ic_idx_1 + 3.0) +
                            24 * Simulation_B.c_k_c) + 96 * Simulation_B.i_f) -
            1] = Simulation_B.Ck[3 * Simulation_B.c_k_c + 1];
          Simulation_B.Jx[((static_cast<int32_T>(Simulation_B.ic_idx_2 + 3.0) +
                            24 * Simulation_B.c_k_c) + 96 * Simulation_B.i_f) -
            1] = Simulation_B.Ck[3 * Simulation_B.c_k_c + 2];
        }

        Simulation_B.Je[static_cast<int32_T>(Simulation_B.ic_idx_0) - 1] = -1;
        Simulation_B.Je[static_cast<int32_T>(Simulation_B.ic_idx_1) - 1] = -1;
        Simulation_B.Je[static_cast<int32_T>(Simulation_B.ic_idx_2) - 1] = -1;
        Simulation_B.Je[static_cast<int32_T>(Simulation_B.ic_idx_0 + 3.0) - 1] =
          -1;
        Simulation_B.Je[static_cast<int32_T>(Simulation_B.ic_idx_1 + 3.0) - 1] =
          -1;
        Simulation_B.Je[static_cast<int32_T>(Simulation_B.ic_idx_2 + 3.0) - 1] =
          -1;
      }

      Simulation_B.ic_idx_0 += 6.0;
      Simulation_B.ic_idx_1 += 6.0;
      Simulation_B.ic_idx_2 += 6.0;
    }

    Simulation_B.c_k_c = 0;
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 24; Simulation_B.i_f++) {
      if (Simulation_B.icf[Simulation_B.i_f]) {
        Simulation_B.c_k_c++;
      }
    }

    b_size_idx_0 = Simulation_B.c_k_c;
    Simulation_B.c_k_c = 0;
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 24; Simulation_B.i_f++) {
      if (Simulation_B.icf[Simulation_B.i_f]) {
        Simulation_B.b_data_p[Simulation_B.c_k_c] = static_cast<int8_T>
          (Simulation_B.i_f + 1);
        Simulation_B.c_k_c++;
      }
    }

    for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < b_size_idx_0;
         Simulation_B.c_k_c++) {
      Simulation_B.b_c_data_l[Simulation_B.c_k_c] =
        Simulation_B.b_c[Simulation_B.b_data_p[Simulation_B.c_k_c] - 1];
    }

    c_size[0] = b_size_idx_0;
    c_size[1] = 1;
    if (0 <= b_size_idx_0 - 1) {
      memcpy(&c_data[0], &Simulation_B.b_c_data_l[0], b_size_idx_0 * sizeof
             (real_T));
    }

    Simulation_B.c_k_c = 0;
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 24; Simulation_B.i_f++) {
      if (Simulation_B.icf[Simulation_B.i_f]) {
        Simulation_B.c_k_c++;
      }
    }

    b_size_idx_0 = Simulation_B.c_k_c;
    Simulation_B.c_k_c = 0;
    for (Simulation_B.i_f = 0; Simulation_B.i_f < 24; Simulation_B.i_f++) {
      if (Simulation_B.icf[Simulation_B.i_f]) {
        Simulation_B.d_data_p[Simulation_B.c_k_c] = static_cast<int8_T>
          (Simulation_B.i_f + 1);
        Simulation_B.c_k_c++;
      }
    }

    Simulation_B.Jx_size_l[0] = b_size_idx_0;
    Simulation_B.Jx_size_l[1] = 4;
    Simulation_B.Jx_size_l[2] = 4;
    for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < 4; Simulation_B.c_k_c++) {
      for (Simulation_B.i_f = 0; Simulation_B.i_f < 4; Simulation_B.i_f++) {
        for (Simulation_B.i5 = 0; Simulation_B.i5 < b_size_idx_0;
             Simulation_B.i5++) {
          Simulation_B.Jx_data[(Simulation_B.i5 + b_size_idx_0 *
                                Simulation_B.i_f) + (b_size_idx_0 << 2) *
            Simulation_B.c_k_c] = Simulation_B.Jx[((24 * Simulation_B.i_f +
            Simulation_B.d_data_p[Simulation_B.i5]) + 96 * Simulation_B.c_k_c) -
            1];
        }
      }

      for (Simulation_B.i_f = 0; Simulation_B.i_f < 2; Simulation_B.i_f++) {
        for (Simulation_B.i5 = 0; Simulation_B.i5 < b_size_idx_0;
             Simulation_B.i5++) {
          Simulation_B.tmp_data[(Simulation_B.i5 + b_size_idx_0 *
            Simulation_B.i_f) + (b_size_idx_0 << 1) * Simulation_B.c_k_c] = 0.0;
        }
      }
    }

    Simulation_B.b_c_size = b_size_idx_0;
    for (Simulation_B.c_k_c = 0; Simulation_B.c_k_c < b_size_idx_0;
         Simulation_B.c_k_c++) {
      Simulation_B.b_c_data_l[Simulation_B.c_k_c] =
        Simulation_B.Je[Simulation_B.d_data_p[Simulation_B.c_k_c] - 1];
    }

    Simulatio_znlmpc_reformJacobian(Simulation_B.Jx_data, Simulation_B.Jx_size_l,
      Simulation_B.tmp_data, Simulation_B.b_c_data_l, &Simulation_B.b_c_size,
      Jc_data, Jc_size);
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_ConstraintFunction(const real_T X[20], const real_T
  lcircle[4], const real_T rcircle[4], real_T cineq_data[], int32_T *cineq_size)
{
  if (lcircle[3] < 0.5) {
    Simulation_B.x_e = X[8] - lcircle[1];
    Simulation_B.lcon_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[9] - lcircle[1];
    Simulation_B.lcon_data_idx_1 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[3] - lcircle[0];
    Simulation_B.rcon_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[4] - lcircle[0];
    Simulation_B.lcon_data_idx_0 = (lcircle[2] + 1.5) + -sqrt
      (Simulation_B.lcon_data_idx_0 + Simulation_B.rcon_data_idx_0);
    Simulation_B.lcon_data_idx_1 = -sqrt(Simulation_B.x_e * Simulation_B.x_e +
      Simulation_B.lcon_data_idx_1) + (lcircle[2] + 1.5);
  } else {
    Simulation_B.x_e = X[8] - lcircle[1];
    Simulation_B.lcon_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[9] - lcircle[1];
    Simulation_B.lcon_data_idx_1 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[3] - lcircle[0];
    Simulation_B.rcon_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[4] - lcircle[0];
    Simulation_B.lcon_data_idx_0 = sqrt(Simulation_B.lcon_data_idx_0 +
      Simulation_B.rcon_data_idx_0) - (lcircle[2] - 1.5);
    Simulation_B.lcon_data_idx_1 = sqrt(Simulation_B.x_e * Simulation_B.x_e +
      Simulation_B.lcon_data_idx_1) - (lcircle[2] - 1.5);
  }

  if (rcircle[3] < 0.5) {
    real_T c_data_idx_0;
    Simulation_B.x_e = X[8] - rcircle[1];
    Simulation_B.rcon_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[9] - rcircle[1];
    Simulation_B.rcon_data_idx_1 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[3] - rcircle[0];
    c_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[4] - rcircle[0];
    Simulation_B.rcon_data_idx_0 = (rcircle[2] + 1.5) + -sqrt
      (Simulation_B.rcon_data_idx_0 + c_data_idx_0);
    Simulation_B.rcon_data_idx_1 = -sqrt(Simulation_B.x_e * Simulation_B.x_e +
      Simulation_B.rcon_data_idx_1) + (rcircle[2] + 1.5);
  } else {
    real_T c_data_idx_0;
    Simulation_B.x_e = X[8] - rcircle[1];
    Simulation_B.rcon_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[9] - rcircle[1];
    Simulation_B.rcon_data_idx_1 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[3] - rcircle[0];
    c_data_idx_0 = Simulation_B.x_e * Simulation_B.x_e;
    Simulation_B.x_e = X[4] - rcircle[0];
    Simulation_B.rcon_data_idx_0 = sqrt(Simulation_B.rcon_data_idx_0 +
      c_data_idx_0) - (rcircle[2] - 1.5);
    Simulation_B.rcon_data_idx_1 = sqrt(Simulation_B.x_e * Simulation_B.x_e +
      Simulation_B.rcon_data_idx_1) - (rcircle[2] - 1.5);
  }

  *cineq_size = 4;
  cineq_data[0] = Simulation_B.lcon_data_idx_0;
  cineq_data[2] = Simulation_B.rcon_data_idx_0;
  cineq_data[1] = Simulation_B.lcon_data_idx_1;
  cineq_data[3] = Simulation_B.rcon_data_idx_1;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulat_eML_blk_kernel_anonFcn2(const real_T runtimedata_x[4], const
  real_T runtimedata_OutputMin[12], const real_T runtimedata_OutputMax[12],
  const real_T runtimedata_Parameters_f1[4], const real_T
  runtimedata_Parameters_f2[4], const real_T z[21], real_T varargout_1_data[],
  int32_T varargout_1_size[2], real_T varargout_2[16], real_T varargout_3_data[],
  int32_T varargout_3_size[2], real_T varargout_4[336])
{
  int8_T b_input_sizes_idx_1;
  int8_T c_input_sizes_idx_1;
  int8_T sizes_idx_0;
  boolean_T empty_non_axis_sizes;
  static const int8_T b[32] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 };

  Simulation_znlmpc_getXUe(z, runtimedata_x, Simulation_B.X_b, Simulation_B.U,
    &Simulation_B.e_f);
  memset(&Simulation_B.b_Jx[0], 0, sizeof(real_T) << 8U);
  memset(&Simulation_B.Jmv[0], 0, sizeof(real_T) << 7U);
  memset(&varargout_2[0], 0, sizeof(real_T) << 4U);
  Simulation_B.ic[0] = 1.0;
  Simulation_B.ic[1] = 2.0;
  Simulation_B.ic[2] = 3.0;
  Simulation_B.ic[3] = 4.0;
  for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 5;
       Simulation_B.fk_tmp_o++) {
    Simulation_B.i_i = Simulation_B.fk_tmp_o << 1;
    Simulation_B.b_U[Simulation_B.i_i] = Simulation_B.U[Simulation_B.fk_tmp_o];
    Simulation_B.b_U[Simulation_B.i_i + 1] =
      Simulation_B.U[Simulation_B.fk_tmp_o + 5];
    Simulation_B.i_i = Simulation_B.fk_tmp_o << 2;
    Simulation_B.b_X[Simulation_B.i_i] = Simulation_B.X_b[Simulation_B.fk_tmp_o];
    Simulation_B.b_X[Simulation_B.i_i + 1] =
      Simulation_B.X_b[Simulation_B.fk_tmp_o + 5];
    Simulation_B.b_X[Simulation_B.i_i + 2] =
      Simulation_B.X_b[Simulation_B.fk_tmp_o + 10];
    Simulation_B.b_X[Simulation_B.i_i + 3] =
      Simulation_B.X_b[Simulation_B.fk_tmp_o + 15];
  }

  for (Simulation_B.i_i = 0; Simulation_B.i_i < 4; Simulation_B.i_i++) {
    Simulation_B.fk_tmp_o = Simulation_B.i_i << 2;
    Simulation_B.dx_g = Simulation_B.b_X[Simulation_B.fk_tmp_o + 2];
    Simulation_B.fk_tmp_tmp = Simulation_B.b_X[Simulation_B.fk_tmp_o + 3];
    Simulation_B.fk[0] = Simulation_B.fk_tmp_tmp * cos(Simulation_B.dx_g);
    Simulation_B.fk[1] = Simulation_B.fk_tmp_tmp * sin(Simulation_B.dx_g);
    Simulation_B.fk_tmp_tmp_m = Simulation_B.i_i << 1;
    Simulation_B.dx_g = tan(Simulation_B.b_U[Simulation_B.fk_tmp_tmp_m + 1]);
    Simulation_B.fk[2] = Simulation_B.fk_tmp_tmp * Simulation_B.dx_g;
    Simulation_B.fk[3] = (Simulation_B.b_U[Simulation_B.fk_tmp_tmp_m] -
                          Simulation_B.fk_tmp_tmp * 2.3) * 0.2;
    for (Simulation_B.i1 = 0; Simulation_B.i1 < 4; Simulation_B.i1++) {
      Simulation_B.b_X_n[Simulation_B.i1] = Simulation_B.b_X[(Simulation_B.i_i <<
        2) + Simulation_B.i1];
    }

    for (Simulation_B.i2 = 0; Simulation_B.i2 < 2; Simulation_B.i2++) {
      Simulation_B.b_U_i[Simulation_B.i2] = Simulation_B.b_U[(Simulation_B.i_i <<
        1) + Simulation_B.i2];
    }

    Sim_znlmpc_computeJacobianState(Simulation_B.fk, Simulation_B.b_X_n,
      Simulation_B.b_U_i, Simulation_B.Ak, Simulation_B.val_i);
    Simulation_B.fk1_tmp = (Simulation_B.i_i + 1) << 2;
    Simulation_B.fk_tmp_tmp = Simulation_B.b_X[Simulation_B.fk1_tmp + 2];
    Simulation_B.fk1_tmp_tmp = Simulation_B.b_X[Simulation_B.fk1_tmp + 3];
    Simulation_B.fk1[0] = Simulation_B.fk1_tmp_tmp * cos(Simulation_B.fk_tmp_tmp);
    Simulation_B.fk1[1] = Simulation_B.fk1_tmp_tmp * sin(Simulation_B.fk_tmp_tmp);
    Simulation_B.fk1[2] = Simulation_B.fk1_tmp_tmp * Simulation_B.dx_g;
    Simulation_B.fk1[3] = (Simulation_B.b_U[Simulation_B.fk_tmp_tmp_m] -
      Simulation_B.fk1_tmp_tmp * 2.3) * 0.2;
    for (Simulation_B.i3 = 0; Simulation_B.i3 < 4; Simulation_B.i3++) {
      Simulation_B.b_X_n[Simulation_B.i3] = Simulation_B.b_X[((Simulation_B.i_i
        + 1) << 2) + Simulation_B.i3];
    }

    for (Simulation_B.i4 = 0; Simulation_B.i4 < 2; Simulation_B.i4++) {
      Simulation_B.b_U_i[Simulation_B.i4] = Simulation_B.b_U[(Simulation_B.i_i <<
        1) + Simulation_B.i4];
    }

    Sim_znlmpc_computeJacobianState(Simulation_B.fk1, Simulation_B.b_X_n,
      Simulation_B.b_U_i, Simulation_B.Ak1, Simulation_B.Bk1);
    varargout_2[static_cast<int32_T>(Simulation_B.ic[0]) - 1] =
      ((Simulation_B.fk[0] + Simulation_B.fk1[0]) * 0.05 +
       Simulation_B.b_X[Simulation_B.fk_tmp_o]) -
      Simulation_B.b_X[Simulation_B.fk1_tmp];
    varargout_2[static_cast<int32_T>(Simulation_B.ic[1]) - 1] =
      ((Simulation_B.fk[1] + Simulation_B.fk1[1]) * 0.05 +
       Simulation_B.b_X[Simulation_B.fk_tmp_o + 1]) -
      Simulation_B.b_X[Simulation_B.fk1_tmp + 1];
    varargout_2[static_cast<int32_T>(Simulation_B.ic[2]) - 1] =
      ((Simulation_B.fk[2] + Simulation_B.fk1[2]) * 0.05 +
       Simulation_B.b_X[Simulation_B.fk_tmp_o + 2]) -
      Simulation_B.b_X[Simulation_B.fk1_tmp + 2];
    varargout_2[static_cast<int32_T>(Simulation_B.ic[3]) - 1] =
      ((Simulation_B.fk[3] + Simulation_B.fk1[3]) * 0.05 +
       Simulation_B.b_X[Simulation_B.fk_tmp_o + 3]) -
      Simulation_B.b_X[Simulation_B.fk1_tmp + 3];
    if (Simulation_B.i_i + 1 > 1) {
      for (Simulation_B.k_k = 0; Simulation_B.k_k < 4; Simulation_B.k_k++) {
        Simulation_B.fk_tmp_o = Simulation_B.k_k << 2;
        Simulation_B.fk_tmp_tmp_m = Simulation_B.k_k << 4;
        Simulation_B.fk1_tmp = (Simulation_B.i_i - 1) << 6;
        Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[0]) +
                            Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) -
          1] = Simulation_B.Ak[Simulation_B.fk_tmp_o] * 0.05;
        Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[1]) +
                            Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) -
          1] = Simulation_B.Ak[Simulation_B.fk_tmp_o + 1] * 0.05;
        Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[2]) +
                            Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) -
          1] = Simulation_B.Ak[Simulation_B.fk_tmp_o + 2] * 0.05;
        Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[3]) +
                            Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) -
          1] = Simulation_B.Ak[Simulation_B.fk_tmp_o + 3] * 0.05;
        Simulation_B.fk_tmp_o = ((Simulation_B.fk_tmp_tmp_m +
          static_cast<int32_T>(Simulation_B.ic[Simulation_B.k_k])) +
          Simulation_B.fk1_tmp) - 1;
        Simulation_B.b_Jx[Simulation_B.fk_tmp_o]++;
      }
    }

    for (Simulation_B.k_k = 0; Simulation_B.k_k < 4; Simulation_B.k_k++) {
      Simulation_B.fk_tmp_o = Simulation_B.k_k << 2;
      Simulation_B.fk_tmp_tmp_m = Simulation_B.k_k << 4;
      Simulation_B.fk1_tmp = Simulation_B.i_i << 6;
      Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[0]) +
                          Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) - 1]
        = Simulation_B.Ak1[Simulation_B.fk_tmp_o] * 0.05;
      Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[1]) +
                          Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) - 1]
        = Simulation_B.Ak1[Simulation_B.fk_tmp_o + 1] * 0.05;
      Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[2]) +
                          Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) - 1]
        = Simulation_B.Ak1[Simulation_B.fk_tmp_o + 2] * 0.05;
      Simulation_B.b_Jx[((static_cast<int32_T>(Simulation_B.ic[3]) +
                          Simulation_B.fk_tmp_tmp_m) + Simulation_B.fk1_tmp) - 1]
        = Simulation_B.Ak1[Simulation_B.fk_tmp_o + 3] * 0.05;
      Simulation_B.fk_tmp_o = ((Simulation_B.fk_tmp_tmp_m + static_cast<int32_T>
        (Simulation_B.ic[Simulation_B.k_k])) + Simulation_B.fk1_tmp) - 1;
      Simulation_B.b_Jx[Simulation_B.fk_tmp_o]--;
    }

    for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 8;
         Simulation_B.fk_tmp_o++) {
      Simulation_B.val_i[Simulation_B.fk_tmp_o] =
        (Simulation_B.val_i[Simulation_B.fk_tmp_o] +
         Simulation_B.Bk1[Simulation_B.fk_tmp_o]) * 0.05;
    }

    for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 2;
         Simulation_B.fk_tmp_o++) {
      Simulation_B.fk_tmp_tmp_m = Simulation_B.fk_tmp_o << 2;
      Simulation_B.fk1_tmp = Simulation_B.fk_tmp_o << 4;
      Simulation_B.k_k = Simulation_B.i_i << 5;
      Simulation_B.Jmv[((static_cast<int32_T>(Simulation_B.ic[0]) +
                         Simulation_B.fk1_tmp) + Simulation_B.k_k) - 1] =
        Simulation_B.val_i[Simulation_B.fk_tmp_tmp_m];
      Simulation_B.Jmv[((static_cast<int32_T>(Simulation_B.ic[1]) +
                         Simulation_B.fk1_tmp) + Simulation_B.k_k) - 1] =
        Simulation_B.val_i[Simulation_B.fk_tmp_tmp_m + 1];
      Simulation_B.Jmv[((static_cast<int32_T>(Simulation_B.ic[2]) +
                         Simulation_B.fk1_tmp) + Simulation_B.k_k) - 1] =
        Simulation_B.val_i[Simulation_B.fk_tmp_tmp_m + 2];
      Simulation_B.Jmv[((static_cast<int32_T>(Simulation_B.ic[3]) +
                         Simulation_B.fk1_tmp) + Simulation_B.k_k) - 1] =
        Simulation_B.val_i[Simulation_B.fk_tmp_tmp_m + 3];
    }

    Simulation_B.ic[0] += 4.0;
    Simulation_B.ic[1] += 4.0;
    Simulation_B.ic[2] += 4.0;
    Simulation_B.ic[3] += 4.0;
  }

  Simulation_outputBounds(runtimedata_OutputMin, runtimedata_OutputMax,
    Simulation_B.X_b, Simulation_B.e_f, Simulation_B.c_data_d,
    Simulation_B.c_size, Simulation_B.Jc_data, Simulation_B.Jc_size);
  Simulation_ConstraintFunction(Simulation_B.X_b, runtimedata_Parameters_f1,
    runtimedata_Parameters_f2, Simulation_B.ic, &Simulation_B.cu_size);
  Simulation_B.Jx_size[0] = 4;
  Simulation_B.Jx_size[1] = 4;
  Simulation_B.Jx_size[2] = 4;
  memset(&Simulation_B.Ju_data[0], 0, sizeof(real_T) << 5U);
  Simulation_B.Je_size = 4;
  for (Simulation_B.i_i = 0; Simulation_B.i_i < 20; Simulation_B.i_i++) {
    Simulation_B.dx_g = fabs(Simulation_B.X_b[Simulation_B.i_i]);
    if (Simulation_B.dx_g < 1.0) {
      Simulation_B.dx_g = 1.0;
    }

    Simulation_B.b_X[Simulation_B.i_i] = Simulation_B.dx_g;
  }

  for (Simulation_B.i_i = 0; Simulation_B.i_i < 4; Simulation_B.i_i++) {
    for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 4;
         Simulation_B.fk_tmp_o++) {
      Simulation_B.dx_g = 1.0E-6 * Simulation_B.b_X[Simulation_B.fk_tmp_o];
      Simulation_B.fk_tmp_tmp_m = (5 * Simulation_B.fk_tmp_o + Simulation_B.i_i)
        + 1;
      Simulation_B.X_b[Simulation_B.fk_tmp_tmp_m] += Simulation_B.dx_g;
      Simulation_ConstraintFunction(Simulation_B.X_b, runtimedata_Parameters_f1,
        runtimedata_Parameters_f2, Simulation_B.fk1, &Simulation_B.cu_size);
      Simulation_B.X_b[Simulation_B.fk_tmp_tmp_m] -= Simulation_B.dx_g;
      Simulation_B.fk_tmp_tmp_m = Simulation_B.i_i << 4;
      Simulation_B.Jx_data_d[(Simulation_B.fk_tmp_o << 2) +
        Simulation_B.fk_tmp_tmp_m] = (Simulation_B.fk1[0] - Simulation_B.ic[0]) /
        Simulation_B.dx_g;
      Simulation_B.Jx_data_d[((Simulation_B.fk_tmp_o << 2) +
        Simulation_B.fk_tmp_tmp_m) + 1] = (Simulation_B.fk1[1] -
        Simulation_B.ic[1]) / Simulation_B.dx_g;
      Simulation_B.Jx_data_d[((Simulation_B.fk_tmp_o << 2) +
        Simulation_B.fk_tmp_tmp_m) + 2] = (Simulation_B.fk1[2] -
        Simulation_B.ic[2]) / Simulation_B.dx_g;
      Simulation_B.Jx_data_d[((Simulation_B.fk_tmp_o << 2) +
        Simulation_B.fk_tmp_tmp_m) + 3] = (Simulation_B.fk1[3] -
        Simulation_B.ic[3]) / Simulation_B.dx_g;
    }
  }

  for (Simulation_B.i_i = 0; Simulation_B.i_i < 10; Simulation_B.i_i++) {
    Simulation_B.dx_g = fabs(Simulation_B.U[Simulation_B.i_i]);
    if (Simulation_B.dx_g < 1.0) {
      Simulation_B.dx_g = 1.0;
    }

    Simulation_B.b_U[Simulation_B.i_i] = Simulation_B.dx_g;
  }

  Simulation_ConstraintFunction(Simulation_B.X_b, runtimedata_Parameters_f1,
    runtimedata_Parameters_f2, Simulation_B.fk1, &Simulation_B.cu_size);
  for (Simulation_B.i_i = 0; Simulation_B.i_i < 3; Simulation_B.i_i++) {
    for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 2;
         Simulation_B.fk_tmp_o++) {
      Simulation_B.dx_g = 1.0E-6 * Simulation_B.b_U[Simulation_B.fk_tmp_o];
      Simulation_B.fk_tmp_tmp_m = Simulation_B.i_i << 3;
      Simulation_B.Ju_data[(Simulation_B.fk_tmp_o << 2) +
        Simulation_B.fk_tmp_tmp_m] = (Simulation_B.fk1[0] - Simulation_B.ic[0]) /
        Simulation_B.dx_g;
      Simulation_B.Ju_data[((Simulation_B.fk_tmp_o << 2) +
                            Simulation_B.fk_tmp_tmp_m) + 1] = (Simulation_B.fk1
        [1] - Simulation_B.ic[1]) / Simulation_B.dx_g;
      Simulation_B.Ju_data[((Simulation_B.fk_tmp_o << 2) +
                            Simulation_B.fk_tmp_tmp_m) + 2] = (Simulation_B.fk1
        [2] - Simulation_B.ic[2]) / Simulation_B.dx_g;
      Simulation_B.Ju_data[((Simulation_B.fk_tmp_o << 2) +
                            Simulation_B.fk_tmp_tmp_m) + 3] = (Simulation_B.fk1
        [3] - Simulation_B.ic[3]) / Simulation_B.dx_g;
    }
  }

  Simulation_ConstraintFunction(Simulation_B.X_b, runtimedata_Parameters_f1,
    runtimedata_Parameters_f2, Simulation_B.fk1, &Simulation_B.cu_size);
  for (Simulation_B.i_i = 0; Simulation_B.i_i < 2; Simulation_B.i_i++) {
    Simulation_B.dx_g = 1.0E-6 * Simulation_B.b_U[Simulation_B.i_i];
    Simulation_B.fk_tmp_tmp_m = 24;
    Simulation_B.Ju_data[(Simulation_B.i_i << 2) + Simulation_B.fk_tmp_tmp_m] =
      (Simulation_B.fk1[0] - Simulation_B.ic[0]) / Simulation_B.dx_g;
    Simulation_B.Ju_data[((Simulation_B.i_i << 2) + Simulation_B.fk_tmp_tmp_m) +
      1] = (Simulation_B.fk1[1] - Simulation_B.ic[1]) / Simulation_B.dx_g;
    Simulation_B.Ju_data[((Simulation_B.i_i << 2) + Simulation_B.fk_tmp_tmp_m) +
      2] = (Simulation_B.fk1[2] - Simulation_B.ic[2]) / Simulation_B.dx_g;
    Simulation_B.Ju_data[((Simulation_B.i_i << 2) + Simulation_B.fk_tmp_tmp_m) +
      3] = (Simulation_B.fk1[3] - Simulation_B.ic[3]) / Simulation_B.dx_g;
  }

  Simulation_B.e_f = fabs(Simulation_B.e_f);
  Simulation_ConstraintFunction(Simulation_B.X_b, runtimedata_Parameters_f1,
    runtimedata_Parameters_f2, Simulation_B.fk1, &Simulation_B.cu_size);
  Simulation_ConstraintFunction(Simulation_B.X_b, runtimedata_Parameters_f1,
    runtimedata_Parameters_f2, Simulation_B.b_X_n, &Simulation_B.cu_size);
  if ((1.0E-6 >= Simulation_B.e_f) || rtIsNaN(Simulation_B.e_f)) {
    Simulation_B.e_f = 1.0E-6;
  }

  Simulation_B.e_f = Simulation_B.e_f * 1.0E-6 * 2.0;
  Simulation_B.fk[0] = (Simulation_B.fk1[0] - Simulation_B.b_X_n[0]) /
    Simulation_B.e_f;
  Simulation_B.fk[1] = (Simulation_B.fk1[1] - Simulation_B.b_X_n[1]) /
    Simulation_B.e_f;
  Simulation_B.fk[2] = (Simulation_B.fk1[2] - Simulation_B.b_X_n[2]) /
    Simulation_B.e_f;
  Simulation_B.fk[3] = (Simulation_B.fk1[3] - Simulation_B.b_X_n[3]) /
    Simulation_B.e_f;
  Simulatio_znlmpc_reformJacobian(Simulation_B.Jx_data_d, Simulation_B.Jx_size,
    Simulation_B.Ju_data, Simulation_B.fk, &Simulation_B.Je_size,
    Simulation_B.d_data, Simulation_B.d_size);
  if ((Simulation_B.c_size[0] != 0) && (Simulation_B.c_size[1] != 0)) {
    Simulation_B.i_i = Simulation_B.c_size[0];
  } else {
    Simulation_B.i_i = 0;
  }

  varargout_1_size[0] = Simulation_B.i_i + 4;
  varargout_1_size[1] = 1;
  if (0 <= Simulation_B.i_i - 1) {
    memcpy(&varargout_1_data[0], &Simulation_B.c_data_d[0], Simulation_B.i_i *
           sizeof(real_T));
  }

  for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 4;
       Simulation_B.fk_tmp_o++) {
    varargout_1_data[Simulation_B.fk_tmp_o + Simulation_B.i_i] =
      Simulation_B.ic[Simulation_B.fk_tmp_o];
  }

  if ((Simulation_B.Jc_size[0] != 0) && (Simulation_B.Jc_size[1] != 0)) {
    sizes_idx_0 = static_cast<int8_T>(Simulation_B.Jc_size[0]);
  } else if (Simulation_B.d_size[0] != 0) {
    sizes_idx_0 = static_cast<int8_T>(Simulation_B.d_size[0]);
  } else {
    sizes_idx_0 = static_cast<int8_T>(Simulation_B.Jc_size[0]);
  }

  empty_non_axis_sizes = (sizes_idx_0 == 0);
  if (empty_non_axis_sizes || ((Simulation_B.Jc_size[0] != 0) &&
       (Simulation_B.Jc_size[1] != 0))) {
    b_input_sizes_idx_1 = static_cast<int8_T>(Simulation_B.Jc_size[1]);
  } else {
    b_input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes || (Simulation_B.d_size[0] != 0)) {
    c_input_sizes_idx_1 = 4;
  } else {
    c_input_sizes_idx_1 = 0;
  }

  varargout_3_size[0] = sizes_idx_0;
  varargout_3_size[1] = b_input_sizes_idx_1 + c_input_sizes_idx_1;
  Simulation_B.i_i = sizes_idx_0 * b_input_sizes_idx_1;
  Simulation_B.fk_tmp_tmp_m = sizes_idx_0 * c_input_sizes_idx_1;
  if (0 <= Simulation_B.i_i - 1) {
    memcpy(&varargout_3_data[0], &Simulation_B.Jc_data[0], Simulation_B.i_i *
           sizeof(real_T));
  }

  for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o <
       Simulation_B.fk_tmp_tmp_m; Simulation_B.fk_tmp_o++) {
    varargout_3_data[Simulation_B.fk_tmp_o + Simulation_B.i_i] =
      Simulation_B.d_data[Simulation_B.fk_tmp_o];
  }

  for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 4;
       Simulation_B.fk_tmp_o++) {
    for (Simulation_B.i_i = 0; Simulation_B.i_i < 16; Simulation_B.i_i++) {
      Simulation_B.fk_tmp_tmp_m = (Simulation_B.i_i << 2) +
        Simulation_B.fk_tmp_o;
      Simulation_B.Jx_data_d[Simulation_B.fk_tmp_tmp_m] = 0.0;
      for (Simulation_B.fk1_tmp = 0; Simulation_B.fk1_tmp < 8;
           Simulation_B.fk1_tmp++) {
        Simulation_B.Jx_data_d[Simulation_B.fk_tmp_tmp_m] += Simulation_B.Jmv
          [(Simulation_B.fk1_tmp << 4) + Simulation_B.i_i] * static_cast<real_T>
          (b[(Simulation_B.fk_tmp_o << 3) + Simulation_B.fk1_tmp]);
      }
    }
  }

  for (Simulation_B.fk_tmp_o = 0; Simulation_B.fk_tmp_o < 16;
       Simulation_B.fk_tmp_o++) {
    for (Simulation_B.i_i = 0; Simulation_B.i_i < 16; Simulation_B.i_i++) {
      varargout_4[Simulation_B.i_i + 21 * Simulation_B.fk_tmp_o] =
        Simulation_B.b_Jx[(Simulation_B.i_i << 4) + Simulation_B.fk_tmp_o];
    }

    Simulation_B.i_i = Simulation_B.fk_tmp_o << 2;
    varargout_4[21 * Simulation_B.fk_tmp_o + 16] =
      Simulation_B.Jx_data_d[Simulation_B.i_i];
    varargout_4[21 * Simulation_B.fk_tmp_o + 17] =
      Simulation_B.Jx_data_d[Simulation_B.i_i + 1];
    varargout_4[21 * Simulation_B.fk_tmp_o + 18] =
      Simulation_B.Jx_data_d[Simulation_B.i_i + 2];
    varargout_4[21 * Simulation_B.fk_tmp_o + 19] =
      Simulation_B.Jx_data_d[Simulation_B.i_i + 3];
    varargout_4[21 * Simulation_B.fk_tmp_o + 20] = 0.0;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_factoryConstruct(int32_T nVarMax, int32_T mConstrMax,
  int32_T mIneq, int32_T mNonlinIneq, s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *obj)
{
  obj->nVarMax = nVarMax;
  obj->mNonlinIneq = mNonlinIneq;
  obj->mNonlinEq = 16;
  obj->mIneq = mIneq;
  obj->mEq = 16;
  obj->iNonIneq0 = (mIneq - mNonlinIneq) + 1;
  obj->iNonEq0 = 1;
  obj->sqpFval = 0.0;
  obj->sqpFval_old = 0.0;
  obj->cIneq.size = mIneq;
  obj->cIneq_old.size = mIneq;
  obj->grad.size = nVarMax;
  obj->grad_old.size = nVarMax;
  obj->FunctionEvaluations = 0;
  obj->sqpIterations = 0;
  obj->sqpExitFlag = 0;
  obj->lambdasqp.size = mConstrMax;
  if (0 <= mConstrMax - 1) {
    memset(&obj->lambdasqp.data[0], 0, mConstrMax * sizeof(real_T));
  }

  obj->lambdaStopTest.size = mConstrMax;
  obj->lambdaStopTestPrev.size = mConstrMax;
  obj->steplength = 1.0;
  obj->delta_x.size = nVarMax;
  if (0 <= nVarMax - 1) {
    memset(&obj->delta_x.data[0], 0, nVarMax * sizeof(real_T));
  }

  obj->socDirection.size = nVarMax;
  obj->workingset_old.size = mConstrMax;
  if (mNonlinIneq > 0) {
    obj->JacCineqTrans_old.size[0] = nVarMax;
    obj->JacCineqTrans_old.size[1] = mNonlinIneq;
  } else {
    obj->JacCineqTrans_old.size[0] = 0;
    obj->JacCineqTrans_old.size[1] = 0;
  }

  obj->JacCeqTrans_old.size[0] = nVarMax;
  obj->JacCeqTrans_old.size[1] = 16;
  obj->gradLag.size = nVarMax;
  obj->delta_gradLag.size = nVarMax;
  obj->xstar.size = nVarMax;
  obj->fstar = 0.0;
  obj->firstorderopt = 0.0;
  obj->lambda.size = mConstrMax;
  if (0 <= mConstrMax - 1) {
    memset(&obj->lambda.data[0], 0, mConstrMax * sizeof(real_T));
  }

  obj->state = 0;
  obj->maxConstr = 0.0;
  obj->iterations = 0;
  obj->searchDir.size = nVarMax;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulatio_factoryConstruct_cyd0(int32_T MaxVars, int32_T
  *obj_grad_size, int32_T *obj_Hx_size, boolean_T *obj_hasLinear, int32_T
  *obj_nvar, int32_T *obj_maxVar, real_T *obj_beta, real_T *obj_rho, int32_T
  *obj_objtype, int32_T *obj_prev_objtype, int32_T *obj_prev_nvar, boolean_T
  *obj_prev_hasLinear, real_T *obj_gammaScalar)
{
  *obj_grad_size = MaxVars;
  *obj_Hx_size = MaxVars - 1;
  *obj_hasLinear = false;
  *obj_nvar = 0;
  *obj_maxVar = MaxVars;
  *obj_beta = 0.0;
  *obj_rho = 0.0;
  *obj_objtype = 3;
  *obj_prev_objtype = 3;
  *obj_prev_nvar = 0;
  *obj_prev_hasLinear = false;
  *obj_gammaScalar = 0.0;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulati_factoryConstruct_cyd03(int32_T mIneqMax, int32_T nVarMax,
  int32_T mConstrMax, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj)
{
  int32_T i;
  obj->mConstr = 0;
  obj->mConstrOrig = 0;
  obj->mConstrMax = mConstrMax;
  obj->nVar = 21;
  obj->nVarOrig = 21;
  obj->nVarMax = nVarMax;
  obj->ldA = nVarMax;
  obj->Aineq.size = mIneqMax * nVarMax;
  obj->bineq.size = mIneqMax;
  obj->Aeq.size = nVarMax << 4;
  obj->lb.size = nVarMax;
  obj->ub.size = nVarMax;
  obj->indexLB.size = nVarMax;
  obj->indexUB.size = nVarMax;
  obj->indexFixed.size = nVarMax;
  obj->mEqRemoved = 0;
  obj->ATwset.size = nVarMax * mConstrMax;
  obj->bwset.size = mConstrMax;
  obj->nActiveConstr = 0;
  obj->maxConstrWorkspace.size = mConstrMax;
  for (i = 0; i < 5; i++) {
    obj->sizes[i] = 0;
    obj->sizesNormal[i] = 0;
    obj->sizesPhaseOne[i] = 0;
    obj->sizesRegularized[i] = 0;
    obj->sizesRegPhaseOne[i] = 0;
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdx[i] = 0;
    obj->isActiveIdxNormal[i] = 0;
    obj->isActiveIdxPhaseOne[i] = 0;
    obj->isActiveIdxRegularized[i] = 0;
    obj->isActiveIdxRegPhaseOne[i] = 0;
  }

  obj->isActiveConstr.size = mConstrMax;
  obj->Wid.size = mConstrMax;
  obj->Wlocalidx.size = mConstrMax;
  for (i = 0; i < 5; i++) {
    obj->nWConstr[i] = 0;
  }

  obj->probType = 3;
  obj->SLACK0 = 1.0E-5;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_loadProblem(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj, int32_T
  mIneq, int32_T mLinIneq, const real_T Aineq_data[], int32_T mLB, int32_T mUB,
  int32_T mFixed, int32_T mConstrMax)
{
  int32_T e_k;
  int32_T k;
  e_k = mIneq + mLB;
  k = ((e_k + mUB) + mFixed) + 16;
  obj->mConstr = k;
  obj->mConstrOrig = k;
  obj->mConstrMax = mConstrMax;
  obj->sizes[0] = mFixed;
  obj->sizes[1] = 16;
  obj->sizes[2] = mIneq;
  obj->sizes[3] = mLB;
  obj->sizes[4] = mUB;
  for (k = 0; k < 5; k++) {
    obj->sizesNormal[k] = obj->sizes[k];
  }

  obj->sizesPhaseOne[0] = mFixed;
  obj->sizesPhaseOne[1] = 16;
  obj->sizesPhaseOne[2] = mIneq;
  obj->sizesPhaseOne[3] = mLB + 1;
  obj->sizesPhaseOne[4] = mUB;
  obj->sizesRegularized[0] = mFixed;
  obj->sizesRegularized[1] = 16;
  obj->sizesRegularized[2] = mIneq;
  obj->sizesRegularized[3] = e_k + 32;
  obj->sizesRegularized[4] = mUB;
  obj->sizesRegPhaseOne[0] = mFixed;
  obj->sizesRegPhaseOne[1] = 16;
  obj->sizesRegPhaseOne[2] = mIneq;
  obj->sizesRegPhaseOne[3] = e_k + 33;
  obj->sizesRegPhaseOne[4] = mUB;
  obj->isActiveIdxNormal[0] = 1;
  obj->isActiveIdxNormal[1] = mFixed;
  obj->isActiveIdxNormal[2] = 16;
  obj->isActiveIdxNormal[3] = mIneq;
  obj->isActiveIdxNormal[4] = mLB;
  obj->isActiveIdxNormal[5] = mUB;
  for (k = 0; k < 6; k++) {
    obj->isActiveIdxRegPhaseOne[k] = obj->isActiveIdxNormal[k];
  }

  for (k = 0; k < 5; k++) {
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 6; k++) {
    obj->isActiveIdx[k] = obj->isActiveIdxRegPhaseOne[k];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 16;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = mLB + 1;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj->isActiveIdxNormal[k + 1] += obj->isActiveIdxNormal[k];
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 6; k++) {
    obj->isActiveIdxPhaseOne[k] = obj->isActiveIdxRegPhaseOne[k];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 16;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = e_k + 32;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj->isActiveIdxRegPhaseOne[k + 1] += obj->isActiveIdxRegPhaseOne[k];
  }

  for (k = 0; k < 6; k++) {
    obj->isActiveIdxRegularized[k] = obj->isActiveIdxRegPhaseOne[k];
  }

  obj->isActiveIdxRegPhaseOne[0] = 1;
  obj->isActiveIdxRegPhaseOne[1] = mFixed;
  obj->isActiveIdxRegPhaseOne[2] = 16;
  obj->isActiveIdxRegPhaseOne[3] = mIneq;
  obj->isActiveIdxRegPhaseOne[4] = e_k + 33;
  obj->isActiveIdxRegPhaseOne[5] = mUB;
  for (e_k = 0; e_k < 5; e_k++) {
    obj->isActiveIdxRegPhaseOne[e_k + 1] += obj->isActiveIdxRegPhaseOne[e_k];
  }

  if (mIneq > 0) {
    for (k = 0; k < mLinIneq; k++) {
      for (e_k = 0; e_k < 21; e_k++) {
        obj->Aineq.data[e_k + obj->ldA * k] = Aineq_data[mLinIneq * e_k + k];
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulation_checkVectorNonFinite(int32_T N, const real_T vec_data[],
  int32_T iv0)
{
  int32_T idx_current;
  int32_T idx_end;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = iv0 - 2;
  idx_end = (iv0 + N) - 1;
  while (allFinite && (idx_current + 2 <= idx_end)) {
    Simulation_B.allFinite_tmp = vec_data[idx_current + 1];
    allFinite = ((!rtIsInf(Simulation_B.allFinite_tmp)) && (!rtIsNaN
      (Simulation_B.allFinite_tmp)));
    idx_current++;
  }

  if (!allFinite) {
    if (rtIsNaN(vec_data[idx_current])) {
      status = -3;
    } else if (vec_data[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulati_checkVectorNonFinite_c(const real_T vec[16])
{
  int32_T idx_current;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = -1;
  while (allFinite && (idx_current + 2 <= 16)) {
    Simulation_B.allFinite_tmp_e = vec[idx_current + 1];
    allFinite = ((!rtIsInf(Simulation_B.allFinite_tmp_e)) && (!rtIsNaN
      (Simulation_B.allFinite_tmp_e)));
    idx_current++;
  }

  if (!allFinite) {
    if (rtIsNaN(vec[idx_current])) {
      status = -3;
    } else if (vec[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulation_checkMatrixNonFinite(int32_T ncols, const real_T
  mat_data[], int32_T col0, int32_T ldm)
{
  int32_T col;
  int32_T col_end;
  int32_T idx_mat;
  int32_T row;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  row = -1;
  col = col0;
  col_end = (col0 + ncols) - 1;
  while (allFinite && (col <= col_end)) {
    row = -1;
    while (allFinite && (row + 2 <= 21)) {
      idx_mat = ((col - 1) * ldm + row) + 1;
      allFinite = ((!rtIsInf(mat_data[idx_mat])) && (!rtIsNaN(mat_data[idx_mat])));
      row++;
    }

    col++;
  }

  if (!allFinite) {
    idx_mat = (col - 2) * ldm + row;
    if (rtIsNaN(mat_data[idx_mat])) {
      status = -3;
    } else if (mat_data[idx_mat] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void evalObjAndConstrAndDerivatives(const real_T
  obj_objfun_workspace_runtimedat[4], const real_T
  obj_objfun_workspace_runtimed_0[2], const real_T
  obj_nonlcon_workspace_runtimeda[4], const real_T
  obj_nonlcon_workspace_runtime_0[12], const real_T
  obj_nonlcon_workspace_runtime_1[12], const real_T
  obj_nonlcon_workspace_runtime_2[4], const real_T
  obj_nonlcon_workspace_runtime_3[4], int32_T obj_mCineq, const real_T x[21],
  real_T grad_workspace_data[], real_T Cineq_workspace_data[], int32_T ineq0,
  real_T Ceq_workspace[16], real_T JacIneqTrans_workspace_data[], int32_T
  iJI_col, int32_T ldJI, real_T JacEqTrans_workspace_data[], int32_T ldJE,
  real_T *fval, int32_T *status)
{
  static const int8_T b[32] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1 };

  Simulation_znlmpc_getXUe(x, obj_objfun_workspace_runtimedat, Simulation_B.X_o,
    Simulation_B.c_x, &Simulation_B.d_x);
  Simulation_B.dx = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
  Simulation_B.b_a = Simulation_B.X_o[9] - obj_objfun_workspace_runtimed_0[1];
  *fval = Simulation_B.dx * Simulation_B.dx + Simulation_B.b_a *
    Simulation_B.b_a;
  memset(&Simulation_B.Gfuu[0], 0, sizeof(real_T) << 3U);
  for (Simulation_B.e_k = 0; Simulation_B.e_k < 20; Simulation_B.e_k++) {
    Simulation_B.dx = fabs(Simulation_B.X_o[Simulation_B.e_k]);
    if (Simulation_B.dx < 1.0) {
      Simulation_B.dx = 1.0;
    }

    Simulation_B.xa[Simulation_B.e_k] = Simulation_B.dx;
  }

  for (Simulation_B.e_k = 0; Simulation_B.e_k < 4; Simulation_B.e_k++) {
    Simulation_B.dx = 1.0E-6 * Simulation_B.xa[0];
    Simulation_B.X_o[Simulation_B.e_k + 1] += Simulation_B.dx;
    Simulation_B.b_a = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
    Simulation_B.d_a_tmp_tmp = Simulation_B.X_o[9] -
      obj_objfun_workspace_runtimed_0[1];
    Simulation_B.X_o[Simulation_B.e_k + 1] -= Simulation_B.dx;
    Simulation_B.Gfxu_tmp = Simulation_B.e_k << 2;
    Simulation_B.Gfxu[Simulation_B.Gfxu_tmp] = ((Simulation_B.b_a *
      Simulation_B.b_a + Simulation_B.d_a_tmp_tmp * Simulation_B.d_a_tmp_tmp) - *
      fval) / Simulation_B.dx;
    Simulation_B.dx = 1.0E-6 * Simulation_B.xa[1];
    Simulation_B.X_o[Simulation_B.e_k + 6] += Simulation_B.dx;
    Simulation_B.b_a = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
    Simulation_B.d_a_tmp_tmp = Simulation_B.X_o[9] -
      obj_objfun_workspace_runtimed_0[1];
    Simulation_B.X_o[Simulation_B.e_k + 6] -= Simulation_B.dx;
    Simulation_B.Gfxu[Simulation_B.Gfxu_tmp + 1] = ((Simulation_B.b_a *
      Simulation_B.b_a + Simulation_B.d_a_tmp_tmp * Simulation_B.d_a_tmp_tmp) - *
      fval) / Simulation_B.dx;
    Simulation_B.dx = 1.0E-6 * Simulation_B.xa[2];
    Simulation_B.X_o[Simulation_B.e_k + 11] += Simulation_B.dx;
    Simulation_B.b_a = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
    Simulation_B.d_a_tmp_tmp = Simulation_B.X_o[9] -
      obj_objfun_workspace_runtimed_0[1];
    Simulation_B.X_o[Simulation_B.e_k + 11] -= Simulation_B.dx;
    Simulation_B.Gfxu[Simulation_B.Gfxu_tmp + 2] = ((Simulation_B.b_a *
      Simulation_B.b_a + Simulation_B.d_a_tmp_tmp * Simulation_B.d_a_tmp_tmp) - *
      fval) / Simulation_B.dx;
    Simulation_B.dx = 1.0E-6 * Simulation_B.xa[3];
    Simulation_B.X_o[Simulation_B.e_k + 16] += Simulation_B.dx;
    Simulation_B.b_a = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
    Simulation_B.d_a_tmp_tmp = Simulation_B.X_o[9] -
      obj_objfun_workspace_runtimed_0[1];
    Simulation_B.X_o[Simulation_B.e_k + 16] -= Simulation_B.dx;
    Simulation_B.Gfxu[Simulation_B.Gfxu_tmp + 3] = ((Simulation_B.b_a *
      Simulation_B.b_a + Simulation_B.d_a_tmp_tmp * Simulation_B.d_a_tmp_tmp) - *
      fval) / Simulation_B.dx;
  }

  for (Simulation_B.e_k = 0; Simulation_B.e_k < 10; Simulation_B.e_k++) {
    Simulation_B.dx = fabs(Simulation_B.c_x[Simulation_B.e_k]);
    if (Simulation_B.dx < 1.0) {
      Simulation_B.dx = 1.0;
    }

    Simulation_B.ua[Simulation_B.e_k] = Simulation_B.dx;
  }

  for (Simulation_B.e_k = 0; Simulation_B.e_k < 3; Simulation_B.e_k++) {
    Simulation_B.dx = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
    Simulation_B.b_a = Simulation_B.X_o[9] - obj_objfun_workspace_runtimed_0[1];
    Simulation_B.Gfxu_tmp = Simulation_B.e_k << 1;
    Simulation_B.dx *= Simulation_B.dx;
    Simulation_B.Gfuu[Simulation_B.Gfxu_tmp] = ((Simulation_B.b_a *
      Simulation_B.b_a + Simulation_B.dx) - *fval) / (1.0E-6 * Simulation_B.ua[0]);
    Simulation_B.Gfuu[Simulation_B.Gfxu_tmp + 1] = ((Simulation_B.b_a *
      Simulation_B.b_a + Simulation_B.dx) - *fval) / (1.0E-6 * Simulation_B.ua[1]);
  }

  Simulation_B.dx = Simulation_B.X_o[4] - obj_objfun_workspace_runtimed_0[0];
  Simulation_B.b_a = Simulation_B.X_o[9] - obj_objfun_workspace_runtimed_0[1];
  Simulation_B.Gfuu[6] = ((Simulation_B.dx * Simulation_B.dx + Simulation_B.b_a *
    Simulation_B.b_a) - *fval) / (1.0E-6 * Simulation_B.ua[0]);
  Simulation_B.Gfuu[7] = ((Simulation_B.dx * Simulation_B.dx + Simulation_B.b_a *
    Simulation_B.b_a) - *fval) / (1.0E-6 * Simulation_B.ua[1]);
  Simulation_B.d_x = fabs(Simulation_B.d_x);
  for (Simulation_B.e_k = 0; Simulation_B.e_k < 4; Simulation_B.e_k++) {
    Simulation_B.d_a_tmp_tmp = 0.0;
    for (Simulation_B.Gfxu_tmp = 0; Simulation_B.Gfxu_tmp < 8;
         Simulation_B.Gfxu_tmp++) {
      Simulation_B.d_a_tmp_tmp += static_cast<real_T>(b[(Simulation_B.Gfxu_tmp <<
        2) + Simulation_B.e_k]) * Simulation_B.Gfuu[Simulation_B.Gfxu_tmp];
    }

    Simulation_B.dv1[Simulation_B.e_k] = Simulation_B.d_a_tmp_tmp;
  }

  memcpy(&Simulation_B.b_x[0], &Simulation_B.Gfxu[0], sizeof(real_T) << 4U);
  Simulation_B.b_x[16] = Simulation_B.dv1[0];
  Simulation_B.b_x[17] = Simulation_B.dv1[1];
  Simulation_B.b_x[18] = Simulation_B.dv1[2];
  Simulation_B.b_x[19] = Simulation_B.dv1[3];
  if ((1.0E-6 >= Simulation_B.d_x) || rtIsNaN(Simulation_B.d_x)) {
    Simulation_B.d_x = 1.0E-6;
  }

  Simulation_B.dx *= Simulation_B.dx;
  Simulation_B.b_x[20] = ((Simulation_B.b_a * Simulation_B.b_a + Simulation_B.dx)
    - (Simulation_B.b_a * Simulation_B.b_a + Simulation_B.dx)) /
    (Simulation_B.d_x * 1.0E-6 * 2.0);
  memcpy(&grad_workspace_data[0], &Simulation_B.b_x[0], 21U * sizeof(real_T));
  if (rtIsInf(*fval) || rtIsNaN(*fval)) {
    if (rtIsNaN(*fval)) {
      *status = -3;
    } else if (*fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  } else {
    *status = Simulation_checkVectorNonFinite(21, grad_workspace_data, 1);
  }

  if (*status == 1) {
    if (obj_mCineq > 0) {
      Simulat_eML_blk_kernel_anonFcn2(obj_nonlcon_workspace_runtimeda,
        obj_nonlcon_workspace_runtime_0, obj_nonlcon_workspace_runtime_1,
        obj_nonlcon_workspace_runtime_2, obj_nonlcon_workspace_runtime_3, x,
        Simulation_B.a__3_data, Simulation_B.a__3_size, Simulation_B.Gfxu,
        Simulation_B.a__4_data, Simulation_B.a__4_size,
        Simulation_B.JacEqTrans_tmp);
      Simulation_B.e_k = 0;
      while (Simulation_B.e_k <= obj_mCineq - 1) {
        Cineq_workspace_data[(ineq0 + Simulation_B.e_k) - 1] =
          Simulation_B.a__3_data[Simulation_B.e_k];
        Simulation_B.e_k++;
      }

      memcpy(&Ceq_workspace[0], &Simulation_B.Gfxu[0], sizeof(real_T) << 4U);
      Simulation_B.e_k = 0;
      while (Simulation_B.e_k <= Simulation_B.a__4_size[0] - 1) {
        Simulation_B.Gfxu_tmp = 0;
        while (Simulation_B.Gfxu_tmp <= Simulation_B.a__4_size[1] - 1) {
          JacIneqTrans_workspace_data[Simulation_B.e_k + ldJI * ((iJI_col +
            Simulation_B.Gfxu_tmp) - 1)] =
            Simulation_B.a__4_data[Simulation_B.a__4_size[0] *
            Simulation_B.Gfxu_tmp + Simulation_B.e_k];
          Simulation_B.Gfxu_tmp++;
        }

        Simulation_B.e_k++;
      }

      for (Simulation_B.e_k = 0; Simulation_B.e_k < 21; Simulation_B.e_k++) {
        for (Simulation_B.Gfxu_tmp = 0; Simulation_B.Gfxu_tmp < 16;
             Simulation_B.Gfxu_tmp++) {
          JacEqTrans_workspace_data[Simulation_B.e_k + ldJE *
            Simulation_B.Gfxu_tmp] = Simulation_B.JacEqTrans_tmp[21 *
            Simulation_B.Gfxu_tmp + Simulation_B.e_k];
        }
      }
    } else {
      Simulat_eML_blk_kernel_anonFcn2(obj_nonlcon_workspace_runtimeda,
        obj_nonlcon_workspace_runtime_0, obj_nonlcon_workspace_runtime_1,
        obj_nonlcon_workspace_runtime_2, obj_nonlcon_workspace_runtime_3, x,
        Simulation_B.a__3_data, Simulation_B.a__3_size, Simulation_B.Gfxu,
        Simulation_B.a__4_data, Simulation_B.a__4_size,
        Simulation_B.JacEqTrans_tmp);
      memcpy(&Ceq_workspace[0], &Simulation_B.Gfxu[0], sizeof(real_T) << 4U);
      for (Simulation_B.e_k = 0; Simulation_B.e_k < 21; Simulation_B.e_k++) {
        for (Simulation_B.Gfxu_tmp = 0; Simulation_B.Gfxu_tmp < 16;
             Simulation_B.Gfxu_tmp++) {
          JacEqTrans_workspace_data[Simulation_B.e_k + ldJE *
            Simulation_B.Gfxu_tmp] = Simulation_B.JacEqTrans_tmp[21 *
            Simulation_B.Gfxu_tmp + Simulation_B.e_k];
        }
      }
    }

    *status = Simulation_checkVectorNonFinite(obj_mCineq, Cineq_workspace_data,
      ineq0);
    if (*status == 1) {
      *status = Simulati_checkVectorNonFinite_c(Ceq_workspace);
      if (*status == 1) {
        *status = Simulation_checkMatrixNonFinite(obj_mCineq,
          JacIneqTrans_workspace_data, iJI_col, ldJI);
        if (*status == 1) {
          *status = Simulation_checkMatrixNonFinite(16,
            JacEqTrans_workspace_data, 1, ldJE);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simula_updateWorkingSetForNewQP(const real_T xk[21],
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet, int32_T mIneq, const real_T
  cIneq_data[], const real_T cEq[16], int32_T mLB, const real_T lb[21], int32_T
  mUB, const real_T ub[21], int32_T mFixed)
{
  int32_T b_idx;
  int32_T iEq0;
  int32_T iw0;
  iw0 = WorkingSet->ldA * mFixed;
  iEq0 = 0;
  for (b_idx = 0; b_idx < 16; b_idx++) {
    WorkingSet->beq[b_idx] = -cEq[b_idx];
    WorkingSet->bwset.data[mFixed + b_idx] = WorkingSet->beq[b_idx];
    memcpy(&WorkingSet->ATwset.data[iw0], &WorkingSet->Aeq.data[iEq0], 21U *
           sizeof(real_T));
    iw0 += WorkingSet->ldA;
    iEq0 += WorkingSet->ldA;
  }

  for (b_idx = 0; b_idx < mIneq; b_idx++) {
    WorkingSet->bineq.data[b_idx] = -cIneq_data[b_idx];
  }

  for (b_idx = 0; b_idx < mLB; b_idx++) {
    WorkingSet->lb.data[WorkingSet->indexLB.data[b_idx] - 1] = -lb
      [WorkingSet->indexLB.data[b_idx] - 1] + xk[WorkingSet->indexLB.data[b_idx]
      - 1];
  }

  for (b_idx = 0; b_idx < mUB; b_idx++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[b_idx] - 1] = ub
      [WorkingSet->indexUB.data[b_idx] - 1] - xk[WorkingSet->indexUB.data[b_idx]
      - 1];
  }

  for (b_idx = 0; b_idx < mFixed; b_idx++) {
    WorkingSet->ub.data[WorkingSet->indexFixed.data[b_idx] - 1] = ub
      [WorkingSet->indexFixed.data[b_idx] - 1] - xk[WorkingSet->
      indexFixed.data[b_idx] - 1];
    WorkingSet->bwset.data[b_idx] = ub[WorkingSet->indexFixed.data[b_idx] - 1] -
      xk[WorkingSet->indexFixed.data[b_idx] - 1];
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulat_modifyOverheadPhaseOne_(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj)
{
  int32_T idx;
  for (idx = 0; idx < obj->sizes[0]; idx++) {
    obj->ATwset.data[(obj->nVar + obj->ldA * idx) - 1] = 0.0;
  }

  for (idx = 0; idx < 16; idx++) {
    int32_T idxEq;
    idxEq = (obj->ldA * idx + obj->nVar) - 1;
    obj->Aeq.data[idxEq] = 0.0;
    obj->ATwset.data[idxEq + obj->ldA * (obj->isActiveIdx[1] - 1)] = 0.0;
  }

  for (idx = 0; idx < obj->sizes[2]; idx++) {
    obj->Aineq.data[(obj->nVar + obj->ldA * idx) - 1] = -1.0;
  }

  obj->indexLB.data[obj->sizes[3] - 1] = obj->nVar;
  obj->lb.data[obj->nVar - 1] = 1.0E-5;
  for (idx = obj->isActiveIdx[2]; idx <= obj->nActiveConstr; idx++) {
    obj->ATwset.data[(obj->nVar + obj->ldA * (idx - 1)) - 1] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    for (idx = 0; idx <= obj->sizesNormal[4]; idx++) {
      obj->isActiveConstr.data[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr.data[obj->isActiveIdx[4] - 2] = false;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_setProblemType(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
   case 3:
    {
      int32_T d_idx_row;
      obj->nVar = 21;
      obj->mConstr = obj->mConstrOrig;
      if (obj->nWConstr[4] > 0) {
        for (int32_T mIneq = -1; mIneq < obj->sizesNormal[4] - 1; mIneq++) {
          obj->isActiveConstr.data[obj->isActiveIdxNormal[4] + mIneq] =
            obj->isActiveConstr.data[obj->isActiveIdx[4] + mIneq];
        }
      }

      for (d_idx_row = 0; d_idx_row < 5; d_idx_row++) {
        obj->sizes[d_idx_row] = obj->sizesNormal[d_idx_row];
      }

      for (d_idx_row = 0; d_idx_row < 6; d_idx_row++) {
        obj->isActiveIdx[d_idx_row] = obj->isActiveIdxNormal[d_idx_row];
      }
    }
    break;

   case 1:
    {
      int32_T d_idx_row;
      obj->nVar = 22;
      obj->mConstr = obj->mConstrOrig + 1;
      for (d_idx_row = 0; d_idx_row < 5; d_idx_row++) {
        obj->sizes[d_idx_row] = obj->sizesPhaseOne[d_idx_row];
      }

      for (d_idx_row = 0; d_idx_row < 6; d_idx_row++) {
        obj->isActiveIdx[d_idx_row] = obj->isActiveIdxPhaseOne[d_idx_row];
      }

      Simulat_modifyOverheadPhaseOne_(obj);
    }
    break;

   case 2:
    {
      int32_T d_idx_row;
      obj->nVar = obj->nVarMax - 1;
      obj->mConstr = obj->mConstrMax - 1;
      for (d_idx_row = 0; d_idx_row < 5; d_idx_row++) {
        obj->sizes[d_idx_row] = obj->sizesRegularized[d_idx_row];
      }

      if (obj->probType != 4) {
        int32_T colOffsetATw;
        int32_T colOffsetAeq;
        int32_T colOffsetAineq;
        int32_T mIneq;
        mIneq = obj->sizes[2] + 22;
        for (colOffsetAineq = 0; colOffsetAineq < obj->sizes[0]; colOffsetAineq
             ++) {
          colOffsetATw = obj->ldA * colOffsetAineq;
          for (colOffsetAeq = 22; colOffsetAeq <= obj->nVar; colOffsetAeq++) {
            obj->ATwset.data[(colOffsetAeq + colOffsetATw) - 1] = 0.0;
          }
        }

        for (colOffsetATw = 0; colOffsetATw <= mIneq - 23; colOffsetATw++) {
          colOffsetAineq = obj->ldA * colOffsetATw - 1;
          for (colOffsetAeq = 22; colOffsetAeq <= colOffsetATw + 21;
               colOffsetAeq++) {
            obj->Aineq.data[colOffsetAeq + colOffsetAineq] = 0.0;
          }

          obj->Aineq.data[(colOffsetATw + colOffsetAineq) + 22] = -1.0;
          for (colOffsetAeq = colOffsetATw + 23; colOffsetAeq <= obj->nVar;
               colOffsetAeq++) {
            obj->Aineq.data[colOffsetAeq + colOffsetAineq] = 0.0;
          }
        }

        for (colOffsetAineq = 0; colOffsetAineq < 16; colOffsetAineq++) {
          int32_T b_tmp;
          int32_T c;
          int32_T f_idx_row;
          colOffsetAeq = obj->ldA * colOffsetAineq - 1;
          colOffsetATw = (obj->isActiveIdx[1] - 1) * obj->ldA + colOffsetAeq;
          for (d_idx_row = 22; d_idx_row < mIneq; d_idx_row++) {
            obj->Aeq.data[d_idx_row + colOffsetAeq] = 0.0;
            obj->ATwset.data[d_idx_row + colOffsetATw] = 0.0;
          }

          d_idx_row = mIneq;
          b_tmp = mIneq + colOffsetAineq;
          while (d_idx_row <= b_tmp - 1) {
            obj->Aeq.data[d_idx_row + colOffsetAeq] = 0.0;
            obj->ATwset.data[d_idx_row + colOffsetATw] = 0.0;
            d_idx_row++;
          }

          d_idx_row = b_tmp + colOffsetAeq;
          obj->Aeq.data[d_idx_row] = -1.0;
          obj->ATwset.data[b_tmp + colOffsetATw] = -1.0;
          for (f_idx_row = b_tmp + 1; f_idx_row <= mIneq + 15; f_idx_row++) {
            obj->Aeq.data[f_idx_row + colOffsetAeq] = 0.0;
            obj->ATwset.data[f_idx_row + colOffsetATw] = 0.0;
          }

          f_idx_row = mIneq + 16;
          c = mIneq + colOffsetAineq;
          while (f_idx_row <= c + 15) {
            obj->Aeq.data[f_idx_row + colOffsetAeq] = 0.0;
            obj->ATwset.data[f_idx_row + colOffsetATw] = 0.0;
            f_idx_row++;
          }

          obj->Aeq.data[d_idx_row + 16] = 1.0;
          obj->ATwset.data[(b_tmp + colOffsetATw) + 16] = 1.0;
          for (d_idx_row = b_tmp + 17; d_idx_row <= obj->nVar; d_idx_row++) {
            obj->Aeq.data[d_idx_row + colOffsetAeq] = 0.0;
            obj->ATwset.data[d_idx_row + colOffsetATw] = 0.0;
          }
        }

        colOffsetATw = 21;
        for (colOffsetAineq = obj->sizesNormal[3]; colOffsetAineq <
             obj->sizesRegularized[3]; colOffsetAineq++) {
          colOffsetATw++;
          obj->indexLB.data[colOffsetAineq] = colOffsetATw;
        }

        if (obj->nWConstr[4] > 0) {
          for (colOffsetATw = -1; colOffsetATw < obj->sizesRegularized[4] - 1;
               colOffsetATw++) {
            obj->isActiveConstr.data[(obj->isActiveIdxRegularized[4] +
              colOffsetATw) + 1] = obj->isActiveConstr.data[obj->isActiveIdx[4]
              + colOffsetATw];
          }
        }

        for (colOffsetATw = obj->isActiveIdx[4]; colOffsetATw <
             obj->isActiveIdxRegularized[4]; colOffsetATw++) {
          obj->isActiveConstr.data[colOffsetATw - 1] = false;
        }

        for (colOffsetATw = 22; colOffsetATw <= mIneq + 31; colOffsetATw++) {
          obj->lb.data[colOffsetATw - 1] = 0.0;
        }

        for (mIneq = obj->isActiveIdx[2] - 1; mIneq < obj->nActiveConstr; mIneq
             ++) {
          colOffsetATw = obj->ldA * mIneq - 1;
          if (obj->Wid.data[mIneq] == 3) {
            for (colOffsetAineq = 22; colOffsetAineq <= obj->
                 Wlocalidx.data[mIneq] + 20; colOffsetAineq++) {
              obj->ATwset.data[colOffsetAineq + colOffsetATw] = 0.0;
            }

            obj->ATwset.data[(obj->Wlocalidx.data[mIneq] + colOffsetATw) + 21] =
              -1.0;
            for (colOffsetAineq = obj->Wlocalidx.data[mIneq] + 22;
                 colOffsetAineq <= obj->nVar; colOffsetAineq++) {
              obj->ATwset.data[colOffsetAineq + colOffsetATw] = 0.0;
            }
          } else {
            for (colOffsetAineq = 22; colOffsetAineq <= obj->nVar;
                 colOffsetAineq++) {
              obj->ATwset.data[colOffsetAineq + colOffsetATw] = 0.0;
            }
          }
        }
      }

      for (d_idx_row = 0; d_idx_row < 6; d_idx_row++) {
        obj->isActiveIdx[d_idx_row] = obj->isActiveIdxRegularized[d_idx_row];
      }
    }
    break;

   default:
    {
      int32_T d_idx_row;
      obj->nVar = obj->nVarMax;
      obj->mConstr = obj->mConstrMax;
      for (d_idx_row = 0; d_idx_row < 5; d_idx_row++) {
        obj->sizes[d_idx_row] = obj->sizesRegPhaseOne[d_idx_row];
      }

      for (d_idx_row = 0; d_idx_row < 6; d_idx_row++) {
        obj->isActiveIdx[d_idx_row] = obj->isActiveIdxRegPhaseOne[d_idx_row];
      }

      Simulat_modifyOverheadPhaseOne_(obj);
    }
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_initActiveSet(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj)
{
  int32_T b_idx_local;
  int32_T iAeq0;
  int32_T idx_global;
  Simulation_setProblemType(obj, 3);
  Simulation_B.nWFixed = obj->isActiveIdx[2];
  while (Simulation_B.nWFixed <= obj->mConstrMax) {
    obj->isActiveConstr.data[Simulation_B.nWFixed - 1] = false;
    Simulation_B.nWFixed++;
  }

  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = 16;
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + 16;
  Simulation_B.nWFixed = obj->sizes[0];
  for (b_idx_local = 0; b_idx_local < Simulation_B.nWFixed; b_idx_local++) {
    obj->Wid.data[b_idx_local] = 1;
    obj->Wlocalidx.data[b_idx_local] = b_idx_local + 1;
    obj->isActiveConstr.data[b_idx_local] = true;
    idx_global = obj->ldA * b_idx_local - 1;
    for (iAeq0 = 0; iAeq0 <= obj->indexFixed.data[b_idx_local] - 2; iAeq0++) {
      obj->ATwset.data[(iAeq0 + idx_global) + 1] = 0.0;
    }

    obj->ATwset.data[obj->indexFixed.data[b_idx_local] + idx_global] = 1.0;
    for (iAeq0 = obj->indexFixed.data[b_idx_local] + 1; iAeq0 <= obj->nVar;
         iAeq0++) {
      obj->ATwset.data[iAeq0 + idx_global] = 0.0;
    }

    obj->bwset.data[b_idx_local] = obj->ub.data[obj->indexFixed.data[b_idx_local]
      - 1];
  }

  for (b_idx_local = 0; b_idx_local < 16; b_idx_local++) {
    int32_T iATw0;
    idx_global = Simulation_B.nWFixed + b_idx_local;
    obj->Wid.data[idx_global] = 2;
    obj->Wlocalidx.data[idx_global] = b_idx_local + 1;
    obj->isActiveConstr.data[idx_global] = true;
    iAeq0 = obj->ldA * b_idx_local;
    iATw0 = obj->ldA * idx_global;
    for (int32_T c_i = 0; c_i < obj->nVar; c_i++) {
      obj->ATwset.data[iATw0 + c_i] = obj->Aeq.data[iAeq0 + c_i];
    }

    obj->bwset.data[idx_global] = obj->beq[b_idx_local];
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_factoryConstruct_cy(int32_T maxRows, int32_T maxCols,
  int32_T *obj_ldq, int32_T obj_QR_size[2], real_T obj_Q_data[], int32_T
  obj_Q_size[2], int32_T obj_jpvt_data[], int32_T *obj_jpvt_size, int32_T
  *obj_mrows, int32_T *obj_ncols, int32_T *obj_tau_size, int32_T *obj_minRowCol,
  boolean_T *obj_usedPivoting)
{
  int32_T loop_ub;
  *obj_ldq = maxRows;
  obj_QR_size[0] = maxRows;
  obj_QR_size[1] = maxCols;
  obj_Q_size[0] = maxRows;
  obj_Q_size[1] = maxRows;
  loop_ub = maxRows * maxRows - 1;
  if (0 <= loop_ub) {
    memset(&obj_Q_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  *obj_jpvt_size = maxCols;
  if (0 <= maxCols - 1) {
    memset(&obj_jpvt_data[0], 0, maxCols * sizeof(int32_T));
  }

  *obj_mrows = 0;
  *obj_ncols = 0;
  if (maxRows <= maxCols) {
    *obj_tau_size = maxRows;
  } else {
    *obj_tau_size = maxCols;
  }

  *obj_minRowCol = 0;
  *obj_usedPivoting = false;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_factoryConstruct_cyd(int32_T MaxDims, int32_T
  obj_FMat_size[2], int32_T *obj_ldm, int32_T *obj_ndims, int32_T *obj_info,
  real_T *obj_scaleFactor, boolean_T *obj_ConvexCheck, real_T *obj_regTol_,
  real_T *obj_workspace_, real_T *obj_workspace2_)
{
  obj_FMat_size[0] = MaxDims;
  obj_FMat_size[1] = MaxDims;
  *obj_ldm = MaxDims;
  *obj_ndims = 0;
  *obj_info = 0;
  *obj_scaleFactor = 0.0;
  *obj_ConvexCheck = true;
  *obj_regTol_ = (rtInf);
  *obj_workspace_ = (rtInf);
  *obj_workspace2_ = (rtInf);
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T iac;
    int32_T ix;
    ix = ix0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = (iac + m) - 1;
      for (int32_T ia = iac; ia <= c; ia++) {
        y_data[iy] += A_data[ia - 1] * x_data[ix - 1];
        iy++;
      }

      ix++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_computeGradLag(real_T workspace_data[], int32_T ldA,
  int32_T nVar, const real_T grad_data[], int32_T mIneq, const real_T
  AineqTrans_data[], const real_T AeqTrans_data[], const int32_T
  finiteFixed_data[], int32_T mFixed, const int32_T finiteLB_data[], int32_T mLB,
  const int32_T finiteUB_data[], int32_T mUB, const real_T lambda_data[])
{
  int32_T c_idx;
  int32_T iL0;
  for (iL0 = 0; iL0 < nVar; iL0++) {
    workspace_data[iL0] = grad_data[iL0];
  }

  for (iL0 = 0; iL0 < mFixed; iL0++) {
    workspace_data[finiteFixed_data[iL0] - 1] += lambda_data[iL0];
  }

  Simulation_xgemv(nVar, 16, AeqTrans_data, ldA, lambda_data, mFixed + 1,
                   workspace_data);
  Simulation_xgemv(nVar, mIneq, AineqTrans_data, ldA, lambda_data, mFixed + 17,
                   workspace_data);
  iL0 = (mFixed + mIneq) + 16;
  for (c_idx = 0; c_idx < mLB; c_idx++) {
    workspace_data[finiteLB_data[c_idx] - 1] -= lambda_data[iL0];
    iL0++;
  }

  for (c_idx = 0; c_idx < mUB; c_idx++) {
    workspace_data[finiteUB_data[c_idx] - 1] += lambda_data[iL0];
    iL0++;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulati_computePrimalFeasError(const real_T x[21], int32_T
  mLinIneq, int32_T mNonlinIneq, const real_T cIneq_data[], const real_T cEq[16],
  const int32_T finiteLB_data[], int32_T mLB, const real_T lb[21], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[21])
{
  real_T feasError;
  real_T u1;
  int32_T idx;
  int32_T mIneq;
  feasError = 0.0;
  mIneq = mNonlinIneq + mLinIneq;
  for (idx = 0; idx < 16; idx++) {
    u1 = fabs(cEq[idx]);
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  for (idx = 0; idx < mIneq; idx++) {
    u1 = cIneq_data[idx];
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  for (mIneq = 0; mIneq < mLB; mIneq++) {
    u1 = lb[finiteLB_data[mIneq] - 1] - x[finiteLB_data[mIneq] - 1];
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  for (mIneq = 0; mIneq < mUB; mIneq++) {
    u1 = x[finiteUB_data[mIneq] - 1] - ub[finiteUB_data[mIneq] - 1];
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  return feasError;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_computeDualFeasError(int32_T nVar, const real_T
  gradLag_data[], boolean_T *gradOK, real_T *val)
{
  int32_T b_idx;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  b_idx = 0;
  exitg1 = false;
  while ((!exitg1) && (b_idx <= nVar - 1)) {
    *gradOK = ((!rtIsInf(gradLag_data[b_idx])) && (!rtIsNaN(gradLag_data[b_idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      real_T u1;
      u1 = fabs(gradLag_data[b_idx]);
      if ((!(*val >= u1)) && (!rtIsNaN(u1))) {
        *val = u1;
      }

      b_idx++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_saveJacobian(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *obj,
  int32_T nVar, int32_T mIneq, const real_T JacCineqTrans_data[], int32_T
  ineqCol0, const real_T JacCeqTrans_data[], int32_T ldJ)
{
  int32_T b;
  int32_T iCol;
  int32_T iCol_old;
  int32_T idx_col;
  iCol = (ineqCol0 - 1) * ldJ;
  iCol_old = -1;
  b = mIneq - ineqCol0;
  for (idx_col = 0; idx_col <= b; idx_col++) {
    int32_T loop_ub_tmp;
    int32_T y_size_idx_0;
    int32_T y_size_idx_1;
    y_size_idx_0 = obj->JacCineqTrans_old.size[0];
    y_size_idx_1 = obj->JacCineqTrans_old.size[1];
    loop_ub_tmp = obj->JacCineqTrans_old.size[0] * obj->JacCineqTrans_old.size[1];
    if (0 <= loop_ub_tmp - 1) {
      memcpy(&Simulation_B.y_data[0], &obj->JacCineqTrans_old.data[0],
             loop_ub_tmp * sizeof(real_T));
    }

    for (loop_ub_tmp = 1; loop_ub_tmp - 1 < nVar; loop_ub_tmp++) {
      Simulation_B.y_data[iCol_old + loop_ub_tmp] = JacCineqTrans_data[(iCol +
        loop_ub_tmp) - 1];
    }

    obj->JacCineqTrans_old.size[1] = y_size_idx_1;
    y_size_idx_0 *= y_size_idx_1;
    if (0 <= y_size_idx_0 - 1) {
      memcpy(&obj->JacCineqTrans_old.data[0], &Simulation_B.y_data[0],
             y_size_idx_0 * sizeof(real_T));
    }

    iCol += ldJ;
    iCol_old += ldJ;
  }

  iCol = -1;
  iCol_old = -1;
  for (b = 0; b < 16; b++) {
    for (idx_col = 1; idx_col - 1 < nVar; idx_col++) {
      obj->JacCeqTrans_old.data[iCol_old + idx_col] = JacCeqTrans_data[iCol +
        idx_col];
    }

    iCol += ldJ;
    iCol_old += ldJ;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_saveState(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *obj)
{
  int32_T k;
  int32_T y_size_idx_0;
  obj->sqpFval_old = obj->sqpFval;
  for (k = 0; k < 21; k++) {
    obj->xstarsqp_old[k] = obj->xstarsqp[k];
    obj->grad_old.data[k] = obj->grad.data[k];
  }

  y_size_idx_0 = obj->cIneq_old.size;
  if (0 <= obj->cIneq_old.size - 1) {
    memcpy(&Simulation_B.y_data_n[0], &obj->cIneq_old.data[0],
           obj->cIneq_old.size * sizeof(real_T));
  }

  for (k = 0; k < obj->mIneq; k++) {
    Simulation_B.y_data_n[k] = obj->cIneq.data[k];
  }

  if (0 <= y_size_idx_0 - 1) {
    memcpy(&obj->cIneq_old.data[0], &Simulation_B.y_data_n[0], y_size_idx_0 *
           sizeof(real_T));
  }

  memcpy(&obj->cEq_old[0], &obj->cEq[0], sizeof(real_T) << 4U);
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_computeComplError(const int32_T
  *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
  const real_T xCurrent[21], int32_T mIneq, const real_T cIneq_data[], const
  int32_T finiteLB_data[], int32_T mLB, const real_T lb[21], const int32_T
  finiteUB_data[], int32_T mUB, const real_T ub[21], const real_T lambda_data[],
  int32_T iL0)
{
  real_T nlpComplError;
  nlpComplError = 0.0;
  if ((mIneq + mLB) + mUB > 0) {
    real_T u0;
    real_T ubDelta;
    real_T ubLambda;
    int32_T c_idx;
    int32_T iLineq0;
    int32_T mLinIneq;
    for (iLineq0 = 0; iLineq0 < *fscales_lineq_constraint_size; iLineq0++) {
      u0 = fabs(cIneq_data[iLineq0]);
      ubDelta = lambda_data[(iL0 + iLineq0) - 1];
      if ((!(u0 <= ubDelta)) && (!rtIsNaN(ubDelta))) {
        u0 = ubDelta;
      }

      ubDelta = fabs(ubDelta * cIneq_data[iLineq0]);
      if ((ubDelta <= u0) || rtIsNaN(u0)) {
        u0 = ubDelta;
      }

      if ((!(nlpComplError >= u0)) && (!rtIsNaN(u0))) {
        nlpComplError = u0;
      }
    }

    iLineq0 = (iL0 + *fscales_lineq_constraint_size) - 2;
    for (c_idx = 1; c_idx - 1 < *fscales_cineq_constraint_size; c_idx++) {
      u0 = fabs(cIneq_data[(*fscales_lineq_constraint_size - 1) + c_idx]);
      ubDelta = lambda_data[iLineq0 + c_idx];
      if ((!(u0 <= ubDelta)) && (!rtIsNaN(ubDelta))) {
        u0 = ubDelta;
      }

      ubDelta = fabs(cIneq_data[(*fscales_lineq_constraint_size - 1) + c_idx] *
                     ubDelta);
      if ((ubDelta <= u0) || rtIsNaN(u0)) {
        u0 = ubDelta;
      }

      if ((!(nlpComplError >= u0)) && (!rtIsNaN(u0))) {
        nlpComplError = u0;
      }
    }

    iLineq0 = (iL0 + mIneq) - 1;
    mLinIneq = iLineq0 + mLB;
    for (c_idx = 0; c_idx < mLB; c_idx++) {
      ubDelta = xCurrent[finiteLB_data[c_idx] - 1] - lb[finiteLB_data[c_idx] - 1];
      ubLambda = lambda_data[iLineq0 + c_idx];
      u0 = fabs(ubDelta);
      if ((!(u0 <= ubLambda)) && (!rtIsNaN(ubLambda))) {
        u0 = ubLambda;
      }

      ubDelta = fabs(ubDelta * ubLambda);
      if ((ubDelta <= u0) || rtIsNaN(u0)) {
        u0 = ubDelta;
      }

      if ((!(nlpComplError >= u0)) && (!rtIsNaN(u0))) {
        nlpComplError = u0;
      }
    }

    for (iLineq0 = 0; iLineq0 < mUB; iLineq0++) {
      ubDelta = ub[finiteUB_data[iLineq0] - 1] - xCurrent[finiteUB_data[iLineq0]
        - 1];
      ubLambda = lambda_data[mLinIneq + iLineq0];
      u0 = fabs(ubDelta);
      if ((!(u0 <= ubLambda)) && (!rtIsNaN(ubLambda))) {
        u0 = ubLambda;
      }

      ubDelta = fabs(ubDelta * ubLambda);
      if ((ubDelta <= u0) || rtIsNaN(u0)) {
        u0 = ubDelta;
      }

      if ((!(nlpComplError >= u0)) && (!rtIsNaN(u0))) {
        nlpComplError = u0;
      }
    }
  }

  return nlpComplError;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_l(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T iac;
    int32_T ix;
    ix = ix0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = (iac + m) - 1;
      for (int32_T ia = iac; ia <= c; ia++) {
        y_data[iy] += A_data[ia - 1] * x_data[ix - 1];
        iy++;
      }

      ix++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_computeGradLag_p(real_T workspace_data[], int32_T ldA,
  int32_T nVar, const real_T grad_data[], int32_T mIneq, const real_T
  AineqTrans_data[], const real_T AeqTrans_data[], const int32_T
  finiteFixed_data[], int32_T mFixed, const int32_T finiteLB_data[], int32_T mLB,
  const int32_T finiteUB_data[], int32_T mUB, const real_T lambda_data[])
{
  int32_T c_idx;
  int32_T iL0;
  for (iL0 = 0; iL0 < nVar; iL0++) {
    workspace_data[iL0] = grad_data[iL0];
  }

  for (iL0 = 0; iL0 < mFixed; iL0++) {
    workspace_data[finiteFixed_data[iL0] - 1] += lambda_data[iL0];
  }

  Simulation_xgemv_l(nVar, 16, AeqTrans_data, ldA, lambda_data, mFixed + 1,
                     workspace_data);
  Simulation_xgemv_l(nVar, mIneq, AineqTrans_data, ldA, lambda_data, mFixed + 17,
                     workspace_data);
  iL0 = (mFixed + mIneq) + 16;
  for (c_idx = 0; c_idx < mLB; c_idx++) {
    workspace_data[finiteLB_data[c_idx] - 1] -= lambda_data[iL0];
    iL0++;
  }

  for (c_idx = 0; c_idx < mUB; c_idx++) {
    workspace_data[finiteUB_data[c_idx] - 1] += lambda_data[iL0];
    iL0++;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulati_computeDualFeasError_l(int32_T nVar, const real_T
  gradLag_data[], boolean_T *gradOK, real_T *val)
{
  int32_T b_idx;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  b_idx = 0;
  exitg1 = false;
  while ((!exitg1) && (b_idx <= nVar - 1)) {
    *gradOK = ((!rtIsInf(gradLag_data[b_idx])) && (!rtIsNaN(gradLag_data[b_idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      real_T u1;
      u1 = fabs(gradLag_data[b_idx]);
      if ((!(*val >= u1)) && (!rtIsNaN(u1))) {
        *val = u1;
      }

      b_idx++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simu_updateWorkingSetForNewQP_m(const real_T xk[21],
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet, int32_T mIneq, int32_T
  mNonlinIneq, const real_T cIneq_data[], const real_T cEq[16], int32_T mLB,
  const real_T lb[21], int32_T mUB, const real_T ub[21], int32_T mFixed)
{
  int32_T b_idx;
  int32_T i;
  int32_T iEq0;
  int32_T iw0;
  int32_T nVar;
  nVar = WorkingSet->nVar - 1;
  iw0 = WorkingSet->ldA * mFixed;
  iEq0 = 0;
  for (b_idx = 0; b_idx < 16; b_idx++) {
    WorkingSet->beq[b_idx] = -cEq[b_idx];
    WorkingSet->bwset.data[mFixed + b_idx] = WorkingSet->beq[b_idx];
    for (i = 0; i <= nVar; i++) {
      WorkingSet->ATwset.data[iw0 + i] = WorkingSet->Aeq.data[iEq0 + i];
    }

    iw0 += WorkingSet->ldA;
    iEq0 += WorkingSet->ldA;
  }

  for (b_idx = 0; b_idx < mIneq; b_idx++) {
    WorkingSet->bineq.data[b_idx] = -cIneq_data[b_idx];
  }

  for (b_idx = 0; b_idx < mLB; b_idx++) {
    WorkingSet->lb.data[WorkingSet->indexLB.data[b_idx] - 1] = -lb
      [WorkingSet->indexLB.data[b_idx] - 1] + xk[WorkingSet->indexLB.data[b_idx]
      - 1];
  }

  for (b_idx = 0; b_idx < mUB; b_idx++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[b_idx] - 1] = ub
      [WorkingSet->indexUB.data[b_idx] - 1] - xk[WorkingSet->indexUB.data[b_idx]
      - 1];
  }

  for (b_idx = 0; b_idx < mFixed; b_idx++) {
    WorkingSet->ub.data[WorkingSet->indexFixed.data[b_idx] - 1] = ub
      [WorkingSet->indexFixed.data[b_idx] - 1] - xk[WorkingSet->
      indexFixed.data[b_idx] - 1];
    WorkingSet->bwset.data[b_idx] = ub[WorkingSet->indexFixed.data[b_idx] - 1] -
      xk[WorkingSet->indexFixed.data[b_idx] - 1];
  }

  if (WorkingSet->nActiveConstr > mFixed + 16) {
    for (b_idx = mFixed + 16; b_idx < WorkingSet->nActiveConstr; b_idx++) {
      switch (WorkingSet->Wid.data[b_idx]) {
       case 4:
        WorkingSet->bwset.data[b_idx] = WorkingSet->lb.data
          [WorkingSet->indexLB.data[WorkingSet->Wlocalidx.data[b_idx] - 1] - 1];
        break;

       case 5:
        WorkingSet->bwset.data[b_idx] = WorkingSet->ub.data
          [WorkingSet->indexUB.data[WorkingSet->Wlocalidx.data[b_idx] - 1] - 1];
        break;

       default:
        WorkingSet->bwset.data[b_idx] = WorkingSet->bineq.data
          [WorkingSet->Wlocalidx.data[b_idx] - 1];
        if ((mNonlinIneq > 0) && (WorkingSet->Wlocalidx.data[b_idx] >=
             mNonlinIneq)) {
          iw0 = WorkingSet->ldA * b_idx;
          iEq0 = (WorkingSet->Wlocalidx.data[b_idx] - 1) * WorkingSet->ldA;
          for (i = 1; i - 1 <= nVar; i++) {
            WorkingSet->ATwset.data[(iw0 + i) - 1] = WorkingSet->Aineq.data
              [(iEq0 + i) - 1];
          }
        }
        break;
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_xnrm2(int32_T n, const real_T x_data[], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x_data[ix0 - 1]);
    } else {
      int32_T kend;
      Simulation_B.scale_m = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        Simulation_B.absxk_m = fabs(x_data[k - 1]);
        if (Simulation_B.absxk_m > Simulation_B.scale_m) {
          Simulation_B.t_c = Simulation_B.scale_m / Simulation_B.absxk_m;
          y = y * Simulation_B.t_c * Simulation_B.t_c + 1.0;
          Simulation_B.scale_m = Simulation_B.absxk_m;
        } else {
          Simulation_B.t_c = Simulation_B.absxk_m / Simulation_B.scale_m;
          y += Simulation_B.t_c * Simulation_B.t_c;
        }
      }

      y = Simulation_B.scale_m * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_xzlarfg(int32_T n, real_T *alpha1, real_T x_data[],
  int32_T ix0)
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    Simulation_B.xnorm = Simulation_xnrm2(n - 1, x_data, ix0);
    if (Simulation_B.xnorm != 0.0) {
      Simulation_B.xnorm = rt_hypotd_snf(*alpha1, Simulation_B.xnorm);
      if (*alpha1 >= 0.0) {
        Simulation_B.xnorm = -Simulation_B.xnorm;
      }

      if (fabs(Simulation_B.xnorm) < 1.0020841800044864E-292) {
        int32_T b_k;
        int32_T c_k;
        int32_T knt;
        knt = -1;
        c_k = (ix0 + n) - 2;
        do {
          knt++;
          for (b_k = ix0; b_k <= c_k; b_k++) {
            x_data[b_k - 1] *= 9.9792015476736E+291;
          }

          Simulation_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(Simulation_B.xnorm) >= 1.0020841800044864E-292));

        Simulation_B.xnorm = rt_hypotd_snf(*alpha1, Simulation_xnrm2(n - 1,
          x_data, ix0));
        if (*alpha1 >= 0.0) {
          Simulation_B.xnorm = -Simulation_B.xnorm;
        }

        tau = (Simulation_B.xnorm - *alpha1) / Simulation_B.xnorm;
        Simulation_B.a = 1.0 / (*alpha1 - Simulation_B.xnorm);
        for (b_k = ix0; b_k <= c_k; b_k++) {
          x_data[b_k - 1] *= Simulation_B.a;
        }

        for (c_k = 0; c_k <= knt; c_k++) {
          Simulation_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = Simulation_B.xnorm;
      } else {
        int32_T knt;
        tau = (Simulation_B.xnorm - *alpha1) / Simulation_B.xnorm;
        Simulation_B.a = 1.0 / (*alpha1 - Simulation_B.xnorm);
        knt = (ix0 + n) - 2;
        for (int32_T c_k = ix0; c_k <= knt; c_k++) {
          x_data[c_k - 1] *= Simulation_B.a;
        }

        *alpha1 = Simulation_B.xnorm;
      }
    }
  }

  return tau;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la(int32_T m, int32_T n, const real_T A_data[],
  int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * lda + ia0;
    iac = ia0;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T d;
      int32_T ix;
      ix = ix0;
      Simulation_B.c_m = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        Simulation_B.c_m += A_data[ia - 1] * x_data[ix - 1];
        ix++;
      }

      y_data[b_iy] += Simulation_B.c_m;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y_data[], real_T A_data[], int32_T ia0, int32_T lda)
{
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    int32_T jy;
    jA = ia0 - 1;
    jy = 0;
    for (int32_T j = 0; j < n; j++) {
      if (y_data[jy] != 0.0) {
        int32_T b;
        int32_T ijA;
        int32_T ix;
        Simulation_B.temp_e = y_data[jy] * alpha1;
        ix = ix0;
        ijA = jA;
        b = m + jA;
        while (ijA + 1 <= b) {
          A_data[ijA] += A_data[ix - 1] * Simulation_B.temp_e;
          ix++;
          ijA++;
        }
      }

      jy++;
      jA += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C_data[], int32_T ic0, int32_T ldc, real_T work_data[])
{
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C_data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T coltop;
      int32_T exitg1;
      int32_T ia;
      coltop = (lastc - 1) * ldc + ic0;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + lastv) - 1) {
          if (C_data[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    Simulation_xgemv_la(lastv, lastc, C_data, ic0, ldc, C_data, iv0, work_data);
    Simulation_xgerc(lastv, lastc, -tau, iv0, work_data, C_data, ic0, ldc);
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_qrf(real_T A_data[], const int32_T A_size[2], int32_T m,
  int32_T n, int32_T nfxd, real_T tau_data[])
{
  int32_T ii;
  Simulation_B.lda = A_size[0];
  ii = A_size[1];
  if (0 <= ii - 1) {
    memset(&Simulation_B.work_data[0], 0, ii * sizeof(real_T));
  }

  for (int32_T i = 0; i < nfxd; i++) {
    int32_T mmi;
    ii = i * Simulation_B.lda + i;
    mmi = m - i;
    if (i + 1 < m) {
      Simulation_B.b_atmp = A_data[ii];
      tau_data[i] = Simulation_xzlarfg(mmi, &Simulation_B.b_atmp, A_data, ii + 2);
      A_data[ii] = Simulation_B.b_atmp;
    } else {
      tau_data[i] = 0.0;
    }

    if (i + 1 < n) {
      Simulation_B.b_atmp = A_data[ii];
      A_data[ii] = 1.0;
      Simulation_xzlarf(mmi, (n - i) - 1, ii + 1, tau_data[i], A_data, (ii +
        Simulation_B.lda) + 1, Simulation_B.lda, Simulation_B.work_data);
      A_data[ii] = Simulation_B.b_atmp;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xswap(int32_T n, real_T x_data[], int32_T ix0, int32_T
  iy0)
{
  int32_T ix;
  int32_T iy;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (int32_T k = 0; k < n; k++) {
    real_T temp;
    temp = x_data[ix];
    x_data[ix] = x_data[iy];
    x_data[iy] = temp;
    ix++;
    iy++;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_qrpf(real_T A_data[], const int32_T A_size[2], int32_T m,
  int32_T n, int32_T nfxd, real_T tau_data[], int32_T jpvt_data[])
{
  int32_T j;
  int32_T loop_ub;
  Simulation_B.ma_j = A_size[0];
  if (m <= n) {
    Simulation_B.minmn_k = m;
  } else {
    Simulation_B.minmn_k = n;
  }

  loop_ub = A_size[1];
  if (0 <= loop_ub - 1) {
    memset(&Simulation_B.work_data_f[0], 0, loop_ub * sizeof(real_T));
  }

  loop_ub = A_size[1];
  if (0 <= loop_ub - 1) {
    memset(&Simulation_B.vn1_data[0], 0, loop_ub * sizeof(real_T));
  }

  loop_ub = A_size[1];
  if (0 <= loop_ub - 1) {
    memset(&Simulation_B.vn2_data[0], 0, loop_ub * sizeof(real_T));
  }

  for (j = nfxd; j < n; j++) {
    Simulation_B.vn1_data[j] = Simulation_xnrm2(m - nfxd, A_data, (j *
      Simulation_B.ma_j + nfxd) + 1);
    Simulation_B.vn2_data[j] = Simulation_B.vn1_data[j];
  }

  for (j = nfxd; j < Simulation_B.minmn_k; j++) {
    int32_T ix;
    loop_ub = j + 1;
    Simulation_B.ii = j * Simulation_B.ma_j + j;
    Simulation_B.nmi = n - j;
    Simulation_B.mmi = m - j;
    if (Simulation_B.nmi < 1) {
      Simulation_B.pvt = -1;
    } else {
      Simulation_B.pvt = 0;
      if (Simulation_B.nmi > 1) {
        ix = j;
        Simulation_B.smax = fabs(Simulation_B.vn1_data[j]);
        for (int32_T k = 2; k <= Simulation_B.nmi; k++) {
          ix++;
          Simulation_B.s_p = fabs(Simulation_B.vn1_data[ix]);
          if (Simulation_B.s_p > Simulation_B.smax) {
            Simulation_B.pvt = k - 1;
            Simulation_B.smax = Simulation_B.s_p;
          }
        }
      }
    }

    Simulation_B.pvt += j;
    if (Simulation_B.pvt + 1 != j + 1) {
      Simulation_xswap(m, A_data, Simulation_B.pvt * Simulation_B.ma_j + 1, j *
                       Simulation_B.ma_j + 1);
      ix = jpvt_data[Simulation_B.pvt];
      jpvt_data[Simulation_B.pvt] = jpvt_data[j];
      jpvt_data[j] = ix;
      Simulation_B.vn1_data[Simulation_B.pvt] = Simulation_B.vn1_data[j];
      Simulation_B.vn2_data[Simulation_B.pvt] = Simulation_B.vn2_data[j];
    }

    if (j + 1 < m) {
      Simulation_B.smax = A_data[Simulation_B.ii];
      tau_data[j] = Simulation_xzlarfg(Simulation_B.mmi, &Simulation_B.smax,
        A_data, Simulation_B.ii + 2);
      A_data[Simulation_B.ii] = Simulation_B.smax;
    } else {
      tau_data[j] = 0.0;
    }

    if (j + 1 < n) {
      Simulation_B.smax = A_data[Simulation_B.ii];
      A_data[Simulation_B.ii] = 1.0;
      Simulation_xzlarf(Simulation_B.mmi, Simulation_B.nmi - 1, Simulation_B.ii
                        + 1, tau_data[j], A_data, (Simulation_B.ii +
        Simulation_B.ma_j) + 1, Simulation_B.ma_j, Simulation_B.work_data_f);
      A_data[Simulation_B.ii] = Simulation_B.smax;
    }

    while (loop_ub + 1 <= n) {
      Simulation_B.ii = loop_ub * Simulation_B.ma_j + j;
      if (Simulation_B.vn1_data[loop_ub] != 0.0) {
        Simulation_B.smax = fabs(A_data[Simulation_B.ii]) /
          Simulation_B.vn1_data[loop_ub];
        Simulation_B.smax = 1.0 - Simulation_B.smax * Simulation_B.smax;
        if (Simulation_B.smax < 0.0) {
          Simulation_B.smax = 0.0;
        }

        Simulation_B.s_p = Simulation_B.vn1_data[loop_ub] /
          Simulation_B.vn2_data[loop_ub];
        Simulation_B.s_p = Simulation_B.s_p * Simulation_B.s_p *
          Simulation_B.smax;
        if (Simulation_B.s_p <= 1.4901161193847656E-8) {
          if (j + 1 < m) {
            Simulation_B.vn1_data[loop_ub] = Simulation_xnrm2(Simulation_B.mmi -
              1, A_data, Simulation_B.ii + 2);
            Simulation_B.vn2_data[loop_ub] = Simulation_B.vn1_data[loop_ub];
          } else {
            Simulation_B.vn1_data[loop_ub] = 0.0;
            Simulation_B.vn2_data[loop_ub] = 0.0;
          }
        } else {
          Simulation_B.vn1_data[loop_ub] *= sqrt(Simulation_B.smax);
        }
      }

      loop_ub++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgeqp3(real_T A_data[], const int32_T A_size[2], int32_T
  m, int32_T n, int32_T jpvt_data[], real_T tau_data[], int32_T *tau_size)
{
  Simulation_B.ma = A_size[0];
  if (A_size[0] <= A_size[1]) {
    Simulation_B.minmana = A_size[0];
  } else {
    Simulation_B.minmana = A_size[1];
  }

  if (m <= n) {
    Simulation_B.minmn = m;
  } else {
    Simulation_B.minmn = n;
  }

  *tau_size = Simulation_B.minmana;
  if (0 <= Simulation_B.minmana - 1) {
    memset(&tau_data[0], 0, Simulation_B.minmana * sizeof(real_T));
  }

  if (Simulation_B.minmn < 1) {
    Simulation_B.ma = 0;
    while (Simulation_B.ma <= n - 1) {
      jpvt_data[Simulation_B.ma] = Simulation_B.ma + 1;
      Simulation_B.ma++;
    }
  } else {
    Simulation_B.nfxd = -1;
    Simulation_B.minmana = 0;
    while (Simulation_B.minmana <= n - 1) {
      if (jpvt_data[Simulation_B.minmana] != 0) {
        Simulation_B.nfxd++;
        if (Simulation_B.minmana + 1 != Simulation_B.nfxd + 1) {
          Simulation_xswap(m, A_data, Simulation_B.minmana * Simulation_B.ma + 1,
                           Simulation_B.nfxd * Simulation_B.ma + 1);
          jpvt_data[Simulation_B.minmana] = jpvt_data[Simulation_B.nfxd];
          jpvt_data[Simulation_B.nfxd] = Simulation_B.minmana + 1;
        } else {
          jpvt_data[Simulation_B.minmana] = Simulation_B.minmana + 1;
        }
      } else {
        jpvt_data[Simulation_B.minmana] = Simulation_B.minmana + 1;
      }

      Simulation_B.minmana++;
    }

    if (Simulation_B.nfxd + 1 <= Simulation_B.minmn) {
      Simulation_B.nfxd++;
    } else {
      Simulation_B.nfxd = Simulation_B.minmn;
    }

    Simulation_qrf(A_data, A_size, m, n, Simulation_B.nfxd, tau_data);
    if (Simulation_B.nfxd < Simulation_B.minmn) {
      Simulation_qrpf(A_data, A_size, m, n, Simulation_B.nfxd, tau_data,
                      jpvt_data);
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_computeQ_(s_ASr52t7t39LT7rtZ8hZCX_Simul_T *obj, int32_T
  nrows)
{
  int32_T itau;
  int32_T lastv;
  Simulation_B.idx_p = 0;
  while (Simulation_B.idx_p <= obj->minRowCol - 1) {
    Simulation_B.iQR0 = obj->ldq * Simulation_B.idx_p + Simulation_B.idx_p;
    itau = obj->mrows - Simulation_B.idx_p;
    Simulation_B.i_o = 1;
    while (Simulation_B.i_o - 1 <= itau - 2) {
      lastv = Simulation_B.iQR0 + Simulation_B.i_o;
      obj->Q.data[lastv] = obj->QR.data[lastv];
      Simulation_B.i_o++;
    }

    Simulation_B.idx_p++;
  }

  Simulation_B.idx_p = obj->mrows;
  Simulation_B.iQR0 = obj->ldq;
  if (nrows >= 1) {
    int32_T iaii;
    int32_T lastc;
    for (itau = obj->minRowCol; itau < nrows; itau++) {
      Simulation_B.i_o = itau * Simulation_B.iQR0;
      for (iaii = 0; iaii < Simulation_B.idx_p; iaii++) {
        obj->Q.data[Simulation_B.i_o + iaii] = 0.0;
      }

      obj->Q.data[Simulation_B.i_o + itau] = 1.0;
    }

    itau = obj->minRowCol - 1;
    lastc = static_cast<uint8_T>(obj->Q.size[1]);
    if (0 <= lastc - 1) {
      memset(&Simulation_B.work_data_g[0], 0, lastc * sizeof(real_T));
    }

    Simulation_B.i_o = obj->minRowCol;
    while (Simulation_B.i_o >= 1) {
      int32_T ic0;
      iaii = (Simulation_B.i_o - 1) * Simulation_B.iQR0 + Simulation_B.i_o;
      if (Simulation_B.i_o < nrows) {
        int32_T coltop;
        obj->Q.data[iaii - 1] = 1.0;
        coltop = (Simulation_B.idx_p - Simulation_B.i_o) - 1;
        ic0 = iaii + Simulation_B.iQR0;
        Simulation_B.A_size_i[0] = obj->Q.size[0];
        Simulation_B.A_size_i[1] = obj->Q.size[1];
        lastc = obj->Q.size[0] * obj->Q.size[1];
        if (0 <= lastc - 1) {
          memcpy(&Simulation_B.A_data[0], &obj->Q.data[0], lastc * sizeof(real_T));
        }

        if (obj->tau.data[itau] != 0.0) {
          boolean_T exitg2;
          lastv = coltop + 2;
          lastc = iaii + coltop;
          while ((lastv > 0) && (obj->Q.data[lastc] == 0.0)) {
            lastv--;
            lastc--;
          }

          lastc = nrows - Simulation_B.i_o;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int32_T A;
            int32_T exitg1;
            coltop = (lastc - 1) * Simulation_B.iQR0 + ic0;
            A = coltop;
            do {
              exitg1 = 0;
              if (A <= (coltop + lastv) - 1) {
                if (obj->Q.data[A - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  A++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = 0;
          lastc = 0;
        }

        if (lastv > 0) {
          Simulation_xgemv_la(lastv, lastc, obj->Q.data, ic0, Simulation_B.iQR0,
                              obj->Q.data, iaii, Simulation_B.work_data_g);
          Simulation_xgerc(lastv, lastc, -obj->tau.data[itau], iaii,
                           Simulation_B.work_data_g, Simulation_B.A_data, ic0,
                           Simulation_B.iQR0);
        }

        obj->Q.size[0] = Simulation_B.A_size_i[0];
        obj->Q.size[1] = Simulation_B.A_size_i[1];
        lastc = Simulation_B.A_size_i[0] * Simulation_B.A_size_i[1];
        if (0 <= lastc - 1) {
          memcpy(&obj->Q.data[0], &Simulation_B.A_data[0], lastc * sizeof(real_T));
        }
      }

      if (Simulation_B.i_o < Simulation_B.idx_p) {
        lastv = (iaii + Simulation_B.idx_p) - Simulation_B.i_o;
        for (ic0 = iaii; ic0 < lastv; ic0++) {
          obj->Q.data[ic0] *= -obj->tau.data[itau];
        }
      }

      obj->Q.data[iaii - 1] = 1.0 - obj->tau.data[itau];
      for (lastv = 0; lastv <= Simulation_B.i_o - 2; lastv++) {
        obj->Q.data[(iaii - lastv) - 2] = 0.0;
      }

      itau--;
      Simulation_B.i_o--;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], real_T y_data[])
{
  if (m != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = 0;
      c = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        c += A_data[ia - 1] * x_data[ix];
        ix++;
      }

      y_data[b_iy] += c;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xtrsv(int32_T n, const real_T A_data[], int32_T lda,
  real_T x_data[])
{
  if (n != 0) {
    for (int32_T j = n - 1; j + 1 > 0; j--) {
      int32_T jjA;
      jjA = j * lda + j;
      x_data[j] /= A_data[jjA];
      for (int32_T i = 1; i - 1 < j; i++) {
        int32_T ix;
        ix = j - i;
        x_data[ix] -= A_data[jjA - i] * x_data[j];
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_computeLambdaLSQ(int32_T nVar, int32_T mConstr,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager, const real_T ATwset_data[],
  int32_T ldA, const real_T grad_data[], real_T lambdaLSQ_data[], real_T
  workspace_data[])
{
  Simulation_B.minDim = 0;
  while (Simulation_B.minDim <= mConstr - 1) {
    lambdaLSQ_data[Simulation_B.minDim] = 0.0;
    Simulation_B.minDim++;
  }

  Simulation_B.minDim = 0;
  while (Simulation_B.minDim <= mConstr - 1) {
    Simulation_B.rankR = ldA * Simulation_B.minDim;
    Simulation_B.iQR_diag = QRManager->ldq * Simulation_B.minDim;
    Simulation_B.b_k_d = 1;
    while (Simulation_B.b_k_d - 1 <= nVar - 1) {
      QRManager->QR.data[(Simulation_B.iQR_diag + Simulation_B.b_k_d) - 1] =
        ATwset_data[(Simulation_B.rankR + Simulation_B.b_k_d) - 1];
      Simulation_B.b_k_d++;
    }

    Simulation_B.minDim++;
  }

  QRManager->usedPivoting = true;
  QRManager->mrows = nVar;
  QRManager->ncols = mConstr;
  if (nVar <= mConstr) {
    Simulation_B.minDim = nVar;
  } else {
    Simulation_B.minDim = mConstr;
  }

  QRManager->minRowCol = Simulation_B.minDim;
  Simulation_xgeqp3(QRManager->QR.data, QRManager->QR.size, nVar, mConstr,
                    QRManager->jpvt.data, QRManager->tau.data,
                    &QRManager->tau.size);
  Simulation_computeQ_(QRManager, QRManager->mrows);
  Simulation_xgemv_la4(nVar, nVar, QRManager->Q.data, QRManager->ldq, grad_data,
                       workspace_data);
  if (nVar >= mConstr) {
    Simulation_B.rankR = nVar;
  } else {
    Simulation_B.rankR = mConstr;
  }

  Simulation_B.tol_k = static_cast<real_T>(Simulation_B.rankR) *
    2.2204460492503131E-16;
  if (1.4901161193847656E-8 <= Simulation_B.tol_k) {
    Simulation_B.tol_k = 1.4901161193847656E-8;
  }

  Simulation_B.tol_k *= fabs(QRManager->QR.data[0]);
  Simulation_B.rankR = 0;
  Simulation_B.iQR_diag = 0;
  while ((Simulation_B.rankR < Simulation_B.minDim) && (fabs(QRManager->
           QR.data[Simulation_B.iQR_diag]) > Simulation_B.tol_k)) {
    Simulation_B.rankR++;
    Simulation_B.iQR_diag = (Simulation_B.iQR_diag + QRManager->ldq) + 1;
  }

  Simulation_xtrsv(Simulation_B.rankR, QRManager->QR.data, QRManager->ldq,
                   workspace_data);
  if (mConstr <= Simulation_B.minDim) {
    Simulation_B.minDim = mConstr;
  }

  Simulation_B.rankR = 0;
  while (Simulation_B.rankR <= Simulation_B.minDim - 1) {
    lambdaLSQ_data[QRManager->jpvt.data[Simulation_B.rankR] - 1] =
      workspace_data[Simulation_B.rankR];
    Simulation_B.rankR++;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_sortLambdaQP(real_T lambda_data[], int32_T
  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[], const int32_T
  WorkingSet_Wlocalidx_data[], real_T workspace_data[])
{
  if (WorkingSet_nActiveConstr != 0) {
    int32_T idx;
    int32_T idxOffset;
    int32_T mAll;
    mAll = (((WorkingSet_sizes[0] + WorkingSet_sizes[3]) + WorkingSet_sizes[4])
            + WorkingSet_sizes[2]) + 15;
    for (idx = 0; idx <= mAll; idx++) {
      workspace_data[idx] = lambda_data[idx];
    }

    for (idx = 0; idx <= mAll; idx++) {
      lambda_data[idx] = 0.0;
    }

    mAll = 0;
    idx = 0;
    while ((idx + 1 <= WorkingSet_nActiveConstr) && (WorkingSet_Wid_data[idx] <=
            2)) {
      if (WorkingSet_Wid_data[idx] == 1) {
        idxOffset = 1;
      } else {
        idxOffset = WorkingSet_isActiveIdx[1];
      }

      lambda_data[(idxOffset + WorkingSet_Wlocalidx_data[idx]) - 2] =
        workspace_data[mAll];
      mAll++;
      idx++;
    }

    while (idx + 1 <= WorkingSet_nActiveConstr) {
      switch (WorkingSet_Wid_data[idx]) {
       case 3:
        idxOffset = WorkingSet_isActiveIdx[2];
        break;

       case 4:
        idxOffset = WorkingSet_isActiveIdx[3];
        break;

       default:
        idxOffset = WorkingSet_isActiveIdx[4];
        break;
      }

      lambda_data[(idxOffset + WorkingSet_Wlocalidx_data[idx]) - 2] =
        workspace_data[mAll];
      mAll++;
      idx++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulation_ixamax(int32_T n, const real_T x_data[])
{
  int32_T idxmax;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      int32_T ix;
      ix = 0;
      smax = fabs(x_data[0]);
      for (int32_T k = 2; k <= n; k++) {
        real_T s;
        ix++;
        s = fabs(x_data[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_test_exit(s7RdrPWkr8UPAUyTdDJkLaG_Simul_T *Flags,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, sG8JZ69axY52WWR6RKyApQC_Simul_T
  *MeritFunction, const int32_T *fscales_lineq_constraint_size, const int32_T
  *fscales_cineq_constraint_size, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet,
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *QRManager, const real_T lb[21], const real_T ub[21])
{
  boolean_T dxTooSmall;
  boolean_T isFeasible;
  Simulation_B.nVar_d = WorkingSet->nVar;
  Simulation_B.mFixed_g = WorkingSet->sizes[0];
  Simulation_B.mIneq_c = WorkingSet->sizes[2];
  Simulation_B.mLB_c = WorkingSet->sizes[3];
  Simulation_B.mUB_i = WorkingSet->sizes[4];
  Simulation_B.mLambda = (((WorkingSet->sizes[0] + WorkingSet->sizes[2]) +
    WorkingSet->sizes[3]) + WorkingSet->sizes[4]) + 15;
  Simulation_B.nActiveConstr = 0;
  while (Simulation_B.nActiveConstr <= Simulation_B.mLambda) {
    TrialState->lambdaStopTest.data[Simulation_B.nActiveConstr] =
      TrialState->lambdasqp.data[Simulation_B.nActiveConstr];
    Simulation_B.nActiveConstr++;
  }

  Simulation_computeGradLag(TrialState->gradLag.data, WorkingSet->ldA,
    WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
    WorkingSet->Aineq.data, WorkingSet->Aeq.data, WorkingSet->indexFixed.data,
    WorkingSet->sizes[0], WorkingSet->indexLB.data, WorkingSet->sizes[3],
    WorkingSet->indexUB.data, WorkingSet->sizes[4],
    TrialState->lambdaStopTest.data);
  Simulation_B.optimRelativeFactor_h = fabs(TrialState->
    grad.data[Simulation_ixamax(WorkingSet->nVar, TrialState->grad.data) - 1]);
  if ((1.0 >= Simulation_B.optimRelativeFactor_h) || rtIsNaN
      (Simulation_B.optimRelativeFactor_h)) {
    Simulation_B.optimRelativeFactor_h = 1.0;
  }

  if (rtIsInf(Simulation_B.optimRelativeFactor_h)) {
    Simulation_B.optimRelativeFactor_h = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = Simulati_computePrimalFeasError
    (TrialState->xstarsqp, WorkingSet->sizes[2] - TrialState->mNonlinIneq,
     TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cEq,
     WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
     WorkingSet->indexUB.data, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    if ((1.0 >= MeritFunction->nlpPrimalFeasError) || rtIsNaN
        (MeritFunction->nlpPrimalFeasError)) {
      MeritFunction->feasRelativeFactor = 1.0;
    } else {
      MeritFunction->feasRelativeFactor = MeritFunction->nlpPrimalFeasError;
    }
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 0.01 *
                MeritFunction->feasRelativeFactor);
  Simulation_computeDualFeasError(WorkingSet->nVar, TrialState->gradLag.data,
    &Flags->gradOK, &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = Simulation_computeComplError
      (fscales_lineq_constraint_size, fscales_cineq_constraint_size,
       TrialState->xstarsqp, WorkingSet->sizes[2], TrialState->cIneq.data,
       WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
       WorkingSet->indexUB.data, WorkingSet->sizes[4], ub,
       TrialState->lambdaStopTest.data, WorkingSet->sizes[0] + 17);
    if ((MeritFunction->nlpDualFeasError >= MeritFunction->nlpComplError) ||
        rtIsNaN(MeritFunction->nlpComplError)) {
      MeritFunction->firstOrderOpt = MeritFunction->nlpDualFeasError;
    } else {
      MeritFunction->firstOrderOpt = MeritFunction->nlpComplError;
    }

    if (TrialState->sqpIterations > 1) {
      Simulation_computeGradLag_p(memspace->workspace_double.data,
        WorkingSet->ldA, WorkingSet->nVar, TrialState->grad.data,
        WorkingSet->sizes[2], WorkingSet->Aineq.data, WorkingSet->Aeq.data,
        WorkingSet->indexFixed.data, WorkingSet->sizes[0],
        WorkingSet->indexLB.data, WorkingSet->sizes[3], WorkingSet->indexUB.data,
        WorkingSet->sizes[4], TrialState->lambdaStopTestPrev.data);
      Simulati_computeDualFeasError_l(WorkingSet->nVar,
        memspace->workspace_double.data, &dxTooSmall,
        &Simulation_B.nlpDualFeasErrorTmp);
      Simulation_B.nlpComplErrorTmp = Simulation_computeComplError
        (fscales_lineq_constraint_size, fscales_cineq_constraint_size,
         TrialState->xstarsqp, WorkingSet->sizes[2], TrialState->cIneq.data,
         WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
         WorkingSet->indexUB.data, WorkingSet->sizes[4], ub,
         TrialState->lambdaStopTestPrev.data, WorkingSet->sizes[0] + 17);
      if ((Simulation_B.nlpDualFeasErrorTmp >= Simulation_B.nlpComplErrorTmp) ||
          rtIsNaN(Simulation_B.nlpComplErrorTmp)) {
        Simulation_B.d = Simulation_B.nlpDualFeasErrorTmp;
      } else {
        Simulation_B.d = Simulation_B.nlpComplErrorTmp;
      }

      if ((MeritFunction->nlpDualFeasError >= MeritFunction->nlpComplError) ||
          rtIsNaN(MeritFunction->nlpComplError)) {
        Simulation_B.MeritFunction_c = MeritFunction->nlpDualFeasError;
      } else {
        Simulation_B.MeritFunction_c = MeritFunction->nlpComplError;
      }

      if (Simulation_B.d < Simulation_B.MeritFunction_c) {
        MeritFunction->nlpDualFeasError = Simulation_B.nlpDualFeasErrorTmp;
        MeritFunction->nlpComplError = Simulation_B.nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = Simulation_B.d;
        Simulation_B.nActiveConstr = 0;
        while (Simulation_B.nActiveConstr <= Simulation_B.mLambda) {
          TrialState->lambdaStopTest.data[Simulation_B.nActiveConstr] =
            TrialState->lambdaStopTestPrev.data[Simulation_B.nActiveConstr];
          Simulation_B.nActiveConstr++;
        }
      } else {
        Simulation_B.nActiveConstr = 0;
        while (Simulation_B.nActiveConstr <= Simulation_B.mLambda) {
          TrialState->lambdaStopTestPrev.data[Simulation_B.nActiveConstr] =
            TrialState->lambdaStopTest.data[Simulation_B.nActiveConstr];
          Simulation_B.nActiveConstr++;
        }
      }
    } else {
      Simulation_B.nActiveConstr = 0;
      while (Simulation_B.nActiveConstr <= Simulation_B.mLambda) {
        TrialState->lambdaStopTestPrev.data[Simulation_B.nActiveConstr] =
          TrialState->lambdaStopTest.data[Simulation_B.nActiveConstr];
        Simulation_B.nActiveConstr++;
      }
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       Simulation_B.optimRelativeFactor_h) &&
        (MeritFunction->nlpComplError <= 1.0E-6 *
         Simulation_B.optimRelativeFactor_h)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        boolean_T guard1 = false;
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          boolean_T exitg1;
          dxTooSmall = true;
          Simulation_B.nActiveConstr = 0;
          exitg1 = false;
          while ((!exitg1) && (Simulation_B.nActiveConstr <= Simulation_B.nVar_d
                               - 1)) {
            Simulation_B.nlpDualFeasErrorTmp = fabs(TrialState->
              xstarsqp[Simulation_B.nActiveConstr]);
            if ((1.0 >= Simulation_B.nlpDualFeasErrorTmp) || rtIsNaN
                (Simulation_B.nlpDualFeasErrorTmp)) {
              Simulation_B.nlpDualFeasErrorTmp = 1.0;
            }

            if (1.0E-6 * Simulation_B.nlpDualFeasErrorTmp <= fabs
                (TrialState->delta_x.data[Simulation_B.nActiveConstr])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              Simulation_B.nActiveConstr++;
            }
          }

          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType != 2) {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              }
            } else {
              Simulation_B.nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr > 0) {
                Simu_updateWorkingSetForNewQP_m(TrialState->xstarsqp, WorkingSet,
                  WorkingSet->sizes[2], TrialState->mNonlinIneq,
                  TrialState->cIneq.data, TrialState->cEq, WorkingSet->sizes[3],
                  lb, WorkingSet->sizes[4], ub, WorkingSet->sizes[0]);
                Simulation_computeLambdaLSQ(Simulation_B.nVar_d,
                  Simulation_B.nActiveConstr, QRManager, WorkingSet->ATwset.data,
                  WorkingSet->ldA, TrialState->grad.data,
                  TrialState->lambda.data, memspace->workspace_double.data);
                Simulation_B.nActiveConstr = Simulation_B.mFixed_g;
                while (Simulation_B.nActiveConstr + 1 <= Simulation_B.mFixed_g +
                       16) {
                  TrialState->lambda.data[Simulation_B.nActiveConstr] =
                    -TrialState->lambda.data[Simulation_B.nActiveConstr];
                  Simulation_B.nActiveConstr++;
                }

                Simulation_sortLambdaQP(TrialState->lambda.data,
                  WorkingSet->nActiveConstr, WorkingSet->sizes,
                  WorkingSet->isActiveIdx, WorkingSet->Wid.data,
                  WorkingSet->Wlocalidx.data, memspace->workspace_double.data);
                Simulation_computeGradLag_p(memspace->workspace_double.data,
                  WorkingSet->ldA, Simulation_B.nVar_d, TrialState->grad.data,
                  Simulation_B.mIneq_c, WorkingSet->Aineq.data,
                  WorkingSet->Aeq.data, WorkingSet->indexFixed.data,
                  Simulation_B.mFixed_g, WorkingSet->indexLB.data,
                  Simulation_B.mLB_c, WorkingSet->indexUB.data,
                  Simulation_B.mUB_i, TrialState->lambda.data);
                Simulati_computeDualFeasError_l(Simulation_B.nVar_d,
                  memspace->workspace_double.data, &isFeasible,
                  &Simulation_B.nlpDualFeasErrorTmp);
                Simulation_B.nlpComplErrorTmp = Simulation_computeComplError
                  (fscales_lineq_constraint_size, fscales_cineq_constraint_size,
                   TrialState->xstarsqp, Simulation_B.mIneq_c,
                   TrialState->cIneq.data, WorkingSet->indexLB.data,
                   Simulation_B.mLB_c, lb, WorkingSet->indexUB.data,
                   Simulation_B.mUB_i, ub, TrialState->lambda.data,
                   Simulation_B.mFixed_g + 1);
                if ((Simulation_B.nlpDualFeasErrorTmp <= 1.0E-6 *
                     Simulation_B.optimRelativeFactor_h) &&
                    (Simulation_B.nlpComplErrorTmp <= 1.0E-6 *
                     Simulation_B.optimRelativeFactor_h)) {
                  MeritFunction->nlpDualFeasError =
                    Simulation_B.nlpDualFeasErrorTmp;
                  MeritFunction->nlpComplError = Simulation_B.nlpComplErrorTmp;
                  if (Simulation_B.nlpDualFeasErrorTmp >=
                      Simulation_B.nlpComplErrorTmp) {
                    MeritFunction->firstOrderOpt =
                      Simulation_B.nlpDualFeasErrorTmp;
                  } else {
                    MeritFunction->firstOrderOpt = Simulation_B.nlpComplErrorTmp;
                  }

                  Simulation_B.nVar_d = 0;
                  while (Simulation_B.nVar_d <= Simulation_B.mLambda) {
                    TrialState->lambdaStopTest.data[Simulation_B.nVar_d] =
                      TrialState->lambda.data[Simulation_B.nVar_d];
                    Simulation_B.nVar_d++;
                  }

                  Flags->done = true;
                  TrialState->sqpExitFlag = 1;
                } else {
                  Flags->done = true;
                  TrialState->sqpExitFlag = 2;
                }
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          if (TrialState->sqpIterations >= 300) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else if (TrialState->FunctionEvaluations >= 2100) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4rhx2l0j(int32_T m, int32_T n, const real_T
  A_data[], int32_T ia0, int32_T lda, const real_T x_data[], int32_T ix0, real_T
  y_data[])
{
  int32_T b;
  int32_T iac;
  int32_T ix;
  ix = ix0;
  b = (n - 1) * lda + ia0;
  iac = ia0;
  while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
    int32_T c;
    int32_T iy;
    iy = 0;
    c = (iac + m) - 1;
    for (int32_T ia = iac; ia <= c; ia++) {
      y_data[iy] += A_data[ia - 1] * x_data[ix - 1];
      iy++;
    }

    ix++;
    iac += lda;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static boolean_T Simulation_BFGSUpdate(int32_T nvar, real_T Bk[441], const
  real_T sk_data[], real_T yk_data[], real_T workspace_data[])
{
  real_T curvatureS;
  real_T dotSY;
  int32_T b_ix;
  int32_T d;
  int32_T iac;
  int32_T ijA;
  int32_T ix;
  int32_T jy;
  boolean_T success;
  dotSY = 0.0;
  if (nvar >= 1) {
    for (ix = 0; ix < nvar; ix++) {
      dotSY += sk_data[ix] * yk_data[ix];
    }
  }

  for (ix = 0; ix < nvar; ix++) {
    workspace_data[ix] = 0.0;
  }

  ix = 0;
  jy = (nvar - 1) * 21 + 1;
  for (iac = 1; iac <= jy; iac += 21) {
    b_ix = 0;
    ijA = (iac + nvar) - 1;
    for (d = iac; d <= ijA; d++) {
      workspace_data[b_ix] += Bk[d - 1] * sk_data[ix];
      b_ix++;
    }

    ix++;
  }

  curvatureS = 0.0;
  if (nvar >= 1) {
    for (ix = 0; ix < nvar; ix++) {
      curvatureS += workspace_data[ix] * sk_data[ix];
    }
  }

  if (dotSY < 0.2 * curvatureS) {
    dotSY = 0.8 * curvatureS / (curvatureS - dotSY);
    for (ix = 0; ix < nvar; ix++) {
      yk_data[ix] *= dotSY;
    }

    if (!(1.0 - dotSY == 0.0)) {
      for (ix = 0; ix < nvar; ix++) {
        yk_data[ix] += (1.0 - dotSY) * workspace_data[ix];
      }
    }

    dotSY = 0.0;
    if (nvar >= 1) {
      for (ix = 0; ix < nvar; ix++) {
        dotSY += sk_data[ix] * yk_data[ix];
      }
    }
  }

  success = ((curvatureS > 2.2204460492503131E-16) && (dotSY >
              2.2204460492503131E-16));
  if (success) {
    curvatureS = -1.0 / curvatureS;
    if (!(curvatureS == 0.0)) {
      ix = 0;
      jy = 0;
      for (iac = 0; iac < nvar; iac++) {
        if (workspace_data[jy] != 0.0) {
          real_T temp;
          temp = workspace_data[jy] * curvatureS;
          b_ix = 0;
          ijA = ix;
          d = nvar + ix;
          while (ijA + 1 <= d) {
            Bk[ijA] += workspace_data[b_ix] * temp;
            b_ix++;
            ijA++;
          }
        }

        jy++;
        ix += 21;
      }
    }

    dotSY = 1.0 / dotSY;
    if (!(dotSY == 0.0)) {
      ix = 0;
      jy = 0;
      for (iac = 0; iac < nvar; iac++) {
        if (yk_data[jy] != 0.0) {
          curvatureS = yk_data[jy] * dotSY;
          b_ix = 0;
          ijA = ix;
          d = nvar + ix;
          while (ijA + 1 <= d) {
            Bk[ijA] += yk_data[b_ix] * curvatureS;
            b_ix++;
            ijA++;
          }
        }

        jy++;
        ix += 21;
      }
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulati_ComputeNumDependentEq_(s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *qrmanager, const real_T beqf_data[], int32_T mConstr, int32_T nVar)
{
  int32_T numDependent;
  numDependent = mConstr - nVar;
  if (0 >= numDependent) {
    numDependent = 0;
  }

  Simulation_B.totalRank = 0;
  while (Simulation_B.totalRank <= nVar - 1) {
    qrmanager->jpvt.data[Simulation_B.totalRank] = 0;
    Simulation_B.totalRank++;
  }

  if (mConstr * nVar == 0) {
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mConstr;
    qrmanager->ncols = nVar;
    if (mConstr <= nVar) {
      qrmanager->minRowCol = mConstr;
    } else {
      qrmanager->minRowCol = nVar;
    }

    Simulation_xgeqp3(qrmanager->QR.data, qrmanager->QR.size, mConstr, nVar,
                      qrmanager->jpvt.data, qrmanager->tau.data,
                      &qrmanager->tau.size);
  }

  Simulation_B.tol = 100.0 * static_cast<real_T>(nVar) * 2.2204460492503131E-16;
  if (nVar <= mConstr) {
    Simulation_B.totalRank = nVar;
  } else {
    Simulation_B.totalRank = mConstr;
  }

  Simulation_B.totalRank += (Simulation_B.totalRank - 1) * qrmanager->ldq;
  while ((Simulation_B.totalRank > 0) && (fabs(qrmanager->
           QR.data[Simulation_B.totalRank - 1]) < Simulation_B.tol)) {
    Simulation_B.totalRank = (Simulation_B.totalRank - qrmanager->ldq) - 1;
    numDependent++;
  }

  if (numDependent > 0) {
    boolean_T exitg1;
    Simulation_computeQ_(qrmanager, qrmanager->mrows);
    Simulation_B.totalRank = 0;
    exitg1 = false;
    while ((!exitg1) && (Simulation_B.totalRank <= numDependent - 1)) {
      Simulation_B.ix_c = ((mConstr - Simulation_B.totalRank) - 1) *
        qrmanager->ldq;
      Simulation_B.qtb = 0.0;
      Simulation_B.iy_c = 0;
      Simulation_B.k_m = 0;
      while (Simulation_B.k_m <= mConstr - 1) {
        Simulation_B.qtb += qrmanager->Q.data[Simulation_B.ix_c] *
          beqf_data[Simulation_B.iy_c];
        Simulation_B.ix_c++;
        Simulation_B.iy_c++;
        Simulation_B.k_m++;
      }

      if (fabs(Simulation_B.qtb) >= Simulation_B.tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        Simulation_B.totalRank++;
      }
    }
  }

  return numDependent;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_IndexOfDependentEq_(int32_T depIdx_data[], int32_T mFixed,
  int32_T nDep, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, int32_T mRows,
  int32_T nCols)
{
  Simulation_B.b_idx_d = 0;
  while (Simulation_B.b_idx_d <= mFixed - 1) {
    qrmanager->jpvt.data[Simulation_B.b_idx_d] = 1;
    Simulation_B.b_idx_d++;
  }

  Simulation_B.b_idx_d = mFixed;
  while (Simulation_B.b_idx_d + 1 <= nCols) {
    qrmanager->jpvt.data[Simulation_B.b_idx_d] = 0;
    Simulation_B.b_idx_d++;
  }

  if (mRows * nCols == 0) {
    qrmanager->mrows = mRows;
    qrmanager->ncols = nCols;
    qrmanager->minRowCol = 0;
  } else {
    qrmanager->usedPivoting = true;
    qrmanager->mrows = mRows;
    qrmanager->ncols = nCols;
    if (mRows <= nCols) {
      qrmanager->minRowCol = mRows;
    } else {
      qrmanager->minRowCol = nCols;
    }

    Simulation_xgeqp3(qrmanager->QR.data, qrmanager->QR.size, mRows, nCols,
                      qrmanager->jpvt.data, qrmanager->tau.data,
                      &qrmanager->tau.size);
  }

  Simulation_B.b_idx_d = 0;
  while (Simulation_B.b_idx_d <= nDep - 1) {
    depIdx_data[Simulation_B.b_idx_d] = qrmanager->jpvt.data[(nCols - nDep) +
      Simulation_B.b_idx_d];
    Simulation_B.b_idx_d++;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_countsort(int32_T x_data[], int32_T xLen, int32_T
  workspace_data[], int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxStart;
    b_tmp = xMax - xMin;
    for (idxStart = 0; idxStart <= b_tmp; idxStart++) {
      workspace_data[idxStart] = 0;
    }

    for (idxStart = 0; idxStart < xLen; idxStart++) {
      idxEnd = x_data[idxStart] - xMin;
      workspace_data[idxEnd]++;
    }

    for (idxStart = 1; idxStart < b_tmp + 1; idxStart++) {
      workspace_data[idxStart] += workspace_data[idxStart - 1];
    }

    idxStart = 1;
    idxEnd = workspace_data[0];
    for (int32_T b_idxW = 0; b_idxW < b_tmp; b_idxW++) {
      while (idxStart <= idxEnd) {
        x_data[idxStart - 1] = b_idxW + xMin;
        idxStart++;
      }

      idxStart = workspace_data[b_idxW] + 1;
      idxEnd = workspace_data[b_idxW + 1];
    }

    while (idxStart <= idxEnd) {
      x_data[idxStart - 1] = xMax;
      idxStart++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_removeConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T idx_global_start_tmp_tmp;
  TYPE_tmp = obj->Wid.data[idx_global - 1] - 1;
  obj->isActiveConstr.data[(obj->isActiveIdx[TYPE_tmp] + obj->
    Wlocalidx.data[idx_global - 1]) - 2] = false;
  idx_global_start_tmp_tmp = obj->nActiveConstr - 1;
  obj->Wid.data[idx_global - 1] = obj->Wid.data[obj->nActiveConstr - 1];
  obj->Wlocalidx.data[idx_global - 1] = obj->
    Wlocalidx.data[idx_global_start_tmp_tmp];
  for (int32_T b_idx = 0; b_idx < obj->nVar; b_idx++) {
    obj->ATwset.data[b_idx + obj->ldA * (idx_global - 1)] = obj->ATwset.data
      [obj->ldA * idx_global_start_tmp_tmp + b_idx];
  }

  obj->bwset.data[idx_global - 1] = obj->bwset.data[idx_global_start_tmp_tmp];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulation_RemoveDependentEq_(s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager)
{
  int32_T nDepInd;
  Simulation_B.nVar_tmp_tmp_g = workingset->nVar - 1;
  Simulation_B.mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr
    [1];
  nDepInd = 0;
  if (Simulation_B.mTotalWorkingEq > 0) {
    Simulation_B.idx_row = 0;
    while (Simulation_B.idx_row <= Simulation_B.mTotalWorkingEq - 1) {
      Simulation_B.c_idx = 0;
      while (Simulation_B.c_idx <= Simulation_B.nVar_tmp_tmp_g) {
        qrmanager->QR.data[Simulation_B.idx_row + qrmanager->ldq *
          Simulation_B.c_idx] = workingset->ATwset.data[workingset->ldA *
          Simulation_B.idx_row + Simulation_B.c_idx];
        Simulation_B.c_idx++;
      }

      Simulation_B.idx_row++;
    }

    nDepInd = Simulati_ComputeNumDependentEq_(qrmanager, workingset->bwset.data,
      Simulation_B.mTotalWorkingEq, workingset->nVar);
    if (nDepInd > 0) {
      Simulation_B.idx_row = 0;
      while (Simulation_B.idx_row <= Simulation_B.mTotalWorkingEq - 1) {
        Simulation_B.c_idx = qrmanager->ldq * Simulation_B.idx_row;
        Simulation_B.e_idx = workingset->ldA * Simulation_B.idx_row;
        Simulation_B.k_o = 1;
        while (Simulation_B.k_o - 1 <= Simulation_B.nVar_tmp_tmp_g) {
          qrmanager->QR.data[(Simulation_B.c_idx + Simulation_B.k_o) - 1] =
            workingset->ATwset.data[(Simulation_B.e_idx + Simulation_B.k_o) - 1];
          Simulation_B.k_o++;
        }

        Simulation_B.idx_row++;
      }

      Simulation_IndexOfDependentEq_(memspace->workspace_int.data,
        workingset->nWConstr[0], nDepInd, qrmanager, workingset->nVar,
        Simulation_B.mTotalWorkingEq);
      Simulation_countsort(memspace->workspace_int.data, nDepInd,
                           memspace->workspace_sort.data, 1,
                           Simulation_B.mTotalWorkingEq);
      Simulation_B.nVar_tmp_tmp_g = nDepInd - 1;
      while (Simulation_B.nVar_tmp_tmp_g + 1 > 0) {
        Simulation_B.mTotalWorkingEq = (workingset->nWConstr[0] +
          workingset->nWConstr[1]) - 1;
        if ((Simulation_B.mTotalWorkingEq + 1 != 0) &&
            (memspace->workspace_int.data[Simulation_B.nVar_tmp_tmp_g] <=
             Simulation_B.mTotalWorkingEq + 1)) {
          if ((Simulation_B.mTotalWorkingEq + 1 == workingset->nActiveConstr) ||
              (Simulation_B.mTotalWorkingEq + 1 == memspace->
               workspace_int.data[Simulation_B.nVar_tmp_tmp_g])) {
            workingset->mEqRemoved++;
            workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
              workingset->Wlocalidx.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1];
            Simulation_removeConstr(workingset, memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g]);
          } else {
            workingset->mEqRemoved++;
            Simulation_B.idx_row = workingset->Wid.data
              [memspace->workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1] -
              1;
            workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
              workingset->Wlocalidx.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1];
            workingset->isActiveConstr.data[(workingset->isActiveIdx
              [workingset->Wid.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1] - 1] +
              workingset->Wlocalidx.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1]) - 2] = false;
            workingset->Wid.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1] =
              workingset->Wid.data[Simulation_B.mTotalWorkingEq];
            workingset->Wlocalidx.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1] =
              workingset->Wlocalidx.data[Simulation_B.mTotalWorkingEq];
            Simulation_B.c_idx = 0;
            while (Simulation_B.c_idx <= workingset->nVar - 1) {
              workingset->ATwset.data[Simulation_B.c_idx + workingset->ldA *
                (memspace->workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1)]
                = workingset->ATwset.data[workingset->ldA *
                Simulation_B.mTotalWorkingEq + Simulation_B.c_idx];
              Simulation_B.c_idx++;
            }

            workingset->bwset.data[memspace->
              workspace_int.data[Simulation_B.nVar_tmp_tmp_g] - 1] =
              workingset->bwset.data[Simulation_B.mTotalWorkingEq];
            Simulation_B.c_idx = workingset->nActiveConstr - 1;
            workingset->Wid.data[Simulation_B.mTotalWorkingEq] =
              workingset->Wid.data[workingset->nActiveConstr - 1];
            workingset->Wlocalidx.data[Simulation_B.mTotalWorkingEq] =
              workingset->Wlocalidx.data[Simulation_B.c_idx];
            Simulation_B.e_idx = 0;
            while (Simulation_B.e_idx <= workingset->nVar - 1) {
              workingset->ATwset.data[Simulation_B.e_idx + workingset->ldA *
                Simulation_B.mTotalWorkingEq] = workingset->
                ATwset.data[workingset->ldA * Simulation_B.c_idx +
                Simulation_B.e_idx];
              Simulation_B.e_idx++;
            }

            workingset->bwset.data[Simulation_B.mTotalWorkingEq] =
              workingset->bwset.data[Simulation_B.c_idx];
            workingset->nActiveConstr--;
            workingset->nWConstr[Simulation_B.idx_row]--;
          }
        }

        Simulation_B.nVar_tmp_tmp_g--;
      }
    }
  }

  return nDepInd;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_removeAllIneqConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj)
{
  for (int32_T idx_global = obj->nWConstr[0] + obj->nWConstr[1]; idx_global <
       obj->nActiveConstr; idx_global++) {
    obj->isActiveConstr.data[(obj->isActiveIdx[obj->Wid.data[idx_global] - 1] +
      obj->Wlocalidx.data[idx_global]) - 2] = false;
  }

  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + obj->nWConstr[1];
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_RemoveDependentIneq_(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace)
{
  Simulation_B.nFixedConstr_e = workingset->nWConstr[0] + workingset->nWConstr[1];
  Simulation_B.nVar_dd = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    Simulation_B.tol_b = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    Simulation_B.nDepIneq_g = 0;
    while (Simulation_B.nDepIneq_g <= Simulation_B.nFixedConstr_e - 1) {
      qrmanager->jpvt.data[Simulation_B.nDepIneq_g] = 1;
      Simulation_B.nDepIneq_g++;
    }

    Simulation_B.nDepIneq_g = Simulation_B.nFixedConstr_e + 1;
    while (Simulation_B.nDepIneq_g <= workingset->nActiveConstr) {
      qrmanager->jpvt.data[Simulation_B.nDepIneq_g - 1] = 0;
      Simulation_B.nDepIneq_g++;
    }

    Simulation_B.nDepIneq_g = 0;
    while (Simulation_B.nDepIneq_g <= workingset->nActiveConstr - 1) {
      Simulation_B.idx_i = qrmanager->ldq * Simulation_B.nDepIneq_g;
      Simulation_B.ix0_n = workingset->ldA * Simulation_B.nDepIneq_g;
      Simulation_B.k_l = 1;
      while (Simulation_B.k_l - 1 <= Simulation_B.nVar_dd - 1) {
        qrmanager->QR.data[(Simulation_B.idx_i + Simulation_B.k_l) - 1] =
          workingset->ATwset.data[(Simulation_B.ix0_n + Simulation_B.k_l) - 1];
        Simulation_B.k_l++;
      }

      Simulation_B.nDepIneq_g++;
    }

    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      if (workingset->nVar <= workingset->nActiveConstr) {
        qrmanager->minRowCol = workingset->nVar;
      } else {
        qrmanager->minRowCol = workingset->nActiveConstr;
      }

      Simulation_xgeqp3(qrmanager->QR.data, qrmanager->QR.size, workingset->nVar,
                        workingset->nActiveConstr, qrmanager->jpvt.data,
                        qrmanager->tau.data, &qrmanager->tau.size);
    }

    Simulation_B.nDepIneq_g = 0;
    Simulation_B.idx_i = workingset->nActiveConstr - 1;
    while (Simulation_B.idx_i + 1 > Simulation_B.nVar_dd) {
      Simulation_B.nDepIneq_g++;
      memspace->workspace_int.data[Simulation_B.nDepIneq_g - 1] =
        qrmanager->jpvt.data[Simulation_B.idx_i];
      Simulation_B.idx_i--;
    }

    if (Simulation_B.idx_i + 1 <= workingset->nVar) {
      Simulation_B.nVar_dd = qrmanager->ldq * Simulation_B.idx_i +
        Simulation_B.idx_i;
      while ((Simulation_B.idx_i + 1 > Simulation_B.nFixedConstr_e) && (fabs
              (qrmanager->QR.data[Simulation_B.nVar_dd]) < Simulation_B.tol_b))
      {
        Simulation_B.nDepIneq_g++;
        memspace->workspace_int.data[Simulation_B.nDepIneq_g - 1] =
          qrmanager->jpvt.data[Simulation_B.idx_i];
        Simulation_B.idx_i--;
        Simulation_B.nVar_dd = (Simulation_B.nVar_dd - qrmanager->ldq) - 1;
      }
    }

    Simulation_countsort(memspace->workspace_int.data, Simulation_B.nDepIneq_g,
                         memspace->workspace_sort.data,
                         Simulation_B.nFixedConstr_e + 1,
                         workingset->nActiveConstr);
    while (Simulation_B.nDepIneq_g > 0) {
      Simulation_removeConstr(workingset, memspace->
        workspace_int.data[Simulation_B.nDepIneq_g - 1]);
      Simulation_B.nDepIneq_g--;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgeqrf(real_T A_data[], const int32_T A_size[2], int32_T
  m, int32_T n, real_T tau_data[], int32_T *tau_size)
{
  if (A_size[0] <= A_size[1]) {
    Simulation_B.minmana_n = A_size[0];
  } else {
    Simulation_B.minmana_n = A_size[1];
  }

  if (m <= n) {
    Simulation_B.minmn_p = m;
  } else {
    Simulation_B.minmn_p = n;
  }

  *tau_size = Simulation_B.minmana_n;
  if (0 <= Simulation_B.minmana_n - 1) {
    memset(&tau_data[0], 0, Simulation_B.minmana_n * sizeof(real_T));
  }

  if (Simulation_B.minmn_p >= 1) {
    Simulation_qrf(A_data, A_size, m, n, Simulation_B.minmn_p, tau_data);
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_factorQR(s_ASr52t7t39LT7rtZ8hZCX_Simul_T *obj, const
  real_T A_data[], int32_T mrows, int32_T ncols, int32_T ldA)
{
  boolean_T guard1 = false;
  Simulation_B.b_idx_f = mrows * ncols;
  guard1 = false;
  if (Simulation_B.b_idx_f > 0) {
    Simulation_B.b_idx_f = 0;
    while (Simulation_B.b_idx_f <= ncols - 1) {
      Simulation_B.ix0 = ldA * Simulation_B.b_idx_f;
      Simulation_B.iy0 = obj->ldq * Simulation_B.b_idx_f;
      Simulation_B.k_c = 1;
      while (Simulation_B.k_c - 1 <= mrows - 1) {
        obj->QR.data[(Simulation_B.iy0 + Simulation_B.k_c) - 1] = A_data
          [(Simulation_B.ix0 + Simulation_B.k_c) - 1];
        Simulation_B.k_c++;
      }

      Simulation_B.b_idx_f++;
    }

    guard1 = true;
  } else if (Simulation_B.b_idx_f == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    Simulation_B.b_idx_f = 0;
    while (Simulation_B.b_idx_f <= ncols - 1) {
      obj->jpvt.data[Simulation_B.b_idx_f] = Simulation_B.b_idx_f + 1;
      Simulation_B.b_idx_f++;
    }

    if (mrows <= ncols) {
      obj->minRowCol = mrows;
    } else {
      obj->minRowCol = ncols;
    }

    Simulation_xgeqrf(obj->QR.data, obj->QR.size, mrows, ncols, obj->tau.data,
                      &obj->tau.size);
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = 0;
      c = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        c += A_data[ia - 1] * x_data[ix];
        ix++;
      }

      y_data[b_iy] += c;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x(int32_T n, const real_T A_data[], int32_T lda,
  const real_T x_data[], real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      real_T c;
      int32_T ix;
      ix = 0;
      c = 0.0;
      for (int32_T ia = iac; ia <= iac + 20; ia++) {
        c += A_data[ia - 1] * x_data[ix];
        ix++;
      }

      y_data[b_iy] += c;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulati_maxConstraintViolation(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *obj, const real_T x_data[])
{
  real_T v;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    int32_T b_k;
    v = 0.0;
    mIneq = obj->sizes[2] - 1;
    if (obj->Aineq.size != 0) {
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] = obj->bineq.data[b_k];
      }

      Simulation_xgemv_la4x(obj->sizes[2], obj->Aineq.data, obj->ldA, x_data,
                            obj->maxConstrWorkspace.data);
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] -= x_data[b_k + 21];
        Simulation_B.u1_f = obj->maxConstrWorkspace.data[b_k];
        if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
          v = Simulation_B.u1_f;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], sizeof(real_T) << 4U);
    Simulation_xgemv_la4x(16, obj->Aeq.data, obj->ldA, x_data,
                          obj->maxConstrWorkspace.data);
    for (b_k = 0; b_k < 16; b_k++) {
      obj->maxConstrWorkspace.data[b_k] = (obj->maxConstrWorkspace.data[b_k] -
        x_data[(mIneq + b_k) + 22]) + x_data[(obj->sizes[2] + b_k) + 37];
      Simulation_B.u1_f = fabs(obj->maxConstrWorkspace.data[b_k]);
      if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
        v = Simulation_B.u1_f;
      }
    }
  } else {
    v = 0.0;
    mIneq = obj->sizes[2] - 1;
    if (obj->Aineq.size != 0) {
      int32_T b_k;
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] = obj->bineq.data[b_k];
      }

      Simulation_xgemv_la4x4(obj->nVar, obj->sizes[2], obj->Aineq.data, obj->ldA,
        x_data, obj->maxConstrWorkspace.data);
      for (b_k = 0; b_k <= mIneq; b_k++) {
        Simulation_B.u1_f = obj->maxConstrWorkspace.data[b_k];
        if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
          v = Simulation_B.u1_f;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], sizeof(real_T) << 4U);
    Simulation_xgemv_la4x4(obj->nVar, 16, obj->Aeq.data, obj->ldA, x_data,
      obj->maxConstrWorkspace.data);
    for (mIneq = 0; mIneq < 16; mIneq++) {
      Simulation_B.u1_f = fabs(obj->maxConstrWorkspace.data[mIneq]);
      if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
        v = Simulation_B.u1_f;
      }
    }
  }

  if (mLB > 0) {
    for (mIneq = 0; mIneq < mLB; mIneq++) {
      Simulation_B.u1_f = -x_data[obj->indexLB.data[mIneq] - 1] - obj->
        lb.data[obj->indexLB.data[mIneq] - 1];
      if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
        v = Simulation_B.u1_f;
      }
    }
  }

  if (mUB > 0) {
    for (mLB = 0; mLB < mUB; mLB++) {
      Simulation_B.u1_f = x_data[obj->indexUB.data[mLB] - 1] - obj->ub.data
        [obj->indexUB.data[mLB] - 1];
      if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
        v = Simulation_B.u1_f;
      }
    }
  }

  if (mFixed > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      Simulation_B.u1_f = fabs(x_data[obj->indexFixed.data[mUB] - 1] -
        obj->ub.data[obj->indexFixed.data[mUB] - 1]);
      if ((!(v >= Simulation_B.u1_f)) && (!rtIsNaN(Simulation_B.u1_f))) {
        v = Simulation_B.u1_f;
      }
    }
  }

  return v;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4r(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], int32_T ix0, real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        c += x_data[ix - 1] * A_data[ia - 1];
        ix++;
      }

      y_data[b_iy] += c;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simula_maxConstraintViolation_e(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *obj, const real_T x_data[], int32_T ix0)
{
  real_T v;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    int32_T b_k;
    v = 0.0;
    mIneq = obj->sizes[2] - 1;
    if (obj->Aineq.size != 0) {
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] = obj->bineq.data[b_k];
      }

      Simulation_xgemv_la4x4r(21, obj->sizes[2], obj->Aineq.data, obj->ldA,
        x_data, ix0, obj->maxConstrWorkspace.data);
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] -= x_data[(ix0 + b_k) + 20];
        Simulation_B.u1_e = obj->maxConstrWorkspace.data[b_k];
        if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
          v = Simulation_B.u1_e;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], sizeof(real_T) << 4U);
    Simulation_xgemv_la4x4r(21, 16, obj->Aeq.data, obj->ldA, x_data, ix0,
      obj->maxConstrWorkspace.data);
    for (b_k = 0; b_k < 16; b_k++) {
      obj->maxConstrWorkspace.data[b_k] = (obj->maxConstrWorkspace.data[b_k] -
        x_data[((ix0 + mIneq) + b_k) + 21]) + x_data[((ix0 + obj->sizes[2]) +
        b_k) + 36];
      Simulation_B.u1_e = fabs(obj->maxConstrWorkspace.data[b_k]);
      if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
        v = Simulation_B.u1_e;
      }
    }
  } else {
    v = 0.0;
    mIneq = obj->sizes[2] - 1;
    if (obj->Aineq.size != 0) {
      int32_T b_k;
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] = obj->bineq.data[b_k];
      }

      Simulation_xgemv_la4x4r(obj->nVar, obj->sizes[2], obj->Aineq.data,
        obj->ldA, x_data, ix0, obj->maxConstrWorkspace.data);
      for (b_k = 0; b_k <= mIneq; b_k++) {
        Simulation_B.u1_e = obj->maxConstrWorkspace.data[b_k];
        if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
          v = Simulation_B.u1_e;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], sizeof(real_T) << 4U);
    Simulation_xgemv_la4x4r(obj->nVar, 16, obj->Aeq.data, obj->ldA, x_data, ix0,
      obj->maxConstrWorkspace.data);
    for (mIneq = 0; mIneq < 16; mIneq++) {
      Simulation_B.u1_e = fabs(obj->maxConstrWorkspace.data[mIneq]);
      if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
        v = Simulation_B.u1_e;
      }
    }
  }

  if (mLB > 0) {
    for (mIneq = 0; mIneq < mLB; mIneq++) {
      Simulation_B.u1_e = -x_data[(ix0 + obj->indexLB.data[mIneq]) - 2] -
        obj->lb.data[obj->indexLB.data[mIneq] - 1];
      if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
        v = Simulation_B.u1_e;
      }
    }
  }

  if (mUB > 0) {
    for (mLB = 0; mLB < mUB; mLB++) {
      Simulation_B.u1_e = x_data[(ix0 + obj->indexUB.data[mLB]) - 2] -
        obj->ub.data[obj->indexUB.data[mLB] - 1];
      if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
        v = Simulation_B.u1_e;
      }
    }
  }

  if (mFixed > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      Simulation_B.u1_e = fabs(x_data[(ix0 + obj->indexFixed.data[mUB]) - 2] -
        obj->ub.data[obj->indexFixed.data[mUB] - 1]);
      if ((!(v >= Simulation_B.u1_e)) && (!rtIsNaN(Simulation_B.u1_e))) {
        v = Simulation_B.u1_e;
      }
    }
  }

  return v;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static boolean_T Simulat_feasibleX0ForWorkingSet(real_T workspace_data[], const
  int32_T workspace_size[2], real_T xCurrent_data[],
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *qrmanager)
{
  boolean_T nonDegenerateWset;
  Simulation_B.mWConstr_tmp_tmp = workingset->nActiveConstr - 1;
  Simulation_B.nVar_j = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    Simulation_B.ldq = 0;
    while (Simulation_B.ldq <= Simulation_B.mWConstr_tmp_tmp) {
      workspace_data[Simulation_B.ldq] = workingset->bwset.data[Simulation_B.ldq];
      workspace_data[Simulation_B.ldq + workspace_size[0]] =
        workingset->bwset.data[Simulation_B.ldq];
      Simulation_B.ldq++;
    }

    Simulation_B.ldq = workingset->ldA;
    if (workingset->nActiveConstr != 0) {
      Simulation_B.iy_a = 0;
      Simulation_B.br = (workingset->nActiveConstr - 1) * workingset->ldA + 1;
      Simulation_B.iAcol = 1;
      while (((Simulation_B.ldq > 0) && (Simulation_B.iAcol <= Simulation_B.br))
             || ((Simulation_B.ldq < 0) && (Simulation_B.iAcol >=
               Simulation_B.br))) {
        Simulation_B.ix_f = 0;
        Simulation_B.c = 0.0;
        Simulation_B.d_g = (Simulation_B.iAcol + Simulation_B.nVar_j) - 1;
        Simulation_B.ia_n = Simulation_B.iAcol;
        while (Simulation_B.ia_n <= Simulation_B.d_g) {
          Simulation_B.c += workingset->ATwset.data[Simulation_B.ia_n - 1] *
            xCurrent_data[Simulation_B.ix_f];
          Simulation_B.ix_f++;
          Simulation_B.ia_n++;
        }

        workspace_data[Simulation_B.iy_a] += -Simulation_B.c;
        Simulation_B.iy_a++;
        Simulation_B.iAcol += Simulation_B.ldq;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      Simulation_B.ldq = 0;
      while (Simulation_B.ldq <= Simulation_B.nVar_j - 1) {
        Simulation_B.iy_a = qrmanager->ldq * Simulation_B.ldq;
        Simulation_B.br = 0;
        while (Simulation_B.br <= Simulation_B.mWConstr_tmp_tmp) {
          qrmanager->QR.data[Simulation_B.br + Simulation_B.iy_a] =
            workingset->ATwset.data[workingset->ldA * Simulation_B.br +
            Simulation_B.ldq];
          Simulation_B.br++;
        }

        Simulation_B.ldq++;
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      Simulation_B.ldq = 0;
      while (Simulation_B.ldq <= Simulation_B.nVar_j - 1) {
        qrmanager->jpvt.data[Simulation_B.ldq] = Simulation_B.ldq + 1;
        Simulation_B.ldq++;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        qrmanager->minRowCol = workingset->nActiveConstr;
      } else {
        qrmanager->minRowCol = workingset->nVar;
      }

      Simulation_xgeqrf(qrmanager->QR.data, qrmanager->QR.size,
                        workingset->nActiveConstr, workingset->nVar,
                        qrmanager->tau.data, &qrmanager->tau.size);
      Simulation_computeQ_(qrmanager, qrmanager->mrows);
      Simulation_B.ldq = qrmanager->ldq;
      Simulation_B.iy_a = workspace_size[0];
      Simulation_B.iAcol = workspace_size[0] * workspace_size[1];
      if (0 <= Simulation_B.iAcol - 1) {
        memcpy(&Simulation_B.B_data[0], &workspace_data[0], Simulation_B.iAcol *
               sizeof(real_T));
      }

      Simulation_B.br = 0;
      while ((Simulation_B.iy_a > 0) && (Simulation_B.br <= Simulation_B.iy_a))
      {
        Simulation_B.iAcol = Simulation_B.br;
        Simulation_B.ix_f = Simulation_B.br + Simulation_B.nVar_j;
        while (Simulation_B.iAcol + 1 <= Simulation_B.ix_f) {
          workspace_data[Simulation_B.iAcol] = 0.0;
          Simulation_B.iAcol++;
        }

        Simulation_B.br += Simulation_B.iy_a;
      }

      Simulation_B.br = -1;
      Simulation_B.iAcol = 0;
      while ((Simulation_B.iy_a > 0) && (Simulation_B.iAcol <= Simulation_B.iy_a))
      {
        Simulation_B.ix_f = -1;
        Simulation_B.d_g = Simulation_B.iAcol;
        Simulation_B.ia_n = Simulation_B.iAcol + Simulation_B.nVar_j;
        while (Simulation_B.d_g + 1 <= Simulation_B.ia_n) {
          Simulation_B.c = 0.0;
          Simulation_B.b_ia_d = 1;
          while (Simulation_B.b_ia_d - 1 <= Simulation_B.mWConstr_tmp_tmp) {
            Simulation_B.c += qrmanager->Q.data[Simulation_B.b_ia_d +
              Simulation_B.ix_f] * Simulation_B.B_data[Simulation_B.b_ia_d +
              Simulation_B.br];
            Simulation_B.b_ia_d++;
          }

          workspace_data[Simulation_B.d_g] += Simulation_B.c;
          Simulation_B.ix_f += Simulation_B.ldq;
          Simulation_B.d_g++;
        }

        Simulation_B.br += Simulation_B.iy_a;
        Simulation_B.iAcol += Simulation_B.iy_a;
      }

      Simulation_B.mWConstr_tmp_tmp = workingset->nVar;
      while (Simulation_B.mWConstr_tmp_tmp > 0) {
        Simulation_B.iAcol = (Simulation_B.mWConstr_tmp_tmp - 1) *
          Simulation_B.ldq - 1;
        if (workspace_data[Simulation_B.mWConstr_tmp_tmp + -1] != 0.0) {
          workspace_data[Simulation_B.mWConstr_tmp_tmp + -1] /=
            qrmanager->QR.data[Simulation_B.mWConstr_tmp_tmp +
            Simulation_B.iAcol];
          Simulation_B.ix_f = 1;
          while (Simulation_B.ix_f - 1 <= Simulation_B.mWConstr_tmp_tmp - 2) {
            workspace_data[Simulation_B.ix_f + -1] -=
              workspace_data[Simulation_B.mWConstr_tmp_tmp + -1] *
              qrmanager->QR.data[Simulation_B.ix_f + Simulation_B.iAcol];
            Simulation_B.ix_f++;
          }
        }

        Simulation_B.mWConstr_tmp_tmp--;
      }

      Simulation_B.mWConstr_tmp_tmp = workingset->nVar;
      while (Simulation_B.mWConstr_tmp_tmp > 0) {
        Simulation_B.iAcol = (Simulation_B.mWConstr_tmp_tmp - 1) *
          Simulation_B.ldq - 1;
        Simulation_B.br = (Simulation_B.iy_a + Simulation_B.mWConstr_tmp_tmp) -
          1;
        if (workspace_data[Simulation_B.br] != 0.0) {
          workspace_data[Simulation_B.br] /= qrmanager->
            QR.data[Simulation_B.mWConstr_tmp_tmp + Simulation_B.iAcol];
          Simulation_B.ix_f = 1;
          while (Simulation_B.ix_f - 1 <= Simulation_B.mWConstr_tmp_tmp - 2) {
            Simulation_B.d_g = (Simulation_B.iy_a + Simulation_B.ix_f) - 1;
            workspace_data[Simulation_B.d_g] -= qrmanager->
              QR.data[Simulation_B.ix_f + Simulation_B.iAcol] *
              workspace_data[Simulation_B.br];
            Simulation_B.ix_f++;
          }
        }

        Simulation_B.mWConstr_tmp_tmp--;
      }
    } else {
      Simulation_factorQR(qrmanager, workingset->ATwset.data, workingset->nVar,
                          workingset->nActiveConstr, workingset->ldA);
      Simulation_computeQ_(qrmanager, qrmanager->minRowCol);
      Simulation_B.ldq = qrmanager->ldq;
      Simulation_B.iy_a = workspace_size[0];
      Simulation_B.br = 1;
      while (Simulation_B.br - 1 <= Simulation_B.mWConstr_tmp_tmp) {
        Simulation_B.iAcol = (Simulation_B.br - 1) * Simulation_B.ldq - 1;
        Simulation_B.c = workspace_data[Simulation_B.br + -1];
        Simulation_B.ix_f = 1;
        while (Simulation_B.ix_f - 1 <= Simulation_B.br - 2) {
          Simulation_B.c -= qrmanager->QR.data[Simulation_B.ix_f +
            Simulation_B.iAcol] * workspace_data[Simulation_B.ix_f + -1];
          Simulation_B.ix_f++;
        }

        workspace_data[Simulation_B.br + -1] = Simulation_B.c /
          qrmanager->QR.data[Simulation_B.br + Simulation_B.iAcol];
        Simulation_B.br++;
      }

      Simulation_B.br = 1;
      while (Simulation_B.br - 1 <= Simulation_B.mWConstr_tmp_tmp) {
        Simulation_B.iAcol = (Simulation_B.br - 1) * Simulation_B.ldq - 1;
        Simulation_B.d_g = (Simulation_B.iy_a + Simulation_B.br) - 1;
        Simulation_B.c = workspace_data[Simulation_B.d_g];
        Simulation_B.ix_f = 1;
        while (Simulation_B.ix_f - 1 <= Simulation_B.br - 2) {
          Simulation_B.c -= workspace_data[(Simulation_B.iy_a +
            Simulation_B.ix_f) - 1] * qrmanager->QR.data[Simulation_B.ix_f +
            Simulation_B.iAcol];
          Simulation_B.ix_f++;
        }

        workspace_data[Simulation_B.d_g] = Simulation_B.c / qrmanager->
          QR.data[Simulation_B.br + Simulation_B.iAcol];
        Simulation_B.br++;
      }

      Simulation_B.iAcol = workspace_size[0] * workspace_size[1];
      if (0 <= Simulation_B.iAcol - 1) {
        memcpy(&Simulation_B.B_data[0], &workspace_data[0], Simulation_B.iAcol *
               sizeof(real_T));
      }

      Simulation_B.br = 0;
      while ((Simulation_B.iy_a > 0) && (Simulation_B.br <= Simulation_B.iy_a))
      {
        Simulation_B.iAcol = Simulation_B.br;
        Simulation_B.ix_f = Simulation_B.br + Simulation_B.nVar_j;
        while (Simulation_B.iAcol + 1 <= Simulation_B.ix_f) {
          workspace_data[Simulation_B.iAcol] = 0.0;
          Simulation_B.iAcol++;
        }

        Simulation_B.br += Simulation_B.iy_a;
      }

      Simulation_B.br = 1;
      Simulation_B.iAcol = 0;
      while ((Simulation_B.iy_a > 0) && (Simulation_B.iAcol <= Simulation_B.iy_a))
      {
        Simulation_B.ix_f = -1;
        Simulation_B.d_g = Simulation_B.br;
        Simulation_B.ia_n = Simulation_B.br + Simulation_B.mWConstr_tmp_tmp;
        while (Simulation_B.d_g <= Simulation_B.ia_n) {
          Simulation_B.b_ia_d = Simulation_B.ix_f;
          Simulation_B.b_ic_c = Simulation_B.iAcol;
          Simulation_B.g_n = Simulation_B.iAcol + Simulation_B.nVar_j;
          while (Simulation_B.b_ic_c + 1 <= Simulation_B.g_n) {
            Simulation_B.b_ia_d++;
            workspace_data[Simulation_B.b_ic_c] +=
              Simulation_B.B_data[Simulation_B.d_g - 1] * qrmanager->
              Q.data[Simulation_B.b_ia_d];
            Simulation_B.b_ic_c++;
          }

          Simulation_B.ix_f += Simulation_B.ldq;
          Simulation_B.d_g++;
        }

        Simulation_B.br += Simulation_B.iy_a;
        Simulation_B.iAcol += Simulation_B.iy_a;
      }
    }

    Simulation_B.mWConstr_tmp_tmp = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (Simulation_B.mWConstr_tmp_tmp <= Simulation_B.nVar_j - 1) {
        Simulation_B.c = workspace_data[Simulation_B.mWConstr_tmp_tmp];
        if (rtIsInf(Simulation_B.c) || rtIsNaN(Simulation_B.c)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          Simulation_B.c = workspace_data[Simulation_B.mWConstr_tmp_tmp +
            workspace_size[0]];
          if (rtIsInf(Simulation_B.c) || rtIsNaN(Simulation_B.c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            Simulation_B.mWConstr_tmp_tmp++;
          }
        }
      } else {
        Simulation_B.mWConstr_tmp_tmp = 0;
        while (Simulation_B.mWConstr_tmp_tmp <= Simulation_B.nVar_j - 1) {
          workspace_data[Simulation_B.mWConstr_tmp_tmp] +=
            xCurrent_data[Simulation_B.mWConstr_tmp_tmp];
          Simulation_B.mWConstr_tmp_tmp++;
        }

        Simulation_B.c = Simulati_maxConstraintViolation(workingset,
          workspace_data);
        Simulation_B.constrViolation_basicX = Simula_maxConstraintViolation_e
          (workingset, workspace_data, workspace_size[0] + 1);
        if ((Simulation_B.c <= 2.2204460492503131E-16) || (Simulation_B.c <
             Simulation_B.constrViolation_basicX)) {
          Simulation_B.mWConstr_tmp_tmp = 0;
          while (Simulation_B.mWConstr_tmp_tmp <= Simulation_B.nVar_j - 1) {
            xCurrent_data[Simulation_B.mWConstr_tmp_tmp] =
              workspace_data[Simulation_B.mWConstr_tmp_tmp];
            Simulation_B.mWConstr_tmp_tmp++;
          }
        } else {
          Simulation_B.mWConstr_tmp_tmp = 0;
          while (Simulation_B.mWConstr_tmp_tmp <= Simulation_B.nVar_j - 1) {
            xCurrent_data[Simulation_B.mWConstr_tmp_tmp] =
              workspace_data[workspace_size[0] + Simulation_B.mWConstr_tmp_tmp];
            Simulation_B.mWConstr_tmp_tmp++;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulati_RemoveDependentIneq__a(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace)
{
  Simulation_B.nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  Simulation_B.nVar_n = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    Simulation_B.tol_o = 1000.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    Simulation_B.nDepIneq = 0;
    while (Simulation_B.nDepIneq <= Simulation_B.nFixedConstr - 1) {
      qrmanager->jpvt.data[Simulation_B.nDepIneq] = 1;
      Simulation_B.nDepIneq++;
    }

    Simulation_B.nDepIneq = Simulation_B.nFixedConstr + 1;
    while (Simulation_B.nDepIneq <= workingset->nActiveConstr) {
      qrmanager->jpvt.data[Simulation_B.nDepIneq - 1] = 0;
      Simulation_B.nDepIneq++;
    }

    Simulation_B.nDepIneq = 0;
    while (Simulation_B.nDepIneq <= workingset->nActiveConstr - 1) {
      Simulation_B.idx_o = qrmanager->ldq * Simulation_B.nDepIneq;
      Simulation_B.ix0_c = workingset->ldA * Simulation_B.nDepIneq;
      Simulation_B.k_b = 1;
      while (Simulation_B.k_b - 1 <= Simulation_B.nVar_n - 1) {
        qrmanager->QR.data[(Simulation_B.idx_o + Simulation_B.k_b) - 1] =
          workingset->ATwset.data[(Simulation_B.ix0_c + Simulation_B.k_b) - 1];
        Simulation_B.k_b++;
      }

      Simulation_B.nDepIneq++;
    }

    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      if (workingset->nVar <= workingset->nActiveConstr) {
        qrmanager->minRowCol = workingset->nVar;
      } else {
        qrmanager->minRowCol = workingset->nActiveConstr;
      }

      Simulation_xgeqp3(qrmanager->QR.data, qrmanager->QR.size, workingset->nVar,
                        workingset->nActiveConstr, qrmanager->jpvt.data,
                        qrmanager->tau.data, &qrmanager->tau.size);
    }

    Simulation_B.nDepIneq = 0;
    Simulation_B.idx_o = workingset->nActiveConstr - 1;
    while (Simulation_B.idx_o + 1 > Simulation_B.nVar_n) {
      Simulation_B.nDepIneq++;
      memspace->workspace_int.data[Simulation_B.nDepIneq - 1] =
        qrmanager->jpvt.data[Simulation_B.idx_o];
      Simulation_B.idx_o--;
    }

    if (Simulation_B.idx_o + 1 <= workingset->nVar) {
      Simulation_B.nVar_n = qrmanager->ldq * Simulation_B.idx_o +
        Simulation_B.idx_o;
      while ((Simulation_B.idx_o + 1 > Simulation_B.nFixedConstr) && (fabs
              (qrmanager->QR.data[Simulation_B.nVar_n]) < Simulation_B.tol_o)) {
        Simulation_B.nDepIneq++;
        memspace->workspace_int.data[Simulation_B.nDepIneq - 1] =
          qrmanager->jpvt.data[Simulation_B.idx_o];
        Simulation_B.idx_o--;
        Simulation_B.nVar_n = (Simulation_B.nVar_n - qrmanager->ldq) - 1;
      }
    }

    Simulation_countsort(memspace->workspace_int.data, Simulation_B.nDepIneq,
                         memspace->workspace_sort.data,
                         Simulation_B.nFixedConstr + 1,
                         workingset->nActiveConstr);
    while (Simulation_B.nDepIneq > 0) {
      Simulation_removeConstr(workingset, memspace->
        workspace_int.data[Simulation_B.nDepIneq - 1]);
      Simulation_B.nDepIneq--;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4rhx(int32_T m, int32_T n, const real_T A_data[],
  int32_T lda, const real_T x_data[], real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = 0;
      c = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        c += A_data[ia - 1] * x_data[ix];
        ix++;
      }

      y_data[b_iy] += c;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4rh(int32_T n, const real_T A_data[], int32_T
  lda, const real_T x_data[], real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      real_T c;
      int32_T ix;
      ix = 0;
      c = 0.0;
      for (int32_T ia = iac; ia <= iac + 20; ia++) {
        c += A_data[ia - 1] * x_data[ix];
        ix++;
      }

      y_data[b_iy] += c;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simul_maxConstraintViolation_e4(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *obj, const real_T x_data[])
{
  real_T v;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    int32_T b_k;
    v = 0.0;
    mIneq = obj->sizes[2] - 1;
    if (obj->Aineq.size != 0) {
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] = obj->bineq.data[b_k];
      }

      Simulation_xgemv_la4x4rh(obj->sizes[2], obj->Aineq.data, obj->ldA, x_data,
        obj->maxConstrWorkspace.data);
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] -= x_data[b_k + 21];
        Simulation_B.u1_g = obj->maxConstrWorkspace.data[b_k];
        if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
          v = Simulation_B.u1_g;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], sizeof(real_T) << 4U);
    Simulation_xgemv_la4x4rh(16, obj->Aeq.data, obj->ldA, x_data,
      obj->maxConstrWorkspace.data);
    for (b_k = 0; b_k < 16; b_k++) {
      obj->maxConstrWorkspace.data[b_k] = (obj->maxConstrWorkspace.data[b_k] -
        x_data[(mIneq + b_k) + 22]) + x_data[(obj->sizes[2] + b_k) + 37];
      Simulation_B.u1_g = fabs(obj->maxConstrWorkspace.data[b_k]);
      if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
        v = Simulation_B.u1_g;
      }
    }
  } else {
    v = 0.0;
    mIneq = obj->sizes[2] - 1;
    if (obj->Aineq.size != 0) {
      int32_T b_k;
      for (b_k = 0; b_k <= mIneq; b_k++) {
        obj->maxConstrWorkspace.data[b_k] = obj->bineq.data[b_k];
      }

      Simulation_xgemv_la4x4rhx(obj->nVar, obj->sizes[2], obj->Aineq.data,
        obj->ldA, x_data, obj->maxConstrWorkspace.data);
      for (b_k = 0; b_k <= mIneq; b_k++) {
        Simulation_B.u1_g = obj->maxConstrWorkspace.data[b_k];
        if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
          v = Simulation_B.u1_g;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], sizeof(real_T) << 4U);
    Simulation_xgemv_la4x4rhx(obj->nVar, 16, obj->Aeq.data, obj->ldA, x_data,
      obj->maxConstrWorkspace.data);
    for (mIneq = 0; mIneq < 16; mIneq++) {
      Simulation_B.u1_g = fabs(obj->maxConstrWorkspace.data[mIneq]);
      if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
        v = Simulation_B.u1_g;
      }
    }
  }

  if (mLB > 0) {
    for (mIneq = 0; mIneq < mLB; mIneq++) {
      Simulation_B.u1_g = -x_data[obj->indexLB.data[mIneq] - 1] - obj->
        lb.data[obj->indexLB.data[mIneq] - 1];
      if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
        v = Simulation_B.u1_g;
      }
    }
  }

  if (mUB > 0) {
    for (mLB = 0; mLB < mUB; mLB++) {
      Simulation_B.u1_g = x_data[obj->indexUB.data[mLB] - 1] - obj->ub.data
        [obj->indexUB.data[mLB] - 1];
      if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
        v = Simulation_B.u1_g;
      }
    }
  }

  if (mFixed > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      Simulation_B.u1_g = fabs(x_data[obj->indexFixed.data[mUB] - 1] -
        obj->ub.data[obj->indexFixed.data[mUB] - 1]);
      if ((!(v >= Simulation_B.u1_g)) && (!rtIsNaN(Simulation_B.u1_g))) {
        v = Simulation_B.u1_g;
      }
    }
  }

  return v;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_PresolveWorkingSet(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
  *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace,
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *qrmanager)
{
  solution->state = 82;
  Simulation_B.b_n = Simulation_RemoveDependentEq_(memspace, workingset,
    qrmanager);
  if ((Simulation_B.b_n != -1) && (workingset->nActiveConstr <= qrmanager->ldq))
  {
    boolean_T guard1 = false;
    boolean_T okWorkingSet;
    Simulation_RemoveDependentIneq_(workingset, qrmanager, memspace);
    okWorkingSet = Simulat_feasibleX0ForWorkingSet
      (memspace->workspace_double.data, memspace->workspace_double.size,
       solution->xstar.data, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      Simulati_RemoveDependentIneq__a(workingset, qrmanager, memspace);
      okWorkingSet = Simulat_feasibleX0ForWorkingSet
        (memspace->workspace_double.data, memspace->workspace_double.size,
         solution->xstar.data, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        Simulation_B.constrViolation = Simul_maxConstraintViolation_e4
          (workingset, solution->xstar.data);
        if (Simulation_B.constrViolation > 0.01) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    Simulation_removeAllIneqConstr(workingset);
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace_data[], const real_T H[441], const real_T f_data[], const
  real_T x_data[])
{
  int32_T ix;
  ix = 0;
  if (obj_hasLinear) {
    for (ix = 0; ix < obj_nvar; ix++) {
      workspace_data[ix] = f_data[ix];
    }

    ix = 1;
  }

  if (obj_nvar != 0) {
    int32_T b;
    int32_T iac;
    if (ix != 1) {
      for (ix = 0; ix < obj_nvar; ix++) {
        workspace_data[ix] = 0.0;
      }
    }

    ix = 0;
    b = (obj_nvar - 1) * obj_nvar + 1;
    iac = 1;
    while (((obj_nvar > 0) && (iac <= b)) || ((obj_nvar < 0) && (iac >= b))) {
      real_T c;
      int32_T d;
      int32_T iy;
      c = 0.5 * x_data[ix];
      iy = 0;
      d = (iac + obj_nvar) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        workspace_data[iy] += H[ia - 1] * c;
        iy++;
      }

      ix++;
      iac += obj_nvar;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_computeFval(const s_ollgpvqodLtAhexvVgD8pB_Simu_T *obj,
  real_T workspace_data[], const real_T H[441], const real_T f_data[], const
  real_T x_data[])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x_data[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    Simulation_linearForm_(obj->hasLinear, obj->nvar, workspace_data, H, f_data,
      x_data);
    val = 0.0;
    if (obj->nvar >= 1) {
      for (int32_T idx = 0; idx < obj->nvar; idx++) {
        val += workspace_data[idx] * x_data[idx];
      }
    }
    break;

   default:
    {
      int32_T idx;
      Simulation_linearForm_(obj->hasLinear, obj->nvar, workspace_data, H,
        f_data, x_data);
      for (idx = obj->nvar; idx < obj->maxVar - 1; idx++) {
        workspace_data[idx] = 0.5 * obj->beta * x_data[idx] + obj->rho;
      }

      val = 0.0;
      if (obj->maxVar - 1 >= 1) {
        for (idx = 0; idx <= obj->maxVar - 2; idx++) {
          val += workspace_data[idx] * x_data[idx];
        }
      }
    }
    break;
  }

  return val;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4rhx2(int32_T m, int32_T n, const real_T A[441],
  int32_T lda, const real_T x_data[], real_T y_data[])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iac;
    int32_T ix;
    for (ix = 0; ix < m; ix++) {
      y_data[ix] = 0.0;
    }

    ix = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = (iac + m) - 1;
      for (int32_T ia = iac; ia <= c; ia++) {
        y_data[iy] += A[ia - 1] * x_data[ix];
        iy++;
      }

      ix++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_computeGrad_StoreHx(s_ollgpvqodLtAhexvVgD8pB_Simu_T *obj,
  const real_T H[441], const real_T f_data[], const real_T x_data[])
{
  switch (obj->objtype) {
   case 5:
    for (int32_T maxRegVar = 0; maxRegVar <= obj->nvar - 2; maxRegVar++) {
      obj->grad.data[maxRegVar] = 0.0;
    }

    obj->grad.data[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    {
      int32_T maxRegVar;
      Simulation_xgemv_la4x4rhx2(obj->nvar, obj->nvar, H, obj->nvar, x_data,
        obj->Hx.data);
      for (maxRegVar = 0; maxRegVar < obj->nvar; maxRegVar++) {
        obj->grad.data[maxRegVar] = obj->Hx.data[maxRegVar];
      }

      if (obj->hasLinear && (obj->nvar >= 1)) {
        maxRegVar = obj->nvar - 1;
        for (int32_T iy = 0; iy <= maxRegVar; iy++) {
          obj->grad.data[iy] += f_data[iy];
        }
      }
    }
    break;

   default:
    {
      int32_T iy;
      int32_T maxRegVar;
      maxRegVar = obj->maxVar - 1;
      Simulation_xgemv_la4x4rhx2(obj->nvar, obj->nvar, H, obj->nvar, x_data,
        obj->Hx.data);
      for (iy = obj->nvar; iy < maxRegVar; iy++) {
        obj->Hx.data[iy] = obj->beta * x_data[iy];
      }

      for (iy = 0; iy < maxRegVar; iy++) {
        obj->grad.data[iy] = obj->Hx.data[iy];
      }

      if (obj->hasLinear && (obj->nvar >= 1)) {
        maxRegVar = obj->nvar - 1;
        for (iy = 0; iy <= maxRegVar; iy++) {
          obj->grad.data[iy] += f_data[iy];
        }
      }

      maxRegVar = (obj->maxVar - obj->nvar) - 1;
      if (maxRegVar >= 1) {
        iy = obj->nvar;
        for (int32_T c_k = 0; c_k < maxRegVar; c_k++) {
          obj->grad.data[iy] += obj->rho;
          iy++;
        }
      }
    }
    break;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_computeFval_ReuseHx(const
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *obj, real_T workspace_data[], const real_T
  f_data[], const real_T x_data[])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x_data[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T maxRegVar_tmp_tmp;
        for (maxRegVar_tmp_tmp = 0; maxRegVar_tmp_tmp < obj->nvar;
             maxRegVar_tmp_tmp++) {
          workspace_data[maxRegVar_tmp_tmp] = 0.5 * obj->
            Hx.data[maxRegVar_tmp_tmp] + f_data[maxRegVar_tmp_tmp];
        }

        val = 0.0;
        if (obj->nvar >= 1) {
          for (maxRegVar_tmp_tmp = 0; maxRegVar_tmp_tmp < obj->nvar;
               maxRegVar_tmp_tmp++) {
            val += workspace_data[maxRegVar_tmp_tmp] * x_data[maxRegVar_tmp_tmp];
          }
        }
      } else {
        val = 0.0;
        if (obj->nvar >= 1) {
          for (int32_T maxRegVar_tmp_tmp = 0; maxRegVar_tmp_tmp < obj->nvar;
               maxRegVar_tmp_tmp++) {
            val += x_data[maxRegVar_tmp_tmp] * obj->Hx.data[maxRegVar_tmp_tmp];
          }
        }

        val *= 0.5;
      }
    }
    break;

   default:
    {
      int32_T maxRegVar_tmp_tmp;
      maxRegVar_tmp_tmp = obj->maxVar - 1;
      if (obj->hasLinear) {
        int32_T d_k;
        for (d_k = 0; d_k < obj->nvar; d_k++) {
          workspace_data[d_k] = f_data[d_k];
        }

        d_k = obj->maxVar - obj->nvar;
        for (int32_T d_i = 0; d_i <= d_k - 2; d_i++) {
          workspace_data[obj->nvar + d_i] = obj->rho;
        }

        for (d_k = 0; d_k < maxRegVar_tmp_tmp; d_k++) {
          workspace_data[d_k] += 0.5 * obj->Hx.data[d_k];
        }

        val = 0.0;
        if (obj->maxVar - 1 >= 1) {
          for (maxRegVar_tmp_tmp = 0; maxRegVar_tmp_tmp <= obj->maxVar - 2;
               maxRegVar_tmp_tmp++) {
            val += workspace_data[maxRegVar_tmp_tmp] * x_data[maxRegVar_tmp_tmp];
          }
        }
      } else {
        int32_T d_k;
        val = 0.0;
        if (obj->maxVar - 1 >= 1) {
          for (d_k = 0; d_k <= obj->maxVar - 2; d_k++) {
            val += x_data[d_k] * obj->Hx.data[d_k];
          }
        }

        val *= 0.5;
        for (d_k = obj->nvar; d_k < maxRegVar_tmp_tmp; d_k++) {
          val += x_data[d_k] * obj->rho;
        }
      }
    }
    break;
  }

  return val;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T scale;
  Simulation_B.roe = *b;
  Simulation_B.absa = fabs(*a);
  Simulation_B.absb = fabs(*b);
  if (Simulation_B.absa > Simulation_B.absb) {
    Simulation_B.roe = *a;
  }

  scale = Simulation_B.absa + Simulation_B.absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = Simulation_B.absa / scale;
    bds = Simulation_B.absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (Simulation_B.roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (Simulation_B.absa > Simulation_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_deleteColMoveEnd(s_ASr52t7t39LT7rtZ8hZCX_Simul_T *obj,
  int32_T idx)
{
  int32_T i;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt.data[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt.data[idx - 1] = obj->jpvt.data[obj->ncols - 1];
    for (i = 0; i < obj->minRowCol; i++) {
      obj->QR.data[i + obj->ldq * (idx - 1)] = obj->QR.data[(obj->ncols - 1) *
        obj->ldq + i];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      int32_T QRk0;
      int32_T b_ix;
      int32_T idxRotGCol;
      int32_T ix;
      int32_T k;
      if (obj->mrows - 1 <= obj->ncols) {
        i = obj->mrows - 1;
      } else {
        i = obj->ncols;
      }

      k = i;
      idxRotGCol = (idx - 1) * obj->ldq;
      while (k >= idx) {
        QRk0 = k + idxRotGCol;
        Simulation_B.b_temp = obj->QR.data[QRk0];
        Simulation_xrotg(&obj->QR.data[(k + idxRotGCol) - 1],
                         &Simulation_B.b_temp, &Simulation_B.c_c_j,
                         &Simulation_B.b_s);
        obj->QR.data[QRk0] = Simulation_B.b_temp;
        obj->QR.data[k + obj->ldq * (k - 1)] = 0.0;
        QRk0 = obj->ldq * idx + k;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = QRk0 - 1;
          for (int32_T d_k = 0; d_k < b_ix; d_k++) {
            Simulation_B.b_temp = obj->QR.data[ix] * Simulation_B.c_c_j +
              obj->QR.data[QRk0] * Simulation_B.b_s;
            obj->QR.data[QRk0] = obj->QR.data[QRk0] * Simulation_B.c_c_j -
              obj->QR.data[ix] * Simulation_B.b_s;
            obj->QR.data[ix] = Simulation_B.b_temp;
            QRk0 += obj->ldq;
            ix += obj->ldq;
          }
        }

        QRk0 = (k - 1) * obj->ldq;
        if (obj->mrows >= 1) {
          b_ix = obj->ldq + QRk0;
          for (ix = 0; ix < obj->mrows; ix++) {
            Simulation_B.b_temp = obj->Q.data[QRk0] * Simulation_B.c_c_j +
              obj->Q.data[b_ix] * Simulation_B.b_s;
            obj->Q.data[b_ix] = obj->Q.data[b_ix] * Simulation_B.c_c_j -
              obj->Q.data[QRk0] * Simulation_B.b_s;
            obj->Q.data[QRk0] = Simulation_B.b_temp;
            b_ix++;
            QRk0++;
          }
        }

        k--;
      }

      for (k = idx + 1; k <= i; k++) {
        idxRotGCol = (k - 1) * obj->ldq;
        QRk0 = k + idxRotGCol;
        Simulation_B.b_temp = obj->QR.data[QRk0];
        Simulation_xrotg(&obj->QR.data[(k + idxRotGCol) - 1],
                         &Simulation_B.b_temp, &Simulation_B.c_c_j,
                         &Simulation_B.b_s);
        obj->QR.data[QRk0] = Simulation_B.b_temp;
        QRk0 = (obj->ldq + 1) * k;
        idxRotGCol = obj->ncols - k;
        if (idxRotGCol >= 1) {
          b_ix = QRk0 - 1;
          for (ix = 0; ix < idxRotGCol; ix++) {
            Simulation_B.b_temp = obj->QR.data[b_ix] * Simulation_B.c_c_j +
              obj->QR.data[QRk0] * Simulation_B.b_s;
            obj->QR.data[QRk0] = obj->QR.data[QRk0] * Simulation_B.c_c_j -
              obj->QR.data[b_ix] * Simulation_B.b_s;
            obj->QR.data[b_ix] = Simulation_B.b_temp;
            QRk0 += obj->ldq;
            b_ix += obj->ldq;
          }
        }

        idxRotGCol = (k - 1) * obj->ldq;
        if (obj->mrows >= 1) {
          QRk0 = obj->ldq + idxRotGCol;
          for (b_ix = 0; b_ix < obj->mrows; b_ix++) {
            Simulation_B.b_temp = obj->Q.data[idxRotGCol] * Simulation_B.c_c_j +
              obj->Q.data[QRk0] * Simulation_B.b_s;
            obj->Q.data[QRk0] = obj->Q.data[QRk0] * Simulation_B.c_c_j -
              obj->Q.data[idxRotGCol] * Simulation_B.b_s;
            obj->Q.data[idxRotGCol] = Simulation_B.b_temp;
            QRk0++;
            idxRotGCol++;
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static boolean_T Simulation_strcmp(const char_T a[7])
{
  int32_T ret;
  static const char_T b[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  ret = memcmp(&a[0], &b[0], 7);
  return ret == 0;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[441],
  int32_T lda, const real_T B_data[], int32_T ib0, int32_T ldb, real_T C_data[],
  int32_T ldc)
{
  if ((m != 0) && (n != 0)) {
    int32_T ar;
    int32_T br;
    int32_T cr;
    int32_T ib;
    int32_T lastColC;
    br = ib0;
    lastColC = (n - 1) * ldc;
    cr = 0;
    while (((ldc > 0) && (cr <= lastColC)) || ((ldc < 0) && (cr >= lastColC))) {
      ar = cr;
      ib = cr + m;
      while (ar + 1 <= ib) {
        C_data[ar] = 0.0;
        ar++;
      }

      cr += ldc;
    }

    cr = 0;
    while (((ldc > 0) && (cr <= lastColC)) || ((ldc < 0) && (cr >= lastColC))) {
      int32_T c;
      ar = -1;
      ib = br;
      c = br + k;
      while (ib <= c - 1) {
        int32_T b_ic;
        int32_T d;
        int32_T ia;
        ia = ar;
        b_ic = cr;
        d = cr + m;
        while (b_ic + 1 <= d) {
          ia++;
          C_data[b_ic] += B_data[ib - 1] * A[ia];
          b_ic++;
        }

        ar += lda;
        ib++;
      }

      br += ldb;
      cr += ldc;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemm_b(int32_T m, int32_T n, int32_T k, const real_T
  A_data[], int32_T ia0, int32_T lda, const real_T B_data[], int32_T ldb, real_T
  C_data[], int32_T ldc)
{
  if ((m != 0) && (n != 0)) {
    int32_T ar;
    int32_T b_cr;
    int32_T br;
    int32_T lastColC;
    lastColC = (n - 1) * ldc;
    br = 0;
    while (((ldc > 0) && (br <= lastColC)) || ((ldc < 0) && (br >= lastColC))) {
      b_cr = br;
      ar = br + m;
      while (b_cr + 1 <= ar) {
        C_data[b_cr] = 0.0;
        b_cr++;
      }

      br += ldc;
    }

    br = -1;
    b_cr = 0;
    while (((ldc > 0) && (b_cr <= lastColC)) || ((ldc < 0) && (b_cr >= lastColC)))
    {
      int32_T b_ic;
      int32_T c;
      ar = ia0;
      b_ic = b_cr;
      c = b_cr + m;
      while (b_ic + 1 <= c) {
        real_T temp;
        temp = 0.0;
        for (int32_T w = 1; w - 1 < k; w++) {
          temp += A_data[(w + ar) - 2] * B_data[w + br];
        }

        C_data[b_ic] += temp;
        ar += lda;
        b_ic++;
      }

      br += ldb;
      b_cr += ldc;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulation_ixamax_k(int32_T n, const real_T x_data[], int32_T
  incx)
{
  int32_T idxmax;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      int32_T ix;
      ix = 0;
      smax = fabs(x_data[0]);
      for (int32_T k = 2; k <= n; k++) {
        real_T s;
        ix += incx;
        s = fabs(x_data[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_fullColLDL2_(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj,
  int32_T LD_offset, int32_T NColsRemain)
{
  int32_T LDimSizeP1;
  LDimSizeP1 = obj->ldm;
  for (int32_T k = 0; k < NColsRemain; k++) {
    real_T alpha1;
    real_T y;
    int32_T LD_diagOffset;
    int32_T j;
    int32_T jA;
    int32_T subMatrixDim;
    LD_diagOffset = ((LDimSizeP1 + 1) * k + LD_offset) - 1;
    alpha1 = -1.0 / obj->FMat.data[LD_diagOffset];
    subMatrixDim = (NColsRemain - k) - 2;
    for (jA = 1; jA - 1 <= subMatrixDim; jA++) {
      obj->workspace_ = obj->FMat.data[LD_diagOffset + jA];
    }

    y = obj->workspace_;
    if (!(alpha1 == 0.0)) {
      jA = (LD_diagOffset + LDimSizeP1) + 1;
      for (j = 0; j <= subMatrixDim; j++) {
        if (y != 0.0) {
          real_T temp;
          int32_T b;
          int32_T ijA;
          temp = y * alpha1;
          ijA = jA;
          b = subMatrixDim + jA;
          while (ijA + 1 <= b + 1) {
            obj->FMat.data[ijA] += obj->workspace_ * temp;
            ijA++;
          }
        }

        jA += obj->ldm;
      }
    }

    for (jA = 1; jA - 1 <= subMatrixDim; jA++) {
      j = LD_diagOffset + jA;
      obj->FMat.data[j] /= obj->FMat.data[LD_diagOffset];
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_partialColLDL3_(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj,
  int32_T LD_offset, int32_T NColsRemain)
{
  int32_T FMat_offset;
  int32_T LD_diagOffset;
  int32_T LDimSizeP1;
  int32_T br;
  int32_T d;
  int32_T ia;
  int32_T idx;
  int32_T ix;
  int32_T k;
  int32_T subRows;
  LDimSizeP1 = obj->ldm + 1;
  for (k = 0; k < 48; k++) {
    subRows = (NColsRemain - k) - 1;
    LD_diagOffset = (LDimSizeP1 * k + LD_offset) - 1;
    for (idx = 0; idx <= subRows; idx++) {
      obj->workspace_ = obj->FMat.data[LD_diagOffset + idx];
    }

    for (idx = 0; idx < NColsRemain; idx++) {
      obj->workspace2_ = obj->workspace_;
    }

    idx = obj->ldm;
    Simulation_B.y_p = obj->workspace2_;
    if ((NColsRemain != 0) && (k != 0)) {
      ix = LD_offset + k;
      FMat_offset = (k - 1) * obj->ldm + 1;
      br = 1;
      while (((idx > 0) && (br <= FMat_offset)) || ((idx < 0) && (br >=
               FMat_offset))) {
        d = (br + NColsRemain) - 1;
        for (ia = br; ia <= d; ia++) {
          Simulation_B.y_p += -obj->FMat.data[ix - 1] * obj->workspace_;
        }

        ix += obj->ldm;
        br += idx;
      }
    }

    obj->workspace2_ = Simulation_B.y_p;
    for (idx = 0; idx < NColsRemain; idx++) {
      obj->workspace_ = Simulation_B.y_p;
    }

    for (idx = 0; idx <= subRows; idx++) {
      obj->FMat.data[LD_diagOffset + idx] = obj->workspace_;
    }

    for (idx = 1; idx - 1 < subRows; idx++) {
      ix = LD_diagOffset + idx;
      obj->FMat.data[ix] /= obj->FMat.data[LD_diagOffset];
    }
  }

  for (k = 48; k <= NColsRemain - 1; k += 48) {
    int32_T ic;
    int32_T iy;
    LD_diagOffset = NColsRemain - k;
    if (48 <= LD_diagOffset) {
      subRows = 48;
    } else {
      subRows = LD_diagOffset;
    }

    idx = k + subRows;
    for (ix = k; ix < idx; ix++) {
      FMat_offset = idx - ix;
      br = (LDimSizeP1 * ix + LD_offset) - 1;
      for (d = 0; d < 48; d++) {
        obj->workspace2_ = obj->FMat.data[((LD_offset + ix) + d * obj->ldm) - 1];
      }

      d = obj->ldm;
      if (FMat_offset != 0) {
        ia = (obj->ldm * 47 + ix) + 1;
        ic = ix + 1;
        while (((d > 0) && (ic <= ia)) || ((d < 0) && (ic >= ia))) {
          int32_T f;
          iy = br;
          f = (ic + FMat_offset) - 1;
          for (int32_T b_ia = ic; b_ia <= f; b_ia++) {
            obj->FMat.data[iy] += obj->workspace_ * -obj->workspace2_;
            iy++;
          }

          ic += d;
        }
      }
    }

    if (idx < NColsRemain) {
      LD_diagOffset -= subRows;
      idx = ((LD_offset + subRows) + LDimSizeP1 * k) - 1;
      for (ix = 0; ix < 48; ix++) {
        FMat_offset = (LD_offset + k) + ix * obj->ldm;
        for (br = 0; br < subRows; br++) {
          obj->workspace2_ = obj->FMat.data[(FMat_offset + br) - 1];
        }
      }

      ix = obj->ldm;
      FMat_offset = obj->ldm;
      if ((LD_diagOffset != 0) && (subRows != 0)) {
        subRows = (subRows - 1) * obj->ldm + idx;
        br = 0;
        while (((FMat_offset > 0) && (idx <= subRows)) || ((FMat_offset < 0) &&
                (idx >= subRows))) {
          br++;
          d = ix * 47 + br;
          ia = br;
          while (((ix > 0) && (ia <= d)) || ((ix < 0) && (ia >= d))) {
            ic = idx;
            iy = idx + LD_diagOffset;
            while (ic + 1 <= iy) {
              obj->FMat.data[ic] += -obj->workspace2_ * obj->workspace_;
              ic++;
            }

            ia += ix;
          }

          idx += FMat_offset;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static int32_T Simulation_xpotrf(int32_T n, real_T A_data[], int32_T lda)
{
  int32_T b_j;
  int32_T info;
  boolean_T exitg1;
  info = 0;
  b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (b_j <= n - 1)) {
    int32_T b_ix;
    int32_T b_iy;
    int32_T idxA1j;
    int32_T idxAjj;
    int32_T iy;
    idxA1j = b_j * lda;
    idxAjj = idxA1j + b_j;
    Simulation_B.ssq = 0.0;
    if (b_j >= 1) {
      b_ix = idxA1j;
      b_iy = idxA1j;
      for (iy = 0; iy < b_j; iy++) {
        Simulation_B.ssq += A_data[b_ix] * A_data[b_iy];
        b_ix++;
        b_iy++;
      }
    }

    Simulation_B.ssq = A_data[idxAjj] - Simulation_B.ssq;
    if (Simulation_B.ssq > 0.0) {
      Simulation_B.ssq = sqrt(Simulation_B.ssq);
      A_data[idxAjj] = Simulation_B.ssq;
      if (b_j + 1 < n) {
        b_ix = (n - b_j) - 2;
        b_iy = (idxA1j + lda) + 1;
        idxAjj += lda;
        if ((b_j != 0) && (b_ix + 1 != 0)) {
          int32_T b;
          iy = idxAjj;
          b = lda * b_ix + b_iy;
          while (((lda > 0) && (b_iy <= b)) || ((lda < 0) && (b_iy >= b))) {
            int32_T d;
            int32_T ix;
            ix = idxA1j;
            Simulation_B.c_ao = 0.0;
            d = (b_iy + b_j) - 1;
            for (int32_T ia = b_iy; ia <= d; ia++) {
              Simulation_B.c_ao += A_data[ia - 1] * A_data[ix];
              ix++;
            }

            A_data[iy] += -Simulation_B.c_ao;
            iy += lda;
            b_iy += lda;
          }
        }

        Simulation_B.ssq = 1.0 / Simulation_B.ssq;
        idxA1j = (lda * b_ix + idxAjj) + 1;
        b_ix = idxAjj + 1;
        while (((lda > 0) && (b_ix <= idxA1j)) || ((lda < 0) && (b_ix >= idxA1j)))
        {
          A_data[b_ix - 1] *= Simulation_B.ssq;
          b_ix += lda;
        }
      }

      b_j++;
    } else {
      A_data[idxAjj] = Simulation_B.ssq;
      info = b_j + 1;
      exitg1 = true;
    }
  }

  return info;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4rhx2l(int32_T m, int32_T n, const real_T
  A_data[], int32_T ia0, int32_T lda, const real_T x_data[], real_T y_data[])
{
  if (m != 0) {
    int32_T b;
    int32_T iac;
    int32_T ix;
    for (ix = 0; ix < m; ix++) {
      y_data[ix] = 0.0;
    }

    ix = 0;
    b = (n - 1) * lda + ia0;
    iac = ia0;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = (iac + m) - 1;
      for (int32_T ia = iac; ia <= c; ia++) {
        y_data[iy] += A_data[ia - 1] * x_data[ix];
        iy++;
      }

      ix++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_factor(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj, const real_T
  A[441], int32_T ndims, int32_T ldA)
{
  obj->ndims = ndims;
  for (int32_T b_idx = 0; b_idx < ndims; b_idx++) {
    int32_T ix0;
    int32_T iy0;
    ix0 = ldA * b_idx;
    iy0 = obj->ldm * b_idx;
    for (int32_T k = 1; k - 1 < ndims; k++) {
      obj->FMat.data[(iy0 + k) - 1] = A[(ix0 + k) - 1];
    }
  }

  obj->info = Simulation_xpotrf(ndims, obj->FMat.data, obj->ldm);
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_solve(const s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj, real_T
  rhs_data[])
{
  if (obj->ndims != 0) {
    int32_T b_j;
    int32_T c_i;
    int32_T jjA;
    for (b_j = 0; b_j < obj->ndims; b_j++) {
      real_T temp;
      jjA = b_j * obj->ldm;
      temp = rhs_data[b_j];
      for (c_i = 0; c_i < b_j; c_i++) {
        temp -= obj->FMat.data[jjA + c_i] * rhs_data[c_i];
      }

      rhs_data[b_j] = temp / obj->FMat.data[jjA + b_j];
    }

    for (b_j = obj->ndims - 1; b_j + 1 > 0; b_j--) {
      jjA = b_j * obj->ldm + b_j;
      rhs_data[b_j] /= obj->FMat.data[jjA];
      for (c_i = 1; c_i - 1 < b_j; c_i++) {
        int32_T ix;
        ix = b_j - c_i;
        rhs_data[ix] -= obj->FMat.data[jjA - c_i] * rhs_data[b_j];
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_factor_b(s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj, const
  real_T A[441], int32_T ndims, int32_T ldA)
{
  Simulation_B.LDimSizeP1_tmp_tmp = obj->ldm + 1;
  obj->ndims = ndims;
  Simulation_B.A_maxDiag_idx_d = 0;
  while (Simulation_B.A_maxDiag_idx_d <= ndims - 1) {
    Simulation_B.LD_diagOffset_j = ldA * Simulation_B.A_maxDiag_idx_d;
    Simulation_B.order_i = obj->ldm * Simulation_B.A_maxDiag_idx_d;
    Simulation_B.b_k_h2 = 1;
    while (Simulation_B.b_k_h2 - 1 <= ndims - 1) {
      obj->FMat.data[(Simulation_B.order_i + Simulation_B.b_k_h2) - 1] = A
        [(Simulation_B.LD_diagOffset_j + Simulation_B.b_k_h2) - 1];
      Simulation_B.b_k_h2++;
    }

    Simulation_B.A_maxDiag_idx_d++;
  }

  Simulation_B.A_maxDiag_idx_d = Simulation_ixamax_k(ndims, obj->FMat.data,
    obj->ldm + 1) - 1;
  Simulation_B.u0 = fabs(obj->FMat.data[obj->ldm * Simulation_B.A_maxDiag_idx_d
    + Simulation_B.A_maxDiag_idx_d]) * 2.2204460492503131E-16;
  if (Simulation_B.u0 >= 0.0) {
    obj->regTol_ = Simulation_B.u0;
  } else {
    obj->regTol_ = 0.0;
  }

  if ((obj->FMat.size[0] * obj->FMat.size[1] > 16384) && (ndims > 128)) {
    boolean_T exitg1;
    Simulation_B.A_maxDiag_idx_d = 0;
    exitg1 = false;
    while ((!exitg1) && (Simulation_B.A_maxDiag_idx_d < ndims)) {
      Simulation_B.LD_diagOffset_j = Simulation_B.LDimSizeP1_tmp_tmp *
        Simulation_B.A_maxDiag_idx_d + 1;
      Simulation_B.order_i = ndims - Simulation_B.A_maxDiag_idx_d;
      if (Simulation_B.A_maxDiag_idx_d + 48 <= ndims) {
        Simulation_partialColLDL3_(obj, Simulation_B.LD_diagOffset_j,
          Simulation_B.order_i);
        Simulation_B.A_maxDiag_idx_d += 48;
      } else {
        Simulation_fullColLDL2_(obj, Simulation_B.LD_diagOffset_j,
          Simulation_B.order_i);
        exitg1 = true;
      }
    }
  } else {
    Simulation_fullColLDL2_(obj, 1, ndims);
  }

  if (obj->ConvexCheck) {
    Simulation_B.LDimSizeP1_tmp_tmp = 0;
    int32_T exitg2;
    do {
      exitg2 = 0;
      if (Simulation_B.LDimSizeP1_tmp_tmp <= ndims - 1) {
        if (obj->FMat.data[obj->ldm * Simulation_B.LDimSizeP1_tmp_tmp +
            Simulation_B.LDimSizeP1_tmp_tmp] <= 0.0) {
          obj->info = -Simulation_B.LDimSizeP1_tmp_tmp - 1;
          exitg2 = 1;
        } else {
          Simulation_B.LDimSizeP1_tmp_tmp++;
        }
      } else {
        obj->ConvexCheck = false;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_solve_b(const s_scny3ZL5wSoGnQzGbzQQC_Simul_T *obj,
  real_T rhs_data[])
{
  int32_T jA;
  int32_T jjA;
  int32_T n_tmp;
  n_tmp = obj->ndims - 1;
  if (obj->ndims != 0) {
    for (jA = 0; jA <= n_tmp; jA++) {
      int32_T b;
      jjA = jA * obj->ldm + jA;
      b = n_tmp - jA;
      for (int32_T i = 1; i - 1 < b; i++) {
        int32_T ix;
        ix = jA + i;
        rhs_data[ix] -= obj->FMat.data[jjA + i] * rhs_data[jA];
      }
    }
  }

  for (jA = 0; jA <= n_tmp; jA++) {
    rhs_data[jA] /= obj->FMat.data[obj->ldm * jA + jA];
  }

  if (obj->ndims != 0) {
    for (n_tmp = obj->ndims - 1; n_tmp + 1 > 0; n_tmp--) {
      real_T temp;
      jA = n_tmp * obj->ldm;
      temp = rhs_data[n_tmp];
      for (jjA = obj->ndims; jjA >= n_tmp + 2; jjA--) {
        temp -= obj->FMat.data[(jA + jjA) - 1] * rhs_data[jjA - 1];
      }

      rhs_data[n_tmp] = temp;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_compute_deltax(const real_T H[441],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, const s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *cholmanager, const
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective, boolean_T alwaysPositiveDef)
{
  Simulation_B.nVar_g = qrmanager->mrows - 1;
  Simulation_B.mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (Simulation_B.mNull_tmp <= 0) {
    Simulation_B.mNull_tmp = 0;
    while (Simulation_B.mNull_tmp <= Simulation_B.nVar_g) {
      solution->searchDir.data[Simulation_B.mNull_tmp] = 0.0;
      Simulation_B.mNull_tmp++;
    }
  } else {
    Simulation_B.c_idx_l = 0;
    while (Simulation_B.c_idx_l <= Simulation_B.nVar_g) {
      solution->searchDir.data[Simulation_B.c_idx_l] = -objective->
        grad.data[Simulation_B.c_idx_l];
      Simulation_B.c_idx_l++;
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        if (alwaysPositiveDef) {
          Simulation_factor(cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        } else {
          Simulation_factor_b(cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else if (alwaysPositiveDef) {
          Simulation_solve(cholmanager, solution->searchDir.data);
        } else {
          Simulation_solve_b(cholmanager, solution->searchDir.data);
        }
        break;

       default:
        if (alwaysPositiveDef) {
          Simulation_factor(cholmanager, H, objective->nvar, objective->nvar);
          if (cholmanager->info != 0) {
            solution->state = -6;
          } else {
            Simulation_solve(cholmanager, solution->searchDir.data);
            Simulation_B.c_p = 1.0 / objective->beta;
            Simulation_B.mNull_tmp = objective->nvar;
            while (Simulation_B.mNull_tmp + 1 <= qrmanager->mrows) {
              solution->searchDir.data[Simulation_B.mNull_tmp] *=
                Simulation_B.c_p;
              Simulation_B.mNull_tmp++;
            }
          }
        }
        break;
      }
    } else {
      Simulation_B.c_idx_l = qrmanager->ldq * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        Simulation_B.b_ldw = 0;
        while (Simulation_B.b_ldw <= Simulation_B.mNull_tmp - 1) {
          memspace->workspace_double.data[Simulation_B.b_ldw] =
            -qrmanager->Q.data[(qrmanager->ncols + Simulation_B.b_ldw) *
            qrmanager->ldq + Simulation_B.nVar_g];
          Simulation_B.b_ldw++;
        }

        Simulation_xgemv_la4x4rhx2l(qrmanager->mrows, Simulation_B.mNull_tmp,
          qrmanager->Q.data, Simulation_B.c_idx_l, qrmanager->ldq,
          memspace->workspace_double.data, solution->searchDir.data);
      } else {
        if (objective->objtype == 3) {
          Simulation_B.b_ldw = memspace->workspace_double.size[0];
          Simulation_xgemm(qrmanager->mrows, Simulation_B.mNull_tmp,
                           qrmanager->mrows, H, qrmanager->mrows,
                           qrmanager->Q.data, Simulation_B.c_idx_l,
                           qrmanager->ldq, memspace->workspace_double.data,
                           memspace->workspace_double.size[0]);
          Simulation_xgemm_b(Simulation_B.mNull_tmp, Simulation_B.mNull_tmp,
                             qrmanager->mrows, qrmanager->Q.data,
                             Simulation_B.c_idx_l, qrmanager->ldq,
                             memspace->workspace_double.data, Simulation_B.b_ldw,
                             cholmanager->FMat.data, cholmanager->ldm);
        } else if (alwaysPositiveDef) {
          Simulation_B.b_ldw = memspace->workspace_double.size[0];
          Simulation_xgemm(objective->nvar, Simulation_B.mNull_tmp,
                           objective->nvar, H, objective->nvar,
                           qrmanager->Q.data, Simulation_B.c_idx_l,
                           qrmanager->ldq, memspace->workspace_double.data,
                           memspace->workspace_double.size[0]);
          Simulation_B.A_maxDiag_idx = 0;
          while (Simulation_B.A_maxDiag_idx <= Simulation_B.mNull_tmp - 1) {
            Simulation_B.LD_diagOffset = objective->nvar;
            while (Simulation_B.LD_diagOffset + 1 <= qrmanager->mrows) {
              memspace->workspace_double.data[Simulation_B.LD_diagOffset +
                memspace->workspace_double.size[0] * Simulation_B.A_maxDiag_idx]
                = qrmanager->Q.data[(Simulation_B.A_maxDiag_idx +
                qrmanager->ncols) * qrmanager->Q.size[0] +
                Simulation_B.LD_diagOffset] * objective->beta;
              Simulation_B.LD_diagOffset++;
            }

            Simulation_B.A_maxDiag_idx++;
          }

          Simulation_xgemm_b(Simulation_B.mNull_tmp, Simulation_B.mNull_tmp,
                             qrmanager->mrows, qrmanager->Q.data,
                             Simulation_B.c_idx_l, qrmanager->ldq,
                             memspace->workspace_double.data, Simulation_B.b_ldw,
                             cholmanager->FMat.data, cholmanager->ldm);
        }

        if (alwaysPositiveDef) {
          cholmanager->ndims = Simulation_B.mNull_tmp;
          cholmanager->info = Simulation_xpotrf(Simulation_B.mNull_tmp,
            cholmanager->FMat.data, cholmanager->ldm);
        } else {
          Simulation_B.b_ldw = cholmanager->ldm + 1;
          cholmanager->ndims = Simulation_B.mNull_tmp;
          Simulation_B.A_maxDiag_idx = Simulation_ixamax_k
            (Simulation_B.mNull_tmp, cholmanager->FMat.data, cholmanager->ldm +
             1) - 1;
          Simulation_B.c_p = fabs(cholmanager->FMat.data[cholmanager->ldm *
            Simulation_B.A_maxDiag_idx + Simulation_B.A_maxDiag_idx]) *
            2.2204460492503131E-16;
          if (Simulation_B.c_p >= 0.0) {
            cholmanager->regTol_ = Simulation_B.c_p;
          } else {
            cholmanager->regTol_ = 0.0;
          }

          if ((cholmanager->FMat.size[0] * cholmanager->FMat.size[1] > 16384) &&
              (Simulation_B.mNull_tmp > 128)) {
            boolean_T exitg1;
            Simulation_B.A_maxDiag_idx = 0;
            exitg1 = false;
            while ((!exitg1) && (Simulation_B.A_maxDiag_idx <
                                 Simulation_B.mNull_tmp)) {
              Simulation_B.LD_diagOffset = Simulation_B.b_ldw *
                Simulation_B.A_maxDiag_idx + 1;
              Simulation_B.order = Simulation_B.mNull_tmp -
                Simulation_B.A_maxDiag_idx;
              if (Simulation_B.A_maxDiag_idx + 48 <= Simulation_B.mNull_tmp) {
                Simulation_partialColLDL3_(cholmanager,
                  Simulation_B.LD_diagOffset, Simulation_B.order);
                Simulation_B.A_maxDiag_idx += 48;
              } else {
                Simulation_fullColLDL2_(cholmanager, Simulation_B.LD_diagOffset,
                  Simulation_B.order);
                exitg1 = true;
              }
            }
          } else {
            Simulation_fullColLDL2_(cholmanager, 1, Simulation_B.mNull_tmp);
          }

          if (cholmanager->ConvexCheck) {
            Simulation_B.b_ldw = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (Simulation_B.b_ldw <= Simulation_B.mNull_tmp - 1) {
                if (cholmanager->FMat.data[cholmanager->ldm * Simulation_B.b_ldw
                    + Simulation_B.b_ldw] <= 0.0) {
                  cholmanager->info = -Simulation_B.b_ldw - 1;
                  exitg2 = 1;
                } else {
                  Simulation_B.b_ldw++;
                }
              } else {
                cholmanager->ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          Simulation_B.b_ldw = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            Simulation_B.A_maxDiag_idx = 0;
            while (Simulation_B.A_maxDiag_idx <= Simulation_B.mNull_tmp - 1) {
              memspace->workspace_double.data[Simulation_B.A_maxDiag_idx] = 0.0;
              Simulation_B.A_maxDiag_idx++;
            }

            Simulation_B.A_maxDiag_idx = 0;
            Simulation_B.LD_diagOffset = (Simulation_B.mNull_tmp - 1) *
              qrmanager->ldq + Simulation_B.c_idx_l;
            Simulation_B.order = Simulation_B.c_idx_l;
            while (((Simulation_B.b_ldw > 0) && (Simulation_B.order <=
                     Simulation_B.LD_diagOffset)) || ((Simulation_B.b_ldw < 0) &&
                    (Simulation_B.order >= Simulation_B.LD_diagOffset))) {
              Simulation_B.ix_f1 = 0;
              Simulation_B.c_p = 0.0;
              Simulation_B.rhs_size_idx_0 = Simulation_B.order +
                Simulation_B.nVar_g;
              Simulation_B.rhs_size_idx_1 = Simulation_B.order;
              while (Simulation_B.rhs_size_idx_1 <= Simulation_B.rhs_size_idx_0)
              {
                Simulation_B.c_p += qrmanager->
                  Q.data[Simulation_B.rhs_size_idx_1 - 1] * objective->
                  grad.data[Simulation_B.ix_f1];
                Simulation_B.ix_f1++;
                Simulation_B.rhs_size_idx_1++;
              }

              memspace->workspace_double.data[Simulation_B.A_maxDiag_idx] +=
                -Simulation_B.c_p;
              Simulation_B.A_maxDiag_idx++;
              Simulation_B.order += Simulation_B.b_ldw;
            }
          }

          if (alwaysPositiveDef) {
            Simulation_B.rhs_size_idx_0 = memspace->workspace_double.size[0];
            Simulation_B.rhs_size_idx_1 = memspace->workspace_double.size[1];
            Simulation_B.b_ldw = memspace->workspace_double.size[0] *
              memspace->workspace_double.size[1];
            if (0 <= Simulation_B.b_ldw - 1) {
              memcpy(&Simulation_B.rhs_data[0], &memspace->
                     workspace_double.data[0], Simulation_B.b_ldw * sizeof
                     (real_T));
            }

            if (cholmanager->ndims != 0) {
              Simulation_B.nVar_g = 0;
              while (Simulation_B.nVar_g <= cholmanager->ndims - 1) {
                Simulation_B.b_ldw = Simulation_B.nVar_g * cholmanager->ldm;
                Simulation_B.c_p = Simulation_B.rhs_data[Simulation_B.nVar_g];
                Simulation_B.A_maxDiag_idx = 0;
                while (Simulation_B.A_maxDiag_idx <= Simulation_B.nVar_g - 1) {
                  Simulation_B.c_p -= cholmanager->FMat.data[Simulation_B.b_ldw
                    + Simulation_B.A_maxDiag_idx] *
                    Simulation_B.rhs_data[Simulation_B.A_maxDiag_idx];
                  Simulation_B.A_maxDiag_idx++;
                }

                Simulation_B.rhs_data[Simulation_B.nVar_g] = Simulation_B.c_p /
                  cholmanager->FMat.data[Simulation_B.b_ldw +
                  Simulation_B.nVar_g];
                Simulation_B.nVar_g++;
              }
            }

            memspace->workspace_double.size[1] = Simulation_B.rhs_size_idx_1;
            Simulation_B.b_ldw = Simulation_B.rhs_size_idx_0 *
              Simulation_B.rhs_size_idx_1;
            if (0 <= Simulation_B.b_ldw - 1) {
              memcpy(&memspace->workspace_double.data[0],
                     &Simulation_B.rhs_data[0], Simulation_B.b_ldw * sizeof
                     (real_T));
            }

            Simulation_xtrsv(cholmanager->ndims, cholmanager->FMat.data,
                             cholmanager->ldm, memspace->workspace_double.data);
          } else {
            Simulation_B.rhs_size_idx_0 = memspace->workspace_double.size[0];
            Simulation_B.rhs_size_idx_1 = memspace->workspace_double.size[1];
            Simulation_B.b_ldw = memspace->workspace_double.size[0] *
              memspace->workspace_double.size[1];
            if (0 <= Simulation_B.b_ldw - 1) {
              memcpy(&Simulation_B.rhs_data[0], &memspace->
                     workspace_double.data[0], Simulation_B.b_ldw * sizeof
                     (real_T));
            }

            Simulation_B.nVar_g = cholmanager->ndims - 1;
            if (cholmanager->ndims != 0) {
              Simulation_B.b_ldw = 0;
              while (Simulation_B.b_ldw <= Simulation_B.nVar_g) {
                Simulation_B.A_maxDiag_idx = Simulation_B.b_ldw *
                  cholmanager->ldm + Simulation_B.b_ldw;
                Simulation_B.LD_diagOffset = Simulation_B.nVar_g -
                  Simulation_B.b_ldw;
                Simulation_B.order = 1;
                while (Simulation_B.order - 1 <= Simulation_B.LD_diagOffset - 1)
                {
                  Simulation_B.ix_f1 = Simulation_B.b_ldw + Simulation_B.order;
                  Simulation_B.rhs_data[Simulation_B.ix_f1] -=
                    cholmanager->FMat.data[Simulation_B.A_maxDiag_idx +
                    Simulation_B.order] *
                    Simulation_B.rhs_data[Simulation_B.b_ldw];
                  Simulation_B.order++;
                }

                Simulation_B.b_ldw++;
              }
            }

            Simulation_B.b_ldw = 0;
            while (Simulation_B.b_ldw <= Simulation_B.nVar_g) {
              Simulation_B.rhs_data[Simulation_B.b_ldw] /=
                cholmanager->FMat.data[cholmanager->ldm * Simulation_B.b_ldw +
                Simulation_B.b_ldw];
              Simulation_B.b_ldw++;
            }

            if (cholmanager->ndims != 0) {
              Simulation_B.nVar_g = cholmanager->ndims - 1;
              while (Simulation_B.nVar_g + 1 > 0) {
                Simulation_B.b_ldw = Simulation_B.nVar_g * cholmanager->ldm;
                Simulation_B.c_p = Simulation_B.rhs_data[Simulation_B.nVar_g];
                Simulation_B.A_maxDiag_idx = cholmanager->ndims;
                while (Simulation_B.A_maxDiag_idx >= Simulation_B.nVar_g + 2) {
                  Simulation_B.c_p -= cholmanager->FMat.data[(Simulation_B.b_ldw
                    + Simulation_B.A_maxDiag_idx) - 1] *
                    Simulation_B.rhs_data[Simulation_B.A_maxDiag_idx - 1];
                  Simulation_B.A_maxDiag_idx--;
                }

                Simulation_B.rhs_data[Simulation_B.nVar_g] = Simulation_B.c_p;
                Simulation_B.nVar_g--;
              }
            }

            memspace->workspace_double.size[1] = Simulation_B.rhs_size_idx_1;
            Simulation_B.b_ldw = Simulation_B.rhs_size_idx_0 *
              Simulation_B.rhs_size_idx_1;
            if (0 <= Simulation_B.b_ldw - 1) {
              memcpy(&memspace->workspace_double.data[0],
                     &Simulation_B.rhs_data[0], Simulation_B.b_ldw * sizeof
                     (real_T));
            }
          }

          Simulation_xgemv_la4x4rhx2l(qrmanager->mrows, Simulation_B.mNull_tmp,
            qrmanager->Q.data, Simulation_B.c_idx_l, qrmanager->ldq,
            memspace->workspace_double.data, solution->searchDir.data);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_xnrm2_e(int32_T n, const real_T x_data[])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x_data[0]);
    } else {
      Simulation_B.scale_h = 3.3121686421112381E-170;
      for (int32_T k = 0; k < n; k++) {
        real_T absxk;
        absxk = fabs(x_data[k]);
        if (absxk > Simulation_B.scale_h) {
          real_T t;
          t = Simulation_B.scale_h / absxk;
          y = y * t * t + 1.0;
          Simulation_B.scale_h = absxk;
        } else {
          real_T t;
          t = absxk / Simulation_B.scale_h;
          y += t * t;
        }
      }

      y = Simulation_B.scale_h * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_xgemv_la4x4rhx2l0(int32_T m, int32_T n, const real_T
  A_data[], int32_T lda, const real_T x_data[], real_T y_data[])
{
  if (n != 0) {
    int32_T b;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    b_iy = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T d;
      int32_T ix;
      ix = 0;
      Simulation_B.c_a = 0.0;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        Simulation_B.c_a += A_data[ia - 1] * x_data[ix];
        ix++;
      }

      y_data[b_iy] += Simulation_B.c_a;
      b_iy++;
      iac += lda;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_feasibleratiotest(const real_T solution_xstar_data[],
  const real_T solution_searchDir_data[], real_T workspace_data[], const int32_T
  workspace_size[2], int32_T workingset_nVar, int32_T workingset_ldA, const
  real_T workingset_Aineq_data[], const real_T workingset_bineq_data[], const
  real_T workingset_lb_data[], const real_T workingset_ub_data[], const int32_T
  workingset_indexLB_data[], const int32_T workingset_indexUB_data[], const
  int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const
  boolean_T workingset_isActiveConstr_data[], const int32_T workingset_nWConstr
  [5], boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
  *constrType, int32_T *constrIdx)
{
  int32_T totalIneq;
  totalIneq = workingset_sizes[2] - 1;
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  Simulation_B.denomTol = 2.2204460492503131E-13 * Simulation_xnrm2_e
    (workingset_nVar, solution_searchDir_data);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    int32_T b_iy;
    int32_T iyend;
    int32_T ldw;
    for (ldw = 0; ldw <= totalIneq; ldw++) {
      workspace_data[ldw] = workingset_bineq_data[ldw];
    }

    Simulation_xgemv_la4x4rhx2l0(workingset_nVar, workingset_sizes[2],
      workingset_Aineq_data, workingset_ldA, solution_xstar_data, workspace_data);
    ldw = workspace_size[0];
    if (workingset_sizes[2] != 0) {
      int32_T iac;
      iyend = workspace_size[0] + workingset_sizes[2];
      for (b_iy = workspace_size[0]; b_iy < iyend; b_iy++) {
        workspace_data[b_iy] = 0.0;
      }

      iyend = workspace_size[0];
      b_iy = (workingset_sizes[2] - 1) * workingset_ldA + 1;
      iac = 1;
      while (((workingset_ldA > 0) && (iac <= b_iy)) || ((workingset_ldA < 0) &&
              (iac >= b_iy))) {
        int32_T d;
        int32_T ix;
        ix = 0;
        Simulation_B.c_p4 = 0.0;
        d = (iac + workingset_nVar) - 1;
        for (int32_T ia = iac; ia <= d; ia++) {
          Simulation_B.c_p4 += workingset_Aineq_data[ia - 1] *
            solution_searchDir_data[ix];
          ix++;
        }

        workspace_data[iyend] += Simulation_B.c_p4;
        iyend++;
        iac += workingset_ldA;
      }
    }

    for (iyend = 0; iyend <= totalIneq; iyend++) {
      b_iy = ldw + iyend;
      if ((workspace_data[b_iy] > Simulation_B.denomTol) &&
          (!workingset_isActiveConstr_data[(workingset_isActiveIdx[2] + iyend) -
           1])) {
        Simulation_B.c_p4 = fabs(workspace_data[iyend]);
        Simulation_B.phaseOneCorrectionX = 0.01 - workspace_data[iyend];
        if ((Simulation_B.c_p4 <= Simulation_B.phaseOneCorrectionX) || rtIsNaN
            (Simulation_B.phaseOneCorrectionX)) {
          Simulation_B.phaseOneCorrectionX = Simulation_B.c_p4;
        }

        Simulation_B.c_p4 = Simulation_B.phaseOneCorrectionX /
          workspace_data[b_iy];
        if (Simulation_B.c_p4 < *alpha) {
          *alpha = Simulation_B.c_p4;
          *constrType = 3;
          *constrIdx = iyend + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    Simulation_B.phaseOneCorrectionX = solution_xstar_data[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    Simulation_B.phaseOneCorrectionP = solution_searchDir_data[workingset_nVar -
      1] * static_cast<real_T>(isPhaseOne);
    for (totalIneq = 0; totalIneq <= workingset_sizes[3] - 2; totalIneq++) {
      Simulation_B.pk_corrected =
        -solution_searchDir_data[workingset_indexLB_data[totalIneq] - 1] -
        Simulation_B.phaseOneCorrectionP;
      if ((Simulation_B.pk_corrected > Simulation_B.denomTol) &&
          (!workingset_isActiveConstr_data[(workingset_isActiveIdx[3] +
            totalIneq) - 1])) {
        Simulation_B.ratio =
          (-solution_xstar_data[workingset_indexLB_data[totalIneq] - 1] -
           workingset_lb_data[workingset_indexLB_data[totalIneq] - 1]) -
          Simulation_B.phaseOneCorrectionX;
        Simulation_B.c_p4 = fabs(Simulation_B.ratio);
        if ((!(Simulation_B.c_p4 <= 0.01 - Simulation_B.ratio)) && (!rtIsNaN
             (0.01 - Simulation_B.ratio))) {
          Simulation_B.c_p4 = 0.01 - Simulation_B.ratio;
        }

        Simulation_B.c_p4 /= Simulation_B.pk_corrected;
        if (Simulation_B.c_p4 < *alpha) {
          *alpha = Simulation_B.c_p4;
          *constrType = 4;
          *constrIdx = totalIneq + 1;
          *newBlocking = true;
        }
      }
    }

    totalIneq = workingset_indexLB_data[workingset_sizes[3] - 1] - 1;
    Simulation_B.phaseOneCorrectionX = -solution_searchDir_data[totalIneq];
    if ((Simulation_B.phaseOneCorrectionX > Simulation_B.denomTol) &&
        (!workingset_isActiveConstr_data[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      Simulation_B.ratio = -solution_xstar_data[totalIneq] -
        workingset_lb_data[totalIneq];
      Simulation_B.c_p4 = fabs(Simulation_B.ratio);
      if ((!(Simulation_B.c_p4 <= 0.01 - Simulation_B.ratio)) && (!rtIsNaN(0.01
            - Simulation_B.ratio))) {
        Simulation_B.c_p4 = 0.01 - Simulation_B.ratio;
      }

      Simulation_B.c_p4 /= Simulation_B.phaseOneCorrectionX;
      if (Simulation_B.c_p4 < *alpha) {
        *alpha = Simulation_B.c_p4;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    Simulation_B.phaseOneCorrectionX = solution_xstar_data[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    Simulation_B.phaseOneCorrectionP = solution_searchDir_data[workingset_nVar -
      1] * static_cast<real_T>(isPhaseOne);
    for (totalIneq = 0; totalIneq < workingset_sizes[4]; totalIneq++) {
      Simulation_B.pk_corrected =
        solution_searchDir_data[workingset_indexUB_data[totalIneq] - 1] -
        Simulation_B.phaseOneCorrectionP;
      if ((Simulation_B.pk_corrected > Simulation_B.denomTol) &&
          (!workingset_isActiveConstr_data[(workingset_isActiveIdx[4] +
            totalIneq) - 1])) {
        Simulation_B.ratio =
          (solution_xstar_data[workingset_indexUB_data[totalIneq] - 1] -
           workingset_ub_data[workingset_indexUB_data[totalIneq] - 1]) -
          Simulation_B.phaseOneCorrectionX;
        Simulation_B.c_p4 = fabs(Simulation_B.ratio);
        if ((!(Simulation_B.c_p4 <= 0.01 - Simulation_B.ratio)) && (!rtIsNaN
             (0.01 - Simulation_B.ratio))) {
          Simulation_B.c_p4 = 0.01 - Simulation_B.ratio;
        }

        Simulation_B.c_p4 /= Simulation_B.pk_corrected;
        if (Simulation_B.c_p4 < *alpha) {
          *alpha = Simulation_B.c_p4;
          *constrType = 5;
          *constrIdx = totalIneq + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simula_checkUnboundedOrIllPosed(s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
  *solution, const s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective)
{
  if (objective->objtype == 5) {
    if (Simulation_xnrm2_e(objective->nvar, solution->searchDir.data) > 100.0 *
        static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8) {
      solution->state = 3;
    } else {
      solution->state = 4;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simu_addBoundToActiveSetMatrix_(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr.data[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid.data[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx.data[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * obj->ldA - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB.data[idx_local - 1];
    obj->bwset.data[obj->nActiveConstr - 1] = obj->ub.data[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB.data[idx_local - 1];
    obj->bwset.data[obj->nActiveConstr - 1] = obj->lb.data[idx_bnd_local - 1];
  }

  for (int32_T idx = 0; idx <= idx_bnd_local - 2; idx++) {
    obj->ATwset.data[(idx + colOffset) + 1] = 0.0;
  }

  obj->ATwset.data[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) *
    2.0 - 1.0;
  for (idx_bnd_local++; idx_bnd_local <= obj->nVar; idx_bnd_local++) {
    obj->ATwset.data[idx_bnd_local + colOffset] = 0.0;
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset.data[obj->nVar + colOffset] = -1.0;
    break;
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_addAineqConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T idx_local)
{
  int32_T iAineq0;
  int32_T iAw0;
  obj->nWConstr[2]++;
  obj->isActiveConstr.data[(obj->isActiveIdx[2] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid.data[obj->nActiveConstr - 1] = 3;
  obj->Wlocalidx.data[obj->nActiveConstr - 1] = idx_local;
  iAineq0 = (idx_local - 1) * obj->ldA;
  iAw0 = (obj->nActiveConstr - 1) * obj->ldA;
  for (int32_T idx = 0; idx < obj->nVar; idx++) {
    obj->ATwset.data[iAw0 + idx] = obj->Aineq.data[iAineq0 + idx];
  }

  obj->bwset.data[obj->nActiveConstr - 1] = obj->bineq.data[idx_local - 1];
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simu_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, const
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *workingset, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval)
{
  solution->iterations++;
  Simulation_B.nVar_tmp_tmp_m = objective->nvar - 1;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - div_nzp_s32(solution->iterations, 50) * 50 == 0) {
    solution->maxConstr = Simul_maxConstraintViolation_e4(workingset,
      solution->xstar.data);
    Simulation_B.tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      Simulation_B.tempMaxConstr = solution->maxConstr - solution->
        xstar.data[objective->nvar - 1];
    }

    if (Simulation_B.tempMaxConstr > 0.01) {
      boolean_T nonDegenerateWset;
      Simulation_B.y_size_idx_0_mv = solution->searchDir.size;
      Simulation_B.loop_ub_e = solution->searchDir.size;
      if (0 <= Simulation_B.loop_ub_e - 1) {
        memcpy(&Simulation_B.y_data_cv[0], &solution->searchDir.data[0],
               Simulation_B.loop_ub_e * sizeof(real_T));
      }

      Simulation_B.loop_ub_e = 0;
      while (Simulation_B.loop_ub_e <= Simulation_B.nVar_tmp_tmp_m) {
        Simulation_B.y_data_cv[Simulation_B.loop_ub_e] = solution->
          xstar.data[Simulation_B.loop_ub_e];
        Simulation_B.loop_ub_e++;
      }

      if (0 <= Simulation_B.y_size_idx_0_mv - 1) {
        memcpy(&solution->searchDir.data[0], &Simulation_B.y_data_cv[0],
               Simulation_B.y_size_idx_0_mv * sizeof(real_T));
      }

      nonDegenerateWset = Simulat_feasibleX0ForWorkingSet
        (memspace->workspace_double.data, memspace->workspace_double.size,
         solution->searchDir.data, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      Simulation_B.tempMaxConstr = Simul_maxConstraintViolation_e4(workingset,
        solution->searchDir.data);
      if (Simulation_B.tempMaxConstr < solution->maxConstr) {
        Simulation_B.loop_ub_e = 0;
        while (Simulation_B.loop_ub_e <= Simulation_B.nVar_tmp_tmp_m) {
          solution->xstar.data[Simulation_B.loop_ub_e] =
            solution->searchDir.data[Simulation_B.loop_ub_e];
          Simulation_B.loop_ub_e++;
        }

        solution->maxConstr = Simulation_B.tempMaxConstr;
      }
    }
  }

  if (updateFval && (options_ObjectiveLimit > (rtMinusInf))) {
    solution->fstar = Simulation_computeFval_ReuseHx(objective,
      memspace->workspace_double.data, f_data, solution->xstar.data);
    if ((solution->fstar < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_iterate(const real_T H[441], const real_T f_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *cholmanager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective, const char_T
  options_SolverName[7], real_T options_StepTolerance, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations)
{
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  Simulation_B.activeSetChangeID = 0;
  Simulation_B.TYPE = objective->objtype;
  Simulation_B.nVar_c = workingset->nVar;
  Simulation_B.globalActiveConstrIdx = 0;
  Simulation_computeGrad_StoreHx(objective, H, f_data, solution->xstar.data);
  solution->fstar = Simulation_computeFval_ReuseHx(objective,
    memspace->workspace_double.data, f_data, solution->xstar.data);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  Simulation_B.idx = 0;
  while (Simulation_B.idx <= workingset->mConstrMax - 1) {
    solution->lambda.data[Simulation_B.idx] = 0.0;
    Simulation_B.idx++;
  }

  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      boolean_T guard11 = false;
      guard11 = false;
      if (subProblemChanged) {
        switch (Simulation_B.activeSetChangeID) {
         case 1:
          Simulation_B.idx = (workingset->nActiveConstr - 1) * workingset->ldA;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          Simulation_B.b_iy_i = qrmanager->ldq * qrmanager->ncols;
          Simulation_B.idxRotGCol = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            Simulation_B.iyend = Simulation_B.b_iy_i + qrmanager->mrows;
            Simulation_B.c_iy = Simulation_B.b_iy_i;
            while (Simulation_B.c_iy + 1 <= Simulation_B.iyend) {
              qrmanager->QR.data[Simulation_B.c_iy] = 0.0;
              Simulation_B.c_iy++;
            }

            Simulation_B.iyend = (qrmanager->mrows - 1) * qrmanager->ldq + 1;
            Simulation_B.c_iy = 1;
            while (((Simulation_B.idxRotGCol > 0) && (Simulation_B.c_iy <=
                     Simulation_B.iyend)) || ((Simulation_B.idxRotGCol < 0) &&
                    (Simulation_B.c_iy >= Simulation_B.iyend))) {
              Simulation_B.b_ix_n = Simulation_B.idx;
              Simulation_B.normDelta = 0.0;
              Simulation_B.g_m = (Simulation_B.c_iy + qrmanager->mrows) - 1;
              Simulation_B.ia_j = Simulation_B.c_iy;
              while (Simulation_B.ia_j <= Simulation_B.g_m) {
                Simulation_B.normDelta += qrmanager->Q.data[Simulation_B.ia_j -
                  1] * workingset->ATwset.data[Simulation_B.b_ix_n];
                Simulation_B.b_ix_n++;
                Simulation_B.ia_j++;
              }

              qrmanager->QR.data[Simulation_B.b_iy_i] += Simulation_B.normDelta;
              Simulation_B.b_iy_i++;
              Simulation_B.c_iy += Simulation_B.idxRotGCol;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt.data[qrmanager->ncols - 1] = qrmanager->ncols;
          Simulation_B.idx = qrmanager->mrows - 2;
          while (Simulation_B.idx + 2 > qrmanager->ncols) {
            Simulation_B.idxRotGCol = (qrmanager->ncols - 1) * qrmanager->ldq;
            Simulation_B.b_iy_i = (Simulation_B.idx + Simulation_B.idxRotGCol) +
              1;
            Simulation_B.temp = qrmanager->QR.data[Simulation_B.b_iy_i];
            Simulation_xrotg(&qrmanager->QR.data[Simulation_B.idx +
                             Simulation_B.idxRotGCol], &Simulation_B.temp,
                             &Simulation_B.normDelta, &Simulation_B.s_l);
            qrmanager->QR.data[Simulation_B.b_iy_i] = Simulation_B.temp;
            Simulation_B.idxRotGCol = qrmanager->ldq * Simulation_B.idx;
            if (qrmanager->mrows >= 1) {
              Simulation_B.b_iy_i = qrmanager->ldq + Simulation_B.idxRotGCol;
              Simulation_B.iyend = 0;
              while (Simulation_B.iyend <= qrmanager->mrows - 1) {
                Simulation_B.temp = qrmanager->Q.data[Simulation_B.idxRotGCol] *
                  Simulation_B.normDelta + qrmanager->Q.data[Simulation_B.b_iy_i]
                  * Simulation_B.s_l;
                qrmanager->Q.data[Simulation_B.b_iy_i] = qrmanager->
                  Q.data[Simulation_B.b_iy_i] * Simulation_B.normDelta -
                  qrmanager->Q.data[Simulation_B.idxRotGCol] * Simulation_B.s_l;
                qrmanager->Q.data[Simulation_B.idxRotGCol] = Simulation_B.temp;
                Simulation_B.b_iy_i++;
                Simulation_B.idxRotGCol++;
                Simulation_B.iyend++;
              }
            }

            Simulation_B.idx--;
          }
          break;

         case -1:
          Simulation_deleteColMoveEnd(qrmanager,
            Simulation_B.globalActiveConstrIdx);
          break;

         default:
          Simulation_factorQR(qrmanager, workingset->ATwset.data,
                              Simulation_B.nVar_c, workingset->nActiveConstr,
                              workingset->ldA);
          Simulation_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        Simulation_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective, Simulation_strcmp(options_SolverName));
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          Simulation_B.normDelta = Simulation_xnrm2_e(Simulation_B.nVar_c,
            solution->searchDir.data);
          guard11 = true;
        }
      } else {
        Simulation_B.b_iy_i = solution->searchDir.size;
        Simulation_B.idxRotGCol = solution->searchDir.size;
        if (0 <= Simulation_B.idxRotGCol - 1) {
          memcpy(&Simulation_B.y_data_p[0], &solution->searchDir.data[0],
                 Simulation_B.idxRotGCol * sizeof(real_T));
        }

        Simulation_B.idx = 0;
        while (Simulation_B.idx <= Simulation_B.nVar_c - 1) {
          Simulation_B.y_data_p[Simulation_B.idx] = 0.0;
          Simulation_B.idx++;
        }

        if (0 <= Simulation_B.b_iy_i - 1) {
          memcpy(&solution->searchDir.data[0], &Simulation_B.y_data_p[0],
                 Simulation_B.b_iy_i * sizeof(real_T));
        }

        Simulation_B.normDelta = 0.0;
        guard11 = true;
      }

      if (guard11) {
        if ((!subProblemChanged) || (Simulation_B.normDelta <
             options_StepTolerance) || (workingset->nActiveConstr >=
             Simulation_B.nVar_c)) {
          Simulation_B.h_size[0] = memspace->workspace_double.size[0];
          Simulation_B.h_size[1] = memspace->workspace_double.size[1];
          Simulation_B.b_iy_i = memspace->workspace_double.size[0] *
            memspace->workspace_double.size[1];
          if (0 <= Simulation_B.b_iy_i - 1) {
            memcpy(&Simulation_B.h_data[0], &memspace->workspace_double.data[0],
                   Simulation_B.b_iy_i * sizeof(real_T));
          }

          if (qrmanager->ncols > 0) {
            boolean_T guard1 = false;
            guard1 = false;
            if (objective->objtype != 4) {
              Simulation_B.normDelta = 100.0 * static_cast<real_T>
                (qrmanager->mrows) * 2.2204460492503131E-16;
              updateFval = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
              if (updateFval) {
                boolean_T guard2 = false;
                Simulation_B.idx = qrmanager->ncols;
                guard2 = false;
                if (qrmanager->mrows < qrmanager->ncols) {
                  Simulation_B.idxRotGCol = (qrmanager->ncols - 1) *
                    qrmanager->ldq + qrmanager->mrows;
                  while ((Simulation_B.idx > qrmanager->mrows) && (fabs
                          (qrmanager->QR.data[Simulation_B.idxRotGCol - 1]) >=
                          Simulation_B.normDelta)) {
                    Simulation_B.idx--;
                    Simulation_B.idxRotGCol -= qrmanager->ldq;
                  }

                  updateFval = (Simulation_B.idx == qrmanager->mrows);
                  if (!updateFval) {
                  } else {
                    guard2 = true;
                  }
                } else {
                  guard2 = true;
                }

                if (guard2) {
                  Simulation_B.idxRotGCol = (Simulation_B.idx - 1) *
                    qrmanager->ldq + Simulation_B.idx;
                  while ((Simulation_B.idx >= 1) && (fabs(qrmanager->
                           QR.data[Simulation_B.idxRotGCol - 1]) >=
                          Simulation_B.normDelta)) {
                    Simulation_B.idx--;
                    Simulation_B.idxRotGCol = (Simulation_B.idxRotGCol -
                      qrmanager->ldq) - 1;
                  }

                  updateFval = (Simulation_B.idx == 0);
                }
              }

              if (!updateFval) {
                solution->state = -7;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              Simulation_B.h_size[0] = memspace->workspace_double.size[0];
              Simulation_B.h_size[1] = memspace->workspace_double.size[1];
              if (0 <= Simulation_B.b_iy_i - 1) {
                memcpy(&Simulation_B.h_data[0], &memspace->
                       workspace_double.data[0], Simulation_B.b_iy_i * sizeof
                       (real_T));
              }

              Simulation_xgemv_la4(qrmanager->mrows, qrmanager->ncols,
                                   qrmanager->Q.data, qrmanager->ldq,
                                   objective->grad.data, Simulation_B.h_data);
              Simulation_xtrsv(qrmanager->ncols, qrmanager->QR.data,
                               qrmanager->ldq, Simulation_B.h_data);
              Simulation_B.idx = 0;
              while (Simulation_B.idx <= qrmanager->ncols - 1) {
                solution->lambda.data[Simulation_B.idx] =
                  -Simulation_B.h_data[Simulation_B.idx];
                Simulation_B.idx++;
              }
            }
          }

          memspace->workspace_double.size[0] = Simulation_B.h_size[0];
          memspace->workspace_double.size[1] = Simulation_B.h_size[1];
          Simulation_B.idxRotGCol = Simulation_B.h_size[0] *
            Simulation_B.h_size[1];
          if (0 <= Simulation_B.idxRotGCol - 1) {
            memcpy(&memspace->workspace_double.data[0], &Simulation_B.h_data[0],
                   Simulation_B.idxRotGCol * sizeof(real_T));
          }

          if ((solution->state != -7) || (workingset->nActiveConstr >
               Simulation_B.nVar_c)) {
            Simulation_B.idx = 0;
            Simulation_B.normDelta = 0.0;
            Simulation_B.idxRotGCol = workingset->nWConstr[0] +
              workingset->nWConstr[1];
            while (Simulation_B.idxRotGCol + 1 <= workingset->nActiveConstr) {
              if (solution->lambda.data[Simulation_B.idxRotGCol] <
                  Simulation_B.normDelta) {
                Simulation_B.normDelta = solution->
                  lambda.data[Simulation_B.idxRotGCol];
                Simulation_B.idx = Simulation_B.idxRotGCol + 1;
              }

              Simulation_B.idxRotGCol++;
            }

            if (Simulation_B.idx == 0) {
              solution->state = 1;
            } else {
              Simulation_B.activeSetChangeID = -1;
              Simulation_B.globalActiveConstrIdx = Simulation_B.idx;
              subProblemChanged = true;
              Simulation_removeConstr(workingset, Simulation_B.idx);
              solution->lambda.data[Simulation_B.idx - 1] = 0.0;
            }
          } else {
            Simulation_B.idx = workingset->nActiveConstr;
            Simulation_B.activeSetChangeID = 0;
            Simulation_B.globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            Simulation_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda.data[Simulation_B.idx - 1] = 0.0;
          }

          updateFval = false;
        } else {
          Simulation_feasibleratiotest(solution->xstar.data,
            solution->searchDir.data, memspace->workspace_double.data,
            memspace->workspace_double.size, workingset->nVar, workingset->ldA,
            workingset->Aineq.data, workingset->bineq.data, workingset->lb.data,
            workingset->ub.data, workingset->indexLB.data,
            workingset->indexUB.data, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr.data, workingset->nWConstr,
            Simulation_B.TYPE == 5, &Simulation_B.normDelta, &updateFval,
            &Simulation_B.idx, &Simulation_B.idxRotGCol);
          if (updateFval) {
            switch (Simulation_B.idx) {
             case 3:
              Simulation_addAineqConstr(workingset, Simulation_B.idxRotGCol);
              break;

             case 4:
              Simu_addBoundToActiveSetMatrix_(workingset, 4,
                Simulation_B.idxRotGCol);
              break;

             default:
              Simu_addBoundToActiveSetMatrix_(workingset, 5,
                Simulation_B.idxRotGCol);
              break;
            }

            Simulation_B.activeSetChangeID = 1;
          } else {
            Simula_checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if ((Simulation_B.nVar_c >= 1) && (!(Simulation_B.normDelta == 0.0)))
          {
            Simulation_B.idx = 0;
            while (Simulation_B.idx <= Simulation_B.nVar_c - 1) {
              solution->xstar.data[Simulation_B.idx] += Simulation_B.normDelta *
                solution->searchDir.data[Simulation_B.idx];
              Simulation_B.idx++;
            }
          }

          Simulation_computeGrad_StoreHx(objective, H, f_data,
            solution->xstar.data);
          updateFval = true;
        }

        Simu_checkStoppingAndUpdateFval(&Simulation_B.activeSetChangeID, f_data,
          solution, memspace, objective, workingset, qrmanager,
          options_ObjectiveLimit, runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = Simulation_computeFval_ReuseHx(objective,
          memspace->workspace_double.data, f_data, solution->xstar.data);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_phaseone(const real_T H[441], const real_T f_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *cholmanager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective,
  somzaGboVhDG7PNQS6E98jD_Simul_T *options, const
  somzaGboVhDG7PNQS6E98jD_Simul_T *runTimeOptions)
{
  Simulation_B.PROBTYPE_ORIG = workingset->probType;
  Simulation_B.nVar_tmp = workingset->nVar;
  solution->xstar.data[workingset->nVar] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    Simulation_B.mConstr = 1;
  } else {
    Simulation_B.mConstr = 4;
  }

  Simulation_setProblemType(workingset, Simulation_B.mConstr);
  Simulation_removeAllIneqConstr(workingset);
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = Simulation_B.nVar_tmp + 1;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 0.01;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = Simulation_computeFval(objective,
    memspace->workspace_double.data, H, f_data, solution->xstar.data);
  solution->state = 5;
  Simulation_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                     cholmanager, objective, options->SolverName,
                     options->StepTolerance, options->ObjectiveLimit,
                     runTimeOptions->MaxIterations);
  if (workingset->isActiveConstr.data[(workingset->isActiveIdx[3] +
       workingset->sizes[3]) - 2]) {
    boolean_T exitg1;
    Simulation_B.mConstr = workingset->sizes[0] + 17;
    exitg1 = false;
    while ((!exitg1) && (Simulation_B.mConstr <= workingset->nActiveConstr)) {
      if ((workingset->Wid.data[Simulation_B.mConstr - 1] == 4) &&
          (workingset->Wlocalidx.data[Simulation_B.mConstr - 1] ==
           workingset->sizes[3])) {
        Simulation_removeConstr(workingset, Simulation_B.mConstr);
        exitg1 = true;
      } else {
        Simulation_B.mConstr++;
      }
    }
  }

  Simulation_B.mConstr = workingset->nActiveConstr;
  Simulation_B.mEqFixed = workingset->sizes[0] + 16;
  while ((Simulation_B.mConstr > Simulation_B.mEqFixed) && (Simulation_B.mConstr
          > Simulation_B.nVar_tmp)) {
    Simulation_removeConstr(workingset, Simulation_B.mConstr);
    Simulation_B.mConstr--;
  }

  solution->maxConstr = solution->xstar.data[Simulation_B.nVar_tmp];
  Simulation_setProblemType(workingset, Simulation_B.PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = (rtMinusInf);
  options->StepTolerance = 1.0E-6;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_driver_b(const real_T H[441], const real_T f_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *solution, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *workingset,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *qrmanager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *cholmanager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *objective,
  somzaGboVhDG7PNQS6E98jD_Simul_T *options, somzaGboVhDG7PNQS6E98jD_Simul_T
  *runTimeOptions)
{
  boolean_T guard1 = false;
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = true;
  Simulation_B.nVar_p = workingset->nVar - 1;
  guard1 = false;
  if (workingset->probType == 3) {
    Simulation_B.b_idx = 0;
    while (Simulation_B.b_idx <= workingset->sizes[0] - 1) {
      solution->xstar.data[workingset->indexFixed.data[Simulation_B.b_idx] - 1] =
        workingset->ub.data[workingset->indexFixed.data[Simulation_B.b_idx] - 1];
      Simulation_B.b_idx++;
    }

    Simulation_B.b_idx = 0;
    while (Simulation_B.b_idx <= workingset->sizes[3] - 1) {
      if (workingset->isActiveConstr.data[(workingset->isActiveIdx[3] +
           Simulation_B.b_idx) - 1]) {
        solution->xstar.data[workingset->indexLB.data[Simulation_B.b_idx] - 1] =
          -workingset->lb.data[workingset->indexLB.data[Simulation_B.b_idx] - 1];
      }

      Simulation_B.b_idx++;
    }

    Simulation_B.b_idx = 0;
    while (Simulation_B.b_idx <= workingset->sizes[4] - 1) {
      if (workingset->isActiveConstr.data[(workingset->isActiveIdx[4] +
           Simulation_B.b_idx) - 1]) {
        solution->xstar.data[workingset->indexUB.data[Simulation_B.b_idx] - 1] =
          workingset->ub.data[workingset->indexUB.data[Simulation_B.b_idx] - 1];
      }

      Simulation_B.b_idx++;
    }

    Simulation_PresolveWorkingSet(solution, memspace, workingset, qrmanager);
    if (solution->state < 0) {
    } else {
      guard1 = true;
    }
  } else {
    solution->state = 82;
    guard1 = true;
  }

  if (guard1) {
    solution->iterations = 0;
    solution->maxConstr = Simul_maxConstraintViolation_e4(workingset,
      solution->xstar.data);
    if (solution->maxConstr > 0.01) {
      Simulation_phaseone(H, f_data, solution, memspace, workingset, qrmanager,
                          cholmanager, objective, options, runTimeOptions);
      if (solution->state == 0) {
      } else {
        solution->maxConstr = Simul_maxConstraintViolation_e4(workingset,
          solution->xstar.data);
        if (solution->maxConstr > 0.01) {
          Simulation_B.b_idx = 0;
          while (Simulation_B.b_idx <= workingset->mConstrMax - 1) {
            solution->lambda.data[Simulation_B.b_idx] = 0.0;
            Simulation_B.b_idx++;
          }

          solution->fstar = Simulation_computeFval(objective,
            memspace->workspace_double.data, H, f_data, solution->xstar.data);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            Simulation_B.y_size_idx_0_b = solution->searchDir.size;
            Simulation_B.b_idx = solution->searchDir.size;
            if (0 <= Simulation_B.b_idx - 1) {
              memcpy(&Simulation_B.y_data_b[0], &solution->searchDir.data[0],
                     Simulation_B.b_idx * sizeof(real_T));
            }

            Simulation_B.b_idx = 0;
            while (Simulation_B.b_idx <= Simulation_B.nVar_p) {
              Simulation_B.y_data_b[Simulation_B.b_idx] = solution->
                xstar.data[Simulation_B.b_idx];
              Simulation_B.b_idx++;
            }

            if (0 <= Simulation_B.y_size_idx_0_b - 1) {
              memcpy(&solution->searchDir.data[0], &Simulation_B.y_data_b[0],
                     Simulation_B.y_size_idx_0_b * sizeof(real_T));
            }

            Simulation_PresolveWorkingSet(solution, memspace, workingset,
              qrmanager);
            Simulation_B.maxConstr_new = Simul_maxConstraintViolation_e4
              (workingset, solution->xstar.data);
            if (Simulation_B.maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = Simulation_B.maxConstr_new;
              Simulation_B.y_size_idx_0_b = solution->xstar.size;
              Simulation_B.b_idx = solution->xstar.size;
              if (0 <= Simulation_B.b_idx - 1) {
                memcpy(&Simulation_B.y_data_b[0], &solution->xstar.data[0],
                       Simulation_B.b_idx * sizeof(real_T));
              }

              Simulation_B.b_idx = 0;
              while (Simulation_B.b_idx <= Simulation_B.nVar_p) {
                Simulation_B.y_data_b[Simulation_B.b_idx] =
                  solution->searchDir.data[Simulation_B.b_idx];
                Simulation_B.b_idx++;
              }

              if (0 <= Simulation_B.y_size_idx_0_b - 1) {
                memcpy(&solution->xstar.data[0], &Simulation_B.y_data_b[0],
                       Simulation_B.y_size_idx_0_b * sizeof(real_T));
              }
            }
          }

          Simulation_iterate(H, f_data, solution, memspace, workingset,
                             qrmanager, cholmanager, objective,
                             options->SolverName, options->StepTolerance,
                             options->ObjectiveLimit,
                             runTimeOptions->MaxIterations);
        }
      }
    } else {
      Simulation_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                         cholmanager, objective, options->SolverName,
                         options->StepTolerance, options->ObjectiveLimit,
                         runTimeOptions->MaxIterations);
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_addAeqConstr(s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *obj,
  int32_T idx_local)
{
  int32_T totalEq;
  totalEq = obj->nWConstr[0] + obj->nWConstr[1];
  if ((obj->nActiveConstr == totalEq) && (idx_local > obj->nWConstr[1])) {
    int32_T iAeq0;
    int32_T iAw0;
    obj->nWConstr[1]++;
    obj->isActiveConstr.data[(obj->isActiveIdx[1] + idx_local) - 2] = true;
    obj->nActiveConstr++;
    obj->Wid.data[obj->nActiveConstr - 1] = 2;
    obj->Wlocalidx.data[obj->nActiveConstr - 1] = idx_local;
    iAeq0 = (idx_local - 1) * obj->ldA;
    iAw0 = (obj->nActiveConstr - 1) * obj->ldA;
    for (totalEq = 1; totalEq - 1 < obj->nVar; totalEq++) {
      obj->ATwset.data[(iAw0 + totalEq) - 1] = obj->Aeq.data[(iAeq0 + totalEq) -
        1];
    }

    obj->bwset.data[obj->nActiveConstr - 1] = obj->beq[idx_local - 1];
  } else {
    int32_T iAeq0;
    int32_T iAw0;
    obj->nActiveConstr++;
    iAeq0 = obj->nActiveConstr - 1;
    obj->Wid.data[obj->nActiveConstr - 1] = obj->Wid.data[totalEq];
    obj->Wlocalidx.data[iAeq0] = obj->Wlocalidx.data[totalEq];
    for (iAw0 = 0; iAw0 < obj->nVar; iAw0++) {
      obj->ATwset.data[iAw0 + obj->ldA * iAeq0] = obj->ATwset.data[obj->ldA *
        totalEq + iAw0];
    }

    obj->bwset.data[iAeq0] = obj->bwset.data[totalEq];
    obj->nWConstr[1]++;
    obj->isActiveConstr.data[(obj->isActiveIdx[1] + idx_local) - 2] = true;
    obj->Wid.data[totalEq] = 2;
    obj->Wlocalidx.data[totalEq] = idx_local;
    iAeq0 = (idx_local - 1) * obj->ldA;
    iAw0 = obj->ldA * totalEq;
    for (int32_T b_idx = 1; b_idx - 1 < obj->nVar; b_idx++) {
      obj->ATwset.data[(iAw0 + b_idx) - 1] = obj->Aeq.data[(iAeq0 + b_idx) - 1];
    }

    obj->bwset.data[totalEq] = obj->beq[idx_local - 1];
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static boolean_T Simulation_soc(const real_T Hessian[441], const real_T
  grad_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *
  QPObjective, const somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions)
{
  boolean_T success;
  Simulation_B.nWIneq_old = WorkingSet->nWConstr[2];
  Simulation_B.nWLower_old = WorkingSet->nWConstr[3];
  Simulation_B.nWUpper_old = WorkingSet->nWConstr[4];
  Simulation_B.nVar_pm = WorkingSet->nVar - 1;
  Simulation_B.mConstrMax_p = WorkingSet->mConstrMax - 1;
  Simulation_B.idx_Aineq = 0;
  while (Simulation_B.idx_Aineq <= Simulation_B.nVar_pm) {
    TrialState->xstarsqp[Simulation_B.idx_Aineq] = TrialState->
      xstarsqp_old[Simulation_B.idx_Aineq];
    Simulation_B.idx_Aineq++;
  }

  Simulation_B.idx_Aineq = 0;
  while (Simulation_B.idx_Aineq <= Simulation_B.nVar_pm) {
    TrialState->socDirection.data[Simulation_B.idx_Aineq] =
      TrialState->xstar.data[Simulation_B.idx_Aineq];
    Simulation_B.idx_Aineq++;
  }

  Simulation_B.idx_Aineq = 0;
  while (Simulation_B.idx_Aineq <= Simulation_B.mConstrMax_p) {
    TrialState->lambdaStopTest.data[Simulation_B.idx_Aineq] =
      TrialState->lambda.data[Simulation_B.idx_Aineq];
    Simulation_B.idx_Aineq++;
  }

  for (Simulation_B.idx_Aineq = 0; Simulation_B.idx_Aineq < 16;
       Simulation_B.idx_Aineq++) {
    WorkingSet->beq[Simulation_B.idx_Aineq] = -TrialState->
      cEq[Simulation_B.idx_Aineq];
  }

  Simulation_B.idx_Aineq_tmp = WorkingSet->ldA;
  Simulation_B.iy_n = 0;
  Simulation_B.idx_upper = WorkingSet->ldA * 15 + 1;
  Simulation_B.iac = 1;
  while (((Simulation_B.idx_Aineq_tmp > 0) && (Simulation_B.iac <=
           Simulation_B.idx_upper)) || ((Simulation_B.idx_Aineq_tmp < 0) &&
          (Simulation_B.iac >= Simulation_B.idx_upper))) {
    Simulation_B.idx_Partition = 0;
    Simulation_B.oldDirIdx = 0.0;
    Simulation_B.idx_Aineq = (Simulation_B.iac + WorkingSet->nVar) - 1;
    Simulation_B.b_ia_k = Simulation_B.iac;
    while (Simulation_B.b_ia_k <= Simulation_B.idx_Aineq) {
      Simulation_B.oldDirIdx += WorkingSet->Aeq.data[Simulation_B.b_ia_k - 1] *
        TrialState->searchDir.data[Simulation_B.idx_Partition];
      Simulation_B.idx_Partition++;
      Simulation_B.b_ia_k++;
    }

    WorkingSet->beq[Simulation_B.iy_n] += Simulation_B.oldDirIdx;
    Simulation_B.iy_n++;
    Simulation_B.iac += Simulation_B.idx_Aineq_tmp;
  }

  for (Simulation_B.idx_Aineq = 0; Simulation_B.idx_Aineq < 16;
       Simulation_B.idx_Aineq++) {
    WorkingSet->bwset.data[WorkingSet->sizes[0] + Simulation_B.idx_Aineq] =
      WorkingSet->beq[Simulation_B.idx_Aineq];
  }

  if (WorkingSet->sizes[2] > 0) {
    Simulation_B.idx_Aineq = 0;
    while (Simulation_B.idx_Aineq <= WorkingSet->sizes[2] - 1) {
      WorkingSet->bineq.data[Simulation_B.idx_Aineq] = -TrialState->
        cIneq.data[Simulation_B.idx_Aineq];
      Simulation_B.idx_Aineq++;
    }

    Simulation_B.idx_Aineq_tmp = WorkingSet->ldA;
    Simulation_B.iy_n = 0;
    Simulation_B.idx_upper = (WorkingSet->sizes[2] - 1) * WorkingSet->ldA + 1;
    Simulation_B.iac = 1;
    while (((Simulation_B.idx_Aineq_tmp > 0) && (Simulation_B.iac <=
             Simulation_B.idx_upper)) || ((Simulation_B.idx_Aineq_tmp < 0) &&
            (Simulation_B.iac >= Simulation_B.idx_upper))) {
      Simulation_B.idx_Partition = 0;
      Simulation_B.oldDirIdx = 0.0;
      Simulation_B.idx_Aineq = (Simulation_B.iac + WorkingSet->nVar) - 1;
      Simulation_B.b_ia_k = Simulation_B.iac;
      while (Simulation_B.b_ia_k <= Simulation_B.idx_Aineq) {
        Simulation_B.oldDirIdx += WorkingSet->Aineq.data[Simulation_B.b_ia_k - 1]
          * TrialState->searchDir.data[Simulation_B.idx_Partition];
        Simulation_B.idx_Partition++;
        Simulation_B.b_ia_k++;
      }

      WorkingSet->bineq.data[Simulation_B.iy_n] += Simulation_B.oldDirIdx;
      Simulation_B.iy_n++;
      Simulation_B.iac += Simulation_B.idx_Aineq_tmp;
    }

    Simulation_B.idx_Aineq = 1;
    Simulation_B.iy_n = WorkingSet->sizes[2] + 1;
    Simulation_B.idx_upper = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
    Simulation_B.iac = WorkingSet->isActiveIdx[2] - 1;
    while (Simulation_B.iac + 1 <= WorkingSet->nActiveConstr) {
      switch (WorkingSet->Wid.data[Simulation_B.iac]) {
       case 3:
        Simulation_B.idx_Partition = Simulation_B.idx_Aineq;
        Simulation_B.idx_Aineq++;
        WorkingSet->bwset.data[Simulation_B.iac] = WorkingSet->
          bineq.data[WorkingSet->Wlocalidx.data[Simulation_B.iac] - 1];
        break;

       case 4:
        Simulation_B.idx_Partition = Simulation_B.iy_n;
        Simulation_B.iy_n++;
        break;

       default:
        Simulation_B.idx_Partition = Simulation_B.idx_upper;
        Simulation_B.idx_upper++;
        break;
      }

      TrialState->workingset_old.data[Simulation_B.idx_Partition - 1] =
        WorkingSet->Wlocalidx.data[Simulation_B.iac];
      Simulation_B.iac++;
    }
  }

  Simulation_B.idx_Aineq = 0;
  while (Simulation_B.idx_Aineq <= Simulation_B.nVar_pm) {
    TrialState->xstar.data[Simulation_B.idx_Aineq] = TrialState->
      xstarsqp[Simulation_B.idx_Aineq];
    Simulation_B.idx_Aineq++;
  }

  Simulation_B.qpoptions_a = *qpoptions;
  Simulation_B.qpoptions_j = *qpoptions;
  Simulation_driver_b(Hessian, grad_data, TrialState, memspace, WorkingSet,
                      QRManager, CholManager, QPObjective,
                      &Simulation_B.qpoptions_a, &Simulation_B.qpoptions_j);
  while ((WorkingSet->mEqRemoved > 0) && (WorkingSet->indexEqRemoved
          [WorkingSet->mEqRemoved - 1] >= 1)) {
    Simulation_addAeqConstr(WorkingSet, WorkingSet->indexEqRemoved
      [WorkingSet->mEqRemoved - 1]);
    WorkingSet->mEqRemoved--;
  }

  Simulation_B.idx_Aineq = 0;
  while (Simulation_B.idx_Aineq <= Simulation_B.nVar_pm) {
    Simulation_B.oldDirIdx = TrialState->
      socDirection.data[Simulation_B.idx_Aineq];
    TrialState->socDirection.data[Simulation_B.idx_Aineq] =
      TrialState->xstar.data[Simulation_B.idx_Aineq] -
      TrialState->socDirection.data[Simulation_B.idx_Aineq];
    TrialState->xstar.data[Simulation_B.idx_Aineq] = Simulation_B.oldDirIdx;
    Simulation_B.idx_Aineq++;
  }

  success = (Simulation_xnrm2_e(Simulation_B.nVar_pm + 1,
              TrialState->socDirection.data) <= Simulation_xnrm2_e
             (Simulation_B.nVar_pm + 1, TrialState->xstar.data) * 2.0);
  Simulation_B.idx_Aineq = WorkingSet->sizes[2];
  Simulation_B.iy_n = WorkingSet->sizes[3];
  for (Simulation_B.nVar_pm = 0; Simulation_B.nVar_pm < 16; Simulation_B.nVar_pm
       ++) {
    WorkingSet->beq[Simulation_B.nVar_pm] = -TrialState->
      cEq[Simulation_B.nVar_pm];
  }

  for (Simulation_B.nVar_pm = 0; Simulation_B.nVar_pm < 16; Simulation_B.nVar_pm
       ++) {
    WorkingSet->bwset.data[WorkingSet->sizes[0] + Simulation_B.nVar_pm] =
      WorkingSet->beq[Simulation_B.nVar_pm];
  }

  if (WorkingSet->sizes[2] > 0) {
    Simulation_B.nVar_pm = 0;
    while (Simulation_B.nVar_pm <= Simulation_B.idx_Aineq - 1) {
      WorkingSet->bineq.data[Simulation_B.nVar_pm] = -TrialState->
        cIneq.data[Simulation_B.nVar_pm];
      Simulation_B.nVar_pm++;
    }

    if (!success) {
      Simulation_removeAllIneqConstr(WorkingSet);
      Simulation_B.nVar_pm = 0;
      while (Simulation_B.nVar_pm <= Simulation_B.nWIneq_old - 1) {
        Simulation_addAineqConstr(WorkingSet, TrialState->
          workingset_old.data[Simulation_B.nVar_pm]);
        Simulation_B.nVar_pm++;
      }

      Simulation_B.nWIneq_old = 0;
      while (Simulation_B.nWIneq_old <= Simulation_B.nWLower_old - 1) {
        Simu_addBoundToActiveSetMatrix_(WorkingSet, 4,
          TrialState->workingset_old.data[Simulation_B.nWIneq_old +
          Simulation_B.idx_Aineq]);
        Simulation_B.nWIneq_old++;
      }

      Simulation_B.nWLower_old = 0;
      while (Simulation_B.nWLower_old <= Simulation_B.nWUpper_old - 1) {
        Simu_addBoundToActiveSetMatrix_(WorkingSet, 5,
          TrialState->workingset_old.data[(Simulation_B.nWLower_old +
          Simulation_B.idx_Aineq) + Simulation_B.iy_n]);
        Simulation_B.nWLower_old++;
      }
    }
  }

  if (!success) {
    Simulation_B.nWUpper_old = 0;
    while (Simulation_B.nWUpper_old <= Simulation_B.mConstrMax_p) {
      TrialState->lambda.data[Simulation_B.nWUpper_old] =
        TrialState->lambdaStopTest.data[Simulation_B.nWUpper_old];
      Simulation_B.nWUpper_old++;
    }
  } else {
    Simulation_sortLambdaQP(TrialState->lambda.data, WorkingSet->nActiveConstr,
      WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid.data,
      WorkingSet->Wlocalidx.data, memspace->workspace_double.data);
  }

  return success;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_normal(const real_T Hessian[441], const real_T grad_data[],
  s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState, sG8JZ69axY52WWR6RKyApQC_Simul_T
  *MeritFunction, s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace,
  s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T
  *QRManager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager,
  s_ollgpvqodLtAhexvVgD8pB_Simu_T *QPObjective, const
  somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions)
{
  boolean_T nonlinEqRemoved;
  Simulation_B.qpoptions_jz = *qpoptions;
  Simulation_B.qpoptions_o = *qpoptions;
  Simulation_driver_b(Hessian, grad_data, TrialState, memspace, WorkingSet,
                      QRManager, CholManager, QPObjective,
                      &Simulation_B.qpoptions_jz, &Simulation_B.qpoptions_o);
  if (TrialState->state > 0) {
    Simulation_B.penaltyParamTrial = MeritFunction->penaltyParam;
    Simulation_B.constrViolationEq = 0.0;
    for (Simulation_B.k_mx = 0; Simulation_B.k_mx < 16; Simulation_B.k_mx++) {
      Simulation_B.constrViolationEq += fabs(TrialState->cEq[Simulation_B.k_mx]);
    }

    Simulation_B.constrViolationIneq = 0.0;
    Simulation_B.k_mx = 0;
    while (Simulation_B.k_mx <= WorkingSet->sizes[2] - 1) {
      if (TrialState->cIneq.data[Simulation_B.k_mx] > 0.0) {
        Simulation_B.constrViolationIneq += TrialState->
          cIneq.data[Simulation_B.k_mx];
      }

      Simulation_B.k_mx++;
    }

    Simulation_B.constrViolationEq += Simulation_B.constrViolationIneq;
    Simulation_B.constrViolationIneq = MeritFunction->linearizedConstrViol;
    MeritFunction->linearizedConstrViol = 0.0;
    Simulation_B.constrViolationIneq += Simulation_B.constrViolationEq;
    if ((Simulation_B.constrViolationIneq > 2.2204460492503131E-16) &&
        (TrialState->fstar > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        Simulation_B.penaltyParamTrial = 1.0;
      } else {
        Simulation_B.penaltyParamTrial = 1.5;
      }

      Simulation_B.penaltyParamTrial = Simulation_B.penaltyParamTrial *
        TrialState->fstar / Simulation_B.constrViolationIneq;
    }

    if (Simulation_B.penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi = Simulation_B.penaltyParamTrial *
        Simulation_B.constrViolationEq + TrialState->sqpFval;
      if (((MeritFunction->initConstrViolationEq +
            MeritFunction->initConstrViolationIneq) *
           Simulation_B.penaltyParamTrial + MeritFunction->initFval) -
          MeritFunction->phi > static_cast<real_T>
          (MeritFunction->nPenaltyDecreases) * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        if (Simulation_B.penaltyParamTrial >= 1.0E-10) {
          MeritFunction->penaltyParam = Simulation_B.penaltyParamTrial;
        } else {
          MeritFunction->penaltyParam = 1.0E-10;
        }
      } else {
        MeritFunction->phi = MeritFunction->penaltyParam *
          Simulation_B.constrViolationEq + TrialState->sqpFval;
      }
    } else {
      if (Simulation_B.penaltyParamTrial >= 1.0E-10) {
        MeritFunction->penaltyParam = Simulation_B.penaltyParamTrial;
      } else {
        MeritFunction->penaltyParam = 1.0E-10;
      }

      MeritFunction->phi = MeritFunction->penaltyParam *
        Simulation_B.constrViolationEq + TrialState->sqpFval;
    }

    Simulation_B.penaltyParamTrial = TrialState->fstar -
      MeritFunction->penaltyParam * Simulation_B.constrViolationEq;
    if (Simulation_B.penaltyParamTrial <= 0.0) {
      MeritFunction->phiPrimePlus = Simulation_B.penaltyParamTrial;
    } else {
      MeritFunction->phiPrimePlus = 0.0;
    }
  }

  Simulation_sortLambdaQP(TrialState->lambda.data, WorkingSet->nActiveConstr,
    WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid.data,
    WorkingSet->Wlocalidx.data, memspace->workspace_double.data);
  nonlinEqRemoved = (WorkingSet->mEqRemoved > 0);
  while ((WorkingSet->mEqRemoved > 0) && (WorkingSet->indexEqRemoved
          [WorkingSet->mEqRemoved - 1] >= 1)) {
    Simulation_addAeqConstr(WorkingSet, WorkingSet->indexEqRemoved
      [WorkingSet->mEqRemoved - 1]);
    WorkingSet->mEqRemoved--;
  }

  if (nonlinEqRemoved) {
    for (Simulation_B.k_mx = 0; Simulation_B.k_mx < 16; Simulation_B.k_mx++) {
      WorkingSet->Wlocalidx.data[WorkingSet->sizes[0] + Simulation_B.k_mx] =
        Simulation_B.k_mx + 1;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_relaxed(const real_T Hessian[441], const real_T
  grad_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Simul_T *MeritFunction,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions)
{
  boolean_T tf;
  Simulation_B.nVarOrig = WorkingSet->nVar - 1;
  Simulation_B.beta = 0.0;
  Simulation_B.temp_a = 0;
  while (Simulation_B.temp_a <= Simulation_B.nVarOrig) {
    Simulation_B.beta += Hessian[21 * Simulation_B.temp_a + Simulation_B.temp_a];
    Simulation_B.temp_a++;
  }

  Simulation_B.beta /= static_cast<real_T>(WorkingSet->nVar);
  if (TrialState->sqpIterations <= 1) {
    Simulation_B.rho = fabs(grad_data[Simulation_ixamax(QPObjective->nvar,
      grad_data) - 1]);
    if ((1.0 >= Simulation_B.rho) || rtIsNaN(Simulation_B.rho)) {
      Simulation_B.rho = 1.0;
    }

    Simulation_B.rho *= 100.0;
  } else {
    Simulation_B.rho = fabs(TrialState->lambdasqp.data[Simulation_ixamax
      (WorkingSet->mConstr, TrialState->lambdasqp.data) - 1]);
  }

  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = Simulation_B.beta;
  QPObjective->rho = Simulation_B.rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  Simulation_B.b_WorkingSet = *WorkingSet;
  Simulation_setProblemType(&Simulation_B.b_WorkingSet, 2);
  Simulation_B.mIneq_k = Simulation_B.b_WorkingSet.sizes[2] - 1;
  Simulation_B.mLBOrig = (Simulation_B.b_WorkingSet.sizes[3] -
    Simulation_B.b_WorkingSet.sizes[2]) - 32;
  Simulation_B.temp_a = 0;
  while (Simulation_B.temp_a <= Simulation_B.mIneq_k) {
    memspace->workspace_double.data[Simulation_B.temp_a] =
      Simulation_B.b_WorkingSet.bineq.data[Simulation_B.temp_a];
    Simulation_B.temp_a++;
  }

  Simulation_xgemv_la4x4rhx2l0(WorkingSet->nVar,
    Simulation_B.b_WorkingSet.sizes[2], Simulation_B.b_WorkingSet.Aineq.data,
    Simulation_B.b_WorkingSet.ldA, TrialState->xstar.data,
    memspace->workspace_double.data);
  Simulation_B.temp_a = 0;
  while (Simulation_B.temp_a <= Simulation_B.mIneq_k) {
    TrialState->xstar.data[(Simulation_B.nVarOrig + Simulation_B.temp_a) + 1] =
      static_cast<real_T>(memspace->workspace_double.data[Simulation_B.temp_a] >
                          0.0) * memspace->
      workspace_double.data[Simulation_B.temp_a];
    Simulation_B.temp_a++;
  }

  memcpy(&memspace->workspace_double.data[0], &Simulation_B.b_WorkingSet.beq[0],
         sizeof(real_T) << 4U);
  Simulation_xgemv_la4x4rhx2l0(WorkingSet->nVar, 16,
    Simulation_B.b_WorkingSet.Aeq.data, Simulation_B.b_WorkingSet.ldA,
    TrialState->xstar.data, memspace->workspace_double.data);
  for (Simulation_B.temp_a = 0; Simulation_B.temp_a < 16; Simulation_B.temp_a++)
  {
    Simulation_B.idx_positive_tmp = Simulation_B.mIneq_k + Simulation_B.temp_a;
    if (memspace->workspace_double.data[Simulation_B.temp_a] <= 0.0) {
      TrialState->xstar.data[(Simulation_B.nVarOrig +
        Simulation_B.idx_positive_tmp) + 2] = 0.0;
      TrialState->xstar.data[(Simulation_B.nVarOrig +
        Simulation_B.idx_positive_tmp) + 18] = -memspace->
        workspace_double.data[Simulation_B.temp_a];
      Simu_addBoundToActiveSetMatrix_(&Simulation_B.b_WorkingSet, 4,
        (Simulation_B.mLBOrig + Simulation_B.idx_positive_tmp) + 2);
      if (memspace->workspace_double.data[Simulation_B.temp_a] >= -0.01) {
        Simu_addBoundToActiveSetMatrix_(&Simulation_B.b_WorkingSet, 4,
          (Simulation_B.mLBOrig + Simulation_B.idx_positive_tmp) + 18);
      }
    } else {
      Simulation_B.i6 = Simulation_B.nVarOrig + Simulation_B.idx_positive_tmp;
      TrialState->xstar.data[Simulation_B.i6 + 2] =
        memspace->workspace_double.data[Simulation_B.temp_a];
      TrialState->xstar.data[Simulation_B.i6 + 18] = 0.0;
      Simu_addBoundToActiveSetMatrix_(&Simulation_B.b_WorkingSet, 4,
        (Simulation_B.mLBOrig + Simulation_B.idx_positive_tmp) + 18);
      if (memspace->workspace_double.data[Simulation_B.temp_a] <= 0.01) {
        Simu_addBoundToActiveSetMatrix_(&Simulation_B.b_WorkingSet, 4,
          (Simulation_B.mLBOrig + Simulation_B.idx_positive_tmp) + 2);
      }
    }
  }

  Simulation_B.temp_a = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations +
    Simulation_B.b_WorkingSet.nVar) - WorkingSet->nVar;
  Simulation_B.qpoptions = *qpoptions;
  Simulation_B.qpoptions_f = *qpoptions;
  Simulation_driver_b(Hessian, grad_data, TrialState, memspace,
                      &Simulation_B.b_WorkingSet, QRManager, CholManager,
                      QPObjective, &Simulation_B.qpoptions,
                      &Simulation_B.qpoptions_f);
  qpoptions->MaxIterations = Simulation_B.temp_a;
  Simulation_B.mIneq_k = Simulation_B.b_WorkingSet.sizes[2] - 1;
  Simulation_B.mLBOrig = Simulation_B.b_WorkingSet.sizes[3] - 33;
  Simulation_B.temp_a = 0;
  for (Simulation_B.nVarOrig = 0; Simulation_B.nVarOrig < 16;
       Simulation_B.nVarOrig++) {
    boolean_T b_tf;
    Simulation_B.idx_positive_tmp = (Simulation_B.b_WorkingSet.isActiveIdx[3] +
      Simulation_B.mLBOrig) + Simulation_B.nVarOrig;
    tf =
      Simulation_B.b_WorkingSet.isActiveConstr.data[Simulation_B.idx_positive_tmp];
    b_tf =
      Simulation_B.b_WorkingSet.isActiveConstr.data[Simulation_B.idx_positive_tmp
      + 16];
    memspace->workspace_int.data[Simulation_B.nVarOrig] = tf;
    memspace->workspace_int.data[Simulation_B.nVarOrig + 16] = b_tf;
    Simulation_B.temp_a = (Simulation_B.temp_a + tf) + b_tf;
  }

  Simulation_B.nVarOrig = 0;
  while (Simulation_B.nVarOrig <= Simulation_B.mIneq_k) {
    tf = Simulation_B.b_WorkingSet.isActiveConstr.data
      [(((Simulation_B.b_WorkingSet.isActiveIdx[3] + Simulation_B.mLBOrig) -
         Simulation_B.mIneq_k) + Simulation_B.nVarOrig) - 1];
    memspace->workspace_int.data[Simulation_B.nVarOrig + 32] = tf;
    Simulation_B.temp_a += tf;
    Simulation_B.nVarOrig++;
  }

  if (TrialState->state != -6) {
    Simulation_B.nVarOrig = (Simulation_B.b_WorkingSet.nVarMax -
      WorkingSet->nVar) - 1;
    Simulation_B.qpfvalLinearExcess = 0.0;
    Simulation_B.qpfvalQuadExcess = 0.0;
    if (Simulation_B.nVarOrig >= 1) {
      Simulation_B.mIneq_k = WorkingSet->nVar + Simulation_B.nVarOrig;
      Simulation_B.mLBOrig = WorkingSet->nVar;
      while (Simulation_B.mLBOrig + 1 <= Simulation_B.mIneq_k) {
        Simulation_B.qpfvalLinearExcess += fabs(TrialState->
          xstar.data[Simulation_B.mLBOrig]);
        Simulation_B.mLBOrig++;
      }

      Simulation_B.mIneq_k = WorkingSet->nVar;
      Simulation_B.mLBOrig = WorkingSet->nVar;
      Simulation_B.idx_positive_tmp = 0;
      while (Simulation_B.idx_positive_tmp <= Simulation_B.nVarOrig - 1) {
        Simulation_B.qpfvalQuadExcess += TrialState->
          xstar.data[Simulation_B.mIneq_k] * TrialState->
          xstar.data[Simulation_B.mLBOrig];
        Simulation_B.mIneq_k++;
        Simulation_B.mLBOrig++;
        Simulation_B.idx_positive_tmp++;
      }
    }

    Simulation_B.beta = (TrialState->fstar - Simulation_B.rho *
                         Simulation_B.qpfvalLinearExcess) - Simulation_B.beta /
      2.0 * Simulation_B.qpfvalQuadExcess;
    Simulation_B.mIneq_k = (WorkingSet->nVarMax - WorkingSet->nVar) - 1;
    Simulation_B.rho = MeritFunction->penaltyParam;
    Simulation_B.qpfvalLinearExcess = 0.0;
    for (Simulation_B.nVarOrig = 0; Simulation_B.nVarOrig < 16;
         Simulation_B.nVarOrig++) {
      Simulation_B.qpfvalLinearExcess += fabs(TrialState->
        cEq[Simulation_B.nVarOrig]);
    }

    Simulation_B.qpfvalQuadExcess = 0.0;
    Simulation_B.nVarOrig = 0;
    while (Simulation_B.nVarOrig <= WorkingSet->sizes[2] - 1) {
      if (TrialState->cIneq.data[Simulation_B.nVarOrig] > 0.0) {
        Simulation_B.qpfvalQuadExcess += TrialState->
          cIneq.data[Simulation_B.nVarOrig];
      }

      Simulation_B.nVarOrig++;
    }

    Simulation_B.qpfvalLinearExcess += Simulation_B.qpfvalQuadExcess;
    Simulation_B.qpfvalQuadExcess = MeritFunction->linearizedConstrViol;
    Simulation_B.y_o3 = 0.0;
    if (Simulation_B.mIneq_k >= 1) {
      Simulation_B.nVarOrig = WorkingSet->nVar + Simulation_B.mIneq_k;
      Simulation_B.mIneq_k = WorkingSet->nVar;
      while (Simulation_B.mIneq_k + 1 <= Simulation_B.nVarOrig) {
        Simulation_B.y_o3 += fabs(TrialState->xstar.data[Simulation_B.mIneq_k]);
        Simulation_B.mIneq_k++;
      }
    }

    MeritFunction->linearizedConstrViol = Simulation_B.y_o3;
    Simulation_B.qpfvalQuadExcess = (Simulation_B.qpfvalLinearExcess +
      Simulation_B.qpfvalQuadExcess) - Simulation_B.y_o3;
    if ((Simulation_B.qpfvalQuadExcess > 2.2204460492503131E-16) &&
        (Simulation_B.beta > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        Simulation_B.rho = 1.0;
      } else {
        Simulation_B.rho = 1.5;
      }

      Simulation_B.rho = Simulation_B.rho * Simulation_B.beta /
        Simulation_B.qpfvalQuadExcess;
    }

    if (Simulation_B.rho < MeritFunction->penaltyParam) {
      MeritFunction->phi = Simulation_B.rho * Simulation_B.qpfvalLinearExcess +
        TrialState->sqpFval;
      if (((MeritFunction->initConstrViolationEq +
            MeritFunction->initConstrViolationIneq) * Simulation_B.rho +
           MeritFunction->initFval) - MeritFunction->phi > static_cast<real_T>
          (MeritFunction->nPenaltyDecreases) * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        if (Simulation_B.rho >= 1.0E-10) {
          MeritFunction->penaltyParam = Simulation_B.rho;
        } else {
          MeritFunction->penaltyParam = 1.0E-10;
        }
      } else {
        MeritFunction->phi = MeritFunction->penaltyParam *
          Simulation_B.qpfvalLinearExcess + TrialState->sqpFval;
      }
    } else {
      if (Simulation_B.rho >= 1.0E-10) {
        MeritFunction->penaltyParam = Simulation_B.rho;
      } else {
        MeritFunction->penaltyParam = 1.0E-10;
      }

      MeritFunction->phi = MeritFunction->penaltyParam *
        Simulation_B.qpfvalLinearExcess + TrialState->sqpFval;
    }

    Simulation_B.beta -= MeritFunction->penaltyParam *
      Simulation_B.qpfvalLinearExcess;
    if (Simulation_B.beta <= 0.0) {
      MeritFunction->phiPrimePlus = Simulation_B.beta;
    } else {
      MeritFunction->phiPrimePlus = 0.0;
    }

    Simulation_B.mIneq_k = Simulation_B.b_WorkingSet.isActiveIdx[1] - 1;
    for (Simulation_B.nVarOrig = 0; Simulation_B.nVarOrig < 16;
         Simulation_B.nVarOrig++) {
      if ((memspace->workspace_int.data[Simulation_B.nVarOrig] != 0) &&
          (memspace->workspace_int.data[Simulation_B.nVarOrig + 16] != 0)) {
        tf = true;
      } else {
        tf = false;
      }

      Simulation_B.mLBOrig = Simulation_B.mIneq_k + Simulation_B.nVarOrig;
      TrialState->lambda.data[Simulation_B.mLBOrig] *= static_cast<real_T>(tf);
    }

    Simulation_B.nVarOrig = Simulation_B.b_WorkingSet.isActiveIdx[2] - 1;
    while (Simulation_B.nVarOrig + 1 <= Simulation_B.b_WorkingSet.nActiveConstr)
    {
      if (Simulation_B.b_WorkingSet.Wid.data[Simulation_B.nVarOrig] == 3) {
        TrialState->lambda.data[Simulation_B.nVarOrig] *= static_cast<real_T>
          (memspace->
           workspace_int.data[Simulation_B.b_WorkingSet.Wlocalidx.data[Simulation_B.nVarOrig]
           + 31]);
      }

      Simulation_B.nVarOrig++;
    }
  }

  Simulation_B.c_WorkingSet = Simulation_B.b_WorkingSet;
  Simulation_B.nVarOrig = (Simulation_B.b_WorkingSet.sizes[3] -
    Simulation_B.b_WorkingSet.sizes[2]) - 32;
  Simulation_B.mIneq_k = Simulation_B.b_WorkingSet.nActiveConstr;
  while ((Simulation_B.mIneq_k > Simulation_B.b_WorkingSet.sizes[0] + 16) &&
         (Simulation_B.temp_a > 0)) {
    if ((Simulation_B.c_WorkingSet.Wid.data[Simulation_B.mIneq_k - 1] == 4) &&
        (Simulation_B.c_WorkingSet.Wlocalidx.data[Simulation_B.mIneq_k - 1] >
         Simulation_B.nVarOrig)) {
      Simulation_B.beta = TrialState->
        lambda.data[Simulation_B.c_WorkingSet.nActiveConstr - 1];
      TrialState->lambda.data[Simulation_B.c_WorkingSet.nActiveConstr - 1] = 0.0;
      TrialState->lambda.data[Simulation_B.mIneq_k - 1] = Simulation_B.beta;
      Simulation_removeConstr(&Simulation_B.c_WorkingSet, Simulation_B.mIneq_k);
      Simulation_B.temp_a--;
    }

    Simulation_B.mIneq_k--;
  }

  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  *WorkingSet = Simulation_B.c_WorkingSet;
  Simulation_setProblemType(WorkingSet, 3);
  Simulation_sortLambdaQP(TrialState->lambda.data, WorkingSet->nActiveConstr,
    WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid.data,
    WorkingSet->Wlocalidx.data, memspace->workspace_double.data);
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static boolean_T Simulation_step_h(int32_T *STEP_TYPE, real_T Hessian[441],
  const real_T lb[21], const real_T ub[21], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
  *TrialState, sG8JZ69axY52WWR6RKyApQC_Simul_T *MeritFunction,
  s_07kFxl6AwaSqE78SXFEtBE_Simu_T *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
  *WorkingSet, s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager,
  s_scny3ZL5wSoGnQzGbzQQC_Simul_T *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Simul_T *qpoptions)
{
  boolean_T checkBoundViolation;
  boolean_T stepSuccess;
  stepSuccess = true;
  checkBoundViolation = true;
  Simulation_B.nVar = WorkingSet->nVar - 1;
  if (*STEP_TYPE != 3) {
    Simulation_B.b_k_h = 0;
    while (Simulation_B.b_k_h <= Simulation_B.nVar) {
      TrialState->xstar.data[Simulation_B.b_k_h] = TrialState->
        xstarsqp[Simulation_B.b_k_h];
      Simulation_B.b_k_h++;
    }
  } else {
    Simulation_B.y_size_idx_0_m = TrialState->searchDir.size;
    Simulation_B.iH0 = TrialState->searchDir.size;
    if (0 <= Simulation_B.iH0 - 1) {
      memcpy(&Simulation_B.y_data_cx[0], &TrialState->searchDir.data[0],
             Simulation_B.iH0 * sizeof(real_T));
    }

    Simulation_B.b_k_h = 0;
    while (Simulation_B.b_k_h <= Simulation_B.nVar) {
      Simulation_B.y_data_cx[Simulation_B.b_k_h] = TrialState->
        xstar.data[Simulation_B.b_k_h];
      Simulation_B.b_k_h++;
    }

    if (0 <= Simulation_B.y_size_idx_0_m - 1) {
      memcpy(&TrialState->searchDir.data[0], &Simulation_B.y_data_cx[0],
             Simulation_B.y_size_idx_0_m * sizeof(real_T));
    }
  }

  int32_T exitg1;
  boolean_T guard1 = false;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
     case 1:
      Simulation_normal(Hessian, TrialState->grad.data, TrialState,
                        MeritFunction, memspace, WorkingSet, QRManager,
                        CholManager, QPObjective, qpoptions);
      if ((TrialState->state <= 0) && (TrialState->state != -6)) {
        *STEP_TYPE = 2;
      } else {
        Simulation_B.y_size_idx_0_m = TrialState->delta_x.size;
        Simulation_B.iH0 = TrialState->delta_x.size;
        if (0 <= Simulation_B.iH0 - 1) {
          memcpy(&Simulation_B.y_data_cx[0], &TrialState->delta_x.data[0],
                 Simulation_B.iH0 * sizeof(real_T));
        }

        Simulation_B.b_k_h = 0;
        while (Simulation_B.b_k_h <= Simulation_B.nVar) {
          Simulation_B.y_data_cx[Simulation_B.b_k_h] = TrialState->
            xstar.data[Simulation_B.b_k_h];
          Simulation_B.b_k_h++;
        }

        if (0 <= Simulation_B.y_size_idx_0_m - 1) {
          memcpy(&TrialState->delta_x.data[0], &Simulation_B.y_data_cx[0],
                 Simulation_B.y_size_idx_0_m * sizeof(real_T));
        }

        guard1 = true;
      }
      break;

     case 2:
      Simulation_removeAllIneqConstr(WorkingSet);
      Simulation_B.y_size_idx_0_m = TrialState->xstar.size;
      Simulation_B.iH0 = TrialState->xstar.size;
      if (0 <= Simulation_B.iH0 - 1) {
        memcpy(&Simulation_B.c_data[0], &TrialState->xstar.data[0],
               Simulation_B.iH0 * sizeof(real_T));
      }

      Simulation_B.b_k_h = 0;
      while (Simulation_B.b_k_h <= WorkingSet->sizes[3] - 1) {
        Simulation_B.nrmGradInf = WorkingSet->lb.data[WorkingSet->
          indexLB.data[Simulation_B.b_k_h] - 1];
        if (-Simulation_B.c_data[WorkingSet->indexLB.data[Simulation_B.b_k_h] -
            1] > Simulation_B.nrmGradInf) {
          if (rtIsInf(ub[WorkingSet->indexLB.data[Simulation_B.b_k_h] - 1])) {
            Simulation_B.c_data[WorkingSet->indexLB.data[Simulation_B.b_k_h] - 1]
              = -Simulation_B.nrmGradInf + fabs(Simulation_B.nrmGradInf);
          } else {
            Simulation_B.c_data[WorkingSet->indexLB.data[Simulation_B.b_k_h] - 1]
              = (WorkingSet->ub.data[WorkingSet->indexLB.data[Simulation_B.b_k_h]
                 - 1] - Simulation_B.nrmGradInf) / 2.0;
          }
        }

        Simulation_B.b_k_h++;
      }

      Simulation_B.b_k_h = 0;
      while (Simulation_B.b_k_h <= WorkingSet->sizes[4] - 1) {
        Simulation_B.nrmGradInf = WorkingSet->ub.data[WorkingSet->
          indexUB.data[Simulation_B.b_k_h] - 1];
        if (Simulation_B.c_data[WorkingSet->indexUB.data[Simulation_B.b_k_h] - 1]
            > Simulation_B.nrmGradInf) {
          if (rtIsInf(lb[WorkingSet->indexUB.data[Simulation_B.b_k_h] - 1])) {
            Simulation_B.c_data[WorkingSet->indexUB.data[Simulation_B.b_k_h] - 1]
              = Simulation_B.nrmGradInf - fabs(Simulation_B.nrmGradInf);
          } else {
            Simulation_B.c_data[WorkingSet->indexUB.data[Simulation_B.b_k_h] - 1]
              = (Simulation_B.nrmGradInf - WorkingSet->lb.data
                 [WorkingSet->indexUB.data[Simulation_B.b_k_h] - 1]) / 2.0;
          }
        }

        Simulation_B.b_k_h++;
      }

      if (0 <= Simulation_B.y_size_idx_0_m - 1) {
        memcpy(&TrialState->xstar.data[0], &Simulation_B.c_data[0],
               Simulation_B.y_size_idx_0_m * sizeof(real_T));
      }

      Simulation_relaxed(Hessian, TrialState->grad.data, TrialState,
                         MeritFunction, memspace, WorkingSet, QRManager,
                         CholManager, QPObjective, qpoptions);
      Simulation_B.y_size_idx_0_m = TrialState->delta_x.size;
      Simulation_B.iH0 = TrialState->delta_x.size;
      if (0 <= Simulation_B.iH0 - 1) {
        memcpy(&Simulation_B.y_data_cx[0], &TrialState->delta_x.data[0],
               Simulation_B.iH0 * sizeof(real_T));
      }

      Simulation_B.b_k_h = 0;
      while (Simulation_B.b_k_h <= Simulation_B.nVar) {
        Simulation_B.y_data_cx[Simulation_B.b_k_h] = TrialState->
          xstar.data[Simulation_B.b_k_h];
        Simulation_B.b_k_h++;
      }

      if (0 <= Simulation_B.y_size_idx_0_m - 1) {
        memcpy(&TrialState->delta_x.data[0], &Simulation_B.y_data_cx[0],
               Simulation_B.y_size_idx_0_m * sizeof(real_T));
      }

      guard1 = true;
      break;

     default:
      stepSuccess = Simulation_soc(Hessian, TrialState->grad.data, TrialState,
        memspace, WorkingSet, QRManager, CholManager, QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (TrialState->state != -6)) {
        Simulation_B.b_k_h = 0;
        while (Simulation_B.b_k_h <= Simulation_B.nVar) {
          TrialState->delta_x.data[Simulation_B.b_k_h] = TrialState->
            xstar.data[Simulation_B.b_k_h] + TrialState->
            socDirection.data[Simulation_B.b_k_h];
          Simulation_B.b_k_h++;
        }
      }

      guard1 = true;
      break;
    }

    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        Simulation_B.nrmGradInf = 0.0;
        Simulation_B.nrmDirInf = 1.0;
        for (Simulation_B.b_k_h = 0; Simulation_B.b_k_h < 21; Simulation_B.b_k_h
             ++) {
          Simulation_B.u1 = fabs(TrialState->grad.data[Simulation_B.b_k_h]);
          if ((!(Simulation_B.nrmGradInf >= Simulation_B.u1)) && (!rtIsNaN
               (Simulation_B.u1))) {
            Simulation_B.nrmGradInf = Simulation_B.u1;
          }

          Simulation_B.u1 = fabs(TrialState->xstar.data[Simulation_B.b_k_h]);
          if ((!(Simulation_B.nrmDirInf >= Simulation_B.u1)) && (!rtIsNaN
               (Simulation_B.u1))) {
            Simulation_B.nrmDirInf = Simulation_B.u1;
          }
        }

        Simulation_B.nrmGradInf /= Simulation_B.nrmDirInf;
        if ((2.2204460492503131E-16 >= Simulation_B.nrmGradInf) || rtIsNaN
            (Simulation_B.nrmGradInf)) {
          Simulation_B.nrmGradInf = 2.2204460492503131E-16;
        }

        for (Simulation_B.b_k_h = 0; Simulation_B.b_k_h < 21; Simulation_B.b_k_h
             ++) {
          Simulation_B.iH0 = 21 * Simulation_B.b_k_h;
          Simulation_B.y_size_idx_0_m = 0;
          while (Simulation_B.y_size_idx_0_m <= Simulation_B.b_k_h - 1) {
            Hessian[Simulation_B.iH0 + Simulation_B.y_size_idx_0_m] = 0.0;
            Simulation_B.y_size_idx_0_m++;
          }

          Hessian[Simulation_B.b_k_h + 21 * Simulation_B.b_k_h] =
            Simulation_B.nrmGradInf;
          Simulation_B.iH0 += Simulation_B.b_k_h;
          Simulation_B.y_size_idx_0_m = 0;
          while (Simulation_B.y_size_idx_0_m <= 19 - Simulation_B.b_k_h) {
            Hessian[(Simulation_B.iH0 + Simulation_B.y_size_idx_0_m) + 1] = 0.0;
            Simulation_B.y_size_idx_0_m++;
          }
        }
      }
    }
  } while (exitg1 == 0);

  if (checkBoundViolation) {
    Simulation_B.y_size_idx_0_m = TrialState->delta_x.size;
    Simulation_B.iH0 = TrialState->delta_x.size;
    if (0 <= Simulation_B.iH0 - 1) {
      memcpy(&Simulation_B.c_data[0], &TrialState->delta_x.data[0],
             Simulation_B.iH0 * sizeof(real_T));
    }

    Simulation_B.nVar = 0;
    while (Simulation_B.nVar <= WorkingSet->sizes[3] - 1) {
      Simulation_B.nrmGradInf = Simulation_B.c_data[WorkingSet->
        indexLB.data[Simulation_B.nVar] - 1];
      Simulation_B.nrmDirInf = (TrialState->xstarsqp[WorkingSet->
        indexLB.data[Simulation_B.nVar] - 1] + Simulation_B.nrmGradInf) -
        lb[WorkingSet->indexLB.data[Simulation_B.nVar] - 1];
      if (Simulation_B.nrmDirInf < 0.0) {
        Simulation_B.c_data[WorkingSet->indexLB.data[Simulation_B.nVar] - 1] =
          Simulation_B.nrmGradInf - Simulation_B.nrmDirInf;
        TrialState->xstar.data[WorkingSet->indexLB.data[Simulation_B.nVar] - 1] -=
          Simulation_B.nrmDirInf;
      }

      Simulation_B.nVar++;
    }

    Simulation_B.nVar = 0;
    while (Simulation_B.nVar <= WorkingSet->sizes[4] - 1) {
      Simulation_B.nrmGradInf = Simulation_B.c_data[WorkingSet->
        indexUB.data[Simulation_B.nVar] - 1];
      Simulation_B.nrmDirInf = (ub[WorkingSet->indexUB.data[Simulation_B.nVar] -
        1] - TrialState->xstarsqp[WorkingSet->indexUB.data[Simulation_B.nVar] -
        1]) - Simulation_B.nrmGradInf;
      if (Simulation_B.nrmDirInf < 0.0) {
        Simulation_B.c_data[WorkingSet->indexUB.data[Simulation_B.nVar] - 1] =
          Simulation_B.nrmGradInf + Simulation_B.nrmDirInf;
        TrialState->xstar.data[WorkingSet->indexUB.data[Simulation_B.nVar] - 1] +=
          Simulation_B.nrmDirInf;
      }

      Simulation_B.nVar++;
    }

    TrialState->delta_x.size = Simulation_B.y_size_idx_0_m;
    if (0 <= Simulation_B.y_size_idx_0_m - 1) {
      memcpy(&TrialState->delta_x.data[0], &Simulation_B.c_data[0],
             Simulation_B.y_size_idx_0_m * sizeof(real_T));
    }
  }

  return stepSuccess;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_evalObjAndConstr(const real_T
  obj_objfun_workspace_runtimedat[4], const real_T
  obj_objfun_workspace_runtimed_0[2], const real_T
  obj_nonlcon_workspace_runtimeda[4], const real_T
  obj_nonlcon_workspace_runtime_0[12], const real_T
  obj_nonlcon_workspace_runtime_1[12], const real_T
  obj_nonlcon_workspace_runtime_2[4], const real_T
  obj_nonlcon_workspace_runtime_3[4], int32_T obj_mCineq, const real_T x[21],
  real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[16], real_T
  *fval, int32_T *status)
{
  int32_T d_size_idx_0;
  int32_T i;
  boolean_T icf[6];
  boolean_T b_x[3];
  Simulation_znlmpc_getXUe(x, obj_objfun_workspace_runtimedat,
    Simulation_B.b_X_b, Simulation_B.U_d, &Simulation_B.e_o);
  Simulation_B.e_o = Simulation_B.b_X_b[4] - obj_objfun_workspace_runtimed_0[0];
  Simulation_B.ic_idx_0_h = Simulation_B.b_X_b[9] -
    obj_objfun_workspace_runtimed_0[1];
  *fval = Simulation_B.e_o * Simulation_B.e_o + Simulation_B.ic_idx_0_h *
    Simulation_B.ic_idx_0_h;
  *status = 1;
  if (rtIsInf(*fval) || rtIsNaN(*fval)) {
    if (rtIsNaN(*fval)) {
      *status = -3;
    } else if (*fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }

  if (*status == 1) {
    int32_T b_U_tmp;
    int32_T ineqEnd;
    boolean_T exitg1;
    boolean_T guard1 = false;
    boolean_T y;
    ineqEnd = (ineq0 + obj_mCineq) - 2;
    Simulation_znlmpc_getXUe(x, obj_nonlcon_workspace_runtimeda,
      Simulation_B.b_X_b, Simulation_B.U_d, &Simulation_B.e_o);
    memset(&Simulation_B.reshapes_f1[0], 0, sizeof(real_T) << 4U);
    Simulation_B.ic_idx_0_h = 1.0;
    Simulation_B.ic_idx_1_l = 2.0;
    Simulation_B.ic_idx_2_h = 3.0;
    Simulation_B.ic_idx_3 = 4.0;
    for (i = 0; i < 5; i++) {
      b_U_tmp = i << 1;
      Simulation_B.b_U_e[b_U_tmp] = Simulation_B.U_d[i];
      Simulation_B.b_U_e[b_U_tmp + 1] = Simulation_B.U_d[i + 5];
      b_U_tmp = i << 2;
      Simulation_B.X_n[b_U_tmp] = Simulation_B.b_X_b[i];
      Simulation_B.X_n[b_U_tmp + 1] = Simulation_B.b_X_b[i + 5];
      Simulation_B.X_n[b_U_tmp + 2] = Simulation_B.b_X_b[i + 10];
      Simulation_B.X_n[b_U_tmp + 3] = Simulation_B.b_X_b[i + 15];
    }

    for (i = 0; i < 4; i++) {
      int32_T reshapes_f1_tmp;
      b_U_tmp = i << 1;
      Simulation_B.fk_tmp = tan(Simulation_B.b_U_e[b_U_tmp + 1]);
      d_size_idx_0 = (i + 1) << 2;
      reshapes_f1_tmp = i << 2;
      Simulation_B.reshapes_f1_tmp = Simulation_B.X_n[d_size_idx_0 + 2];
      Simulation_B.reshapes_f1_tmp_m = Simulation_B.X_n[d_size_idx_0 + 3];
      Simulation_B.yk_idx_0 = Simulation_B.X_n[reshapes_f1_tmp + 2];
      Simulation_B.yk_idx_1 = Simulation_B.X_n[reshapes_f1_tmp + 3];
      Simulation_B.reshapes_f1[static_cast<int32_T>(Simulation_B.ic_idx_0_h) - 1]
        = ((Simulation_B.reshapes_f1_tmp_m * cos(Simulation_B.reshapes_f1_tmp) +
            Simulation_B.yk_idx_1 * cos(Simulation_B.yk_idx_0)) * 0.05 +
           Simulation_B.X_n[reshapes_f1_tmp]) - Simulation_B.X_n[d_size_idx_0];
      Simulation_B.reshapes_f1[static_cast<int32_T>(Simulation_B.ic_idx_1_l) - 1]
        = ((Simulation_B.reshapes_f1_tmp_m * sin(Simulation_B.reshapes_f1_tmp) +
            Simulation_B.yk_idx_1 * sin(Simulation_B.yk_idx_0)) * 0.05 +
           Simulation_B.X_n[reshapes_f1_tmp + 1]) -
        Simulation_B.X_n[d_size_idx_0 + 1];
      Simulation_B.reshapes_f1[static_cast<int32_T>(Simulation_B.ic_idx_2_h) - 1]
        = ((Simulation_B.reshapes_f1_tmp_m * Simulation_B.fk_tmp +
            Simulation_B.yk_idx_1 * Simulation_B.fk_tmp) * 0.05 +
           Simulation_B.yk_idx_0) - Simulation_B.reshapes_f1_tmp;
      Simulation_B.reshapes_f1_tmp = Simulation_B.b_U_e[b_U_tmp];
      Simulation_B.reshapes_f1[static_cast<int32_T>(Simulation_B.ic_idx_3) - 1] =
        (((Simulation_B.reshapes_f1_tmp - Simulation_B.reshapes_f1_tmp_m * 2.3) *
          0.2 + (Simulation_B.reshapes_f1_tmp - Simulation_B.yk_idx_1 * 2.3) *
          0.2) * 0.05 + Simulation_B.yk_idx_1) - Simulation_B.reshapes_f1_tmp_m;
      Simulation_B.ic_idx_0_h += 4.0;
      Simulation_B.ic_idx_1_l += 4.0;
      Simulation_B.ic_idx_2_h += 4.0;
      Simulation_B.ic_idx_3 += 4.0;
    }

    for (i = 0; i < 12; i++) {
      Simulation_B.bv1[i] = rtIsInf(obj_nonlcon_workspace_runtime_0[i]);
    }

    Simulation_all(Simulation_B.bv1, b_x);
    y = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      if (!b_x[i]) {
        y = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    guard1 = false;
    if (y) {
      for (i = 0; i < 12; i++) {
        Simulation_B.bv1[i] = rtIsInf(obj_nonlcon_workspace_runtime_1[i]);
      }

      Simulation_all(Simulation_B.bv1, b_x);
      y = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        if (!b_x[i]) {
          y = false;
          exitg1 = true;
        } else {
          i++;
        }
      }

      if (y) {
        d_size_idx_0 = 0;
        i = 0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      for (i = 0; i < 24; i++) {
        Simulation_B.c_c[i] = 0.0;
        Simulation_B.icf_e[i] = true;
      }

      Simulation_B.ic_idx_0_h = 1.0;
      Simulation_B.ic_idx_1_l = 2.0;
      Simulation_B.ic_idx_2_h = 3.0;
      for (b_U_tmp = 0; b_U_tmp < 4; b_U_tmp++) {
        Simulation_B.ic_idx_3 = obj_nonlcon_workspace_runtime_0[b_U_tmp];
        Simulation_B.icf_e[static_cast<int32_T>(Simulation_B.ic_idx_0_h) - 1] =
          ((!rtIsInf(Simulation_B.ic_idx_3)) && (!rtIsNaN(Simulation_B.ic_idx_3)));
        Simulation_B.ic_idx_3 = obj_nonlcon_workspace_runtime_0[b_U_tmp + 4];
        Simulation_B.icf_e[static_cast<int32_T>(Simulation_B.ic_idx_1_l) - 1] =
          ((!rtIsInf(Simulation_B.ic_idx_3)) && (!rtIsNaN(Simulation_B.ic_idx_3)));
        Simulation_B.fk_tmp = obj_nonlcon_workspace_runtime_0[b_U_tmp + 8];
        Simulation_B.icf_e[static_cast<int32_T>(Simulation_B.ic_idx_2_h) - 1] =
          ((!rtIsInf(Simulation_B.fk_tmp)) && (!rtIsNaN(Simulation_B.fk_tmp)));
        Simulation_B.reshapes_f1_tmp = obj_nonlcon_workspace_runtime_1[b_U_tmp];
        Simulation_B.icf_e[static_cast<int32_T>(Simulation_B.ic_idx_0_h + 3.0) -
          1] = ((!rtIsInf(Simulation_B.reshapes_f1_tmp)) && (!rtIsNaN
                 (Simulation_B.reshapes_f1_tmp)));
        Simulation_B.b_ic[0] = static_cast<int32_T>(Simulation_B.ic_idx_0_h) - 1;
        Simulation_B.b_ic[3] = static_cast<int32_T>(Simulation_B.ic_idx_0_h +
          3.0) - 1;
        Simulation_B.reshapes_f1_tmp = obj_nonlcon_workspace_runtime_1[b_U_tmp +
          4];
        Simulation_B.icf_e[static_cast<int32_T>(Simulation_B.ic_idx_1_l + 3.0) -
          1] = ((!rtIsInf(Simulation_B.reshapes_f1_tmp)) && (!rtIsNaN
                 (Simulation_B.reshapes_f1_tmp)));
        Simulation_B.b_ic[1] = static_cast<int32_T>(Simulation_B.ic_idx_1_l) - 1;
        Simulation_B.b_ic[4] = static_cast<int32_T>(Simulation_B.ic_idx_1_l +
          3.0) - 1;
        Simulation_B.reshapes_f1_tmp_m = obj_nonlcon_workspace_runtime_1[b_U_tmp
          + 8];
        Simulation_B.icf_e[static_cast<int32_T>(Simulation_B.ic_idx_2_h + 3.0) -
          1] = ((!rtIsInf(Simulation_B.reshapes_f1_tmp_m)) && (!rtIsNaN
                 (Simulation_B.reshapes_f1_tmp_m)));
        Simulation_B.b_ic[2] = static_cast<int32_T>(Simulation_B.ic_idx_2_h) - 1;
        Simulation_B.b_ic[5] = static_cast<int32_T>(Simulation_B.ic_idx_2_h +
          3.0) - 1;
        for (i = 0; i < 6; i++) {
          icf[i] = Simulation_B.icf_e[Simulation_B.b_ic[i]];
        }

        if (Simulation_any(icf)) {
          Simulation_B.yk_idx_0 = Simulation_B.b_X_b[b_U_tmp + 1];
          Simulation_B.yk_idx_1 = Simulation_B.b_X_b[b_U_tmp + 6];
          Simulation_B.yk_idx_2 = Simulation_B.b_X_b[b_U_tmp + 11];
          Simulation_B.c_c[static_cast<int32_T>(Simulation_B.ic_idx_0_h) - 1] =
            (obj_nonlcon_workspace_runtime_0[b_U_tmp] - Simulation_B.e_o) -
            Simulation_B.yk_idx_0;
          Simulation_B.c_c[static_cast<int32_T>(Simulation_B.ic_idx_1_l) - 1] =
            (Simulation_B.ic_idx_3 - Simulation_B.e_o) - Simulation_B.yk_idx_1;
          Simulation_B.c_c[static_cast<int32_T>(Simulation_B.ic_idx_2_h) - 1] =
            (Simulation_B.fk_tmp - Simulation_B.e_o) - Simulation_B.yk_idx_2;
          Simulation_B.c_c[static_cast<int32_T>(Simulation_B.ic_idx_0_h + 3.0) -
            1] = (Simulation_B.yk_idx_0 -
                  obj_nonlcon_workspace_runtime_1[b_U_tmp]) - Simulation_B.e_o;
          Simulation_B.c_c[static_cast<int32_T>(Simulation_B.ic_idx_1_l + 3.0) -
            1] = (Simulation_B.yk_idx_1 - Simulation_B.reshapes_f1_tmp) -
            Simulation_B.e_o;
          Simulation_B.c_c[static_cast<int32_T>(Simulation_B.ic_idx_2_h + 3.0) -
            1] = (Simulation_B.yk_idx_2 - Simulation_B.reshapes_f1_tmp_m) -
            Simulation_B.e_o;
        }

        Simulation_B.ic_idx_0_h += 6.0;
        Simulation_B.ic_idx_1_l += 6.0;
        Simulation_B.ic_idx_2_h += 6.0;
      }

      b_U_tmp = 0;
      for (i = 0; i < 24; i++) {
        if (Simulation_B.icf_e[i]) {
          b_U_tmp++;
        }
      }

      d_size_idx_0 = b_U_tmp;
      b_U_tmp = 0;
      for (i = 0; i < 24; i++) {
        if (Simulation_B.icf_e[i]) {
          Simulation_B.d_data_a[b_U_tmp] = static_cast<int8_T>(i + 1);
          b_U_tmp++;
        }
      }

      for (i = 0; i < d_size_idx_0; i++) {
        Simulation_B.c_c_data[i] = Simulation_B.c_c[Simulation_B.d_data_a[i] - 1];
      }

      i = 1;
      if (0 <= d_size_idx_0 - 1) {
        memcpy(&Simulation_B.c_c[0], &Simulation_B.c_c_data[0], d_size_idx_0 *
               sizeof(real_T));
      }
    }

    if (ineq0 > ineqEnd + 1) {
      b_U_tmp = -1;
      ineqEnd = -1;
    } else {
      b_U_tmp = ineq0 - 2;
    }

    if ((d_size_idx_0 != 0) && (i != 0)) {
    } else {
      d_size_idx_0 = 0;
    }

    Simulation_ConstraintFunction(Simulation_B.b_X_b,
      obj_nonlcon_workspace_runtime_2, obj_nonlcon_workspace_runtime_3,
      Simulation_B.tmp_data_c, &i);
    if (0 <= d_size_idx_0 - 1) {
      memcpy(&Simulation_B.b_c_data[0], &Simulation_B.c_c[0], d_size_idx_0 *
             sizeof(real_T));
    }

    for (i = 0; i < 4; i++) {
      Simulation_B.b_c_data[i + d_size_idx_0] = Simulation_B.tmp_data_c[i];
    }

    ineqEnd -= b_U_tmp;
    for (i = 0; i < ineqEnd; i++) {
      Cineq_workspace_data[(b_U_tmp + i) + 1] = Simulation_B.b_c_data[i];
    }

    memcpy(&Ceq_workspace[0], &Simulation_B.reshapes_f1[0], sizeof(real_T) << 4U);
    *status = Simulation_checkVectorNonFinite(obj_mCineq, Cineq_workspace_data,
      ineq0);
    if (*status == 1) {
      *status = Simulati_checkVectorNonFinite_c(Ceq_workspace);
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulati_computeLinearResiduals(const real_T x[21], int32_T nVar,
  real_T workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T
  mLinIneq, const real_T AineqT_data[], const real_T bineq_data[], int32_T ldAi)
{
  if (mLinIneq > 0) {
    int32_T k;
    int32_T loop_ub;
    int32_T y_size_idx_0;
    if (0 <= *workspaceIneq_size - 1) {
      memcpy(&Simulation_B.y_data_m[0], &workspaceIneq_data[0],
             *workspaceIneq_size * sizeof(real_T));
    }

    for (k = 0; k < mLinIneq; k++) {
      Simulation_B.y_data_m[k] = bineq_data[k];
    }

    if (0 <= *workspaceIneq_size - 1) {
      memcpy(&workspaceIneq_data[0], &Simulation_B.y_data_m[0],
             *workspaceIneq_size * sizeof(real_T));
    }

    for (k = 0; k < mLinIneq; k++) {
      workspaceIneq_data[k] = -workspaceIneq_data[k];
    }

    k = 0;
    loop_ub = (mLinIneq - 1) * ldAi + 1;
    y_size_idx_0 = 1;
    while (((ldAi > 0) && (y_size_idx_0 <= loop_ub)) || ((ldAi < 0) &&
            (y_size_idx_0 >= loop_ub))) {
      real_T c;
      int32_T d;
      int32_T ix;
      ix = 0;
      c = 0.0;
      d = (y_size_idx_0 + nVar) - 1;
      for (int32_T ia = y_size_idx_0; ia <= d; ia++) {
        c += AineqT_data[ia - 1] * x[ix];
        ix++;
      }

      workspaceIneq_data[k] += c;
      k++;
      y_size_idx_0 += ldAi;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static real_T Simulation_computeMeritFcn(real_T obj_penaltyParam, real_T fval,
  const real_T Cineq_workspace_data[], int32_T mIneq, const real_T
  Ceq_workspace[16], boolean_T evalWellDefined)
{
  real_T val;
  if (evalWellDefined) {
    real_T constrViolationEq;
    real_T constrViolationIneq;
    int32_T k;
    constrViolationEq = 0.0;
    for (k = 0; k < 16; k++) {
      constrViolationEq += fabs(Ceq_workspace[k]);
    }

    constrViolationIneq = 0.0;
    for (k = 0; k < mIneq; k++) {
      if (Cineq_workspace_data[k] > 0.0) {
        constrViolationIneq += Cineq_workspace_data[k];
      }
    }

    val = (constrViolationEq + constrViolationIneq) * obj_penaltyParam + fval;
  } else {
    val = (rtInf);
  }

  return val;
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_linesearch(boolean_T *evalWellDefined, const real_T
  bineq_data[], int32_T WorkingSet_nVar, int32_T WorkingSet_ldA, const real_T
  WorkingSet_Aineq_data[], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState, real_T
  MeritFunction_penaltyParam, real_T MeritFunction_phi, real_T
  MeritFunction_phiPrimePlus, real_T MeritFunction_phiFullStep, const real_T
  FcnEvaluator_objfun_workspace_r[4], const real_T
  FcnEvaluator_objfun_workspace_0[2], const real_T
  FcnEvaluator_nonlcon_workspace_[4], const real_T
  FcnEvaluator_nonlcon_workspac_0[12], const real_T
  FcnEvaluator_nonlcon_workspac_1[12], const cell_0_Simulation_T
  *FcnEvaluator_nonlcon_workspac_2, int32_T FcnEvaluator_mCineq, boolean_T
  socTaken, real_T *alpha, int32_T *exitflag)
{
  int32_T loop_ub;
  int32_T mLinIneq;
  int32_T y_size_idx_0;
  mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
  *alpha = 1.0;
  *exitflag = 1;
  Simulation_B.phi_alpha = MeritFunction_phiFullStep;
  y_size_idx_0 = TrialState->searchDir.size;
  if (0 <= TrialState->searchDir.size - 1) {
    memcpy(&Simulation_B.y_data_g[0], &TrialState->searchDir.data[0],
           TrialState->searchDir.size * sizeof(real_T));
  }

  for (loop_ub = 0; loop_ub < WorkingSet_nVar; loop_ub++) {
    Simulation_B.y_data_g[loop_ub] = TrialState->delta_x.data[loop_ub];
  }

  if (0 <= y_size_idx_0 - 1) {
    memcpy(&TrialState->searchDir.data[0], &Simulation_B.y_data_g[0],
           y_size_idx_0 * sizeof(real_T));
  }

  int32_T exitg1;
  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 2100) {
      if ((*evalWellDefined) && (Simulation_B.phi_alpha <= *alpha * 0.0001 *
           MeritFunction_phiPrimePlus + MeritFunction_phi)) {
        exitg1 = 1;
      } else {
        boolean_T exitg2;
        boolean_T tooSmallX;
        *alpha *= 0.7;
        for (loop_ub = 0; loop_ub < WorkingSet_nVar; loop_ub++) {
          TrialState->delta_x.data[loop_ub] = *alpha * TrialState->
            xstar.data[loop_ub];
        }

        if (socTaken) {
          Simulation_B.phi_alpha = *alpha * *alpha;
          if ((WorkingSet_nVar >= 1) && (!(Simulation_B.phi_alpha == 0.0))) {
            for (loop_ub = 0; loop_ub < WorkingSet_nVar; loop_ub++) {
              TrialState->delta_x.data[loop_ub] += Simulation_B.phi_alpha *
                TrialState->socDirection.data[loop_ub];
            }
          }
        }

        tooSmallX = true;
        loop_ub = 0;
        exitg2 = false;
        while ((!exitg2) && (loop_ub <= WorkingSet_nVar - 1)) {
          Simulation_B.phi_alpha = fabs(TrialState->xstarsqp[loop_ub]);
          if ((1.0 >= Simulation_B.phi_alpha) || rtIsNaN(Simulation_B.phi_alpha))
          {
            Simulation_B.phi_alpha = 1.0;
          }

          if (1.0E-6 * Simulation_B.phi_alpha <= fabs(TrialState->
               delta_x.data[loop_ub])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            loop_ub++;
          }
        }

        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          for (loop_ub = 0; loop_ub < WorkingSet_nVar; loop_ub++) {
            TrialState->xstarsqp[loop_ub] = TrialState->xstarsqp_old[loop_ub] +
              TrialState->delta_x.data[loop_ub];
          }

          Simulation_evalObjAndConstr(FcnEvaluator_objfun_workspace_r,
            FcnEvaluator_objfun_workspace_0, FcnEvaluator_nonlcon_workspace_,
            FcnEvaluator_nonlcon_workspac_0, FcnEvaluator_nonlcon_workspac_1,
            FcnEvaluator_nonlcon_workspac_2->f1,
            FcnEvaluator_nonlcon_workspac_2->f2, FcnEvaluator_mCineq,
            TrialState->xstarsqp, TrialState->cIneq.data, TrialState->iNonIneq0,
            TrialState->cEq, &TrialState->sqpFval, &loop_ub);
          Simulati_computeLinearResiduals(TrialState->xstarsqp, WorkingSet_nVar,
            TrialState->cIneq.data, &TrialState->cIneq.size, mLinIneq,
            WorkingSet_Aineq_data, bineq_data, WorkingSet_ldA);
          TrialState->FunctionEvaluations++;
          *evalWellDefined = (loop_ub == 1);
          Simulation_B.phi_alpha = Simulation_computeMeritFcn
            (MeritFunction_penaltyParam, TrialState->sqpFval,
             TrialState->cIneq.data, TrialState->mIneq, TrialState->cEq,
             *evalWellDefined);
        }
      }
    } else {
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_driver(const real_T bineq_data[], const real_T lb[21],
  const real_T ub[21], s_Oj8MU04AHs4QRosT0dAtfB_Simu_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Simul_T *MeritFunction, const
  s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T *FcnEvaluator, s_07kFxl6AwaSqE78SXFEtBE_Simu_T
  *memspace, s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T *WorkingSet,
  s_ASr52t7t39LT7rtZ8hZCX_Simul_T *QRManager, s_scny3ZL5wSoGnQzGbzQQC_Simul_T
  *CholManager, s_ollgpvqodLtAhexvVgD8pB_Simu_T *QPObjective, const int32_T
  *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
  real_T Hessian[441])
{
  boolean_T isFeasible;
  static const int8_T j[441] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const char_T h[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  for (Simulation_B.b_k = 0; Simulation_B.b_k < 441; Simulation_B.b_k++) {
    Hessian[Simulation_B.b_k] = j[Simulation_B.b_k];
  }

  Simulation_B.nVar_tmp_tmp = WorkingSet->nVar;
  Simulation_B.mFixed_o = WorkingSet->sizes[0];
  Simulation_B.mIneq_n = WorkingSet->sizes[2];
  Simulation_B.mLB_l = WorkingSet->sizes[3];
  Simulation_B.mUB_p = WorkingSet->sizes[4];
  Simulation_B.mConstr_tmp = (((WorkingSet->sizes[0] + WorkingSet->sizes[2]) +
    WorkingSet->sizes[3]) + WorkingSet->sizes[4]) + 15;
  Simulation_B.mLinIneq_tmp_tmp = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  Simulation_B.u1_o = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) +
                       WorkingSet->sizes[4]) + (WorkingSet->sizes[0] << 1);
  if (WorkingSet->nVar >= Simulation_B.u1_o) {
    Simulation_B.u1_o = WorkingSet->nVar;
  }

  Simulation_B.u1_o *= 10;
  TrialState->steplength = 1.0;
  Simulation_B.Flags.fevalOK = true;
  Simulation_B.Flags.stepAccepted = false;
  Simulation_B.Flags.failedLineSearch = false;
  Simulation_B.Flags.stepType = 1;
  Simulation_B.b_k = 0;
  while (Simulation_B.b_k <= Simulation_B.mConstr_tmp) {
    TrialState->lambdaStopTest.data[Simulation_B.b_k] =
      TrialState->lambdasqp.data[Simulation_B.b_k];
    Simulation_B.b_k++;
  }

  Simulation_computeGradLag(TrialState->gradLag.data, WorkingSet->ldA,
    WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
    WorkingSet->Aineq.data, WorkingSet->Aeq.data, WorkingSet->indexFixed.data,
    WorkingSet->sizes[0], WorkingSet->indexLB.data, WorkingSet->sizes[3],
    WorkingSet->indexUB.data, WorkingSet->sizes[4],
    TrialState->lambdaStopTest.data);
  Simulation_B.optimRelativeFactor = fabs(TrialState->
    grad.data[Simulation_ixamax(WorkingSet->nVar, TrialState->grad.data) - 1]);
  if ((1.0 >= Simulation_B.optimRelativeFactor) || rtIsNaN
      (Simulation_B.optimRelativeFactor)) {
    Simulation_B.optimRelativeFactor = 1.0;
  }

  if (rtIsInf(Simulation_B.optimRelativeFactor)) {
    Simulation_B.optimRelativeFactor = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = Simulati_computePrimalFeasError
    (TrialState->xstarsqp, WorkingSet->sizes[2] - TrialState->mNonlinIneq,
     TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cEq,
     WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
     WorkingSet->indexUB.data, WorkingSet->sizes[4], ub);
  if ((1.0 >= MeritFunction->nlpPrimalFeasError) || rtIsNaN
      (MeritFunction->nlpPrimalFeasError)) {
    MeritFunction->feasRelativeFactor = 1.0;
  } else {
    MeritFunction->feasRelativeFactor = MeritFunction->nlpPrimalFeasError;
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 0.01 *
                MeritFunction->feasRelativeFactor);
  Simulation_computeDualFeasError(WorkingSet->nVar, TrialState->gradLag.data,
    &Simulation_B.Flags.gradOK, &MeritFunction->nlpDualFeasError);
  if (!Simulation_B.Flags.gradOK) {
    Simulation_B.Flags.done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = 0.0;
    if (MeritFunction->nlpDualFeasError >= 0.0) {
      MeritFunction->firstOrderOpt = MeritFunction->nlpDualFeasError;
    } else {
      MeritFunction->firstOrderOpt = 0.0;
    }

    Simulation_B.b_k = 0;
    while (Simulation_B.b_k <= Simulation_B.mConstr_tmp) {
      TrialState->lambdaStopTestPrev.data[Simulation_B.b_k] =
        TrialState->lambdaStopTest.data[Simulation_B.b_k];
      Simulation_B.b_k++;
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 *
                       Simulation_B.optimRelativeFactor)) {
      Simulation_B.Flags.done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Simulation_B.Flags.done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Simulation_B.Flags.done = true;
        TrialState->sqpExitFlag = -3;
      }
    }
  }

  Simulation_saveJacobian(TrialState, WorkingSet->nVar, WorkingSet->sizes[2],
    WorkingSet->Aineq.data, TrialState->iNonIneq0, WorkingSet->Aeq.data,
    WorkingSet->ldA);
  Simulation_saveState(TrialState);
  if (!Simulation_B.Flags.done) {
    TrialState->sqpIterations = 1;
  }

  while (!Simulation_B.Flags.done) {
    if ((!Simulation_B.Flags.stepAccepted) &&
        (!Simulation_B.Flags.failedLineSearch)) {
      Simulation_B.expl_temp_b.IterDisplayQP = false;
      Simulation_B.expl_temp_b.RemainFeasible = false;
      Simulation_B.expl_temp_b.ProbRelTolFactor = 1.0;
      Simulation_B.expl_temp_b.ConstrRelTolFactor = 1.0;
      Simulation_B.expl_temp_b.PricingTolerance = 0.0;
      Simulation_B.expl_temp_b.ObjectiveLimit = (rtMinusInf);
      Simulation_B.expl_temp_b.ConstraintTolerance = 0.01;
      Simulation_B.expl_temp_b.OptimalityTolerance = 2.2204460492503131E-14;
      Simulation_B.expl_temp_b.StepTolerance = 1.0E-6;
      Simulation_B.expl_temp_b.MaxIterations = Simulation_B.u1_o;
      for (Simulation_B.b_k = 0; Simulation_B.b_k < 7; Simulation_B.b_k++) {
        Simulation_B.expl_temp_b.SolverName[Simulation_B.b_k] =
          h[Simulation_B.b_k];
      }
    }

    while ((!Simulation_B.Flags.stepAccepted) &&
           (!Simulation_B.Flags.failedLineSearch)) {
      if (Simulation_B.Flags.stepType != 3) {
        Simu_updateWorkingSetForNewQP_m(TrialState->xstarsqp, WorkingSet,
          Simulation_B.mIneq_n, TrialState->mNonlinIneq, TrialState->cIneq.data,
          TrialState->cEq, Simulation_B.mLB_l, lb, Simulation_B.mUB_p, ub,
          Simulation_B.mFixed_o);
      }

      Simulation_B.expl_temp_j = Simulation_B.expl_temp_b;
      Simulation_B.Flags.stepAccepted = Simulation_step_h
        (&Simulation_B.Flags.stepType, Hessian, lb, ub, TrialState,
         MeritFunction, memspace, WorkingSet, QRManager, CholManager,
         QPObjective, &Simulation_B.expl_temp_j);
      if (Simulation_B.Flags.stepAccepted) {
        Simulation_B.b_k = 0;
        while (Simulation_B.b_k <= Simulation_B.nVar_tmp_tmp - 1) {
          TrialState->xstarsqp[Simulation_B.b_k] += TrialState->
            delta_x.data[Simulation_B.b_k];
          Simulation_B.b_k++;
        }

        Simulation_evalObjAndConstr(FcnEvaluator->objfun.workspace.runtimedata.x,
          FcnEvaluator->objfun.workspace.runtimedata.Parameters.f3,
          FcnEvaluator->nonlcon.workspace.runtimedata.x,
          FcnEvaluator->nonlcon.workspace.runtimedata.OutputMin,
          FcnEvaluator->nonlcon.workspace.runtimedata.OutputMax,
          FcnEvaluator->nonlcon.workspace.runtimedata.Parameters.f1,
          FcnEvaluator->nonlcon.workspace.runtimedata.Parameters.f2,
          FcnEvaluator->mCineq, TrialState->xstarsqp, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->cEq, &TrialState->sqpFval,
          &Simulation_B.b_k);
        Simulation_B.Flags.fevalOK = (Simulation_B.b_k == 1);
        TrialState->FunctionEvaluations++;
        Simulati_computeLinearResiduals(TrialState->xstarsqp,
          Simulation_B.nVar_tmp_tmp, TrialState->cIneq.data,
          &TrialState->cIneq.size, Simulation_B.mLinIneq_tmp_tmp,
          WorkingSet->Aineq.data, bineq_data, WorkingSet->ldA);
        MeritFunction->phiFullStep = Simulation_computeMeritFcn
          (MeritFunction->penaltyParam, TrialState->sqpFval,
           TrialState->cIneq.data, Simulation_B.mIneq_n, TrialState->cEq,
           Simulation_B.Flags.fevalOK);
      }

      if ((Simulation_B.Flags.stepType == 1) && Simulation_B.Flags.stepAccepted &&
          Simulation_B.Flags.fevalOK && (MeritFunction->phi <
           MeritFunction->phiFullStep) && (TrialState->sqpFval <
           TrialState->sqpFval_old)) {
        Simulation_B.Flags.stepType = 3;
        Simulation_B.Flags.stepAccepted = false;
      } else {
        Simulation_linesearch(&Simulation_B.Flags.fevalOK, bineq_data,
                              WorkingSet->nVar, WorkingSet->ldA,
                              WorkingSet->Aineq.data, TrialState,
                              MeritFunction->penaltyParam, MeritFunction->phi,
                              MeritFunction->phiPrimePlus,
                              MeritFunction->phiFullStep,
                              FcnEvaluator->objfun.workspace.runtimedata.x,
                              FcnEvaluator->objfun.workspace.runtimedata.Parameters.f3,
                              FcnEvaluator->nonlcon.workspace.runtimedata.x,
                              FcnEvaluator->nonlcon.workspace.runtimedata.OutputMin,
                              FcnEvaluator->nonlcon.workspace.runtimedata.OutputMax,
                              &FcnEvaluator->nonlcon.workspace.runtimedata.Parameters,
                              FcnEvaluator->mCineq, (Simulation_B.Flags.stepType
          == 3) && Simulation_B.Flags.stepAccepted,
                              &Simulation_B.optimRelativeFactor,
                              &Simulation_B.b_k);
        TrialState->steplength = Simulation_B.optimRelativeFactor;
        if (Simulation_B.b_k > 0) {
          Simulation_B.Flags.stepAccepted = true;
        } else {
          Simulation_B.Flags.failedLineSearch = true;
        }
      }
    }

    if (Simulation_B.Flags.stepAccepted && (!Simulation_B.Flags.failedLineSearch))
    {
      Simulation_B.b_k = 0;
      while (Simulation_B.b_k <= Simulation_B.nVar_tmp_tmp - 1) {
        TrialState->xstarsqp[Simulation_B.b_k] = TrialState->
          xstarsqp_old[Simulation_B.b_k] + TrialState->
          delta_x.data[Simulation_B.b_k];
        Simulation_B.b_k++;
      }

      Simulation_B.b_k = 0;
      while (Simulation_B.b_k <= Simulation_B.mConstr_tmp) {
        TrialState->lambdasqp.data[Simulation_B.b_k] += (TrialState->
          lambda.data[Simulation_B.b_k] - TrialState->
          lambdasqp.data[Simulation_B.b_k]) * TrialState->steplength;
        Simulation_B.b_k++;
      }

      Simulation_saveState(TrialState);
      Simulation_B.Flags.gradOK = true;
      evalObjAndConstrAndDerivatives
        (FcnEvaluator->objfun.workspace.runtimedata.x,
         FcnEvaluator->objfun.workspace.runtimedata.Parameters.f3,
         FcnEvaluator->nonlcon.workspace.runtimedata.x,
         FcnEvaluator->nonlcon.workspace.runtimedata.OutputMin,
         FcnEvaluator->nonlcon.workspace.runtimedata.OutputMax,
         FcnEvaluator->nonlcon.workspace.runtimedata.Parameters.f1,
         FcnEvaluator->nonlcon.workspace.runtimedata.Parameters.f2,
         FcnEvaluator->mCineq, TrialState->xstarsqp, TrialState->grad.data,
         TrialState->cIneq.data, TrialState->iNonIneq0, TrialState->cEq,
         WorkingSet->Aineq.data, TrialState->iNonIneq0, WorkingSet->ldA,
         WorkingSet->Aeq.data, WorkingSet->ldA, &TrialState->sqpFval,
         &Simulation_B.b_k);
      TrialState->FunctionEvaluations++;
      Simulation_B.Flags.fevalOK = (Simulation_B.b_k == 1);
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0], 21U *
             sizeof(real_T));
      Simulation_B.ix_p = TrialState->cIneq.size;
      Simulation_B.b_ix = TrialState->cIneq.size;
      if (0 <= Simulation_B.b_ix - 1) {
        memcpy(&Simulation_B.y_data_k[0], &TrialState->cIneq.data[0],
               Simulation_B.b_ix * sizeof(real_T));
      }

      Simulation_B.b_k = 0;
      while (Simulation_B.b_k <= TrialState->mIneq - 1) {
        Simulation_B.y_data_k[Simulation_B.b_k] = TrialState->
          cIneq_old.data[Simulation_B.b_k];
        Simulation_B.b_k++;
      }

      if (0 <= Simulation_B.ix_p - 1) {
        memcpy(&TrialState->cIneq.data[0], &Simulation_B.y_data_k[0],
               Simulation_B.ix_p * sizeof(real_T));
      }

      memcpy(&TrialState->cEq[0], &TrialState->cEq_old[0], sizeof(real_T) << 4U);
    }

    Simulation_test_exit(&Simulation_B.Flags, memspace, MeritFunction,
                         fscales_lineq_constraint_size,
                         fscales_cineq_constraint_size, WorkingSet, TrialState,
                         QRManager, lb, ub);
    if ((!Simulation_B.Flags.done) && Simulation_B.Flags.stepAccepted) {
      Simulation_B.Flags.stepAccepted = false;
      Simulation_B.Flags.stepType = 1;
      Simulation_B.Flags.failedLineSearch = false;
      Simulation_B.b_ix = Simulation_B.mFixed_o + TrialState->iNonIneq0;
      Simulation_B.b_k = WorkingSet->ldA;
      Simulation_B.ix_p = 0;
      while (Simulation_B.ix_p <= Simulation_B.nVar_tmp_tmp - 1) {
        TrialState->delta_gradLag.data[Simulation_B.ix_p] =
          TrialState->grad.data[Simulation_B.ix_p];
        Simulation_B.ix_p++;
      }

      if (Simulation_B.nVar_tmp_tmp >= 1) {
        Simulation_B.ix_p = 0;
        while (Simulation_B.ix_p <= Simulation_B.nVar_tmp_tmp - 1) {
          TrialState->delta_gradLag.data[Simulation_B.ix_p] +=
            -TrialState->grad_old.data[Simulation_B.ix_p];
          Simulation_B.ix_p++;
        }
      }

      Simulation_xgemv_la4x4rhx2l0j(Simulation_B.nVar_tmp_tmp, 16,
        WorkingSet->Aeq.data, 1, WorkingSet->ldA, TrialState->lambdasqp.data,
        Simulation_B.mFixed_o + 1, TrialState->delta_gradLag.data);
      Simulation_B.ix_p = Simulation_B.mFixed_o;
      Simulation_B.c_f = WorkingSet->ldA * 15 + 1;
      Simulation_B.b_iy = 1;
      while (((Simulation_B.b_k > 0) && (Simulation_B.b_iy <= Simulation_B.c_f))
             || ((Simulation_B.b_k < 0) && (Simulation_B.b_iy >=
               Simulation_B.c_f))) {
        Simulation_B.iy = 0;
        Simulation_B.b_ia = (Simulation_B.b_iy + Simulation_B.nVar_tmp_tmp) - 1;
        Simulation_B.ia_i = Simulation_B.b_iy;
        while (Simulation_B.ia_i <= Simulation_B.b_ia) {
          TrialState->delta_gradLag.data[Simulation_B.iy] +=
            TrialState->JacCeqTrans_old.data[Simulation_B.ia_i - 1] *
            -TrialState->lambdasqp.data[Simulation_B.ix_p];
          Simulation_B.iy++;
          Simulation_B.ia_i++;
        }

        Simulation_B.ix_p++;
        Simulation_B.b_iy += Simulation_B.b_k;
      }

      if (TrialState->mNonlinIneq > 0) {
        Simulation_xgemv_la4x4rhx2l0j(Simulation_B.nVar_tmp_tmp,
          TrialState->mNonlinIneq, WorkingSet->Aineq.data, WorkingSet->ldA *
          (TrialState->iNonIneq0 - 1) + 1, WorkingSet->ldA,
          TrialState->lambdasqp.data, Simulation_B.b_ix + 16,
          TrialState->delta_gradLag.data);
        Simulation_B.ix_p = (TrialState->mNonlinIneq - 1) * WorkingSet->ldA + 1;
        Simulation_B.c_f = 1;
        while (((Simulation_B.b_k > 0) && (Simulation_B.c_f <= Simulation_B.ix_p))
               || ((Simulation_B.b_k < 0) && (Simulation_B.c_f >=
                 Simulation_B.ix_p))) {
          Simulation_B.b_iy = 0;
          Simulation_B.iy = (Simulation_B.c_f + Simulation_B.nVar_tmp_tmp) - 1;
          Simulation_B.b_ia = Simulation_B.c_f;
          while (Simulation_B.b_ia <= Simulation_B.iy) {
            TrialState->delta_gradLag.data[Simulation_B.b_iy] +=
              TrialState->JacCineqTrans_old.data[Simulation_B.b_ia - 1] *
              -TrialState->lambdasqp.data[Simulation_B.b_ix + 15];
            Simulation_B.b_iy++;
            Simulation_B.b_ia++;
          }

          Simulation_B.b_ix++;
          Simulation_B.c_f += Simulation_B.b_k;
        }
      }

      Simulation_saveJacobian(TrialState, Simulation_B.nVar_tmp_tmp,
        Simulation_B.mIneq_n, WorkingSet->Aineq.data, TrialState->iNonIneq0,
        WorkingSet->Aeq.data, WorkingSet->ldA);
      Simulation_BFGSUpdate(Simulation_B.nVar_tmp_tmp, Hessian,
                            TrialState->delta_x.data,
                            TrialState->delta_gradLag.data,
                            memspace->workspace_double.data);
      TrialState->sqpIterations++;
    }
  }
}

/* Function for MATLAB Function: '<S12>/NLMPC' */
static void Simulation_fmincon(const s_p8D01swky5RV3KRPR0QFHD_Simu_T
  *fun_workspace_runtimedata, const sGG2r25KPyhmOjq8dWjrTNG_Simul_T
  *fun_workspace_userdata, const real_T x0[21], const real_T Aineq_data[], const
  real_T bineq_data[], const int32_T *bineq_size, const real_T lb[21], const
  real_T ub[21], const s_p8D01swky5RV3KRPR0QFHD_Simu_T
  *nonlcon_workspace_runtimedata, const sGG2r25KPyhmOjq8dWjrTNG_Simul_T
  *nonlcon_workspace_userdata, real_T x[21], real_T *fval, real_T *exitflag,
  sttYSJM5GCi2c1Eu0R50efC_Simul_T *output)
{
  Simulat_eML_blk_kernel_anonFcn2(nonlcon_workspace_runtimedata->x,
    nonlcon_workspace_runtimedata->OutputMin,
    nonlcon_workspace_runtimedata->OutputMax,
    nonlcon_workspace_runtimedata->Parameters.f1,
    nonlcon_workspace_runtimedata->Parameters.f2, x0, Simulation_B.Cineq_data,
    Simulation_B.Cineq_size, Simulation_B.Ceq, Simulation_B.JacCineqTrans_data,
    Simulation_B.JacCineqTrans_size, Simulation_B.JacCeqTrans);
  Simulation_B.c_k = Simulation_B.Cineq_size[0] * Simulation_B.Cineq_size[1];
  Simulation_B.mIneq = *bineq_size + Simulation_B.c_k;
  Simulation_B.mConstrMax = (Simulation_B.mIneq + Simulation_B.mIneq) + 91;
  if (Simulation_B.mIneq + 54 >= Simulation_B.mConstrMax) {
    Simulation_B.maxDims = Simulation_B.mIneq + 54;
  } else {
    Simulation_B.maxDims = Simulation_B.mConstrMax;
  }

  Simulation_factoryConstruct(Simulation_B.mIneq + 54, Simulation_B.mConstrMax,
    Simulation_B.mIneq, Simulation_B.c_k, &Simulation_B.TrialState);
  Simulation_B.FcnEvaluator.objfun.workspace.runtimedata =
    *fun_workspace_runtimedata;
  Simulation_B.FcnEvaluator.objfun.workspace.userdata = *fun_workspace_userdata;
  Simulation_B.FcnEvaluator.nonlcon.workspace.runtimedata =
    *nonlcon_workspace_runtimedata;
  Simulation_B.FcnEvaluator.nonlcon.workspace.userdata =
    *nonlcon_workspace_userdata;
  Simulation_B.FcnEvaluator.mCineq = Simulation_B.c_k;
  Simulation_B.FcnEvaluator.nVar = 21;
  Simulation_B.FcnEvaluator.mCeq = 16;
  Simulation_B.FcnEvaluator.NonFiniteSupport = true;
  Simulation_B.FcnEvaluator.SpecifyObjectiveGradient = true;
  Simulation_B.FcnEvaluator.SpecifyConstraintGradient = true;
  Simulation_B.FcnEvaluator.ScaleProblem = false;
  Simulatio_factoryConstruct_cyd0(Simulation_B.mIneq + 54,
    &Simulation_B.QPObjective.grad.size, &Simulation_B.QPObjective.Hx.size,
    &Simulation_B.QPObjective.hasLinear, &Simulation_B.QPObjective.nvar,
    &Simulation_B.QPObjective.maxVar, &Simulation_B.QPObjective.beta,
    &Simulation_B.QPObjective.rho, &Simulation_B.QPObjective.objtype,
    &Simulation_B.QPObjective.prev_objtype, &Simulation_B.QPObjective.prev_nvar,
    &Simulation_B.QPObjective.prev_hasLinear,
    &Simulation_B.QPObjective.gammaScalar);
  Simulation_B.QPObjective.nvar = 21;
  Simulation_B.QPObjective.hasLinear = true;
  Simulation_B.QPObjective.objtype = 3;
  Simulation_B.memspace.workspace_double.size[0] = Simulation_B.maxDims;
  Simulation_B.memspace.workspace_double.size[1] = Simulation_B.mIneq + 54;
  Simulation_B.memspace.workspace_int.size = Simulation_B.maxDims;
  Simulation_B.memspace.workspace_sort.size = Simulation_B.maxDims;
  Simulati_factoryConstruct_cyd03(Simulation_B.mIneq, Simulation_B.mIneq + 54,
    Simulation_B.mConstrMax, &Simulation_B.WorkingSet);
  Simulation_B.mLB = 0;
  Simulation_B.mUB = 0;
  Simulation_B.mFixed = 0;
  for (Simulation_B.k = 0; Simulation_B.k < 21; Simulation_B.k++) {
    boolean_T guard1 = false;
    Simulation_B.TrialState.xstarsqp[Simulation_B.k] = x0[Simulation_B.k];
    Simulation_B.b_c_i = ub[Simulation_B.k];
    Simulation_B.scale = lb[Simulation_B.k];
    guard1 = false;
    if ((!rtIsInf(Simulation_B.scale)) && (!rtIsNaN(Simulation_B.scale))) {
      if (fabs(Simulation_B.scale - Simulation_B.b_c_i) < 0.01) {
        Simulation_B.mFixed++;
        Simulation_B.WorkingSet.indexFixed.data[Simulation_B.mFixed - 1] =
          Simulation_B.k + 1;
      } else {
        Simulation_B.mLB++;
        Simulation_B.WorkingSet.indexLB.data[Simulation_B.mLB - 1] =
          Simulation_B.k + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if ((!rtIsInf(Simulation_B.b_c_i)) && (!rtIsNaN(Simulation_B.b_c_i))) {
        Simulation_B.mUB++;
        Simulation_B.WorkingSet.indexUB.data[Simulation_B.mUB - 1] =
          Simulation_B.k + 1;
      }
    }
  }

  Simulation_loadProblem(&Simulation_B.WorkingSet, Simulation_B.mIneq,
    *bineq_size, Aineq_data, Simulation_B.mLB, Simulation_B.mUB,
    Simulation_B.mFixed, Simulation_B.mConstrMax);
  Simulation_B.mConstrMax = 0;
  while (Simulation_B.mConstrMax <= Simulation_B.mLB - 1) {
    Simulation_B.b_c_i =
      Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexLB.data[Simulation_B.mConstrMax]
      - 1];
    Simulation_B.scale =
      lb[Simulation_B.WorkingSet.indexLB.data[Simulation_B.mConstrMax] - 1];
    if ((Simulation_B.b_c_i >= Simulation_B.scale) || rtIsNaN(Simulation_B.scale))
    {
      Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexLB.data[Simulation_B.mConstrMax]
        - 1] = Simulation_B.b_c_i;
    } else {
      Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexLB.data[Simulation_B.mConstrMax]
        - 1] = Simulation_B.scale;
    }

    Simulation_B.mConstrMax++;
  }

  Simulation_B.mConstrMax = 0;
  while (Simulation_B.mConstrMax <= Simulation_B.mUB - 1) {
    Simulation_B.b_c_i =
      Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexUB.data[Simulation_B.mConstrMax]
      - 1];
    Simulation_B.scale =
      ub[Simulation_B.WorkingSet.indexUB.data[Simulation_B.mConstrMax] - 1];
    if ((Simulation_B.b_c_i <= Simulation_B.scale) || rtIsNaN(Simulation_B.scale))
    {
      Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexUB.data[Simulation_B.mConstrMax]
        - 1] = Simulation_B.b_c_i;
    } else {
      Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexUB.data[Simulation_B.mConstrMax]
        - 1] = Simulation_B.scale;
    }

    Simulation_B.mConstrMax++;
  }

  Simulation_B.mConstrMax = 0;
  while (Simulation_B.mConstrMax <= Simulation_B.mFixed - 1) {
    Simulation_B.TrialState.xstarsqp[Simulation_B.WorkingSet.indexFixed.data[Simulation_B.mConstrMax]
      - 1] = ub[Simulation_B.WorkingSet.indexFixed.data[Simulation_B.mConstrMax]
      - 1];
    Simulation_B.mConstrMax++;
  }

  evalObjAndConstrAndDerivatives(fun_workspace_runtimedata->x,
    fun_workspace_runtimedata->Parameters.f3, nonlcon_workspace_runtimedata->x,
    nonlcon_workspace_runtimedata->OutputMin,
    nonlcon_workspace_runtimedata->OutputMax,
    nonlcon_workspace_runtimedata->Parameters.f1,
    nonlcon_workspace_runtimedata->Parameters.f2, Simulation_B.c_k,
    Simulation_B.TrialState.xstarsqp, Simulation_B.TrialState.grad.data,
    Simulation_B.TrialState.cIneq.data, Simulation_B.TrialState.iNonIneq0,
    Simulation_B.TrialState.cEq, Simulation_B.WorkingSet.Aineq.data,
    Simulation_B.TrialState.iNonIneq0, Simulation_B.WorkingSet.ldA,
    Simulation_B.WorkingSet.Aeq.data, Simulation_B.WorkingSet.ldA,
    &Simulation_B.TrialState.sqpFval, &Simulation_B.mConstrMax);
  Simulation_B.TrialState.FunctionEvaluations = 1;
  Simulation_B.mConstrMax = Simulation_B.WorkingSet.ldA;
  if (*bineq_size > 0) {
    Simulation_B.y_size_idx_0 = Simulation_B.TrialState.cIneq.size;
    Simulation_B.loop_ub = Simulation_B.TrialState.cIneq.size;
    if (0 <= Simulation_B.loop_ub - 1) {
      memcpy(&Simulation_B.y_data_c[0], &Simulation_B.TrialState.cIneq.data[0],
             Simulation_B.loop_ub * sizeof(real_T));
    }

    Simulation_B.k = 0;
    while (Simulation_B.k <= *bineq_size - 1) {
      Simulation_B.y_data_c[Simulation_B.k] = bineq_data[Simulation_B.k];
      Simulation_B.k++;
    }

    if (0 <= Simulation_B.y_size_idx_0 - 1) {
      memcpy(&Simulation_B.TrialState.cIneq.data[0], &Simulation_B.y_data_c[0],
             Simulation_B.y_size_idx_0 * sizeof(real_T));
    }

    Simulation_B.k = 0;
    while (Simulation_B.k <= *bineq_size - 1) {
      Simulation_B.TrialState.cIneq.data[Simulation_B.k] =
        -Simulation_B.TrialState.cIneq.data[Simulation_B.k];
      Simulation_B.k++;
    }

    Simulation_B.k = 0;
    Simulation_B.loop_ub = (*bineq_size - 1) * Simulation_B.WorkingSet.ldA + 1;
    Simulation_B.y_size_idx_0 = 1;
    while (((Simulation_B.mConstrMax > 0) && (Simulation_B.y_size_idx_0 <=
             Simulation_B.loop_ub)) || ((Simulation_B.mConstrMax < 0) &&
            (Simulation_B.y_size_idx_0 >= Simulation_B.loop_ub))) {
      Simulation_B.ix = 0;
      Simulation_B.b_c_i = 0.0;
      Simulation_B.ia = Simulation_B.y_size_idx_0;
      while (Simulation_B.ia <= Simulation_B.y_size_idx_0 + 20) {
        Simulation_B.b_c_i += Simulation_B.WorkingSet.Aineq.data[Simulation_B.ia
          - 1] * Simulation_B.TrialState.xstarsqp[Simulation_B.ix];
        Simulation_B.ix++;
        Simulation_B.ia++;
      }

      Simulation_B.TrialState.cIneq.data[Simulation_B.k] += Simulation_B.b_c_i;
      Simulation_B.k++;
      Simulation_B.y_size_idx_0 += Simulation_B.mConstrMax;
    }
  }

  Simula_updateWorkingSetForNewQP(x0, &Simulation_B.WorkingSet,
    Simulation_B.mIneq, Simulation_B.TrialState.cIneq.data,
    Simulation_B.TrialState.cEq, Simulation_B.mLB, lb, Simulation_B.mUB, ub,
    Simulation_B.mFixed);
  Simulation_initActiveSet(&Simulation_B.WorkingSet);
  Simulation_B.MeritFunction.initFval = Simulation_B.TrialState.sqpFval;
  Simulation_B.MeritFunction.penaltyParam = 1.0;
  Simulation_B.MeritFunction.threshold = 0.0001;
  Simulation_B.MeritFunction.nPenaltyDecreases = 0;
  Simulation_B.MeritFunction.linearizedConstrViol = 0.0;
  Simulation_B.b_c_i = 0.0;
  for (Simulation_B.mLB = 0; Simulation_B.mLB < 16; Simulation_B.mLB++) {
    Simulation_B.b_c_i += fabs(Simulation_B.TrialState.cEq[Simulation_B.mLB]);
  }

  Simulation_B.MeritFunction.initConstrViolationEq = Simulation_B.b_c_i;
  Simulation_B.b_c_i = 0.0;
  Simulation_B.mLB = 0;
  while (Simulation_B.mLB <= Simulation_B.mIneq - 1) {
    if (Simulation_B.TrialState.cIneq.data[Simulation_B.mLB] > 0.0) {
      Simulation_B.b_c_i += Simulation_B.TrialState.cIneq.data[Simulation_B.mLB];
    }

    Simulation_B.mLB++;
  }

  Simulation_B.MeritFunction.initConstrViolationIneq = Simulation_B.b_c_i;
  Simulation_B.MeritFunction.phi = 0.0;
  Simulation_B.MeritFunction.phiPrimePlus = 0.0;
  Simulation_B.MeritFunction.phiFullStep = 0.0;
  Simulation_B.MeritFunction.feasRelativeFactor = 0.0;
  Simulation_B.MeritFunction.nlpPrimalFeasError = 0.0;
  Simulation_B.MeritFunction.nlpDualFeasError = 0.0;
  Simulation_B.MeritFunction.nlpComplError = 0.0;
  Simulation_B.MeritFunction.firstOrderOpt = 0.0;
  Simulation_B.MeritFunction.hasObjective = true;
  Simulation_factoryConstruct_cy(Simulation_B.maxDims, Simulation_B.maxDims,
    &Simulation_B.QRManager.ldq, Simulation_B.QRManager.QR.size,
    Simulation_B.QRManager.Q.data, Simulation_B.QRManager.Q.size,
    Simulation_B.QRManager.jpvt.data, &Simulation_B.QRManager.jpvt.size,
    &Simulation_B.QRManager.mrows, &Simulation_B.QRManager.ncols,
    &Simulation_B.QRManager.tau.size, &Simulation_B.QRManager.minRowCol,
    &Simulation_B.QRManager.usedPivoting);
  Simulation_factoryConstruct_cyd(Simulation_B.maxDims,
    Simulation_B.CholManager.FMat.size, &Simulation_B.CholManager.ldm,
    &Simulation_B.CholManager.ndims, &Simulation_B.CholManager.info,
    &Simulation_B.CholManager.scaleFactor, &Simulation_B.CholManager.ConvexCheck,
    &Simulation_B.CholManager.regTol_, &Simulation_B.CholManager.workspace_,
    &Simulation_B.CholManager.workspace2_);
  Simulation_B.tmp_size_p = *bineq_size;
  Simulation_B.tmp_size_m = Simulation_B.c_k;
  Simulation_driver(bineq_data, lb, ub, &Simulation_B.TrialState,
                    &Simulation_B.MeritFunction, &Simulation_B.FcnEvaluator,
                    &Simulation_B.memspace, &Simulation_B.WorkingSet,
                    &Simulation_B.QRManager, &Simulation_B.CholManager,
                    &Simulation_B.QPObjective, &Simulation_B.tmp_size_p,
                    &Simulation_B.tmp_size_m, Simulation_B.unusedExpr);
  *fval = Simulation_B.TrialState.sqpFval;
  *exitflag = Simulation_B.TrialState.sqpExitFlag;
  output->iterations = Simulation_B.TrialState.sqpIterations;
  output->funcCount = Simulation_B.TrialState.FunctionEvaluations;
  output->algorithm[0] = 's';
  output->algorithm[1] = 'q';
  output->algorithm[2] = 'p';
  output->constrviolation = Simulation_B.MeritFunction.nlpPrimalFeasError;
  Simulation_B.b_c_i = 0.0;
  Simulation_B.scale = 3.3121686421112381E-170;
  for (Simulation_B.c_k = 0; Simulation_B.c_k < 21; Simulation_B.c_k++) {
    x[Simulation_B.c_k] = Simulation_B.TrialState.xstarsqp[Simulation_B.c_k];
    Simulation_B.absxk = fabs
      (Simulation_B.TrialState.delta_x.data[Simulation_B.c_k]);
    if (Simulation_B.absxk > Simulation_B.scale) {
      Simulation_B.t = Simulation_B.scale / Simulation_B.absxk;
      Simulation_B.b_c_i = Simulation_B.b_c_i * Simulation_B.t * Simulation_B.t
        + 1.0;
      Simulation_B.scale = Simulation_B.absxk;
    } else {
      Simulation_B.t = Simulation_B.absxk / Simulation_B.scale;
      Simulation_B.b_c_i += Simulation_B.t * Simulation_B.t;
    }
  }

  output->stepsize = Simulation_B.scale * sqrt(Simulation_B.b_c_i);
  output->lssteplength = Simulation_B.TrialState.steplength;
  output->firstorderopt = Simulation_B.MeritFunction.firstOrderOpt;
}

/* Function for MATLAB Function: '<S36>/MATLAB Function' */
static void Simulation_nonzeros(const real_T s[128], real_T v_data[], int32_T
  *v_size)
{
  int32_T b_k;
  int32_T i;
  i = 0;
  for (b_k = 0; b_k < 128; b_k++) {
    if (s[b_k] != 0.0) {
      i++;
    }
  }

  *v_size = i;
  i = -1;
  for (b_k = 0; b_k < 128; b_k++) {
    real_T s_0;
    s_0 = s[b_k];
    if (s_0 != 0.0) {
      i++;
      v_data[i] = s_0;
    }
  }
}

static real_T Simulation_norm(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static void Simulation_closestPointOnLine(const real_T pt1[2], const real_T pt2
  [2], const real_T refPt[2], real_T closestPoint[2], real_T *distance)
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(pt1[b_k] == pt2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (p) {
    closestPoint[0] = pt1[0];
    Simulation_B.refPt[0] = refPt[0] - pt1[0];
    closestPoint[1] = pt1[1];
    Simulation_B.refPt[1] = refPt[1] - pt1[1];
    *distance = Simulation_norm(Simulation_B.refPt);
  } else {
    real_T alpha;
    real_T v12;
    real_T v12_0;
    alpha = pt2[0] - pt1[0];
    v12 = (pt2[0] - refPt[0]) * alpha;
    v12_0 = alpha * alpha;
    alpha = pt2[1] - pt1[1];
    alpha = ((pt2[1] - refPt[1]) * alpha + v12) / (alpha * alpha + v12_0);
    p = (alpha > 1.0);
    p_0 = (alpha < 0.0);
    if (p) {
      v12 = pt1[0];
    } else if (p_0) {
      v12 = pt2[0];
    } else {
      v12 = (1.0 - alpha) * pt2[0] + alpha * pt1[0];
    }

    Simulation_B.refPt[0] = refPt[0] - v12;
    closestPoint[0] = v12;
    if (p) {
      v12 = pt1[1];
    } else if (p_0) {
      v12 = pt2[1];
    } else {
      v12 = (1.0 - alpha) * pt2[1] + alpha * pt1[1];
    }

    Simulation_B.refPt[1] = refPt[1] - v12;
    closestPoint[1] = v12;
    *distance = Simulation_norm(Simulation_B.refPt);
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T u0_0;
    int32_T u1_0;
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Simulation_step(void)
{
  boolean_T p;
  boolean_T searchFlag;
  static const char_T tmp[25] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'S', 't', 'e', 'e', 'r', 'i', 'n', 'g', 'A', 'n', 'g', 'l',
    'e' };

  static const char_T tmp_0[25] = { 'V', 'e', 'h', 'i', 'c', 'l', 'e', 'S', 'p',
    'e', 'e', 'd', 'H', 'e', 'a', 'd', 'i', 'n', 'g', 'R', 'a', 't', 'e', '-',
    '-' };

  static const int8_T e_a[32] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T c[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 };

  static const real_T d[8] = { -30.0, -30.0, -30.0, -30.0, -0.25, -0.25, -0.25,
    -0.25 };

  static const real_T f[8] = { 45.0, 45.0, 45.0, 45.0, 0.25, 0.25, 0.25, 0.25 };

  static const real_T g[8] = { -5.0, -5.0, -5.0, -5.0, -0.08, -0.08, -0.08,
    -0.08 };

  static const real_T h[8] = { 5.0, 5.0, 5.0, 5.0, 0.08, 0.08, 0.08, 0.08 };

  boolean_T exitg1;
  if (rtmIsMajorTimeStep(Simulation_M)) {
    /* set solver stop time */
    if (!(Simulation_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Simulation_M->solverInfo,
                            ((Simulation_M->Timing.clockTickH0 + 1) *
        Simulation_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Simulation_M->solverInfo,
                            ((Simulation_M->Timing.clockTick0 + 1) *
        Simulation_M->Timing.stepSize0 + Simulation_M->Timing.clockTickH0 *
        Simulation_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Simulation_M)) {
    Simulation_M->Timing.t[0] = rtsiGetT(&Simulation_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator' */
  Simulation_B.v = Simulation_X.Integrator_CSTATE;

  /* Integrator: '<S10>/Integrator' */
  Simulation_B.Integrator[0] = Simulation_X.Integrator_CSTATE_m[0];
  Simulation_B.Integrator[1] = Simulation_X.Integrator_CSTATE_m[1];
  Simulation_B.Integrator[2] = Simulation_X.Integrator_CSTATE_m[2];
  if (rtmIsMajorTimeStep(Simulation_M)) {
    /* SignalConversion generated from: '<Root>/To Workspace' */
    Simulation_B.TmpSignalConversionAtToWork[0] = Simulation_B.Integrator[0];
    Simulation_B.TmpSignalConversionAtToWork[1] = Simulation_B.Integrator[1];
    Simulation_B.TmpSignalConversionAtToWork[2] = Simulation_B.Integrator[2];
    Simulation_B.TmpSignalConversionAtToWork[3] = Simulation_B.v;

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S7>/SourceBlock' incorporates:
     *  Inport: '<S87>/In1'
     */
    searchFlag = Sub_Simulation_292.getLatestMessage
      (&Simulation_B.b_varargout_2_c);

    /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S87>/Enable'
     */
    if (searchFlag) {
      Simulation_B.In1_d = Simulation_B.b_varargout_2_c;
    }

    /* End of MATLABSystem: '<S7>/SourceBlock' */
    /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
    /* MATLABSystem: '<S8>/SourceBlock' incorporates:
     *  Inport: '<S88>/In1'
     */
    searchFlag = Sub_Simulation_110.getLatestMessage
      (&Simulation_B.b_varargout_2_b);

    /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S88>/Enable'
     */
    if (searchFlag) {
      Simulation_B.In1_e = Simulation_B.b_varargout_2_b;
    }

    /* End of MATLABSystem: '<S8>/SourceBlock' */
    /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

    /* Outputs for Enabled SubSystem: '<Root>/MPC Controller' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (rtmIsMajorTimeStep(Simulation_M)) {
      Simulation_DW.MPCController_MODE = (Simulation_B.In1_d.Data > 0.0);
    }

    /* End of Outputs for SubSystem: '<Root>/MPC Controller' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/MPC Controller' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (Simulation_DW.MPCController_MODE) {
    /* Product: '<S13>/Product1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Reshape: '<S13>/reshape_x'
     */
    Simulation_B.TmpSignalConversionAtToWork[0] = Simulation_P.Constant1_Value[0];
    Simulation_B.TmpSignalConversionAtToWork[1] = Simulation_P.Constant1_Value[1];
    Simulation_B.TmpSignalConversionAtToWork[2] = Simulation_P.Constant1_Value[2];
    Simulation_B.TmpSignalConversionAtToWork[3] = Simulation_B.v;
    for (Simulation_B.i_d = 0; Simulation_B.i_d < 4; Simulation_B.i_d++) {
      for (Simulation_B.rtb_Selector1_tmp = 0; Simulation_B.rtb_Selector1_tmp <
           5; Simulation_B.rtb_Selector1_tmp++) {
        /* Product: '<S13>/Product1' incorporates:
         *  Constant: '<S13>/ones'
         */
        Simulation_B.Product1[Simulation_B.rtb_Selector1_tmp + 5 *
          Simulation_B.i_d] =
          Simulation_P.ones_Value[Simulation_B.rtb_Selector1_tmp] *
          Simulation_B.TmpSignalConversionAtToWork[Simulation_B.i_d];
      }
    }

    if (rtmIsMajorTimeStep(Simulation_M)) {
      /* Delay: '<S13>/x_Delay' incorporates:
       *  Product: '<S13>/Product1'
       */
      if (Simulation_DW.icLoad) {
        memcpy(&Simulation_DW.x_Delay_DSTATE[0], &Simulation_B.Product1[0], 20U *
               sizeof(real_T));
      }

      /* End of Delay: '<S13>/x_Delay' */

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.LeftParameters[0] = Simulation_B.In1_e.LeftParameters[0];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.RightParameters[0] = Simulation_B.In1_e.RightParameters[0];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.LeftParameters[1] = Simulation_B.In1_e.LeftParameters[1];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.RightParameters[1] = Simulation_B.In1_e.RightParameters[1];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.LeftParameters[2] = Simulation_B.In1_e.LeftParameters[2];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.RightParameters[2] = Simulation_B.In1_e.RightParameters[2];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.LeftParameters[3] = Simulation_B.In1_e.LeftParameters[3];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.RightParameters[3] = Simulation_B.In1_e.RightParameters[3];

      /* SignalConversion generated from: '<S4>/Bus Selector' */
      Simulation_B.TargetPoint[0] = Simulation_B.In1_e.TargetPoint[0];
      Simulation_B.TargetPoint[1] = Simulation_B.In1_e.TargetPoint[1];
    }

    /* FromWorkspace: '<S4>/From Workspace' */
    {
      real_T *pDataValues = (real_T *) Simulation_DW.FromWorkspace_PWORK.DataPtr;

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&Simulation_B.FromWorkspace[0])[elIdx] = pDataValues[0];
          pDataValues += 1;
        }
      }
    }

    /* Reshape: '<S12>/Reshape' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    Simulation_B.Reshape[0] = Simulation_P.Constant1_Value[0];
    Simulation_B.Reshape[1] = Simulation_P.Constant1_Value[1];
    Simulation_B.Reshape[2] = Simulation_P.Constant1_Value[2];
    Simulation_B.Reshape[3] = Simulation_B.v;
    if (rtmIsMajorTimeStep(Simulation_M)) {
      /* Delay: '<S13>/mv_Delay' incorporates:
       *  Constant: '<S13>/ones'
       *  Memory: '<S4>/Memory'
       *  Product: '<S13>/Product'
       */
      if (Simulation_DW.icLoad_n) {
        for (Simulation_B.i_d = 0; Simulation_B.i_d < 2; Simulation_B.i_d++) {
          for (Simulation_B.rtb_Selector1_tmp = 0;
               Simulation_B.rtb_Selector1_tmp < 5;
               Simulation_B.rtb_Selector1_tmp++) {
            Simulation_DW.mv_Delay_DSTATE[Simulation_B.rtb_Selector1_tmp + 5 *
              Simulation_B.i_d] =
              Simulation_P.ones_Value[Simulation_B.rtb_Selector1_tmp] *
              Simulation_DW.Memory_PreviousInput_a[Simulation_B.i_d];
          }
        }
      }

      /* Selector: '<S13>/Selector1' incorporates:
       *  Constant: '<S13>/Constant1'
       *  Delay: '<S13>/mv_Delay'
       */
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 2; Simulation_B.i_d++) {
        Simulation_B.Selector1[3 * Simulation_B.i_d] =
          Simulation_DW.mv_Delay_DSTATE[(5 * Simulation_B.i_d +
          static_cast<int32_T>(Simulation_P.Constant1_Value_p[0])) - 1];
        Simulation_B.Selector1[3 * Simulation_B.i_d + 1] =
          Simulation_DW.mv_Delay_DSTATE[(5 * Simulation_B.i_d +
          static_cast<int32_T>(Simulation_P.Constant1_Value_p[1])) - 1];
        Simulation_B.Selector1[3 * Simulation_B.i_d + 2] =
          Simulation_DW.mv_Delay_DSTATE[(5 * Simulation_B.i_d +
          static_cast<int32_T>(Simulation_P.Constant1_Value_p[2])) - 1];
      }

      /* End of Selector: '<S13>/Selector1' */

      /* Selector: '<S13>/Selector' incorporates:
       *  Constant: '<S13>/Constant'
       *  Delay: '<S13>/x_Delay'
       */
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 4; Simulation_B.i_d++) {
        Simulation_B.Selector[3 * Simulation_B.i_d] =
          Simulation_DW.x_Delay_DSTATE[(5 * Simulation_B.i_d +
          static_cast<int32_T>(Simulation_P.Constant_Value_di[0])) - 1];
        Simulation_B.Selector[3 * Simulation_B.i_d + 1] =
          Simulation_DW.x_Delay_DSTATE[(5 * Simulation_B.i_d +
          static_cast<int32_T>(Simulation_P.Constant_Value_di[1])) - 1];
        Simulation_B.Selector[3 * Simulation_B.i_d + 2] =
          Simulation_DW.x_Delay_DSTATE[(5 * Simulation_B.i_d +
          static_cast<int32_T>(Simulation_P.Constant_Value_di[2])) - 1];
      }

      /* End of Selector: '<S13>/Selector' */

      /* Delay: '<S13>/slack_delay' incorporates:
       *  Constant: '<S11>/e.init_zero'
       */
      if (Simulation_DW.icLoad_b) {
        Simulation_DW.slack_delay_DSTATE = Simulation_P.einit_zero_Value;
      }

      /* MATLAB Function: '<S12>/NLMPC' incorporates:
       *  BusCreator: '<S4>/Bus Creator'
       *  Delay: '<S13>/slack_delay'
       *  FromWorkspace: '<S4>/From Workspace'
       *  Memory: '<S4>/Memory'
       *  Reshape: '<S12>/Reshape'
       *  Selector: '<S13>/Selector'
       *  Selector: '<S13>/Selector1'
       */
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 3; Simulation_B.i_d++) {
        Simulation_B.rtb_Selector1_tmp = Simulation_B.i_d << 2;
        Simulation_B.expl_temp.ref[Simulation_B.rtb_Selector1_tmp] =
          Simulation_B.FromWorkspace[Simulation_B.i_d];
        Simulation_B.expl_temp.ref[Simulation_B.rtb_Selector1_tmp + 1] =
          Simulation_B.FromWorkspace[Simulation_B.i_d];
        Simulation_B.expl_temp.ref[Simulation_B.rtb_Selector1_tmp + 2] =
          Simulation_B.FromWorkspace[Simulation_B.i_d];
        Simulation_B.expl_temp.ref[Simulation_B.rtb_Selector1_tmp + 3] =
          Simulation_B.FromWorkspace[Simulation_B.i_d];
        Simulation_B.rtb_Selector_l[Simulation_B.rtb_Selector1_tmp] =
          Simulation_B.Selector[Simulation_B.i_d];
        Simulation_B.rtb_Selector_l[Simulation_B.rtb_Selector1_tmp + 1] =
          Simulation_B.Selector[Simulation_B.i_d + 3];
        Simulation_B.rtb_Selector_l[Simulation_B.rtb_Selector1_tmp + 2] =
          Simulation_B.Selector[Simulation_B.i_d + 6];
        Simulation_B.rtb_Selector_l[Simulation_B.rtb_Selector1_tmp + 3] =
          Simulation_B.Selector[Simulation_B.i_d + 9];
      }

      Simulation_B.rtb_Selector_l[12] = Simulation_B.Selector[2];
      Simulation_B.rtb_Selector_l[13] = Simulation_B.Selector[5];
      Simulation_B.rtb_Selector_l[14] = Simulation_B.Selector[8];
      Simulation_B.rtb_Selector_l[15] = Simulation_B.Selector[11];
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 3; Simulation_B.i_d++) {
        Simulation_B.rtb_Selector1_tmp = Simulation_B.i_d << 1;
        Simulation_B.rtb_Selector1_n[Simulation_B.rtb_Selector1_tmp] =
          Simulation_B.Selector1[Simulation_B.i_d];
        Simulation_B.rtb_Selector1_n[Simulation_B.rtb_Selector1_tmp + 1] =
          Simulation_B.Selector1[Simulation_B.i_d + 3];
      }

      Simulation_B.rtb_Selector1_n[6] = Simulation_B.Selector1[2];
      Simulation_B.rtb_Selector1_n[7] = Simulation_B.Selector1[5];
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 4; Simulation_B.i_d++) {
        Simulation_B.TmpSignalConversionAtToWork[Simulation_B.i_d] = 0.0;
        for (Simulation_B.rtb_Selector1_tmp = 0; Simulation_B.rtb_Selector1_tmp <
             8; Simulation_B.rtb_Selector1_tmp++) {
          Simulation_B.TmpSignalConversionAtToWork[Simulation_B.i_d] +=
            static_cast<real_T>(e_a[(Simulation_B.rtb_Selector1_tmp << 2) +
                                Simulation_B.i_d]) *
            Simulation_B.rtb_Selector1_n[Simulation_B.rtb_Selector1_tmp];
        }
      }

      memcpy(&Simulation_B.z0[0], &Simulation_B.rtb_Selector_l[0], sizeof(real_T)
             << 4U);
      Simulation_B.z0[16] = Simulation_B.TmpSignalConversionAtToWork[0];
      Simulation_B.z0[17] = Simulation_B.TmpSignalConversionAtToWork[1];
      Simulation_B.z0[18] = Simulation_B.TmpSignalConversionAtToWork[2];
      Simulation_B.z0[19] = Simulation_B.TmpSignalConversionAtToWork[3];
      Simulation_B.z0[20] = Simulation_DW.slack_delay_DSTATE;
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 12; Simulation_B.i_d++) {
        Simulation_B.expl_temp.OutputWeights[Simulation_B.i_d] =
          c[Simulation_B.i_d];
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 16; Simulation_B.i_d++) {
        Simulation_B.zUB[Simulation_B.i_d] = (rtInf);
      }

      Simulation_B.zUB[16] = (rtInf);
      Simulation_B.zUB[17] = (rtInf);
      Simulation_B.zUB[18] = (rtInf);
      Simulation_B.zUB[19] = (rtInf);
      Simulation_B.zUB[20] = (rtInf);
      Simulation_znlmpc_getXUe(Simulation_B.z0, Simulation_B.Reshape,
        Simulation_B.xseq, Simulation_B.mvseq, &Simulation_B.dist);
      Simulation_B.dist = Simulation_B.xseq[4] - Simulation_B.TargetPoint[0];
      Simulation_B.minDistance = Simulation_B.xseq[9] -
        Simulation_B.TargetPoint[1];
      Simulation_B.dist = Simulation_B.dist * Simulation_B.dist +
        Simulation_B.minDistance * Simulation_B.minDistance;
      if (Simulation_B.dist <= Simulation_B.dist) {
        Simulation_B.zUB[20] = 0.0;
      }

      Simulation_znlmpc_getUBounds(Simulation_DW.Memory_PreviousInput_a, d, f, g,
        h, Simulation_B.A_data_m, Simulation_B.A_size, Simulation_B.B_data_d,
        &Simulation_B.B_size);
      Simulation_B.expl_temp.Parameters.f1[0] = Simulation_B.LeftParameters[0];
      Simulation_B.expl_temp.Parameters.f2[0] = Simulation_B.RightParameters[0];
      Simulation_B.expl_temp.Parameters.f1[1] = Simulation_B.LeftParameters[1];
      Simulation_B.expl_temp.Parameters.f2[1] = Simulation_B.RightParameters[1];
      Simulation_B.expl_temp.Parameters.f1[2] = Simulation_B.LeftParameters[2];
      Simulation_B.expl_temp.Parameters.f2[2] = Simulation_B.RightParameters[2];
      Simulation_B.expl_temp.Parameters.f1[3] = Simulation_B.LeftParameters[3];
      Simulation_B.expl_temp.Parameters.f2[3] = Simulation_B.RightParameters[3];
      Simulation_B.expl_temp.Parameters.f3[0] = Simulation_B.TargetPoint[0];
      Simulation_B.expl_temp.Parameters.f3[1] = Simulation_B.TargetPoint[1];
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 8; Simulation_B.i_d++) {
        Simulation_B.expl_temp.MVScaledTarget[Simulation_B.i_d] = 0.0;
        Simulation_B.expl_temp.MVRateMax[Simulation_B.i_d] = h[Simulation_B.i_d];
        Simulation_B.expl_temp.MVRateMin[Simulation_B.i_d] = g[Simulation_B.i_d];
        Simulation_B.expl_temp.MVMax[Simulation_B.i_d] = f[Simulation_B.i_d];
        Simulation_B.expl_temp.MVMin[Simulation_B.i_d] = d[Simulation_B.i_d];
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 16; Simulation_B.i_d++) {
        Simulation_B.expl_temp.StateMax[Simulation_B.i_d] = (rtInf);
        Simulation_B.expl_temp.StateMin[Simulation_B.i_d] = (rtMinusInf);
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 12; Simulation_B.i_d++) {
        Simulation_B.expl_temp.OutputMax[Simulation_B.i_d] = (rtInf);
        Simulation_B.expl_temp.OutputMin[Simulation_B.i_d] = (rtMinusInf);
      }

      Simulation_B.expl_temp.ECRWeight = 100000.0;
      Simulation_B.expl_temp.lastMV[0] = Simulation_DW.Memory_PreviousInput_a[0];
      Simulation_B.expl_temp.lastMV[1] = Simulation_DW.Memory_PreviousInput_a[1];
      Simulation_B.expl_temp.x[0] = Simulation_B.Reshape[0];
      Simulation_B.expl_temp.x[1] = Simulation_B.Reshape[1];
      Simulation_B.expl_temp.x[2] = Simulation_B.Reshape[2];
      Simulation_B.expl_temp.x[3] = Simulation_B.Reshape[3];
      Simulation_B.expl_temp_g.MVIndex[0] = 1.0;
      Simulation_B.expl_temp_g.MVIndex[1] = 2.0;
      Simulation_B.expl_temp_g.NumOfInputs = 2.0;
      Simulation_B.expl_temp_g.NumOfOutputs = 3.0;
      Simulation_B.expl_temp_g.NumOfStates = 4.0;
      Simulation_B.expl_temp_g.PredictionHorizon = 4.0;
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 8; Simulation_B.i_d++) {
        Simulation_B.expl_temp.MVRateWeights[Simulation_B.i_d] = 0.1;
        Simulation_B.expl_temp.MVWeights[Simulation_B.i_d] = 0.0;
        Simulation_B.expl_temp_g.MVTarget[Simulation_B.i_d] = 0.0;
      }

      memcpy(&Simulation_B.expl_temp_g.References[0],
             &Simulation_B.expl_temp.ref[0], 12U * sizeof(real_T));
      Simulation_B.expl_temp_g.LastMV[0] = Simulation_DW.Memory_PreviousInput_a
        [0];
      Simulation_B.expl_temp_g.LastMV[1] = Simulation_DW.Memory_PreviousInput_a
        [1];
      Simulation_B.expl_temp_g.Ts = 0.1;
      Simulation_B.expl_temp_g.CurrentStates[0] = Simulation_B.Reshape[0];
      Simulation_B.expl_temp_p.Parameters.f1[0] = Simulation_B.LeftParameters[0];
      Simulation_B.expl_temp_p.Parameters.f2[0] = Simulation_B.RightParameters[0];
      Simulation_B.expl_temp_g.CurrentStates[1] = Simulation_B.Reshape[1];
      Simulation_B.expl_temp_p.Parameters.f1[1] = Simulation_B.LeftParameters[1];
      Simulation_B.expl_temp_p.Parameters.f2[1] = Simulation_B.RightParameters[1];
      Simulation_B.expl_temp_g.CurrentStates[2] = Simulation_B.Reshape[2];
      Simulation_B.expl_temp_p.Parameters.f1[2] = Simulation_B.LeftParameters[2];
      Simulation_B.expl_temp_p.Parameters.f2[2] = Simulation_B.RightParameters[2];
      Simulation_B.expl_temp_g.CurrentStates[3] = Simulation_B.Reshape[3];
      Simulation_B.expl_temp_p.Parameters.f1[3] = Simulation_B.LeftParameters[3];
      Simulation_B.expl_temp_p.Parameters.f2[3] = Simulation_B.RightParameters[3];
      Simulation_B.expl_temp_p.Parameters.f3[0] = Simulation_B.TargetPoint[0];
      Simulation_B.expl_temp_p.Parameters.f3[1] = Simulation_B.TargetPoint[1];
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 8; Simulation_B.i_d++) {
        Simulation_B.expl_temp_p.MVScaledTarget[Simulation_B.i_d] = 0.0;
        Simulation_B.expl_temp_p.MVRateMax[Simulation_B.i_d] =
          h[Simulation_B.i_d];
        Simulation_B.expl_temp_p.MVRateMin[Simulation_B.i_d] =
          g[Simulation_B.i_d];
        Simulation_B.expl_temp_p.MVMax[Simulation_B.i_d] = f[Simulation_B.i_d];
        Simulation_B.expl_temp_p.MVMin[Simulation_B.i_d] = d[Simulation_B.i_d];
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 16; Simulation_B.i_d++) {
        Simulation_B.expl_temp_p.StateMax[Simulation_B.i_d] = (rtInf);
        Simulation_B.expl_temp_p.StateMin[Simulation_B.i_d] = (rtMinusInf);
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 12; Simulation_B.i_d++) {
        Simulation_B.expl_temp_p.OutputMax[Simulation_B.i_d] = (rtInf);
        Simulation_B.expl_temp_p.OutputMin[Simulation_B.i_d] = (rtMinusInf);
      }

      Simulation_B.expl_temp_p.ECRWeight = 100000.0;
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 8; Simulation_B.i_d++) {
        Simulation_B.expl_temp_p.MVRateWeights[Simulation_B.i_d] = 0.1;
        Simulation_B.expl_temp_p.MVWeights[Simulation_B.i_d] = 0.0;
      }

      memcpy(&Simulation_B.expl_temp_p.OutputWeights[0],
             &Simulation_B.expl_temp.OutputWeights[0], 12U * sizeof(real_T));
      memcpy(&Simulation_B.expl_temp_p.ref[0], &Simulation_B.expl_temp.ref[0],
             12U * sizeof(real_T));
      Simulation_B.expl_temp_p.lastMV[0] = Simulation_DW.Memory_PreviousInput_a
        [0];
      Simulation_B.expl_temp_p.lastMV[1] = Simulation_DW.Memory_PreviousInput_a
        [1];
      Simulation_B.expl_temp_p.x[0] = Simulation_B.Reshape[0];
      Simulation_B.expl_temp_p.x[1] = Simulation_B.Reshape[1];
      Simulation_B.expl_temp_p.x[2] = Simulation_B.Reshape[2];
      Simulation_B.expl_temp_p.x[3] = Simulation_B.Reshape[3];
      Simulation_B.expl_temp_l.MVIndex[0] = 1.0;
      Simulation_B.expl_temp_l.MVIndex[1] = 2.0;
      Simulation_B.expl_temp_l.NumOfInputs = 2.0;
      Simulation_B.expl_temp_l.NumOfOutputs = 3.0;
      Simulation_B.expl_temp_l.NumOfStates = 4.0;
      Simulation_B.expl_temp_l.PredictionHorizon = 4.0;
      memset(&Simulation_B.expl_temp_l.MVTarget[0], 0, sizeof(real_T) << 3U);
      memcpy(&Simulation_B.expl_temp_l.References[0],
             &Simulation_B.expl_temp.ref[0], 12U * sizeof(real_T));
      Simulation_B.expl_temp_l.LastMV[0] = Simulation_DW.Memory_PreviousInput_a
        [0];
      Simulation_B.expl_temp_l.LastMV[1] = Simulation_DW.Memory_PreviousInput_a
        [1];
      Simulation_B.expl_temp_l.Ts = 0.1;
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 4; Simulation_B.i_d++) {
        Simulation_B.expl_temp_l.CurrentStates[Simulation_B.i_d] =
          Simulation_B.Reshape[Simulation_B.i_d];
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 16; Simulation_B.i_d++) {
        Simulation_B.dv[Simulation_B.i_d] = (rtMinusInf);
      }

      Simulation_B.dv[16] = (rtMinusInf);
      Simulation_B.dv[17] = (rtMinusInf);
      Simulation_B.dv[18] = (rtMinusInf);
      Simulation_B.dv[19] = (rtMinusInf);
      Simulation_B.dv[20] = 0.0;
      Simulation_fmincon(&Simulation_B.expl_temp, &Simulation_B.expl_temp_g,
                         Simulation_B.z0, Simulation_B.A_data_m,
                         Simulation_B.B_data_d, &Simulation_B.B_size,
                         Simulation_B.dv, Simulation_B.zUB,
                         &Simulation_B.expl_temp_p, &Simulation_B.expl_temp_l,
                         Simulation_B.z, &Simulation_B.dist,
                         &Simulation_B.nlpstatus, &Simulation_B.Out);
      if ((Simulation_B.nlpstatus == 0.0) && (Simulation_B.Out.constrviolation >
           0.01)) {
        Simulation_B.nlpstatus = -2.0;
      }

      Simulation_znlmpc_getXUe(Simulation_B.z, Simulation_B.Reshape,
        Simulation_B.xseq, Simulation_B.mvseq, &Simulation_B.e);
      if (Simulation_B.nlpstatus > 0.0) {
        Simulation_B.mv[0] = Simulation_B.mvseq[0];
        Simulation_B.mv[1] = Simulation_B.mvseq[5];
      } else {
        Simulation_B.mv[0] = Simulation_DW.Memory_PreviousInput_a[0];
        Simulation_B.mv[1] = Simulation_DW.Memory_PreviousInput_a[1];
      }

      for (Simulation_B.i_d = 0; Simulation_B.i_d < 5; Simulation_B.i_d++) {
        Simulation_B.yseq[Simulation_B.i_d] = Simulation_B.xseq[Simulation_B.i_d];
        Simulation_B.yseq[Simulation_B.i_d + 5] =
          Simulation_B.xseq[Simulation_B.i_d + 5];
        Simulation_B.yseq[Simulation_B.i_d + 10] =
          Simulation_B.xseq[Simulation_B.i_d + 10];
      }

      /* End of MATLAB Function: '<S12>/NLMPC' */
    }
  }

  /* End of Outputs for SubSystem: '<Root>/MPC Controller' */
  if (rtmIsMajorTimeStep(Simulation_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
    /* MATLABSystem: '<S9>/SourceBlock' incorporates:
     *  Inport: '<S89>/In1'
     */
    searchFlag = Sub_Simulation_266.getLatestMessage(&Simulation_B.b_varargout_2);

    /* Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S89>/Enable'
     */
    if (searchFlag) {
      Simulation_B.In1 = Simulation_B.b_varargout_2;
    }

    /* End of MATLABSystem: '<S9>/SourceBlock' */
    /* End of Outputs for SubSystem: '<S9>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

    /* Gain: '<Root>/Gain' */
    Simulation_B.Gain = Simulation_P.Gain_Gain * Simulation_B.In1_d.Data;

    /* Outputs for Enabled SubSystem: '<Root>/Pure Pursuit Controller' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (rtmIsMajorTimeStep(Simulation_M)) {
      Simulation_DW.PurePursuitController_MODE = (Simulation_B.Gain > 0.0);
    }

    /* End of Outputs for SubSystem: '<Root>/Pure Pursuit Controller' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Pure Pursuit Controller' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (Simulation_DW.PurePursuitController_MODE) {
    if (rtmIsMajorTimeStep(Simulation_M)) {
      for (Simulation_B.i_d = 0; Simulation_B.i_d < 128; Simulation_B.i_d++) {
        /* SignalConversion generated from: '<S36>/Bus Selector' */
        Simulation_B.dist = Simulation_B.In1.X[Simulation_B.i_d];

        /* SignalConversion generated from: '<S36>/Vector Concatenate' */
        Simulation_B.VectorConcatenate[Simulation_B.i_d] = Simulation_B.dist;

        /* SignalConversion generated from: '<S36>/Bus Selector' */
        Simulation_B.X[Simulation_B.i_d] = Simulation_B.dist;
      }

      /* SignalConversion generated from: '<S36>/Vector Concatenate' */
      memcpy(&Simulation_B.VectorConcatenate[128], &Simulation_B.In1.Y[0],
             sizeof(real_T) << 7U);

      /* MATLAB Function: '<S36>/MATLAB Function' incorporates:
       *  Concatenate: '<S36>/Vector Concatenate'
       */
      Simulation_nonzeros(&Simulation_B.VectorConcatenate[0], Simulation_B.X,
                          &Simulation_B.B_size);
      Simulation_nonzeros(&Simulation_B.VectorConcatenate[128],
                          Simulation_B.b_data, &Simulation_B.b_size);
      if ((Simulation_B.B_size > 0) && (Simulation_B.B_size ==
           Simulation_B.b_size)) {
        Simulation_B.dist = Simulation_B.X[Simulation_B.B_size - 1];
        Simulation_B.dist += (Simulation_B.dist -
                              Simulation_B.X[Simulation_B.B_size - 2]) * 200.0;
        Simulation_B.minDistance = Simulation_B.b_data[Simulation_B.b_size - 1];
        Simulation_B.minDistance += (Simulation_B.minDistance -
          Simulation_B.b_data[Simulation_B.b_size - 2]) * 200.0;
        for (Simulation_B.i_d = 0; Simulation_B.i_d < 40; Simulation_B.i_d++) {
          Simulation_B.y[Simulation_B.i_d] = Simulation_B.dist;
          Simulation_B.y[Simulation_B.i_d + 40] = Simulation_B.minDistance;
        }

        Simulation_B.i_d = Simulation_B.B_size;
        if (0 <= Simulation_B.i_d - 1) {
          memcpy(&Simulation_B.y[0], &Simulation_B.X[0], Simulation_B.i_d *
                 sizeof(real_T));
        }

        Simulation_B.i_d = Simulation_B.b_size;
        if (0 <= Simulation_B.i_d - 1) {
          memcpy(&Simulation_B.y[40], &Simulation_B.b_data[0], Simulation_B.i_d *
                 sizeof(real_T));
        }
      } else {
        memset(&Simulation_B.y[0], 0, 80U * sizeof(real_T));
      }

      /* End of MATLAB Function: '<S36>/MATLAB Function' */
    }

    /* MATLABSystem: '<S6>/Pure Pursuit1' */
    if (Simulation_DW.obj.DesiredLinearVelocity !=
        Simulation_P.PurePursuit1_DesiredLinearVeloc) {
      Simulation_DW.obj.DesiredLinearVelocity =
        Simulation_P.PurePursuit1_DesiredLinearVeloc;
    }

    if (Simulation_DW.obj.MaxAngularVelocity !=
        Simulation_P.PurePursuit1_MaxAngularVelocity) {
      Simulation_DW.obj.MaxAngularVelocity =
        Simulation_P.PurePursuit1_MaxAngularVelocity;
    }

    if (Simulation_DW.obj.LookaheadDistance != Simulation_P.ld) {
      Simulation_DW.obj.LookaheadDistance = Simulation_P.ld;
    }

    searchFlag = false;
    p = true;
    Simulation_B.i_d = 0;
    exitg1 = false;
    while ((!exitg1) && (Simulation_B.i_d < 80)) {
      if ((Simulation_DW.obj.WaypointsInternal[Simulation_B.i_d] ==
           Simulation_B.y[Simulation_B.i_d]) || (rtIsNaN
           (Simulation_DW.obj.WaypointsInternal[Simulation_B.i_d]) && rtIsNaN
           (Simulation_B.y[Simulation_B.i_d]))) {
        Simulation_B.i_d++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (p) {
      searchFlag = true;
    }

    if (!searchFlag) {
      memcpy(&Simulation_DW.obj.WaypointsInternal[0], &Simulation_B.y[0], 80U *
             sizeof(real_T));
      Simulation_DW.obj.ProjectionLineIndex = 0.0;
    }

    for (Simulation_B.i_d = 0; Simulation_B.i_d < 80; Simulation_B.i_d++) {
      Simulation_B.b[Simulation_B.i_d] = !rtIsNaN
        (Simulation_B.y[Simulation_B.i_d]);
    }

    Simulation_B.rtb_Selector1_tmp = 0;
    for (Simulation_B.i_d = 0; Simulation_B.i_d < 40; Simulation_B.i_d++) {
      if (Simulation_B.b[Simulation_B.i_d] && Simulation_B.b[Simulation_B.i_d +
          40]) {
        Simulation_B.rtb_Selector1_tmp++;
      }
    }

    Simulation_B.f_size_idx_0 = Simulation_B.rtb_Selector1_tmp;
    Simulation_B.rtb_Selector1_tmp = 0;
    for (Simulation_B.i_d = 0; Simulation_B.i_d < 40; Simulation_B.i_d++) {
      if (Simulation_B.b[Simulation_B.i_d] && Simulation_B.b[Simulation_B.i_d +
          40]) {
        Simulation_B.f_data[Simulation_B.rtb_Selector1_tmp] = static_cast<int8_T>
          (Simulation_B.i_d + 1);
        Simulation_B.rtb_Selector1_tmp++;
      }
    }

    for (Simulation_B.i_d = 0; Simulation_B.i_d < 2; Simulation_B.i_d++) {
      for (Simulation_B.rtb_Selector1_tmp = 0; Simulation_B.rtb_Selector1_tmp <
           Simulation_B.f_size_idx_0; Simulation_B.rtb_Selector1_tmp++) {
        Simulation_B.waypoints_data[Simulation_B.rtb_Selector1_tmp +
          Simulation_B.f_size_idx_0 * Simulation_B.i_d] = Simulation_B.y[(40 *
          Simulation_B.i_d + Simulation_B.f_data[Simulation_B.rtb_Selector1_tmp])
          - 1];
      }
    }

    if (Simulation_B.f_size_idx_0 == 0) {
      Simulation_B.minDistance = 0.0;
      Simulation_B.dist = 0.0;
    } else {
      searchFlag = false;
      if (Simulation_DW.obj.ProjectionLineIndex == 0.0) {
        searchFlag = true;
        Simulation_DW.obj.ProjectionPoint[0] = Simulation_B.waypoints_data[0];
        Simulation_DW.obj.ProjectionPoint[1] =
          Simulation_B.waypoints_data[Simulation_B.f_size_idx_0];
        Simulation_DW.obj.ProjectionLineIndex = 1.0;
      }

      if (Simulation_B.f_size_idx_0 == 1) {
        Simulation_B.dist = Simulation_B.waypoints_data[0];
        Simulation_DW.obj.ProjectionPoint[0] = Simulation_B.dist;
        Simulation_B.minDistance =
          Simulation_B.waypoints_data[Simulation_B.f_size_idx_0];
        Simulation_DW.obj.ProjectionPoint[1] = Simulation_B.minDistance;
        Simulation_DW.obj.LookaheadPoint[0] = Simulation_B.dist;
        Simulation_DW.obj.LookaheadPoint[1] = Simulation_B.minDistance;
      } else {
        Simulation_B.waypoints[0] = Simulation_B.waypoints_data
          [static_cast<int32_T>(Simulation_DW.obj.ProjectionLineIndex + 1.0) - 1];
        Simulation_B.waypoints[1] = Simulation_B.waypoints_data
          [(static_cast<int32_T>(Simulation_DW.obj.ProjectionLineIndex + 1.0) +
            Simulation_B.f_size_idx_0) - 1];
        for (Simulation_B.i_a = 0; Simulation_B.i_a < 2; Simulation_B.i_a++) {
          Simulation_B.lookaheadStartPt[Simulation_B.i_a] =
            Simulation_DW.obj.ProjectionPoint[Simulation_B.i_a];
        }

        Simulation_closestPointOnLine(Simulation_B.lookaheadStartPt,
          Simulation_B.waypoints, &Simulation_B.Integrator[0],
          Simulation_DW.obj.ProjectionPoint, &Simulation_B.minDistance);
        Simulation_B.lookaheadStartPt[0] = Simulation_DW.obj.ProjectionPoint[0]
          - Simulation_B.waypoints_data[static_cast<int32_T>
          (Simulation_DW.obj.ProjectionLineIndex + 1.0) - 1];
        Simulation_B.lookaheadStartPt[1] = Simulation_DW.obj.ProjectionPoint[1]
          - Simulation_B.waypoints_data[(static_cast<int32_T>
          (Simulation_DW.obj.ProjectionLineIndex + 1.0) +
          Simulation_B.f_size_idx_0) - 1];
        Simulation_B.dist = Simulation_norm(Simulation_B.lookaheadStartPt);
        Simulation_B.lookaheadIdx = Simulation_DW.obj.ProjectionLineIndex + 1.0;
        Simulation_B.rtb_Selector1_tmp = static_cast<int32_T>((1.0 -
          (Simulation_DW.obj.ProjectionLineIndex + 1.0)) + (static_cast<real_T>
          (Simulation_B.f_size_idx_0) - 1.0)) - 1;
        Simulation_B.i_d = 0;
        exitg1 = false;
        while ((!exitg1) && (Simulation_B.i_d <= Simulation_B.rtb_Selector1_tmp))
        {
          Simulation_B.i = Simulation_B.lookaheadIdx + static_cast<real_T>
            (Simulation_B.i_d);
          if ((!searchFlag) && (Simulation_B.dist >
                                Simulation_DW.obj.LookaheadDistance)) {
            exitg1 = true;
          } else {
            Simulation_B.waypoints_tmp = Simulation_B.waypoints_data[
              static_cast<int32_T>(Simulation_B.i) - 1];
            Simulation_B.waypoints_tmp_f = Simulation_B.waypoints_data[
              static_cast<int32_T>(Simulation_B.i + 1.0) - 1];
            Simulation_B.waypoints[0] = Simulation_B.waypoints_tmp -
              Simulation_B.waypoints_tmp_f;
            Simulation_B.lookaheadEndPt[0] = Simulation_B.waypoints_tmp;
            Simulation_B.waypoints_a[0] = Simulation_B.waypoints_tmp_f;
            Simulation_B.waypoints_tmp = Simulation_B.waypoints_data[(
              static_cast<int32_T>(Simulation_B.i) + Simulation_B.f_size_idx_0)
              - 1];
            Simulation_B.waypoints_tmp_f = Simulation_B.waypoints_data[(
              static_cast<int32_T>(Simulation_B.i + 1.0) +
              Simulation_B.f_size_idx_0) - 1];
            Simulation_B.waypoints[1] = Simulation_B.waypoints_tmp -
              Simulation_B.waypoints_tmp_f;
            Simulation_B.lookaheadEndPt[1] = Simulation_B.waypoints_tmp;
            Simulation_B.waypoints_a[1] = Simulation_B.waypoints_tmp_f;
            Simulation_B.dist += Simulation_norm(Simulation_B.waypoints);
            Simulation_closestPointOnLine(Simulation_B.lookaheadEndPt,
              Simulation_B.waypoints_a, &Simulation_B.Integrator[0],
              Simulation_B.lookaheadStartPt, &Simulation_B.waypoints_tmp);
            if (Simulation_B.waypoints_tmp < Simulation_B.minDistance) {
              Simulation_B.minDistance = Simulation_B.waypoints_tmp;
              Simulation_DW.obj.ProjectionPoint[0] =
                Simulation_B.lookaheadStartPt[0];
              Simulation_DW.obj.ProjectionPoint[1] =
                Simulation_B.lookaheadStartPt[1];
              Simulation_DW.obj.ProjectionLineIndex = Simulation_B.i;
            }

            Simulation_B.i_d++;
          }
        }

        Simulation_B.minDistance = Simulation_B.waypoints_data[static_cast<
          int32_T>(Simulation_DW.obj.ProjectionLineIndex + 1.0) - 1];
        Simulation_B.lookaheadStartPt[0] = Simulation_DW.obj.ProjectionPoint[0]
          - Simulation_B.minDistance;
        Simulation_B.lookaheadIdx = Simulation_B.waypoints_data
          [(static_cast<int32_T>(Simulation_DW.obj.ProjectionLineIndex + 1.0) +
            Simulation_B.f_size_idx_0) - 1];
        Simulation_B.lookaheadStartPt[1] = Simulation_DW.obj.ProjectionPoint[1]
          - Simulation_B.lookaheadIdx;
        Simulation_B.dist = Simulation_norm(Simulation_B.lookaheadStartPt);
        Simulation_B.lookaheadStartPt[0] = Simulation_DW.obj.ProjectionPoint[0];
        Simulation_B.lookaheadEndPt[0] = Simulation_B.minDistance;
        Simulation_B.lookaheadStartPt[1] = Simulation_DW.obj.ProjectionPoint[1];
        Simulation_B.lookaheadEndPt[1] = Simulation_B.lookaheadIdx;
        Simulation_B.minDistance = Simulation_B.dist -
          Simulation_DW.obj.LookaheadDistance;
        Simulation_B.lookaheadIdx = Simulation_DW.obj.ProjectionLineIndex;
        while ((Simulation_B.minDistance < 0.0) && (Simulation_B.lookaheadIdx <
                static_cast<real_T>(Simulation_B.f_size_idx_0) - 1.0)) {
          Simulation_B.lookaheadIdx++;
          Simulation_B.i = Simulation_B.waypoints_data[static_cast<int32_T>
            (Simulation_B.lookaheadIdx) - 1];
          Simulation_B.lookaheadStartPt[0] = Simulation_B.i;
          Simulation_B.minDistance = Simulation_B.waypoints_data
            [static_cast<int32_T>(Simulation_B.lookaheadIdx + 1.0) - 1];
          Simulation_B.waypoints[0] = Simulation_B.i - Simulation_B.minDistance;
          Simulation_B.lookaheadEndPt[0] = Simulation_B.minDistance;
          Simulation_B.i = Simulation_B.waypoints_data[(static_cast<int32_T>
            (Simulation_B.lookaheadIdx) + Simulation_B.f_size_idx_0) - 1];
          Simulation_B.lookaheadStartPt[1] = Simulation_B.i;
          Simulation_B.minDistance = Simulation_B.waypoints_data
            [(static_cast<int32_T>(Simulation_B.lookaheadIdx + 1.0) +
              Simulation_B.f_size_idx_0) - 1];
          Simulation_B.waypoints[1] = Simulation_B.i - Simulation_B.minDistance;
          Simulation_B.lookaheadEndPt[1] = Simulation_B.minDistance;
          Simulation_B.dist += Simulation_norm(Simulation_B.waypoints);
          Simulation_B.minDistance = Simulation_B.dist -
            Simulation_DW.obj.LookaheadDistance;
        }

        Simulation_B.waypoints[0] = Simulation_B.lookaheadStartPt[0] -
          Simulation_B.lookaheadEndPt[0];
        Simulation_B.waypoints[1] = Simulation_B.lookaheadStartPt[1] -
          Simulation_B.lookaheadEndPt[1];
        Simulation_B.dist = Simulation_B.minDistance / Simulation_norm
          (Simulation_B.waypoints);
        if (Simulation_B.dist > 0.0) {
          Simulation_DW.obj.LookaheadPoint[0] = (1.0 - Simulation_B.dist) *
            Simulation_B.lookaheadEndPt[0] + Simulation_B.dist *
            Simulation_B.lookaheadStartPt[0];
          Simulation_DW.obj.LookaheadPoint[1] = (1.0 - Simulation_B.dist) *
            Simulation_B.lookaheadEndPt[1] + Simulation_B.dist *
            Simulation_B.lookaheadStartPt[1];
        } else {
          Simulation_DW.obj.LookaheadPoint[0] = Simulation_B.lookaheadEndPt[0];
          Simulation_DW.obj.LookaheadPoint[1] = Simulation_B.lookaheadEndPt[1];
        }
      }

      Simulation_B.dist = rt_atan2d_snf(Simulation_DW.obj.LookaheadPoint[1] -
        Simulation_B.Integrator[1], Simulation_DW.obj.LookaheadPoint[0] -
        Simulation_B.Integrator[0]) - Simulation_B.Integrator[2];
      if (fabs(Simulation_B.dist) > 3.1415926535897931) {
        if (rtIsNaN(Simulation_B.dist + 3.1415926535897931) || rtIsInf
            (Simulation_B.dist + 3.1415926535897931)) {
          Simulation_B.minDistance = (rtNaN);
        } else if (Simulation_B.dist + 3.1415926535897931 == 0.0) {
          Simulation_B.minDistance = 0.0;
        } else {
          Simulation_B.minDistance = fmod(Simulation_B.dist + 3.1415926535897931,
            6.2831853071795862);
          searchFlag = (Simulation_B.minDistance == 0.0);
          if (!searchFlag) {
            Simulation_B.lookaheadIdx = fabs((Simulation_B.dist +
              3.1415926535897931) / 6.2831853071795862);
            searchFlag = !(fabs(Simulation_B.lookaheadIdx - floor
                                (Simulation_B.lookaheadIdx + 0.5)) >
                           2.2204460492503131E-16 * Simulation_B.lookaheadIdx);
          }

          if (searchFlag) {
            Simulation_B.minDistance = 0.0;
          } else if (Simulation_B.dist + 3.1415926535897931 < 0.0) {
            Simulation_B.minDistance += 6.2831853071795862;
          }
        }

        if ((Simulation_B.minDistance == 0.0) && (Simulation_B.dist +
             3.1415926535897931 > 0.0)) {
          Simulation_B.minDistance = 6.2831853071795862;
        }

        Simulation_B.dist = Simulation_B.minDistance - 3.1415926535897931;
      }

      Simulation_B.minDistance = Simulation_DW.obj.DesiredLinearVelocity;
      Simulation_DW.obj.LastPose[0] = Simulation_B.Integrator[0];
      Simulation_DW.obj.LastPose[1] = Simulation_B.Integrator[1];
      Simulation_DW.obj.LastPose[2] = Simulation_B.Integrator[2];
      if (rtIsNaN(Simulation_B.dist)) {
        Simulation_B.dist = 0.0;
      }
    }

    /* Trigonometry: '<S37>/Atan' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  MATLABSystem: '<S6>/Pure Pursuit1'
     *  Product: '<S37>/Divide'
     *  Product: '<S37>/Product1'
     *  Trigonometry: '<S37>/Sin'
     */
    Simulation_B.SteeringAngle = atan(Simulation_P.Constant_Value_k *
      Simulation_P.L * sin(Simulation_B.dist) / Simulation_P.ld);

    /* Sum: '<S6>/Sum' incorporates:
     *  MATLABSystem: '<S6>/Pure Pursuit1'
     */
    Simulation_B.dist = Simulation_B.minDistance - Simulation_B.v;

    /* Gain: '<S72>/Filter Coefficient' incorporates:
     *  Gain: '<S63>/Derivative Gain'
     *  Integrator: '<S64>/Filter'
     *  Sum: '<S64>/SumD'
     */
    Simulation_B.FilterCoefficient = (Simulation_P.PIDController1_D *
      Simulation_B.dist - Simulation_X.Filter_CSTATE) *
      Simulation_P.PIDController1_N;

    /* Sum: '<S78>/Sum' incorporates:
     *  Gain: '<S74>/Proportional Gain'
     *  Integrator: '<S69>/Integrator'
     */
    Simulation_B.Sum = (Simulation_P.PIDController1_P * Simulation_B.dist +
                        Simulation_X.Integrator_CSTATE_i) +
      Simulation_B.FilterCoefficient;

    /* Gain: '<S66>/Integral Gain' */
    Simulation_B.IntegralGain = Simulation_P.PIDController1_I *
      Simulation_B.dist;
  }

  /* End of Outputs for SubSystem: '<Root>/Pure Pursuit Controller' */

  /* Switch: '<Root>/Switch' */
  if (Simulation_B.In1_d.Data > Simulation_P.Switch_Threshold) {
    Simulation_B.lookaheadStartPt[0] = Simulation_B.mv[0];
    Simulation_B.lookaheadStartPt[1] = Simulation_B.mv[1];
  } else {
    Simulation_B.lookaheadStartPt[0] = Simulation_B.Sum;
    Simulation_B.lookaheadStartPt[1] = Simulation_B.SteeringAngle;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<S10>/MATLAB System' */
  if (Simulation_DW.obj_p.WheelBase !=
      Simulation_P.BicycleKinematicModel_WheelBase) {
    if (Simulation_DW.obj_p.isInitialized == 1) {
      Simulation_DW.obj_p.TunablePropsChanged = true;
      Simulation_DW.obj_p.tunablePropertyChanged[0] = true;
    }

    Simulation_DW.obj_p.WheelBase = Simulation_P.BicycleKinematicModel_WheelBase;
  }

  searchFlag = false;
  p = true;
  Simulation_B.i_d = 0;
  exitg1 = false;
  while ((!exitg1) && (Simulation_B.i_d < 2)) {
    if (!(Simulation_DW.obj_p.VehicleSpeedRange[Simulation_B.i_d] ==
          Simulation_P.BicycleKinematicModel_VehicleSp[Simulation_B.i_d])) {
      p = false;
      exitg1 = true;
    } else {
      Simulation_B.i_d++;
    }
  }

  if (p) {
    searchFlag = true;
  }

  if (!searchFlag) {
    if (Simulation_DW.obj_p.isInitialized == 1) {
      Simulation_DW.obj_p.TunablePropsChanged = true;
      Simulation_DW.obj_p.tunablePropertyChanged[1] = true;
    }

    Simulation_DW.obj_p.VehicleSpeedRange[0] =
      Simulation_P.BicycleKinematicModel_VehicleSp[0];
    Simulation_DW.obj_p.VehicleSpeedRange[1] =
      Simulation_P.BicycleKinematicModel_VehicleSp[1];
  }

  if (Simulation_DW.obj_p.MaxSteeringAngle !=
      Simulation_P.BicycleKinematicModel_MaxSteeri) {
    if (Simulation_DW.obj_p.isInitialized == 1) {
      Simulation_DW.obj_p.TunablePropsChanged = true;
      Simulation_DW.obj_p.tunablePropertyChanged[2] = true;
    }

    Simulation_DW.obj_p.MaxSteeringAngle =
      Simulation_P.BicycleKinematicModel_MaxSteeri;
  }

  if (Simulation_DW.obj_p.TunablePropsChanged) {
    Simulation_DW.obj_p.TunablePropsChanged = false;
    if (Simulation_DW.obj_p.tunablePropertyChanged[1]) {
      Simulation_DW.obj_p.KinModel.VehicleSpeedRange[0] =
        Simulation_DW.obj_p.VehicleSpeedRange[0];
      Simulation_DW.obj_p.KinModel.VehicleSpeedRange[1] =
        Simulation_DW.obj_p.VehicleSpeedRange[1];
    }

    if (Simulation_DW.obj_p.tunablePropertyChanged[0]) {
      Simulation_DW.obj_p.KinModel.WheelBase = Simulation_DW.obj_p.WheelBase;
    }

    if (Simulation_DW.obj_p.tunablePropertyChanged[2]) {
      Simulation_DW.obj_p.KinModel.MaxSteeringAngle =
        Simulation_DW.obj_p.MaxSteeringAngle;
    }

    Simulation_DW.obj_p.tunablePropertyChanged[0] = false;
    Simulation_DW.obj_p.tunablePropertyChanged[1] = false;
    Simulation_DW.obj_p.tunablePropertyChanged[2] = false;
  }

  Simulation_B.lookaheadEndPt[0] = Simulation_B.v;
  Simulation_B.lookaheadEndPt[1] = Simulation_B.lookaheadStartPt[1];
  if ((Simulation_B.lookaheadEndPt[0] >=
       Simulation_DW.obj_p.KinModel.VehicleSpeedRange[0]) || rtIsNaN
      (Simulation_DW.obj_p.KinModel.VehicleSpeedRange[0])) {
    Simulation_B.dist = Simulation_B.lookaheadEndPt[0];
  } else {
    Simulation_B.dist = Simulation_DW.obj_p.KinModel.VehicleSpeedRange[0];
  }

  if ((!(Simulation_B.dist <= Simulation_DW.obj_p.KinModel.VehicleSpeedRange[1]))
      && (!rtIsNaN(Simulation_DW.obj_p.KinModel.VehicleSpeedRange[1]))) {
    Simulation_B.dist = Simulation_DW.obj_p.KinModel.VehicleSpeedRange[1];
  }

  Simulation_B.minDistance = 0.0;
  for (Simulation_B.i_d = 0; Simulation_B.i_d < 25; Simulation_B.i_d++) {
    Simulation_B.b_m[Simulation_B.i_d] = tmp[Simulation_B.i_d];
  }

  Simulation_B.i_d = memcmp(&Simulation_DW.obj_p.KinModel.VehicleInputsInternal
    [0], &Simulation_B.b_m[0], 25);
  if (Simulation_B.i_d == 0) {
    Simulation_B.i_d = 0;
  } else {
    for (Simulation_B.i_d = 0; Simulation_B.i_d < 25; Simulation_B.i_d++) {
      Simulation_B.b_m[Simulation_B.i_d] = tmp_0[Simulation_B.i_d];
    }

    Simulation_B.i_d = memcmp
      (&Simulation_DW.obj_p.KinModel.VehicleInputsInternal[0],
       &Simulation_B.b_m[0], 25);
    if (Simulation_B.i_d == 0) {
      Simulation_B.i_d = 1;
    } else {
      Simulation_B.i_d = -1;
    }
  }

  switch (Simulation_B.i_d) {
   case 0:
    Simulation_B.minDistance = Simulation_B.lookaheadEndPt[1];
    if (fabs(Simulation_B.lookaheadEndPt[1]) >
        Simulation_DW.obj_p.KinModel.MaxSteeringAngle) {
      if (Simulation_B.lookaheadEndPt[1] < 0.0) {
        Simulation_B.minDistance = -1.0;
      } else if (Simulation_B.lookaheadEndPt[1] > 0.0) {
        Simulation_B.minDistance = 1.0;
      } else if (Simulation_B.lookaheadEndPt[1] == 0.0) {
        Simulation_B.minDistance = 0.0;
      } else {
        Simulation_B.minDistance = (rtNaN);
      }

      Simulation_B.minDistance *= Simulation_DW.obj_p.KinModel.MaxSteeringAngle;
    }

    Simulation_B.minDistance = Simulation_B.dist /
      Simulation_DW.obj_p.KinModel.WheelBase * tan(Simulation_B.minDistance);
    break;

   case 1:
    Simulation_B.minDistance = rt_atan2d_snf(Simulation_B.lookaheadEndPt[1] *
      Simulation_DW.obj_p.KinModel.WheelBase, Simulation_B.lookaheadEndPt[0]);
    if (fabs(Simulation_B.minDistance) >
        Simulation_DW.obj_p.KinModel.MaxSteeringAngle) {
      if (Simulation_B.minDistance < 0.0) {
        Simulation_B.minDistance = -1.0;
      } else if (Simulation_B.minDistance > 0.0) {
        Simulation_B.minDistance = 1.0;
      } else if (Simulation_B.minDistance == 0.0) {
        Simulation_B.minDistance = 0.0;
      } else {
        Simulation_B.minDistance = (rtNaN);
      }

      Simulation_B.minDistance *= Simulation_DW.obj_p.KinModel.MaxSteeringAngle;
    }

    Simulation_B.dist = Simulation_B.lookaheadEndPt[0];
    Simulation_B.minDistance = Simulation_B.lookaheadEndPt[0] /
      Simulation_DW.obj_p.KinModel.WheelBase * tan(Simulation_B.minDistance);
    break;
  }

  Simulation_B.Selector1[0] = cos(Simulation_B.Integrator[2]);
  Simulation_B.Selector1[3] = 0.0;
  Simulation_B.Selector1[1] = sin(Simulation_B.Integrator[2]);
  Simulation_B.Selector1[4] = 0.0;
  Simulation_B.Selector1[2] = 0.0;
  Simulation_B.Selector1[5] = 1.0;
  for (Simulation_B.i_d = 0; Simulation_B.i_d < 3; Simulation_B.i_d++) {
    /* MATLABSystem: '<S10>/MATLAB System' */
    Simulation_B.MATLABSystem[Simulation_B.i_d] = 0.0;
    Simulation_B.MATLABSystem[Simulation_B.i_d] +=
      Simulation_B.Selector1[Simulation_B.i_d] * Simulation_B.dist;
    Simulation_B.MATLABSystem[Simulation_B.i_d] +=
      Simulation_B.Selector1[Simulation_B.i_d + 3] * Simulation_B.minDistance;
  }

  if (rtmIsMajorTimeStep(Simulation_M)) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Memory: '<Root>/Memory'
     */
    Simulation_B.lookaheadEndPt[0] = Simulation_B.mv[0] -
      Simulation_DW.Memory_PreviousInput[0];
    Simulation_B.lookaheadEndPt[1] = Simulation_B.mv[1] -
      Simulation_DW.Memory_PreviousInput[1];
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Gain: '<S1>/Gain'
   *  Sum: '<S1>/Sum'
   */
  Simulation_B.v_dot = (Simulation_B.lookaheadStartPt[0] -
                        Simulation_P.Gain_Gain_j * Simulation_B.v) *
    Simulation_P.Gain1_Gain;

  /* BusAssignment: '<Root>/Bus Assignment1' */
  Simulation_B.BusAssignment1.X = Simulation_B.Integrator[0];
  Simulation_B.BusAssignment1.Y = Simulation_B.Integrator[1];
  Simulation_B.BusAssignment1.Theta = Simulation_B.Integrator[2];

  /* Outputs for Atomic SubSystem: '<Root>/Publish1' */
  /* MATLABSystem: '<S5>/SinkBlock' */
  Pub_Simulation_156.publish(&Simulation_B.BusAssignment1);

  /* End of Outputs for SubSystem: '<Root>/Publish1' */
  if (rtmIsMajorTimeStep(Simulation_M)) {
  }

  if (rtmIsMajorTimeStep(Simulation_M)) {
    /* Update for Enabled SubSystem: '<Root>/MPC Controller' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (Simulation_DW.MPCController_MODE && rtmIsMajorTimeStep(Simulation_M)) {
      /* Update for Delay: '<S13>/x_Delay' */
      Simulation_DW.icLoad = false;
      memcpy(&Simulation_DW.x_Delay_DSTATE[0], &Simulation_B.xseq[0], 20U *
             sizeof(real_T));

      /* Update for Memory: '<S4>/Memory' */
      Simulation_DW.Memory_PreviousInput_a[0] = Simulation_B.mv[0];
      Simulation_DW.Memory_PreviousInput_a[1] = Simulation_B.mv[1];

      /* Update for Delay: '<S13>/mv_Delay' */
      Simulation_DW.icLoad_n = false;
      memcpy(&Simulation_DW.mv_Delay_DSTATE[0], &Simulation_B.mvseq[0], 10U *
             sizeof(real_T));

      /* Update for Delay: '<S13>/slack_delay' */
      Simulation_DW.icLoad_b = false;
      Simulation_DW.slack_delay_DSTATE = Simulation_B.e;
    }

    /* End of Update for SubSystem: '<Root>/MPC Controller' */
    if (rtmIsMajorTimeStep(Simulation_M)) {
      /* Update for Memory: '<Root>/Memory' */
      Simulation_DW.Memory_PreviousInput[0] = Simulation_B.mv[0];
      Simulation_DW.Memory_PreviousInput[1] = Simulation_B.mv[1];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Simulation_M)) {
    rt_ertODEUpdateContinuousStates(&Simulation_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Simulation_M->Timing.clockTick0)) {
      ++Simulation_M->Timing.clockTickH0;
    }

    Simulation_M->Timing.t[0] = rtsiGetSolverStopTime(&Simulation_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Simulation_M->Timing.clockTick1++;
      if (!Simulation_M->Timing.clockTick1) {
        Simulation_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Simulation_derivatives(void)
{
  XDot_Simulation_T *_rtXdot;
  _rtXdot = ((XDot_Simulation_T *) Simulation_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Simulation_B.v_dot;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE_m[0] = Simulation_B.MATLABSystem[0];
  _rtXdot->Integrator_CSTATE_m[1] = Simulation_B.MATLABSystem[1];
  _rtXdot->Integrator_CSTATE_m[2] = Simulation_B.MATLABSystem[2];

  /* Derivatives for Enabled SubSystem: '<Root>/Pure Pursuit Controller' */
  if (Simulation_DW.PurePursuitController_MODE) {
    /* Derivatives for Integrator: '<S64>/Filter' */
    _rtXdot->Filter_CSTATE = Simulation_B.FilterCoefficient;

    /* Derivatives for Integrator: '<S69>/Integrator' */
    _rtXdot->Integrator_CSTATE_i = Simulation_B.IntegralGain;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_Simulation_T *) Simulation_M->derivs)->Filter_CSTATE);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/Pure Pursuit Controller' */
}

/* Model initialize function */
void Simulation_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Simulation_P.BicycleKinematicModel_VehicleSp[0] = rtMinusInf;
  Simulation_P.BicycleKinematicModel_VehicleSp[1] = rtInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Simulation_M->solverInfo,
                          &Simulation_M->Timing.simTimeStep);
    rtsiSetTPtr(&Simulation_M->solverInfo, &rtmGetTPtr(Simulation_M));
    rtsiSetStepSizePtr(&Simulation_M->solverInfo,
                       &Simulation_M->Timing.stepSize0);
    rtsiSetdXPtr(&Simulation_M->solverInfo, &Simulation_M->derivs);
    rtsiSetContStatesPtr(&Simulation_M->solverInfo, (real_T **)
                         &Simulation_M->contStates);
    rtsiSetNumContStatesPtr(&Simulation_M->solverInfo,
      &Simulation_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Simulation_M->solverInfo,
      &Simulation_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Simulation_M->solverInfo,
      &Simulation_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Simulation_M->solverInfo,
      &Simulation_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Simulation_M->solverInfo, (&rtmGetErrorStatus
      (Simulation_M)));
    rtsiSetRTModelPtr(&Simulation_M->solverInfo, Simulation_M);
  }

  rtsiSetSimTimeStep(&Simulation_M->solverInfo, MAJOR_TIME_STEP);
  Simulation_M->intgData.y = Simulation_M->odeY;
  Simulation_M->intgData.f[0] = Simulation_M->odeF[0];
  Simulation_M->intgData.f[1] = Simulation_M->odeF[1];
  Simulation_M->intgData.f[2] = Simulation_M->odeF[2];
  Simulation_M->contStates = ((X_Simulation_T *) &Simulation_X);
  rtsiSetSolverData(&Simulation_M->solverInfo, static_cast<void *>
                    (&Simulation_M->intgData));
  rtsiSetSolverName(&Simulation_M->solverInfo,"ode3");
  rtmSetTPtr(Simulation_M, &Simulation_M->Timing.tArray[0]);
  Simulation_M->Timing.stepSize0 = 0.1;

  /* block I/O */
  (void) memset((static_cast<void *>(&Simulation_B)), 0,
                sizeof(B_Simulation_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&Simulation_X), 0,
                  sizeof(X_Simulation_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&Simulation_DW), 0,
                sizeof(DW_Simulation_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_1[11];
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_2[7];
    static const char_T tmp[7] = { '/', 's', 'i', 'g', 'n', 'a', 'l' };

    static const char_T tmp_0[9] = { '/', 'm', 'p', 'c', 'p', 'a', 'r', 'a', 'm'
    };

    static const char_T tmp_1[10] = { '/', 'm', 'i', 'd', 'p', 'o', 'i', 'n',
      't', 's' };

    static const char_T tmp_2[6] = { '/', 's', 't', 'a', 't', 'e' };

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S7>/SourceBlock' */
    Simulation_DW.obj_c4.matlabCodegenIsDeleted = false;
    Simulation_DW.objisempty_g = true;
    Simulation_DW.obj_c4.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_Simulation_292.createSubscriber(&b_zeroDelimTopic[0], 1);
    Simulation_DW.obj_c4.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S8>/SourceBlock' */
    Simulation_DW.obj_j.matlabCodegenIsDeleted = false;
    Simulation_DW.objisempty_o = true;
    Simulation_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Sub_Simulation_110.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    Simulation_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S8>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Enabled SubSystem: '<Root>/MPC Controller' */
    Simulation_DW.MPCController_MODE = false;

    /* Start for FromWorkspace: '<S4>/From Workspace' */
    {
      static real_T pTimeValues0[] = { 0.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.7 } ;

      Simulation_DW.FromWorkspace_PWORK.TimePtr = static_cast<void *>
        (pTimeValues0);
      Simulation_DW.FromWorkspace_PWORK.DataPtr = static_cast<void *>
        (pDataValues0);
      Simulation_DW.FromWorkspace_IWORK.PrevIndex = 0;
    }

    /* End of Start for SubSystem: '<Root>/MPC Controller' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S9>/SourceBlock' */
    Simulation_DW.obj_c.matlabCodegenIsDeleted = false;
    Simulation_DW.objisempty = true;
    Simulation_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[10] = '\x00';
    Sub_Simulation_266.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    Simulation_DW.obj_c.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S9>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Enabled SubSystem: '<Root>/Pure Pursuit Controller' */
    Simulation_DW.PurePursuitController_MODE = false;

    /* Start for MATLABSystem: '<S6>/Pure Pursuit1' */
    Simulation_DW.objisempty_a = true;
    Simulation_DW.obj.DesiredLinearVelocity =
      Simulation_P.PurePursuit1_DesiredLinearVeloc;
    Simulation_DW.obj.MaxAngularVelocity =
      Simulation_P.PurePursuit1_MaxAngularVelocity;
    Simulation_DW.obj.LookaheadDistance = Simulation_P.ld;
    Simulation_DW.obj.isInitialized = 1;
    for (i = 0; i < 80; i++) {
      Simulation_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    Simulation_DW.obj.LookaheadPoint[0] = 0.0;
    Simulation_DW.obj.LookaheadPoint[1] = 0.0;
    Simulation_DW.obj.LastPose[0] = 0.0;
    Simulation_DW.obj.LastPose[1] = 0.0;
    Simulation_DW.obj.LastPose[2] = 0.0;
    Simulation_DW.obj.ProjectionPoint[0] = (rtNaN);
    Simulation_DW.obj.ProjectionPoint[1] = (rtNaN);
    Simulation_DW.obj.ProjectionLineIndex = 0.0;

    /* End of Start for MATLABSystem: '<S6>/Pure Pursuit1' */
    /* End of Start for SubSystem: '<Root>/Pure Pursuit Controller' */

    /* Start for MATLABSystem: '<S10>/MATLAB System' */
    Simulation_DW.obj_p.isInitialized = 0;
    Simulation_DW.obj_p.tunablePropertyChanged[0] = false;
    Simulation_DW.obj_p.tunablePropertyChanged[1] = false;
    Simulation_DW.obj_p.tunablePropertyChanged[2] = false;
    Simulation_DW.objisempty_d = true;
    if (Simulation_DW.obj_p.isInitialized == 1) {
      Simulation_DW.obj_p.TunablePropsChanged = true;
      Simulation_DW.obj_p.tunablePropertyChanged[0] = true;
    }

    Simulation_DW.obj_p.WheelBase = Simulation_P.BicycleKinematicModel_WheelBase;
    if (Simulation_DW.obj_p.isInitialized == 1) {
      Simulation_DW.obj_p.TunablePropsChanged = true;
      Simulation_DW.obj_p.tunablePropertyChanged[1] = true;
    }

    Simulation_DW.obj_p.VehicleSpeedRange[0] =
      Simulation_P.BicycleKinematicModel_VehicleSp[0];
    Simulation_DW.obj_p.VehicleSpeedRange[1] =
      Simulation_P.BicycleKinematicModel_VehicleSp[1];
    if (Simulation_DW.obj_p.isInitialized == 1) {
      Simulation_DW.obj_p.TunablePropsChanged = true;
      Simulation_DW.obj_p.tunablePropertyChanged[2] = true;
    }

    Simulation_DW.obj_p.MaxSteeringAngle =
      Simulation_P.BicycleKinematicModel_MaxSteeri;
    Simulation_SystemCore_setup(&Simulation_DW.obj_p);

    /* End of Start for MATLABSystem: '<S10>/MATLAB System' */

    /* Start for Atomic SubSystem: '<Root>/Publish1' */
    /* Start for MATLABSystem: '<S5>/SinkBlock' */
    Simulation_DW.obj_h.matlabCodegenIsDeleted = false;
    Simulation_DW.objisempty_i = true;
    Simulation_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_2[i] = tmp_2[i];
    }

    b_zeroDelimTopic_2[6] = '\x00';
    Pub_Simulation_156.createPublisher(&b_zeroDelimTopic_2[0], 1);
    Simulation_DW.obj_h.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish1' */
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Simulation_X.Integrator_CSTATE = Simulation_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  Simulation_X.Integrator_CSTATE_m[0] =
    Simulation_P.BicycleKinematicModel_InitialSt[0];
  Simulation_X.Integrator_CSTATE_m[1] =
    Simulation_P.BicycleKinematicModel_InitialSt[1];
  Simulation_X.Integrator_CSTATE_m[2] =
    Simulation_P.BicycleKinematicModel_InitialSt[2];

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S87>/Out1' incorporates:
   *  Inport: '<S87>/In1'
   */
  Simulation_B.In1_d = Simulation_P.Out1_Y0_m;

  /* End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S88>/Out1' incorporates:
   *  Inport: '<S88>/In1'
   */
  Simulation_B.In1_e = Simulation_P.Out1_Y0_h;

  /* End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/MPC Controller' */
  /* InitializeConditions for Delay: '<S13>/x_Delay' */
  Simulation_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S13>/mv_Delay' */
  Simulation_DW.icLoad_n = true;

  /* InitializeConditions for Delay: '<S13>/slack_delay' */
  Simulation_DW.icLoad_b = true;

  /* End of SystemInitialize for SubSystem: '<Root>/MPC Controller' */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  Simulation_DW.Memory_PreviousInput[0] = Simulation_P.Memory_InitialCondition_j;

  /* SystemInitialize for Enabled SubSystem: '<Root>/MPC Controller' */
  /* InitializeConditions for Memory: '<S4>/Memory' */
  Simulation_DW.Memory_PreviousInput_a[0] = Simulation_P.Memory_InitialCondition;

  /* SystemInitialize for Outport: '<S4>/Control Commands' */
  Simulation_B.mv[0] = Simulation_P.ControlCommands_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/MPC Controller' */

  /* InitializeConditions for Memory: '<Root>/Memory' */
  Simulation_DW.Memory_PreviousInput[1] = Simulation_P.Memory_InitialCondition_j;

  /* SystemInitialize for Enabled SubSystem: '<Root>/MPC Controller' */
  /* InitializeConditions for Memory: '<S4>/Memory' */
  Simulation_DW.Memory_PreviousInput_a[1] = Simulation_P.Memory_InitialCondition;

  /* SystemInitialize for Outport: '<S4>/Control Commands' */
  Simulation_B.mv[1] = Simulation_P.ControlCommands_Y0;

  /* SystemInitialize for Outport: '<S4>/Log Data' */
  memcpy(&Simulation_B.yseq[0], &Simulation_P.LogData_Y0.yseq[0], 15U * sizeof
         (real_T));
  Simulation_B.nlpstatus = Simulation_P.LogData_Y0.nlpstatus;

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.LeftParameters[0] = Simulation_P.LogData_Y0.LeftParameters[0];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.RightParameters[0] = Simulation_P.LogData_Y0.RightParameters[0];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.LeftParameters[1] = Simulation_P.LogData_Y0.LeftParameters[1];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.RightParameters[1] = Simulation_P.LogData_Y0.RightParameters[1];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.LeftParameters[2] = Simulation_P.LogData_Y0.LeftParameters[2];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.RightParameters[2] = Simulation_P.LogData_Y0.RightParameters[2];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.LeftParameters[3] = Simulation_P.LogData_Y0.LeftParameters[3];

  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.RightParameters[3] = Simulation_P.LogData_Y0.RightParameters[3];

  /* End of SystemInitialize for SubSystem: '<Root>/MPC Controller' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S89>/Out1' incorporates:
   *  Inport: '<S89>/In1'
   */
  Simulation_B.In1 = Simulation_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Pure Pursuit Controller' */
  /* InitializeConditions for Integrator: '<S64>/Filter' */
  Simulation_X.Filter_CSTATE = Simulation_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S69>/Integrator' */
  Simulation_X.Integrator_CSTATE_i =
    Simulation_P.PIDController1_InitialConditi_n;

  /* End of SystemInitialize for SubSystem: '<Root>/Pure Pursuit Controller' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/MPC Controller' */
  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.TargetPoint[0] = Simulation_P.LogData_Y0.TargetPoint[0];

  /* End of SystemInitialize for SubSystem: '<Root>/MPC Controller' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Pure Pursuit Controller' */
  /* InitializeConditions for MATLABSystem: '<S6>/Pure Pursuit1' */
  Simulation_DW.obj.LookaheadPoint[0] *= 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Pure Pursuit Controller' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/MPC Controller' */
  /* SystemInitialize for SignalConversion generated from: '<S4>/Bus Selector' incorporates:
   *  Outport: '<S4>/Log Data'
   */
  Simulation_B.TargetPoint[1] = Simulation_P.LogData_Y0.TargetPoint[1];

  /* End of SystemInitialize for SubSystem: '<Root>/MPC Controller' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Pure Pursuit Controller' */
  /* InitializeConditions for MATLABSystem: '<S6>/Pure Pursuit1' */
  Simulation_DW.obj.LookaheadPoint[1] *= 0.0;
  Simulation_DW.obj.LastPose[0] *= 0.0;
  Simulation_DW.obj.LastPose[1] *= 0.0;
  Simulation_DW.obj.LastPose[2] *= 0.0;
  Simulation_DW.obj.ProjectionPoint[0] = (rtNaN);
  Simulation_DW.obj.ProjectionPoint[1] = (rtNaN);
  Simulation_DW.obj.ProjectionLineIndex *= 0.0;

  /* SystemInitialize for Sum: '<S78>/Sum' incorporates:
   *  Outport: '<S6>/Control Commands'
   */
  Simulation_B.Sum = Simulation_P.ControlCommands_Y0_c;

  /* SystemInitialize for Trigonometry: '<S37>/Atan' incorporates:
   *  Outport: '<S6>/Control Commands'
   */
  Simulation_B.SteeringAngle = Simulation_P.ControlCommands_Y0_c;

  /* End of SystemInitialize for SubSystem: '<Root>/Pure Pursuit Controller' */

  /* InitializeConditions for MATLABSystem: '<S10>/MATLAB System' */
  BicycleKinematics_assignModelPr(&Simulation_DW.obj_p);
}

/* Model terminate function */
void Simulation_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S7>/SourceBlock' */
  if (!Simulation_DW.obj_c4.matlabCodegenIsDeleted) {
    Simulation_DW.obj_c4.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S8>/SourceBlock' */
  if (!Simulation_DW.obj_j.matlabCodegenIsDeleted) {
    Simulation_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S9>/SourceBlock' */
  if (!Simulation_DW.obj_c.matlabCodegenIsDeleted) {
    Simulation_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */
  /* Terminate for Atomic SubSystem: '<Root>/Publish1' */
  /* Terminate for MATLABSystem: '<S5>/SinkBlock' */
  if (!Simulation_DW.obj_h.matlabCodegenIsDeleted) {
    Simulation_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish1' */
}
