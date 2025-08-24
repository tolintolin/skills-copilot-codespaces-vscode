# Arduino Examples for GitHub Copilot

Este directorio contiene ejemplos de código Arduino diseñados para demostrar las capacidades de GitHub Copilot en el desarrollo de proyectos de microcontroladores.

## Archivos incluidos

### 1. `basic_led_blink.ino`
- **Descripción**: Ejemplo básico para hacer parpadear un LED
- **Conceptos**: pinMode, digitalWrite, delay
- **Hardware requerido**: Arduino Uno/Nano, LED integrado

### 2. `sensor_reading.ino`  
- **Descripción**: Lectura de sensores analógicos y comunicación serie
- **Conceptos**: analogRead, Serial, conversión ADC
- **Hardware requerido**: Arduino, sensor analógico (potenciómetro, LDR, etc.)

### 3. `pwm_led_dimmer.ino`
- **Descripción**: Control de brillo LED usando PWM
- **Conceptos**: analogWrite, PWM, efectos de desvanecimiento
- **Hardware requerido**: Arduino, LED, resistencia

### 4. `servo_control.ino`
- **Descripción**: Control de servomotor
- **Conceptos**: Biblioteca Servo, control de posición
- **Hardware requerido**: Arduino, servomotor

### 5. `button_debounce.ino`
- **Descripción**: Lectura de botón con anti-rebote (debounce)
- **Conceptos**: INPUT_PULLUP, debounce, manejo de interrupciones
- **Hardware requerido**: Arduino, pulsador, LED

## Cómo usar con GitHub Copilot

1. **Abre Arduino IDE** o VS Code con la extensión Arduino
2. **Activa GitHub Copilot** en tu editor
3. **Abre cualquiera de los archivos .ino**
4. **Experimenta con Copilot**:
   - Escribe comentarios describiendo lo que quieres hacer
   - Deja que Copilot sugiera código
   - Prueba modificaciones y mejoras sugeridas

## Sugerencias para experimentos

### Con `basic_led_blink.ino`:
- Comenta: `// Make LED blink faster when button is pressed`
- Comenta: `// Add multiple LEDs with different patterns`

### Con `sensor_reading.ino`:
- Comenta: `// Add temperature sensor reading`
- Comenta: `// Create data logging to SD card`

### Con `pwm_led_dimmer.ino`:
- Comenta: `// Control brightness with potentiometer`
- Comenta: `// Add RGB LED color mixing`

### Con `servo_control.ino`:
- Comenta: `// Control servo with joystick input`
- Comenta: `// Create smooth servo movements`

### Con `button_debounce.ino`:
- Comenta: `// Add multiple buttons with different functions`
- Comenta: `// Create button press patterns detection`

## Consejos para mejores resultados con Copilot

1. **Escribe comentarios claros** en inglés o español
2. **Usa nombres descriptivos** para variables y funciones  
3. **Incluye el contexto** del hardware que estás usando
4. **Experimenta con diferentes enfoques** sugeridos por Copilot
5. **Revisa y adapta** las sugerencias a tu proyecto específico

## Compilación y carga

Todos los ejemplos están diseñados para compilar con Arduino IDE 1.8+ o Arduino CLI. Asegúrate de:

- Seleccionar la placa correcta (Arduino Uno, Nano, etc.)
- Seleccionar el puerto serie correcto
- Instalar las librerías necesarias (como Servo.h)

## Contribuciones

Si tienes ideas para nuevos ejemplos Arduino que demuestren capacidades específicas de GitHub Copilot, ¡las contribuciones son bienvenidas!