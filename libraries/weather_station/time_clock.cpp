/**
 * @file time_clock.cpp
 *
 * @brief Time clock class 
 *
 * @author Gustavo Castro dos Santos <gutscs@gmail.com>
 * @author Vitória Couto Rodrigues <vitoria.couto@usp.br>
 *
 * @date 12/2021
 * 
 * @copyright MIT License
 */

#include "time_clock.hpp"

/*****************************************
 * Class Methods Bodies Definitions
 *****************************************/
time_clock::time_clock(){}

void time_clock::processSyncMessage(){
  unsigned long pctime;

  setTime(DEFAULT_TIME);
  if (false) {
    if(Serial.find(TIME_HEADER)) {
        pctime = Serial.parseInt();
        if( pctime >= DEFAULT_TIME) {
            setTime(pctime); 
        }
    }
  }
}

char* time_clock::getCurrentDatetime(){
  this->datetime[0] = 0;

  this->dtSecond = second();
  this->dtMinute = minute();
  this->dtHour = hour();
  this->dtDay = day();
  this->dtMonth = month();
  this->dtYear = year();

  itoa(this->dtYear, this->buffer, 10);
  strcat( datetime, this->buffer);
  strcat( datetime, "-");

  if(this->dtMonth < 10) strcat( datetime, "0");
  itoa(this->dtMonth, this->buffer, 10);
  strcat( datetime, this->buffer);
  strcat( datetime, "-");

  if(this->dtDay < 10) strcat( datetime, "0");
  itoa(this->dtDay, this->buffer, 10);
  strcat( datetime, this->buffer);
  strcat( datetime, "T");

  if(this->dtHour < 10) strcat( datetime, "0");
  itoa(dtHour, this->buffer, 10);
  strcat( datetime, this->buffer);
  strcat( datetime, ":");

  if(this->dtMinute < 10) strcat( datetime, "0");
  itoa(dtMinute, this->buffer, 10);
  strcat( datetime, this->buffer);
  strcat( datetime, ":");

  if(this->dtSecond < 10) strcat( datetime, "0");
  itoa(this->dtSecond, this->buffer, 10);
  strcat( datetime, this->buffer);

  return this->datetime;

}