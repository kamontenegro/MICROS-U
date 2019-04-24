/******UNIVERSIDAD TECNICA DEL NORTE
 *******SISTEMAS MICROPROCESADOS
 ********Alumno: Kevin Montenegro
 *********Fecha:24/04/2019
 **********Deber N1 
 */

 //declaracion de variables y pines mediante array led
int i=0; int j=0; int k=0;
int led[8]={5,6,7,8,9,10,11,12};
long randon;
void setup() {
  //para iniciar todos los pines
  for(i=0;i<8;i++);
  {
    pinMode(led[i],OUTPUT);
  }
  i=0;

  for(j=0;j<8;j++);
  {
    pinMode(led[j],OUTPUT);
  }
  j=0;

}

void loop() {
  /*
   * 1 EJERCICIO PRENDRA Y APAGUE 
   *          LEDS PARES 
   */
   for(;i<8;i++){
    if(i%2==0){
    digitalWrite(led[i],HIGH);
    delay(200);
    }
    }
   for(;i>=0;i--){
    if(i%2==0){
    digitalWrite(led[i],LOW);
    delay(200);
    }
    }
    i=0;

  /*
   * 2 EJERCICIO PRENDRA Y APAGUE 
   *         LEDS IMPARES
   */
   for(;i<8;i++){
    if(i%2==1){
    digitalWrite(led[i],HIGH);
    delay(200);
    }
    }
   for(;i>=0;i--){
    if(i%2==1){
    digitalWrite(led[i],LOW);
    delay(200);
    }
    }
    i=0;

  /*
   * 3 EJERCICIO RANDOM 
   *         
   */
   for(;i<8;i++){
    randon= random(5,13);
    digitalWrite(randon,HIGH);
    delay(200);
    digitalWrite(randon,LOW);
    delay(200);
    }
    i=0;

  /*
   * 4 EJERCICIO 
   * Prender leds de los extremos
   *         al medio
   */
   for(;i<=3;i++){
    digitalWrite(led[i],HIGH);
    delay(150);}
    for(j=7;j>=4;j--){
    digitalWrite(led[j],HIGH);
    delay(150);
      }
   
    for(i=3;i>=0;i--){
    digitalWrite(led[i],LOW);
    delay(150);
    for(;j<=7;j++){
    digitalWrite(led[j],LOW);
    delay(150);
  
    }
  }
    i=0;
    j=0;

 /* 5 EJERCICIO
  *  PRENDER MULTIPLOS DE 3
  */
     for(;i<8;i++){
    if(i%3==0){
    digitalWrite(led[i],HIGH);
    delay(200);
    }
    }
   for(;i>=0;i--){
    if(i%3==0){
    digitalWrite(led[i],LOW);
    delay(200);
    }
    }
    i=0;
    j=0;
  
}
