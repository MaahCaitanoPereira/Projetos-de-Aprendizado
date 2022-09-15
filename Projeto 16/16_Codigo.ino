
#define interruptor 2 
#define motorPin1 10  // Entrada 1 do L293D
#define motorPin2 4   // Entrada 2 do L293D
#define speedPin 11   // Pino de Ativação 1 do L293D
#define poten 0      // entrada A0

int va = 0; // velociade atual

void setup()
{
  pinMode(interruptor, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(speedPin, OUTPUT); 
}
  
void loop()
{
  
  va = analogRead(poten)/4;
  analogWrite(speedPin, va);
  
  if(digitalRead(interruptor)){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
 
  else{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
}
