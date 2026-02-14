int trig = 5;
int echo = 4;
int Largo = 0;
int Ancho = 0;
int Area = 0;
int contador = 0;

long duration, cm, inches;
 
void setup() {
  Serial.begin (9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(6, INPUT);
}
 
void loop() {
  if (digitalRead(6) == 1){
    contador + 1;
    digitalWrite(trig, LOW);
    delayMicroseconds(5);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    delayMicroseconds(15);
  
    
    duration = pulseIn(echo, HIGH);
 
    cm = (duration/2) / 29.1;
    inches = (duration/2) / 74;
  
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
  
    delay(250);
    
    if (contador == 1){
      Largo = cm;
      
    }
    if (contador == 2){
      Ancho = cm;
      Area = Largo*Ancho;
      Serial.print("El area es de ");
      Serial.print(Area);
      Serial.println(" cm");
      
    }
  }
}
