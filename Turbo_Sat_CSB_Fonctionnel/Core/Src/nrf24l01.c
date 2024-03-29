/**
 * @file nrf24l01.c
 * @brief Librairie pour le module nrf24l01+
 * @author Olivier BETIL
 * @version 1.0
 * @date 10/11/2022
 */

#include "stm32f4xx_hal.h"
#include "nrf24l01.h"

extern SPI_HandleTypeDef hspi2;

#define SPI_PROTO			&hspi2
#define SPI_CE_GPIO			GPIOB
#define SPI_CE_PIN			GPIO_PIN_11
#define SPI_GPIO			GPIOA
#define SPI_CS_GPIO			GPIOB
#define SPI_CS_PIN			GPIO_PIN_12

/**
 * @brief met le pin CS a 0
 */
void selectCS(void){
	HAL_GPIO_WritePin(SPI_CS_GPIO, SPI_CS_PIN, GPIO_PIN_RESET);
}

/**
 * @brief met le pin CS a 1
 */
void unselectCS(void){
	HAL_GPIO_WritePin(SPI_CS_GPIO, SPI_CS_PIN, GPIO_PIN_SET);
}

/**
 * @brief met le pin CE a 1
 */
void enableCE(void){
	HAL_GPIO_WritePin(SPI_CE_GPIO, SPI_CE_PIN, GPIO_PIN_SET);
}

/**
 * @brief met le pin CE a 0
 */
void disableCE(void){
	HAL_GPIO_WritePin(SPI_CE_GPIO, SPI_CE_PIN, GPIO_PIN_RESET);
}

/**
 * @brief Ecrit une valeur dans un registre du module
 *
 * @param Reg : Registre a modifier
 * @param Data : Donnee a ecrire dans le registre
 */
void nrf24_WriteReg(uint8_t Reg, uint8_t Data){
	uint8_t buf[2];
	buf[0]=Reg|1<<5;
	buf[1]=Data;

	selectCS();
	HAL_SPI_Transmit(SPI_PROTO, buf, 2, 100);
	unselectCS();
}


/**
 * @brief Ecrit une valeur de plus d'un octet dans un registre
 *
 * @param Reg : Registre a modifier
 * @param Data : Donnee a ecrire dans le registre
 * @param size : Taille de la donnee (en octets)
 */
void nrf24_WriteRegMulti(uint8_t Reg, uint8_t *Data, uint8_t size){
	uint8_t buf[2];
	buf[0]=Reg|1<<5;
	//buf[1]=Data;

	selectCS();
	HAL_SPI_Transmit(SPI_PROTO, &buf[0], 1, 100);
	HAL_SPI_Transmit(SPI_PROTO, Data, size, 100);

	unselectCS();
}


/**
 * @brief lit la valeur d'un registre du module
 *
 * @param Reg : Registre ou l'on veut lire la valeur
 * @return la valeur du registre
 */
uint8_t nrf24_ReadReg(uint8_t Reg){
	uint8_t data=0;
	selectCS();
	HAL_SPI_Transmit(SPI_PROTO, &Reg, 1, 100);
	HAL_SPI_Receive(SPI_PROTO, &data, 1, 100);
	unselectCS();
	return data;
}

/**
 * @brief lit la valeur d'un registre de plus d'un octet
 *
 * @param Reg : registre dont on veut la valeut
 * @param data : pointeur vers la ou l'on enregistre la valeur du registre
 * @param size : taille de la valeur a recuperer (en octets)
 */
void nrf24_ReadRegMulti(uint8_t Reg, uint8_t *data, uint16_t size){
	//uint8_t data=0;
	selectCS();
	HAL_SPI_Transmit(SPI_PROTO, &Reg, 1, 100);
	HAL_SPI_Receive(SPI_PROTO, data, size, 100);
	unselectCS();
}

/**
 * @brief Envoie une commande au module
 *
 * @param cmd : Commande a envoyer (voir datasheet module pour liste des commandes)
 */
void nrfsendcmd(uint8_t cmd){
	selectCS();
	HAL_SPI_Transmit(SPI_PROTO, &cmd, 1, 100);
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
	nrf24_WriteReg(RF_SETUP, 0x0e);
	enableCE();
}

/**
 * @brief initialise le module en mode Tx (envoi de donnees)
 *
 * @param Address : l'adresse du module
 * @param channel : chaine du module (mettre a 10)
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
 * @brief envoie une donnee et confirme son envoi
 *
 * @param data : pointeur vers la donnee a envoyer (32 bits)
 * @return true : donnee bien envoyee; false : donnee non envoyee
 */
uint8_t nrf24_Transmit(uint8_t *data){
	uint8_t cmdtosend = 0;
	selectCS();

	cmdtosend=W_TX_PAYLOAD;
	HAL_SPI_Transmit(SPI_PROTO, &cmdtosend, 1, 100);

	HAL_SPI_Transmit(SPI_PROTO, data, 32, 100);

	unselectCS();

	HAL_Delay(1);
	uint8_t test = nrf24_ReadReg(RF_SETUP);
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
 * @brief initialise le module en mode Rx (reception de donnees)
 *
 * @param Address : l'adresse du module
 * @param channel : chaine du module (mettre 10)
 */
void nrf24_RxMode(uint8_t *Address, uint8_t channel){
	disableCE();
	nrf24_WriteReg(RF_CH, channel);

	uint8_t en_rxaddr=nrf24_ReadReg(EN_RXADDR);
	en_rxaddr=en_rxaddr | (1<<1);
	nrf24_WriteReg(EN_RXADDR, en_rxaddr);
	nrf24_WriteRegMulti(RX_ADDR_P1, Address, 5);
	nrf24_WriteReg(RX_PW_P1, 32); //Set up la taille maximale de la donnee a recuperer

	//power up the device in RX mode
	uint8_t config = nrf24_ReadReg(CONFIG);
	config=config | (1<<1) | (1<<0);
	nrf24_WriteReg(CONFIG, config);
	enableCE();
}

/**
 * @brief observe si une donnee est arrivee dans la pipe
 *
 * @param pipenum : pipe a scuter
 * @return true : donnee disponible; false : pas de donnee
 */
uint8_t isDataAvailable(uint8_t pipenum){
	uint8_t status = nrf24_ReadReg(STATUS);

	//uint8_t check = nrf24_ReadReg(RF_SETUP);

	if((status&(1<<6)) && (status&(pipenum<<1))){
		nrf24_WriteReg(STATUS, (1<<6));
		return 1;
	}
	else
		return 0;
}

/**
 * @brief recupere la donnee dans la pipe 1
 *
 * @param data pointeur vers la ou l'on veut stocker la donnee (32 bits)
 */
void nrf24_Receive(uint8_t *data){
	uint8_t cmdtosend = 0;
	selectCS();

	cmdtosend=R_RX_PAYLOAD;
	HAL_SPI_Transmit(SPI_PROTO, &cmdtosend, 1, 100);

	HAL_SPI_Receive(SPI_PROTO, data, 32, 100);

	unselectCS();

	HAL_Delay(1);

	cmdtosend=FLUSH_RX;
	nrfsendcmd(cmdtosend);
}
