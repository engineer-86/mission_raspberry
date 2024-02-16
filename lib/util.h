#ifndef UTIL_H
#define UTIL_H
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 * \brief this function is saving the mask written and read mask in csv
 * \param register the checked register 
 * \param written_mask the mask which was written to the register
 * \param read_mask the mask which was read from the register after interval
 * \param interval the time that passed until reading the register
 * \param radiation_value the sensor raditation value
 * \return 0 for succes and 1 for failure
*/
u_int16_t save_data(int target_register, u_int32_t written_mask,
                    u_int32_t read_mask, float radiation_value, u_int32_t interval);

/**
 * \brief this function is waiting for msec milliseconds
 * \param msec the time in millisecs to wait
 * \return return 0 after msec
*/
u_int16_t wait_for_msec(u_int16_t msec);

/**
 * \brief this function is printing the mission logo
 * \return void
*/
void show_mission_logo();

#endif