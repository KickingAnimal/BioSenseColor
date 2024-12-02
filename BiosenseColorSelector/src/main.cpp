#include <DmxSimple.h>
#include <Arduino.h>

// pins for the DMX Controllers
#define settingPin1 5
#define settingPin2 2
#define settingPin3 20

//buttons on the gray box which have no function yet 
/*
#define greenbutton 14
#define bluebutton 15
#define redbutton  17
#define whitebutton  16
#define on_off_button 18
*/

/* 
uint8_t rowPinsForDmx[3] = {5, 22, 24};
uint8_t rowColors[3] = {1, 2, 3};
*/
uint8_t dmx_vals[5] = {0};

/* 
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
*/


void setup() {

// Initialize serial communication and DMX
 Serial.begin(9600);
 pinMode(settingPin1, OUTPUT);
 pinMode(settingPin2, OUTPUT);
 pinMode(settingPin3, OUTPUT);
 DmxSimple.maxChannel(4);
}



void loop() {
  // code is copied 3 times to control 3 different LEDs, calibrated to the specific intensity of the LEDs

Serial.println("loop start");

DmxSimple.usePin(settingPin1); // use the pin for the first LED
//intensity can be set from 0 -255
dmx_vals[2] = 0; // white LED 
dmx_vals[0] = 0; // red 
dmx_vals[1] = 255; // blue 
dmx_vals[3] = 0; // IR 

digitalWrite(settingPin1, HIGH); // turn on the LED

for (int i = 0; i < 4; i++) {
  DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

Serial.println("led 1 (Blue) done");
delay(1000); // wait for 1 second

DmxSimple.usePin(settingPin2); // use the pin for the second LED
//intensity can be set from 0 -255
dmx_vals[2] = 0; // white LED 
dmx_vals[0] = 135; // red 
dmx_vals[1] = 0; // blue 
dmx_vals[3] = 0; // IR 

digitalWrite(settingPin2, HIGH); // turn on the LED

for (int i = 0; i < 4; i++) {
  DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }
Serial.println("led 2 (Red) done");
delay(1000);

DmxSimple.usePin(settingPin3); // use the pin for the third LED
//intensity can be set from 0 -255
dmx_vals[2] = 235; // white LED 
dmx_vals[0] = 0; // red 
dmx_vals[1] = 0; // blue 
dmx_vals[3] = 0; // IR 

digitalWrite(settingPin3, HIGH);  // turn on the LED

for (int i = 0; i < 4; i++) {
  DmxSimple.write(i + 1, dmx_vals[i]);  // write the values to the DMX
  }
Serial.println("led 3 (White) done");
delay(1000);

Serial.println("all done");

}
