/*
   Universidad Tecnica del Norte
   Fica - Ciercom
   Sistemas Microprocesados
   Nombre : Kevin Montenegro
   Fecha:28/07/2019

   Deber WatchDog
    Realizar un programa que reinicie el sistema al tener la hora 00:10:50.
    Cuando vuelva a funcionar, deberá empezar con la hora 00:11:10.
    Es proceso se observa en una LCD.
*/
#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <EEPROM.h>
#include <avr/wdt.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int segundos, minutos, horas;
void setup() {
  //  //Borrar estado de memoria
  //        EEPROM.write(0, 0);
  //        EEPROM.write(1, 0);
  //        EEPROM.write(2, 0);

  //lcd y comunicacion
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print('RELOJ');
  segundos = EEPROM.read(0);
  minutos = EEPROM.read(1);
  horas = EEPROM.read(2);

  Timer1.initialize(10000);
  Timer1.attachInterrupt(reloj);
}

void loop() {
  Serial.println("on");
}
//metodo reloj
void reloj () {
  if (segundos < 59) {
    segundos++;
    if (segundos % 10 == 0) {
      EEPROM.update(0, segundos);
      //      Serial.println("actualizado segundos");
    }
  } else {
    segundos = 0;
    EEPROM.update(0, segundos);
    //    Serial.println("actualizado segundos");
    if (minutos < 59) {
      minutos++;
      EEPROM.update(1, minutos);
      //      Serial.println("actualizado minutos");
    } else {
      minutos = 0;
      EEPROM.update(1, minutos);
      //      Serial.println("actualizado minutos");
      if (horas < 23) {
        horas++;
        EEPROM.update(2, horas);
        //        Serial.println("actualizado horas");
      } else {
        horas = 0;
        EEPROM.update(2, horas);
        //        Serial.println("actualizado horas");
      }
      //posicionamiento e impresion
      if (segundos < 10) {
        lcd.clear();
        lcd.setCursor(8, 1);
        lcd.print(':');
        lcd.setCursor(9, 1);
        lcd.print('0');
        lcd.setCursor(10, 1);
        lcd.print(segundos);
      } else {
        lcd.clear();
        lcd.setCursor(8, 1);
        lcd.print(':');
        lcd.setCursor(9, 1);
        lcd.print(segundos);
      }
      if (minutos < 9) {
        lcd.setCursor(5, 1);
        lcd.print(':');
        lcd.setCursor(6, 1);
        lcd.print('0');
        lcd.setCursor(7, 1);
        lcd.print(minutos);
      } else {
        lcd.setCursor(5, 1);
        lcd.print(':');
        lcd.setCursor(6, 1);
        lcd.print(minutos);
      }
      if (horas < 10) {
        lcd.setCursor(3, 1);
        lcd.print('0');
        lcd.setCursor(4, 1);
        lcd.print(horas);
      } else {
        lcd.setCursor(4, 1);
        lcd.print(horas);
      }
      //verificar si funciona
      Serial.println("reloj on");
    }
    //condicion de reinicio
    if (horas == 0 && minutos == 10 && segundos == 50 ) {
      Serial.println("Reinicia Sistema");
      //tiempo
      wdt_enable(WDTO_500MS);
    }
  }
}
