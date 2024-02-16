#include "../lib/rpi_io.h"

int mem_fd;
char *gpio_mem, *gpio_map;
char *spi0_mem, *spi0_map;

// I/O access
volatile unsigned *gpio;

void setup_io()
{
    /* open /dev/mem */
    if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0)
    {
        printf("can't open /dev/mem \n");
        exit(-1);
    }

    /* mmap GPIO */

    // Allocate MAP block
    if ((gpio_mem = malloc(BLOCK_SIZE + (PAGE_SIZE - 1))) == NULL)
    {
        printf("allocation error \n");
        exit(-1);
    }

    // Make sure pointer is on 4K boundary
    if ((unsigned long)gpio_mem % PAGE_SIZE)
        gpio_mem += PAGE_SIZE - ((unsigned long)gpio_mem % PAGE_SIZE);

    // Now map it
    gpio_map = (unsigned char *)mmap(
        (caddr_t)gpio_mem,
        BLOCK_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_FIXED,
        mem_fd,
        GPIO_BASE);

    if ((long)gpio_map < 0)
    {
        printf("mmap error %d\n", (int)gpio_map);
        exit(-1);
    }

    gpio = (volatile unsigned *)gpio_map;
}

int set_bitmask(u_int32_t bitmask)
{
    int i = 0;

    for (i = 0; i < 32; i++) //t /etc/*-release
    {
        if (!(*(gpio + i) = bitmask)) //write into 32 gpio registers
        {
            return -1;
        }
    }

    return 0;
}

u_int32_t read_bitmask(unsigned reg)
{
    if ((reg < 0) || (reg > 31))
    {
        return -1;
    }

    u_int32_t value = *(gpio + reg);

    return value;
}

int check_bitmask(u_int32_t bitmask)
{
    int i = 0;

    for (i = 0; i < 32; i++)
    {
        if (*(gpio + i) != bitmask)
        {
            return -1;
        }
    }

    return 0;
}
