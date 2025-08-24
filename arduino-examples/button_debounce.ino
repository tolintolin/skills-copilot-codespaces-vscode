// Arduino button input example
// Shows how to read button state and debounce
// Ask Copilot to suggest improvements for button handling

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin = 13;       // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = 0;     // previous state of the button
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

bool ledState = false;       // current state of the LED

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Initialize the pushbutton pin as an input with pullup
  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  // Read the state of the switch into a local variable
  int reading = digitalRead(buttonPin);

  // Check if the button state has changed
  if (reading != lastButtonState) {
    // Reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed
    if (reading != buttonState) {
      buttonState = reading;

      // Only toggle the LED if the new button state is LOW (pressed)
      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        Serial.println(ledState ? "LED ON" : "LED OFF");
      }
    }
  }

  // Save the reading for next time
  lastButtonState = reading;
}