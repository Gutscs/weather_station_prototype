/**
 * @file  hcsr04_sensor.cpp
 *
 * @brief HCSR04 sensor class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#include "hcsr04_sensor.hpp"

/*****************************************
 * Class Methods Bodies Definitions
 *****************************************/
hcsr04_sensor::hcsr04_sensor(): hc(HCTRIGGER, HCECHO){}


bool hcsr04_sensor::begin(){
    if (isnan(hc.dist())) {
        return false;    
    } 
    return true;
}


float hcsr04_sensor::readDistance(){
    return this->hc.dist()/100;
}

     
float hcsr04_sensor::readWaterLevel(){
    return SENSOR_HEIGHT_IN_M - readDistance();
}
