/*
 * UNIVERSIDAD TECNICA DEL NORTE
 *        FICA-CIERCOM
 *     SISTEMAS MICROPROCESADOS
 *    ALUMNO: KEVIN MONTENEGRO
 *    FECHA:04/05/2019
 *  Deber2.REalizar un programa que mediante dos pusadores   
 *  (operando1 y operando 2)sumen su valor de veces(hasta 25)
 *  cada uno que han sido presionados. Dicho valor se mostrara
 *  en display multiplexados al presionar un tercer pulsador
 */

// declaracion de variables para el botton
 int op1=0;
 int op2=1;
 int res=2;
 int on=0;
 //creamos un contador para cada boton
 int contador1=0;
 int contador2=0;
 //variable para sumar
 int resul=0; //variable para guardar el resultado
 
//declaracion de variables para el display
 int A=6;
 int B=5;
 int C=4;
 int D=3;
 int unidades1;
 int decenas1;
 int dec1=8;
 int uni1=9;
 
void setup() {

 //activacion de botones
 pinMode(op1,INPUT_PULLUP);
 pinMode(op2,INPUT_PULLUP);
 pinMode(res,INPUT_PULLUP);
 //activacion de display
 pinMode(A,OUTPUT);
 pinMode(B,OUTPUT);
 pinMode(C,OUTPUT);
 pinMode(D,OUTPUT);
 //activacion deacuerdo a unidades o decenas
 pinMode(uni1,OUTPUT);
 pinMode(dec1,OUTPUT);

}

void loop() {
 //activacion de boton
 if(digitalRead(op1)==LOW)
 {
  delay(300);
  on=1-on;
  if(contador1<25)
    contador1++;
    else 
      contador1=0;
  
    decenas1=contador1/10;
    unidades1=contador1-decenas1*10;
    digitalWrite(dec1,HIGH);
    digitalWrite(uni1,LOW);
    contador(decenas1);
    delay(50);
    digitalWrite(dec1,LOW);
    digitalWrite(uni1,HIGH);
    contador(unidades1);
    delay(50);
}

 if(digitalRead(op2)==LOW)
 {
  delay(300);
  on=1-on;
  if(contador2<25)
    contador2++;
    else 
      contador2=0;
  

    decenas1=contador2/10;
    unidades1=contador2-decenas1*10;
    digitalWrite(dec1,HIGH);
    digitalWrite(uni1,LOW);
    contador(decenas1);
    delay(50);
    digitalWrite(dec1,LOW);
    digitalWrite(uni1,HIGH);
    contador(unidades1);
    delay(50);
}
 if(digitalRead(res)==LOW)
 {
  delay(300);
  resul=contador1+contador2;
 } 
    decenas1=resul/10;
    unidades1=resul-decenas1*10;
    digitalWrite(dec1,HIGH);
    digitalWrite(uni1,LOW);
    contador(decenas1);
    delay(50);
    digitalWrite(dec1,LOW);
    digitalWrite(uni1,HIGH);
    contador(unidades1);
    delay(50);
}

//para activar el display del 0 al 9 en forma binaria
void contador (int dato){
  switch(dato){
    case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
    case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
  }

}
