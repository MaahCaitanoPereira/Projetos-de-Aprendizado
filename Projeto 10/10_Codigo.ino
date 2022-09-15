
char buffer[18]; // banco de dados para usar
int red, green, blue;
int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;

void setup() 
{
  Serial.begin(9600); // inicia o monitor serial
  Serial.flush(); // limpar memoria do monitor serial
  
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() 
{
  if (Serial.available() > 0) { // checa o monitor ligado
    int index=0;
    delay(100); 
    int numChar = Serial.available();
      
  if (numChar>15){
    numChar=15;
  }
  while (numChar--) { // enquanto numchar ser !=0, salva o dado do usuario
  buffer[index++] = Serial.read();
  }
  splitString(buffer); // alimenta a funcao com os dados do buffer
  }
}

void splitString(char* data) 
{
  Serial.print("Data entered: ");
  Serial.println(data);
  char* parameter;
  parameter = strtok (data, " ,");
  
  while (parameter != NULL) {
  setLED(parameter);
  parameter = strtok (NULL, " ,");
}
// Limpa o texto e os buffers seriais

  for (int x=0; x<16; x++) {
  buffer[x]='\0';
  }
  Serial.flush();
  }

void setLED(char* data) 
{
  if ((data[0] == 'r') || (data[0] == 'R')) { // ligar o led vermelho
  int Ans = strtol(data+1, NULL, 10);
  Ans = constrain(Ans,0,255); // brilho
  analogWrite(RedPin, Ans);
  Serial.print("Red is set to: ");
  Serial.println(Ans);
}
  if ((data[0] == 'g') || (data[0] == 'G')) { // ligar o led verde
  int Ans = strtol(data+1, NULL, 10);
  Ans = constrain(Ans,0,255); // brilho
  analogWrite(GreenPin, Ans);
  Serial.print("Green is set to: ");
  Serial.println(Ans);
}
  if ((data[0] == 'b') || (data[0] == 'B')) { // ligar o led azul   
  int Ans = strtol(data+1, NULL, 10);
  Ans = constrain(Ans,0,255); // brilho
  analogWrite(BluePin, Ans);
  Serial.print("Blue is set to: ");
  Serial.println(Ans);
}
}
