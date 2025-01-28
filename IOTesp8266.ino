#include <Servo.h>
Servo servo;

#include "thingProperties.h"

void setup() {
  servo.attach(D5);  // Configura el pin D5 para el servo
  Serial.begin(9600);  // Inicializa la comunicación serial
  delay(1500);  // Espera 1.5 segundos

  // Inicializa las propiedades de IoT
  initProperties();

  // Conecta a Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

/*
  Since Porcion is READ_WRITE variable, onPorcionChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPorcionChange() {
  if (porcion == 1) {
    // Gira hacia la posición 90° (hacia la derecha)
    servo.writeMicroseconds(1600);  // Gira hacia la derecha
    delay(10);  // Gira durante 1 segundo (aproximadamente 90°)
    servo.writeMicroseconds(0);  // Detiene el servo (posición neutra)
  }
  else if (porcion == 2) {
    // Gira hacia la posición 180° (hacia la izquierda)
    servo.writeMicroseconds(1400);  // Gira hacia la izquierda
    delay(20);  // Gira durante 2 segundos (aproximadamente 180°)
    servo.writeMicroseconds(0);  // Detiene el servo (posición neutra)
  }
  else if (porcion == 3) {
    // Gira hacia la posición 270° (hacia la derecha)
    servo.writeMicroseconds(1600);  // Gira hacia la derecha
    delay(30);  // Gira durante 3 segundos (aproximadamente 270°)
    servo.writeMicroseconds(0);  // Detiene el servo (posición neutra)
  }
  else if (porcion == 4) {
    // Gira hacia la posición 360° (hacia la izquierda)
    servo.writeMicroseconds(1400);  // Gira hacia la izquierda
    delay(45);  // Gira durante 4 segundos (aproximadamente 360°)
    servo.writeMicroseconds(0);  // Detiene el servo (posición neutra)
  }
}
