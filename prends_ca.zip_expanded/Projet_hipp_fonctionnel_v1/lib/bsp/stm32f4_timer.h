/**
 * TIMER.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Nirgal
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "stm32f4xx_hal.h"

#include "main.h"	//Permet de d�sactiver ce module logiciel en d�finissant DISABLE_BSP_TIMER. Utile � des fins p�dagogiques uniquement.
#ifndef DISABLE_BSP_TIMER
/**
 * @brief	Initialisation et lancement du timer 2.
 * 			Cette fonction lance de timer 2 et le configure pour qu'il d�clenche sa routine d'interruption toutes les ms.
 * @func 	void TIMER2_run_1ms(void)
 * @post	Le timer 2 et son horloge sont activ�s, ses interruptions autoris�es, et son d�compte lanc�.
 */
void TIMER2_run_1ms(void);

/**
 * @brief	Fonction de l'utilisateur appel�e par la routine d'interruption du timer 2.
 * 			Cette fonction doit etre d�finie par l'utilisateur... Elle est appel�e par la routine d'IT du timer 2.
 * @func 	void TIMER2_user_handler_it_1ms(void)
 * @post	Le timer 2 et son horloge sont activ�s, ses interruptions autoris�es, et son d�compte lanc�.
 */
void TIMER2_user_handler_it_1ms(void);

#endif
#endif /* TIMER_H_ */
