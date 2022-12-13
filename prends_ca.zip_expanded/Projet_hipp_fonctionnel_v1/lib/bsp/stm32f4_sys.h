/*
 *	Club Robot ESEO 2009 - 2010
 *	Chomp
 *
 *	Fichier : QS_sys.c
 *	Package : Qualite Soft
 *	Description : Configuration du STM32 - Horloges - Démarrage
 *	Auteur : Gwenn
 *	Version 20100421
 */

#ifndef QS_SYS_H
#define QS_SYS_H
#include "stm32f4xx_hal.h"
#include "stm32f4_uart.h"
void SYS_init(void);
void SYS_set_std_usart(uart_id_e in, uart_id_e out, uart_id_e err);

typedef void (*callback_fun_t)(void);
void SYS_set_usr_systick_handler(callback_fun_t func);
void Delay(uint32_t wait_duration_ms);

#endif /* ndef QS_SYS_H */
