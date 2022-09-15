// TEM ZUNIDO, USAR FONES DISTANTES

int piezo = 13;
int ldrPin = 0;
int ldr = 0;

void setup()
{ 
}

void loop() 
{

  ldr = analogRead(ldrPin);
  tone(piezo,1000); // significado de tone(pino, frequência 1000hz, duração)
  delay(25);
  noTone(piezo); // parar o tom
  delay(ldr);
    
}
