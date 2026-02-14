const int IN1 = 3;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 9;
const int pin_trig = 10;
const int pin_echo = 11;
const int infra_1 = 2;
const int infra_2 = 4;
const int infra_3 = 7;
const int infra_4 = 8;
int tiempo = 0;
int distancia = 0;
int valor_1 = 0;
int valor_2 = 0;
int valor_3 = 0;
int valor_4 = 0;
//blanco = 0
//negro = 1
void setup() {
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(pin_echo, INPUT);
pinMode(pin_trig, OUTPUT);
delay(5000);
}

void loop() {
digitalWrite(pin_trig, HIGH);//Distancia del sensor ultrasónico  
delay(1);
digitalWrite(pin_trig, LOW);
tiempo = pulseIn(pin_echo, HIGH);
distancia = tiempo * 0.01715;
delay(100);
valor_1 = digitalRead(infra_1); //Estudiar posición negra o blanca del robot  
valor_2 = digitalRead(infra_2);
valor_3 = digitalRead(infra_3);
valor_4 = digitalRead(infra_4);
if(valor_1 == 1 & valor_2 == 1 & valor_3 == 1 & valor_4){
if(distancia <= 50){
analogWrite(IN4, 0);//Para atacar.      
analogWrite(IN3, 255);
analogWrite(IN2, 0);
analogWrite(IN1, 255);
}
else{
analogWrite(IN4, 0);//Para  girar sobre su eje.      
analogWrite(IN3, 85);
analogWrite(IN2, 85);
analogWrite(IN1, 0);
}
}
else if(valor_1 == 0 || valor_2 == 0){
analogWrite(IN4, 255); //Devolverse cuando está sobre la línea blanca al frente. 
analogWrite(IN3, 0);
analogWrite(IN2, 255);
analogWrite(IN1, 0);
delay(1000);
}
else if(valor_3 == 0 || valor_4 == 0){
analogWrite(IN4, 0);//Devolverse cuando está sobre la línea blanca atrás.  
analogWrite(IN3, 255);
analogWrite(IN2, 0);
analogWrite(IN1, 255);
delay(1000);
}
}
