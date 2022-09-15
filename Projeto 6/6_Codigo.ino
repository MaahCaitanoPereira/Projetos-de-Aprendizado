// Codigo diferente do livro, mais simples
byte ledPino[]= {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // entrada em vetores
int ledDelay; // intervalo entre os leds
int direcao = 1; // segui 4 a 13 e voltar 13 a 4
int atual = 0; // posicao do vetor 4, o incial
int potPin = 2;

void setup()
{
 for ( int x=0; x< 10; x++) // começa 4, e roda toda vez +1, ate chega 14
  {
  pinMode(ledPino[x], OUTPUT); 
  }  
  delay(500);
}

void loop()
{
  ledDelay = analogRead(potPin=2);
  delay(500);
  Led();
}  

void Led()
{
  for ( int x=0; x<10; x++)
  {
    digitalWrite(ledPino[x], LOW);
  } 
  digitalWrite(ledPino[atual], HIGH);
  atual += direcao;
  
  if (atual== 9) {direcao = -1;}  
  if (atual == 0) {direcao = 1;}  
 } 
