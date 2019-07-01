#include "B1PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
// #include "Randomize.hh"

B1PrimaryGeneratorAction::B1PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0), 
  fEnvelopeBox(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
}

B1PrimaryGeneratorAction::~B1PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void B1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  G4Box* mat_box = dynamic_cast<G4Box*>(G4LogicalVolumeStore::GetInstance()->GetVolume("material_box")->GetSolid());
  
//   G4double size = 0.8; 
//   G4double x0 = size * envSizeXY * (G4UniformRand()-0.5);
//   G4double y0 = size * envSizeXY * (G4UniformRand()-0.5);
  G4double x0 = 0.;
  G4double y0 = 0.;
  G4double z0 = -1.2 * mat_box->GetZHalfLength();
  
  // shoot particles along z axis from directly in front of the material box
  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

  fParticleGun->GeneratePrimaryVertex(anEvent);
}
