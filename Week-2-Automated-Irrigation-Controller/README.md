# Automated Irrigation Controller

A closed-loop irrigation system built with Arduino that automatically activates a water pump based on real-time soil moisture readings.

## How It Works

Soil moisture sensor reads analog moisture level. Arduino compares it against dry/wet thresholds and switches the relay ON/OFF accordingly. Active buzzer alerts when pump activates. LCD displays live moisture value and pump status.

## Components

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| Soil Moisture Sensor | 1 |
| 5V Relay Module | 1 |
| Active Buzzer | 1 |
| 16x2 I2C LCD (0x27) | 1 |
| Jumper Wires | — |
| Breadboard | 1 |

## Thresholds

| State | Value |
|-------|-------|
| Dry (Pump ON) | > 800 |
| Wet (Pump OFF) | < 500 |

## Libraries

- LiquidCrystal_I2C by Frank de Brabander
- Wire (built-in)

## Demo

### Startup
![Startup](images/irrigation_screen.jpeg)

### Pump ON
![ON](images/pump_on.jpeg)

### Pump OFF
![OFF](images/pump_off.jpeg)

### Video
[Watch Demo](images/demo_video.mp4)
