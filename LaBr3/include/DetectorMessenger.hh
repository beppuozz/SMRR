//Header file, definisco tutti i membri e metodi che implementerò nel file .cc
/*================================================== INCLUDES ==================================================*/

#include "G4UImessenger.hh"
#include "globals.hh"
#include "DetectorConstruction.hh"  //target class

/*================================================== CLASSES ==================================================*/
class G4UIDirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithoutParameter;
class G4UIcmdWithABool;

//This class provides interface to DetecotrConstruction 

class DetectorMessenger: public G4UImessenger {
    public:
        DetectorMessenger(DetectorConstruction*);   //constructor
        ~DetectorMessenger();                     //destructor

    //Handle user commands
        void SetNewValue(G4UIcommand*, G4String);
    
    private:
        DetectorConstruction* detector; //pointer to DetectorConstruction class
        G4UIDirectory* detDir;        //directory for detector commands
        G4UIcmdWithADoubleAndUnit* xShiftCmd; 
        G4UIcmdWithADoubleAndUnit* yShiftCmd; 
        G4UIcmdWithADoubleAndUnit* zShiftCmd; //pointers to shift command
        G4UIcmdWithADoubleAndUnit* thetaCmd; //pointer to rotation command
        G4UIcmdWithoutParameter* updateCmd; //pointer to update command 
}