/**
 * @file  dht_sensor.cpp
 *
 * @brief DHT sensor class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#include "dht_sensor.hpp"

/*****************************************
 * Class Methods Bodies Definitions
 *****************************************/
dht_sensor::dht_sensor(): dht(DHTPIN, DHTTYPE){}


bool dht_sensor::begin(){
    dht.begin();

    if (isnan(dht.readHumidity()) || isnan(dht.readTemperature())) {
        return false;    
    } 
    return true;
}


float dht_sensor::readTemperature(){
    return this->dht.readTemperature();
}

     
float dht_sensor::readHumidity(){
    return this->dht.readHumidity();
}
