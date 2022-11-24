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
#include "demo_camera.h"
#include "stm32f4_gpio.h"
#include "stm32f4_timer.h"
#include "stm32f4_uart.h"
#include "stm32f4_sys.h"

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

	UART_init(UART2_ID,115200);	//Initialisation de l'USART2 (PA2=Tx, PA3=Rx, 115200 bauds/sec)
	UART_init(UART6_ID,115200);	//Initialisation de l'USART6 (PC6=Tx, PC7=Rx, 115200 bauds/sec)
	SYS_set_std_usart(UART6_ID,UART6_ID,UART6_ID);

	while (1) {
		Camera_statemachine(FALSE, MODE_CAMERA_TO_SRAM);
	}
}

