// O livro fala q usa um resistor, e nem tem na imagem do circuito
// Foi dificil montar no meio dos fios e achar o motor 
// O motor do Tinkercad não é o mesmo do livro
// O codigo funciona para este motor

#include <Stepper.h>

#define STEPS 200
// O motor livro a 200 passos consegue fazer 360 graus
// Usando no motor este valor não gera 360 graus 


Stepper stepper(STEPS, 4, 5, 6, 7); // Pinos

void setup() 
{
  
}

void loop() 
{
  stepper.setSpeed(2737);
  stepper.step(200);
  delay(100);
  stepper.setSpeed(2737);
  stepper.step(-50);
  delay(100);
}
