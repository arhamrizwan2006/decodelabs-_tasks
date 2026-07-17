# Environmental Monitor System

Arduino project that reads temperature and humidity from a DHT11 sensor and 
displays live readings on a 16x2 I2C LCD, updating once per second.

## Components Used
- Arduino (Uno/Nano/similar)
- DHT11 Temperature & Humidity Sensor
- 16x2 I2C LCD Display
- Jumper wires
- Breadboard

## Libraries Required
Install via Arduino IDE: **Sketch → Include Library → Manage Libraries**
- `DHT sensor library` (Adafruit)
- `Adafruit Unified Sensor`
- `LiquidCrystal I2C`
- `Wire` (pre-installed)

## How It Works
- On startup, the LCD shows a short intro message.
- Every 1 second, the DHT11 is read and temperature (°C) and humidity (%) 
  are displayed on the LCD.
- Uses `millis()` for non-blocking timing instead of `delay()`.

## Wiring
See [docs/wiring_connections.md](docs/wiring_connections.md) for full pin connections.

## Project Images

### Setup
![Setup](images/setup_photo.jpeg)

### Live Readings
![LCD Readings](images/lcd_readings.jpeg)

## Setup Instructions
1. Wire the components as described in the wiring docs.
2. Open `code/environmental_monitor_system.ino` in Arduino IDE.
3. Install the required libraries.
4. Select your board and port under **Tools**.
5. Upload the sketch.
