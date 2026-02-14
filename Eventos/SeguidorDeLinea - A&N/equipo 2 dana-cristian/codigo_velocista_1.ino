//Pines a utilizar para los sensores IR 
const int izquierda=9;
const int centro=8;
const int derecha=13;

const int ENA = 9;    // Velocidad motor izquierdo (PWM)
const int IN1 = 8;    // Giro motor izquierdo
const int IN2 = 7;

const int ENB = 10;   // Velocidad motor derecho (PWM)
const int IN3 = 6;    // Giro motor derecho
const int IN4 = 5;

//Variables necesarias
int ir1=0;
int ir2=0;
int ir3=0;


void setup() {
  Serial.begin(9600);
  pinMode(izquierda, INPUT);
  pinMode(centro, INPUT);
  pinMode(derecha, INPUT);

}

void loop() {
  //Lectura de los senosres infrarrojos
  ir1=digitalRead(izquierda);
  ir2=digitalRead(centro);
  ir3=digitalRead(derecha);
  
  Serial.print("izquierda: ");
  Serial.println(ir1);
  Serial.print("centro: ");
  Serial.println(ir2);  
  Serial.print("derecha: ");
  Serial.println(ir3);
  Serial.println("___________________________________________");
  delay(500);  
if(izquierda == 0 && centro == 1 && derecha ==0) {
avanzar();
}

else if(izquierda == 1 && centro == 0 && derecha == 0) {
  avanzar();
}

else if (izquierda == 0 && centro == 0 && derecha == 1) {
  girarDerecha();

}

}

void avanzar() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void girarIzquierda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  // Izquierdo gira atrás
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);   // Derecho hacia adelante
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
}

void girarDerecha() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);   // Izquierdo hacia adelante
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  // Derecho gira atrás
  analogWrite(ENA, 120);
  analogWrite(ENB, 120);
}


