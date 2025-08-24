// Advanced Arduino IoT sensor station
// This example shows how Copilot can help with more complex Arduino projects
// Try asking Copilot to add features like WiFi, web server, or data logging

#include <SoftwareSerial.h>

// Pin definitions
const int tempSensorPin = A0;     // Temperature sensor (LM35 or TMP36)
const int lightSensorPin = A1;    // Light sensor (LDR)
const int motionSensorPin = 2;    // PIR motion sensor
const int buzzerPin = 8;          // Buzzer for alerts
const int ledPin = 13;            // Status LED

// Variables for sensor readings
float temperature = 0.0;
int lightLevel = 0;
bool motionDetected = false;
unsigned long lastMotionTime = 0;

// Timing variables
unsigned long previousMillis = 0;
const long interval = 2000;      // Update interval in milliseconds

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Configure pins
  pinMode(motionSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // Startup sequence
  Serial.println("=== Arduino Sensor Station ===");
  Serial.println("Initializing sensors...");
  
  // Blink LED to indicate startup
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  
  Serial.println("System ready!");
  Serial.println("Time,Temperature(°C),Light Level,Motion");
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Check for motion (immediate response)
  if (digitalRead(motionSensorPin) == HIGH) {
    if (!motionDetected) {
      motionDetected = true;
      lastMotionTime = currentMillis;
      digitalWrite(ledPin, HIGH);
      
      // Sound alert
      tone(buzzerPin, 1000, 200);
      
      Serial.println("*** MOTION DETECTED ***");
    }
  } else {
    // Reset motion flag after 5 seconds of no motion
    if (motionDetected && (currentMillis - lastMotionTime > 5000)) {
      motionDetected = false;
      digitalWrite(ledPin, LOW);
    }
  }
  
  // Read sensors at regular intervals
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Read temperature sensor (TMP36 formula)
    int tempReading = analogRead(tempSensorPin);
    float voltage = tempReading * 5.0 / 1024.0;
    temperature = (voltage - 0.5) * 100.0;  // TMP36 conversion
    
    // Read light sensor
    lightLevel = analogRead(lightSensorPin);
    int lightPercent = map(lightLevel, 0, 1023, 0, 100);
    
    // Output data in CSV format
    Serial.print(currentMillis / 1000);  // Time in seconds
    Serial.print(",");
    Serial.print(temperature, 1);
    Serial.print(",");
    Serial.print(lightPercent);
    Serial.print(",");
    Serial.println(motionDetected ? "YES" : "NO");
    
    // Check for alert conditions
    checkAlerts();
  }
}

void checkAlerts() {
  // Temperature alerts
  if (temperature > 30.0) {
    Serial.println("ALERT: High temperature detected!");
    blinkLED(3);
  } else if (temperature < 0.0) {
    Serial.println("ALERT: Low temperature detected!");
    blinkLED(2);
  }
  
  // Light level alerts
  int lightPercent = map(lightLevel, 0, 1023, 0, 100);
  if (lightPercent < 10) {
    Serial.println("INFO: Very dark conditions");
  }
}

void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}