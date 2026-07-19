# 💧 Smart Water Tank System using ESP32

## 📌 Overview

The Smart Water Tank System is an automated water-level monitoring and pump-control project developed using an ESP32 microcontroller, float sensors, and a relay module.

The system automatically switches the water pump ON when the tank level falls below the minimum threshold and turns it OFF once the tank becomes full.

This project reduces manual effort, prevents water wastage, and protects the pump from unnecessary operation.

---

## ✨ Features

* Automatic water-level monitoring.
* Automatic pump ON/OFF control.
* LED indicators for system status.
* Relay-based pump switching.
* Sensor debouncing for stable operation.
* Serial monitor debugging support.

---

## ⚙️ Working Principle

### Tank Empty Condition

When the water level falls below both float sensors:

* Pump turns ON.
* Red LED glows.
* Green LED remains OFF.

### Tank Full Condition

When the upper float sensor detects water:

* Pump turns OFF.
* Red LED turns OFF.
* Green LED glows.

---

## 🧠 Logic Used

The system uses:

* Two float sensors.
* Internal pull-up resistors (`INPUT_PULLUP`).
* Relay switching.
* A Boolean state variable:

```cpp
bool isPumpRunning = false;
```

Sensor states:

```text
HIGH → Water level below the sensor.

LOW → Water has reached the sensor.
```

---

## 📟 Serial Output

```text
SMART WATER TANK SYSTEM IS NOW LIVE
```

```text
[STATUS] -> Water level is low! Turning ON the pump.
```

```text
[STATUS] -> Tank FULL! Pump turned OFF.
```

---

## 📂 Repository Structure

```text
Smart-Water-Tank-System/

├── README.md
├── COMPONENTS_USED.md
├── CONNECTIONS.md
├── Smart_Water_Tank_System.ino
└── images/
```

---

## 🚀 Future Improvements

* IoT integration.
* Mobile application support.
* LCD/OLED display.
* Water-level percentage indicator.
* Cloud monitoring.

---

## 👨‍💻 Author

**Anendra Narayan Dixit**

B.Tech Electrical Engineering

Central University of Karnataka

---

## 📜 License

This project is open-source and available under the MIT License.
