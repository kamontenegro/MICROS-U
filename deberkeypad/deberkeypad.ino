/*
                           Universidad Tecnica del Norte
                            Fica - Ciercom
                            Alumno: Kevin Montenegro
                            Fecha:16/06/2019

                          Deber Teclado Matricial 2B
   Instrucciones:  Validar una contraseña de 4 dígitos visualizado en una lcd
   Se realizó la simulacion en Arduino MEGA 2560 con el fin de no interferir
   con la comunicacion serial en puerto 0 y 1, tomando otros pines.
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
//pines necesarios para lcd
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
/*
 * configuracion de keypad
 * designamos el tamaño de filas y columnas
 * integramos los valores y el orden
 * asignacion de pines
 * nombre de keypad
 */
const byte FILAS = 4;
const byte COLUMNAS = 4;
char hexaKeys[FILAS][COLUMNAS] {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte filasPin[FILAS] = {21, 20, 19, 18};
byte colPin[COLUMNAS] = {14, 15, 16, 17};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), filasPin, colPin, FILAS, COLUMNAS);
char valor [] = "1997";
char contra [4];
int cont = 0;

void setup() {

}

void loop() {
  char key = customKeypad.getKey();//obtencion de la pulsacion de keypad
  if (key != NO_KEY) {   //verificador de puulsacion
    contra[cont] = key;
    cont = cont + 1;
    //        lcd.setCursor(0,0);
    //        lcd.print(key);
    if (cont == 4) {    //limitacion de contraseña a 4 carac
      //si lo pulsado es igual a "valor" predefinido 
      if (contra[0] == valor[0] && contra[1] == valor[1] && contra[2] == valor[2] && contra[3] == valor[3]) {
        lcd.setCursor(0, 0);
        lcd.print("Valida");

      }
      if (contra != valor) { // compr si es diferente "invalida"
        lcd.print("Invalida");
      }
      cont = 0;       // contador en 0
    }
  }
}
