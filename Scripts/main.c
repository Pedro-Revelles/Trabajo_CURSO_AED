/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>

#define AHB1RCC 0x40023800UL
#define AHB1ENR_OFFSET 0x30UL

#define AHB1ENR (AHB1RCC+AHB1ENR_OFFSET)

#define GPIOB 0x40020400UL

#define GPIO_MODER_OFFSET 0x00UL
#define GPIO_MODER (GPIOB+GPIO_MODER_OFFSET)

#define GPIO_ODD_OFFSET 0x14UL
#define GPIO_ODD (GPIOB+GPIO_ODD_OFFSET)


int main(void)
{
    uint32_t *pAhbCrlReg = (uint32_t*)  AHB1ENR;
    uint32_t *pGpioModeEnr = (uint32_t*)  GPIO_MODER;
    uint32_t *pGpioOddEnr = (uint32_t*)  GPIO_ODD;

    //Direccion de 32 bits, pasamos un 1 a la posicion 1 para activar GPIOB
    *pAhbCrlReg |= (1 << 1);

    //LED1

    //Limpiamos primero lo que había en estos bits para tener la placa limpia
    //El 3 en binario es 11 asi que movido 0 posiciones cae justo en nuestro bit
    //~ Se escribe con alt + ñ
    *pGpioModeEnr &= ~(3 << 0);
    //Pasamos 01 a la poscion de GPIO del MODER0
    *pGpioModeEnr |= (1 << 0);

    //Pasamos un 1 a la posicion 0 del ODD, para encender el led
    *pGpioOddEnr |= (1 << 0);

    //LED2

    *pGpioModeEnr &= ~(3 << 14);
    *pGpioModeEnr |= (1 << 14);
    *pGpioOddEnr |= (1 << 7);

    //LED3

    *pGpioModeEnr &= ~(3 << 28);
    *pGpioModeEnr |= (1 << 28);
    *pGpioOddEnr |= (1 << 14);


	for(;;);
}
