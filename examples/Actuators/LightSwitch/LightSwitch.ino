/*
Cayenne Light Switch Example

This sketch shows how to set up a Light Switch with Cayenne

The Cayenne Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. In the Cayenne Dashboard add a new Light Switch Widget.
2. Select a digital pin number. Do not use digital pins 0 or 1 since those conflict with the use of Serial.
3. Attach the negative leg of an LED to ground and the other leg to the selected digital pin.
   Schematic:
   [Ground] -- [LED] -- [Resistor] -- [Digital Pin]
4. Set the token variable to match the Arduino token from the Dashboard.
5. Compile and upload this sketch.
6. Once the Arduino connects to the Dashboard you can toggle the LED switch.

Notice that there isn't much coding involved to interact with the digital pins.
Most of it is handled automatically from the Cayenne library.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

void loop()
{
	Cayenne.run();
}
