#ifndef PHASE_CONTROLLER_H
#define PHASE_CONTROLLER_H

class phase_controller
{
private:
    byte address;  // MSB indica el numero de modulo. Modulo 0 reservado para ESP. LSB indica el submodulo.
    unsigned int phase_comparator;
    byte level_raw;
    int digital_pin;
public:
    //Constructores
    phase_controller(int);
    phase_controller();
    phase_controller(int,byte);
    //Functions
    void setAddress(byte);
    void setPins(int);
    void setLevel(byte);
    byte getRawValue();
    unsigned int get_phase_comparator();
    byte getAddress();    
};


#endif