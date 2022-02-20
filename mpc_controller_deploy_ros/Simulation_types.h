/*
 * Simulation_types.h
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

#ifndef RTW_HEADER_Simulation_types_h_
#define RTW_HEADER_Simulation_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_geometry_msgs_Pose2D_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_geometry_msgs_Pose2D_

struct SL_Bus_Simulation_geometry_msgs_Pose2D
{
  real_T X;
  real_T Y;
  real_T Theta;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_std_msgs_Float64_

struct SL_Bus_Simulation_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_rosestimation_Mpcparam_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_rosestimation_Mpcparam_

struct SL_Bus_Simulation_rosestimation_Mpcparam
{
  real_T LeftParameters[4];
  SL_Bus_ROSVariableLengthArrayInfo LeftParameters_SL_Info;
  real_T RightParameters[4];
  SL_Bus_ROSVariableLengthArrayInfo RightParameters_SL_Info;
  real_T TargetPoint[2];
  SL_Bus_ROSVariableLengthArrayInfo TargetPoint_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_rosestimation_Waypoints_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Simulation_rosestimation_Waypoints_

struct SL_Bus_Simulation_rosestimation_Waypoints
{
  real_T X[128];
  SL_Bus_ROSVariableLengthArrayInfo X_SL_Info;
  real_T Y[128];
  SL_Bus_ROSVariableLengthArrayInfo Y_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_param_bus_
#define DEFINED_TYPEDEF_FOR_param_bus_

struct param_bus
{
  real_T deneme1[4];
  real_T deneme2[4];
  real_T deneme3[2];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_D2HXSDhz1X0GfO61QVLFHG_
#define DEFINED_TYPEDEF_FOR_struct_D2HXSDhz1X0GfO61QVLFHG_

struct struct_D2HXSDhz1X0GfO61QVLFHG
{
  real_T yseq[15];
  real_T nlpstatus;
  real_T LeftParameters[4];
  real_T RightParameters[4];
  real_T TargetPoint[2];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6TzqbqIRJM5XbhbOJ3QCp_
#define DEFINED_TYPEDEF_FOR_struct_6TzqbqIRJM5XbhbOJ3QCp_

struct struct_6TzqbqIRJM5XbhbOJ3QCp
{
  real_T values[3];
  real_T dimensions[2];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4OnUUhPSdEBgIbmFc6FLiF_
#define DEFINED_TYPEDEF_FOR_struct_4OnUUhPSdEBgIbmFc6FLiF_

struct struct_4OnUUhPSdEBgIbmFc6FLiF
{
  struct_6TzqbqIRJM5XbhbOJ3QCp signals;
  real_T time;
};

#endif

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_sG8JZ69axY52WWR6RKyApQC_Simul_T
#define struct_sG8JZ69axY52WWR6RKyApQC_Simul_T

struct sG8JZ69axY52WWR6RKyApQC_Simul_T
{
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
};

#endif                              /* struct_sG8JZ69axY52WWR6RKyApQC_Simul_T */

#ifndef struct_s7RdrPWkr8UPAUyTdDJkLaG_Simul_T
#define struct_s7RdrPWkr8UPAUyTdDJkLaG_Simul_T

struct s7RdrPWkr8UPAUyTdDJkLaG_Simul_T
{
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

#endif                              /* struct_s7RdrPWkr8UPAUyTdDJkLaG_Simul_T */

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_P_T */

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_S_T */

#ifndef struct_cell_wrap_Simulation_T
#define struct_cell_wrap_Simulation_T

struct cell_wrap_Simulation_T
{
  uint32_T f1[8];
};

#endif                                 /* struct_cell_wrap_Simulation_T */

#ifndef struct_d_cell_wrap_Simulation_T
#define struct_d_cell_wrap_Simulation_T

struct d_cell_wrap_Simulation_T
{
  char_T f1[25];
};

#endif                                 /* struct_d_cell_wrap_Simulation_T */

#ifndef struct_c_bicycleKinematics_Simulatio_T
#define struct_c_bicycleKinematics_Simulatio_T

struct c_bicycleKinematics_Simulatio_T
{
  real_T WheelBase;
  real_T VehicleSpeedRange[2];
  real_T MaxSteeringAngle;
  char_T VehicleInputsInternal[25];
};

#endif                              /* struct_c_bicycleKinematics_Simulatio_T */

#ifndef struct_robotics_slmobile_internal_bl_T
#define struct_robotics_slmobile_internal_bl_T

struct robotics_slmobile_internal_bl_T
{
  boolean_T tunablePropertyChanged[3];
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_Simulation_T inputVarSize[3];
  c_bicycleKinematics_Simulatio_T KinModel;
  real_T WheelBase;
  real_T VehicleSpeedRange[2];
  real_T MaxSteeringAngle;
};

#endif                              /* struct_robotics_slmobile_internal_bl_T */

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_somzaGboVhDG7PNQS6E98jD_Simul_T
#define struct_somzaGboVhDG7PNQS6E98jD_Simul_T

struct somzaGboVhDG7PNQS6E98jD_Simul_T
{
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T OptimalityTolerance;
  real_T ConstraintTolerance;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
  boolean_T IterDisplayQP;
};

#endif                              /* struct_somzaGboVhDG7PNQS6E98jD_Simul_T */

#ifndef struct_sttYSJM5GCi2c1Eu0R50efC_Simul_T
#define struct_sttYSJM5GCi2c1Eu0R50efC_Simul_T

struct sttYSJM5GCi2c1Eu0R50efC_Simul_T
{
  real_T iterations;
  real_T funcCount;
  char_T algorithm[3];
  real_T constrviolation;
  real_T stepsize;
  real_T lssteplength;
  real_T firstorderopt;
};

#endif                              /* struct_sttYSJM5GCi2c1Eu0R50efC_Simul_T */

#ifndef struct_cell_0_Simulation_T
#define struct_cell_0_Simulation_T

struct cell_0_Simulation_T
{
  real_T f1[4];
  real_T f2[4];
  real_T f3[2];
};

#endif                                 /* struct_cell_0_Simulation_T */

#ifndef struct_nav_slalgs_internal_PurePursu_T
#define struct_nav_slalgs_internal_PurePursu_T

struct nav_slalgs_internal_PurePursu_T
{
  int32_T isInitialized;
  cell_wrap_Simulation_T inputVarSize[2];
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[80];
};

#endif                              /* struct_nav_slalgs_internal_PurePursu_T */

#ifndef struct_emxArray_real_T_114x28_Simula_T
#define struct_emxArray_real_T_114x28_Simula_T

struct emxArray_real_T_114x28_Simula_T
{
  real_T data[3192];
  int32_T size[2];
};

#endif                              /* struct_emxArray_real_T_114x28_Simula_T */

#ifndef struct_emxArray_real_T_114x16_Simula_T
#define struct_emxArray_real_T_114x16_Simula_T

struct emxArray_real_T_114x16_Simula_T
{
  real_T data[1824];
  int32_T size[2];
};

#endif                              /* struct_emxArray_real_T_114x16_Simula_T */

#ifndef struct_emxArray_real_T_211x114_Simul_T
#define struct_emxArray_real_T_211x114_Simul_T

struct emxArray_real_T_211x114_Simul_T
{
  real_T data[24054];
  int32_T size[2];
};

#endif                              /* struct_emxArray_real_T_211x114_Simul_T */

#ifndef struct_emxArray_real_T_211x211_Simul_T
#define struct_emxArray_real_T_211x211_Simul_T

struct emxArray_real_T_211x211_Simul_T
{
  real_T data[44521];
  int32_T size[2];
};

#endif                              /* struct_emxArray_real_T_211x211_Simul_T */

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_s_scny3ZL5wSoGnQzGbzQQC_Simul_T
#define struct_s_scny3ZL5wSoGnQzGbzQQC_Simul_T

struct s_scny3ZL5wSoGnQzGbzQQC_Simul_T
{
  emxArray_real_T_211x211_Simul_T FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_;
  real_T workspace2_;
};

#endif                              /* struct_s_scny3ZL5wSoGnQzGbzQQC_Simul_T */

#ifndef struct_s_p8D01swky5RV3KRPR0QFHD_Simu_T
#define struct_s_p8D01swky5RV3KRPR0QFHD_Simu_T

struct s_p8D01swky5RV3KRPR0QFHD_Simu_T
{
  real_T x[4];
  real_T lastMV[2];
  real_T ref[12];
  real_T OutputWeights[12];
  real_T MVWeights[8];
  real_T MVRateWeights[8];
  real_T ECRWeight;
  real_T OutputMin[12];
  real_T OutputMax[12];
  real_T StateMin[16];
  real_T StateMax[16];
  real_T MVMin[8];
  real_T MVMax[8];
  real_T MVRateMin[8];
  real_T MVRateMax[8];
  real_T MVScaledTarget[8];
  cell_0_Simulation_T Parameters;
};

#endif                              /* struct_s_p8D01swky5RV3KRPR0QFHD_Simu_T */

#ifndef struct_sGG2r25KPyhmOjq8dWjrTNG_Simul_T
#define struct_sGG2r25KPyhmOjq8dWjrTNG_Simul_T

struct sGG2r25KPyhmOjq8dWjrTNG_Simul_T
{
  real_T Ts;
  real_T CurrentStates[4];
  real_T LastMV[2];
  real_T References[12];
  real_T MVTarget[8];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex[2];
};

#endif                              /* struct_sGG2r25KPyhmOjq8dWjrTNG_Simul_T */

#ifndef struct_s_6nVRKLouICEXkdtVoDbkRE_Simu_T
#define struct_s_6nVRKLouICEXkdtVoDbkRE_Simu_T

struct s_6nVRKLouICEXkdtVoDbkRE_Simu_T
{
  s_p8D01swky5RV3KRPR0QFHD_Simu_T runtimedata;
  sGG2r25KPyhmOjq8dWjrTNG_Simul_T userdata;
};

#endif                              /* struct_s_6nVRKLouICEXkdtVoDbkRE_Simu_T */

#ifndef struct_anonymous_function_Simulation_T
#define struct_anonymous_function_Simulation_T

struct anonymous_function_Simulation_T
{
  s_6nVRKLouICEXkdtVoDbkRE_Simu_T workspace;
};

#endif                              /* struct_anonymous_function_Simulation_T */

#ifndef struct_s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T
#define struct_s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T

struct s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T
{
  anonymous_function_Simulation_T objfun;
  anonymous_function_Simulation_T nonlcon;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
};

#endif                              /* struct_s_CTfvpiq7Dke5kLVDIXBZAF_Simu_T */

#ifndef struct_emxArray_real_T_60_Simulation_T
#define struct_emxArray_real_T_60_Simulation_T

struct emxArray_real_T_60_Simulation_T
{
  real_T data[60];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_60_Simulation_T */

#ifndef struct_emxArray_real_T_114_Simulatio_T
#define struct_emxArray_real_T_114_Simulatio_T

struct emxArray_real_T_114_Simulatio_T
{
  real_T data[114];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_114_Simulatio_T */

#ifndef struct_emxArray_real_T_211_Simulatio_T
#define struct_emxArray_real_T_211_Simulatio_T

struct emxArray_real_T_211_Simulatio_T
{
  real_T data[211];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_211_Simulatio_T */

#ifndef struct_emxArray_int32_T_211_Simulati_T
#define struct_emxArray_int32_T_211_Simulati_T

struct emxArray_int32_T_211_Simulati_T
{
  int32_T data[211];
  int32_T size;
};

#endif                              /* struct_emxArray_int32_T_211_Simulati_T */

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
#define struct_s_Oj8MU04AHs4QRosT0dAtfB_Simu_T

struct s_Oj8MU04AHs4QRosT0dAtfB_Simu_T
{
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[21];
  real_T xstarsqp_old[21];
  emxArray_real_T_60_Simulation_T cIneq;
  emxArray_real_T_60_Simulation_T cIneq_old;
  real_T cEq[16];
  real_T cEq_old[16];
  emxArray_real_T_114_Simulatio_T grad;
  emxArray_real_T_114_Simulatio_T grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_211_Simulatio_T lambdasqp;
  emxArray_real_T_211_Simulatio_T lambdaStopTest;
  emxArray_real_T_211_Simulatio_T lambdaStopTestPrev;
  real_T steplength;
  emxArray_real_T_114_Simulatio_T delta_x;
  emxArray_real_T_114_Simulatio_T socDirection;
  emxArray_int32_T_211_Simulati_T workingset_old;
  emxArray_real_T_114x28_Simula_T JacCineqTrans_old;
  emxArray_real_T_114x16_Simula_T JacCeqTrans_old;
  emxArray_real_T_114_Simulatio_T gradLag;
  emxArray_real_T_114_Simulatio_T delta_gradLag;
  emxArray_real_T_114_Simulatio_T xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_211_Simulatio_T lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_114_Simulatio_T searchDir;
};

#endif                              /* struct_s_Oj8MU04AHs4QRosT0dAtfB_Simu_T */

#ifndef struct_s_07kFxl6AwaSqE78SXFEtBE_Simu_T
#define struct_s_07kFxl6AwaSqE78SXFEtBE_Simu_T

struct s_07kFxl6AwaSqE78SXFEtBE_Simu_T
{
  emxArray_real_T_211x114_Simul_T workspace_double;
  emxArray_int32_T_211_Simulati_T workspace_int;
  emxArray_int32_T_211_Simulati_T workspace_sort;
};

#endif                              /* struct_s_07kFxl6AwaSqE78SXFEtBE_Simu_T */

#ifndef struct_emxArray_real_T_6840_Simulati_T
#define struct_emxArray_real_T_6840_Simulati_T

struct emxArray_real_T_6840_Simulati_T
{
  real_T data[6840];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_6840_Simulati_T */

#ifndef struct_emxArray_real_T_1824_Simulati_T
#define struct_emxArray_real_T_1824_Simulati_T

struct emxArray_real_T_1824_Simulati_T
{
  real_T data[1824];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_1824_Simulati_T */

#ifndef struct_emxArray_int32_T_114_Simulati_T
#define struct_emxArray_int32_T_114_Simulati_T

struct emxArray_int32_T_114_Simulati_T
{
  int32_T data[114];
  int32_T size;
};

#endif                              /* struct_emxArray_int32_T_114_Simulati_T */

#ifndef struct_emxArray_real_T_24054_Simulat_T
#define struct_emxArray_real_T_24054_Simulat_T

struct emxArray_real_T_24054_Simulat_T
{
  real_T data[24054];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_24054_Simulat_T */

#ifndef struct_emxArray_boolean_T_211_Simula_T
#define struct_emxArray_boolean_T_211_Simula_T

struct emxArray_boolean_T_211_Simula_T
{
  boolean_T data[211];
  int32_T size;
};

#endif                              /* struct_emxArray_boolean_T_211_Simula_T */

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
#define struct_s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T

struct s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_6840_Simulati_T Aineq;
  emxArray_real_T_60_Simulation_T bineq;
  emxArray_real_T_1824_Simulati_T Aeq;
  real_T beq[16];
  emxArray_real_T_114_Simulatio_T lb;
  emxArray_real_T_114_Simulatio_T ub;
  emxArray_int32_T_114_Simulati_T indexLB;
  emxArray_int32_T_114_Simulati_T indexUB;
  emxArray_int32_T_114_Simulati_T indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[16];
  emxArray_real_T_24054_Simulat_T ATwset;
  emxArray_real_T_211_Simulatio_T bwset;
  int32_T nActiveConstr;
  emxArray_real_T_211_Simulatio_T maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  emxArray_boolean_T_211_Simula_T isActiveConstr;
  emxArray_int32_T_211_Simulati_T Wid;
  emxArray_int32_T_211_Simulati_T Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                              /* struct_s_fwiqsfo4bpbXgdp6e6yQoG_Simu_T */

#ifndef struct_emxArray_real_T_113_Simulatio_T
#define struct_emxArray_real_T_113_Simulatio_T

struct emxArray_real_T_113_Simulatio_T
{
  real_T data[113];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_113_Simulatio_T */

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_s_ollgpvqodLtAhexvVgD8pB_Simu_T
#define struct_s_ollgpvqodLtAhexvVgD8pB_Simu_T

struct s_ollgpvqodLtAhexvVgD8pB_Simu_T
{
  emxArray_real_T_114_Simulatio_T grad;
  emxArray_real_T_113_Simulatio_T Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                              /* struct_s_ollgpvqodLtAhexvVgD8pB_Simu_T */

#ifndef struct_s_ASr52t7t39LT7rtZ8hZCX_Simul_T
#define struct_s_ASr52t7t39LT7rtZ8hZCX_Simul_T

struct s_ASr52t7t39LT7rtZ8hZCX_Simul_T
{
  int32_T ldq;
  emxArray_real_T_211x211_Simul_T QR;
  emxArray_real_T_211x211_Simul_T Q;
  emxArray_int32_T_211_Simulati_T jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_211_Simulatio_T tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                              /* struct_s_ASr52t7t39LT7rtZ8hZCX_Simul_T */

#ifndef struct_emxArray_real_T_28_Simulation_T
#define struct_emxArray_real_T_28_Simulation_T

struct emxArray_real_T_28_Simulation_T
{
  real_T data[28];
  int32_T size;
};

#endif                              /* struct_emxArray_real_T_28_Simulation_T */

/* Custom Type definition for MATLAB Function: '<S12>/NLMPC' */
#ifndef struct_s_NeeBi9ecDK5JSUDm498EDH_Simu_T
#define struct_s_NeeBi9ecDK5JSUDm498EDH_Simu_T

struct s_NeeBi9ecDK5JSUDm498EDH_Simu_T
{
  anonymous_function_Simulation_T objfun;
  anonymous_function_Simulation_T nonlin;
  real_T f_1;
  emxArray_real_T_28_Simulation_T cIneq_1;
  real_T cEq_1[16];
  real_T f_2;
  emxArray_real_T_28_Simulation_T cIneq_2;
  real_T cEq_2[16];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  boolean_T hasLB[21];
  boolean_T hasUB[21];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                              /* struct_s_NeeBi9ecDK5JSUDm498EDH_Simu_T */

/* Parameters (default storage) */
typedef struct P_Simulation_T_ P_Simulation_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Simulation_T RT_MODEL_Simulation_T;

#endif                                 /* RTW_HEADER_Simulation_types_h_ */
