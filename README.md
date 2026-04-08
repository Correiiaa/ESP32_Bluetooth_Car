# 🤖 Bluetooth RC Car with Collision Avoidance (ESP32)

Para facilitar a leitura, escolha o seu idioma / Select your language:
[**English**](#english) | [**Português**](#português)

---

<a name="english"></a>
## 🇺🇸 English

This project was developed at the **University of Aveiro**  for the Microcontrollers course. It consists of a mobile robot controlled via Bluetooth that implements safety logic to prevent frontal collisions.

### 🚀 Features
- **Remote Control:** Manual operation through the Dabble app (Gamepad module).
- **Collision Avoidance System:** Uses an ultrasonic sensor (HC-SR04) to detect obstacles within 10cm, triggering an automatic reverse maneuver.
- **PWM Motor Control:** Implementation of PWM signals (via ESP32 LEDC) for precise motor speed management.

### 🛠️ Tech Stack & Hardware
- **Language:** C++ (Arduino Framework) [cite: 16]
- **Microcontroller:** ESP32
- **Communication:** Bluetooth (BLE) via Dabble library
- **Sensors:** HC-SR04 Ultrasonic Sensor
- **Actuators:** DC Motors with Motor Driver (L298N)

### 📋 How It Works
The code follows a logic loop:
1. It constantly measures distance via the ultrasonic sensor.
2. If an object is detected below the `DIST_LIMIT_CM`, manual input is overridden, and the robot reverses automatically.
3. If the path is clear, the system processes Gamepad inputs for movement (Forward, Backward, Left, Right).

### 📂 Repository Structure
- `Main source code (.ino)`
- `Technical reports and schematics (ProjectReport.pdf)`

---

<a name="português"></a>
## 🇵🇹 Português

Este projeto foi desenvolvido na **Universidade de Aveiro**  no âmbito da unidade curricular de Microcontroladores. Trata-se de um robô móvel controlado via Bluetooth que utiliza lógica de segurança para evitar colisões frontais.

### 🚀 Funcionalidades
- **Controlo Remoto:** Operação manual através da aplicação Dabble (módulo Gamepad).
- **Sistema de Prevenção de Colisões:** Utiliza um sensor ultrassom (HC-SR04) para detetar obstáculos a menos de 10cm, forçando uma manobra de recuo automática.
- **Controlo de Velocidade PWM:** Implementação de sinais PWM (via LEDC no ESP32) para controlo preciso da velocidade dos motores.

### 🛠️ Tecnologias e Hardware
- **Linguagem:** C++ (Arduino Framework) [cite: 16]
- **Microcontrolador:** ESP32
- **Comunicação:** Bluetooth (BLE) via biblioteca Dabble
- **Sensores:** Sensor Ultrassónico HC-SR04
- **Atuadores:** Motores DC com Driver de Motor (L298N)

### 📋 Como Funciona
O código segue um ciclo lógico:
1. Mede constantemente a distância através do sensor ultrassónico.
2. Se um objeto for detetado abaixo do `DIST_LIMIT_CM`, o comando manual é ignorado e o robô recua automaticamente.
3. Se o caminho estiver livre, o sistema processa os inputs do Gamepad para movimentação (Frente, Trás, Esquerda, Direita).

### 📂 Estrutura do Repositório
- `Código fonte principal (.ino)`
- `Relatórios técnicos e esquemas (ProjectReport.pdf)`
