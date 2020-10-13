This folder contains sample projects that you can build

## Lab2: GPIO Driver 
![image](https://user-images.githubusercontent.com/38081550/95832812-ac28bc80-0cef-11eb-9eea-3b6b61dd5132.png)

OBJECTIVE
1. Manipulate microcontroller's registers in order to access and control physical pins.
2. Use implemented driver to sense input signals and control LEDs.
3. Use FreeRTOS binary semaphore to signal between tasks.

* L3-Driver       [GPIO Header](lab2/l3_drivers/gpio_lab.h).

* L3-Driver       [GPIO Source](lab2/l3_drivers/sources/gpio_lab.c).

* L5-Application  [main](lab2/l5_application/main.c)
```
# Compile Command:
scons --project=lab2

# SJ2 Board Flash Command:
python nxp-programmer/flash.py --input _build_lab2/lab2.bin
```

## Lab3: GPIO Interrupt - Dynamic User Defined ISR Callback Driver
![image](https://user-images.githubusercontent.com/38081550/95835603-48a08e00-0cf3-11eb-9d4f-1c6d447c46cc.png)
![Alt text](http://books.socialledge.com/uploads/images/gallery/2019-09-Sep/isr.gif)

OBJECTIVE
1. Semaphores
    * Wait on [Semaphore Design pattern](http://books.socialledge.com/books/embedded-drivers-real-time-operating-systems/page/binary-semaphores#bkmrk-design-pattern)
2. [Lookup table](http://books.socialledge.com/books/embedded-drivers-real-time-operating-systems/page/lookup-tables) structures and Function Pointers
    * code will allow the user to register their callbacks
    * Be sure to understand how [function pointers](http://books.socialledge.com/books/useful-knowledge/page/function-pointer) work
3. [Interrupts](http://books.socialledge.com/books/embedded-drivers-real-time-operating-systems/page/nested-vector-interrupt-controller-%28nvic%29)
    * LPC supports rising and falling edge interrupts on certain port pins
    * These port/pin interrupts are actually OR'd together and use a single CPU interrupt.
    * On the SJ2 board, GPIO interrupts are handled by a dedicated GPIO interrupt (exception number 54)
    
* L3-Driver       [GPIO ISR Header](lab3/l3_drivers/gpio_isr.h).

* L3-Driver       [GPIO ISR Source](lab3/l3_drivers/sources/gpio_isr.c).

* L5-Application  [main](lab3/l5_application/main.c)
```
# Compile Command:
scons --project=lab3

# SJ2 Board Flash Command:
python nxp-programmer/flash.py --input _build_lab3/lab3.bin
```

## lpc40xx_freertos
* This the primary LPC40xx project with all of the sources
* This is the default project that gets compiled when you simply type `scons` without any arguments
Build the project by using any of these commands:
```
scons
scons --project=lpc40xx_freertos

# Build without any printf/scanf of float (saves program flash space, and is faster to program)
scons --project=lpc40xx_freertos --no-float-format
# Build without unit tests
scons --project=lpc40xx_freertos --no-float-format --no-unit-test
# Build with multiple threads on your machine
scons --project=lpc40xx_freertos --no-float-format --no-unit-test -j32

```

## lpc40xx_cmpe30

This is the "simple" main control loop project setup just for CmpE30 which is a freshmen level class at San Jose State University. It re-uses all of the code from `lpc40xx_freertos` except that it has its own main function override.

Build the project by using any of these commands:
```
scons

scons --project=lpc40xx_cmpe30
```

## x86_freertos

This is the FreeRTOS "simulator" on your host machine. For example, you can run a program with multiple FreeRTOS tasks on your Mac or Linux machine (or maybe even windows?)

Use this project to:

* Learn FreeRTOS API
* Experiment with multiple FreeRTOS tasks or queues
```
# Compile
scons --project=x86_freertos

# Run the executable
_build_x86_freertos/./x86_freertos.exe
```

## x86_sandbox

This is to compile a program on your host machine. For example, you can compile an executable that runs on your Mac or Linux machine (or maybe even windows?)
```
# Compile
scons --project=x86_sandbox

# Run the executable
_build_x86_sandbox/./x86_sandbox.exe
```

Use this project to:

* Compile a program for your host machine
* Run unit-tests for code modules
