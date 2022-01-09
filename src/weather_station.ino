#include "time_clock.hpp"
#include "hcsr04_sensor.hpp"
#include "bmp_sensor.hpp"
#include "dht_sensor.hpp"
#include "serial_print.hpp"

hcsr04_sensor hc;
bmp_sensor bmp;
dht_sensor dht;
time_clock tc;
serial_print sp;

bool sensorError = false;
float waterLevel;
float pressure;
float altitude;
float humidity;
float temperature;
char datetime[25];

unsigned long previous_millis;
unsigned long current_millis;

void setup(){
    previous_millis = millis();
    Serial.begin(SERIAL_VEL);
    tc.processSyncMessage();
    
    sp.begin();
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
        current_millis = millis();

        if(current_millis - previous_millis > SAMPLING_TIME){
            previous_millis = current_millis;

            waterLevel = hc.readWaterLevel();
            pressure = bmp.readPressure();
            altitude = bmp.readAltitude(true);
            humidity = dht.readHumidity();
            temperature = bmp.readTemperature();
            
            strcpy(datetime, tc.getCurrentDatetime());
            float data[5] = {waterLevel, pressure, altitude, humidity, temperature};
            
            sp.printData(data, 5, datetime);
        }  
      
    }
}