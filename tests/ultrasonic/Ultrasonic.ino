//Carrega a biblioteca do sensor ultrassonico
#include <HCSR04.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 

HCSR04 hc(pino_trigger, pino_echo);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{ Serial.begin(9600); }

void loop() 
{ Serial.println( hc.dist() ); } //return current distance (cm) in serial