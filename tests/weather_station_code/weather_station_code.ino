#include "DHT.h"
#include <HCSR04.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
//#include "config.hpp"

// constants
#define SERIAL_VEL 115200

#define DHTPIN A1 
#define DHTTYPE DHT11 

#define pino_trigger PD4
#define pino_echo PD5

DHT dht(DHTPIN, DHTTYPE); 
HCSR04 hc(pino_trigger, pino_echo);
Adafruit_BMP085 bmp;

void setup(){
    Serial.begin(SERIAL_VEL);
    Serial.println("Arduino Iniciado");
    
    dht.begin();

    if (!bmp.begin()){ //SE O SENSOR NÃO FOR INICIALIZADO, FAZ
        Serial.println("Sensor BMP180 não foi identificado! Verifique as conexões."); //IMPRIME O TEXTO NO MONITOR SERIAL
        while(1){} //SEMPRE ENTRE NO LOOP
    }
}

void loop(){
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    float dist = hc.dist();

    float temperature2 = bmp.readTemperature();
    float pressure = bmp.readPressure();
    float altitude = bmp.readAltitude();
    float altitude_real = bmp.readAltitude(101500);

    Serial.print("Umidade: ");
    Serial.print(humidity);
    Serial.println(" %t"); 

    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" *C (Grau Celsius)"); 

    Serial.print("Temperatura 2: ");
    Serial.print(temperature2);
    Serial.println(" *C  (Grau Celsius)"); 

    Serial.print("Distância: ");
    Serial.print(dist);
    Serial.println(" cm (Centímetros)"); 

    Serial.print("Pressão: ");
    Serial.print(pressure);
    Serial.println(" Pa (Pascal)"); 

    Serial.print("Altitude: ");
    Serial.print(altitude);
    Serial.println(" m (Metros)"); 

    Serial.print("Altitude Real: ");
    Serial.print(altitude_real);
    Serial.println(" m (Metros)"); 

    delay(5000);

}
