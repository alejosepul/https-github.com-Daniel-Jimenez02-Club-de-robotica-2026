#include <SoftwareSerial.h> //incluimos la libreria para la comunicación serial

SoftwareSerial myApp(2,3);//rx-4 tx-5

char myChar ;

int rx = 2;
int tx = 3;
int m1r = 8;
int m1a = 9;
int m2a = 10;
int m2r = 11;
char dato = ' ';
//nombramos los pines

SoftwareSerial BT(rx, tx); // RX,TX

void setup() {
  Serial.begin(9600);
 myApp.begin(9600);
 Serial.println("SERIAL PC LISTO");
 myApp.println("APP LISTA#");
 
  pinMode(m1a, OUTPUT);
  pinMode(m1r, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2r, OUTPUT);
 
  //inicializamos los pines


  //inicializamos la comunicacion serial

  //se muestra la palabra "listo" cuando ya se ha inicializado la comunicación serial
  BT.begin(9600);
  // se inicializa la comunicacion serial entre el bluetooth y el arduino

  digitalWrite(m1a, LOW);
  digitalWrite(m1r, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2r, LOW);

  //se apagan los pines de los motores
}

void loop() {
   while(myApp.available()){
    myChar=myApp.read();
    Serial.print(myChar);
    myApp.print(myChar);
    myApp.print("#");
  }

  while(Serial.available()){
    myChar= Serial.read();
    myApp.print(myChar);
    myApp.print("#");
  }
  
  Serial.println(dato);
  if (BT.available()) {
    dato = BT.read();
    //Serial.println(dato);
    switch (dato) {
      case 'U':
        avanzar();
        break;
      case 'D':
        retroceder();
        break;
      case 'R':
        giro_derecha();
        break;
      case 'L':
        giro_izquierda();
        break;
    }
    }

}

void avanzar() {
  digitalWrite(m1a, HIGH);
  digitalWrite(m1r, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2r, LOW);
 Serial.println("avanzando");
}

void retroceder() {
  digitalWrite(m1a, LOW);
  digitalWrite(m1r, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2r, HIGH);
Serial.println("retrocediendo");
}

void giro_derecha() {
  digitalWrite(m1a, 0);
  digitalWrite(m1r, 1);
  digitalWrite(m2a, 1);
  digitalWrite(m2r, 0); 
Serial.println("girandod");
}

void giro_izquierda() {
  digitalWrite(m1a, 1);
  digitalWrite(m1r, 0);
  digitalWrite(m2a, 0);
  digitalWrite(m2r, 1);
Serial.println("girandoi");
}
  

  
