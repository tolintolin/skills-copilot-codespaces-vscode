// Arduino basic LED blink example
// This demonstrates how GitHub Copilot can help with Arduino code

void setup() {
  // Initialize digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // Wait for a second
  delay(1000);
  // Turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // Wait for a second
  delay(1000);
}