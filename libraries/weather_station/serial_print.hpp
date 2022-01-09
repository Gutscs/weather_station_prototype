/**
 * @file serial_print.hpp
 *
 * @brief Serial print class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#ifndef __SERIAL_PRINT_HPP__
#define __SERIAL_PRINT_HPP__

#include "config.hpp"
#include <Arduino.h>

class serial_print{
    protected:
        char dataStr[100];
        char buffer[7];

        /**
         * @brief convert an 
         */
        void arrayToChar(float arr[], int length);
        
    public:
        /**
         * @brief Default constructor of a serial print class
         */
        serial_print();

        /**
         * @brief initiate the serial communication
         */
        void begin();

        /**
         * @brief print the data separated by comma
         */
        void printData(float data[], int length, char datetime[]);


};
#endif //__SERIAL_PRINT_HPP__