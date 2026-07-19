# 🔌 Breadboard Connections

## Float Sensor Connections

### Lower Float Sensor

| Float Sensor Pin | ESP32 Pin |
| ---------------- | --------- |
| Signal           | GPIO 18   |
| VCC              | 3.3 V     |
| GND              | GND       |

---

### Upper Float Sensor

| Float Sensor Pin | ESP32 Pin |
| ---------------- | --------- |
| Signal           | GPIO 19   |
| VCC              | 3.3 V     |
| GND              | GND       |

---

## Relay Module Connections

| Relay Pin | ESP32 Pin |
| --------- | --------- |
| IN        | GPIO 23   |
| VCC       | 5 V       |
| GND       | GND       |

---

## LED Connections

### Red LED (Pump Indicator)

| LED Terminal | ESP32 Pin                    |
| ------------ | ---------------------------- |
| Anode (+)    | GPIO 2                       |
| Cathode (−)  | GND (through 220 Ω resistor) |

---

### Green LED (Tank Full Indicator)

| LED Terminal | ESP32 Pin                    |
| ------------ | ---------------------------- |
| Anode (+)    | GPIO 4                       |
| Cathode (−)  | GND (through 220 Ω resistor) |

---

## Power Connections

| Device        | Power Source |
| ------------- | ------------ |
| ESP32         | USB / 5 V    |
| Relay Module  | 5 V          |
| Float Sensors | 3.3 V        |
| LEDs          | ESP32 GPIO   |

---

## ⚠️ Important Notes

* Use common ground for all components.
* Double-check the GPIO connections before powering the circuit.
* Keep the relay OFF during startup.
* Ensure proper insulation if using a high-voltage water pump.
* Place all components carefully on the breadboard.
