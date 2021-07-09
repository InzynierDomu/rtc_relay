/**
 * @file main.cpp
 * @brief time relay
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/
 * @date 06-2021
 */

#include <Arduino.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 m_rtc; ///< DS1307 RTC

const DateTime m_start = DateTime(2000, 1, 1, 16, 48, 0); ///< time when realy turn on
const DateTime m_stop = DateTime(2000, 1, 1, 16, 50, 0);  ///< time when realy turn off
const byte m_output_pin = 2;        ///< pin connected to relay
const int min_in_h = 60;            ///< minutes in an hour
const int refresh_time_ms = 15000;  ///< time of repeting check time is in range and sending message

/**
 * @brief check if current time is in range from start to end time
 * @param current current time
 * @param start start time
 * @param stop stop time
 * @return true if is in range, false if is not in range
 */
bool is_in_range(const DateTime& current, const DateTime& start, const DateTime& end)
{
  int current_minute = current.hour() * min_in_h;
  current_minute += current.minute();

  int start_minute = start.hour() * min_in_h;
  start_minute += start.minute();

  int end_minute = end.hour() * min_in_h;
  end_minute += end.minute();

  return((current_minute >= start_minute) && (current_minute < end_minute));
}

/**
 * @brief setup
 */
void setup() 
{
  Serial.begin(9600);  

  pinMode(m_output_pin, OUTPUT);

  if (!m_rtc.begin()) 
  {
    Serial.println("Couldn't find RTC");
  }

  if (!m_rtc.isrunning())
  {
    Serial.println("RTC is NOT running, let's set the time!");    
  }

  m_rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

/**
 * @brief main loop
 */
void loop() 
{
  static long last_loop_time = 0;
  long loop_time = millis();
  if(loop_time - last_loop_time > refresh_time_ms)
  {
    DateTime time = m_rtc.now();
    Serial.print(time.hour(), DEC);
    Serial.print(":");
    Serial.print(time.minute(), DEC);
    Serial.print(":");
    Serial.println(time.second(), DEC);
    last_loop_time = millis();

    static bool is_turn_on = false;
    if(is_in_range(m_rtc.now(), m_start, m_stop) && !is_turn_on)
    {
      Serial.println("Start");
      digitalWrite(m_output_pin, HIGH);
      is_turn_on = true;
    }
    else if(!is_in_range(m_rtc.now(), m_start, m_stop) && is_turn_on)
    {
      Serial.println("Stop");
      digitalWrite(m_output_pin, LOW);
      is_turn_on = false;
    }
  }
}