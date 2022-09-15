// A função do livro de K, C e F não servem para o sensor do Tinkercad
// O Potenciômetro não tem uso, quando se altera a resistência nele a T muda 

char degree = 176; // Simbolo de Graus

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int t = analogRead(A0);
  float voltage = (t * 5.0)/1024;
  float milliVolt = voltage * 1000;
  float C = (milliVolt-500)/10;
  float K = (C + 273.15);
  float F = (((C*9)/5)+32);
  

  Serial.print("Kelvin: ");
  Serial.print(K);
  Serial.println(degree);

  Serial.print("Celsius: ");
  Serial.print(C);
  Serial.println(degree);

  Serial.print("Fahrenheit: ");
  Serial.print(F);
  Serial.println(degree);
  Serial.println("");


  delay(2000);

}
