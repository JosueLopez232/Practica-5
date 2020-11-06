#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
 pinMode(A0,INPUT);
 lcd.begin(16, 2);
 Serial.begin(9600);
 
}

void loop() {
  float X,A,B;
  float D=.0146;
  float H=.5322;
  float Y=3.8889;
  delay(1000);
  X=analogRead(A0);
  X=X*(5.0/1023.0);
  lcd.setCursor(0,0);
  lcd.print("El Voltaje :");
  lcd.setCursor(11,0);
  lcd.print(X);
  
  Y=Y-X;
  A = (H + sqrt( (H*H) - (4 * D * Y) ) ) / (2.0 * D);
  B = (H - sqrt( (H*H) - (4 * D * Y) ) ) / (2.0 * D);
   Serial.print(" X1 ");
   Serial.println(A);
   Serial.print(" x2 ");
   Serial.println(B);
   lcd.setCursor(0,1);
   lcd.print("La Distancia :");
   lcd.setCursor(13,1);
   lcd.print(B);
    
 }
