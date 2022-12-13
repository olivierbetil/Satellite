/*
 * usb_conf.h
 *
 *  Created on: 18 ao�t 2015
 *      Author: S. Poiraud
 */

#ifndef APPLI_USB_CONF_H_
#define APPLI_USB_CONF_H_

//#define USE_HOST_MODE
#define USE_DEVICE_MODE

#ifdef USE_HOST_MODE
	#define USB_USE_FS
	//#define USB_USE_HS
	#define USB_USE_HOST	//for TM dual host lib
	#ifdef USE_DEVICE_MODE
	#error "You MUST NOT define HOST and DEVICE mode... A choice MUST be done!"
	#endif
#endif

#define USE_USB_OTG_FS

#endif /* APPLI_USB_CONF_H_ */
