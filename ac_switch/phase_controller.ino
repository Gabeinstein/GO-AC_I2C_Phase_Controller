#include"phase_controller.h"

phase_controller::phase_controller(int _digital_pin)
{
    digital_pin = _digital_pin;
    address = 0x11;
    phase_comparator = 0;
    level_raw = 0;
}
phase_controller::phase_controller()
{
    digital_pin = 3;
    address = 0x11;
    phase_comparator = 0;
    level_raw = 0;
}

phase_controller::phase_controller(int _digital_pin, byte _address)
{
    digital_pin = _digital_pin;
    address = _address;
    phase_comparator = 0;
    level_raw = 0;
}
void phase_controller::setLevel(byte _level_raw){
    level_raw = _level_raw;
    phase_comparator = map(level_raw,0,255,0,16667);    //120Hz Timer Counter
}
void phase_controller::setAddress(byte _address){
  address = _address;
}
void phase_controller::setPins(int _pin){
  digital_pin = _pin;
}
unsigned int phase_controller::get_phase_comparator(){
    return phase_comparator;
}
byte phase_controller::getAddress(){
    return address;
}
byte phase_controller::getRawValue(){
    return level_raw;
}