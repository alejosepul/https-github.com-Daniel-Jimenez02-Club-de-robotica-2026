// Definiciones de los pines de los sensores de llama conectados a los pines analógicos del Arduino
#define sensorLlama1 A1  // Sensor de llama 1 en el pin A1
#define sensorLlama2 A2  // Sensor de llama 2 en el pin A2
#define sensorLlama3 A3  // Sensor de llama 3 en el pin A3
#define sensorLlama4 A4  // Sensor de llama 4 en el pin A4
#define sensorLlama5 A5  // Sensor de llama 5 en el pin A5

// Definiciones de los pines de salida para el motor y control de velocidad
int pinMotor = 5;  // Pin digital para controlar el motor (enciende o apaga)
int ENA = 9;       // Pin digital para controlar la velocidad del motor con PWM

void setup() {
  // Configuración de los pines de los sensores de llama como entradas
  pinMode(sensorLlama1, INPUT);  // Configura el sensor de llama 1 como entrada
  pinMode(sensorLlama2, INPUT);  // Configura el sensor de llama 2 como entrada
  pinMode(sensorLlama3, INPUT);  // Configura el sensor de llama 3 como entrada
  pinMode(sensorLlama4, INPUT);  // Configura el sensor de llama 4 como entrada
  pinMode(sensorLlama5, INPUT);  // Configura el sensor de llama 5 como entrada

  // Configuración de los pines del motor como salidas
  pinMode(pinMotor, OUTPUT);     // Configura el pin del motor como salida
  pinMode(ENA, OUTPUT);          // Configura el pin ENA como salida para el control de velocidad

  // Inicia la comunicación serial a 9600 baudios para monitorear los valores de los sensores
  Serial.begin(9600);            // Inicia la comunicación serial para depuración
}

void loop() {
  // Lee los valores analógicos de cada uno de los sensores de llama
  int valorLlama1 = analogRead(sensorLlama1);  // Lee el valor del sensor de llama 1
  int valorLlama2 = analogRead(sensorLlama2);  // Lee el valor del sensor de llama 2
  int valorLlama3 = analogRead(sensorLlama3);  // Lee el valor del sensor de llama 3
  int valorLlama4 = analogRead(sensorLlama4);  // Lee el valor del sensor de llama 4
  int valorLlama5 = analogRead(sensorLlama5);  // Lee el valor del sensor de llama 5

  // Imprime los valores leídos de cada sensor en el monitor serial
  Serial.print("Llama 1: "); Serial.println(valorLlama1);  // Muestra el valor del sensor 1
  Serial.print("Llama 2: "); Serial.println(valorLlama2);  // Muestra el valor del sensor 2
  Serial.print("Llama 3: "); Serial.println(valorLlama3);  // Muestra el valor del sensor 3
  Serial.print("Llama 4: "); Serial.println(valorLlama4);  // Muestra el valor del sensor 4
  Serial.print("Llama 5: "); Serial.println(valorLlama5);  // Muestra el valor del sensor 5

  // Comparaciones para encontrar cuál sensor de llama detecta el valor más alto
  // Enciende el motor y ajusta su velocidad según el sensor que detecte más proximidad a la llama
  if (valorLlama1 > valorLlama2 && valorLlama1 > valorLlama3 && valorLlama1 > valorLlama4 && valorLlama1 > valorLlama5) {
    digitalWrite(pinMotor, HIGH);  // Activa el motor
    analogWrite(ENA, 60);          // Ajusta la velocidad del motor para el sensor 1 (PWM=60)
  }
  else if (valorLlama2 > valorLlama1 && valorLlama2 > valorLlama3 && valorLlama2 > valorLlama4 && valorLlama2 > valorLlama5) {
    digitalWrite(pinMotor, HIGH);  // Activa el motor
    analogWrite(ENA, 115);         // Ajusta la velocidad del motor para el sensor 2 (PWM=115)
  }
  else if (valorLlama3 > valorLlama1 && valorLlama3 > valorLlama2 && valorLlama3 > valorLlama4 && valorLlama3 > valorLlama5) {
    digitalWrite(pinMotor, HIGH);  // Activa el motor
    analogWrite(ENA, 160);         // Ajusta la velocidad del motor para el sensor 3 (PWM=160)
  }
  else if (valorLlama4 > valorLlama1 && valorLlama4 > valorLlama2 && valorLlama4 > valorLlama3 && valorLlama4 > valorLlama5) {
    digitalWrite(pinMotor, HIGH);  // Activa el motor
    analogWrite(ENA, 205);         // Ajusta la velocidad del motor para el sensor 4 (PWM=205)
  }
  else if (valorLlama5 > valorLlama1 && valorLlama5 > valorLlama2 && valorLlama5 > valorLlama3 && valorLlama5 > valorLlama4) {
    digitalWrite(pinMotor, HIGH);  // Activa el motor
    analogWrite(ENA, 255);         // Ajusta la velocidad del motor para el sensor 5 (PWM=255)
  }
  else {
    digitalWrite(pinMotor, LOW);   // Apaga el motor si ninguno de los sensores detecta una llama
  }

  // Pausa de 200 ms para evitar lecturas continuas y permitir que el motor reaccione
  delay(200);  // Pausa de 200 ms antes de repetir el bucle
}
