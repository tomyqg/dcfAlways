/**
 * \file
 *
 * \brief USB configuration file
 *
 * Copyright (c) 2009 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _CONF_USB_H_
#define _CONF_USB_H_

#define UDD_NO_SLEEP_MGR

#include "usb_atmel.h"
#include "compiler.h"

//#warning You must refill the following definitions with a correct values

/**
 * USB Device Configuration
 * @{
 */

//! Device definition (mandatory)
#define  USB_DEVICE_VENDOR_ID             USB_VID_ATMEL
#define  USB_DEVICE_PRODUCT_ID            USB_PID_ATMEL_ASF_HIDGENERIC
#define  USB_DEVICE_MAJOR_VERSION         13
#define  USB_DEVICE_MINOR_VERSION         03
#define  USB_DEVICE_POWER                 100 // Consumption on Vbus line (mA)
#define  USB_DEVICE_ATTR                  \
	(USB_CONFIG_ATTR_SELF_POWERED)
// (USB_CONFIG_ATTR_BUS_POWERED)
//	(USB_CONFIG_ATTR_REMOTE_WAKEUP|USB_CONFIG_ATTR_SELF_POWERED)
//	(USB_CONFIG_ATTR_REMOTE_WAKEUP|USB_CONFIG_ATTR_BUS_POWERED)

//! USB Device string definitions (Optional)
// #define  USB_DEVICE_MANUFACTURE_NAME      "Manufacture name"
// #define  USB_DEVICE_PRODUCT_NAME          "Product name"
// #define  USB_DEVICE_SERIAL_NAME           "12...EF"

/**
 * Device speeds support
 * @{
 */
//! To define a Low speed device
//#define  USB_DEVICE_LOW_SPEED

//! To authorize the High speed
#if (UC3A3||UC3A4)
//#define  USB_DEVICE_HS_SUPPORT
#endif
//@}

/**
 * USB Device Callbacks definitions (Optional)
 * @{
 */
#define  UDC_VBUS_EVENT(b_vbus_high)      user_callback_vbus_action(b_vbus_high)
// #define  UDC_SOF_EVENT()                  user_callback_sof_action()
// #define  UDC_SUSPEND_EVENT()              user_callback_suspend_action()
// #define  UDC_RESUME_EVENT()               user_callback_resume_action()
//! Mandatory when USB_DEVICE_ATTR authorizes remote wakeup feature
// #define  UDC_REMOTEWAKEUP_ENABLE()        user_callback_remotewakeup_enable()
// #define  UDC_REMOTEWAKEUP_DISABLE()       user_callback_remotewakeup_disable()
//! When a extra string descriptor must be supported
//! other than manufacturer, product and serial string
// #define  UDC_GET_EXTRA_STRING()
//@}

//@}


/**
*   user defined callbacks
*
*   pn 9.7.12 just testingg and trying around with usb
*
*/

void initUSB();

void attemptSendUSBString(char* st1);

void user_callback_vbus_action(unsigned char b_vbus_high);

bool user_callback_UDI_HID_GENERIC_ENABLE_EXT(); 

bool user_callback_UDI_HID_GENERIC_DISABLE_EXT();

void user_callback_UDI_HID_GENERIC_REPORT_IN_SENT();

void user_callback_UDI_HID_GENERIC_REPORT_OUT(uint8_t* ptr);

void user_callback_UDI_HID_GENERIC_SET_FEATURE(uint8_t*  ptr);


/**
 * USB Interface Configuration
 * @{
 */
/**
 * Configuration of HID Generic interface
 * @{
 */
//! Interface callback definition
#define  UDI_HID_GENERIC_ENABLE_EXT()       	user_callback_UDI_HID_GENERIC_ENABLE_EXT() 
#define  UDI_HID_GENERIC_DISABLE_EXT()			user_callback_UDI_HID_GENERIC_DISABLE_EXT()
#define  UDI_HID_GENERIC_REPORT_OUT(ptr)        user_callback_UDI_HID_GENERIC_REPORT_OUT(ptr)

#define  UDI_HID_GENERIC_REPORT_IN_SENT()        user_callback_UDI_HID_GENERIC_REPORT_IN_SENT()
// PN 15. jul 12 added this report for micrium integration

#define  UDI_HID_GENERIC_SET_FEATURE(ptr)       user_callback_UDI_HID_GENERIC_SET_FEATURE(ptr)   

//! Sizes of I/O reports
#define  UDI_HID_REPORT_IN_SIZE             64
#define  UDI_HID_REPORT_OUT_SIZE            64
#define  UDI_HID_REPORT_FEATURE_SIZE        4

//! Sizes of I/O endpoints
#define  UDI_HID_GENERIC_EP_SIZE            64
//@}
//@}


/**
 * USB Device Driver Configuration
 * @{
 */
//@}

//! The includes of classes and other headers must be done at the end of this file to avoid compile error
#include "udi_hid_generic_conf.h"

#endif // _CONF_USB_H_
