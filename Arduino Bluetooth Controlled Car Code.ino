#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *RMotor = AFMS.getMotor(1);
Adafruit_DCMotor *LMotor = AFMS.getMotor(2);

char Incoming_value = 0; // variable to store the incoming value from HC-05

void setup() {
  Serial.begin(9600);
  AFMS.begin();  // create with the default frequency 1.6KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
  RMotor->setSpeed(150);
  LMotor->setSpeed(150);
  RMotor->run(FORWARD);
  LMotor->run(FORWARD);

  // turn on motor
  RMotor->run(RELEASE);
  LMotor->run(RELEASE); 
}

void move_Forward(){
  RMotor->run(FORWARD);
  LMotor->run(FORWARD);
}

void move_Backward(){
  RMotor->run(BACKWARD);
  LMotor->run(BACKWARD);
}

void turnLeft(){
  RMotor->run(FORWARD);
  LMotor->run(BACKWARD);
}

void turnRight(){
  RMotor->run(BACKWARD);
  LMotor->run(FORWARD);
}

void stop(){
  RMotor->run(RELEASE);
  LMotor->run(RELEASE); 
}

void loop() {
  if (Serial.available() > 0){
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
    if (Incoming_value == '1'){
      move_Forward();
    }
    else if (Incoming_value == '2'){
      move_Backward();
    }
    else if (Incoming_value == '3'){
      turnLeft();
    }
    else if (Incoming_value == '4'){
      turnRight();
    }
    else if (Incoming_value == '0'){
      stop();
    }
  }

}
