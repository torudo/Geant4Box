#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
// #include "G4Cons.hh"
// #include "G4Orb.hh"
// #include "G4Sphere.hh"
// #include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

B1DetectorConstruction::~B1DetectorConstruction()
{ }


G4VPhysicalVolume* B1DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Option to switch on/off checking of volumes overlaps
  G4bool checkOverlaps = true;

  // test material
  G4double box_sizeXY = 2*m, box_sizeZ = 1*cm; // box sizes
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Neon", "G4_Ne", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Neon", "G4_Ne", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  G4Material* box_mat = nist->ConstructNewGasMaterial("STD_N", "G4_N", CLHEP::STP_Temperature, CLHEP::STP_Pressure);// 3.e-18*pascal);
  //G4Material* box_mat = nist->FindOrBuildMaterial("G4_Ur","Uran", "92", 1)
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Uran", "G4_U", 300.0, 1.0);
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_Galactic");


  //---- The global object (with vacuum) ----//

  G4Box* environment_solid
    = new G4Box("environment", 3.*box_sizeXY, 3.*box_sizeXY, 100.*box_sizeZ);
  G4LogicalVolume* environment_logic
    = new G4LogicalVolume(environment_solid, env_mat, "environment");
  G4VPhysicalVolume* environment
    = new G4PVPlacement(
      0,                          // rotation
      G4ThreeVector(0.,0.,0.),    // inital position
      environment_logic,          // volume
      "environment",              // name
      0,                          // no mother value
      false,                      // no bool operation
      0,                          // copy number
      checkOverlaps               // integrity check
    );


  //---- Test volume where E deposition is measured ----//

  // solid: physical size
  G4Box* material_box_solid
    = new G4Box("material_box", 0.5*box_sizeXY, 0.5*box_sizeXY, 0.5*box_sizeZ); // 1/2 because Geant takes values as halflengths
  // logic: material properties
  G4LogicalVolume* material_box_logic
    = new G4LogicalVolume(material_box_solid, box_mat, "material_box");
  // actual volume
  new G4PVPlacement(
    0,
    G4ThreeVector(0.,0.,0.),
    material_box_logic,
    "material_box",
    environment_logic,
    false,
    0,
    checkOverlaps
  );

  fScoringVolume = material_box_logic;

  //
  //always return the physical World
  //
  return environment;
}
