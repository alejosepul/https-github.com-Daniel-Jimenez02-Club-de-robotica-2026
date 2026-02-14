const int sensorI = 9;
const int sensorC = 8;
const int sensorD = 7;
int lecturaI;
int lecturaC;
int lecturaD;

void setup() {
  pinMode(sensorI, INPUT);
  pinMode(sensorC, INPUT);
  pinMode(sensorD, INPUT);
  Serial.begin(9600);
}

void loop() {
  lecturaI = digitalRead(sensorI);
  lecturaC = digitalRead(sensorC);
  lecturaD = digitalRead(sensorD);

  Serial.print(lecturaI);
  Serial.print(lecturaC);
  Serial.println(lecturaD);
}
