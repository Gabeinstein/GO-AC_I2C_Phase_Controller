#include "ac_controller.h"

ac_controller::ac_controller()
{
  unsigned int _pins[3] = {5,6,7};
  byte _addresses[3]  = {0x11,0x12,0x13};

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
void ac_controller::updateLevel(byte toAddress, byte value){
    for (int i = 0; i<n_switches; i++){
        if(switches[i].getAddress() == toAddress){
            switches[i].setLevel(value);
            break;
        }
    }
}
void ac_controller::status(){
    Serial.println("------ Status AC Controller ------");
    Serial.println("Number of modules: " + String(n_switches));
    Serial.println("------ Raw Values ------");
    for (int i=0; i<n_switches; i++){
        Serial.print(switches[i].getAddress(),HEX);
        Serial.println(" -> " + String(switches[i].get_phase_comparator()));
    }
    Serial.println("-------------- END ---------------");
    
}
int ac_controller::getNumSwitches(){
    return n_switches;
}