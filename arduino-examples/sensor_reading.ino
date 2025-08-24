// Arduino sensor reading example
// Demonstrates analog sensor reading and serial communication
// GitHub Copilot can suggest improvements and optimizations

int sensorPin = A0;    // select the input pin for the sensor
int sensorValue = 0;   // variable to store the value coming from the sensor

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the value from the sensor
  sensorValue = analogRead(sensorPin);
  
  // Print the sensor value to the serial monitor
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  
  // Convert to voltage (assuming 5V reference)
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  
  // Wait before next reading
  delay(500);
}