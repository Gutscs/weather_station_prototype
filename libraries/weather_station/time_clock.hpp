/**
 * @file time_clock.hpp
 *
 * @brief time_clock class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#ifndef __TIME_CLOCK_HPP__
#define __TIME_CLOCK_HPP__

#include <TimeLib.h>
#include "config.hpp"
#include <Arduino.h>

class time_clock{
    private:
        char datetime[25];
        char buffer[5];
        
        int dtSecond;
        int dtMinute;
        int dtHour;
        int dtDay;
        int dtMonth;
        int dtYear;

    public:
        /**
         * @brief Default constructor of a Time clock class
         */
        time_clock();

        /**
         * @brief Sync Arduino clock to the time received on the serial port
         */
        void processSyncMessage();

        char* getCurrentDatetime();

};
#endif //__TIME_CLOCK_HPP__