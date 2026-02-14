#include <SoftwareSerial.h>   // Incluimos la librería SoftwareSerial  
SoftwareSerial BT(10, 11);    // Pines RX y TX conectados al módulo Bluetooth

const int DerA = 3;
const int DerB = 4;
const int IzqA = 5;
const int IzqB = 6;

int tiempo = 0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  
  pinMode(DerA, OUTPUT);
  pinMode(DerB, OUTPUT);
  pinMode(IzqA, OUTPUT);
  pinMode(IzqB, OUTPUT);
}

void loop() {
  // Comunicación bidireccional entre Bluetooth y Monitor Serial
  if (BT.available()) {
    char dato = BT.read();
    Serial.write(dato);
    procesarDato(dato);
  }

  if (Serial.available()) {
    char dato = Serial.read();
    BT.write(dato);
    procesarDato(dato);
  }

  if (tiempo < 400) {
    tiempo++;
  } else {
    Mover_Stop();
  }

  delay(1);
}

void procesarDato(char dato) {
  if (dato == 'a') {
    Mover_Adelante();
    tiempo = 0;
  } else if (dato == 'b') {
    Mover_Retroceso();
    tiempo = 0;
  } else if (dato == 'd') {
    Mover_Derecha();
    tiempo = 0;
  } else if (dato == 'i') {
    Mover_Izquierda();
    tiempo = 0;
  }
}

// Funciones de movimiento
void Mover_Adelante() {
  digitalWrite(DerA, HIGH);
  digitalWrite(DerB, LOW);
  digitalWrite(IzqA, HIGH);
  digitalWrite(IzqB, LOW);
}

void Mover_Retroceso() {
  digitalWrite(DerA, LOW);
  digitalWrite(DerB, HIGH);
  digitalWrite(IzqA, LOW);
  digitalWrite(IzqB, HIGH);
}

void Mover_Derecha() {
  digitalWrite(DerA, LOW);
  digitalWrite(DerB, HIGH);
  digitalWrite(IzqA, HIGH);
  digitalWrite(IzqB, LOW);
}

void Mover_Izquierda() {
  digitalWrite(DerA, HIGH);
  digitalWrite(DerB, LOW);
  digitalWrite(IzqA, LOW);
  digitalWrite(IzqB, HIGH);
}

void Mover_Stop() {
  digitalWrite(DerA, LOW);
  digitalWrite(DerB, LOW);
  digitalWrite(IzqA, LOW);
  digitalWrite(IzqB, LOW);
}
