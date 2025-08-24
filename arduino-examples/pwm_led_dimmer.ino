// Arduino PWM LED dimmer example
// Shows how to use PWM to control LED brightness
// Try asking Copilot to suggest improvements or variations

int ledPin = 9;      // LED connected to digital pin 9 (PWM capable)
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

void setup() {
  // Initialize the digital pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Set the brightness of the LED
  analogWrite(ledPin, brightness);

  // Change the brightness for next time through the loop
  brightness = brightness + fadeAmount;

  // Reverse the direction of the fading at the ends of the fade
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  // Wait for 30 milliseconds to see the dimming effect
  delay(30);
}