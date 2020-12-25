/* DEFINIMOS DIRECCIONES DE MEMORIA DE LOS REGISTROS
 * Y LAS ESTRUCTURAS PARA ABSTRAER LOS BITS QUE QUEREMOS
 * CONFIGURAR
 */
#ifndef REGISTERS_IO_H_
#define REGISTERS_IO_H_
#include <stdint.h>

//RCC_AHB1ENR para todas las puertas
#define AHB1RCC 0x40023800UL
#define AHB1ENR_OFFSET 0x30UL
#define AHB1ENR (AHB1RCC+AHB1ENR_OFFSET)

#define GPIOx_MODER_OFFSET 0x00UL //offset de MODER (para todas las puertas)
#define GPIO_ODR_OFFSET 0x14UL //offset del ODR, salida (para todas las puertas)
#define GPIOA_IDR_OFFASET 0x10UL //offset del IDR, entrada (para todas las puertas)
//PuetaB
#define GPIOB_BASE_ODDR 0x40020400UL
#define GPIOB_MODER_ADDR (GPIOB_BASE_ODDR+GPIOx_MODER_OFFSET)//MODO PORTB
#define GPIOB_ODR_ADDR (GPIOB_BASE_ODDR+GPIO_ODR_OFFSET)//SALIDA PORTB

//PuertaA
#define GPIOA_BASE 0x40020000UL
#define GPIOA_MODER_ADDR (GPIOA_BASE+GPIO_MODER_OFFSET)//MODO PORTA
#define GPIOA_IDR_ADDR (GPIOA_BASE+GPIOA_IDR_OFFASET)//ENTRADA PORTA

typedef struct //RELOJ
{
	uint32_t gpioA_en:1;
	uint32_t gpioB_en:1;
	uint32_t gpioC_en:1;
	uint32_t gpioD_en:1;
	uint32_t gpioE_en:1;
	uint32_t gpioF_en:1;
	uint32_t gpioG_en:1;
	uint32_t gpioH_en:1;
	uint32_t gpioI_en:1;
	uint32_t Reserved1:23;
}RCC_AHB1ENR_t;

typedef struct//MODO
{
	uint32_t pin_0:2;
	uint32_t pin_1:2;
	uint32_t pin_2:2;
	uint32_t pin_3:2;
	uint32_t pin_4:2;
	uint32_t pin_5:2;
	uint32_t pin_6:2;
	uint32_t pin_7:2;
	uint32_t pin_8:2;
	uint32_t pin_9:2;
	uint32_t pin_10:2;
	uint32_t pin_11:2;
	uint32_t pin_12:2;
	uint32_t pin_13:2;
	uint32_t pin_14:2;
	uint32_t pin_15:2;
}GIPIOx_MODE_t;

typedef struct //ODR
{
	uint32_t pin_0:1;
	uint32_t pin_1:1;
	uint32_t pin_2:1;
	uint32_t pin_3:1;
	uint32_t pin_4:1;
	uint32_t pin_5:1;
	uint32_t pin_6:1;
	uint32_t pin_7:1;
	uint32_t pin_8:1;
	uint32_t pin_9:1;
	uint32_t pin_10:1;
	uint32_t pin_11:1;
	uint32_t pin_12:1;
	uint32_t pin_13:1;
	uint32_t pin_14:1;
	uint32_t pin_15:1;
	uint32_t Reserved:16;
}GPIOx_ODR_t;//REGISTRO DE DATOS DE SALIDA


typedef struct //IDR
{
	uint32_t pin_0:1;
	uint32_t pin_1:1;
	uint32_t pin_2:1;
	uint32_t pin_3:1;
	uint32_t pin_4:1;
	uint32_t pin_5:1;
	uint32_t pin_6:1;
	uint32_t pin_7:1;
	uint32_t pin_8:1;
	uint32_t pin_9:1;
	uint32_t pin_10:1;
	uint32_t pin_11:1;
	uint32_t pin_12:1;
	uint32_t pin_13:1;
	uint32_t pin_14:1;
	uint32_t pin_15:1;
	uint32_t Reserved:16;
}GPIOx_IDR_t; //REGISTRO DE DATOS DE ENTRADA





#endif /* REGISTERS_IO_H_ */
