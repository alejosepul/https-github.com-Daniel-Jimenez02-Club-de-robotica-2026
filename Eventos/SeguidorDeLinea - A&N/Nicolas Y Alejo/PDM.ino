const int adelante1 = 2;
const int adelante2 = 5;
const int atras1 = 3;
const int atras2 = 4;

void setup() {
  pinMode(adelante1, OUTPUT);
  pinMode(adelante2, OUTPUT);
  pinMode(atras1, OUTPUT);
  pinMode(atras2, OUTPUT);
}

void loop() {
  digitalWrite(adelante1, 1);
  digitalWrite(adelante2, 1);
  digitalWrite(atras1, 0);
  digitalWrite(atras2, 0);
  delay(1000); //izq
  digitalWrite(adelante1, 0);
  digitalWrite(adelante2, 0);
  digitalWrite(atras1, 1);
  digitalWrite(atras2, 1);
  delay(1000); //der
  digitalWrite(adelante1, 1);
  digitalWrite(adelante2, 0);
  digitalWrite(atras1, 0);
  digitalWrite(atras2, 1);
  delay(1000); //adelante
  digitalWrite(adelante1, 0);
  digitalWrite(adelante2, 1);
  digitalWrite(atras1, 1);
  digitalWrite(atras2, 0);
  delay(1000); //atras
}
