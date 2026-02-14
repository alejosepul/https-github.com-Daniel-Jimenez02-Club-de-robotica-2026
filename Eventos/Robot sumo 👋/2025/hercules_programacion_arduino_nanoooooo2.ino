#define delIzq 11  //IR delantero izquierdo
#define delDer 10  //IR delantero derecha
#define traIzq 9  //IR trasero izquierdo
#define traDer 8  //IR trasero derecho

#define echo 6
#define triger 7

#define adelante1 2  //in1
#define atras1 3     //in2
#define adelante2 5  //in3
#define atras2 4     //in4

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
  int ir1 = digitalRead(delIzq);      //Delantero izquierda
  int ir2 = digitalRead(delDer);      //Delantero derecha
  int ir3 = digitalRead(traIzq);      //Trasero izquierda
  int ir4 = digitalRead(traDer);      //Trasero derecha
  digitalWrite(triger, LOW);
  delayMicroseconds(4);
  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);

  tiempo = pulseIn(echo, HIGH);
    distancia = tiempo / 58;  
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

  Serial.print("IR Delantero Izq: ");
  Serial.println(ir1);
  Serial.print("IR Delantero Der: ");
  Serial.println(ir2);
  Serial.print("IR Trasero Izq: ");
  Serial.println(ir3);
  Serial.print("IR Trasero Der: ");
  Serial.println(ir4);
  if (ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 1) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 255/2);
    digitalWrite(atras2, 1);
    delay(700); 
  }
  else if (ir1 == 0 && ir2 == 0 && ir3 == 1 && ir4 == 0) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 1);
    digitalWrite(atras2, 255/2);
    delay(700); 
  }
  else if (ir1 == 0 && ir2 == 1 && ir3 == 0 && ir4 == 0) {
    digitalWrite(adelante1, 255/2);
    digitalWrite(adelante2, 1);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 0);
    delay(700); 
  }
  else if (ir1 == 1 && ir2 == 0 && ir3 == 0 && ir4 == 0) {
    digitalWrite(adelante1, 1);
    digitalWrite(adelante2, 255/2);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 0);
    delay(700); 
  }
  else if (ir1 == 1 && ir2 == 1 && ir3 == 0 && ir4 == 0) {
    digitalWrite(adelante1, 1);
    digitalWrite(adelante2, 1);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 0);
    delay(700); 
  }
  else if (ir1 == 0 && ir2 == 0 && ir3 == 1 && ir4 == 1) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 1);
    digitalWrite(atras2, 1);
    delay(700);
  }
  else if (ir1 == 1 && ir2 == 0 && ir3 == 1 && ir4 == 0) {
    digitalWrite(adelante1, 0);
    digitalWrite(adelante2, 1);
    digitalWrite(atras1, 1);
    digitalWrite(atras2, 0);
    delay(700);
  }
  else if (ir1 == 0 && ir2 == 1 && ir3 == 0 && ir4 == 1) {
    digitalWrite(adelante1, 1);
    digitalWrite(adelante2, 0);
    digitalWrite(atras1, 0);
    digitalWrite(atras2, 1);
    delay(700);
  }  else if (ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 1) {
          if (distancia < 30.0) {
            if (distancia < 3.0) {
              digitalWrite(adelante1, HIGH);
              digitalWrite(adelante2, HIGH);
              digitalWrite(atras1, LOW); 
              digitalWrite(atras2, LOW);
              delay(100);               
            } else {
              digitalWrite(adelante1, 255/2);
              digitalWrite(adelante2, 255/2);
              digitalWrite(atras1, LOW);
              digitalWrite(atras2, LOW);
              delay(100);
            }
      } else {
        digitalWrite(adelante1, LOW);
        analogWrite(adelante2, 255 / 4);
        analogWrite(atras1, 255 / 4);
        digitalWrite(atras2, LOW);
        delay(100); 
      }
  } else {
      digitalWrite(adelante1, LOW);
        analogWrite(adelante2, 255 / 4);
        analogWrite(atras1, 255 / 4);
        digitalWrite(atras2, LOW);
        delay(100);
  }
   delay(50);
}
