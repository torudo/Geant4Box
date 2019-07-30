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
  G4Element* He  = nist->FindOrBuildElement(2);
  G4Element* Li  = nist->FindOrBuildElement(3);
  G4Element* Be  = nist->FindOrBuildElement(4);
  G4Element* B = nist->FindOrBuildElement(5);
  G4Element* C  = nist->FindOrBuildElement(6);
  G4Element* N  = nist->FindOrBuildElement(7);
  G4Element* O  = nist->FindOrBuildElement(8);
  G4Element* F = nist->FindOrBuildElement(9);
  G4Element* Ne = nist->FindOrBuildElement(10);
  G4Element* Na = nist->FindOrBuildElement(11);
  G4Element* Mg = nist->FindOrBuildElement(12);
  G4Element* Al = nist->FindOrBuildElement(13);
  G4Element* Si = nist->FindOrBuildElement(14);
  G4Element* P  = nist->FindOrBuildElement(15);
  G4Element* S  = nist->FindOrBuildElement(16);
  G4Element* Cl  = nist->FindOrBuildElement(17);
  G4Element* Ar  = nist->FindOrBuildElement(18);
  G4Element* K  = nist->FindOrBuildElement(19);
  G4Element* Ca = nist->FindOrBuildElement(20);
  G4Element* Sc = nist->FindOrBuildElement(21);
  G4Element* Ti = nist->FindOrBuildElement(22);
  G4Element* V = nist->FindOrBuildElement(23);
  G4Element* Cr  = nist->FindOrBuildElement(24);
  G4Element* Mn = nist->FindOrBuildElement(25);
  G4Element* Fe = nist->FindOrBuildElement(26);
  G4Element* Co  = nist->FindOrBuildElement(27);
  G4Element* Ni  = nist->FindOrBuildElement(28);
  G4Element* Cu  = nist->FindOrBuildElement(29);
  G4Element* Zn  = nist->FindOrBuildElement(30);
  G4Element* Ga  = nist->FindOrBuildElement(31);
  G4Element* Ge = nist->FindOrBuildElement(32);
  G4Element* As = nist->FindOrBuildElement(33);
  G4Element* Se = nist->FindOrBuildElement(34);
  G4Element* Br = nist->FindOrBuildElement(35);
  G4Element* Kr = nist->FindOrBuildElement(36);
  G4Element* Rb  = nist->FindOrBuildElement(37);
  G4Element* Sr  = nist->FindOrBuildElement(38);
  G4Element* Y = nist->FindOrBuildElement(39);
  G4Element* Zr = nist->FindOrBuildElement(40);
  G4Element* Nb = nist->FindOrBuildElement(41);
  G4Element* Mo  = nist->FindOrBuildElement(42);
  G4Element* Tc  = nist->FindOrBuildElement(43);
  G4Element* Ru  = nist->FindOrBuildElement(44);
  G4Element* Rh = nist->FindOrBuildElement(45);
  G4Element* Pd = nist->FindOrBuildElement(46);
  G4Element* Ag = nist->FindOrBuildElement(47);
  G4Element* Cd = nist->FindOrBuildElement(48);
  G4Element* In = nist->FindOrBuildElement(49);
  G4Element* Sn  = nist->FindOrBuildElement(50);
  G4Element* Sb = nist->FindOrBuildElement(51);
  G4Element* Te = nist->FindOrBuildElement(52);
  G4Element* I = nist->FindOrBuildElement(53);
  G4Element* Xe  = nist->FindOrBuildElement(54);
  G4Element* Cs  = nist->FindOrBuildElement(55);
  G4Element* Ba  = nist->FindOrBuildElement(56);
  G4Element* La  = nist->FindOrBuildElement(57);
  G4Element* Ce = nist->FindOrBuildElement(58);
  G4Element* Pr = nist->FindOrBuildElement(59);
  G4Element* Nd = nist->FindOrBuildElement(60);
  G4Element* Pm = nist->FindOrBuildElement(61);
  G4Element* Sm = nist->FindOrBuildElement(62);
  G4Element* Eu = nist->FindOrBuildElement(63);
  G4Element* Gd = nist->FindOrBuildElement(64);
  G4Element* Tb = nist->FindOrBuildElement(65);
  G4Element* Dy = nist->FindOrBuildElement(66);
  G4Element* Ho  = nist->FindOrBuildElement(67);
  G4Element* Er  = nist->FindOrBuildElement(68);
  G4Element* Tm  = nist->FindOrBuildElement(69);
  G4Element* Yb = nist->FindOrBuildElement(70);
  G4Element* Lu = nist->FindOrBuildElement(71);
  G4Element* Hf = nist->FindOrBuildElement(72);
  G4Element* Ta = nist->FindOrBuildElement(73);
  G4Element* W = nist->FindOrBuildElement(74);
  G4Element* Re  = nist->FindOrBuildElement(75);
  G4Element* Os = nist->FindOrBuildElement(76);
  G4Element* Ir = nist->FindOrBuildElement(77);
  G4Element* Pt = nist->FindOrBuildElement(78);
  G4Element* Au  = nist->FindOrBuildElement(79);
  G4Element* Hg = nist->FindOrBuildElement(80);
  G4Element* Tl  = nist->FindOrBuildElement(81);
  G4Element* Pb  = nist->FindOrBuildElement(82);
  G4Element* Bi = nist->FindOrBuildElement(83);
  G4Element* Po = nist->FindOrBuildElement(84);
  G4Element* At = nist->FindOrBuildElement(85);
  G4Element* Rn = nist->FindOrBuildElement(86);
  G4Element* Fr  = nist->FindOrBuildElement(87);
  G4Element* Ra  = nist->FindOrBuildElement(88);
  G4Element* Ac = nist->FindOrBuildElement(89);
  G4Element* Th = nist->FindOrBuildElement(90);
  G4Element* Pa = nist->FindOrBuildElement(91);
  G4Element* U = nist->FindOrBuildElement(92);
  G4Element* Np = nist->FindOrBuildElement(93);
  G4Element* Pu = nist->FindOrBuildElement(94);
  G4Element* Am  = nist->FindOrBuildElement(95);
  G4Element* Cm  = nist->FindOrBuildElement(96);
  G4Element* Bk = nist->FindOrBuildElement(97);
  G4Element* Cf = nist->FindOrBuildElement(98);
 

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

//  G4Material* box_mat = new G4Material("waterstoff", 8.3748e-05*g/cm3, 1);
//  box_mat->AddElement(H, 1.0);

//  G4Material* box_mat = new G4Material("Helium", 0.000166322*g/cm3, 1);
//  box_mat->AddElement(He, 1.0);  

//  G4Material* box_mat = new G4Material("Lithium", 0.534*g/cm3, 1);
//  box_mat->AddElement(Li, 1.0);

//  G4Material* box_mat = new G4Material("Berilium", 1.848*g/cm3, 1);
//  box_mat->AddElement(Be, 1.0);

// Das muss noch
//  G4Material* box_mat = new G4Material("B", 2.37*g/cm3, 1);
//  box_mat->AddElement(B, 1.0);

//  G4Material* box_mat = new G4Material("Kohlenstoff", 2*g/cm3, 1);
//  box_mat->AddElement(C, 1.0);

//  G4Material* box_mat = new G4Material("Stickstoff", 0.0011652*g/cm3, 1);
//  box_mat->AddElement(N, 1.0);

//  G4Material* box_mat = new G4Material("Sauerstoff", 0.00133151*g/cm3, 1);
//  box_mat->AddElement(O, 1.0);

//  G4Material* box_mat = new G4Material("Neon", 0.000838505*g/cm3, 1);
//  box_mat->AddElement(Ne, 1.0);

//  G4Material* box_mat = new G4Material("Natrium", 0.971*g/cm3, 1);
//  box_mat->AddElement(Na, 1.0);

//  G4Material* box_mat = new G4Material("Magnesium", 1.74*g/cm3, 1);
//  box_mat->AddElement(Mg, 1.0);

  G4Material* box_mat = new G4Material("Aluminium", 2.699*g/cm3, 1);
  box_mat->AddElement(Al, 1.0);

//  G4Material* box_mat = new G4Material("Sil", 2.33*g/cm3, 1);
//  box_mat->AddElement(Si, 1.0);

//  G4Material* box_mat = new G4Material("P", 2.2*g/cm3, 1);
//  box_mat->AddElement(P, 1.0);

//  G4Material* box_mat = new G4Material("Schwe", 2*g/cm3, 1);
//  box_mat->AddElement(S, 1.0);

//  G4Material* box_mat = new G4Material("Cl", 0.00299473*g/cm3, 1);
//  box_mat->AddElement(Cl, 1.0);

//  G4Material* box_mat = new G4Material("Ar", 0.00166201*g/cm3, 1);
//  box_mat->AddElement(Ar, 1.0);

//  G4Material* box_mat = new G4Material("K", 0.862*g/cm3, 1);
//  box_mat->AddElement(K, 1.0);

/////////////////////

//  G4Material* box_mat = new G4Material("H ", 8.3748e-05*g/cm3, 1); 
 //  box_mat->AddElement(H, 1.0);
//  G4Material* box_mat = new G4Material("He ", 0.000166322*g/cm3, 1); 
 //  box_mat->AddElement(He, 1.0);
//  G4Material* box_mat = new G4Material("Li ", 0.534*g/cm3, 1); 
 //  box_mat->AddElement(Li, 1.0);
//  G4Material* box_mat = new G4Material("Be ", 1.848*g/cm3, 1); 
 //  box_mat->AddElement(Be, 1.0);
//  G4Material* box_mat = new G4Material("B ", 2.37*g/cm3, 1); 
 //  box_mat->AddElement(B, 1.0);
//  G4Material* box_mat = new G4Material("C ", 2*g/cm3, 1); 
 //  box_mat->AddElement(C, 1.0);
//  G4Material* box_mat = new G4Material("N ", 0.0011652*g/cm3, 1); 
 //  box_mat->AddElement(N, 1.0);
//  G4Material* box_mat = new G4Material("O ", 0.00133151*g/cm3, 1); 
 //  box_mat->AddElement(O, 1.0);
//  G4Material* box_mat = new G4Material("F ", 0.00158029*g/cm3, 1); 
 //  box_mat->AddElement(F, 1.0);
//  G4Material* box_mat = new G4Material("Ne ", 0.000838505*g/cm3, 1); 
 //  box_mat->AddElement(Ne, 1.0);
//  G4Material* box_mat = new G4Material("Na ", 0.971*g/cm3, 1); 
 //  box_mat->AddElement(Na, 1.0);
//  G4Material* box_mat = new G4Material("Mg ", 1.74*g/cm3, 1); 
 //  box_mat->AddElement(Mg, 1.0);
//  G4Material* box_mat = new G4Material("Al ", 2.699*g/cm3, 1); 
 //  box_mat->AddElement(Al, 1.0);
//  G4Material* box_mat = new G4Material("Si ", 2.33*g/cm3, 1); 
 //  box_mat->AddElement(Si, 1.0);
//  G4Material* box_mat = new G4Material("P ", 2.2*g/cm3, 1); 
 //  box_mat->AddElement(P, 1.0);
//  G4Material* box_mat = new G4Material("S ", 2*g/cm3, 1); 
 //  box_mat->AddElement(S, 1.0);
//  G4Material* box_mat = new G4Material("Cl ", 0.00299473*g/cm3, 1); 
 //  box_mat->AddElement(Cl, 1.0);
//  G4Material* box_mat = new G4Material("Ar ", 0.00166201*g/cm3, 1); 
 //  box_mat->AddElement(Ar, 1.0);
//  G4Material* box_mat = new G4Material("K ", 0.862*g/cm3, 1); 
 //  box_mat->AddElement(K, 1.0);
//  G4Material* box_mat = new G4Material("Ca ", 1.55*g/cm3, 1); 
 //  box_mat->AddElement(Ca, 1.0);
//  G4Material* box_mat = new G4Material("Sc ", 2.989*g/cm3, 1); 
 //  box_mat->AddElement(Sc, 1.0);
//  G4Material* box_mat = new G4Material("Ti ", 4.54*g/cm3, 1); 
 //  box_mat->AddElement(Ti, 1.0);
//  G4Material* box_mat = new G4Material("V ", 6.11*g/cm3, 1); 
 //  box_mat->AddElement(V, 1.0);
//  G4Material* box_mat = new G4Material("Cr ", 7.18*g/cm3, 1); 
 //  box_mat->AddElement(Cr, 1.0);
//  G4Material* box_mat = new G4Material("Mn ", 7.44*g/cm3, 1); 
 //  box_mat->AddElement(Mn, 1.0);
//  G4Material* box_mat = new G4Material("Fe ", 7.874*g/cm3, 1); 
 //  box_mat->AddElement(Fe, 1.0);
//  G4Material* box_mat = new G4Material("Co ", 8.9*g/cm3, 1); 
 //  box_mat->AddElement(Co, 1.0);
//  G4Material* box_mat = new G4Material("Ni ", 8.902*g/cm3, 1); 
 //  box_mat->AddElement(Ni, 1.0);
//  G4Material* box_mat = new G4Material("Cu ", 8.96*g/cm3, 1); 
 //  box_mat->AddElement(Cu, 1.0);
//  G4Material* box_mat = new G4Material("Zn ", 7.133*g/cm3, 1); 
 //  box_mat->AddElement(Zn, 1.0);
//  G4Material* box_mat = new G4Material("Ga ", 5.904*g/cm3, 1); 
 //  box_mat->AddElement(Ga, 1.0);
//  G4Material* box_mat = new G4Material("Ge ", 5.323*g/cm3, 1); 
 //  box_mat->AddElement(Ge, 1.0);
//  G4Material* box_mat = new G4Material("As ", 5.73*g/cm3, 1); 
 //  box_mat->AddElement(As, 1.0);
//  G4Material* box_mat = new G4Material("Se ", 4.5*g/cm3, 1); 
 //  box_mat->AddElement(Se, 1.0);
//  G4Material* box_mat = new G4Material("Br ", 0.0070721*g/cm3, 1); 
 //  box_mat->AddElement(Br, 1.0);
//  G4Material* box_mat = new G4Material("Kr ", 0.00347832*g/cm3, 1); 
 //  box_mat->AddElement(Kr, 1.0);
//  G4Material* box_mat = new G4Material("Rb ", 1.532*g/cm3, 1); 
 //  box_mat->AddElement(Rb, 1.0);
//  G4Material* box_mat = new G4Material("Sr ", 2.54*g/cm3, 1); 
 //  box_mat->AddElement(Sr, 1.0);
//  G4Material* box_mat = new G4Material("Y ", 4.469*g/cm3, 1); 
 //  box_mat->AddElement(Y, 1.0);
//  G4Material* box_mat = new G4Material("Zr ", 6.506*g/cm3, 1); 
 //  box_mat->AddElement(Zr, 1.0);
//  G4Material* box_mat = new G4Material("Nb ", 8.57*g/cm3, 1); 
 //  box_mat->AddElement(Nb, 1.0);
//  G4Material* box_mat = new G4Material("Mo ", 10.22*g/cm3, 1); 
 //  box_mat->AddElement(Mo, 1.0);
//  G4Material* box_mat = new G4Material("Tc ", 11.5*g/cm3, 1); 
 //  box_mat->AddElement(Tc, 1.0);
//  G4Material* box_mat = new G4Material("Ru ", 12.41*g/cm3, 1); 
 //  box_mat->AddElement(Ru, 1.0);
//  G4Material* box_mat = new G4Material("Rh ", 12.41*g/cm3, 1); 
 //  box_mat->AddElement(Rh, 1.0);
//  G4Material* box_mat = new G4Material("Pd ", 12.02*g/cm3, 1); 
 //  box_mat->AddElement(Pd, 1.0);
//  G4Material* box_mat = new G4Material("Ag ", 10.5*g/cm3, 1); 
 //  box_mat->AddElement(Ag, 1.0);
//  G4Material* box_mat = new G4Material("Cd ", 8.65*g/cm3, 1); 
 //  box_mat->AddElement(Cd, 1.0);
//  G4Material* box_mat = new G4Material("In ", 7.31*g/cm3, 1); 
 //  box_mat->AddElement(In, 1.0);
//  G4Material* box_mat = new G4Material("Sn ", 7.31*g/cm3, 1); 
 //  box_mat->AddElement(Sn, 1.0);
//  G4Material* box_mat = new G4Material("Sb ", 6.691*g/cm3, 1); 
 //  box_mat->AddElement(Sb, 1.0);
//  G4Material* box_mat = new G4Material("Te ", 6.24*g/cm3, 1); 
 //  box_mat->AddElement(Te, 1.0);
//  G4Material* box_mat = new G4Material("I ", 4.93*g/cm3, 1); 
 //  box_mat->AddElement(I, 1.0);
//  G4Material* box_mat = new G4Material("Xe ", 0.00548536*g/cm3, 1); 
 //  box_mat->AddElement(Xe, 1.0);
//  G4Material* box_mat = new G4Material("Cs ", 1.873*g/cm3, 1); 
 //  box_mat->AddElement(Cs, 1.0);
//  G4Material* box_mat = new G4Material("Ba ", 3.5*g/cm3, 1); 
 //  box_mat->AddElement(Ba, 1.0);
//  G4Material* box_mat = new G4Material("La ", 6.154*g/cm3, 1); 
 //  box_mat->AddElement(La, 1.0);
//  G4Material* box_mat = new G4Material("Ce ", 6.657*g/cm3, 1); 
 //  box_mat->AddElement(Ce, 1.0);
//  G4Material* box_mat = new G4Material("Pr ", 6.71*g/cm3, 1); 
 //  box_mat->AddElement(Pr, 1.0);
//  G4Material* box_mat = new G4Material("Nd ", 6.9*g/cm3, 1); 
 //  box_mat->AddElement(Nd, 1.0);
//  G4Material* box_mat = new G4Material("Pm ", 7.22*g/cm3, 1); 
 //  box_mat->AddElement(Pm, 1.0);
//  G4Material* box_mat = new G4Material("Sm ", 7.46*g/cm3, 1); 
 //  box_mat->AddElement(Sm, 1.0);
//  G4Material* box_mat = new G4Material("Eu ", 5.243*g/cm3, 1); 
 //  box_mat->AddElement(Eu, 1.0);
//  G4Material* box_mat = new G4Material("Gd ", 7.9004*g/cm3, 1); 
 //  box_mat->AddElement(Gd, 1.0);
//  G4Material* box_mat = new G4Material("Tb ", 8.229*g/cm3, 1); 
 //  box_mat->AddElement(Tb, 1.0);
//  G4Material* box_mat = new G4Material("Dy ", 8.55*g/cm3, 1); 
 //  box_mat->AddElement(Dy, 1.0);
//  G4Material* box_mat = new G4Material("Ho ", 8.795*g/cm3, 1); 
 //  box_mat->AddElement(Ho, 1.0);
//  G4Material* box_mat = new G4Material("Er ", 9.066*g/cm3, 1); 
 //  box_mat->AddElement(Er, 1.0);
//  G4Material* box_mat = new G4Material("Tm ", 9.321*g/cm3, 1); 
 //  box_mat->AddElement(Tm, 1.0);
//  G4Material* box_mat = new G4Material("Yb ", 6.73*g/cm3, 1); 
 //  box_mat->AddElement(Yb, 1.0);
//  G4Material* box_mat = new G4Material("Lu ", 9.84*g/cm3, 1); 
 //  box_mat->AddElement(Lu, 1.0);
//  G4Material* box_mat = new G4Material("Hf ", 13.31*g/cm3, 1); 
 //  box_mat->AddElement(Hf, 1.0);
//  G4Material* box_mat = new G4Material("Ta ", 16.654*g/cm3, 1); 
 //  box_mat->AddElement(Ta, 1.0);
//  G4Material* box_mat = new G4Material("W ", 19.3*g/cm3, 1); 
 //  box_mat->AddElement(W, 1.0);
//  G4Material* box_mat = new G4Material("Re ", 21.02*g/cm3, 1); 
 //  box_mat->AddElement(Re, 1.0);
//  G4Material* box_mat = new G4Material("Os ", 22.57*g/cm3, 1); 
 //  box_mat->AddElement(Os, 1.0);
//  G4Material* box_mat = new G4Material("Ir ", 22.42*g/cm3, 1); 
 //  box_mat->AddElement(Ir, 1.0);
//  G4Material* box_mat = new G4Material("Pt ", 21.45*g/cm3, 1); 
 //  box_mat->AddElement(Pt, 1.0);
//  G4Material* box_mat = new G4Material("Au ", 19.32*g/cm3, 1); 
 //  box_mat->AddElement(Au, 1.0);
//  G4Material* box_mat = new G4Material("Hg ", 13.546*g/cm3, 1); 
 //  box_mat->AddElement(Hg, 1.0);
//  G4Material* box_mat = new G4Material("Tl ", 11.72*g/cm3, 1); 
 //  box_mat->AddElement(Tl, 1.0);
//  G4Material* box_mat = new G4Material("Pb ", 11.35*g/cm3, 1); 
 //  box_mat->AddElement(Pb, 1.0);
//  G4Material* box_mat = new G4Material("Bi ", 9.747*g/cm3, 1); 
 //  box_mat->AddElement(Bi, 1.0);
//  G4Material* box_mat = new G4Material("Po ", 9.32*g/cm3, 1); 
 //  box_mat->AddElement(Po, 1.0);
//  G4Material* box_mat = new G4Material("At ", 9.32*g/cm3, 1); 
 //  box_mat->AddElement(At, 1.0);
//  G4Material* box_mat = new G4Material("Rn ", 0.00900662*g/cm3, 1); 
 //  box_mat->AddElement(Rn, 1.0);
//  G4Material* box_mat = new G4Material("Fr ", 1*g/cm3, 1); 
 //  box_mat->AddElement(Fr, 1.0);
//  G4Material* box_mat = new G4Material("Ra ", 5*g/cm3, 1); 
 //  box_mat->AddElement(Ra, 1.0);
//  G4Material* box_mat = new G4Material("Ac ", 10.07*g/cm3, 1); 
 //  box_mat->AddElement(Ac, 1.0);
//  G4Material* box_mat = new G4Material("Th ", 11.72*g/cm3, 1); 
 //  box_mat->AddElement(Th, 1.0);
//  G4Material* box_mat = new G4Material("Pa ", 15.37*g/cm3, 1); 
 //  box_mat->AddElement(Pa, 1.0);
//  G4Material* box_mat = new G4Material("U ", 18.95*g/cm3, 1); 
 //  box_mat->AddElement(U, 1.0);
//  G4Material* box_mat = new G4Material("Np ", 20.25*g/cm3, 1); 
 //  box_mat->AddElement(Np, 1.0);
//  G4Material* box_mat = new G4Material("Pu ", 19.84*g/cm3, 1); 
 //  box_mat->AddElement(Pu, 1.0);
//  G4Material* box_mat = new G4Material("Am ", 13.67*g/cm3, 1); 
 //  box_mat->AddElement(Am, 1.0);
//  G4Material* box_mat = new G4Material("Cm ", 13.51*g/cm3, 1); 
 //  box_mat->AddElement(Cm, 1.0);
//  G4Material* box_mat = new G4Material("Bk ", 14*g/cm3, 1); 
 //  box_mat->AddElement(Bk, 1.0);
//  G4Material* box_mat = new G4Material("Cf ", 10*g/cm3, 1); 
 //  box_mat->AddElement(Cf, 1.0);








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

//Temp and pres
  //G4Material* box_mat = nist->ConstructNewGasMaterial("STD_Argon", "G4_Ar", CLHEP::STP_Temperature, 0.9*bar);

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