<!--
  <<< Author notes: Arduino Step >>>
  Start this step by acknowledging the previous step.
  Define terms and link to docs for Arduino development.
-->

## Arduino Examples: Using GitHub Copilot for Embedded Programming

_¡Excelente trabajo con JavaScript!_ :tada: _Now let's explore how GitHub Copilot can help with Arduino development!_

GitHub Copilot excels at helping with embedded programming, including Arduino sketches. It can suggest complete functions, help with hardware-specific code, and even assist with sensor interfacing and communication protocols.

### :keyboard: Activity: Explore Arduino examples with Copilot

1. Navigate to the `arduino-examples` folder in your repository
2. Open any of the `.ino` files in VS Code (or Arduino IDE with Copilot extension)
3. Try these experiments:

#### Experiment 1: Extend the basic blink example
1. Open `basic_led_blink.ino`
2. Add a comment at the end: `// Add button to control blink speed`
3. Let Copilot suggest the implementation
4. Press Tab to accept good suggestions

#### Experiment 2: Enhance sensor reading
1. Open `sensor_reading.ino`  
2. Add a comment: `// Add temperature and humidity sensor DHT22`
3. Watch Copilot suggest the include statements and sensor code
4. Try: `// Log data to SD card with timestamp`

#### Experiment 3: Create new functionality
1. Create a new file called `traffic_light.ino`
2. Start with this comment: `// Create a traffic light system with 3 LEDs`
3. Let Copilot build the entire program structure
4. Add: `// Add pedestrian crossing button`

### :keyboard: Activity: Test Arduino code compilation

Even if you don't have physical Arduino hardware, you can verify your code:

1. Install Arduino CLI or Arduino IDE 2.0
2. Try compiling one of the examples:
   ```bash
   arduino-cli compile --fqbn arduino:avr:uno arduino-examples/basic_led_blink.ino
   ```

### Tips for Arduino development with Copilot

- **Be specific about hardware**: Mention "Arduino Uno", "ESP32", or specific sensors
- **Include pin numbers**: "LED on pin 13", "button on pin 2"  
- **Mention libraries**: "using Servo library", "with WiFi.h"
- **Describe behavior**: "non-blocking delay", "interrupt-driven"

### Common Arduino patterns Copilot knows well

- **Sensor reading and calibration**
- **Motor control (servo, stepper, DC)**
- **Communication (I2C, SPI, Serial)**
- **Interrupt handling**
- **Power management**
- **Real-time constraints**

### :keyboard: Activity: Push your Arduino experiments

1. Create or modify an Arduino sketch using Copilot suggestions
2. Add your changes to git:
   ```
   git add arduino-examples/
   ```
3. Commit your changes:
   ```
   git commit -m "Arduino examples with Copilot assistance"
   ```
4. Push to your repository:
   ```
   git push
   ```

**¡Felicitaciones!** You've now seen how GitHub Copilot can assist with both web development (JavaScript) and embedded programming (Arduino). The AI understands context across different programming domains and can help accelerate development in both areas.

**Wait about 60 seconds then refresh your repository landing page for the next step.**