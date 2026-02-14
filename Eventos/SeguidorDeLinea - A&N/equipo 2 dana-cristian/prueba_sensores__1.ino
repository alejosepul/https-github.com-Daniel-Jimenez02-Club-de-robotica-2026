//Pines a utilizar para los sensores IR 
const int izquierda=9;
const int centro=8;
const int derecha=13;

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
 

  Serial.print("izquierda ");
  Serial.println(ir1);
  Serial.print("centro");
  Serial.println(ir2);  
  Serial.print("derecha ");
  Serial.println(ir3);
  Serial.println("___________________________________________");
  delay(500);  
}
