/***
 * \file TIMER.c
 * \author S. Poiraud
 * \date 23 janvier 2014
 * \brief Contient les fonctions pour configurer, lancer et gerer les interruption du timer 2.
 */
#include "stm32f4_timer.h"
#include "stm32f4_sys.h"
#include "stm32f4xx_hal.h"

#ifndef DISABLE_BSP_TIMER

/* Declaration du Handle en globale pour pouvoir y acceder lors d'une interruption*/
static TIM_HandleTypeDef Tim2_Handle;

/**
 * @brief 	Routine d'interruption appel�e AUTOMATIQUEMENT lorsque le timer 2 arrive a �cheance.
 * @func 	void TIM2_IRQHandler(void)
 * @pre		Cette fonction NE DOIT PAS �tre appel�e directement par l'utilisateur...
 * @post	Acquittement du flag d'interruption, et appel de la fonction de l'utilisateur : TIMER2_user_handler_it_1ms()
 * @note	Nous n'avons PAS le choix du nom de cette fonction, c'est comme �a qu'elle est nomm�e dans le fichier startup.s !
 */
void TIM2_IRQHandler(void) {
	if (__HAL_TIM_GET_IT_SOURCE(&Tim2_Handle, TIM_IT_UPDATE) != RESET) //Si le flag est lev�...
			{
		__HAL_TIM_CLEAR_IT(&Tim2_Handle, TIM_IT_UPDATE);//...On l'acquitte...
		TIMER2_user_handler_it_1ms();//...Et on appelle la fonction qui nous int�resse
	}
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}

//L'attribut weak indique � l'�diteur de liens, lors de la compilation, que cette fonction sera ignor�e s'il en existe une autre portant le m�me nom. Elle sera choisie par d�faut d'autre fonction homonyme.
//Ainsi, si l'utilisateur d�finie sa propre TIMER2_user_handler_it_1ms(), elle sera appel�e
//Sinon, aucun message d'erreur n'indiquera que cette fonction n'existe pas !
__weak void TIMER2_user_handler_it_1ms(void) {

}

#define TIM2_3_4_5_6_7_12_13_14_CLK    84000000	// = 2*PCLK1

/**
 * @brief	Initialisation et lancement du timer 2.
 * 			Cette fonction lance de timer 2 et le configure pour qu'il d�clenche sa routine d'interruption toutes les ms.
 * @func 	void TIMER2_run_1ms(void)
 * @post	Le timer 2 et son horloge sont activ�s, ses interruptions autoris�es, et son d�compte lanc�.
 */
void TIMER2_run_1ms(void) {
	// On active l'horloge du TIM2
	__HAL_RCC_TIM2_CLK_ENABLE();

	// On fixe les priorit�s des interruptions du timer2 PreemptionPriority = 0, SubPriority = 1 et on autorise les interruptions
	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	// Time base configuration
	Tim2_Handle.Instance = TIM2; //On donne le timer 2 en instance � notre gestionnaire (Handle)
	Tim2_Handle.Init.Period = 1000; //period_us - p�riode choisie en us : Min = 1us, Max = 65535 us
	Tim2_Handle.Init.Prescaler = TIM2_3_4_5_6_7_12_13_14_CLK / (1000000) - 1; //divise notre clock de timer par 84 (afin d'augmenter la p�riode maximale)
	Tim2_Handle.Init.ClockDivision = 0;
	Tim2_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	// On applique les param�tres d'initialisation
	HAL_TIM_Base_Init(&Tim2_Handle);

	// On autorise les interruptions
	HAL_TIM_Base_Start_IT(&Tim2_Handle);

	// On lance le timer2
	__HAL_TIM_ENABLE(&Tim2_Handle);
}

#endif

