#include "ac_controller.h"

ac_controller controller1;

void setup(){
    Serial.begin(9600);
}
void loop(){
    Serial.println(controller1.getSwitches()[2].getAddress());
    delay(1000);
}