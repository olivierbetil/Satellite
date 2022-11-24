/**
 * demo.c
 *
 *  Created on: 24 fevr. 2015
 *      Author: Samuel Poiraud
 *
 *      @brief Cette application fournit une demo d'utilisation d'un ensemble de librairies.
 *
 *      Toute application de votre creation peut se construire sur la base de ce modele.
 */

#include "stm32f4xx_hal.h"
#include "config.h"
#include "stm32f4_gpio.h"
#include "stm32f4_timer.h"
#include "stm32f4_uart.h"
#include "stm32f4_sys.h"
#include "demo.h"
#include <string.h>

//Enumeration des identifiants des menus affiches sur l'ecran
//ATTENTION, il y a correspondance entre les elements de l'enum menu_choice_e et les boutons menu_buttons
typedef enum {
	CHOICE_NONE = 0, CHOICE_MATRIX_KEYBOARD, CHOICE_NB
} menu_choice_e;

void DEMO_IHM_display_menu(void);
static void DEMO_state_machine(bool_e button_pressed, char touch_pressed);
menu_choice_e DEMO_IHM_menu_choice_uart(void);
running_e DEMO_IHM_read_number(uint32_t *nb);
#define BUFFER_SIZE	10
static char buffer[BUFFER_SIZE];
static uint8_t buffer_index = 0;
char DEMO_IHM_uart_read(void);
volatile static uint8_t t = 0;

typedef struct {
	char *text;
} menu_button_t;

const menu_button_t menu_buttons[CHOICE_NB] = { { "" },		//CHOICE_NONE,
		{ "MatrixKeyboard" },		//CHOICE_MATRIX_KEYBOARD,
		};

//Definition de deux lecteurs physiques pour FATFS
//PARTITION VolToPart[2] = {(PARTITION){PD_SD, 0}, (PARTITION){1, 1}};

//////////////Fonctions publiques

/**
 * @brief Cette fonction d'initialisation doit etre appelee une fois, prealablement a tout appel a une autre fonction de ce module logiciel.
 * 			Elle configure les broches d'entree-sortie, lance un timer (1ms) et initialise l'USART2.
 * @post	Un message de bienvenue est envoye sur la sortie de l'USART2
 */
void DEMO_init(void) {
	HAL_Init();
	SYS_init();			//initialisation du systeme (horloge...)
	GPIO_Configure();	//Configuration des broches d'entree-sortie.
	TIMER2_run_1ms();	//Lancement du timer 2 a une periode d'1ms.

	UART_init(UART2_ID, 115200);//Initialisation de l'USART2 (PA2=Tx, PA3=Rx, 115200 bauds/sec)
	UART_init(UART6_ID, 115200);//Initialisation de l'USART6 (PC6=Tx, PC7=Rx, 115200 bauds/sec)
	SYS_set_std_usart(UART6_ID, UART6_ID, UART6_ID);
}

/**
 * @brief cette fonction doit etre appelee periodiquement en t�che de fond. Elle assure la lecture du bouton bleu et appelle la machine a etats de l'application de demo.
 */
void DEMO_process_main(void) {
	static bool_e bt_previous;
	bool_e bt_current;
	bool_e button_pressed;
	char touch_pressed;

	//Detection d'appui bouton.
	bt_current = (bool_e) HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);//Lecture bouton.
	button_pressed = (!bt_previous && bt_current);//Detection d'un appui bouton
	bt_previous = bt_current;			//Memorisation pour le prochain passage.

	touch_pressed = DEMO_IHM_uart_read();//Bufferise chaque caract�re re�u et le renvoi.

	//Detection de l'appui sur
	DEMO_state_machine(
			button_pressed || touch_pressed == 'm' || touch_pressed == 'M',
			touch_pressed);

}

/**
 * @brief	Fonction appelee automatiquemeent en interruption suite au debordement du timer 2, toutes les 1 ms.
 * @post	cette fonction est utilisee pour appeler periodiquement les routines d'interruption des modules logiciels qui en ont besoin.
 */
void TIMER2_user_handler_it_1ms(void) {
	if (t)
		t--;

	//Ces modules logiciels souhaitent etre appeles toutes les ms. (pour incrementer des compteurs, ou lever des flags)
	//ATTENTION, chacune de ces fonction appelees ici doit s'engager a ne pas durer "trop longtemps" (duree d'execution tres inferieur a 1ms !!!)
	//DEMO_matrix_keyboard_process_1ms();
}

////////////////Fonctions privees
//#define DEFAULT_APPLI	CHOICE_ADC		//Si on veut voir le menu
//#define DEFAULT_APPLI	USB_DEVICE		//Si on veut qu'une appli se lance directement

/**
 * @brief	Cette fonction privee est une machine a etat qui regit le comportement de l'application demo.
 * 			Elle affiche un menu a l'ecran et reagit en fonction des appuis sur l'ecran tactile ou sur le bouton.
 * 			Le menu fonctionne sous la forme suivante :
 * 					Lorsqu'on choisit un bouton sur l'ecran LCD tactile, cette machine a etat bascule dans l'etat correspondant.
 * 					Dans cet etat, on appelle une "sous-machine a etat", qui va "vivre sa vie"... et renvoyer un argument du type running_e
 * 					Si cette sous-machine a etat continue de tourner, elle renvoit IN_PROGRESS.
 * 					Si cette sous-machine a etat a termine, elle renvoit autre chose, et on revient a l'affichage du menu.
 * 			Ainsi, on peut considerer que la fonction DEMO_state_machine entretient le lancement d'une application que l'on choisit... ou demande son arret.
 */
static void DEMO_state_machine(bool_e button_pressed, char touch_pressed) {
	__unused typedef enum
	{
			INIT = 0,
			//...
			//Aucun �tat ne peut �tre plac� ici...
			//Les valeurs de l'enum menu_choice_e sont des �tats possibles ! (sauf CHOICE_NONE et CHOICE_NB)
			//...
			//...
		DISPLAY_MENU = CHOICE_NB,
		WAIT_MENU_CHOICE,
		IDLE
	} state_e;
	static uint8_t state = INIT;//Volontairement non d�clar�s comme state_e...

	switch (state) {
	case INIT:

		//state = DEFAULT_APPLI;
		break;
	case DISPLAY_MENU:
		DEMO_IHM_display_menu();			//On affiche le menu sur l'ecran
		state = WAIT_MENU_CHOICE;
		break;
	case WAIT_MENU_CHOICE: {
		menu_choice_e choice;
		choice = DEMO_IHM_menu_choice_uart();//La liaison s�rie peut communiquer un choix de menu

		if (button_pressed)
			state = DISPLAY_MENU;

		if (choice != CHOICE_NONE) {
			state = choice;
			printf("Launching %s...\n", menu_buttons[choice].text);
			printf(
					"Press M or blue button to ask the end of application and to return to the Menu.\n");
		}
		break;
	}			// On sort du menu choice

		/*	case CHOICE_SD_CARD:
		 if(DEMO_sd_state_machine(button_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_USB_KEY:
		 if(DEMO_USB_state_machine(button_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_USB_HOST_HID:
		 if(DEMO_USB_Host_Hid_state_machine(button_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_ACCELEROMETER:
		 if(DEMO_accelerometer_state_machine(button_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_PWM:
		 if(DEMO_pwm_statemachine(button_pressed, touch_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_MOUSE:
		 if(DEMO_usb_device_statemachine(button_pressed,touch_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_DAC:
		 if(DEMO_dac_statemachine(button_pressed, touch_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 case CHOICE_ADC:
		 if(DEMO_adc_statemachine(button_pressed) != IN_PROGRESS)
		 state = DISPLAY_MENU;
		 break;
		 */case IDLE:
		if (button_pressed)
			state = DISPLAY_MENU;
		break;
	case CHOICE_MATRIX_KEYBOARD:
		if (DEMO_matrix_keyboard_process_main(button_pressed) != IN_PROGRESS)
			state = INIT;
		break;
	default:
		state = INIT;	//Never happen.
		break;
	}
}

/**
 * @brief Cette fonction affiche sur l'ecran LCD l'ensemble des elements du menu, en utilisant le tableau menu_buttons.
 */
void DEMO_IHM_display_menu(void) {
	menu_choice_e i;
	printf("________Menu_________\n");
	for (i = CHOICE_NONE + 1; i < CHOICE_NB; i++)//Pour chaque element i du menu... on affiche...
		printf("%02d : %s\n", i, menu_buttons[i].text);
}

/**
 * @brief cette fonction consulte l'ecran tactile. Si un appui est fait par l'utilisateur elle analyse sa position et renvoit l'identifiant de la case pressee.
 * @pre		cette fonction utilise le tableau menu_buttons qui contient la position de chaque bouton sur l'ecran
 * @pre		cette fonction necessite que l'ecran tactile soit correctement initialise
 * @post	attention, cette fonction prend en compte la detection d'appui, et ne renverra qu'une seule fois le menu presse lorsque l'utilisateur maintient son doigt sur un menu.
 * @return	cette fonction retourne un element de l'enumeration menu_choice_e (CHOICE_NONE si aucun menu n'est presse)
 */
menu_choice_e DEMO_IHM_menu_choice_uart(void) {
	menu_choice_e ret;
	uint32_t nb;
	ret = CHOICE_NONE;
	if (DEMO_IHM_read_number(&nb) == END_OK) {
		if (nb < CHOICE_NB)
			ret = (menu_choice_e) nb;	//On caste nb en menu_choice_e.
	}
	return ret;
}

char DEMO_IHM_uart_read(void) {
	char c;
	UART_putc(UART2_ID, 0x55);
	c = UART_getc(UART6_ID);
	if (!c)
		c = UART_getc(UART2_ID);
	if (c)	//Pour chaque caract�re re�u
	{
		buffer[buffer_index] = c;	//On range le caract�re dans le buffer
		if (buffer_index < BUFFER_SIZE)	//Si on est pas d�j� � la fin
			buffer_index++;				//On incr�mente l'index
	}
	return c;
}

running_e DEMO_IHM_read_number(uint32_t *nb) {
	running_e ret;
	uint8_t i, end_loop;
	ret = IN_PROGRESS;
	end_loop = buffer_index;
	for (i = 0; i < end_loop; i++) {
		switch (buffer[i]) {
		case 0:
			break;	//Impossible ?!
		case '\n':
		case '\r':
			buffer[i] = 0;		//On termine la commande par un z�ro terminal.
			buffer_index = 0;	//L'index revient � 0.
			*nb = strtol(buffer, NULL, 0);
			ret = END_OK;
			break;
		default:
			break;
		}
	}

	return ret;
}
