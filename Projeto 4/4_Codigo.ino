int tempotrave = 5000;
unsigned long changeTime;
  
void setup()
{
  pinMode(13, OUTPUT); // Vermelho Carro
  pinMode(12, OUTPUT); // Amarelo Carro
  pinMode(8, OUTPUT); // Verde Carro
  pinMode(7, OUTPUT); // Vermelho Pedestre
  pinMode(4, OUTPUT); // Verde Pedestre
  pinMode(2 , INPUT); // Botao
  
  digitalWrite(8, HIGH); // Aberto para carros
  digitalWrite(7, HIGH); // Fechado para pedreste
  
}  


void loop()
{
 int state = digitalRead(2);
  
 if (state == HIGH && (millis() - changeTime) > 3000) 
 {
  digitalWrite(8, LOW); // apaga o verde carro
    digitalWrite(12, HIGH); // acende o amarelo carro
    delay(2000);
   
    digitalWrite(12, LOW); // apaga o amarelo carro
    digitalWrite(13, HIGH); // acende vermelho carro 
    delay(1000);
   
    digitalWrite(7, LOW); // apaga vermelho do pedestre
    digitalWrite(4, HIGH); // acende verde ao pedestre
    delay(2000);// tempo de atravessar o pedestre
    
      for (int x=0; x<5; x++) {
      digitalWrite(4, HIGH); // pisca o verde do pedestre
      delay(250);
      digitalWrite(4, LOW); // apaga apos piscar
      delay(250);
      }
  
  digitalWrite(7, HIGH); // acende vermelho do pedestre
  delay(500);
  
  digitalWrite(13, LOW); // apaga vermelho do carro
  delay(1000);
  
  digitalWrite(8, HIGH); // acende verde do carro 
  changeTime = millis(); 
 } 
}  
