#include "LaBr3Hit.hh"
#include "G4UnitsTable.hh"

LaBr3Hit::LaBr3Hit(G4int layer):
    layerNumber(layer), 
    edep(0)
{}

LaBr3Hit::~LaBr3Hit() {
    //G4cout << "LaBr3Hit Destructor called!" << G4endl;
}

void LaBr3Hit::Print() {
    G4double edep = this->GetEdep();
    G4int layerN = this->GetLayerNumber();
    G4cout << "HIT: Energy deposited = " << G4BestUnit(edep, "Energy") << " in layer " << layerN << G4endl;
}