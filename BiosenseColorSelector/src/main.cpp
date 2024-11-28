#include <DmxSimple.h>
#include <Arduino.h>


uint8_t rowPinsForDmx[3] = {5, 22, 24};
uint8_t dmx_vals[4] = {0};
uint8_t rowColors[3] = {1, 2, 3};


void selectColor(int color){
  switch (color){
    case 1:
      dmx_vals[2] = 0; // white LED 
      dmx_vals[0] = 255; // red 
      dmx_vals[1] = 0; // blue 
      dmx_vals[3] = 0; // IR 
    case 2:
      dmx_vals[2] = 0; // white LED 
      dmx_vals[0] = 0; // red 
      dmx_vals[1] = 255; // blue 
      dmx_vals[3] = 0; // IR
    case 3:
      dmx_vals[2] = 255; // white LED 
      dmx_vals[0] = 0; // red 
      dmx_vals[1] = 0; // blue 
      dmx_vals[3] = 0; // IR 
  }
}; 


void setup() {
  
// Initialize serial communication and DMX
  Serial.begin(9600);
  // pinMode(6, OUTPUT);

  // pinMode(5, OUTPUT);
  // pinMode(22, OUTPUT);
  // pinMode(24, OUTPUT);

  DmxSimple.usePin(5);
  DmxSimple.maxChannel(4);

   // DmxSimple
}

void loop() {

  Serial.println("Setting Pin 5");
  DmxSimple.usePin(5);

  delay(200);
  
  DmxSimple.write(1, 0);
  DmxSimple.write(2, 50);
  DmxSimple.write(3, 0);
  DmxSimple.write(4, 0);
  
  // Serial.println("Setting Pin 2");
  // DmxSimple.usePin(2);
  
  // delay(200);

  // DmxSimple.write(1, 255);
  // DmxSimple.write(2, 0);
  // DmxSimple.write(3, 0);
  // DmxSimple.write(4, 0);

  // Serial.println("Setting Pin 24");
  // DmxSimple.usePin(24);

  // delay(200);

  // DmxSimple.write(1, 255);
  // DmxSimple.write(2, 0);
  // DmxSimple.write(3, 0);
  // DmxSimple.write(4, 0);
  
  Serial.println("Done..");

  delay(10e3);
}
