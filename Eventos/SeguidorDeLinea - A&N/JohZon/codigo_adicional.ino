// ---------------- PINES (CONFIGURACIÓN MEJORADA) ----------------

// Pines de Velocidad (PWM) - ¡Deben ser pines con el simbolo ~!
// En Arduino Uno/Nano: 3, 5, 6, 9, 10, 11
#define ENA 3   // Velocidad Motor Izquierdo
#define ENB 9   // Velocidad Motor Derecho (CAMBIADO del 2 al 9 para tener PWM real)

// Pines de Dirección Motores
#define motor_izq_av 5
#define motor_izq_at 4
#define motor_der_av 7
#define motor_der_at 6

// Sensores Infrarrojos (Nombres corregidos)
#define sensor_izq 10
#define sensor_cen 8   // CAMBIADO del 9 al 8 (para dejar libre el 9 para PWM)
#define sensor_der 11

// Velocidades (Ajusta estos valores para calibrar tu robot)
const int VELOCIDAD_BASE = 120; 
const int VELOCIDAD_GIRO = 100;

// ---------------- CONFIGURACIÓN INICIAL ----------------

void setup() {
  // Configurar pines de motores como salida
  pinMode(motor_izq_av, OUTPUT);
  pinMode(motor_izq_at, OUTPUT);
  pinMode(motor_der_av, OUTPUT);
  pinMode(motor_der_at, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Configurar sensores como entrada
  pinMode(sensor_izq, INPUT);
  pinMode(sensor_cen, INPUT);
  pinMode(sensor_der, INPUT);

  Serial.begin(9600);
  Serial.println("Robot Iniciado");
  delay(1000); // Pequeña pausa de seguridad al encender
}

// ---------------- FUNCIONES DE MOVIMIENTO ----------------

void avanzar() {
  // Ajusta las velocidades si un motor corre más que el otro
  analogWrite(ENA, VELOCIDAD_BASE); 
  analogWrite(ENB, VELOCIDAD_BASE); 
  
  digitalWrite(motor_izq_av, HIGH);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, HIGH);
  digitalWrite(motor_der_at, LOW);
}

void girar_izquierda() {
  // Para girar mejor, bajamos velocidad o detenemos el motor izquierdo
  analogWrite(ENA, 0);            // Motor izquierdo parado
  analogWrite(ENB, VELOCIDAD_GIRO); // Motor derecho avanza
  
  digitalWrite(motor_izq_av, LOW);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, HIGH);
  digitalWrite(motor_der_at, LOW);
}

void girar_derecha() {
  analogWrite(ENA, VELOCIDAD_GIRO); // Motor izquierdo avanza
  analogWrite(ENB, 0);            // Motor derecho parado
  
  digitalWrite(motor_izq_av, HIGH);
  digitalWrite(motor_izq_at, LOW);
  digitalWrite(motor_der_av, LOW);
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

// ---------------- BUCLE PRINCIPAL ----------------

void loop() {
  // Lectura de sensores
  int lect_izq = digitalRead(sensor_izq);
  int lect_cen = digitalRead(sensor_cen);
  int lect_der = digitalRead(sensor_der);

  // LÓGICA DE CONTROL
  // Asumimos que 1 (HIGH) es DETECCIÓN DE LÍNEA (Negra)
  // Si tu sensor funciona al revés (1 en blanco, 0 en negro), invierte los 1 y 0 abajo.

  // Caso 1: Avanzar (Solo centro detecta O centro+lados un poco)
  if (lect_cen == 1 && lect_izq == 0 && lect_der == 0) {
    avanzar();
  }
  // Caso 2: Desvío a la izquierda -> Corregir girando a la izquierda
  else if (lect_izq == 1 && lect_der == 0) {
    // Nota: No importa si el centro es 1 o 0, si el izq toca linea, hay que girar
    girar_izquierda();
  }
  // Caso 3: Desvío a la derecha -> Corregir girando a la derecha
  else if (lect_der == 1 && lect_izq == 0) {
    girar_derecha();
  }
  // Caso 4: Intersección o final (Todos en 1) -> Detener
  else if (lect_izq == 1 && lect_cen == 1 && lect_der == 1) {
    detener();
    Serial.println("Interseccion detectada - Stop");
  }
  // Caso 5: Se perdió la línea (Todos en 0) -> Detener o mantener último movimiento
  // Por seguridad, detenemos, o podrías poner una lógica para que gire buscando la línea.
  else if (lect_izq == 0 && lect_cen == 0 && lect_der == 0) {
    // detener(); 
    // Opcional: Si quieres que siga avanzando un poco si pierde la linea momentaneamente:
    avanzar(); 
  }
  
  // ¡SIN DELAY! Esto permite leer los sensores miles de veces por segundo.
}
