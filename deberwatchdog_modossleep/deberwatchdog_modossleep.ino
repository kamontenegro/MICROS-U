#include <LowPower.h>

#include <LiquidCrystal.h>
#include <EEPROM.h>


/*
   Universidad Tecnica del Norte
   Fica - Ciercom
   Nombre: Kevin Montenegro
   Fecha:31/07/2019

   Deber WatchDog y modos sleep

  Uso de LowPower de:https://aprendiendoarduino.wordpress.com/2016/11/16/arduino-sleep-mode/
        Con la librería lowpower es muy fácil poner en modo sleep a Arduino con una línea como:
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
        Hay tres maneras de despertar un Arduino del modo Sleep:
          Interrupciones hardware
          Timers y WDT que es un timer un tanto peculiar
          UART o puerto serie.

*/

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
float cad;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Me desperte");
  Serial.println("on..");
  delay(50);
}

void loop() {
  cad = analogRead(A1);
  lcd.setCursor(0, 1);
  lcd.println(cad);
  Serial.println("EN 4 S lee datos ");
  delay(50);
  LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);

}
