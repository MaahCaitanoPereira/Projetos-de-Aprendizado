// O Simulador apenas mostra a tela LCD ligada
// Então não mostra nenhuma T
// Testei outros codigos e tem o mesmo problema
// Erro do Tinkercad

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

int minC=0, maxC=100, minF=0, maxF=212;
int scale = 1;
int buttonPin=8;

void setup() 
{
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  pinMode(buttonPin, INPUT);
  lcd.clear();
}
void loop() 
{
  lcd.setCursor(0,0); // Define o cursor na posição de início
  int sensor = analogRead(0); // Lê a temperatura do sensor
  int buttonState = digitalRead(buttonPin); // Verifica se o botão foi pressionado
  
    switch (buttonState) // Altera o estado da escala, caso tenha sido pressionado
    { 
    case HIGH:
    scale=-scale; // Inverte a escala
    lcd.clear();
  }
 
  delay(250);
  
  switch (scale) // Decide por escala em Celsius ou Fahrenheit
    { 
    case 1:
    celsius(sensor);
    break;
    case -1:
    fahrenheit(sensor);
  }
}

void celsius(int sensor) 
{
  lcd.setCursor(0,0);
  int temp = sensor * 0.09765625; // Converte para Celsius
  lcd.print(temp);
  lcd.write(B11011111); // Símbolo de grau
  lcd.print("C ");
  if (temp>maxC) {maxC=temp;}
  if (temp<minC) {minC=temp;}
  lcd.setCursor(0,1);
  lcd.print("H=");   // Maior T medida
  lcd.print(maxC);
  lcd.write(B11011111);
  lcd.print("L="); // Menor T medida
  lcd.print(minC);
  lcd.write(B11011111);
  lcd.print("C=");
    lcd.print(temp);
    lcd.write(B11011111);
}

void fahrenheit(int sensor) 
{
  lcd.setCursor(0,0);
  float temp = ((sensor * 0.09765625) * 1.8)+32; // Converte para Fahrenheit
  lcd.print(int(temp));
  lcd.write(B11011111); // Imprime o símbolo de grau
  lcd.print("F ");
  if (temp>maxF) {maxF=temp;}
  if (temp<minF) {minF=temp;}
  lcd.setCursor(0,1);
  lcd.print("H="); // Maior T medida
  lcd.print(maxF);
  lcd.write(B11011111);
  lcd.print("L="); // Menor T medida
  lcd.print(minF);
  lcd.write(B11011111);
  lcd.print("F= ");
    lcd.print(temp);
    lcd.write(B11011111);
}
