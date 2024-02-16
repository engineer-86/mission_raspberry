#ifndef RPI_IO_H
#define RPI_IO_H

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

//phys. Adressraum/Startadresse für Periperiekomponenten
#define BCM2708_PERI_BASE 0x20000000
#define GPIO_BASE (BCM2708_PERI_BASE + 0x200000)
#define PAGE_SIZE (4 * 1024)
#define BLOCK_SIZE (4 * 1024)

/**
 * \brief this function initalise the register access in read and write mode
 * \param -
 * \return 0 for succes and -1 for failure
*/
extern void setup_io();

/**
 * \brief this function is setting the bitmask into 32 GPIO registers
 * \param bitmask the bitmask which was generated
 * \return 0 for succes and -1 for failure
*/
extern int set_bitmask(u_int32_t bitmask);

/**
 * \brief this function is read the value from a GPIO register
 * \param reg number [0-31]
 * \return value of selected GPIO register and -1 for failure
*/
extern u_int32_t read_bitmask(unsigned reg);

/**
 * \brief this function is checking the set mask against the read mask on 32 GPIO registers * 
 * \param bitmask the bitmask to check against the register value
 * \return 0 for equal, -1 for not equal 
*/
extern int check_bitmask(u_int32_t bitmask);
#endif