void setup()
{
  pinMode(7, OUTPUT); // Verde
  pinMode(4, OUTPUT); // Amarelo
  pinMode(2, OUTPUT); // Vermelho  
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(1000); 
 
  digitalWrite(4, HIGH);
  delay(2000);
  
  digitalWrite(7, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  delay(1000);
  
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  delay(2000);
  
  digitalWrite(4, LOW);
}
