#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <DmxSimple.h>
#include <BlockNot.h>

// Function declarations
void turnOnAllLights();
void turnOnBlueLight();
void turnOnRedLight();
void turnOnWhiteLight();

void turnOffAllLights();
void turnOffBlueLight();
void turnOffRedLight();
void turnOffWhiteLight();

// Variable declarations
extern uint8_t dmx_vals[5];
extern bool lightsOff;
extern bool blueLightOff;
extern bool redLightOff;
extern bool whiteLightOff;

#endif // MAIN_H
