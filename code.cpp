// Libraries for Arduino
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

// Define the PIR sensor pin
const int pirPin = 2; // Adjust to your actual pin connection

// Variables
boolean lightStatus = false;

void setup() {
  // Initialize the PIR sensor pin as an input
  pinMode(pirPin, INPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the PIR sensor
  int pirValue = digitalRead(pirPin);

  // If motion is detected
  if (pirValue == HIGH) {
    if (!lightStatus) {
      // Send a signal to turn on the lights (you can replace this with your actual lighting control mechanism)
      Serial.println("Lights ON");
      lightStatus = true;
    }
  } else {
    if (lightStatus) {
      // Send a signal to turn off the lights (you can replace this with your actual lighting control mechanism)
      Serial.println("Lights OFF");
      lightStatus = false;
    }
  }

  // Delay to avoid rapid readings
  delay(1000);
}
