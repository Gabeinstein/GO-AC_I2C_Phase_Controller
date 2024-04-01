#include "ac_controller.h"
#include <Wire.h>

ac_controller controller1;

volatile int counter = 0;
volatile bool isZeroCross = 0;
volatile unsigned int current_capture = 0;

void setup(){
    Wire.begin(0x10);
    Wire.onReceive(i2c_receive_event);
    Serial.begin(9600);

    //Timer interrupts;
    attachInterrupt(0,ISR_ZERO_CROSSING,RISING);
    noInterrupts();
    TCCR2A = 0; TCCR2B = 0;
    TCNT2 = 0;
    TCCR2B |= 0b00001101;
    OCR2A = 130;
    TIMSK2 |= 0b00000010;
    interrupts();
}
void loop(){
    //controller1.status();
    //Serial.println(controller1.getSwitches()[0].getAddress());
    Serial.println(counter);
    //delay(500);
}
void i2c_receive_event(int howMany){
    byte address_from_master = Wire.read();
    byte level_raw_value = Wire.read();
    //Serial.println(address_from_master);
    //Serial.println(level_raw_value);
    controller1.updateLevel(address_from_master,level_raw_value);
}
void ISR_ZERO_CROSSING(){
    isZeroCross = true;
    counter = 0;
    digitalWrite(LED_BUILTIN,LOW);
}
ISR(TIMER2_COMPA_vect){
    if (isZeroCross == true){
        if (counter >= 65){     //130 es 120Hz
            digitalWrite(LED_BUILTIN,HIGH);
            counter = 0;
            isZeroCross = false;
        }else{
            counter ++;
        }
    }
}