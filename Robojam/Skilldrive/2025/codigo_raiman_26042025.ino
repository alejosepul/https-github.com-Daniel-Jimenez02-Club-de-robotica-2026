int m1r = 6;
int m1a = 7;
int m2a = 5;
int m2r = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(m1a, OUTPUT);
  pinMode(m1r, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2r, OUTPUT);
}

void loop() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
