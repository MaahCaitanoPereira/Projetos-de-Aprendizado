
int yellow1 = 13;
int red = 8;
int yellow2 = 2;

void setup()
{
  pinMode(yellow1, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow2, OUTPUT);
}

void loop() // gerar cores aleotrias para chama/ brilho
{
  analogWrite(yellow1, random(120)+136); 
  analogWrite(red, random(120)+136);
  analogWrite(yellow2, random(120)+136);
}
