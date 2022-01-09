/**
 * @file  bmp_sensor.hpp
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

#ifndef __BMP_SENSOR_HPP__
#define __BMP_SENSOR_HPP__

#include <Wire.h>
#include <Adafruit_BMP085.h>

#include "config.hpp"  

class bmp_sensor{
    protected:
        Adafruit_BMP085 bmp;
        
    public:
        /**
         * @brief Default constructor of a bmp sensor class
         */
        bmp_sensor();

        /**
         * @brief return true if bmp conected, false otherwhise
         */
        bool begin();

        /**
         * @brief return temperature value in '*C'
         */
        float readTemperature();

        /**
         * @brief return pressure value in 'Pa'
         */
        float readPressure();
        
        /**
         * @brief return altitude value in 'm'
         * 
         * @param realAltitude defines if it's the real altitude
         */
        float readAltitude(bool realAltitude = false);
};
#endif //__BMP_SENSOR_HPP__