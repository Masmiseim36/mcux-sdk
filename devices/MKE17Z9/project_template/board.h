/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME "FRDM-KE17Z512"

/*! @brief The UART to use for debug messages. */
#define BOARD_USE_UART
#define BOARD_DEBUG_UART_TYPE     kSerialPort_Uart
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) LPUART2
#define BOARD_DEBUG_UART_INSTANCE 2U
#define BOARD_DEBUG_UART_CLKSRC   kCLOCK_IpSrcSysOscAsync
#define BOARD_UART_IRQ            LPUART2_IRQn
#define BOARD_UART_IRQ_HANDLER    LPUART2_IRQHandler

/* @Brief Board accelerator sensor configuration */
#define BOARD_ACCEL_I2C_BASEADDR   LPI2C0
#define BOARD_ACCEL_I2C_CLOCK_FREQ CLOCK_GetIpFreq(kCLOCK_Lpi2c0)

#ifndef BOARD_DEBUG_UART_BAUDRATE
#define BOARD_DEBUG_UART_BAUDRATE 115200
#endif /* BOARD_DEBUG_UART_BAUDRATE */

/*! @brief The i2c instance used for i2c connection by default */
#define BOARD_I2C_BASEADDR LPI2C0

/*! @brief The CMP instance/channel used for board. */
#define BOARD_CMP_BASEADDR CMP0
#define BOARD_CMP_CHANNEL  0U

/*! @brief The rtc instance used for board. */
#define BOARD_RTC_FUNC_BASEADDR RTC

/*! @brief Indexes of the TSI channels for on-board electrodes */
#ifndef BOARD_TSI_ELECTRODE_1
#define BOARD_TSI_ELECTRODE_1 19U /* PTD16, TSI0_CH19 */
#endif
#ifndef BOARD_TSI_ELECTRODE_2
#define BOARD_TSI_ELECTRODE_2 3U /* PTA1, TSI1_CH3*/
#endif

/*! @brief Define the port interrupt number for the board switches */
#ifndef BOARD_SW2_GPIO
#define BOARD_SW2_GPIO GPIOE
#endif
#ifndef BOARD_SW2_PORT
#define BOARD_SW2_PORT PORTE
#endif
#ifndef BOARD_SW2_GPIO_PIN
#define BOARD_SW2_GPIO_PIN 14U
#endif
#define BOARD_SW2_IRQ         PORTAE_IRQn
#define BOARD_SW2_IRQ_HANDLER PORTAE_IRQHandler
#define BOARD_SW2_NAME        "SW2"

/* Board RGB LED color mapping */
#define LOGIC_LED_ON  0U
#define LOGIC_LED_OFF 1U
#ifndef BOARD_LED_RED_GPIO
#define BOARD_LED_RED_GPIO GPIOD
#endif
#define BOARD_LED_RED_GPIO_PORT PORTD
#ifndef BOARD_LED_RED_GPIO_PIN
#define BOARD_LED_RED_GPIO_PIN 10U
#endif
#ifndef BOARD_LED_GREEN_GPIO
#define BOARD_LED_GREEN_GPIO GPIOD
#endif
#define BOARD_LED_GREEN_GPIO_PORT PORTD
#ifndef BOARD_LED_GREEN_GPIO_PIN
#define BOARD_LED_GREEN_GPIO_PIN 5U
#endif
#ifndef BOARD_LED_BLUE_GPIO
#define BOARD_LED_BLUE_GPIO GPIOD
#endif
#define BOARD_LED_BLUE_GPIO_PORT PORTD
#ifndef BOARD_LED_BLUE_GPIO_PIN
#define BOARD_LED_BLUE_GPIO_PIN 12U
#endif

/*! @brief FRDM-TOUCH board defines */
/* Push buttons - mutual electrodes */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_TX_ELECTRODE_1 TF_TSI_MUTUAL_CAP_TX_CHANNEL_5 /* PTA10 */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_RX_ELECTRODE_1 TF_TSI_MUTUAL_CAP_RX_CHANNEL_9 /* PTE11  */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_TX_ELECTRODE_2 TF_TSI_MUTUAL_CAP_TX_CHANNEL_5 /* PTA10 */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_RX_ELECTRODE_2 TF_TSI_MUTUAL_CAP_RX_CHANNEL_8 /* PTC5  */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_TX_ELECTRODE_3 TF_TSI_MUTUAL_CAP_TX_CHANNEL_4 /* PTA11 */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_RX_ELECTRODE_3 TF_TSI_MUTUAL_CAP_RX_CHANNEL_9 /* PTE11  */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_TX_ELECTRODE_4 TF_TSI_MUTUAL_CAP_TX_CHANNEL_4 /* PTA11 */
#define FRDM_TOUCH_BOARD_TSI_MUTUAL_RX_ELECTRODE_4 TF_TSI_MUTUAL_CAP_RX_CHANNEL_8 /* PTC5  */

/* Slider - self electrodes */
#define FRDM_TOUCH_BOARD_TSI_SLIDER_ELECTRODE_1 TF_TSI_SELF_CAP_CHANNEL_15 /* PTE13 */
#define FRDM_TOUCH_BOARD_TSI_SLIDER_ELECTRODE_2 TF_TSI_SELF_CAP_CHANNEL_16 /* PTE5 */

/* Rotary - self electrodes */
#define FRDM_TOUCH_BOARD_TSI_ROTARY_ELECTRODE_1 TF_TSI_SELF_CAP_CHANNEL_10 /* PTE10 */
#define FRDM_TOUCH_BOARD_TSI_ROTARY_ELECTRODE_2 TF_TSI_SELF_CAP_CHANNEL_11 /* PTD1 */
#define FRDM_TOUCH_BOARD_TSI_ROTARY_ELECTRODE_3 TF_TSI_SELF_CAP_CHANNEL_13 /* PTE16 */
#define FRDM_TOUCH_BOARD_TSI_ROTARY_ELECTRODE_4 TF_TSI_SELF_CAP_CHANNEL_14 /* PTE15 */

/*! @brief Indexes of the TSI mutual channels for FRDM-TOUCH board */
#define BOARD_TSI_MUTUAL_TX_ELECTRODE_1 5U
#define BOARD_TSI_MUTUAL_RX_ELECTRODE_1 9U

#define LED_RED_INIT(output)                                           \
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, output); \
    BOARD_LED_RED_GPIO->PDDR |= (1U << BOARD_LED_RED_GPIO_PIN)                         /*!< Enable target LED_RED */
#define LED_RED_ON()  GPIO_PortClear(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Turn on target LED_RED */
#define LED_RED_OFF() GPIO_PortSet(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN)   /*!< Turn off target LED_RED */
#define LED_RED_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Toggle on target LED_RED1 */

#define LED_GREEN_INIT(output)                                             \
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, output); \
    BOARD_LED_GREEN_GPIO->PDDR |= (1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Enable target LED_GREEN */
#define LED_GREEN_ON() \
    GPIO_PortClear(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Turn on target LED_GREEN */
#define LED_GREEN_OFF() \
    GPIO_PortSet(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Turn off target LED_GREEN */
#define LED_GREEN_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Toggle on target LED_GREEN */

#define LED_BLUE_INIT(output)                                            \
    GPIO_PinWrite(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, output); \
    BOARD_LED_BLUE_GPIO->PDDR |= (1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Enable target LED_BLUE */
#define LED_BLUE_ON()                                                                               \
    GPIO_PortClear(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Turn on target LED_BLUE \
                                                                        */
#define LED_BLUE_OFF()                                                                             \
    GPIO_PortSet(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Turn off target LED_BLUE \
                                                                      */
#define LED_BLUE_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Toggle on target LED_BLUE */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

void BOARD_InitDebugConsole(void);
#if defined(SDK_I2C_BASED_COMPONENT_USED) && SDK_I2C_BASED_COMPONENT_USED
void BOARD_LPI2C_Init(LPI2C_Type *base, uint32_t clkSrc_Hz);
status_t BOARD_LPI2C_Send(LPI2C_Type *base,
                          uint8_t deviceAddress,
                          uint32_t subAddress,
                          uint8_t subaddressSize,
                          uint8_t *txBuff,
                          uint8_t txBuffSize);
status_t BOARD_LPI2C_Receive(LPI2C_Type *base,
                             uint8_t deviceAddress,
                             uint32_t subAddress,
                             uint8_t subaddressSize,
                             uint8_t *rxBuff,
                             uint8_t rxBuffSize);
void BOARD_Accel_I2C_Init(void);
status_t BOARD_Accel_I2C_Send(uint8_t deviceAddress, uint32_t subAddress, uint8_t subaddressSize, uint32_t txBuff);
status_t BOARD_Accel_I2C_Receive(
    uint8_t deviceAddress, uint32_t subAddress, uint8_t subaddressSize, uint8_t *rxBuff, uint8_t rxBuffSize);
#endif /* SDK_I2C_BASED_COMPONENT_USED */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
