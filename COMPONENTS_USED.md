# 🛠 Components Used

The following components were used to build the Smart Water Tank System.

| Component               | Quantity    |
| ----------------------- | ----------- |
| ESP32 Development Board | 1           |
| Float Sensors           | 2           |
| Relay Module            | 1           |
| Water Pump              | 1           |
| Red LED                 | 1           |
| Green LED               | 1           |
| 220 Ω Resistors         | 2           |
| Breadboard              | 1           |
| Jumper Wires            | As required |
| USB Cable               | 1           |
| External Power Supply   | 1           |

---

## 📋 Component Description

### ESP32 Development Board

The ESP32 acts as the brain of the project. It reads the float sensors and controls the relay and LEDs.

### Float Sensors

Two float sensors are used:

* Lower float sensor detects low water level.
* Upper float sensor detects the full tank condition.

### Relay Module

The relay acts as an electronic switch to control the water pump.

### LEDs

* Red LED indicates that the pump is running.
* Green LED indicates that the tank is full.

### Water Pump

The pump fills the water tank automatically whenever the water level becomes low.
