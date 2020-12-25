#include <stdint.h>
#include "REGISTERS_IO.h"

int IO_register(void)
{
	RCC_AHB1ENR_t *const pAhbCrlReg = (RCC_AHB1ENR_t*) AHB1ENR; //RELOJ DE LAS SALIDAS
	GIPIOx_MODE_t *const pGpioModeEnr = (GIPIOx_MODE_t*) GPIOB_MODER_ADDR; //CONFIGURAR MODO DE CADA PUERTA
	GPIOx_ODR_t *const pGpio0ddEnr = (GPIOx_ODR_t*) GPIOB_ODR_ADDR; //ACTIVAR PIN SELECCIONADO


	//1. Activar reloj en puertaB en AHB1ENR
	pAhbCrlReg->gpioB_en = 1;

	//2. Configurar en MODE como salida "01"
	pGpioModeEnr->pin_0=1;

	//3. Activar salida
	pGpio0ddEnr->pin_0=1;

    /* Loop forever */
	for(;;);
}








