/*
 * VL53_becon.h
 *
 *  Created on: 3 nov. 2019
 *      Author: Guillaume
 */

#ifndef VL53_BEACON_H_
#define VL53_BEACON_H_

#include "macro_types.h"

/*
 * initialise le module et les capteurs
 */
bool_e VL53L1X_init();

/*
 * recupère les info des capteurs VL53
 */
void VL53L1X_process_it();

/*
 *
 */
void VL53L1X_process_main(void);

uint16_t VL53L1X_get_distance(uint8_t id);

#endif /* VL53_BEACON_H_ */
