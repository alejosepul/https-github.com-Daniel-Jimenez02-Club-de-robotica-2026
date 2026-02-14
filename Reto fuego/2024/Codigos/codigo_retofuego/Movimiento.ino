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
