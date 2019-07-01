# AGD Geant 4

Toy tool to play around with Geant4. 

The goal is to simulate the passage of a charged particle through gas.
A mini-setup is used: 
A rectangluar box filled with gas.
The particle is chosen to be a muon.

## Build

First, you need a running Geant4 installation. 
See the [installation guide][inst] for details.
I'll assume you put it to ${HOME}/Geant4; 
If not, change the paths accordingly.

Clone this project. 

In the *build* directory, execute
```bash
cmake -DGeant4_DIR=${HOME}/Geant4/install/lib64/Geant4-10.5.0 ../
make -j6
``` 
To run it, use `./exampleB1 ../run_macro.mac` for macro mode, or `./exampleB1` for GUI mode.


[inst]: http://fsketzer.cb.uni-bonn.de/gitlab/compass/beginners_guide/blob/master/installation_guide_tgeant_coral_phast.md#geant-41002p02 "Gitlab: Compass beginners guide"
