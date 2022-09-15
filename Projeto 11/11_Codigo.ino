// OBS: não use fones no maximo, mantenha distancia se usar

float seno;
float tom;

void setup()
{
  pinMode(7, OUTPUT);
}

void loop()
{
  for( int x=0; x<180; x++){  //usa seno para uma função senoidal
  seno = (sin(x*(3.1416/180)));
  tom = 2000+(int(seno*1000)); //criar o som a partir da função seno
  
  tone(7, tom);
  delay(2);
  }
}
