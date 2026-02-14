// ---------------- PINES ----------------

// Motores
int motor_izq_av = 5;
int motor_izq_at = 4;
int motor_der_av = 7;
int motor_der_at = 6;

//PWM
const int ENA = 3;   // Motor izquierdo
const int ENB = 2;  // Motor derecho

// Sensores infrarojos
int sensoresquilda = 10;
int sensormediamente = 9;
int sensorian = 11;

// ---------------- FUNCIONES DE MOVIMIENTO ----------------

void avanzar() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 200);
  digitalWrite(motor_izq_av, HIGH);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, HIGH);
  digitalWrite(motor_der_at, LOW);
}

void girar_izquierda() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 0);
  digitalWrite(motor_izq_av, HIGH);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, LOW);
  digitalWrite(motor_der_at, LOW);
}

void girar_derecha() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 100);
  digitalWrite(motor_izq_av, LOW);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, HIGH);
  digitalWrite(motor_der_at, LOW);
}

void detener() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(motor_izq_av, LOW);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, LOW);
  digitalWrite(motor_der_at, LOW);
}

// ---------------- FUNCION fantasma ----------------

// ---------------- CONFIGURACION INICIAL ----------------

void setup() {
  // Motores
  pinMode(motor_izq_av, OUTPUT);
  pinMode(motor_izq_at, OUTPUT);
  pinMode(motor_der_av, OUTPUT);
  pinMode(motor_der_at, OUTPUT);

    pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);


  // Sensores infrarrojos
  pinMode(sensoresquilda, INPUT);
  pinMode(sensormediamente, INPUT);
  pinMode(sensorian, INPUT);
  Serial.begin(9600);
  // Espera 3 segundos antes de iniciar
  
}

// ---------------- BUCLE PRINCIPAL ----------------

void loop() {
 int derecha = digitalRead (sensorian);
 int centro = digitalRead(sensormediamente);
 int isquierda = digitalRead(sensoresquilda);
  // Izquierda
    if (isquierda == 1 and centro == 0 and derecha == 0){
    Serial.println("giro izquierdo");
    girar_izquierda();
    delay(100);
 
    }
    
  // Derecha
    if (derecha == 1 and centro == 0 and isquierda == 0){
    Serial.println("giro derecho");
    girar_derecha();
    delay(100);
 
    }
    if (centro == 1 and derecha == 0 and isquierda == 0){
Serial.println("avanzando para adelante");
   avanzar();
delay(100);
    }
    if (centro == 1 and derecha == 1 and isquierda == 1 ){
    detener ();
    }
}
