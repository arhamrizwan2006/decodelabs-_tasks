# Troubleshooting Notes

## PIR sensor not detecting motion / inconsistent triggering
- **Warm-up required**: PIR needs 30-60 seconds after power-on to calibrate 
  to ambient IR. Ignore readings during this window.
- **Trigger distance/angle**: move laterally across the sensor's field of 
  view rather than straight toward it — PIR detects *change* in infrared, 
  not simple presence.
- **Sensitivity knob**: if turned too low, effective range shrinks 
  drastically. Set to a moderate/mid position, not maxed (max sensitivity 
  can cause false triggers from ambient heat sources instead).
- **Time delay knob**: controls how long OUT stays HIGH after a trigger. 
  If turned fully counter-clockwise, hold time can be as short as ~1-3 
  seconds, making triggers seem to "barely register." Turn clockwise for 
  a longer, more observable hold time.
- **Trigger mode jumper** (if present): single-trigger mode won't re-fire 
  until its current hold cycle fully expires, which can look like random 
  missed triggers. Repeatable-trigger mode re-fires continuously during 
  ongoing motion.

## Interrupt not firing / motionFlag never set
- Confirm PIR OUT is wired to **D2 or D3 only** — these are the only 
  hardware interrupt pins on Uno.
- Isolate with a minimal test sketch (PIR → pin 13 onboard LED) to confirm 
  hardware/interrupt wiring independent of the rest of the sketch.

## Relay not clicking despite motionFlag confirmed working
- Confirm relay IN, VCC, and GND are all firmly connected — these can be 
  knocked loose during unrelated wiring changes elsewhere on the breadboard.
- Test the relay pin directly and in isolation (bypassing PIR/interrupt 
  logic entirely) to confirm the relay and pin itself are functional.

## System stuck in "FAULT LOCK" unexpectedly
- Check `gasThreshold` against your sensor's actual clean-air baseline 
  reading. If the threshold is set too close to baseline, normal ambient 
  drift can cross it and trigger a false lockdown.
- Remember: the lockdown is intentionally permanent by design — a reset 
  (power cycle or reset button) is required to clear it, this is not a bug.

## LCD text corrupting / garbled characters
- Usually caused by voltage sag (brownout) when a high-current component 
  (e.g. a motor via the relay) switches on simultaneously with I2C 
  communication. 
- Fix: use a proper external power source (e.g. battery pack via VIN) 
  instead of USB alone when driving higher-current loads, since USB has a 
  limited current budget (~500mA).

## LED dims / onboard LED flickers erratically during relay switching
- Same root cause as LCD corruption above — insufficient/unstable power 
  supply under load. Not a code issue; indicates the power source needs 
  to be upgraded for the attached load.

## Buzzer silent despite correct code and pin
- Check if the buzzer module has 3 pins (S / middle VCC / -) rather than 
  just 2 legs. A 3-pin active buzzer module needs its own VCC connection 
  separate from the signal pin — missing VCC results in total silence 
  even with correct signal wiring.