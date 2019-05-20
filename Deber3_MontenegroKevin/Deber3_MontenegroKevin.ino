/*
 *          UTN-FICA
 *          CIERCOM
 *    Alumno: Kevin Montenegro
 *      Fecha:19/05/2019
 *     VALIDADOR DE CEDULA
 *     se valida que ingrese el "-"
 *     digito 2,3 no mayor a 6
 */
 
String dato = "";
String d1,verificador;
int cond [10]={2,1,2,1,2,1,2,1,2};
int i=0;
int sum =0;
void setup() {
  Serial.begin(9600);
  Serial.println("Bienvenido a validar cedula");
  Serial.println("Cedula : " + dato);
 }
 
void loop() {
  if(Serial.available()>0){
   dato=Serial.readString();//lee datos
   Serial.println(dato);//imprimir datos
    if (dato.length()==11){ //tam ced
      if(dato.substring(9,10)=="-"){ //si tiene -, quitelo y sume el 11
       d1=dato.substring(0,dato.indexOf("-"))+ dato.substring(10,11);
        if(dato.substring(2,3).toInt()<6){ //si el valor que esta ene 2,3 es <6 pase
         verificador=dato.substring(10,11); //Extraer el último dígito de la cédula
         int num=verificador.toInt();
        for (;i<d1.length() ;i++){ //Multiplicar por el vector verificador con los 9 primeros dígitos
          int mul=cond[i]*d1.substring(i,i+1).toInt();
          if (mul>9){
           mul=mul-9;
            }
            sum=sum+mul;
           }
       if (sum%10== 0){
        if (sum/10 ==d1.substring(9,10).toInt()){
         Serial.println("Correcto");
            }
          }
          else{
           int val=(((sum / 10) + 1)*10)-sum;
            if (val==d1.substring(9,10).toInt()) {
             Serial.println("Correcta");
             sum = 0;
                }
           }
        }
          else
        {
          Serial.println("Incorrecta"); // dig 2,3 mayor a 6
        }
      }
        else
      {
        Serial.println("Falta guion"); // guion
        }
    }
      else
    {
      Serial.println("Incorrecta pasa de 11 digitos");//dimens
    }
  }
}
