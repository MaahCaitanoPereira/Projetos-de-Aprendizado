// 9°Projeto um pouco diferente

int laranja = 13;
int vermelho = 8;
int laranja1 = 2;

void setup()
{
  pinMode(laranja, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(laranja1, OUTPUT);
}

void loop()
{
  // Chama alta
  analogWrite(laranja, 150);
  analogWrite(vermelho, 255);
  analogWrite(laranja1, 150);
  delay(2000);

  // Fogo se apagando
  
  analogWrite(laranja, 255);
  analogWrite(vermelho, 150);
  analogWrite(laranja1, 250);
  delay(2000);
  
//Tinkercad não mostra visivilmente a brilho, então tudo é igual
  
}
