/**
 * @file  bmp_sensor.cpp
 *
 * @brief BMP sensor class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#include "bmp_sensor.hpp"

/*****************************************
 * Class Methods Bodies Definitions
 *****************************************/

bmp_sensor::bmp_sensor(){}


bool bmp_sensor::begin(){
    if (!bmp.begin()) {
        return false;
    }
    return true;
}


float bmp_sensor::readTemperature(){
    return this->bmp.readTemperature();
}

     
float bmp_sensor::readPressure(){
    return this->bmp.readPressure();
}


float bmp_sensor::readAltitude(bool realAltitude = false){
    if(realAltitude){
        return this->bmp.readAltitude(SEA_LEVEL_PRESSURE);    
    }

    return this->bmp.readAltitude();
}

