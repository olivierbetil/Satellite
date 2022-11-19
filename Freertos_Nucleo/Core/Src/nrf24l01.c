#include "stm32f1xx_hal.h"
#include "nrf24l01.h"

extern SPI_HandleTypeDef hspi1;

#define SPI_CE_GPIO			GPIOC
#define SPI_CE_PIN			GPIO_PIN_7
#define SPI_GPIO			GPIOA
#define SPI_CS_GPIO			GPIOB
#define SPI_CS_PIN			GPIO_PIN_6

void selectCS(void){
	HAL_GPIO_WritePin(SPI_CS_GPIO, SPI_CS_PIN, GPIO_PIN_RESET);
}

void unselectCS(void){
	HAL_GPIO_WritePin(SPI_CS_GPIO, SPI_CS_PIN, GPIO_PIN_SET);
}

void enableCE(void){
	HAL_GPIO_WritePin(SPI_CE_GPIO, SPI_CE_PIN, GPIO_PIN_SET);
}

void disableCE(void){
	HAL_GPIO_WritePin(SPI_CE_GPIO, SPI_CE_PIN, GPIO_PIN_RESET);
}

void nrf24_WriteReg(uint8_t Reg, uint8_t Data){
	uint8_t buf[2];
	buf[0]=Reg|1<<5;
	buf[1]=Data;
	selectCS();
	HAL_SPI_Transmit(&hspi1, buf, 2, 100);
	unselectCS();
}

void nrf24_WriteRegMulti(uint8_t Reg, uint8_t *Data, uint8_t size){
	uint8_t buf[2];
	buf[0]=Reg|1<<5;
	//buf[1]=Data;

	selectCS();
	HAL_SPI_Transmit(&hspi1, &buf[0], 1, 100);
	HAL_SPI_Transmit(&hspi1, Data, size, 100);

	unselectCS();
}

uint8_t nrf24_ReadReg(uint8_t Reg){
	uint8_t data=0;
	selectCS();
	HAL_SPI_Transmit(&hspi1, &Reg, 1, 100);
	HAL_SPI_Receive(&hspi1, &data, 1, 100);
	unselectCS();
	return data;
}

void nrf24_ReadRegMulti(uint8_t Reg, uint8_t *data, uint16_t size){
	//uint8_t data=0;
	selectCS();
	HAL_SPI_Transmit(&hspi1, &Reg, 1, 100);
	HAL_SPI_Receive(&hspi1, data, size, 100);
	unselectCS();
}

void nrfsendcmd(uint8_t cmd){
	selectCS();
	HAL_SPI_Transmit(&hspi1, &cmd, 1, 100);
	unselectCS();
}

void nrf24_Init(void){
	disableCE();
	nrf24_WriteReg(CONFIG, 0);
	nrf24_WriteReg(EN_AA, 0);
	nrf24_WriteReg(EN_RXADDR, 0);
	nrf24_WriteReg(SETUP_AW, 0x03);
	nrf24_WriteReg(SETUP_RETR, 0);
	nrf24_WriteReg(RF_CH, 0);
	nrf24_WriteReg(RF_SETUP, 0x0E);
	enableCE();
}

void nrf24_TxMode(uint8_t *Address, uint8_t channel){
	disableCE();
	nrf24_WriteReg(RF_CH, channel);
	nrf24_WriteRegMulti(TX_ADDR, Address, 5);



	//power up the device
	uint8_t config = nrf24_ReadReg(CONFIG);
	config=config|(1<<1);
	nrf24_WriteReg(CONFIG, config);
	enableCE();

}

uint8_t nrf24_Transmit(uint8_t *data){
	uint8_t cmdtosend = 0;
	selectCS();

	cmdtosend=W_TX_PAYLOAD;
	HAL_SPI_Transmit(&hspi1, &cmdtosend, 1, 100);

	HAL_SPI_Transmit(&hspi1, data, 32, 1000);

	unselectCS();

	HAL_Delay(1);

	//Pour verifier si l'adresse est bonne
	//uint8_t txadd[5];
	//nrf24_ReadRegMulti(TX_ADDR, txadd, 5);

	uint8_t fifostatus = nrf24_ReadReg(FIFO_STATUS);

	if((fifostatus&(1<<4)) && !(fifostatus&(1<<3))){
		cmdtosend = FLUSH_TX;
		nrfsendcmd(cmdtosend);

		return 1;
	}
	else
		return 0;


}

void nrf24_RxMode(uint8_t *Address, uint8_t channel){
	disableCE();
	nrf24_WriteReg(RF_CH, channel);

	uint8_t en_rxaddr=nrf24_ReadReg(EN_RXADDR);
	en_rxaddr|=(1<<1);
	nrf24_WriteReg(EN_RXADDR, en_rxaddr);
	nrf24_WriteRegMulti(RX_ADDR_P1, Address, 5);
	nrf24_WriteReg(RX_PW_P1, 32); //Set up la taille maximale de la donnée à récuperer

	//power up the device in RX mode
	uint8_t config = nrf24_ReadReg(CONFIG);
	config=config | (1<<1) | (1<<0);
	nrf24_WriteReg(CONFIG, config);
	enableCE();
}

uint8_t isDataAvailable(uint8_t pipenum){
	uint8_t status = nrf24_ReadReg(STATUS);

	if(status&(1<<6) && status&(pipenum<<1)){
		nrf24_WriteReg(STATUS, (1<<6));
		return 1;
	}
	else
		return 0;
}

void nrf24_Receive(uint8_t *data){
	uint8_t cmdtosend = 0;
	selectCS();

	cmdtosend=R_RX_PAYLOAD;
	HAL_SPI_Transmit(&hspi1, &cmdtosend, 1, 100);

	HAL_SPI_Receive(&hspi1, data, 32, 100);

	unselectCS();

	HAL_Delay(1);

	cmdtosend=FLUSH_RX;
	nrfsendcmd(cmdtosend);
}

uint8_t verifReg(){
	uint8_t check=nrf24_ReadReg(RF_CH);
	return check;
}
