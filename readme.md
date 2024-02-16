# MISSION_RASPBERRY

## Overview
![function](/docs/title.png)
MISSION_RASPBERRY is an innovative project designed to explore and simulate the detection of bit shifts in register values caused by solar radiation. Utilizing a Raspberry Pi 3, this project aims to serve as a model for a satellite payload sensor, capable of operating in the challenging conditions of space. By generating, setting, and validating bitmask values within GPIO registers, the system is crafted to identify potential bit flips, simulating the environmental conditions a satellite might face.
Detailed Information in the doc:
[Prasentation](docs/PDR_Presentation_Gruppe_E.pdf).

## Installation and Usage

- Raspberry Pi 3 Model B+
- C Compiler (GCC recommended)
- Make

### Setup

Clone this repository and navigate to the `src` folder to begin.

### Makefile Commands

## To compile the project, execute:

```bash
make
```

## To run the compiled project:

```bash
make run
```

## To clean the /bin and /data directories:

```bash
make clean
```

# Main Function

The main function initializes GPIO and I2C sensors, generates a new bitmask, and sets this bitmask into 32 GPIO registers. It checks the correctness of the values stored and, based on radiation data from the sensor, simulates bit flips by adjusting the bitmask. Each test's results, including bitmask values, radiation levels, and affected registers, are logged.
![function](/docs/function.png)

# Libraries Overview

- rpi_io: Manages GPIO register initialization and manipulation.
- bit_functions: Contains logic for generating and manipulating bitmasks.
- util: Provides utilities such as data logging and displaying the mission logo.
- i2c_sensor: Simulates radiation data reading through the I2C interface.

# Hardware Specifications

The Raspberry Pi 3 Model B+ is the heart of this project, featuring:

- ARMv8 1.2 GHz CPU
- BCM2837 64-bit Quad-Core Processor
- 1 GB RAM
- 41 GPIO registers
  ### Prerequisites![Alt text](/docs/overview.png)

# Sensor Connection

The radiation sensor connects via the I2C interface, providing crucial data for simulating the effects of solar radiation on the Pi's CPU and memory.

# Contributing
Contributions to MISSION_RASPBERRY are welcome! Please submit pull requests for any fixes, enhancements, or new features you propose.

# License
This project is released under the MIT License. See the LICENSE file for more details.