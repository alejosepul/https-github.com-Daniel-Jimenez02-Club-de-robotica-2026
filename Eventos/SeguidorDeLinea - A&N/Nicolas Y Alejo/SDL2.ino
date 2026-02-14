const int adelante1 = 2;
const int adelante2 = 5;
const int atras1 = 3;
const int atras2 = 4;
const int sensorI = 9;
const int sensorD = 7;
int lecturaI;
int lecturaD;
int ENA = 10;
int ENB = 11;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(adelante1, OUTPUT);
  pinMode(adelante2, OUTPUT);
  pinMode(atras1, OUTPUT);
  pinMode(atras2, OUTPUT);
  pinMode(sensorI, INPUT);
  pinMode(sensorD, INPUT);
  Serial.begin(9600);
  delay(200);
}

void loop() {
  lecturaI = digitalRead(sensorI);
  lecturaD = digitalRead(sensorD);
  if (lecturaD == 1) {
    analogWrite(ENB, 140);
    analogWrite(ENA, 0);
    digitalWrite(adelante1, HIGH);
    digitalWrite(adelante2, HIGH);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    Serial.println("Izq");
    delay(30);
  } else if (lecturaI == 1) {
    analogWrite(ENB, 0);
    analogWrite(ENA, 160);
    digitalWrite(adelante1, HIGH);
    digitalWrite(adelante2, HIGH);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    Serial.println("Der");
    delay(30);
  } else {
    analogWrite(ENB, 215);
    analogWrite(ENA, 235);
    digitalWrite(adelante1, HIGH);
    digitalWrite(adelante2, HIGH);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    Serial.println("AVANZA");
  } 
  delay(5);
}
