#ifndef B1SteppingAction_h
#define B1SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include "g4root.hh"

class B1EventAction;

class G4LogicalVolume;

/// The run manager calles this class for every step of the simulation. Note 
/// that the ordering is not necessarily straight-forward, as particles that
/// were shot off might be simulated first.
/// 
/// N.b.: The last step will likely _end_ outside the defined geometry. 

class B1SteppingAction : public G4UserSteppingAction
{
  public:
    B1SteppingAction(B1EventAction* eventAction);
    virtual ~B1SteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    B1EventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
};

#endif
