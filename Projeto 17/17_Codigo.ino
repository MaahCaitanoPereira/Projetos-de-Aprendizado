// No livro não precisa do diodo zener e o regulador de 5 V
// Entretanto ao fazer a montagem ele queima mantendo no 3,3 V
// Colocando o diodo zener e o regulador de 5 V funcina em 3,3 V
// Ambos tem mesmo código
// E não usando diodo e regulador ele queima em determinados tempos
// De maneira aleatoria, mas volta a funcionar
// Recado: Errei varias vezes a montagem, e o codigo é um pouco complexo no inicio


int pinoregistro = 8;   // Pino conectado ao pino 12 do 74HC595 (registrador de saida)
int pinorelogio = 12;  // Pino conectado ao pino 11 do 74HC595 (registrador de deslocamento)
int pinoentrada = 11;  // Pino conectado ao pino 14 do 74HC595 (entrada de dados)

void setup() 
{  
  pinMode(pinoregistro, OUTPUT);  // Armazenam bits de informação
  pinMode(pinorelogio, OUTPUT);  // Alterna quando definido valor do pinoentrada 
  pinMode(pinoentrada, OUTPUT); // Sáida de cada bit
}

void loop() 
{
  for (int i = 0; i < 256; i++)  //cada byte contar com 256 combinações possíveis
    {
    digitalWrite(pinoregistro, LOW);
    contador(i); 

    digitalWrite(pinoregistro, HIGH);
    delay(1000);
  }
}

void contador(byte dataOut) // função que Transfere um byte de dados um bit de cada vez
{
  boolean estado;        // variavel que armazena um valor booleano,ligado ou desligado.
  digitalWrite(pinoentrada, LOW); // deixa o registrador de deslocamento pronto para enviar dados
  digitalWrite(pinorelogio, LOW);
  
  for (int i=0; i<=7; i++) // para cada bit em dataOut, envie um bit
    { 
    digitalWrite(pinorelogio, LOW); 
    
        // se o valor de DataOut e (E lógico) de uma máscara de bits
    // forem verdadeiros, defina estado como 1 (HIGH)
    
      if ( dataOut & (1<<i) ) 
      {
    estado = HIGH; // 
    }
   else 
    {
    estado = LOW;
    }
      
  // define pinoentrada como HIGH ou LOW, dependendo do estado
  digitalWrite(pinoentrada,estado ); // envia o bit no extremo ascendente do clock
  digitalWrite(pinorelogio, HIGH);
  }

  digitalWrite(pinorelogio, LOW); // interrompe o deslocamento de dados

}
