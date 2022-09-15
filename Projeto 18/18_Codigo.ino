// Com 3,3 V não funciona, com 5 V ele queima alternadamente mas funciona
// Usando o Diodo Zener e o Regulador 5 V ele funciona a 3,3 V e queima a 5 V


int pinoregistro = 8;   // Pino conectado ao pino 12 do 74HC595 (registrador de saida)
int pinorelogio = 12;  // Pino conectado ao pino 11 do 74HC595 (registrador de deslocamento)
int pinoentrada = 11;  // Pino conectado ao pino 14 do 74HC595 (entrada de dados)

void setup() 
{
  // define os pinos como saída
  pinMode(pinoregistro, OUTPUT);  // Armazenam bits de informação
  pinMode(pinorelogio, OUTPUT);  // Alterna quando definido valor do pinoentrada 
  pinMode(pinoentrada, OUTPUT); // Sáida de cada bit
}

void loop() 
{
  for (int i = 0; i < 256; i++) //cada byte contar com 256 combinações possíveis
    { 
    digitalWrite(pinoregistro, LOW);
    contador(i);
    contador(255-i);

    digitalWrite(pinoregistro, HIGH);
    delay(1000);
  }
}

void contador(byte dataOut) 
{
  boolean estado; 
  digitalWrite(pinoentrada, LOW); // libera o registrador de deslocamento, deixando-o pronto
  digitalWrite(pinorelogio, LOW);
  
  for (int i=0; i<=7; i++) // para cada bit em pinoentrada, envie um bit
    { 
    digitalWrite(pinorelogio, LOW); // define pinorelogio como LOW, antes de enviar o bit

    if ( dataOut & (1<<i) ) 
        {
    estado = HIGH;
    }
      
      else 
        {
    estado = LOW;
    }
      
    // define dataPin como HIGH ou LOW, dependendo de pinState
    digitalWrite(pinoentrada, estado);
    digitalWrite(pinorelogio, HIGH); // envia o bit no extremo ascendente do clock
    digitalWrite(pinoentrada, LOW);
  }
  digitalWrite(pinorelogio, LOW); // interrompe o deslocamento
}
