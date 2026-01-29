#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithABool.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction* det)
    :detector(det),
    detDir(0)
{
    detDir = new G4UIdirectory("/det/");
    detDir->SetGuidance("Detector construction commands");

    xShiftCmd = new G4UIcmdWithADoubleAndUnit("/det/XShift", this);  //command to set the shift along X axis of the detector
    xShiftCmd->SetGuidance("Set the shift along X axis of the detector");
    xShiftCmd->SetParameterName("XShift", true); //true -> the parameter is optional
    xShiftCmd->SetDefaultValue(0.);
    xShiftCmd->SetUnitCategory("Length");
    xShiftCmd->SetDefaultUnit("mm");
    xShiftCmd->AvailableForStates(G4State_Idle);

    yShiftCmd = new G4UIcmdWithADoubleAndUnit("/det/YShift", this);  //command to set the shift along Y axis of the detector
    yShiftCmd->SetGuidance("Set the shift along Y axis of the detector");
    yShiftCmd->SetParameterName("YShift", true); 
    yShiftCmd->SetDefaultValue(0.);
    yShiftCmd->SetUnitCategory("Length");
    yShiftCmd->SetDefaultUnit("mm");
    yShiftCmd->AvailableForStates(G4State_Idle);

    zShiftCmd = new G4UIcmdWithADoubleAndUnit("/det/ZShift", this);  //command to set the shift along Z axis of the detector
    zShiftCmd->SetGuidance("Set the shift along Z axis of the detector");
    zShiftCmd->SetParameterName("ZShift", true); 
    zShiftCmd->SetDefaultValue(0.);
    zShiftCmd->SetUnitCategory("Length");
    zShiftCmd->SetDefaultUnit("mm");
    zShiftCmd->AvailableForStates(G4State_Idle);

    thetaCmd = new G4UIcmdWithADoubleAndUnit("/det/theta", this);  //command to set the rotation
    thetaCmd->SetGuidance("Set the rotation of the detector");
    thetaCmd->SetParameterName("Theta", true); 
    thetaCmd->SetDefaultValue(0.);
    thetaCmd->SetUnitCategory("Angle");
    thetaCmd->SetDefaultUnit("deg");
    thetaCmd->AvailableForStates(G4State_Idle);

    updateCmd = new G4UIcmdWithoutParameter("/det/update", this);   //command to update the geometry
    updateCmd->SetGuidance("Recompute the detector geometry, this must be applied before /run/beamOn");
    updateCmd->AvailableForStates(G4State_Idle);
}

DetectorMessenger::~DetectorMessenger() {
    delete xShiftCmd;
    delete yShiftCmd;
    delete zShiftCmd;
    delete thetaCmd;
    delete updateCmd;
    delete detDir;
}

void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue) {
    if (command == xShiftCmd) {
        G4ThreeVector pos = detector->DetPosition;
        pos.SetX(xShiftCmd->GetNewDoubleValue(newValue));
        detector->SetPosition(pos);
    }
    else if (command == yShiftCmd) {
        G4ThreeVector pos = detector->DetPosition;
        pos.SetY(yShiftCmd->GetNewDoubleValue(newValue));
        detector->SetPosition(pos);
    }
    else if (command == zShiftCmd) {
        G4ThreeVector pos = detector->DetPosition;
        pos.SetZ(zShiftCmd->GetNewDoubleValue(newValue));
        detector->SetPosition(pos);
    }
    else if (command == thetaCmd) {
        G4double angle = detector->DetAngle;
        detector->SetAngle(angle);
    }
    else if (command == updateCmd) {
        detector->UpdateGeometry();
    }    
        
}