//Programa : Serial port + sensor ultrasonico
//by Wender Fernandes

#include <Ultrasonic.h>
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor
Ultrasonic ultrasonic(pino_trigger, pino_echo);

String inData;
void setup() {    
    Serial.begin(9600);
    Serial.println("sensor pronto");    
}

void medir(){  
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);      
  Serial.println(cmMsec);  
}

void loop() {
    while (Serial.available() > 0){
        char recieved = Serial.read();
        inData += recieved;        
        if (recieved == '\n'){
            if(inData == "1\n"){              
              medir();
            }            
            inData = "";
        }
    }    
}