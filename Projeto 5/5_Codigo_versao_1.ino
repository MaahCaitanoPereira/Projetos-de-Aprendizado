// Pesquise oq é array antes( são vetores)

byte ledPino[]= {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // entrada em vetores
int ledDelay(500); // intervalo entre os leds
int direcao = 1; // segui 4 a 13 e voltar 13 a 4
int atual = 0; // posicao do vetor 4, o incial
unsigned long tempo;

void setup (){
  for ( int x=4; x< 14; x++) // começa 4, e roda toda vez +1, ate chega 14
  {
  pinMode(ledPino[x], OUTPUT); 
  }  
  tempo = millis(); 
}

void loop(){
  if (( millis() - tempo) > ledDelay){ // condicao de parada, nao pode ser menor q 0
  LED(); // ms desde a última alteração
  tempo = millis ();
  }  
}
 
void LED()
{
  for ( int x=4; x< 14; x++){
  digitalWrite( ledPino[x], LOW); 
  }  
    
  digitalWrite(ledPino[atual], HIGH);
  atual += direcao; 
 if (atual == 13) {direcao = -1;}  
  if (atual == 4) {direcao= 1;}    

}  
  
  
  
  
  
