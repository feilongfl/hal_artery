/**
  **************************************************************************
  * @file     at32f43x_conf.h
  * @version  v2.0.8
  * @date     2022-04-25
  * @brief    at32f43x config header file
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F43X_CONF_H
#define __AT32F43X_CONF_H

#ifdef __cplusplus
extern "C" {
#endif


/**
  * @brief in the following line adjust the value of high speed exernal crystal (hext)
  * used in your application
  * tip: to avoid modifying this file each time you need to use different hext, you
  *      can define the hext value in your toolchain compiler preprocessor.
  */
#if !defined  HEXT_VALUE
#define HEXT_VALUE                       ((uint32_t)8000000) /*!< value of the high speed exernal crystal in hz */
#endif

/**
  * @brief in the following line adjust the high speed exernal crystal (hext) startup
  * timeout value
  */
#define HEXT_STARTUP_TIMEOUT             ((uint16_t)0x3000) /*!< time out for hext start up */
#define HICK_VALUE                       ((uint32_t)8000000) /*!< value of the high speed internal clock in hz */

#include "at32f43x_crm.h"
#include "at32f43x_tmr.h"
#include "at32f43x_ertc.h"
#include "at32f43x_gpio.h"
#include "at32f43x_i2c.h"
#include "at32f43x_usart.h"
#include "at32f43x_pwc.h"
#include "at32f43x_can.h"
#include "at32f43x_adc.h"
#include "at32f43x_dac.h"
#include "at32f43x_spi.h"
#include "at32f43x_dma.h"
#include "at32f43x_debug.h"
#include "at32f43x_flash.h"
#include "at32f43x_crc.h"
#include "at32f43x_wwdt.h"
#include "at32f43x_wdt.h"
#include "at32f43x_exint.h"
#include "at32f43x_sdio.h"
#include "at32f43x_xmc.h"
#include "at32f43x_acc.h"
#include "at32f43x_misc.h"
#include "at32f43x_edma.h"
#include "at32f43x_qspi.h"
#include "at32f43x_scfg.h"
#include "at32f43x_emac.h"
#include "at32f43x_dvp.h"
#include "at32f43x_usb.h"

#ifdef __cplusplus
}
#endif

#endif /* __AT32F43X_CONF_H */


