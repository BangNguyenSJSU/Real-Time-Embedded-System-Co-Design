#include "lpc40xx.h"
#include "lpc_peripherals.h"
#include <stdint.h>
#include <stdio.h>

#include "gpio.h"
#include "gpio_lab.h"
#include <string.h>

/* -------------------------------------------------------------------------- */
/* ------------------------- Declaration + Power on ------------------------- */

/* Oled Pixel for single Page (8)H x (128)W*/
uint8_t bitmap_[8][128];

/* Output [P1_22] ( ON<--(LOW)|(HIGH) -->OFF ) */
void oled_CS();
void oled_DS();

/* SSP1_I/O Function PIN P0_7 | P0_9 | P1_25 */
void config_oled_pin();

/* Command Buss P1_25(LOW) | Data Buss P1_25(HIGH) */
void oled_setC_bus();
void oled_setD_bus();

/* -------------------------------------------------------------------------- */
/* ------------------------ Initialization + Testing ------------------------ */

/* SPI_oled Initial */
void SPI_oled_initialization();

/* Oled (SPI1) Transfer Byte  */
uint8_t oled__transfer_byte(uint8_t data_transfer);

/* Initialize the Sequence of OP-CODE for OLED */
void panel_init();

/* Test <-> Turn LCD ON  --> Print ("CMPE") */
void turn_on_lcd();

/* -------------------------------------------------------------------------- */
/* ----------------------- Clear + Fill Update Screen ----------------------- */

/* Set Bit Map with 0x00  */
void oled_clear();

/* Set Bit Map with 0xFF  */
void oled_fill();

/* Update BitMap to Oled */
void oled_update();

/* -------------------------------------------------------------------------- */
/* ------------------------------ Control Usage ----------------------------- */
/* Horizontal Address Mode */
void horizontal_addr_mode();

/**/
void oled_print(char *message);

/* -------------------------------------------------------------------------- */
/* --------------------------- LOOK UP char Array --------------------------- */

/* Call Back Array for char*/
typedef void (*function_pointer_char)(void);

/*
 * Casting to get the ASCII value of the char
 * ---> Assign ASCII value to index of Call Back Array
 */
void char_array_table();

/* Use Lookup Table to search char and Display */
void display_char(char *string);

void char_A(); // 1
void char_B();
void char_C();
void char_D();
void char_E(); // 5
void char_F();
void char_G();
void char_H();
void char_I();
void char_J(); // 10
void char_K();
void char_L();
void char_M();
void char_N();
void char_O(); // 15
void char_P(); // 16
