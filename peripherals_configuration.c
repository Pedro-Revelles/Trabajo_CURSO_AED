#include <stdint.h>
#include "REGISTERS_IO.h"
#include "peripherals_configuration.h"

//Reloj
RCC_AHB1ENR_t *const pAhbCrlReg = (RCC_AHB1ENR_t*) AHB1ENR; //RELOJ DE LAS SALIDAS

GPIOx_ODR_t *const pGpio0ddEnr = (GPIOx_ODR_t*) GPIOB_ODR_ADDR; //ACTIVAR PIN SELECCIONADO

//Modos
GIPIOx_MODE_t *const pGpioModerB = (GIPIOx_MODE_t*) GPIOB_MODER_ADDR; //CONFIGURAR MODO DE CADA PUERTB
GIPIOx_MODE_t *const pGpioModerC = (GIPIOx_MODE_t*) GPIOC_MODER_ADDR; //CONFIGURAR MODO DE CADA PUERTC
GIPIOx_MODE_t *const pGpioModerD = (GIPIOx_MODE_t*) GPIOD_MODER_ADDR; //CONFIGURAR MODO DE CADA PUERTD
GIPIOx_MODE_t *const pGpioModerG = (GIPIOx_MODE_t*) GPIOG_MODER_ADDR; //CONFIGURAR MODO DE CADA PUERTG
GIPIOx_MODE_t *const pGpioModerE = (GIPIOx_MODE_t*) GPIOE_MODER_ADDR; //CONFIGURAR MODO DE CADA PUERTG

//IDR
GPIOx_IDR_t *const pGpioIDRc = (GPIOx_IDR_t*) GPIOC_IDR_ADDR; //ACTIVAR PIN SELECCIONADO
GPIOx_IDR_t *const pGpioIDRd = (GPIOx_IDR_t*) GPIOD_IDR_ADDR; //ACTIVAR PIN SELECCIONADO
GPIOx_IDR_t *const pGpioIDRg = (GPIOx_IDR_t*) GPIOG_IDR_ADDR; //ACTIVAR PIN SELECCIONADO
//Pull-up
GPIOx_PUPDR_t *const pGpioPullupC = (GPIOx_PUPDR_t*) GPIOC_PUPDR;
GPIOx_PUPDR_t *const pGpioPullupD = (GPIOx_PUPDR_t*) GPIOD_PUPDR;
GPIOx_PUPDR_t *const pGpioPullupG = (GPIOx_PUPDR_t*) GPIOG_PUPDR;
//ODR
GPIOx_ODR_t *const pGpioODRb = (GPIOx_ODR_t*) GPIOB_ODR_ADDR; //ACTIVAR PIN SELECCIONADO




int output_led (void)
{
	//1. Configurar clock GPIOC, GPIOD, GPIOG
	pAhbCrlReg->gpioB_en = 1;
	pAhbCrlReg->gpioD_en = 1;
	pAhbCrlReg->gpioE_en = 1;

	//2. Configurar en MODE como salida "00"
	pGpioModerE->pin_14 = 1;
	pGpioModerB->pin_6 = 1;
	pGpioModerB->pin_2 = 1;
	pGpioModerD->pin_12 = 1;
	pGpioModerD->pin_13 = 1;
	pGpioModerD->pin_11 = 1;

	//3. Activar salida
	//pGpio0ddEnr->pin_0=1;

	//prueba
	pGpioModerB->pin_0 = 1;
	pGpioModerB->pin_7 = 1;
	pGpioModerB->pin_14 = 1;


	pGpioODRb->pin_0 = 1;
	pGpioODRb->pin_7 = 1;
	pGpioODRb->pin_14 = 1;




	return 0;
}

int input_botton (void)
{


	//1. Configurar clock GPIOC, GPIOD, GPIOG
	pAhbCrlReg->gpioC_en = 1;
	pAhbCrlReg->gpioD_en = 1;
	pAhbCrlReg->gpioG_en = 1;

	//2. Configuramos el MODO
		//Puerta C
	pGpioModerC->pin_9 = 0;		//	uint32_t *const pGpioModerC_ = (uint32_t*) GPIOC_MODER_ADDR;
	pGpioModerC->pin_10 = 0;	//	*pGpioModerC_ &=~(0xFF<<18);
	pGpioModerC->pin_11 = 0;	//
	pGpioModerC->pin_12 = 0;	//
		//Puerta D
	pGpioModerD->pin_2 = 0;
		//Puerta G
	pGpioModerG->pin_2 = 0;

	//3. COnfiguracion Pull-up
		//Puerta C
	pGpioPullupC->PUPDR9 = 01;	//	uint32_t *const pGpioPullupC_ = (uint32_t*) GPIOC_PUPDR;
	pGpioPullupC->PUPDR10 = 01;	//	*pGpioPullupC_ &=~(0xFF<<18);
	pGpioPullupC->PUPDR11 = 01;	//	*pGpioPullupC_ |=(0x55<<18);
	pGpioPullupC->PUPDR12 = 01;	//
		//Puerta D
	pGpioPullupD->PUPDR2 = 01;
		//Puerta G
	pGpioPullupG->PUPDR2 = 01;

	//4. Borrar estado de las puertas
	pGpioIDRc->pin_9 = 0;		// uint32_t *const pGpioIDRc_ = (uint32_t*) GPIOC_IDR_ADDR;
	pGpioIDRc->pin_10 = 0;		// *pGpioIDRc_ &=~(0xFF<<18);
	pGpioIDRc->pin_11 = 0;
	pGpioIDRc->pin_12 = 0;

	pGpioIDRd->pin_2 = 0;

	pGpioIDRg->pin_2 = 0;



	return 0;
}






