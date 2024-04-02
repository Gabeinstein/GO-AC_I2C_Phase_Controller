#include <Wire.h>

void setup() {
  Wire.begin(0x00); // join I2C bus (address optional for master)
  Serial.begin(9600);
}

byte module_address = 0x11;
byte level_raw = 5;
int data = 0;
void loop() {
  data = analogRead(A0);
  level_raw = map(data,0,1024,0,255);
  Wire.beginTransmission(0x10); // transmit to device #8
  Wire.write(module_address);              // sends one byte
  Wire.write(level_raw);
  Wire.endTransmission();    // stop transmitting
  Serial.println(level_raw);
  delay(5);
}