//Nombramos los pines a utilizar.
//Pines para los sensores de infrarrojo
#define delIzq 22  //IR delantero izquierdo
#define delDer 23  //IR delantero derecha
#define traIzq 24  //IR trasero izquierdo
#define traDer 25  //IR trasero derecho

#define flama1 A4
#define flama2 A5
#define flama3 A6
#define flama4 A7
#define flama5 A8

// pines y variables para ultrasonidos
float tiempo = 0;
float distancia1 = 0; // distancia1 ultrasonido 1
float distancia2 = 0; // distancia2 ultrasonido 2
float distancia3 = 0; // distancia3 ultrasonido 3

#define echo1 6  // echo ultrasonido #1
#define trig1 7  // trigger ultrasonido #1

#define echo2 4  // echo ultrasonido #2
#define trig2 5  // trigger ultrasonido #2

#define echo3 2  // echo ultrasonido #3
#define trig3 3  // trigger ultrasonido #3

//Pines para puente H (motor A - Motor B) inA = atras- inB = adelante- inC = atras- inD = adelante
#define inA 8   //in1
#define inB 9   //in2
#define inC 10  //in3
#define inD 11  //in4

//variables para leer los sensores de linea
int DI = 0;
int DD = 0;
int TI = 0;
int TD = 0;

//variables para leer los sensores de flama
int val1;
int val2;
int val3;
int val4;
int val5;

//pines para PWM
int PWM1 = 13;
int PWM2 = 12;
int v1 = 200;
int v2 = 200;

void Adelante () {
  //Prueba Serial.println("At");
  digitalWrite (inA, HIGH);
  digitalWrite (inB, LOW);
  digitalWrite (inC, HIGH);
  digitalWrite (inD, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(flama1, INPUT);
  pinMode(flama2, INPUT);
  pinMode(flama3, INPUT);
  pinMode(flama4, INPUT);
  pinMode(flama5, INPUT);
  pinMode(delIzq, INPUT);
  pinMode(delDer, INPUT);
  pinMode(traIzq, INPUT);
  pinMode(traDer, INPUT);
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  // funcion de pines de ultrasonido
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
}

void loop() {
  // ultrasonido 1
digitalWrite(trig1,LOW);
delayMicroseconds(4);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);

tiempo=pulseIn(echo1,HIGH);
distancia1=tiempo/58;      //Lugar donde se almacena la distancia medida en cm

// ultrasonido 2
digitalWrite(trig2,LOW);
delayMicroseconds(4);
digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);

tiempo=pulseIn(echo2,HIGH);
distancia2=tiempo/58;      //Lugar donde se almacena la distancia medida en cm

//ultrasonido 3
digitalWrite(trig3,LOW);
delayMicroseconds(4);
digitalWrite(trig3,HIGH);
delayMicroseconds(10);
digitalWrite(trig3,LOW);

tiempo=pulseIn(echo3,HIGH);
distancia3=tiempo/58;      //Lugar donde se almacena la distancia medida en cm

Serial.print("Dis1 es:");
Serial.print(distancia1);
Serial.print(" | Dis2 es:");
Serial.print(distancia2);
Serial.print(" | Dis3 es:");
Serial.println(distancia3);
 
  // se lee los valores de los sensores de linea
  DI = digitalRead(delIzq);
  DD = digitalRead(delDer);
  TI = digitalRead(traIzq);
  TD = digitalRead(traDer);

  //se lee el valoe de los sensores de flama
  val1 = analogRead(flama1);
  val2 = analogRead(flama2);
  val3 = analogRead(flama3);
  val4 = analogRead(flama4);
  val5 = analogRead(flama5);

if (distancia2 > 10.0) {

  if (DI == 1 || DD == 1 || TI == 1 || TD == 1) {
  digitalWrite (inA, HIGH);
  analogWrite  (PWM1, v1);
  digitalWrite (inB, LOW);
  digitalWrite (inC, HIGH);
  analogWrite  (PWM2, v2);
  digitalWrite (inD, LOW);
    if (val1 > 200) {
      Parar();
      delay(500);
      Izquierda();
      delay(1000);
    }
    if (val3 > 200) {
      Parar();
      delay(500);
      Derecha();
      delay(1000);
    }
  }
}
else if (distancia2 < 10.0){
  Atras();
  delay(500);
  Izquierda();
}
   if (DI == 0 || DD == 0 || TI == 0 || TD == 0) {
    Atras();
    delay(800);
    Derecha();
    delay(1000);
   }
}

//Definición de funciones-----------------------------------------/
void Atras () {
  //Prueba Serial.println("Ad");
  digitalWrite (inA, LOW);
  digitalWrite (inB, HIGH);
  analogWrite  (PWM1, v1);
  digitalWrite (inC, LOW);
  digitalWrite (inD, HIGH);
  analogWrite  (PWM2, v2);
}

/*void Adelante () {
  //Prueba Serial.println("At");
  digitalWrite (inA, HIGH);
  digitalWrite (inB, LOW);
  digitalWrite (inC, HIGH);
  digitalWrite (inD, LOW);
}*/

void Derecha () {
  //Prueba Serial.println("Dr");
  digitalWrite (inA, HIGH);
  digitalWrite (inB, LOW);
  analogWrite  (PWM1, v1);
  digitalWrite (inC, LOW);
  digitalWrite (inD, HIGH);
  analogWrite  (PWM2, v2);
}

void Izquierda () {
  //Prueba Serial.println("Iz");
  digitalWrite (inA, LOW);
  digitalWrite (inB, HIGH);
  analogWrite  (PWM1, v1);
  digitalWrite (inC, HIGH);
  digitalWrite (inD, LOW);
  analogWrite  (PWM2, v2);
}

void Parar () {
  //Prueba Serial.println("St");
  digitalWrite (inA, LOW);
  digitalWrite (inB, LOW);
  digitalWrite (inC, LOW);
  digitalWrite (inD, LOW);
}

void ProbarSenFuego() {
  Serial.print("Sen1= ");
  Serial.print(val1);
  Serial.print("| Sen2= ");
  Serial.print(val2);
  Serial.print("| Sen3= ");
  Serial.print(val3);
  Serial.print("| Sen4= ");
  Serial.print(val4);
  Serial.print("| Sen5= ");
  Serial.println(val5);
}

