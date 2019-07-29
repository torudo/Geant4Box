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
//Materials!

  G4Element* H  = nist->FindOrBuildElement(1);
  G4Element* C  = nist->FindOrBuildElement(6);
  G4Element* N  = nist->FindOrBuildElement(7);
  G4Element* O  = nist->FindOrBuildElement(8);
  G4Element* Si = nist->FindOrBuildElement(14);
  G4Element* Ar = nist->FindOrBuildElement(18);
  G4Element* Fe = nist->FindOrBuildElement(26);
  G4Element* Ge = nist->FindOrBuildElement(32);
  G4Element* Sb = nist->FindOrBuildElement(51);
  G4Element* I  = nist->FindOrBuildElement(53);
  G4Element* Cs = nist->FindOrBuildElement(55);
  G4Element* Pb = nist->FindOrBuildElement(82);
  G4Element* Bi = nist->FindOrBuildElement(83);

  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Neon", "G4_Ne", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Argon", "G4_Ar", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Kr", "G4_Kr", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Radon", "G4_Rn", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_He", "G4_He", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_N", "G4_N", CLHEP::STP_Temperature, CLHEP::STP_Pressure);// 3.e-18*pascal);

  //Fabians Code
  //G4NistManager* manager = G4NistManager::Instance();
  //G4Element* H  = nist->FindOrBuildElement(1);
  //nicht funktioneriendes Eisen
  //G4Element* Fe  = nist->FindOrBuildElement(26);
  //G4int   ncomponents;
  //G4Material* box_mat = new G4Material("Ferrit", 7.874*g/cm3, ncomponents=26, kStateGas, CLHEP::STP_Temperature, CLHEP::STP_Pressure);
  //box_mat->AddElement(Fe, 1); //nicht benötigt?

  //Funktionierendes Blei
  //G4Element* Pb = nist->FindOrBuildElement(82);
  //G4Material* box_mat = new G4Material("Lead", 2.336*g/cm3, 1);
  //box_mat->AddElement(Pb, 1.0);

  //G4Material* box_mat = new G4Material("Ar", 100*g/cm3, 1);
  //box_mat->AddElement(Ar, 1.0);

  // G4Material* box_mat = new G4Material("gERMAN", 5.323*g/cm3, 1);
  // box_mat->AddElement(Ge, 1.0);

  //G4Material* box_mat = new G4Material("Ferrit", 7.874*g/cm3, 1);
  //box_mat->AddElement(Fe, 1.0);

  //G4Material* box_mat = new G4Material("Irridium", 4.93*g/cm3, 1);
  //box_mat->AddElement(I, 1.0);


  //G4Element* Li = nist->FindOrBuildElement(3);
  //G4Material* box_mat = new G4Material("Lithium", 0.534*g/cm3, 1);
  //box_mat->AddElement(Li, 1.0);

    //G4Element* Na = nist->FindOrBuildElement(11);
    //G4Material* box_mat = new G4Material("Natrium", 0.971*g/cm3, 1);
    //box_mat->AddElement(Na, 1.0);

//Uran!
//  G4int iz, n;                       //iz=number of protons  in an isotope; n=number of nucleons in an isotope;
//   G4int   ncomponents;
//   G4double abundance;
//
// //  G4Isotope* U5 = new G4Isotope("U235", iz=92, n=235, 235.01*g/mole);
// //  G4Isotope* U8 = new G4Isotope("U238", iz=92, n=238, 238.03*g/mole);
// //  G4Element* U  = new G4Element("enriched Uranium", "U", ncomponents=2);
// //  G4Material* box_mat = new G4Material("Uran", 15*g/cm3, 1);
// //  U->AddIsotope(U5, abundance= 90.*perCent);
// //  U->AddIsotope(U8, abundance= 10.*perCent);
// //  box_mat->AddElement(U, 1.0);
//
// // AR CO2
// G4Material* CO2 = new G4Material("CarbonicGas", 27.*mg/cm3, ncomponents=2, kStateGas, CLHEP::STP_Temperature, CLHEP::STP_Pressure);
// CO2->AddElement(C, 1);
// CO2->AddElement(O, 2);
// //G4Material* box_mat = CO2;
// G4Material* Argon = nist->ConstructNewGasMaterial("STD_Argon", "G4_Ar", CLHEP::STP_Temperature, CLHEP::STP_Pressure);
//
// G4Material* ArCO2 = new G4Material("Ar_CO2", 1.69*mg/cm3, ncomponents=2, kStateGas, CLHEP::STP_Temperature, CLHEP::STP_Pressure);
// ArCO2->AddMaterial(CO2, abundance=10.*perCent);
// ArCO2->AddMaterial(Argon, abundance=90.*perCent);
// G4Material* box_mat = ArCO2;

// Checking forthe Z
// liquid argon with z = 18
  //G4double density = 1.390*g/cm3;
  // G4double a = 100*g/mole;
  // G4double z = 30.;
  // G4Material* box_mat = new G4Material("something", z, a,density);

//Temp
  G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Argon", "G4_Ar", CLHEP::STP_Temperature, 0.9*bar);

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
