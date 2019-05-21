/*
 *      UTN-FICA
 *    CIERCOM- MICROPROCESADOS
 *   Alumno: Kevin Montenegro
 *   Fecha:19/05/2019
 *   VALIDADOR DE PLACA
 *   
 * 
 */
 String placa="";
 
void setup() {
 Serial.begin(9600);
 Serial.println("---Ingrese placa---");
 Serial.println("Formato a ingresar ASD-0000");
}

void loop() {
  if(Serial.available()>0){
    placa=Serial.readString();
    placa.toUpperCase();  
    int tam=placa.length();
    Serial.println("Placa Ingresada : " + placa );
    if(tam<=9){
      if(placa.substring(3,4)=="-"){
        if(placa.substring
        
        //Serial.println("Tiene guion");
        if(placa.substring(0,1)=="A"){
          Serial.println("Pertenece a la provincia de Azuay");
        }
        if(placa.substring(0,1)=="B"){
          Serial.println("Pertenece a la provincia de Bolivar");
        }
        if(placa.substring(0,1)=="C"){
          Serial.println("Pertenece a la provincia de Carchi");
        }
        if(placa.substring(0,1)=="U"){
          Serial.println("Pertenece a la provincia de Cañar");
        }
        if(placa.substring(0,1)=="X"){
          Serial.println("Pertenece a la provincia de Cotopaxi");
        }
        if(placa.substring(0,1)=="H"){
          Serial.println("Pertenece a la provincia de Chimborazo");
        }
        if(placa.substring(0,1)=="O"){
          Serial.println("Pertenece a la provincia de El Oro");
        }
        if(placa.substring(0,1)=="E"){
          Serial.println("Pertenece a la provincia de Esmeraldas");
        }
        if(placa.substring(0,1)=="W"){
          Serial.println("Pertenece a la provincia de Galapagos");
        }
        if(placa.substring(0,1)=="G"){
          Serial.println("Pertenece a la provincia de Guayas");
        }
        if(placa.substring(0,1)=="I"){
          Serial.println("Pertenece a la provincia de Imbarura");
        }
        if(placa.substring(0,1)=="L"){
          Serial.println("Pertenece a la provincia de Loja");
        }
        if(placa.substring(0,1)=="R"){
          Serial.println("Pertenece a la provincia de Los Rios");
        }
        if(placa.substring(0,1)=="M"){
          Serial.println("Pertenece a la provincia de Manabi");
        }
        if(placa.substring(0,1)=="V"){
          Serial.println("Pertenece a la provincia de Morona Santiago");
        }
        if(placa.substring(0,1)=="N"){
          Serial.println("Pertenece a la provincia de Napo");
        }
        if(placa.substring(0,1)=="S"){
          Serial.println("Pertenece a la provincia de Pastaza");
        }
        if(placa.substring(0,1)=="P"){
          Serial.println("Pertenece a la provincia de Pichincha");
        }
        if(placa.substring(0,1)=="Q"){
          Serial.println("Pertenece a la provincia de Orellana");
        }
        if(placa.substring(0,1)=="K"){
          Serial.println("Pertenece a la provincia de Sucumbios");
        }
        if(placa.substring(0,1)=="T"){
          Serial.println("Pertenece a la provincia de Tungurahua");
        }
        if(placa.substring(0,1)=="Z"){
          Serial.println("Pertenece a la provincia de Zamora Chinchipe");
        }
        if(placa.substring(0,1)=="Y"){
          Serial.println("Pertenece a la provincia de Santa Elena");
        }
        if(placa.substring(0,1)=="J"){
          Serial.println("Pertenece a la provincia de Santo Domingo de los Tsachilas");
        }
      }
      else{
        Serial.println("Ponga guion ");
      }
    }
         //si tiene menos de 9 caracteres, despues del "-" ponga 0 para validar
          if(tam<9){
            String placavalida =placa.substring(0,4)+"0"+placa.substring(4,placa.length());   
            Serial.println("Placa validada : " + placavalida);
          }
          if(tam>9){
          Serial.println("Exceso de digitos");
          }
          Serial.println("--------------------------");
      }
   }
