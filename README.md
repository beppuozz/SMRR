# SMRR - Folder for "Simulazioni Montecarlo di Rivelatori di Radiazione" course
To run any programm use the following command line "gdb -batch -ex "run" ./test1"

### Folder Structure
TaskNmr
* TaskNmr --> prima sottocartella, contiene i file principali
    * include --> contains all .hh files
    * src     --> contains all .cc files
    * CMakeList.txt --> il programma CMake serve per fare creare l'eseguibile del programma.\
    Per dirgli come farlo serve questo file di testo, che si ottiene tramite il build.
* TaskNmr_build --> cartella necessaria per creare l'eseguibile 
\\
---
### How to build a GEANT4 programme
Follow this --> https://geant4.web.cern.ch/documentation/pipelines/master/bfad_html/ForApplicationDevelopers/GettingStarted/makeFile.html

```bash
$ mkdir example_build
$ cd example_build
$ cmake -DCMAKE_PREFIX_PATH=/home/you/geant4-install /path/to/example
$ make -j4 VERBOSE=1
```
Nel caso in cui in fase di compilazione dovesse apparire il fatal error "ENSDATA.dat not found", 
Comandi per risolvere ENSDATA.dat not found:

```bash
$ export G4ENSDFSTATEDATA=/home/ubuntu/SMRR/GEANT4/geant4_install/share/Geant4/data/G4ENSDFSTATE3.0
$ export G4PHOTONEvaporationDATA=/home/ubuntu/SMRR/GEANT4/geant4_install/share/Geant4/data/PhotonEvaporation6.1.2
$ export G4RADIOACTIVEDATA=/home/ubuntu/SMRR/GEANT4/geant4_install/share/Geant4/data/RadioactiveDecay6.1.2
$ export G4NEUTRONHPDATA=/home/ubuntu/SMRR/GEANT4/geant4_install/share/Geant4/data/G4NDL4.7.1
$ export G4SAIDXSDATA=/home/ubuntu/SMRR/GEANT4/geant4_install/share/Geant4/data/G4SAIDDATA2.0
$ export G4LEDATA=/home/ubuntu/SMRR/GEANT4/geant4_install/share/Geant4/data/G4EMLOW8.8
```
---
### LaBr3
Folder for Bromuro di Lantanio 