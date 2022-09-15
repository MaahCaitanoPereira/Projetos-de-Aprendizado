// Errei varias vezes a montagem, coloquei um resitor a mais como no livro e deu errado
// Levei um bom tempo pra conseguir entender como mudar os componentes do livro para os do Tinkercad
// Códido do livro tambem não funciona
// O complicado foi fazer o pizo e potenciometro funcionar
// Funcionamento: escolhe uma faixa pelo potenciometro
// Se a distancia do sensor for menor que o valor, ele apita
// O botão reinicia

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
float pwmRange, averageReading, alarmRange;

int trigPin = 10; // Envio de ondas ultrassônicas
int echoPin = 9;  // Recebe as ondas ultrassônicas 

float v=(331.5)+(0.6*20); // velocidade da onda

void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT); // manda a onda
    pinMode(echoPin, INPUT); // recebe a onda
    lcd.begin(16,2);
  pinMode(7, OUTPUT); // piezo  
  pinMode(13, INPUT); //botão
  pinMode(A0, INPUT); // potenciometro 
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

float Faixa()  // transforma um valor em bits para uma distancia
{
  float potValue = analogRead(0);
  alarmRange = 254 * (potValue/1024);   
  return alarmRange;
}

void Alarme() 
{
  while(1) 
  {
    for (int freq=800; freq<2500;freq++) 
    {
      tone(7, freq);
      if (digitalRead(13))   
      {
        noTone(7);
        return;
      }
    }
  }
}

void loop()
{
      float d= distanceCm();
      Faixa(); 

     if ( digitalRead(8)==HIGH)
      {
          lcd.setCursor(7,0);  // imprimi em cm
          lcd.print(d);
          lcd.setCursor(3,0);
          lcd.print("cm:");

      }

    if (digitalRead(8)==LOW)

      {
          float in= d/2.54; // converte e imprimi em polegadas
          lcd.setCursor(7,0);
          lcd.print(in);
          lcd.setCursor(3,0);
          lcd.print("in:");
      }
  if (d<=alarmRange) // liga o alarme
  {
    Alarme();
  }
    delay(1000);
    lcd. clear();
}
