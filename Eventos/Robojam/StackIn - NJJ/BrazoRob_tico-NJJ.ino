#include <SoftwareSerial.h>
#include <Servo.h>
#define RX_PIN 10
#define TX_PIN 11
SoftwareSerial mySerial(RX_PIN, TX_PIN);
Servo servoMotor1;
Servo servoMotor2;
Servo servoMotor3;
Servo servoMotor4;
int g4 = 0;
int g5 = 0;
int g6 = 0;
int g7 = 0;
void setup() {
servoMotor4.attach(7);
servoMotor1.write(0);
servoMotor2.write(0);
servoMotor3.write(0);
servoMotor4.write(0);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void giro() {
  servoMotor1.attach(4);
  servoMotor1.write(g4);
}
void brazo() {
  servoMotor1.attach(5);
  servoMotor1.attach(6);
  servoMotor1.write(g5);
  servoMotor1.write(g6);
}

void loop() {
  if (Serial.available()){
    char data = Serial.read();
    mySerial.write(data);
  }

  if (mySerial.available()){
    char data = mySerial.read();
    if (data == 'd'){
      g4 = g4 - 3;
      giro();
      Serial.println('d');
    } else if (data == 'a'){
      g4 = g4 + 3;
      giro();
      Serial.println('a');
    } else if (data == 'w'){
      g5 = g5 + 3;
      g6 = g6 - 3;
      brazo();
      Serial.println('w');
    } else if (data == 's'){
      g5 = g5 - 3;
      g6 = g6 + 3;
      brazo();
      Serial.println('s');
    } else if (data == 'p') {
       servoMotor1.detach();
       servoMotor2.detach();
       servoMotor3.detach();
       servoMotor4.detach();
       }      
    Serial.write(data);
  }
}
