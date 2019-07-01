#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"

#include "G4RunManager.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4RootAnalysisManager.hh"

#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4Box.hh"


B1SteppingAction::B1SteppingAction(B1EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{ }

B1SteppingAction::~B1SteppingAction()
{ }

void B1SteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) { 
    const B1DetectorConstruction* detectorConstruction
      = static_cast<const B1DetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
  }
  
//   G4double zMaxMat  = dynamic_cast<G4Box*>(G4LogicalVolumeStore::GetInstance()->GetVolume("material_box")->GetSolid())->GetZHalfLength();
  G4double zMaxEnv  = dynamic_cast<G4Box*>(G4LogicalVolumeStore::GetInstance()->GetVolume("environment")->GetSolid())->GetZHalfLength();
//   G4double zPosPre  = step->GetPreStepPoint()->GetPosition().getZ();
  G4double zPosPost = step->GetPostStepPoint()->GetPosition().getZ();
  
  if (zPosPost >= zMaxEnv) return; // have left all environment
  
  // get volume in which the step began
  G4LogicalVolume* start_volume 
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
          
  // only set entry and exit energies for the first particle
  // Geant4 starts counting the track with 0 for the gun
  if (step->GetTrack()->GetTrackID()==1)
  {
    // volume in which the step finished
    G4LogicalVolume* finish_volume 
      = step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    
    // in case of entrance
    if (finish_volume == fScoringVolume && 
        start_volume  != fScoringVolume)
    {
      // read the kinetic energy the particle had when entering the active volume
      fEventAction->SetEntryEnergy(
        step->GetPreStepPoint()->GetKineticEnergy()
      );
    }
    
    // in case of exit
    else if (finish_volume != fScoringVolume && 
             start_volume == fScoringVolume)
    {
      // energy after the active volume
      fEventAction->SetExitEnergy(
        step->GetPostStepPoint()->GetKineticEnergy()
      );
    }
  }

  // check if we are in scoring volume
  if (start_volume != fScoringVolume) return;
  G4RootAnalysisManager* analysisManager = G4AnalysisManager::Instance();

  // collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);  
  
  // histogram the step length of this step
  if (step->GetTrack()->GetTrackID()==1)
  {
    analysisManager->FillH1(3, 
      step->GetStepLength()
    );
  }
}

