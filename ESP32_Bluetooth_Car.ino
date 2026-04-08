#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

const int trigPin = 26;
const int echoPin = 25;

//Right motor
int enableRightMotor=22; 
int rightMotorPin1=12;
int rightMotorPin2=13;
//Left motor
int enableLeftMotor=23;
int leftMotorPin1=18;
int leftMotorPin2=19;

#define MAX_MOTOR_SPEED 255
#define DIST_LIMIT_CM 10 // distância mínima para reagir

const int PWMFreq = 1000;
const int PWMResolution = 8;
const int rightMotorChannel = 4;
const int leftMotorChannel = 5;

void setupMotorPins() {
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  ledcSetup(rightMotorChannel, PWMFreq, PWMResolution);
  ledcSetup(leftMotorChannel, PWMFreq, PWMResolution);
  ledcAttachPin(enableRightMotor, rightMotorChannel);
  ledcAttachPin(enableLeftMotor, leftMotorChannel);

  controlMotors(0, 0);
}

void controlMotors(int rightSpeed, int leftSpeed) {
  // Motor direito
  digitalWrite(rightMotorPin1, rightSpeed > 0);
  digitalWrite(rightMotorPin2, rightSpeed < 0);

  // Motor esquerdo
  digitalWrite(leftMotorPin1, leftSpeed > 0);
  digitalWrite(leftMotorPin2, leftSpeed < 0);

  ledcWrite(rightMotorChannel, abs(rightSpeed));
  ledcWrite(leftMotorChannel, abs(leftSpeed));
}

float getDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000); // timeout: 20 ms
  float distance = duration * 0.0343 / 2.0;
  return distance;
}

void setup() {
  setupMotorPins();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Dabble.begin("CARROdoTONI");
}

void loop() {
  float distance = getDistanceCM();
  Dabble.processInput();

  if (distance > 0 && distance < DIST_LIMIT_CM) {
    // Muito perto, recuar
    controlMotors(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
    delay(500); // anda para trás 0.5 s
    controlMotors(0, 0);
    return;
  }

  // Controlo manual via Gamepad
  int rightSpeed = 0;
  int leftSpeed = 0;

  if (GamePad.isDownPressed()) {
    rightSpeed = -MAX_MOTOR_SPEED;
    leftSpeed = MAX_MOTOR_SPEED;
  }
  if (GamePad.isUpPressed()) {
    rightSpeed = MAX_MOTOR_SPEED;
    leftSpeed = -MAX_MOTOR_SPEED;
  }
  if (GamePad.isRightPressed()) {
    rightSpeed = MAX_MOTOR_SPEED;
    leftSpeed = MAX_MOTOR_SPEED;
  }
  if (GamePad.isLeftPressed()) {
    rightSpeed = -MAX_MOTOR_SPEED;
    leftSpeed = -MAX_MOTOR_SPEED;
  }

  controlMotors(rightSpeed, leftSpeed);
}
