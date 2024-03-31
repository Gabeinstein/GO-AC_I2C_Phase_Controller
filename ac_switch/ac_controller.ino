#include "ac_controller.h"

ac_controller::ac_controller()
{
  int _pins[3] = {5,6,7};
  byte _addresses[3]  = {0x10,0x11,0x12};

  n_switches = 3;
  addresses = _addresses;
  pins = _pins;
  switches = new phase_controller[n_switches];

    for (int i=0; i<n_switches; i++){
        switches[i].setAddress(addresses[i]);
        switches[i].setPins(pins[i]);
    }

}
ac_controller::ac_controller(int _n_switches, unsigned int *_pins, byte *_addresses)
{
    n_switches = _n_switches;
    addresses = _addresses;
    pins = _pins;
    switches = new phase_controller[_n_switches];

    for (int i=0; i<n_switches; i++){
        switches[i].setAddress(addresses[i]);
        switches[i].setPins(pins[i]);
    }
}
phase_controller* ac_controller::getSwitches(){
    return switches;
}