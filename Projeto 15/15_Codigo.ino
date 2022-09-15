// Mexendo no potenciometro( 250 k.Ohns) da direta para esquerda ele acelera

int poten = 0; // potenciometro
int transistor = 3;
int potenValor = 0;

void setup()
{
  pinMode(transistor, OUTPUT);
} 

void loop()
{
  potenValor = analogRead(poten)/4; // max/4 ou seja 1024 uni./4
  analogWrite(transistor,potenValor);
} 
