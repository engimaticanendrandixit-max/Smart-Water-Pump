// ====================================================================
// SMART WATER TANK SYSTEM 
// Pins are to be blaced on breadboard carefully
// ====================================================================

// Float Sensors (Inputs with Internal Pullup)
const int LOW_SENSOR_PIN = 18;  // Low Float Sensor (Pin 18)
const int HIGH_SENSOR_PIN = 19; // Upper Float Sensor (Pin 19)

// Actuator (Output)
const int RELAY_PIN = 23;       // Relay Module (Pin 23)

// LED Indicators (For Outputs)
const int RED_LED_PIN = 2;      // Pump ON Indicator (Pin D2)
const int GREEN_LED_PIN = 4;    // Tank FULL Indicator (Pin D4)

// State tracking variable
bool isPumpRunning = false;

void setup() {
  // Serial Monitor for Debugging
  Serial.begin(115200);
  
  // Configuring Sensor Pins with Internal Pullup Resistors
  pinMode(LOW_SENSOR_PIN, INPUT_PULLUP);
  pinMode(HIGH_SENSOR_PIN, INPUT_PULLUP);
  
  // Configuring Output Pins
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  // Keep everything OFF at boot time for safety
  digitalWrite(RELAY_PIN, LOW); 
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  
  Serial.println("\n=========================================");
  Serial.println("   SMART WATER TANK SYSTEM IS NOW LIVE   ");
  Serial.println("=========================================");
}

void loop() {
  // Reading current state of sensors
  // HIGH = Float ring is DOWN (Water level below sensor)
  // LOW  = Float ring is UP   (Water level lifted the sensor)
  int lowSensor = digitalRead(LOW_SENSOR_PIN);
  int highSensor = digitalRead(HIGH_SENSOR_PIN);

  // LOGIC 1: When Tank is Empty (Both Float sensors at bottom) -> Start Pump, Red LED ON
  if (lowSensor == HIGH && highSensor == HIGH && !isPumpRunning) {
    delay(200); // Noise filter karne ke liye small debounce delay
    if (digitalRead(LOW_SENSOR_PIN) == HIGH) { 
      digitalWrite(RELAY_PIN, HIGH);     // Relay ON (Pump Chalu)
      digitalWrite(RED_LED_PIN, HIGH);   // Red LED ON
      digitalWrite(GREEN_LED_PIN, LOW);  // Green LED OFF
      isPumpRunning = true;
      Serial.println("[STATUS] -> Water is low !Turning on the Pump");
    }
  }

  // LOGIC 2: Tank Full (When both float sensors comes up) -> It Stops Pump then turns the Green LED ON
  if (highSensor == LOW && isPumpRunning) {
    delay(200); // Noise filter karne ke liye small debounce delay
    if (digitalRead(HIGH_SENSOR_PIN) == LOW) {
      digitalWrite(RELAY_PIN, LOW);       // Relay OFF (Pump Band)
      digitalWrite(RED_LED_PIN, LOW);     // Red LED OFF
      digitalWrite(GREEN_LED_PIN, HIGH);  // Green LED ON (Tank Full Alert)
      isPumpRunning = false;
      Serial.println("[STATUS] -> Tanki FULL! Pump turned OFF.");
    }
  }

  delay(500); // 0.5-second checking cycle loop
}