
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"

/* External variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef pHeader;
extern CAN_RxHeaderTypeDef pRxHeader;
extern uint32_t TxMailbox;
extern uint8_t a,r;

/******************************************************************************/
/*                     Interruption and Exception Handlers                    */
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{

}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{

  while (1)
  {

  }

}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{

  while (1)
  {
  }

}

/**
* @brief This function handles Pre-fetch fault, memory access fault.
*/
void BusFault_Handler(void)
{

  while (1)
  {

  }

}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{

  while (1)
  {

  }

}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{

}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{

}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{

}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}


/**
* @brief Esta función maneja la interrupción EXTI line0
*/
/*
 * /si se presiona el botón 'usuario', enviar mensaje a través del bus CAN
 * a partir de una interrupción
 */
void EXTI0_IRQHandler(void)
{


  //eliminar el rebote del contacto mecánico del interruptor y/o cualquier fallo externo
  for (int n=0;n<1000000;n++); //retrasa el programa para evitar falsas pulsaciones, DELAY
  /*
   * Boton de la Placa B1-----PA0 (configurado como interrupcion)
   */
  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)) //Si se ha pulsado el boton
	{
	  //A es nuestra variable de 8 bits de mensaje
		a++; //incrementa a
		//cuando llegue a 3 vuelve a cero
		if(a == 3)
		{
		    a = 0;
		}
		HAL_CAN_AddTxMessage(&hcan1, &pHeader, &a, &TxMailbox);  //function agregar mensaje para transmisión
	}

  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0); //maneja la solicitud de interrupción EXTI.


}

/**
* @brief Esta función maneja interrupciones CAN1 RX0.
*/
//si el bus CAN se interrumpe, alternar los LED
void CAN1_RX0_IRQHandler(void)
{

  HAL_CAN_IRQHandler(&hcan1); //Maneja la solicitud de interrupción CAN
  /* USER CODE BEGIN CAN1_RX0_IRQn 1 */
  HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &pRxHeader, &r);

  //use output data register to turn on LEDs
  switch(a)
   	{
   	case 1 :
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET);
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
   		break;
   	case 2 :
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
   		break;
   	case 3 :
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_RESET);
   		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
   		break;
   	}
}

