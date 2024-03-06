// Definir los pines de entrada y salida
const int pinEntrada1 = 12;
const int pinEntrada2 = 6; //Final carrera subida
const int pinEntrada3 =5;  //Final carrera baixada
const int pinSalida1 = 8;  //Subida
const int pinSalida2 = 7;  //Baixada

int tieneQueMoverse = 0;
int seEstaMoviendo = 0;
int direccion = 0;		 //0 = Subir ; 1 = Bajar
int valorPinEntrada2 =0; //Valor final carrera subida
int valorPinEntrada3 =0; //Valor final carrera bajada

void setup (){
//Activar pins
	pinMode(pinEntrada1,INPUT);		//definir entrada 1 
	pinMode(pinEntrada2,INPUT);		//definir entrada 2
	pinMode(pinEntrada3,INPUT);		//definir entrada 3
	pinMode(pinSalida1,OUTPUT);		//definir salida 1
	pinMode(pinSalida2,OUTPUT);  	//definir salida 2
}
void loop () {
  valorPinEntrada2 = digitalRead(pinEntrada2);	//lectura final carrrera subida
  valorPinEntrada3 = digitalRead(pinEntrada3);	//lectura fianl carrera baixada
  while (digitalRead(pinEntrada1)) {	//Lectura del pulsador 
  	tieneQueMoverse = 1;
  }  
  if (tieneQueMoverse){
	tieneQueMoverse = 0;
  if (seEstaMoviendo){		        //Si se esta moviendo algun motor
    digitalWrite (pinSalida1,LOW);	//Motor subida para
    digitalWrite (pinSalida2,LOW);  //Motor baixada para
    seEstaMoviendo = 0;
    direccion = !direccion;    		//Invertir Giro
  }else{							//Si no se esta moviendo	
    if(direccion){					//Bajada
      seEstaMoviendo = 1;
      digitalWrite (pinSalida2,HIGH);   //Actiiva motor baixada 
    }else{								//
      seEstaMoviendo = 1;
      digitalWrite (pinSalida1,HIGH);	//Activa motor subida  
   }
  }
 }
  if (seEstaMoviendo){
    if (direccion && valorPinEntrada3){
     digitalWrite(pinSalida2,LOW);
     seEstaMoviendo = 0;
     direccion = !direccion;   //iinvertir Giro
    }
    if (!direccion && valorPinEntrada2){
      digitalWrite(pinSalida1,LOW);
     seEstaMoviendo = 0;
     direccion = !direccion;
    }
    
  }
}

