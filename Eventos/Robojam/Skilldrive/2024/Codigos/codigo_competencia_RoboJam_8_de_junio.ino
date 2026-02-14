#include "SoftwareSerial.h" //incluimos la libreria para la comunicación serial

int rx=13;
int tx=12;
int m1r=11;
int m1a=10;
int m2a=9;
int m2r=8;
int m3a=7;
int m3r=6;
int m4r=5;
int m4a=4;
//nombramos los pines

SoftwareSerial BT(rx,tx)// RX,TX

void setup() {

pinMode(m1a,OUTPUT);
pinMode(m1r,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m2r,OUTPUT);
pinMode(m3a,OUTPUT);
pinMode(m3r,OUTPUT);
pinMode(m4a,OUTPUT);
pinMode(m4r,OUTPUT);
//inicializamos los pines

Serial.begin(9600);
//inicializamos la comunicacion serial
Serial.print("listo");
//se muestra la palabra "listo" cuando ya se ha inicializado la comunicación serial
BT.begin(9600);
// se inicializa la comunicacion serial entre el bluetooth y el arduino

digitalWrite(m1a;LOW);
digitalWrite(m1r;LOW);
digitalWrite(m2a;LOW);
digitalWrite(m2r;LOW);
digitalWrite(m3a;LOW);
digitalWrite(m3a;LOW);
digitalWrite(m4a;LOW);
digitalWrite(m1a;LOW);
//se apagan los pines de los motores 
}

void loop() {

if(BT.avaliable()){
  char dato=BT.read();
  Serial.println(dato);
switch(dato){
  case 'a':
  avanzar();
  break;
  case 'r':
  retroceder();
  break;
  case 'c':
  lateral1();
  break;
  case 'b':
  lateral2();
  break;
  case 'p':
  parar();
  break;
  case 'd':
  diagadel1();
  break;
  case 'e':
  diagadel2();
  break;
  case 'g':
  diag1atras1();
  break;
  case 'f':
  diag1atra2();
  break;
  case 'o':
  giroizquierda();
  break;
  case 'q':
  giroderecha();
  break;
 
  }
 }
}

void parar(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2r,LOW);
digitalWrite(m3a,LOW);
digitalWrite(m3r,LOW);
digitalWrite(m4a,LOW);
digitalWrite(m4r,LOW);  
}

void avanzar(){
digitalWrite(m1a,HIGH);
digitalWrite(m1r,LOW);
digitalWrite(m2a,HIGH);
digitalWrite(m2r,LOW);
digitalWrite(m3a,HIGH);
digitalWrite(m3r,LOW);
digitalWrite(m4a,HIGH);
digitalWrite(m4r,LOW);  
}

void retroceder(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,HIGH);
digitalWrite(m2a,LOW);
digitalWrite(m2r,HIGH);
digitalWrite(m3a,LOW);
digitalWrite(m3r,HIGH);
digitalWrite(m4a,LOW);
digitalWrite(m4r,HIGH);  
}

void lateral1(){
digitalWrite(m1a,HIGH);
digitalWrite(m1r,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2r,HIGH);
digitalWrite(m3a,LOW);
digitalWrite(m3r,HIGH);
digitalWrite(m4a,HIGH);
digitalWrite(m4r,LOW);  
}

void lateral2(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,HIGH);
digitalWrite(m2a,HIGH);
digitalWrite(m2r,LOW);
digitalWrite(m3a,HIGH);
digitalWrite(m3r,LOW);
digitalWrite(m4a,LOW);
digitalWrite(m4r,HIGH);  
}

void diagadel1(){
digitalWrite(m1a,HIGH);
digitalWrite(m1r,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2r,LOW);
digitalWrite(m3a,LOW);
digitalWrite(m3r,LOW);
digitalWrite(m4a,HIGH);
digitalWrite(m4r,LOW);  
}

void diagadel2(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,LOW);
digitalWrite(m2a,HIGH);
digitalWrite(m2r,LOW);
digitalWrite(m3a,HIGH);
digitalWrite(m3r,LOW);
digitalWrite(m4a,LOW);
digitalWrite(m4r,LOW);  
}

void diad1atras1(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,HIGH);
digitalWrite(m2a,LOW);
digitalWrite(m2r,LOW);
digitalWrite(m3a,LOW);
digitalWrite(m3r,LOW);
digitalWrite(m4a,LOW);
digitalWrite(m4r,HIGH);  
}

void diag1atras2(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2r,HIGH);
digitalWrite(m3a,LOW);
digitalWrite(m3r,HIGH);
digitalWrite(m4a,LOW);
digitalWrite(m4r,LOW);  
}

void giroderecha(){
digitalWrite(m1a,HIGH);
digitalWrite(m1r,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2r,HIGH);
digitalWrite(m3a,HIGH);
digitalWrite(m3r,LOW);
digitalWrite(m4a,LOW);
digitalWrite(m4r,HIGH);  
}

void giroizquierda(){
digitalWrite(m1a,LOW);
digitalWrite(m1r,HIGH);
digitalWrite(m2a,HIGH);
digitalWrite(m2r,LOW);
digitalWrite(m3a,LOW);
digitalWrite(m3r,HIGH);
digitalWrite(m4a,HIGH);
digitalWrite(m4r,LOW);  
}
