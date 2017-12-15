/*************************************************************************
 * * Authors : Harsimransingh Bindra, Smitesh Modak
 * * Date : 11/26/2017
 * *
 * * File : rtc.c
 * * Description : Source file for RTC initialization functions
 * *              -void init_rtc(void)
 * ***************************************************************************/
#include "FRDM.h"
#include <stdint.h>
#include "non_block_logger.h"
#include "circbuf.h"
#include "binary_logger.h"
//#include "circbuf.h"
#ifdef FRDM
#include "MKL25Z4.h"
#include "RTC.h"
void init_rtc(void)
{
//Enabling clock to Port c
    //SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM_SCGC5|=(1<<11);
	MCG_C1|=(1<<1);
	MCG_C2&=~(1<<0);
	PORTC_PCR1|=(1<<8);
	SIM_SOPT1|=(1<<19);
	SIM_SOPT1|=~(1<<18);
//Provide clock to SPI0
    //SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
    //SIM_CLKDIV1 = ( SIM_CLKDIV1_OUTDIV1(0)| SIM_CLKDIV1_OUTDIV4(1) );
//Enable the internal reference clock. MCGIRCLK is active.
    //MCG_C1 |= MCG_C1_IRCLKEN_MASK;
//Select the slow internal reference clock source.
    //MCG_C2 &= ~(MCG_C2_IRCS_MASK);
//Set PTC1 as RTC_CLKIN and select 32 KHz clock source for the RTC module.
//    PORTC_PCR1 |= (PORT_PCR_MUX(0x1));
//    SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0b10);
//Set PTC3 as CLKOUT pin and selects the MCGIRCLK clock to output on the CLKOUT pin.
//    SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0b100);
//    PORTC_PCR3 |= (PORT_PCR_MUX(0x5));
//Enable software access and interrupts to the RTC module.
//    SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
////Clear all RTC registers.
//    RTC_CR = RTC_CR_SWR_MASK;
//    RTC_CR &= ~RTC_CR_SWR_MASK;
//    if (RTC_SR & RTC_SR_TIF_MASK){
//     RTC_TSR = 0x00000000;
//    }
////Set time compensation parameters. (These parameters can be different for each application)
//    RTC_TCR = RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF);
//    //Enable seconds interrupt
//    RTC_IER |= RTC_IER_TSIE_MASK;
//                                                                                                 //Enable time seconds interrupt for the module and enable its irq.
//    NVIC_EnableIRQ(RTC_Seconds_IRQn);
//    //RTC_TSR = TIME_STAMP - ADJUSTMENT; //Epoch Time
//    RTC_SR |= RTC_SR_TCE_MASK;
	 SIM_SOPT2 |= (1<<7);
	            SIM_SOPT2 &= ~(1<<6);
	            SIM_SOPT2 &= ~(1<<5);

	            //PTC3 as CLKOUT(BIT10,BIT9,BIT8 SHOULD BE 101)

	            PORTC_PCR3 |= (1<<10)|(1<<8);
	            PORTC_PCR3&=~(1<<9);

	            /*enable the clock to SRTC module register space*/
	            SIM_SCGC6 |= (1<<29);//(BIT 29=1)

	            /*Clear Registers*/
	            RTC_CR  = (1<<0);//Software reset
	            RTC_CR  &= ~(1<<0);

	            //Checking for time invalid flag(Bit 1)
	            if (RTC_SR & 0X00000001){
	                RTC_TSR = 0x00000000;   //  this action clears the TIF
	            }

	            /*Set time compensation parameters*/
	           // RTC_TCR = RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF);




	            /*Enable Seconds Interrupt*/
	            RTC_IER |= (1<<4); //Seconds interrupt enable(Bit4=1)

	            /*Timer enable*/
	            RTC_SR |= (1<<4);//Time count enable(Bit 4=1)

	            /*Configure the timer seconds and alarm registers*/
	          //  RTC_TSR = 0xFF;

	NVIC->ISER[0]=0X00200000;//ENABLE NVIC FOR TIMER INTERRUPT(BIT 21)
}

void RTC_Seconds_IRQHandler(void)
{
	START_CRITICAL();
	#ifdef LOG_ON
	if(heart_off==0)
	{
		//log_flush();
		//FRDM_log_string("\n\r");
		system_log->Timestamp = RTC_TSR;
		system_log->logID = HEARTBEAT;
		system_log->LogLength = 0;
		system_log->Payload = 0;
		log_item(system_log);
		if(RTC_SR & RTC_SR_TOF_MASK == RTC_SR_TOF_MASK)
		{
			RTC_SR &= ~RTC_SR_TOF_MASK;
		}
	}
	#endif
	END_CRITICAL();
}

#endif
