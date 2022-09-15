
int ledPino = 11;
float seno;
int led;

void setup()
{
  pinMode(ledPino, OUTPUT);
}  

void loop()
{
  for( int x=0; x<180; x++)
  {
    seno = (sin(x*(3.1416/180)));
    led = int(seno*255);
    analogWrite(ledPino, led);
    delay(25);
  }
}
