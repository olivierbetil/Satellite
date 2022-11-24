/*
 * config.h
 *
 *  Created on: 27 oct. 2015
 *      Author: S. Poiraud
 */

#ifndef APPLI_CONFIG_H_
#define APPLI_CONFIG_H_

#define I_AM_IN_GPE			1		//Indiquer 1 si vous �tes en I1 (activit� GPE), 0 sinon.

#if I_AM_IN_GPE
#define DEMO_WITH_LCD		1		//Indiquer 0 si vous �tes en I1 (activit� GPE), 1 sinon.
#else
	#define DEMO_WITH_LCD		0

			/*Cette configuration permet de s'adapter � ces deux situations :

				1 : La carte BaseBoard et un LCD tactile sont branch�s
						-> le menu est affich� sur l'UART et sur l'�cran, et les fonctionnalit�s tactiles sont disponibles
				0 : La carte STM32F4-DISCOVERY est nue, ou branch�e � un support fait maison
						-> le menu est affich� sur l'UART
			*/
#endif

#endif /* APPLI_CONFIG_H_ */
