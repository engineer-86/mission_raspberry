.PHONY: all clean run fire

all: main

main:
	gcc main.c bit_functions.c i2c_sensor.c util.c rpi_io.c -lm -o ../bin/main

clean:
	sudo rm ../bin/* ../data/*

run:
	sudo ../bin/main 3 3

	
