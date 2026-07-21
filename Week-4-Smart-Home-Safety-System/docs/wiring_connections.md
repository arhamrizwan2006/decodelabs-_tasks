# Wiring Connections

## Power
- Powered via USB from PC (5V, no external battery used for this build)

## PIR Motion Sensor (HC-SR501)
| PIR Pin | Uno Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | D2 (hardware interrupt pin) |

## MQ-2 Gas/Smoke Sensor
| MQ-2 Pin | Uno Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| AO | A0 |
| DO | not used |

## 5V Relay Module
**Logic side:**
| Relay Pin | Uno Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| IN | D4 |
| JD-VCC | jumper removed (opto-isolation) |

**Switched side (screw terminals):**
| Terminal | Connects to |
|---|---|
| COM | 5V |
| NO | (load, if attached) |
| NC | not used |

## Active Buzzer
| Buzzer Pin | Uno Pin |
|---|---|
| S (signal) | D3 |
| VCC | 5V |
| GND | GND |

## Red LED
| LED | Connects to |
|---|---|
| Anode (long leg) | D5, via 220Ω resistor |
| Cathode (short leg) | GND |

## I2C LCD 16x2
| LCD Pin | Uno Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## Full Pin Summary
| Uno Pin | Connected Component |
|---|---|
| D2 | PIR OUT (interrupt) |
| D3 | Buzzer signal |
| D4 | Relay IN |
| D5 | Red LED (via resistor) |
| A0 | MQ-2 AO |
| A4 | LCD SDA |
| A5 | LCD SCL |
| 5V | PIR, MQ-2, Relay VCC/COM, LCD VCC |
| GND | Shared ground across all components |