#include <TimerOne.h>
/*
    UNIVERSIDAD TECNICA DEL NORTE
        FICA-CIERCOM
      NOMBRE: KEVIN MONTENEGRO
      FECHA: 07/07/2019
      
  REALIZAR UN PROGRAMA DE SEGURIDAD DOMOTICA QUE PERMITA ANECENDER LAS LUCES DE UN DOMICILIO
  DE 5 HABITACION DE FORMA ALEATORIA SOLO EN HORARIO NOCTURNO, EL SISTEMA SE ACTIVA AL INGRESAR
  UNA CONTRASEÑA POR COMUNICACION SERIAL.
     
*/
int menu = 0, i = 0;
String clave;
boolean validacion;
int horero = 0, minutero = 0, segundero = 0;
int foco1 = 8, foco2 = 9, foco3 = 10, foco4 = 11, foco5 = 12;
long randon;

void setup() {

  //focos
  pinMode(foco1, OUTPUT);
  pinMode(foco2, OUTPUT);
  pinMode(foco3, OUTPUT);
  pinMode(foco4, OUTPUT);
  pinMode(foco5, OUTPUT);

  //Inicializacion
  Serial.begin(9600);
  attachInterrupt(0, menus, LOW);
  Timer1.initialize(12500);
  Timer1.attachInterrupt(reloj);
}

void loop() {
  if (menu == 2) {
    if (Serial.available() > 0) {
      clave = Serial.readString();
      if (clave.length() == 4) {
        validacion = clave.equals("CASA");
        if (validacion == true) {
          Serial.println("Sistema Activado");
          accion();
          //prueba de encendido de leds
          //          digitalWrite(foco1, HIGH);
          //          digitalWrite(foco2, HIGH);
          //          digitalWrite(foco3, HIGH);
          //          delay(1000);

        }
        else {
          Serial.println("Error en contraseña");
        }
      }
      else {
        Serial.println("Error en contraseña");
      }
    }
  }
}

void accion () {
  if ( segundero >= 0 && minutero >= 10 && horero >= 18) {
    Serial.println("Encendiendo focos ");
    for (; i < 6; i++) {
      randon = random(0, 4);
      switch (randon) {
        case 0:
          digitalWrite(foco1, HIGH);
          delay(500);
          digitalWrite(foco2, HIGH);
          digitalWrite(foco1, LOW);
          break;

        case 1:
          digitalWrite(foco3, HIGH);
          delay(500);
          digitalWrite(foco4, HIGH);
          delay(500);
          digitalWrite(foco2, LOW);
          break;

        case 2:
          digitalWrite(foco3, LOW);
          delay(500);
          digitalWrite(foco5, HIGH);
          delay(500);
          digitalWrite(foco3, LOW);
          break;
        case 3:
          digitalWrite(foco4, LOW);
          delay(500);
          digitalWrite(foco5, HIGH);
          delay(500);
          digitalWrite(foco1, LOW);
          break;
        case 4:
          digitalWrite(foco3, LOW);
          delay(500);
          digitalWrite(foco4, HIGH);
          delay(500);
          digitalWrite(foco1, LOW);
          break;

      }
      i = 0;
    }
  }
}
void menus() {
  switch (menu) {
    case 0:
      Serial.println("Bienvenido");
      menu++;
      break;

    case 1:
      Serial.println("Ingrese contraseña");
      menu++;
      break;

    case 2:
      Serial.println("Sistema Apagado");
      menu = 0;
      break;
  }
}

void reloj() {
  if (segundero < 60) {
    segundero++;
    Serial.print(horero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.print(segundero);
    Serial.print('-');
  }
  else { //else seg
    segundero = 0;
    Serial.print(horero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.print(segundero);
    Serial.print('-');
    if (minutero < 60) {
      minutero++;
      Serial.print(horero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.print(segundero);
      Serial.print('-');
    }//else minutero
    else {
      minutero = 0;
      Serial.print(horero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.print(segundero);
      Serial.print('-');
      if (horero < 24) {
        horero++;
        Serial.print(horero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.print(segundero);
        Serial.print('-');
      }
      else {
        horero = 0;
        Serial.print(horero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.print(segundero);
        Serial.print('-');
      }
    }
  }
}
