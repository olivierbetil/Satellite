/**
 *
 * \file main.c projet-exemple-gpe
 */

/* Includes ------------------------------------------------------------------*/
#include "config.h"
#include "stm32f4xx_hal.h"
#include "macro_types.h"
#include "main.h"
#include "config.h"
#include <stdio.h>
#include "demo_camera.h"
#include "stm32f4_gpio.h"
#include "stm32f4_timer.h"
#include "stm32f4_uart.h"
#include "stm32f4_sys.h"
#include "nrf24l01.h"


SPI_HandleTypeDef hspi2;


/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    //Error
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_SPI2_CLK_ENABLE();

	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_11, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FAST, 0);
	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_12, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FAST, 0);
	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_13, GPIO_MODE_AF_PP, GPIO_NOPULL, GPIO_SPEED_FAST, GPIO_AF5_SPI2);
	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_14, GPIO_MODE_AF_PP, GPIO_NOPULL, GPIO_SPEED_FAST, GPIO_AF5_SPI2);
	BSP_GPIO_PinCfg(GPIOB, GPIO_PIN_15, GPIO_MODE_AF_PP, GPIO_NOPULL, GPIO_SPEED_FAST, GPIO_AF5_SPI2);
}
/**
 * @brief  Main program.
 * @func int main(void)
 * @param  None
 * @retval None
 */
int main(void) {
	HAL_Init();
	SYS_init();			//initialisation du systeme (horloge...)
	GPIO_Configure();	//Configuration des broches d'entree-sortie.
	TIMER2_run_1ms();	//Lancement du timer 2 a une periode d'1ms.
	Camera_reset();

	//UART_init(UART2_ID,115200);	//Initialisation de l'USART2 (PA2=Tx, PA3=Rx, 115200 bauds/sec)
	UART_init(UART6_ID,115200);	//Initialisation de l'USART6 (PC6=Tx, PC7=Rx, 115200 bauds/sec)

	UART_init(UART1_ID, 9600);
	SYS_set_std_usart(UART6_ID,UART6_ID,UART6_ID);

	DEMO_accelerometer_close();	//On initialise l'accéléromètre pour configurer ses sorties en opendrain... pour qu'elles n'entrent pas en conflit avec la caméra !

	MX_SPI2_Init(); // Initialisation SPI2
	uint8_t Address[]={0xEE, 0xDD, 0xCC, 0xBB, 0xAA};
	uint8_t data[32]="helloworld";
	nrf24_Init();
	nrf24_TxMode(Address, 10);
	if(nrf24_Transmit(data) == 1){
		//L'info c'est bien envoyé
	}

	while (1) {
		Camera_statemachine(FALSE, MODE_CAMERA_TO_SRAM);
		if(nrf24_Transmit(data) == 1){
				//L'info c'est bien envoyé
		}
	}
}
