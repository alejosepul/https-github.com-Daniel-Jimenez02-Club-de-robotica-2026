const int echo = 7; //echo del ultrasonido
const int trig = 8; //trigger del ultrasonido
const int sen1 = 2; //sensor 1 de color del carro
const int sen2 = 6; //sensor 2 de color del carro
const int sen3 = 4; //sensor 3 de color del carro
const int sen4 = 3; //sensor 4 de color del carro
const int MotorIzqAtras = 5; //Motor izquierdo para mover atras del carro
const int MotorIzqAdelante = 13; //Motor izquierdo para mover adelante del carro
const int MotorDerAdelante = 12; //Motor derecho para mover adelante del carro
const int MotorDerAtras = 9; //Motor deredcho para mover atras del carro
const int ENA = 10; //ENA
float distancia = 0; //Variable de la distancia del ultrasonido
const int ENB = 11; //ENB

const int espera = 500;

void adelante(){ //Mover adelante
    analogWrite(ENA, 220);
    analogWrite(ENB, 220);
    digitalWrite(MotorDerAtras,0);
    digitalWrite(MotorDerAdelante,1);
    digitalWrite(MotorIzqAtras,0);
    digitalWrite(MotorIzqAdelante,1);
}
void atras(){ //Mover atras
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(MotorDerAtras,1);
    digitalWrite(MotorDerAdelante,0);
    digitalWrite(MotorIzqAtras,1);
    digitalWrite(MotorIzqAdelante,0);
}
void girarDer(){ //Girar hacia la derecha
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(MotorDerAtras,1);
    digitalWrite(MotorDerAdelante,0);
    digitalWrite(MotorIzqAtras,0);
    digitalWrite(MotorIzqAdelante,1);
}
void girarIzq(){ //Girar hacia la izquierda
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(MotorDerAtras,0);
    digitalWrite(MotorDerAdelante,1);
    digitalWrite(MotorIzqAtras,1);
    digitalWrite(MotorIzqAdelante,0);
}
void parar(){ //Parar el motor
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(MotorDerAtras,0);
    digitalWrite(MotorDerAdelante,0);
    digitalWrite(MotorIzqAtras,0);
    digitalWrite(MotorIzqAdelante,0);
}

void setup() { //Setup del robot
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  digitalWrite(trig, LOW);

  
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  pinMode(sen3,INPUT);
  pinMode(sen4,INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MotorDerAtras,OUTPUT);
  pinMode(MotorDerAdelante,OUTPUT);
  pinMode(MotorIzqAtras,OUTPUT);
  pinMode(MotorIzqAdelante,OUTPUT);
  
  Serial.begin(9600);

}

void loop() { //Loop del robot

  if (digitalRead(sen1) == HIGH && digitalRead(sen2) == HIGH && digitalRead(sen3) == HIGH && digitalRead(sen4) == HIGH) { //Si entonces todos los sensores estan en 1 (negro)
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);

    distancia = pulseIn(echo,HIGH); // Solo se va a hacer la lectura del ultrasonido si todos los sensores estan en negro
    distancia = distancia/58;

    delay(50);
    
    if (distancia < 40) { //Y ademas si el ultrasonido mide menos de 50 cm va a ir hacia adelante
    adelante();
    } else { //Y si no, va a girar hacia la derecha
      girarDer();
    }
  }

  if (digitalRead(sen1) == HIGH && digitalRead(sen2) == HIGH && digitalRead(sen3) == LOW && digitalRead(sen4) == LOW) { //Si entonces solo el motor 1 y 2 estan en 1 (negro)
    adelante();
    delay(espera); //Se va a mover hacia adelante durante 1 segundo y luego se para los motores para hacer la siguiente acción
    parar();

  }
  
  if (digitalRead(sen1) == HIGH && digitalRead(sen2) == HIGH && digitalRead(sen3) == HIGH && digitalRead(sen4) == LOW) { //Si entonces solo el motor 4 esta en 0 (blanco)
    adelante();
    delay(espera); //Se va a mover hacia adelante durante 1 segundo y luego se para los motores para hacer la siguiente acción
    parar();

  }

if (digitalRead(sen1) == HIGH && digitalRead(sen2) == HIGH && digitalRead(sen3) == LOW && digitalRead(sen4) == HIGH) { //Si entonces solo el motor 3 esta en 0 (blanco)
    adelante();
    delay(espera); //Se va a mover hacia atras durante 1 segundo y luego se para los motores para hacer la siguiente acción
    parar();
  
  }
  
  if (digitalRead(sen1) == LOW && digitalRead(sen2) == LOW && digitalRead(sen3) == HIGH && digitalRead(sen4) == HIGH) { //Si entonces solo el motor 3 y 4 es 1 (negro)
    atras();
    delay(espera); //Se va a mover hacia atras durante 1 segundo y luego se para los motores para hacer la siguiente acción
    parar();
    
  }
  
  if (digitalRead(sen1) == LOW && digitalRead(sen2) == HIGH && digitalRead(sen3) == HIGH && digitalRead(sen4) == HIGH) { //Si entonces solo el motor 1 es 0 (blanco)
    atras();
    delay(espera); //Se va a mover hacia atras durante 1 segundo y luego se para los motores para hacer la siguiente acción
    parar();
    
  }

  if (digitalRead(sen1) == HIGH && digitalRead(sen2) == LOW && digitalRead(sen3) == HIGH && digitalRead(sen4) == HIGH) { //Si entonces solo el motor 2 es 0 (blanco)
    atras();
    delay(espera); //Se va a mover hacia atras durante 1 segundo y luego se para los motores para hacer la siguiente acción
    parar();
    
  }

  delay(50);
}
