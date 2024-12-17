#include <DmxSimple.h>
#include <Arduino.h>
#include <main.h>
#include <BlockNot.h>

// pins for the DMX Controllers
#define settingPin1 5
#define settingPin2 2
#define settingPin3 20

//buttons on the gray box which have no function yet 
#define greenbutton 14 // not used
#define bluebutton 15
#define redbutton  17
#define whitebutton  16
#define on_off_button 19

uint8_t dmx_vals[5] = {0};
bool lightsOff = false;
bool blueLightOff = false;
bool redLightOff = false;
bool whiteLightOff = false;

BlockNot blueLightTimer(120000); // 2 minutes timer for blue light
BlockNot redLightTimer(120000); // 2 minutes timer for red light
BlockNot whiteLightTimer(120000); // 2 minutes timer for white light

/// @brief Turn on all lights
/// @details This function turns on all the lights
/// @param void
/// @return void
/// @note all the  variables are set globally
void turnOnAllLights(){
  Serial.println("turning on all lights");
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
  lightsOff = false;
  blueLightOff = false;
  redLightOff = false;
  whiteLightOff = false;
}

/// @brief Turn off all lights
/// @details This function turns off all the lights
/// @param void
/// @return void
/// @note all the  variables are set globally
void turnOffAllLights() {
  Serial.println("turning off all lights");
  DmxSimple.usePin(settingPin1); // use the pin for the first LED
  //intensity can be set from 0 -255
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin1, HIGH); // turn on the LED

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  Serial.println("led 1 (Blue) done");



  DmxSimple.usePin(settingPin2); // use the pin for the second LED
  //intensity can be set from 0 -255
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin2, HIGH); // turn on the LED

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }
  Serial.println("led 2 (Red) done");



  DmxSimple.usePin(settingPin3); // use the pin for the third LED
  //intensity can be set from 0 -255
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin3, HIGH);  // turn on the LED

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]);  // write the values to the DMX
  }
  Serial.println("led 3 (White) done");
  lightsOff = true;
  blueLightOff = true;
  redLightOff = true;
  whiteLightOff = true;
}

/// @brief Turn on the blue light
/// @details This function turns on the blue light
/// @param void
/// @return void
void turnOnBlueLight() {
  Serial.println("turning on blue light");
  DmxSimple.usePin(settingPin1); // use the pin for the first LED
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 255; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin1, HIGH);

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  blueLightOff = false;
  Serial.println("led 1 (Blue) on");
}

void turnOffBlueLight() {
  Serial.println("turning off blue light");
  DmxSimple.usePin(settingPin1); // use the pin for the first LED
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin1, HIGH);

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  blueLightOff = true;
  Serial.println("led 1 (Blue) off");
}

/// @brief Turn on the red light
/// @details This function turns on the red light
/// @param void
/// @return void
void turnOnRedLight() {
  Serial.println("turning on red light");
  DmxSimple.usePin(settingPin2); // use the pin for the second LED
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 135; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin2, HIGH);

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  redLightOff = false;
  Serial.println("led 2 (Red) on");
}

void turnOffRedLight() {
  Serial.println("turning off red light");
  DmxSimple.usePin(settingPin2); // use the pin for the second LED
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin2, HIGH);

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  redLightOff = true;
  Serial.println("led 2 (Red) off");
}


/// @brief Turn on the white light
/// @details This function turns on the white light
/// @param void
/// @return void
void turnOnWhiteLight() {
  Serial.println("turning on white light");
  DmxSimple.usePin(settingPin3); // use the pin for the third LED
  dmx_vals[2] = 235; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin3, HIGH);

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  whiteLightOff = false;
  Serial.println("led 3 (White) on");
}

void turnOffWhiteLight() {
  Serial.println("turning off white light");
  DmxSimple.usePin(settingPin3); // use the pin for the third LED
  dmx_vals[2] = 0; // white LED 
  dmx_vals[0] = 0; // red 
  dmx_vals[1] = 0; // blue 
  dmx_vals[3] = 0; // IR 

  digitalWrite(settingPin3, HIGH);

  for (int i = 0; i < 4; i++) {
    DmxSimple.write(i + 1, dmx_vals[i]); // write the values to the DMX
  }

  whiteLightOff = true;
  Serial.println("led 3 (White) off");
}

void setup() {
  // Initialize serial communication and DMX
  Serial.begin(9600);
  pinMode(settingPin1, OUTPUT);
  pinMode(settingPin2, OUTPUT);
  pinMode(settingPin3, OUTPUT);
  pinMode(bluebutton, INPUT_PULLUP); // Set blue button pin as input
  pinMode(whitebutton, INPUT_PULLUP); // Set white button pin as input
  pinMode(redbutton, INPUT_PULLUP); // Set red button pin as input
  pinMode(on_off_button, INPUT_PULLUP); // Set on/off switch pin as input
  DmxSimple.maxChannel(4);
  turnOnAllLights();

  Serial.println("setup done, all light should be on");
}

void loop() {
  // Check if the on/off switch is turned off
  if (digitalRead(on_off_button) == LOW) {
    if (!lightsOff) {
      turnOffAllLights();
      Serial.println("All lights turned off, waiting for on/off switch to be turned on, variable lightsOff is true");
    }
  } else if (lightsOff && digitalRead(on_off_button) != LOW) {
    turnOnAllLights();
    Serial.println("All lights turned on, variable lightsOff is false");
  }

  if (!lightsOff) { // If the lights are not off then check if the buttons are pressed.
    // Check if the blue button is pressed
    if (digitalRead(bluebutton) == LOW && !blueLightOff) {
      Serial.println("Blue button pressed, turning off blue light for 2 minutes");
      turnOffBlueLight();
      blueLightTimer.start();
    }

    // Check if the blue light timer has triggered and turn on the blue light if it was off
    if (blueLightOff && blueLightTimer.triggered()) {
      turnOnBlueLight();
    }

    // Check if the red button is pressed
    if (digitalRead(redbutton) == LOW && !redLightOff) {
      Serial.println("Red button pressed, turning off red light for 2 minutes");
      turnOffRedLight();
      redLightTimer.start();
    }

    // Check if the red light timer has triggered and turn on the red light if it was off
    if (redLightOff && redLightTimer.triggered()) {
      turnOnRedLight();
    }

    // Check if the white button is pressed
    if (digitalRead(whitebutton) == LOW && !whiteLightOff) {
      Serial.println("White button pressed, turning off white light for 2 minutes");
      turnOffWhiteLight();
      whiteLightTimer.start();
    }
    
    // Check if the white light timer has triggered and turn on the white light if it was off
    if (whiteLightOff && whiteLightTimer.triggered()) {
      turnOnWhiteLight();
    }
    Serial.println("button if end");
  }

  Serial.println("main loop end");
}
