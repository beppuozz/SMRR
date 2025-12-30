// Deve avere lo stesso nome del file .hh

/*================================================== INCLUDES ==================================================*/
#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "G4Material.hh"               //per definire i materiali
#include "G4Box.hh"                    //per costruire volumi a forma di scatola
#include "G4Tubs.hh"                   //per costruire volumi a forma di cilindro
#include "G4LogicalVolume.hh"          //per definire i volumi logici
#include "G4PVPlacement.hh"            //per posizionare i volumi fisici
#include "G4GeometryTolerance.hh"      //per la tolleranza geometrica
#include "G4GeometryManager.hh"        //per gestire la geometria
#include "G4NistManager.hh"            //per accedere ai materiali definiti da NIST
#include "G4VisAttributes.hh"          //per definire gli attributi di visualizzazione
#include "G4Colour.hh"                 //per definire i colori

/*
#include "G4SensitiveDetector.hh"   //per i rivelatori sensibili
#include "G4SDManager.hh"          //per gestire i rivelatori sensibili
*/

/*================================================== CONSTRUCTOR ==================================================*/
DetectorConstruction::DetectorConstruction(): 
    vacuum(0), //inizializzo i puntatori a 0
    LaBr3_Mat(0),
    logicWorld(0),
    halfWorldLength(0.5*Km), //inizializzo la metà della dimensione del mondo a 0.5 km
    {
    
    }