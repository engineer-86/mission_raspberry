#ifndef I2C_SENSOR_H
#define I2C_SENSOR_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// data in uSv, typical around 200-400 mSv per year (ISS Orbit) or around 4 uSv/hour
int16_t m_date;

/**
 * \brief initialize "sensor" with default start value for the radiation
 * \return 0 for success
*/
u_int16_t init_sensor();

/**
 * \brief deviate the m_date and return new value
 * \return int16_t rad value
*/
int16_t get_radiation_data();

#endif