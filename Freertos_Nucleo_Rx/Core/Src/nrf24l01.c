/**
 * @file nrf24l01.c
 * @brief Librairie pour le module nrf24l01+
 * @author Olivier BETIL
 * @version 1.0
 * @date 10/11/2022
 */

#include "stm32f1xx_hal.h"
#include "nrf24l01.h"

extern SPI_HandleTypeDef hspi1;

#define SPI_CE_GPIO			GPIOC
#define SPI_CE_PIN			GPIO_PIN_7
#define SPI_GPIO			GPIOA
#define SPI_CS_GPIO			GPIOB
#define SPI_CS_PIN			GPIO_PIN_6

/**
 * @brief met le pin CS � 0
 */
void selectCS(void){
	HAL_GPIO_WritePin(SPI_CS_GPIO, SPI_CS_PIN, GPIO_PIN_RESET);
}

/**
 * @brief met le pin CS � 1
 */
void unselectCS(void){
	HAL_GPIO_WritePin(SPI_CS_GPIO, SPI_CS_PIN, GPIO_PIN_SET);
}

/**
 * @brief met le pin CE � 1
 */
void enableCE(void){
	HAL_GPIO_WritePin(SPI_CE_GPIO, SPI_CE_PIN, GPIO_PIN_SET);
}

/**
 * @brief met le pin CE � 0
 */
void disableCE(void){
	HAL_GPIO_WritePin(SPI_CE_GPIO, SPI_CE_PIN, GPIO_PIN_RESET);
}

/**
 * @brief �crit une valeur dans un registre du module
 *
 * @param Reg : Registre � modifier
 * @param Data : Donn�e � �crire dans le registre
 */
void nrf24_WriteReg(uint8_t Reg, uint8_t Data){
	uint8_t buf[2];
	buf[0]=Reg|1<<5;
	buf[1]=Data;

	selectCS();
	HAL_SPI_Transmit(&hspi1, buf, 2, 100);
	unselectCS();
}


/**
 * @brief �crit une valeur de plus d'un octet dans un registre
 *
 * @param Reg : Registre � modifier
 * @param Data : Donn�e � �crire dans le registre
 * @param size : Taille de la donn�e (en octets)
 */
void nrf24_WriteRegMulti(uint8_t Reg, uint8_t *Data, uint8_t size){
	uint8_t buf[2];
	buf[0]=Reg|1<<5;
	//buf[1]=Data;

	selectCS();
	HAL_SPI_Transmit(&hspi1, &buf[0], 1, 100);
	HAL_SPI_Transmit(&hspi1, Data, size, 100);

	unselectCS();
}


/**
 * @brief lit la valeur d'un registre du module
 *
 * @param Reg : Registre o� l'on veut lire la valeur
 * @return la valeur du registre
 */
uint8_t nrf24_ReadReg(uint8_t Reg){
	uint8_t data=0;
	selectCS();
	HAL_SPI_Transmit(&hspi1, &Reg, 1, 100);
	HAL_SPI_Receive(&hspi1, &data, 1, 100);
	unselectCS();
	return data;
}

/**
 * @brief lit la valeur d'un registre de plus d'un octet
 *
 * @param Reg : registre dont on veut la valeut
 * @param data : pointeur vers l� ou l'on enregistre la valeur du registre
 * @param size : taille de la valeur � r�cuperer (en octets)
 */
void nrf24_ReadRegMulti(uint8_t Reg, uint8_t *data, uint16_t size){
	//uint8_t data=0;
	selectCS();
	HAL_SPI_Transmit(&hspi1, &Reg, 1, 100);
	HAL_SPI_Receive(&hspi1, data, size, 100);
	unselectCS();
}

/**
 * @brief Envoie une commande au module
 *
 * @param cmd : Commande � envoyer (voir datasheet module pour liste des commandes)
 */
void nrfsendcmd(uint8_t cmd){
	selectCS();
	HAL_SPI_Transmit(&hspi1, &cmd, 1, 100);
	unselectCS();
}

/**
 * @brief Initialise les diff�rents registre du module
 */
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

/**
 * @brief initialise le module en mode Tx (envoi de donn�es)
 *
 * @param Address : l'adresse du module
 * @param channel : cha�ne du module (mettre � 10)
 */
void nrf24_TxMode(uint8_t *Address, uint8_t channel){
	disableCE();
	nrf24_WriteReg(RF_CH, channel);
	nrf24_WriteRegMulti(TX_ADDR, Address, 5);

	//power up the device
	uint8_t config = nrf24_ReadReg(CONFIG);
	config=config | (1<<1);
	nrf24_WriteReg(CONFIG, config);
	enableCE();
}

/**
 * @brief envoie une donn�e et confirme son envoi
 *
 * @param data : pointeur vers la donn�e � envoyer (32 bits)
 * @return true : donn�e bien envoy�e; false : donn�e non envoy�e
 */
uint8_t nrf24_Transmit(uint8_t *data){
	uint8_t cmdtosend = 0;
	selectCS();

	cmdtosend=W_TX_PAYLOAD;
	HAL_SPI_Transmit(&hspi1, &cmdtosend, 1, 100);

	HAL_SPI_Transmit(&hspi1, data, 32, 100);

	unselectCS();

	HAL_Delay(1);

	uint8_t fifostatus = nrf24_ReadReg(FIFO_STATUS);

	if((fifostatus&(1<<4)) && !(fifostatus&(1<<3))){
		cmdtosend = FLUSH_TX;
		nrfsendcmd(cmdtosend);

		return 1;
	}
	else
		return 0;


}

/**
 * @brief initialise le module en mode Rx (reception de donn�es)
 *
 * @param Address : l'adresse du module
 * @param channel : cha�ne du module (mettre 10)
 */
void nrf24_RxMode(uint8_t *Address, uint8_t channel){
	disableCE();
	nrf24_WriteReg(RF_CH, channel);

	uint8_t en_rxaddr=nrf24_ReadReg(EN_RXADDR);
	en_rxaddr=en_rxaddr | (1<<1);
	nrf24_WriteReg(EN_RXADDR, en_rxaddr);
	nrf24_WriteRegMulti(RX_ADDR_P1, Address, 5);
	nrf24_WriteReg(RX_PW_P1, 32); //Set up la taille maximale de la donn�e � r�cuperer

	//power up the device in RX mode
	uint8_t config = nrf24_ReadReg(CONFIG);
	config=config | (1<<1) | (1<<0);
	nrf24_WriteReg(CONFIG, config);
	enableCE();
}

/**
 * @brief observe si une donn�e est arriv�e dans la pipe
 *
 * @param pipenum : pipe � scuter
 * @return true : donn�e disponible; false : pas de donn�e
 */
uint8_t isDataAvailable(uint8_t pipenum){
	uint8_t status = nrf24_ReadReg(STATUS);

	if((status&(1<<6)) && (status&(pipenum<<1))){
		nrf24_WriteReg(STATUS, (1<<6));
		return 1;
	}
	else
		return 0;
}

/**
 * @brief r�cupere la donn�e dans la pipe 1
 *
 * @param data pointeur vers l� ou l'on veut stocker la donn�e (32 bits)
 */
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
