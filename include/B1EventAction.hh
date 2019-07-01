#ifndef B1EventAction_h
#define B1EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class B1RunAction;


class B1EventAction : public G4UserEventAction
{
  public:
    B1EventAction(B1RunAction* runAction);
    virtual ~B1EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    // called in B1SteppingAction::UserSteppingAction to add 
    // step->GetTotalEnergyDeposit() each time
    void AddEdep(G4double edep) { fEdep += edep; }
    
    void SetEntryEnergy(G4double E) { fEntryEnergy = E; }
    void SetExitEnergy(G4double E)  { fExitEnergy  = E; }

  private:
    B1RunAction* fRunAction;
    G4double     fEdep;
    G4double     fEntryEnergy; 
    G4double     fExitEnergy;
};

#endif

    
