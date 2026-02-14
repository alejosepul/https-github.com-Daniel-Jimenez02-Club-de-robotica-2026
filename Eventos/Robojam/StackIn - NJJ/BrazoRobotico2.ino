#include <SoftwareSerial.h>
#include <Servo.h>

// Pines para Bluetooth
#define RX_PIN 10
#define TX_PIN 11
SoftwareSerial mySerial(RX_PIN, TX_PIN);

// Declarar los servos
Servo servoGiro;
Servo servoBrazo1;
Servo servoBrazo2;
Servo servoBase;

// Variables para ángulos
int g4 = 90;
int g5 = 90;
int g6 = 90;
int g7= 90;

void setup() {
  // Asignar pines a los servos
  servoGiro.attach(4);
  servoBrazo1.attach(5);
  servoBrazo2.attach(6);
  servoBase.attach(7);

  // Posiciones iniciales
  servoGiro.write(g4);
  servoBrazo1.write(g5);
  servoBrazo2.write(g6);
  servoBase.write(g7);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // Reenviar datos si llegan al Serial
  if (Serial.available()) {
    char data = Serial.read();
    mySerial.write(data);
  }

  // Leer datos del Bluetooth
  if (mySerial.available()) {
    char data = mySerial.read();

    switch (data) {
      case 'd': // Girar a la derecha
        g4 = constrain(g4 - 3, 0, 180); // Limitar entre 0 y 180
        servoGiro.write(g4);
        Serial.println("d");
        break;

      case 'a': // Girar a la izquierda
        g4 = constrain(g4 + 3, 0, 180);
        servoGiro.write(g4);
        Serial.println("a");
        break;

      case 'w': // Subir brazo
        g5 = constrain(g5 + 3, 0, 180);
        g6 = constrain(g6 - 3, 0, 180);
        servoBrazo1.write(g5);
        servoBrazo2.write(g6);
        Serial.println("w");
        break;

      case 's': // Bajar brazo
        g5 = constrain(g5 - 3, 0, 180);
        g6 = constrain(g6 + 3, 0, 180);
        servoBrazo1.write(g5);
        servoBrazo2.write(g6);
        Serial.println("s");
        break;

      case 'p': // Parar y soltar servos
        servoGiro.detach();
        servoBrazo1.detach();
        servoBrazo2.detach();
        servoBase.detach();
        Serial.println("Servos desconectados");
        break;

      default:
        break;
    }
  }
}

