#include <Wire.h>

void setup() {
  Wire.begin(0x00); // join I2C bus (address optional for master)
}

byte module_address = 0x13;
byte level_raw = 0;

void loop() {
  Wire.beginTransmission(0x10); // transmit to device #8
  Wire.write(module_address);              // sends one byte
  Wire.write(level_raw);
  Wire.endTransmission();    // stop transmitting
  level_raw ++;
  delay(500);
}