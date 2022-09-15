#include <Servo.h>

Servo servo1; 

void setup() 
{
  servo1.attach(3);
}
void loop() 
{
  int poten = analogRead(0); 
  poten = map(poten, 0, 1023, 0, 180); // 1 Byte e angulo max
  servo1.write(poten); // Escreve o ângulo para o servo
  delay(15); 
}
