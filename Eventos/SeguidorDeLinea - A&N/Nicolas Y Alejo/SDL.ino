const int adelante1 = 2;
const int adelante2 = 5;
const int atras1 = 3;
const int atras2 = 4;

const int sensorI = 9;
const int sensorC = 8;
const int sensorD = 7;

int lecturaI;
int lecturaC;
int lecturaD;

int ENA = 10;   // PWM
int ENB = 11;   // PWM

char ultimoSensor = 'C'; // Valor inicial cualquiera

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(adelante1, OUTPUT);
  pinMode(adelante2, OUTPUT);
  pinMode(atras1, OUTPUT);
  pinMode(atras2, OUTPUT);

  pinMode(sensorI, INPUT);
  pinMode(sensorC, INPUT);
  pinMode(sensorD, INPUT);

  Serial.begin(9600);
}

void loop() {
  lecturaI = digitalRead(sensorI);
  lecturaC = digitalRead(sensorC);
  lecturaD = digitalRead(sensorD);

  // AVANZAR RECTO
  if (lecturaD == 0 && lecturaC == 1 && lecturaI == 0) {
    analogWrite(ENA, 128);
    analogWrite(ENB, 128);
    digitalWrite(adelante1, HIGH);
    digitalWrite(adelante2, HIGH);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    delay(5);
  }

  // GIRO A LA DERECHA
  else if (lecturaD == 1 && lecturaC == 0 && lecturaI == 0) {
    analogWrite(ENA, 64);
    analogWrite(ENB, 64);
    digitalWrite(adelante1, LOW);
    digitalWrite(adelante2, HIGH);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    ultimoSensor = 'D';
    delay(5);
  }

  // GIRO A LA IZQUIERDA
  else if (lecturaD == 0 && lecturaC == 0 && lecturaI == 1) {
    analogWrite(ENA, 64);
    analogWrite(ENB, 64);
    digitalWrite(adelante1, HIGH);
    digitalWrite(adelante2, LOW);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    ultimoSensor = 'I';
    delay(5);
  }

  // DERECHA + CENTRO (tendencia a ir a la derecha)
  else if (lecturaD == 1 && lecturaC == 1 && lecturaI == 0) {
    analogWrite(ENB, 100);
    analogWrite(ENA, 0);
    digitalWrite(adelante1, LOW);
    digitalWrite(adelante2, HIGH);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    ultimoSensor = 'D';
    delay(5);
  }

  // IZQUIERDA + CENTRO (tendencia a ir a la izquierda)
  else if (lecturaD == 0 && lecturaC == 1 && lecturaI == 1) {
    analogWrite(ENA, 100);
    analogWrite(ENB, 0);
    digitalWrite(adelante1, HIGH);
    digitalWrite(adelante2, LOW);
    digitalWrite(atras1, LOW);
    digitalWrite(atras2, LOW);
    ultimoSensor = 'I';
    delay(5);
  }

  // PERDIDA DE LÍNEA
  else if (lecturaD == 0 && lecturaC == 0 && lecturaI == 0) {
    if (ultimoSensor == 'D') {
      analogWrite(ENA, 100);
      analogWrite(ENB, 0);
      digitalWrite(adelante1, HIGH);
      digitalWrite(adelante2, LOW);
      digitalWrite(atras1, LOW);
      digitalWrite(atras2, LOW);
    } 
    else if (ultimoSensor == 'I') {
      analogWrite(ENA, 0);
      analogWrite(ENB, 100);
      digitalWrite(adelante1, LOW);
      digitalWrite(adelante2, HIGH);
      digitalWrite(atras1, LOW);
      digitalWrite(atras2, LOW);
    }
    delay(5);
  }
}
