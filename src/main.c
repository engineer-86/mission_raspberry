#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/rpi_io.h"
#include "../lib/bit_functions.h"
#include "../lib/util.h"
#include "../lib/i2c_sensor.h"

u_int32_t new_bitmask;

int main(int argc, char *argv[])
{
    int amount_runs = atoi(argv[1]);
    int amount_interval = atoi(argv[2]);

    setup_io();    // initalize register access
    show_mission_logo();
    sleep(2);
    init_sensor(); // init radiation sensor

    for (int i = 0; i < amount_runs; i++)
    {

        new_bitmask = generate_bitmask(); //generate new bitmask

        if ((set_bitmask(new_bitmask) == 0)) //set bitmask into 32 gpio register
        {
            if ((check_bitmask(new_bitmask) == 0)) //check if values are correct
            {
                // let the radiation work
                sleep(amount_interval);
                int16_t radiation_value = get_radiation_data();

                if (radiation_value > 30)
                {
                    set_bitmask(new_bitmask + 0x00000001); // simulate bitflip
                }

                printf("Test Nr %i:\nvalue: 0x%08x succesfully stored into 32 GPIO registers\n", i + 1, new_bitmask); //log out
                printf("Current Rad: %d \n", radiation_value);
                for (int x = 0; x < 32; x++)
                {
                    u_int32_t readed_bitmask = read_bitmask(x);
                    printf("Register %i: 0x%08x\n", x, readed_bitmask);                          //log out
                    save_data(x, new_bitmask, readed_bitmask, radiation_value, amount_interval); //save data
                }

                printf("\n\n");
            }
        }
    }

    return (EXIT_SUCCESS);
}
