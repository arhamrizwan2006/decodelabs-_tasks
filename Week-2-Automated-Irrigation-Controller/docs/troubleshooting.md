# Troubleshooting

**LCD not displaying anything**
Check I2C address — default is 0x27. Run I2C scanner sketch to confirm.

**Moisture value not changing**
Check sensor AOUT connected to A0. Ensure sensor is properly inserted in soil.

**Relay not switching**
Confirm relay IN connected to Pin 8 and relay powered via 5V not 3.3V.

**Buzzer not beeping**
Check S pin connected to Pin 7. Middle pin to 5V, minus pin to GND.

**Pump not turning on**
Check relay COM and NO terminals — pump circuit should be connected across these.