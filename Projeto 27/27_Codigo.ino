// Parecido com o Projeto 25
// Com pequenas diferenças
// Para dois motores e dois potenciômetros

#include <Servo.h>

Servo servo1;
Servo servo2;

int poten1, poten2; // Potenciômetro

void setup()
{
  servo1.attach(5); 
  servo2.attach(6);
  
    servo1.write(90); // Posição inicial
  servo2.write(90);
}

void loop()
{
    poten1 = analogRead(0);
  poten2 = analogRead(1); 

  poten1 = map(poten1,0,1023,0,180);
  poten2 = map(poten2,0,1023,0,180);

  servo1.write(poten1);
  servo2.write(poten2);
  delay(15);
}
