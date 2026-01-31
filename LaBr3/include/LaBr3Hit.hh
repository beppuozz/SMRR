#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
//root libraries
#include "TFile.h"
#include "TH1F.hh"

class LaBr3Hit : public G4VHit {
    public:
        LaBr3Hit(const G4int layer); //Constructor
        ~LaBr3Hit(); //Destructor

        //METHODS for my specific hit interface
        void Print(); //Print hit on a screen
        void AddEdep(const G4double edep) {return edep +=e;}; //Add energy deposition to the hit
        G4double GetEdep() const {return edep;}; //Get energy deposition
        G4int GetLayerNumber() {return layerNumber;}

    private:
        G4int layerNumber; //Layer number
        G4double edep; //Energy deposition
        
        //OVERLOAD of operators
        inline void* operator_new(size_t); 
        inline void operator_delete(void* aHit);

}

//Define the hit collection using the G4THitsCollection template class
typedef G4THitsCollection<LaBr3Hit> LaBr3HitCollection;

// -- new and delete overloaded operators --
extern G4Allocator<LaBr3Hit> LaBr3HitAllocator; //Allocate the appropriate memory for the hits

inline void* LaBr3Hit::operator new(size_t) {
    void* aHit;
    aHit = (void*)LaBr3HitAllocator.MallocSingle();
    return aHit;
}

inline void LaBr3Hit::operator delete(void* aHit) {
    LaBr3HitAllocator.FreeSingle((LaBr3Hit*) aHit);
}