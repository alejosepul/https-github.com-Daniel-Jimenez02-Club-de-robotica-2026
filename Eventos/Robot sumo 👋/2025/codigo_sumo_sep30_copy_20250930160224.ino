const int delIzq = 9;   //IR3
const int delDer = 8;   //IR4
const int traIzq = 11;  //IR1
const int traDer = 10;  //IR2
const int echo = 6;
const int triger = 7;
const int adelante1 = 2;  //in1
const int atras1 = 3;     //in2
const int adelante2 = 5;  //in3
const int atras2 = 4;     //in4

float tiempo = 0;
float distancia = 0;

void setup() {
  pinMode(delDer, INPUT);
  pinMode(delIzq, INPUT);
  pinMode(traDer, INPUT);
  pinMode(traIzq, INPUT);
  pinMode(echo, INPUT);
  pinMode(triger, OUTPUT);
  pinMode(adelante1, OUTPUT);
  pinMode(atras1, OUTPUT);
  pinMode(adelante2, OUTPUT);
  pinMode(atras2, OUTPUT);

  Serial.begin(9600);

  digitalWrite(adelante1, LOW);
  digitalWrite(adelante2, LOW);
  digitalWrite(atras1, LOW);
  digitalWrite(atras2, LOW);
  delay(5000);
}

void loop() {
  digitalWrite(triger, LOW);
  delayMicroseconds(4);
  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58;

  int ir1 = digitalRead(traIzq);
  int ir2 = digitalRead(traDer);
  int ir3 = digitalRead(delIzq);
  int ir4 = digitalRead(delDer);

  Serial.println(distancia);

  if (ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 0) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 1);
    analogWrite(atras2, 255 / 2);
  } else if (ir1 == 1 && ir2 == 1 && ir3 == 0 && ir4 == 1) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 0);
    analogWrite(atras1, 255 / 2);
    digitalWrite(atras2, 1);
  } else if (ir1 == 1 && ir2 == 0 && ir3 == 1 && ir4 == 1) {
    digitalWrite(adelante1, 1);
    analogWrite(adelante2, 255 / 2);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 0);
  } else if (ir1 == 0 && ir2 == 1 && ir3 == 1 && ir4 == 1) {
    analogWrite(adelante1, 255 / 2);
    digitalWrite(adelante2, 1);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 0);
  } else if (ir1 == 1 && ir2 == 1 && ir3 == 0 && ir4 == 0) {
    Serial.println("Adelante");
    digitalWrite(adelante1, 1);
    digitalWrite(adelante2, 1);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 0);
  } else if (ir1 == 0 && ir2 == 0 && ir3 == 1 && ir4 == 1) {
    Serial.println("Atras");
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 1);
    digitalWrite(atras2, 1);
  } else if (ir1 == 1 && ir2 == 0 && ir3 == 1 && ir4 == 0) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 1);
    digitalWrite(atras1, 1);
    digitalWrite(atras2, 0);
  } else if (ir1 == 0 && ir2 == 1 && ir3 == 0 && ir4 == 1) {
    digitalWrite(adelante1, 1);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 1);
  } else if (ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 1) {
    if (distancia < 30.0) {
      digitalWrite(adelante1, HIGH);
      digitalWrite(adelante2, HIGH);
      digitalWrite(atras1, LOW);
      digitalWrite(atras2, LOW);
    }
  } else {
    digitalWrite(adelante1, LOW);
    analogWrite(adelante2, 255 / 4);
    analogWrite(atras1, 255 / 4);
    digitalWrite(atras2, LOW);  
  } 
}