/**
 * @file dht_sensor.hpp
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

#ifndef __DHT_SENSOR_HPP__
#define __DHT_SENSOR_HPP__

#include "DHT.h"
#include "config.hpp"
#include "pins_and_channels.hpp"  

class dht_sensor{
    protected:
        DHT dht;
        
    public:
        /**
         * @brief Default constructor of a dht sensor class
         */
        dht_sensor();


        /**
         * @brief return true if dht conected, false otherwhise
         */
        bool begin();

        /**
         * @brief return humidity value in '% of Temperature'
         */
        float readHumidity();

        /**
         * @brief return temperature value in '*C'
         */
        float readTemperature();
};
#endif //__DHT_SENSOR_HPP__