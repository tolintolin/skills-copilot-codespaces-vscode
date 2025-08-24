# Arduino Project Setup with GitHub Copilot

Este archivo muestra cómo configurar un proyecto Arduino y usar GitHub Copilot efectivamente.

## Configuración del entorno

### Para Arduino IDE:
1. Instala Arduino IDE 2.0 o superior
2. Instala la extensión de GitHub Copilot
3. Configura tu placa y puerto

### Para VS Code:
1. Instala VS Code
2. Instala la extensión Arduino
3. Instala la extensión GitHub Copilot
4. Configura el compilador Arduino

## Consejos para usar Copilot con Arduino

### 1. Sé específico con el hardware
```cpp
// ✅ Bueno: Específico sobre el hardware
// Control servo motor MG995 on pin 9 for robotic arm

// ❌ Malo: Muy genérico  
// Move motor
```

### 2. Menciona bibliotecas necesarias
```cpp
// ✅ Bueno: Incluye contexto de bibliotecas
// Using WiFi.h library to connect ESP32 to local network

// ❌ Malo: Sin contexto de bibliotecas
// Connect to internet
```

### 3. Describe el comportamiento esperado
```cpp
// ✅ Bueno: Comportamiento específico
// Non-blocking LED fade in and out every 2 seconds

// ❌ Malo: Comportamiento vago
// Make LED do something
```

## Patrones comunes que Copilot reconoce bien

### Configuración de pines
```cpp
// Define pins for ultrasonic sensor HC-SR04
const int trigPin = 7;
const int echoPin = 8;
```

### Lectura de sensores
```cpp
// Read temperature and humidity from DHT22 sensor
```

### Control de actuadores
```cpp
// Control stepper motor 28BYJ-48 with ULN2003 driver
```

### Comunicación
```cpp
// Send sensor data via Serial at 115200 baud rate
```

## Estructura de proyecto recomendada

```
mi-proyecto-arduino/
├── mi-proyecto-arduino.ino    # Archivo principal
├── config.h                   # Configuraciones y constantes
├── sensors.cpp                # Funciones de sensores
├── sensors.h                  # Declaraciones de sensores
├── actuators.cpp              # Funciones de actuadores
├── actuators.h                # Declaraciones de actuadores
└── README.md                  # Documentación del proyecto
```

## Ejemplos de prompts efectivos para Copilot

1. **Para inicialización**: "Initialize I2C communication for multiple sensors"
2. **Para control**: "Control RGB LED strip WS2812B with color patterns"
3. **Para comunicación**: "Send JSON data over WiFi to local server"
4. **Para sensores**: "Read GPS coordinates from NEO-6M module"
5. **Para actuadores**: "Control DC motor speed with L298N driver"

## Debugging con Copilot

```cpp
// Add debug prints for troubleshooting sensor readings
// Check if I2C device responds at address 0x48
// Validate input ranges before processing
```

Copilot puede sugerir código de debugging y validación automáticamente cuando mencionas troubleshooting o validation en los comentarios.