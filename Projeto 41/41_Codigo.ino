// Mais facil de montar, dupliquei o Projeto 40 e removi oque não precisava
// Codigo alterado do projeto 40
// Funcionamento: alarme toca quando a distancia fica abaixo de 36 polegadas
// Toca em faixas conforme diminui a distancia

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

float pwmRange, averageReading, alarmRange;

#define frequenciabaixa 123 // C3 nota mais grave  
#define frequenciaalta 2093 // C7 nota mais aguda
#define playHeight 36 // sensibilidade

int trigPin = 10; // Envio de ondas ultrassônicas
int echoPin = 9;  // Recebe as ondas ultrassônicas 

float v=(331.5)+(0.6*20); // velocidade da onda

void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT); // manda a onda
    pinMode(echoPin, INPUT); // recebe a onda
    pinMode(7, OUTPUT); // Piezo
    lcd .begin(16,2);
}

float distanceCm()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    float tUs = pulseIn(echoPin, HIGH);// mede o tempo de ida e de volta do sinal
    float t = tUs / 1000.0 / 1000.0 / 2.0;  // converte o tempo de percurso da onda
    float d = t*v; // distancia total percorrida pela onda
    return d*100; // conversão para cm
}

void loop()
{
      float d= distanceCm();
      float in;

     if ( digitalRead(8)==HIGH)
      {
          lcd.setCursor(7,0);  // imprimi em cm
          lcd.print(d);
          lcd.setCursor(3,0);
          lcd.print("cm:");

      }

    if (digitalRead(8)==LOW)

      {
          in= d/2.54;             // converte e imprimi em polegadas
          lcd.setCursor(7,0);
          lcd.print(in);
          lcd.setCursor(3,0);
          lcd.print("in:");
      }
  
float notas = map(in, 0, playHeight, frequenciabaixa, frequenciaalta);
// Mapeia as notas

  if (in<playHeight) 
    // Valores abaixo de 36 polegadas se tem um alarme
    {
    tone(7, notas); 
  }
  else 
  {
    noTone(7);
  }

    delay(1000);
    lcd. clear();
}
