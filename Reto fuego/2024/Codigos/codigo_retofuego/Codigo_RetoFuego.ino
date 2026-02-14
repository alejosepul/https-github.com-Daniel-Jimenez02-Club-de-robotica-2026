//Nombramos los pines a utilizar.
//Pines para los sensores de infrarrojo
#define delIzq 22  //IR delantero izquierdo
#define delDer 23  //IR delantero derecha
#define traIzq 24  //IR trasero izquierdo
#define traDer 25  //IR trasero derecho

#define flama1 A4
#define flama2 A5
#define flama3 A6
#define flama4 A7
#define flama5 A8

//Pines para puente H (motor A - Motor B) inA = atras- inB = adelante- inC = atras- inD = adelante
#define inA 8   //in1
#define inB 9   //in2
#define inC 10  //in3
#define inD 11  //in4

//variables para leer los sensores de linea
int DI = 0;
int DD = 0;
int TI = 0;
int TD = 0;

//variables para leer los sensores de flama
int val1;
int val2;
int val3;
int val4;
int val5;

//pines para PWM
int PWM1 = 13;
int PWM2 = 12;
int v1 = 100;
int v2 = 100;

void Adelante () {
  //Prueba Serial.println("At");
  digitalWrite (inA, HIGH);
  digitalWrite (inB, LOW);
  digitalWrite (inC, HIGH);
  digitalWrite (inD, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(flama1, INPUT);
  pinMode(flama2, INPUT);
  pinMode(flama3, INPUT);
  pinMode(flama4, INPUT);
  pinMode(flama5, INPUT);
  pinMode(delIzq, INPUT);
  pinMode(delDer, INPUT);
  pinMode(traIzq, INPUT);
  pinMode(traDer, INPUT);
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void loop() {
  
  // se lee los valores de los sensores de linea
  DI = digitalRead(delIzq);
  DD = digitalRead(delDer);
  TI = digitalRead(traIzq);
  TD = digitalRead(traDer);

  //se lee el valoe de los sensores de flama
  val1 = analogRead(flama1);
  val2 = analogRead(flama2);
  val3 = analogRead(flama3);
  val4 = analogRead(flama4);
  val5 = analogRead(flama5);

  ProbarSenFuego();
  //se llama a prueba de sensor

  if (DI == 1 || DD == 1 || TI == 1 || TD == 1) {
  digitalWrite (inA, HIGH);
  analogWrite  (PWM1, v1);
  digitalWrite (inB, LOW);
  digitalWrite (inC, HIGH);
  analogWrite  (PWM2, v2);
  digitalWrite (inD, LOW);
    if (val1 > 200) {
      Parar();
      delay(500);
      Izquierda();
      delay(1000);
    }
    if (val3 > 200) {
      Parar();
      delay(500);
      Derecha();
      delay(1000);
    }
  }
   if (DI == 0 || DD == 0 || TI == 0 || TD == 0) {
    Atras();
    delay(800);
    Derecha();
    delay(1000);
   }
}
