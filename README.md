# A first program for mbed

## Introduction

This repository contains the mbed blinky source.


## Build Instructions


1. Ensure that you have installed mbed-cli
   (https://os.mbed.com/docs/v5.9/tools/arm-mbed-cli.html) and the GCC_ARM
   tools
   (https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads). 

1. Clone the repository and set the current working directory to the new repository.

     ```sh
     $ git clone https://github.com/davidkendall/blinky-mbed
     $ cd blinky-mbed
     ```

1. Download the required libraries.

   ```sh
   $ mbed deploy
   ```

1. Compile the program, load to flash and run (ensure that your K64F board is plugged
   into your computer and mounted).

     ```sh
     $ mbed compile -t GCC_ARM -m K64F -f
     ```
   Notice that the `-f` (`--flash`) option causes the program to be loaded 
   to flash and executed.

