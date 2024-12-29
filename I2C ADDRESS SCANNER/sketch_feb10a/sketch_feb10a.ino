// This is simple code to scan for I2C devices and outputs the device address to the serial monitor
// This software if free for anyone to use or modify

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C ADDRESS SCANNER");
}

void loop() {
  byte error, address;
  int devices = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println();
      devices++;
    }
  }

  if (devices == 0) {
    Serial.println("No devices found");
  } else {
    Serial.print("Found ");
    Serial.print(devices);
    Serial.println(" devices");
  }

  delay(5000);
}
