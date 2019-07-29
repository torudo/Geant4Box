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

  // Energy depostion in detector (all particles)
  analysisManager->CreateH1("Edep","total E deposition", 500, 0., 7000);
  analysisManager->SetH1XAxisTitle(1, "energy deposit per cm (keV)");
  analysisManager->SetH1YAxisTitle(1, "nof entries");

  // Energy loss of the incident particle
  analysisManager->CreateH1("Eloss","E loss", 500, 0., 7000);
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
  //G4String fileName = "Edep_Proton_200_MeV_Ar_1_cm_09_P";
  G4String fileName = "Edep_ZN_13_Al_Proton_200_MeV_1_cm";
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
