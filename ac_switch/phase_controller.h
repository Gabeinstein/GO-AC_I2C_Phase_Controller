#ifndef PHASE_CONTROLLER_H
#define PHASE_CONTROLLER_H

#include "ac_controller.h"

class phase_controller:private ac_controller
{
private:
    byte address;  // MSB indica el numero de modulo. Modulo 0 reservado para ESP. LSB indica el submodulo.
    byte phase_raw;
    int digital_pin;
public:
    //Constructores
    phase_controller(int);
    phase_controller();
    phase_controller(int,byte);
    
};

phase_controller::phase_controller(int _digital_pin)
{
    digital_pin = _digital_pin;
    address = 0x10;
    phase_raw = 0;
}
phase_controller::phase_controller()
{
    digital_pin = 3;
    address = 0x10;
    phase_raw = 0;
}

phase_controller::phase_controller(int _digital_pin, byte _address)
{
    digital_pin = _digital_pin;
    address = _address;
    phase_raw = 0;
}


#endif