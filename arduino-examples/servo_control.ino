// Arduino servo control example
// Demonstrates servo motor control using the Servo library
// GitHub Copilot can help complete servo control functions

#include <Servo.h>

Servo myServo;        // Create servo object to control a servo
int pos = 0;          // Variable to store the servo position

void setup() {
  myServo.attach(9);  // Attaches the servo on pin 9 to the servo object
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);              // Tell servo to go to position in variable 'pos'
    delay(15);                       // Waits 15ms for the servo to reach the position
  }
  
  // Sweep from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);              // Tell servo to go to position in variable 'pos'
    delay(15);                       // Waits 15ms for the servo to reach the position
  }
}