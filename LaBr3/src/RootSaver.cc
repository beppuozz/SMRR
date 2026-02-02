#include "RootSaver.hh"
#include "LaBr3Hit.hh"
#include "TMath.hh"
#include <sstream>
#include <iostream>
#include <cassert>

RootSaver::RootSaver()
    :rootFile(0),
    rootTree(0),
    runCounter(0),
    Tot_Tracks(0)
    {
    
    Part_ID = new Int_t[10000]; //brutal way to initialize the vector saying the entries will be less than 1000
    MothPart_ID = new Int_t[10000];

    Part_Type = new Int_t[10000];
    MothPart_Type = new Int_t[10000];

    Part_EnDep = new Float_t[10000];
    MothPart_EnDep = new Float_t[10000];

    Part_zStart = new Float_t[10000];
    MothPart_zStart = new Float_t[10000];

    Part_tStart = new Float_t[10000];
    MothPart_tStart = new Float_t[10000];
}

RootSaver::~RootSaver() {

    if(rootTree) CloseTree(); //Close the file if it's still open before the destructor
}

void RootSaver::CreateTree(const std::string& fileName, const std::string& treeName){

    if(rootTree) { //Check if the file I want to create was already created
        std::cerr << "TTree already created, first call CloseTree" << std::endl;
        return;
    }

    std::ostringstream fn; //creating a string
    fn << fileName << "_run" << runCounter++ <<".root"; //string structure: "[fileName]_runX.root"
    
    rootFile = TFile::Open(fn.str().data(), "recreate");
    if(rootFile == 0 || rootFile->IsZombie()) { //Check to see if the file.root doesn't exist or is corrupted
        G4cerr << "Error opening the file: " << fn.str() << " TTree will not be saved" << G4endl;
        return;
    }
    else {
        G4cout << "rootFile correctly opened, Name " << rootFile->GetName() << G4endl;
        rootTree = new TTree(treeName.data(), treeName.data());

        //-------------Define Branches for the TTree----------------
        rootTree->Branch("ntracks", &Tot_Tracks, "ntracks/I2"); //NON HO CAPITO
        rootTree->Branch("id", Part_ID, "id[ntracks]/I2"); //LO DICE PURE LUI CHE E' MAGIA
        rootTree->Branch("mum", MothPart_ID, "mum[ntracks]/I2");

        rootTree->Branch("type", Part_Type, "type[ntracks]/I"); //I and not I2 because I need only 1 byte
        rootTree->Branch("mum_type", MothPart_Type, "mum_type[ntracks]/I");

        rootTree->Branch("edep", Part_EnDep, "edep[ntracks]/F");
    }

}