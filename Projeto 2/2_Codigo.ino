void setup()
{
  pinMode(2, OUTPUT);
}

void loop()
{
  for (int x=0; x<3; x++) 
  {
  digitalWrite( 2, HIGH); // acende o LED
  delay(150); // espera 150ms
  digitalWrite( 2, LOW); // apaga o LED
  delay(100); // espera 100ms
  } 

  delay(2000); //Usei para ver as letras em codigo
  
  for (int x=0; x<3; x++) 
  {
  digitalWrite(2, HIGH); // acende o LED
  delay(400); // espera 400ms
  digitalWrite(2, LOW); // apaga o LED
  delay(100); // espera 100ms
  }  
  
  delay(2000); //Usei para ver as letras em codigo
  
   for (int x=0; x<3; x++) 
  {
  digitalWrite( 2, HIGH); // acende o LED
  delay(150); // espera 150ms
  digitalWrite( 2, LOW); // apaga o LED
  delay(100); // espera 100ms
  } 
  delay(3000);//Usei para ver as letras em codigo
  
}
