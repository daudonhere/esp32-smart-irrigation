# Smart Irrigation System – ESP32-Based Automated Water Control

## Project Description

This project is an implementation of a **Smart Irrigation System** using an **ESP32 microcontroller**. The system is designed to simulate automatic irrigation control based on analog sensor input (e.g., soil moisture level).

The system monitors input values from a sensor (represented by a potentiometer in this implementation) and automatically controls a **water pump (via relay)** and a **servo motor (valve control)**. The current system status is displayed on a **16x2 I2C LCD**, while LED indicators provide quick visual feedback of the pump state.

When the sensor value exceeds a predefined threshold, the system activates the pump and opens the valve. When the value is below the threshold, the pump is turned off and the valve is closed.

This project demonstrates basic **embedded automation logic** and serves as a foundation for more advanced **IoT-based smart irrigation systems**.

---

## Hardware Requirements

* ESP32 Development Board  
* Potentiometer (or Soil Moisture Sensor)  
* 16x2 LCD with I2C Interface  
* Relay Module (for water pump control)  
* Servo Motor (for valve control)  
* Red LED (Pump OFF indicator)  
* Green LED (Pump ON indicator)  
* Connecting wires and power supply  

---

## Software Requirements

* Arduino IDE  
* ESP32 Board Support Package  
* Required Libraries:
  * Wire.h  
  * LiquidCrystal_I2C.h  

---

## How to Run

### 1. Install ESP32 Board Package
Add ESP32 board support in the Arduino IDE and select the correct ESP32 board.

### 2. Install Required Libraries
Ensure the following libraries are installed:

* LiquidCrystal_I2C  
* Wire (included by default)

### 3. Upload the Code
Connect the ESP32 to your computer and upload the program using the Arduino IDE.

### 4. System Initialization and Operation

After powering on, the system performs the following operations automatically:

* Initializes the LCD display and shows the system title  
* Sets initial LED and relay states  
* Positions the servo motor to the default (closed valve) position  
* Continuously reads analog input from the sensor  
* Compares the input value against a predefined threshold  
* Activates the pump and opens the valve if the threshold is exceeded  
* Deactivates the pump and closes the valve when the value returns below the threshold  
* Displays the pump status (ON/OFF) on the LCD  

---

## System Logic

* Threshold value: 2000 (ADC reading)  
* If sensor value > 2000:
  * Pump ON  
  * Green LED ON  
  * Red LED OFF  
  * Servo moves to 90 degrees  
* If sensor value ≤ 2000:
  * Pump OFF  
  * Red LED ON  
  * Green LED OFF  
  * Servo moves to 0 degrees  

---

## Notes

* In this implementation, a potentiometer is used to simulate soil moisture levels.  
* For real-world deployment, replace the potentiometer with a calibrated soil moisture sensor.  
* Threshold values may need adjustment depending on sensor characteristics.  
* The current system operates locally without remote monitoring or data logging.  
* The project can be extended with IoT connectivity, cloud dashboards, and automated scheduling features.

---

## License

This project is intended for educational, research, and prototyping purposes.
