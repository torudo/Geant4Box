#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1RunAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"


B1EventAction::B1EventAction(B1RunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction),
  fEdep(0.),
  fEntryEnergy(0.),
  fExitEnergy(0.)
{ }


B1EventAction::~B1EventAction()
{ }


void B1EventAction::BeginOfEventAction(const G4Event*)
{
  fEdep = 0.;
  fEntryEnergy =0.;
  fExitEnergy  =0.;
}


void B1EventAction::EndOfEventAction(const G4Event*)
{
  // thickness of the detector in z direction (converted to cm)
  // i.e. track length for un-curved particles
  G4double zLen
    = dynamic_cast<G4Box*>(G4LogicalVolumeStore::GetInstance()->GetVolume("material_box")->GetSolid())
    ->GetZHalfLength()*2.*CLHEP::mm/CLHEP::cm;

  fEdep = fEdep/zLen;
  G4double fEloss = (fEntryEnergy-fExitEnergy)/zLen;

  // write energy loss and deposition
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->FillH1(1, (fEdep/CLHEP::keV)*CLHEP::MeV); // Geant default unit: MeV; we use keV here.
  analysisManager->FillH1(2, (fEloss/CLHEP::keV)*CLHEP::MeV);


}
