#include <string>
#include "TTree.h"
#include "TFile.h"
#include "G4UnitsTable.hh"
#include "LaBr3Hit.hh"
#include "TrackParticle.hh"
#include "EventAction.hh"
#include "TrackParentParticle.hh"
#include "G4Types.hh"

class RootSaver {
    public:
        RootSaver ();   //Constructor
        ~RootSaver ();  //Destructor

        typedef std::map<G4int, TrackParticle*> trackMap_t;

        void CreateTree(const std::string& filename ="tree", const std::string& Treename="LaBr3_Tree"); 
        void CloseTree();
        void AddEvent(trackMap_t tMap, G4int evID);

    private:

        TFile* rootFile;
        TTree* rootTree;
        unsigned int runCounter; //run counter to uniquely associate TFile with a Run

        //-----------------TTree Variables-------------------
        Int_t Tot_Tracks; //Int_t, Double_t and others are root types
        Int_t* Part_ID;
        Int_t* MothPart_ID;

        Int_t* Part_Type;
        Int_t* MothPart_Type;

        Float_t* Part_EnDep;
        Float_t* MothPart_EnDep;

        Float_t* Part_zStart;
        Float_t* MothPart_zStart;

        Float_t* Part_tStart;
        Float_t* MothPart_tStart;

        Int_t Event_ID;

        typedef std::map<G4int, TrackParentParticle> trackParentMap_t
        TrackParentMap_t GetParentProperties(trackMap_t TParticleMap);

}