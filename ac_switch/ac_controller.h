#ifndef AC_CONTROLLER_H
#define AC_CONTROLLER_H

#include "phase_controller.h"

class ac_controller
{
private:
    phase_controller *switches;
    unsigned int *pins;
    byte *addresses; 
    int n_switches;

public:
    ac_controller(int, unsigned int*, byte*);
    ac_controller();
    phase_controller* getSwitches();
    void updateLevel(byte, byte);
    void status();
};



#endif