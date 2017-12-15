/*************************************************************************
 * * Authors : Harsimransingh Bindra, Smitesh Modak
 * * Date : 11/27/2017
 * *
 * * File : gpio.c
 * * Description : Source file for GPIO initialize functions
 * *               - void init_GPIO_nrf()
 * *               - void init_GPIO_led()
 * ***************************************************************************/

#include <stdint.h>
#include "circbuf.h"
#include "FRDM.h"

#ifdef FRDM
#include "spi.h"
#include "MKL25Z4.h"
#include "gpio.h"
#include "non_block_logger.h"
/*Function to initialize gpio pins for NRF module*/
void init_GPIO_nrf(){
//Enabling clock to Port D
  SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

//Provide clock to SPI0
   SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;

//CE ON by default
   PORTD_PCR5 = PORT_PCR_MUX(1);       //Set the PTD5 pin multiplexer to GPIO mode
   GPIOD_PDDR |= CHIP_SHIFT;         // Set the pins direction to output
   GPIOD_PCOR |= CHIP_SHIFT;         //Set the initial output state to low

//CSN is HIGH by default
   PORTD_PCR6 = PORT_PCR_MUX(1);       //Set the PTD6 pin multiplexer to GPIO mode
   GPIOD_PDDR |= SLAVE_SHIFT;          //Set the pins direction to output
   GPIOD_PSOR |= SLAVE_SHIFT;          //Set the initial output state to high

   //For IRQ from the SPI device
   PORTD_PCR7 = PORT_PCR_MUX(1);       //Set the PTD7 pin multiplexer to GPIO mode
   GPIOD_PDDR |= ISR_SHIFT;          //Set the pins direction to input

   //Set as SPI0_SCK
   PORTD->PCR[1]= AL_MODE;

   //Set as SPI0_MOSI
   PORTD->PCR[2]= AL_MODE;

   //Set as SPI0_MISO
   PORTD->PCR[3]= AL_MODE;

  #ifdef LOG_ON
/*Binary logger for GPIO_INITIALIZED*/
   system_log->logID = GPIO_INITIALIZED;
   system_log->LogLength = 0;
   system_log->Payload = 0;
   log_item(system_log);
  #endif
}

/*Funcion to initialize RED led*/
void init_GPIO_led()
{

/*Using port B pin 18 (red LED) as GPIO*/
  PORTB_PCR18 = PORT_PCR_MUX(0x1);

/*Setting port B pin 18 as output*/
  PTB->PDDR |= PIN18;

/*Sets the port B pin 18 value to 1*/
  PTB->PSOR = PIN18;
  #ifdef LOG_ON
/*Binary logger for GPIO_INITIALIZED*/
    system_log->logID = GPIO_INITIALIZED;
    system_log->LogLength = 0;
    system_log->Payload = 0;
    log_item(system_log);
  #endif
}

#endif                                                                                                   
