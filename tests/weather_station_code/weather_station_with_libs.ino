#include "hcsr04_sensor.hpp"
#include "bmp_sensor.hpp"
#include "dht_sensor.hpp"


hcsr04_sensor hc;
bmp_sensor bmp;
dht_sensor dht;

bool sensorError = false;

void setup(){
    Serial.begin(SERIAL_VEL);
    
    bool hcBegin = hc.begin();
    bool bmpBegin = bmp.begin();
    bool dhtBegin = dht.begin();

    if(!hcBegin ||  !bmpBegin || !dhtBegin){
        if(!hc.begin())  Serial.println("Erro ao iniciar o sensor HCSR04.");
        if(!bmp.begin()) Serial.println("Erro ao iniciar o sensor BMP180.");
        if(!dht.begin()) Serial.println("Erro ao iniciar o sensor DHT11.");    
        sensorError = true;
    }

}

void loop(){

    if(!sensorError){
        Serial.println("###########");
        Serial.print("Distancia: ");
        Serial.print(hc.readDistance());
        Serial.println(" m");
        Serial.print("Nivel da agua: ");
        Serial.print(hc.readWaterLevel());
        Serial.println(" m");
        Serial.print("Pressão: ");
        Serial.print(bmp.readPressure());
        Serial.println(" Pa");
        Serial.print("Altitude: ");
        Serial.print(bmp.readAltitude());
        Serial.println(" m");
        Serial.print("Temperatura (bmp): ");
        Serial.print(bmp.readTemperature());
        Serial.println(" ºC");
        Serial.print("Temperatura (dht): ");
        Serial.print(dht.readTemperature());
        Serial.println(" ºC");
        Serial.print("Umidade: ");
        Serial.print(dht.readHumidity());
        Serial.println(" %");
    }
    
    delay(5000);
}
