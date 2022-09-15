// Mesmo codigo que o Projeto 38
// Mas adicionando a tela LCD e o interruptor que muda de cm para polegada
// Tambem não usei o capacitor 
// O codigo do livro está dando erro de escrita em várias partes
// Refiz do zero 

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int trigPin = 10; // Envio de ondas ultrassônicas
int echoPin = 9;  // Recebe as ondas ultrassônicas 

float v=(331.5)+(0.6*20); // velocidade da onda

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // manda a onda
  pinMode(echoPin, INPUT); // recebe a onda
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

    if ( digitalRead(8)==HIGH)
    {
      lcd.setCursor(7,0);  // imprimi em cm
      lcd.print(d);
      lcd.setCursor(3,0);
      lcd.print("cm:");
      Serial.println(d);
    }
    
  if (digitalRead(8)==LOW)

    {
      d= d/2.54;      // converte e imprimi em polegadas
      lcd.setCursor(7,0);
      lcd.print(d);
      lcd.setCursor(3,0);
      lcd.print("in:");
      Serial.println(d); 
    }

  delay(1000);
    lcd. clear();
}
