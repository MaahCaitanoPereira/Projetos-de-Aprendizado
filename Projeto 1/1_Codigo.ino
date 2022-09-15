void setup()
{
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT); // Pinos
  pinMode(4,OUTPUT);
}
void loop()
{
  digitalWrite(13, HIGH); // Liga
  delay(100); 
  digitalWrite(13, LOW); // Desliga
  delay(100); 

  digitalWrite(7,HIGH); // Liga
  delay(100);
  digitalWrite(7,LOW); // Desliga
  delay(100);
  
  digitalWrite(4,HIGH); // Liga 
  delay(100);
  digitalWrite(4,LOW); // Desliga
  delay(100);
  
}
