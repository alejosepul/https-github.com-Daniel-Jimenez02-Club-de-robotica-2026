#include <SoftwareSerial.h>   // Incluimos la librería SoftwareSerial  
SoftwareSerial BT(10, 11);    // Pines RX y TX conectados al módulo Bluetooth


const int DerA = 2;
const int DerB = 4;
const int IzqA = 5;
const int IzqB = 6;
const int DerC = 7;
const int DerD = 3;
const int IzqC = 13;
const int IzqD = 12;
char dato = digitalRead(10);
int pwm1=255;
int en1=9;
int en2=8;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  analogWrite(en1,pwm1);
  analogWrite(en2,pwm1);
  pinMode(DerA, OUTPUT);
  pinMode(DerB, OUTPUT);
  pinMode(IzqA, OUTPUT);
  pinMode(IzqB, OUTPUT);
  pinMode(IzqC, OUTPUT);
  pinMode(IzqD, OUTPUT);
  pinMode(DerC, OUTPUT);
  pinMode(DerD, OUTPUT);
}

void loop() {
  // Comunicación bidireccional entre Bluetooth y Monitor Serial
  if (BT.available()) 
    char dato = BT.read();
    Serial.write(dato);
    procesarDato();
  }


void procesarDato() {
  if (dato == 'a') {
    Mover_Adelante();
    
  } else if (dato == 'b') {
    Mover_Retroceso();
   
  } else if (dato == 'd') {
    Mover_Derecha();
   
  } else if (dato == 'i') {
    Mover_Izquierda();
    
  }
}

// Funciones de movimiento
void Mover_Adelante() {
  digitalWrite(DerA, HIGH);
  digitalWrite(DerB, LOW);
  digitalWrite(IzqA, HIGH);
  digitalWrite(IzqB, LOW);
  digitalWrite(DerC, HIGH);
  digitalWrite(DerD, LOW);
  digitalWrite(IzqC, HIGH);
  digitalWrite(IzqD, LOW);
}

void Mover_Retroceso() {
  digitalWrite(DerA, LOW);
  digitalWrite(DerB, HIGH);
  digitalWrite(IzqA, LOW);
  digitalWrite(IzqB, HIGH);
  digitalWrite(DerC, LOW);
  digitalWrite(DerD, HIGH);
  digitalWrite(IzqC, LOW);
  digitalWrite(IzqD, HIGH); 
}

void Mover_Derecha() {
  digitalWrite(DerA, LOW);
  digitalWrite(DerB, HIGH);
  digitalWrite(IzqA, HIGH);
  digitalWrite(IzqB, LOW);
  digitalWrite(DerC, LOW);
  digitalWrite(DerD, HIGH);
  digitalWrite(IzqC, HIGH);
  digitalWrite(IzqD, LOW);
}

void Mover_Izquierda() {
  digitalWrite(DerA, HIGH);
  digitalWrite(DerB, LOW);
  digitalWrite(IzqA, LOW);
  digitalWrite(IzqB, HIGH);
  digitalWrite(DerC, HIGH);
  digitalWrite(DerD, LOW);
  digitalWrite(IzqC, LOW);
  digitalWrite(IzqD, HIGH);
}

void Mover_Stop() {
  digitalWrite(DerA, LOW);
  digitalWrite(DerB, LOW);
  digitalWrite(IzqA, LOW);
  digitalWrite(IzqB, LOW);
  digitalWrite(DerC, LOW);
  digitalWrite(DerD, LOW);
  digitalWrite(IzqC, LOW);
  digitalWrite(IzqD, LOW);
}
