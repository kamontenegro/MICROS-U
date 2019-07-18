/*    UNIVERSIDAD TECNICA DEL NORTE
        FICA - CIERCOM
      NOMBRE: KEVIN MONTENEGRO

      DEBER: REALIZAR UN RELOJ CON ALARMA ALMACENADA EN EEPROM
*/

#include <EEPROM.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int horero, minutero, segundero, i;
int alarma_minutero, alarma_horero;
int contador;
String dato;

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  //para la EEPROM
  segundero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  horero = EEPROM.read(2);
  alarma_minutero = EEPROM.read(3);
  alarma_horero = EEPROM.read(4);

  MsTimer2::set(100, reloj); //varia dependiendo la velocidad del reloj
  attachInterrupt(0, menu, LOW);
  attachInterrupt(1, alarma, LOW);
  MsTimer2::start();
  //salida tono
  pinMode(6, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    dato = Serial.readString();
    contador++;
  }
  switch (contador) {
    case 0:
      Serial.println("APAGADA");
      break;
    case 1:
      Serial.println("ENCENDIDO");
      contador = 0;
      break;

  }
  //comparacion para activar tono
  if (contador == 1) {
    if ( EEPROM.read(2) == EEPROM.read(4) && EEPROM.read(1) == EEPROM.read(3) ) {
      Serial.println("ON");
      digitalWrite(6, HIGH);
    }
  }
  else {
    Serial.println("OF");
    digitalWrite(6, LOW);
  }
}

void reloj () {
  if (segundero <= 60) {
    segundero++;
  }
  else {
    segundero = 0;
    if (minutero <= 60) {
      minutero++;
      EEPROM.update(1, minutero);
    }
    else {
      EEPROM.update(1, minutero);
      minutero = 0;
      if (horero < 12) {
        horero++;
        EEPROM.update(2, horero);
      }
      else {
        EEPROM.update(2, horero);
        horero = 0;
      }
    }
  }
  imprimir();
}

void alarma() {
  if (i == 1) {
    if (alarma_minutero <= 60) {
      alarma_minutero++;
      EEPROM.update(3, alarma_minutero);
    }
    else {
      alarma_minutero = 0;
      EEPROM.update(3, alarma_minutero);
    }
  }
  if (i == 2) {
    if (alarma_horero < 12) {
      alarma_horero++;
      EEPROM.update(4, alarma_horero);
    }
    else {
      alarma_horero = 0;
      EEPROM.update(4, alarma_horero);
    }
  }
}

void menu() {
  i++;
  switch (i) {

    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Minutos");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Hora");
      break;

    default:
      i = 0;
  }
}
void imprimir() {
  if (segundero < 10) {
    lcd.clear();
    lcd.setCursor(8, 0);
    lcd.print(':');
    lcd.setCursor(9, 0);
    lcd.print('0');
    lcd.setCursor(10, 0);
    lcd.print(segundero);
  }
  else {
    lcd.clear();
    lcd.setCursor(8, 0);
    lcd.print(':');
    lcd.setCursor(9, 0);
    lcd.print(segundero);
  }
  if (minutero < 10) {
    lcd.setCursor(5, 0);
    lcd.print(':');
    lcd.setCursor(6, 0);
    lcd.print('0');
    lcd.setCursor(7, 0);
    lcd.print(minutero);
  }
  else {
    lcd.setCursor(5, 0);
    lcd.print(':');
    lcd.setCursor(6, 0);
    lcd.print(minutero);
  }
  if (horero < 10) {
    lcd.setCursor(3, 0);
    lcd.print('0');
    lcd.setCursor(4, 0);
    lcd.print(horero);
  }
  else {
    lcd.setCursor(3, 0);
    lcd.print(horero);
  }
}
