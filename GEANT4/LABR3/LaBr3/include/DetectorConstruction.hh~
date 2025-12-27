// $Id: DetectorConstruction.hh Geometry to study np production from polyethylene gcroci$
#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

/**
 * @file
 * @brief Defines mandatory user class DetectorConstruction.
 */

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
class DetectorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/*!
\brief This mandatory user class defines the geometry.

It is responsible for
 - Definition of material, and
 - Construction of geometry

\sa Construct()
 */
class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  //! Constructor
  DetectorConstruction();
  //! Destructor
  ~DetectorConstruction();
public:
  //! Construct geometry of the setup
  G4VPhysicalVolume* Construct();

  //! Update geometry
  void UpdateGeometry();
  
private:
  //! define needed materials
  void DefineMaterials();
  //! initialize geometry parameters
  void ComputeParameters();
  //! Construct the full geometry of the LaBr3 detector
   
  G4VPhysicalVolume* Construct_LaBr3Detector();
  
  

  
  

private:

  //! \name Materials
  //@{

  G4Material* vacuum;
  G4Material* LaBr3_Mat;
  


  //@}

  //! \name Geometry
  //@{

  ////DECLARE LOGICAL VOLUMES!!!!

  //! global mother volume
  G4LogicalVolume * logicWorld;

  //! LaBr3 Logical volume 
  G4LogicalVolume * logicLaBr3;

   
  ///DECLARE PHYSICAL VOLUMES

  //!!Beam Dump physical volume 
  G4VPhysicalVolume* physiLaBr3;
  
  
  //@{

  //DECLARE GEOMETRICAL PARAMETERS
  
  // ** World **
  G4double halfWorldLength;
  
 

  // ** LaBr3 Detector **

  G4double halfLaBr3Det_x;
  G4double halfLaBr3Det_y;
  G4double halfLaBr3Det_z;

  
  //@}

  //! \name UI Messenger 
  //@{
  DetectorMessenger * messenger;
  //@}
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
