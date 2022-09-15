
float RGB1[3]; // Vetor das cores desligadas
float RGB2[3]; // Vetor das cores aleatorias
float AUX[3]; // Vetor que auxilia a troca de cores
  
int red, green, blue;
int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;

void setup()
{
  randomSeed(analogRead(0));
  
    RGB1[0] = 0;
    RGB1[1] = 0;
    RGB1[2] = 0;
  
    RGB2[0] = random(256);
  RGB2[1] = random(256);
    RGB2[2] = random(256);
}  

void loop()
{
 randomSeed(analogRead(0));
    
  for (int x=0; x<3; x++){
    AUX[x] = (RGB1[x] - RGB2[x])/ 256;}
  
  for (int x=0; x<256; x++){  // gerar a cor aleatoria
  red = int(RGB1[0]);
  green = int(RGB1[1]);
  blue = int(RGB1[2]);
    
  analogWrite (RedPin, red);
  analogWrite (GreenPin, green);
  analogWrite (BluePin, blue);
  delay(100);
    
    RGB1[0] -= AUX[0]; // num gerado na linha 29 negativo, e vai para positivo
  RGB1[1] -= AUX[1];
  RGB1[2] -= AUX[2];
  }
  
  for (int x=0; x<3; x++) { // havera cores iguais, gera uma cor aletoria nova
  RGB2[x] = random(556)-300; // num para cor deifenrente das funçoes anteriores
  RGB2[x] = constrain(RGB2[x], 0, 255); // restinge de  0 ate 255 
  delay(1000);
  }
}
   
