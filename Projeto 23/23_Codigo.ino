// O Código do livro não funciona, fiz um diferente

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
 
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};
 
byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};
 
byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};
 
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
 
void setup() 
{
  // inicializa o LCD e configura o número de colunas e linhas:
    lcd.begin(16, 2);
 
    lcd.createChar(0, heart);
    lcd.createChar(1, smiley);
    lcd.createChar(2, frownie);
    lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
 
  // coloca o cursor no canto superior esquerdo
    lcd.setCursor(0, 0);
 
  // Imprime uma mensagem para o lcd.
    lcd.print("I");
    lcd.write(byte(0)); // quando chamar lcd.write() '0' deve ser convertido como um byte
    lcd.print("Sorria!");
    lcd.write((byte) 1);
 
}
 
void loop() 
{
    int delayTime = 1000;
  
    // coloca o cursor na linha inferior, 5ª posição:
    lcd.setCursor(4, 1);
  
  // desenhe o homenzinho de braços para baixo:
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);

  // puxar seus braços para cima:
    lcd.write(4);
    delay(delayTime);
}
