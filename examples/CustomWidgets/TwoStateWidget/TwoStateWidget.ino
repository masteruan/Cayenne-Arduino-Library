/*
Cayenne Two State Display Example

This sketch shows how to set up a two state display widget with Cayenne. This sketch can be used with any widget that displays two states including:
* 2 State
* Open/Close
* CO2 Detector
* Motion Detector
* any other two state display widgets

The Cayenne Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. In the Cayenne Dashboard add a new two state custom widget, e.g 2 State, Motion Detector, etc.
2. Select a digital pin number. Do not use digital pins 0 or 1 since those conflict with the use of Serial.
3. Attach a digital input device (e.g. a button) to the digital pin on your Arduino matching the selected pin.
4. Set the token variable to match the Arduino token from the Dashboard.
5. Compile and upload this sketch.
6. Once the Arduino connects to the Dashboard it should automatically update the widget with data.

Notice that there isn't much coding involved to interact with the digital pins.
Most of it is handled automatically from the Cayenne library.

For further examples of how to send data to Cayenne see the example sketches under Sensors.
*/

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

// If you're not using the Ethernet W5100 shield, change this to match your connection type. See Communications examples.
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
