# Arduino Lightsaber
This project is made to simulate a Light saber from Star Wars by using an Arduino Nano. This repository includes the Arduino code, the diagram and a pcb design

## Materials
Materials that I used to make the Light saber:
- Arduino Nano
- WS2812B LED strip
- Push button
- 330 Ohm resistor
- Resistor (1KOhm recommended)
- 4 AA 1.5v (rechargeable) batteries
- 4 AA battery holder

## Diagram
<img src="https://user-images.githubusercontent.com/78478073/130287816-f7bc7af5-6194-49a9-b75d-72cfc1e3cc56.png" width="650">

## Code
Before you upload the code to your Arduino, you should have the following libraries installed:
- [FastLED](https://www.arduino.cc/reference/en/libraries/fastled/)
- [OneButton](https://www.arduino.cc/reference/en/libraries/onebutton/)

At the beginning of the code you will find a section to customize your Light saber:
```
// ------ Settings ------
#define LED_PIN       8
#define BUTTON_PIN    5
#define NUM_LEDS      50
#define DELAY         1

bool orange = true;
bool green = true;
bool red = true;
bool white = true;
bool purple = true;
bool yellow = true;
bool blue = true;

bool flickering = true;
// --------------------
```
- You can change the pin numbers if you want to, but there is no need to if you have followed along with the diagram.
- ```NUM_LEDS``` can be used to change the length of your Light saber
- ```DELAY``` can be used to change the speed between each transition
- You can disable any color by changing the boolean to false
- ```flickering``` can be used to enable or disable flickering

## How to use
- With a single press on the button the LED will go on/off
- With a double press on the button you can change the color of the LED
