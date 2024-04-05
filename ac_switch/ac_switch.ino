#include "ac_controller.h"
#include <Wire.h>
#include <TimerOne.h>

ac_controller controller1;

volatile unsigned int counter = 0;
volatile bool isZeroCross = 0;


void setup(){
    Wire.begin(0x10);
    Wire.onReceive(i2c_receive_event);
    Serial.begin(9600);
    pinMode(controller1.getSwitches()[0].getPin(),OUTPUT);
    pinMode(controller1.getSwitches()[1].getPin(),OUTPUT);
    pinMode(controller1.getSwitches()[2].getPin(),OUTPUT);
    //Timer interrupts;
    attachInterrupt(0, ZeroCrossingFunction, RISING);
    Timer1.initialize(100);     //100us
    Timer1.attachInterrupt(Dimming_control, 100);        
}
void loop(){
    controller1.status();
    //Serial.println(controller1.getSwitches()[0].getAddress());
    //Serial.println(counter);
}
void i2c_receive_event(int howMany){
    byte address_from_master = Wire.read();
    byte level_raw_value = Wire.read();
    //Serial.println(address_from_master);
    //Serial.println(level_raw_value);
    controller1.updateLevel(address_from_master,level_raw_value);
}
void ZeroCrossingFunction(){
    counter = 0;
    isZeroCross = true;
    for(int i=0; i < controller1.getNumSwitches(); i++){
        digitalWrite(controller1.getSwitches()[i].getPin(),LOW);
    }
}
void Dimming_control(){
    if(isZeroCross == true){
        for (int i = 0; i < controller1.getNumSwitches(); i++){
            if (counter >= controller1.getSwitches()[i].get_phase_comparator()){
                digitalWrite(controller1.getSwitches()[i].getPin(),HIGH);
            }
        }
        counter++;
    } 
}


