/*************************************************************************
* Authors : Harsimransingh Bindra, Smitesh Modak
* Date : 12/7/2017
*
* File : nrf.c
* Description : Source file for nrf functions
*            	-void nrf_read_register(uint8_t reg)
*            	-void nrf_write_register(uint8_t reg, uint8_t val)
*            	-uint8_t nrf_read_status()
*            	-void nrf_write_config(uint8_t val)
*				-uint8_t nrf_read_config()
*				-uint8_t nrf_read_rf_setup()
*				-void nrf_write_rf_setup(uint8_t value)uint8_t nrf_read_rf_ch()
*				-void nrf_write_rf_ch(uint8_t channel)
*				-uint8_t * nrf_read_TX_ADDR()
*				-void nrf_write_TX_ADDR(uint8_t * tx_addr)
*				-uint8_t nrf_read_fifo_status()
*				-void nrf_flush_tx_fifo()
*				-void nrf_flush_rx_fifo()
***************************************************************************/

#include "circbuf.h"
#include "FRDM.h"
#ifdef FRDM
#include "spi.h"
#include "nrf.h"

/*Function to read a NRF register*/
void nrf_read_register(uint8_t reg) {
	//uint8_t val;
	spi_write_byte(R_REGISTER | (REG_MASK & reg));
}

/*Function to write to a NRF register*/
void nrf_write_register(uint8_t reg, uint8_t val) {
	nrf_chip_enable();
	spi_write_byte(W_REGISTER | (REG_MASK & reg));
	spi_write_byte(val);
	nrf_chip_disable();
}

/*Function to read NRF STATUS register*/
uint8_t nrf_read_status() {
	nrf_chip_enable();
	uint8_t val;
	nrf_read_register(NRF_STATUS); //Can send NOP as well to read STATUS
	val = spi_write_byte(DUMMY);
	nrf_chip_disable();
	return val;
}

/*Function to write to the NRF CONFIG register*/
void nrf_write_config(uint8_t val) {

	nrf_chip_enable();
	uint8_t reg = CONFIG;
	nrf_write_register(reg, val);
	nrf_chip_disable();
}

/*Function to read from NRF CONFIG register*/
uint8_t nrf_read_config() {
	nrf_chip_enable();
	uint8_t val;
	nrf_read_register(CONFIG);
	val = spi_write_byte(DUMMY);
	nrf_chip_disable();
	return val;
}

/*Function to read from NRF RF_SETUP register*/
uint8_t nrf_read_rf_setup() {

	uint8_t val;
	nrf_chip_enable();
	nrf_read_register(RF_SETUP);
	val = spi_write_byte(DUMMY);
	nrf_chip_disable();
	return val;
}

/*Function to write to the NRF RF_SETUP register*/
void nrf_write_rf_setup(uint8_t value){

	uint8_t reg = W_REGISTER | RF_SETUP;
	nrf_chip_enable();
	nrf_write_register(reg, value);
	nrf_chip_disable();
}

/*Function to read from NRF RF_CH register*/
uint8_t nrf_read_rf_ch() {
	nrf_chip_enable();
	uint8_t val;
	nrf_read_register(RF_CH);
	val = spi_write_byte(DUMMY);
	nrf_chip_disable();
	return val;
}

/*Function to write to the NRF RF_CH register*/
void nrf_write_rf_ch(uint8_t channel) {

	uint8_t reg = W_REGISTER | RF_CH;
	nrf_write_register(reg, channel);
}

/*Function to read from NRF TX_ADDR register*/
uint8_t * nrf_read_TX_ADDR() {
	nrf_chip_enable();
	uint8_t i;
	nrf_read_register(TX_ADDR);
	for(i=0;i<5;i++)
	{
		TX_Addr_Values[i] = spi_write_byte(DUMMY);
	}
	nrf_chip_disable();
	return TX_Addr_Values;
}

/*Function to write to the NRF TX_ADDR register*/
void nrf_write_TX_ADDR(uint8_t * tx_addr) {

	uint8_t reg = W_REGISTER | TX_ADDR;
	uint8_t i;
	nrf_chip_enable();
	SPI_write_byte(W_REGISTER | reg);
	SPI_send_packet(tx_addr,5);
	nrf_chip_disable();
}

/*Function to read from NRF FIFO_STATUS register*/
uint8_t nrf_read_fifo_status() {
	nrf_chip_enable();
	uint8_t value;
	nrf_read_register(FIFO_STATUS);
	value = spi_write_byte(DUMMY);
	nrf_chip_disable();
	return value;
}

/*Function to flush TX_FIFO buffer*/
void nrf_flush_tx_fifo() {
	nrf_chip_enable();
	spi_write_byte(FLUSH_TX);
	nrf_chip_disable();
}

/*Function to flush RX_FIFO buffer*/
void nrf_flush_rx_fifo() {
	nrf_chip_enable();
	spi_write_byte(FLUSH_RX);
	nrf_chip_disable();
}

#endif

