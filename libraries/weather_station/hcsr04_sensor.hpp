/**
 * @file hcsr04_sensor.hpp
 *
 * @brief Hcsr04 sensor class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#ifndef __HCSR04_SENSOR_HPP__
#define __HCSR04_SENSOR_HPP__

#include <HCSR04.h>
#include "config.hpp"
#include "pins_and_channels.hpp"  

class hcsr04_sensor{
    protected:
        HCSR04 hc;
        
    public:
        /**
         * @brief Default constructor of a dht sensor class
         */
        hcsr04_sensor();

        /**
         * @brief return true if hcsr04 conected, false otherwhise
         */
        bool begin();

        /**
         * @brief return distance in 'm'
         */
        float readDistance();

        /**
         * @brief return water level in 'm'
         */
        float readWaterLevel();
};
#endif //__HCSR04_SENSOR_HPP__