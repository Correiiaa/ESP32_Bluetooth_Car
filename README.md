# 🤖 Bluetooth RC Car with Collision Avoidance (ESP32)

[cite_start]This project was developed at the **University of Aveiro** [cite: 12, 45] for the Microcontrollers course. It consists of a mobile robot controlled via Bluetooth that implements safety logic to prevent frontal collisions.

## 🚀 Features
- **Remote Control:** Manual operation through the Dabble app (Gamepad module).
- **Collision Avoidance System:** Uses an ultrasonic sensor (HC-SR04) to detect obstacles within 10cm, triggering an automatic reverse maneuver.
- **PWM Motor Control:** Implementation of PWM signals (via ESP32 LEDC) for precise motor speed management.

## 🛠️ Tech Stack & Hardware
- [cite_start]**Language:** C++ (Arduino Framework) [cite: 16]
- **Microcontroller:** ESP32
- **Communication:** Bluetooth (BLE) via Dabble library
- **Sensors:** HC-SR04 Ultrasonic Sensor
- **Actuators:** DC Motors with Motor Driver (L298N)

## 📋 How It Works
The code follows a logic loop:
1. It constantly measures distance via the ultrasonic sensor.
2. If an object is detected below the `DIST_LIMIT_CM`, manual input is overridden, and the robot reverses automatically.
3. If the path is clear, the system processes Gamepad inputs for movement (Forward, Backward, Left, Right).

## 📂 Repository Structure
- `Main source code (.ino)
- `Technical reports and schematics (ProjectReport.pdf)
