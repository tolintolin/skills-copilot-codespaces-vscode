// Smart Home Security System - Main Controller
// This example shows how to structure a complex Arduino project
// Try asking Copilot to expand each section with specific implementations

#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

// =========================== HARDWARE SETUP ===========================
// LCD Display (16x2)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Keypad setup (4x4)
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},  
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {A3, A2, A1, A0}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo for door lock
Servo doorLock;

// Sensors and outputs
const int pirPin = 10;          // Motion sensor
const int buzzerPin = A4;       // Alarm buzzer  
const int ledGreen = 13;        // Status LED (armed/disarmed)
const int ledRed = A5;          // Alert LED

// =========================== SYSTEM VARIABLES ===========================
String correctCode = "1234";   // Security code
String enteredCode = "";        // User input buffer
bool systemArmed = false;       // Security system state
bool motionDetected = false;    // Motion sensor state
bool alarmActive = false;       // Alarm state

unsigned long lastMotionTime = 0;
unsigned long alarmStartTime = 0;
const unsigned long alarmDuration = 30000; // 30 seconds

// =========================== SETUP FUNCTION ===========================
void setup() {
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Security System");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  
  // Initialize pins
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  // Initialize servo
  doorLock.attach(1);
  doorLock.write(0); // Unlocked position
  
  // Startup sequence
  delay(2000);
  displayMainMenu();
}

// =========================== MAIN LOOP ===========================
void loop() {
  // Check keypad input
  char key = keypad.getKey();
  if (key) {
    handleKeyInput(key);
  }
  
  // Monitor motion sensor if system is armed
  if (systemArmed) {
    checkMotionSensor();
  }
  
  // Handle active alarm
  if (alarmActive) {
    handleAlarm();
  }
  
  // Update status indicators
  updateStatusLEDs();
  
  delay(100); // Small delay for stability
}

// =========================== KEYPAD FUNCTIONS ===========================
void handleKeyInput(char key) {
  if (key >= '0' && key <= '9') {
    // Number input
    enteredCode += key;
    updateCodeDisplay();
  }
  else if (key == '#') {
    // Confirm code entry
    processCodeEntry();
  }
  else if (key == '*') {
    // Clear input
    enteredCode = "";
    updateCodeDisplay();
  }
  else if (key == 'A') {
    // Arm system
    armSystem();
  }
  else if (key == 'B') {
    // Disarm system  
    disarmSystem();
  }
  else if (key == 'C') {
    // Check status
    displayStatus();
  }
  else if (key == 'D') {
    // Emergency disarm
    emergencyDisarm();
  }
}

// =========================== SYSTEM CONTROL FUNCTIONS ===========================
void armSystem() {
  if (enteredCode == correctCode) {
    systemArmed = true;
    doorLock.write(90); // Lock position
    lcd.clear();
    lcd.print("System ARMED");
    lcd.setCursor(0, 1);
    lcd.print("Door Locked");
    Serial.println("System armed successfully");
    enteredCode = "";
    delay(2000);
    displayMainMenu();
  } else {
    displayError("Wrong Code!");
  }
}

void disarmSystem() {
  if (enteredCode == correctCode) {
    systemArmed = false;
    alarmActive = false;
    doorLock.write(0); // Unlock position
    lcd.clear();
    lcd.print("System DISARMED");
    lcd.setCursor(0, 1);
    lcd.print("Door Unlocked");
    Serial.println("System disarmed successfully");
    enteredCode = "";
    delay(2000);
    displayMainMenu();
  } else {
    displayError("Wrong Code!");
  }
}

// =========================== SENSOR FUNCTIONS ===========================
void checkMotionSensor() {
  if (digitalRead(pirPin) == HIGH && !motionDetected) {
    motionDetected = true;
    lastMotionTime = millis();
    triggerAlarm();
    Serial.println("MOTION DETECTED!");
  }
  
  // Reset motion flag after 5 seconds
  if (motionDetected && (millis() - lastMotionTime > 5000)) {
    motionDetected = false;
  }
}

// =========================== ALARM FUNCTIONS ===========================
void triggerAlarm() {
  alarmActive = true;
  alarmStartTime = millis();
  lcd.clear();
  lcd.print("*** ALARM ***");
  lcd.setCursor(0, 1);
  lcd.print("MOTION DETECTED");
  Serial.println("ALARM TRIGGERED!");
}

void handleAlarm() {
  // Sound alarm
  tone(buzzerPin, 1000, 200);
  delay(300);
  tone(buzzerPin, 1500, 200);
  delay(300);
  
  // Auto-disable alarm after duration
  if (millis() - alarmStartTime > alarmDuration) {
    alarmActive = false;
    displayMainMenu();
  }
}

// =========================== DISPLAY FUNCTIONS ===========================
void displayMainMenu() {
  lcd.clear();
  lcd.print(systemArmed ? "ARMED" : "DISARMED");
  lcd.setCursor(0, 1);
  lcd.print("Enter Code:");
}

void updateCodeDisplay() {
  lcd.setCursor(11, 1);
  lcd.print("     "); // Clear old input
  lcd.setCursor(11, 1);
  for (int i = 0; i < enteredCode.length(); i++) {
    lcd.print("*"); // Show asterisks for security
  }
}

void displayStatus() {
  lcd.clear();
  lcd.print("Status: ");
  lcd.print(systemArmed ? "ARMED" : "SAFE");
  lcd.setCursor(0, 1);
  lcd.print("Motion: ");
  lcd.print(motionDetected ? "YES" : "NO");
  delay(3000);
  displayMainMenu();
}

void displayError(String message) {
  lcd.clear();
  lcd.print("ERROR:");
  lcd.setCursor(0, 1);
  lcd.print(message);
  enteredCode = "";
  delay(2000);
  displayMainMenu();
}

void emergencyDisarm() {
  systemArmed = false;
  alarmActive = false;
  doorLock.write(0);
  lcd.clear();
  lcd.print("EMERGENCY");
  lcd.setCursor(0, 1);
  lcd.print("DISARMED!");
  Serial.println("Emergency disarm activated!");
  delay(3000);
  displayMainMenu();
}

// =========================== STATUS FUNCTIONS ===========================
void updateStatusLEDs() {
  // Green LED: System armed status
  digitalWrite(ledGreen, systemArmed ? HIGH : LOW);
  
  // Red LED: Alarm or motion status
  if (alarmActive) {
    digitalWrite(ledRed, (millis() % 500) < 250); // Blink rapidly
  } else if (motionDetected) {
    digitalWrite(ledRed, HIGH);
  } else {
    digitalWrite(ledRed, LOW);
  }
}