#include <Servo.h> //Incluir la libreria que permite controlar el motor brushless

Servo ESC; //Nombrar el motor, "ESC" es solo el nombre que se designo en este caso, puede ser cualquiera

void setup() {
  // Ordenes obligatorias para inicializar el motor brushless
  ESC.attach(9); //Pin en el que va a estar conectado el motor
  ESC.writeMicroseconds(1000); //Inicializar el motor en su estado "apagado"
  delay(500); //Tiempo de espera para que se inicialice el motor
}

void loop() {
  ESC.writeMicroseconds(1000); //Orden de iniciar el giro del motor, inicia a girar en 1100aprox y el tope es 2100
}
