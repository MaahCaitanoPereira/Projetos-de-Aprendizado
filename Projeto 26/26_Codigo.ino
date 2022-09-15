// De inicio puxei lá do fundo da memoria, trabalhos do Wilson

#include <Servo.h>

char buffer[10];

// nomeando os servos
Servo servo1; 
Servo servo2; 

void setup()
{
  servo1.attach(5); // Pino
  servo2.attach(6); // Pino

  Serial.begin(9600);
  Serial.flush();
  
    // começam à 90°
  servo1.write(90);
  servo2.write(90); 

  Serial.println("Iniciando...");
  Serial.println("Digite o motor e angulo");
}

void loop() 
{
  if (Serial.available() > 0) 
  { // Verifica se dados foram digitados
    int index=0;
    delay(100); // Deixa o buffer encher
    int numChar = Serial.available(); // Encontra o comprimento da string
    if (numChar>10) 
      {
      numChar=10;
    }
    
        while (numChar--) 
        {
      // Preenche o buffer com a string
      buffer[index++] = Serial.read();
    }
    String(buffer); // Executa a função String
  }
}

void String(char* dados) 
{
  Serial.print(" Processando.. \n ");
  Serial.println(dados);
  char* parametro;
  parametro = strtok (dados, " ,"); // Divide string em num e letras
  
  while (parametro != NULL)// Roda o laço até o fim da string
  { 
    posicao(parametro); //Executa a função posicao
    parametro = strtok (NULL, " ,");
  }
  // Limpa o texto e os buffers seriais

  for (int x=0; x<9; x++) 
  {

    buffer[x]='\0';
  }
    Serial.flush();
}

void posicao(char* dados) // Verifica qual motor quer mover, esquerdo ou direita
{
  if ((dados[0] == 'E') || (dados[0] == 'e'))  // Move o Esquerdo
  {
    int angulo1 = strtol(dados+1, NULL, 10); // De string para inteiro longo
    angulo1 = constrain(angulo1,0,180); // Restringe os valores
    servo1.write(angulo1);
    Serial.print(" o Servo 1 foi para: ");
    Serial.println(angulo1);
  }

  if ((dados[0] == 'D') || (dados[0] == 'd')) // Move o Direito
    {
    int angulo2 = strtol(dados+1, NULL, 10); // De string para inteiro longo
    angulo2 = constrain(angulo2,0,255); // Restringe os valores
    servo2.write(angulo2);
    Serial.print("o Servo 2 foi para: ");
    Serial.println(angulo2);
  }
}
