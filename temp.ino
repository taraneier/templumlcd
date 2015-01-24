#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;
const float baselineTemp = 20.0;
const int lightPin = A3;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print("Light: ");
  //  for (int pinNumber = 2; pinNumber < 5; pinNumber++){
  //    pinMode(pinNumber, OUTPUT);
  //    digitalWrite(pinNumber, LOW);
  //  }
}

void loop(){
  int sensorVal = analogRead(tempPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100 * 1.8 + 32;
  int lVal = analogRead(lightPin);
//  lcd.clear();
//  lcd.print("Deg F: ");
//  lcd.setCursor(0,1);
//  lcd.print("Light: ");
  lcd.setCursor(9, 0);
  lcd.print("            ");
  lcd.setCursor(9, 0);
  lcd.print(temperature);
  lcd.setCursor(8, 1);
  lcd.print("            ");
  lcd.setCursor(8, 1);
  if(lVal < 100){
    lcd.print(" ");
  }
  if(lVal < 10){
    lcd.print(" ");
  }
  lcd.print(lVal); 
  delay(1000);
//  Serial.print("Light Value: ");
//  Serial.print(lVal);
//  Serial.print("  Sensor Value: ");
//  Serial.print(sensorVal);
//  Serial.print(", Volts: ");
//  Serial.print(voltage);
//  Serial.print(", degrees C: ");
//  Serial.println(temperature);
}


