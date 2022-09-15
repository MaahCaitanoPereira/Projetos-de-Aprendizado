// O codigo do livro não funcinou 
// Usou outro tipo de sensor, pq o do livro não tem no Tinkercad
// E não usei o capacitor
// Fiz um novo codigo

int trigPin = 10; // Envio de ondas ultrassônicas
int echoPin = 9;  // Recebe as ondas ultrassônicas 

float v=(331.5)+(0.6*20); // velocidade da onda

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // manda a onda
  pinMode(echoPin, INPUT); // recebe a onda
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
  int d=distanceCm();
  Serial.println(d);
  delay(200);
}
