# Arduino Lightsaber
This project is made to simulate a Light saber from Star Wars by using an Arduino Nano. This repository includes the Arduino code, the circuit and a pcb design

## Materials
Materials that I used to make the Light saber:
- Arduino Nano
- WS2812B LED strip
- Push button
- 330 Ohm resistor
- Resistor (1KOhm recommended)
- 4 AA 1.5v batteries
- 4 AA battery holder

## Circuit diagram
<img width="1124" alt="Screenshot 2021-08-16 at 21 23 53" src="https://user-images.githubusercontent.com/78478073/129620455-d927bb69-45c6-4331-9c88-1e4439a5e496.png">


## Code
Before you upload the code to your Arduino, you should have the following libraries installed:
- [FastLED](https://www.arduino.cc/reference/en/libraries/fastled/)
- [OneButton](https://www.arduino.cc/reference/en/libraries/onebutton/)

At the beginning of the code you will find a section to customize your Light saber:
```
// ------ Settings ------
#define LED_PIN     8
#define BUTTON_PIN  5
#define NUM_LEDS    50
#define DELAY       8

bool orange = true;
bool green = true;
bool red = true;
bool white = false;
bool purple = true;
bool yellow = true;
bool blue = true;
// --------------------
```
- You can change the pin numbers if you feel like, but there is no need to if you have followed the circuit diagram.
- ```NUM_LEDS``` can be used to change the length of your Light saber
- ```DELAY``` can be used to change the speed between each transition
- You can disable any color by simply changing the boolean to false.

## How to use
- With a single press on the button the LED will go on/off
- With a double press on the button you can change the color of the LED
