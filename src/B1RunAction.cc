#include "B1RunAction.hh"
#include "B1PrimaryGeneratorAction.hh"
#include "B1DetectorConstruction.hh"
// #include "B1Run.hh"

#include "G4RunManager.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4RootAnalysisManager.hh"

#include "G4Run.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"


B1RunAction::B1RunAction() : G4UserRunAction()
{
  G4RootAnalysisManager* analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);

  //---- Creating histograms ----//
  analysisManager->SetFirstHistoId(1);
// 15000 for Al
// 10 for gases of liwer density
// otherwise 700
  // Energy depostion in detector (all particles)
  analysisManager->CreateH1("Edep","total E deposition", 500, 0., 65000);
  analysisManager->SetH1XAxisTitle(1, "energy deposit per cm (keV)");
  analysisManager->SetH1YAxisTitle(1, "nof entries");

  // Energy loss of the incident particle
  analysisManager->CreateH1("Eloss","E loss", 500, 0., 65000);
  analysisManager->SetH1XAxisTitle(2, "energy loss per cm (keV)");
  analysisManager->SetH1YAxisTitle(2, "nof entries");

  // Step lengths of simulation steps (i.e. distance between collisions)
  analysisManager->CreateH1("StepL","Step Lengths", 100, 0., 40*CLHEP::cm);
  analysisManager->SetH1XAxisTitle(3, "step length (mm)");
  analysisManager->SetH1YAxisTitle(3, "nof entries");
}


B1RunAction::~B1RunAction()
{
    delete G4AnalysisManager::Instance();
}


void B1RunAction::BeginOfRunAction(const G4Run*)
{
  // inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  // copy from B4
  G4RootAnalysisManager* analysisManager = G4AnalysisManager::Instance();
  G4String fileName = "BBmuon_40000_MeV_Cu_01_cm";
  //  G4String fileName = "Edep_ZN_1_H_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_2_He_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_3_Li_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_4_Be_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_5_B_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_6_C_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_7_N_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_8_O_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_9_F_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_10_Ne_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_11_Na_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_12_Mg_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_13_Al_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_14_Si_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_15_P_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_16_S_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_17_Cl_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_18_Ar_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_19_K_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_20_Ca_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_21_Sc_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_22_Ti_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_23_V_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_24_Cr_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_25_Mn_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_26_Fe_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_27_Co_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_28_Ni_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_29_Cu_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_30_Zn_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_31_Ga_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_32_Ge_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_33_As_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_34_Se_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_35_Br_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_36_Kr_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_37_Rb_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_38_Sr_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_39_Y_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_40_Zr_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_41_Nb_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_42_Mo_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_43_Tc_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_44_Ru_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_45_Rh_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_46_Pd_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_47_Ag_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_48_Cd_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_49_In_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_50_Sn_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_51_Sb_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_52_Te_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_53_I_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_54_Xe_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_55_Cs_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_56_Ba_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_57_La_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_58_Ce_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_59_Pr_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_60_Nd_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_61_Pm_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_62_Sm_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_63_Eu_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_64_Gd_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_65_Tb_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_66_Dy_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_67_Ho_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_68_Er_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_69_Tm_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_70_Yb_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_71_Lu_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_72_Hf_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_73_Ta_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_74_W_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_75_Re_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_76_Os_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_77_Ir_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_78_Pt_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_79_Au_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_80_Hg_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_81_Tl_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_82_Pb_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_83_Bi_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_84_Po_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_85_At_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_86_Rn_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_87_Fr_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_88_Ra_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_89_Ac_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_90_Th_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_91_Pa_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_92_U_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_93_Np_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_94_Pu_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_95_Am_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_96_Cm_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_97_Bk_Proton_20_GeV_1_cm";
  // G4String fileName = "Edep_ZN_98_Cf_Proton_20_GeV_1_cm";
  analysisManager->OpenFile(fileName);
}


void B1RunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;

  G4RootAnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  // Prints whatever is in analysismanager
  //std::cout << analysisManager;
  analysisManager->CloseFile();

  G4cout
     << G4endl
     << " The run consists of " << nofEvents << " events."
     << G4endl
     << "------------------------------------------------------------"
     << G4endl
     << G4endl;
}
