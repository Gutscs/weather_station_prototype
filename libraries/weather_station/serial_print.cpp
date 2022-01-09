/**
 * @file serial_print.cpp
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

#include "serial_print.hpp"

/*****************************************
 * Class Methods Bodies Definitions
 *****************************************/
serial_print::serial_print(){}


void serial_print::begin(){
    this->dataStr[100] = 0;
}


void serial_print::arrayToChar(float arr[], int length){
    for (int n=0; n<length; ++n){
        dtostrf(arr[n], 5, 3, buffer);
        strcat( dataStr, buffer);
        strcat( dataStr, ", ");
    }
}

     
void serial_print::printData(float data[], int length, char datetime[]){
    this->dataStr[0] = 0;
    this->arrayToChar(data, length);
    strcat(this->dataStr, datetime);
    Serial.println(this->dataStr);
}
