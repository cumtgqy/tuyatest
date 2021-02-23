/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
#include "multi_button.h"
uint8_t keyLongPress = 0;
struct Button btn1;
uint8_t read_btn1_gpio(void);
void btn1_callback(void *btn);

struct Button btn2;
uint8_t read_btn2_gpio(void);
void btn2_callback(void *btn);
#define KEY0_DOWN_LEVEL               0  /* 根据原理图设计，KEY0按下时引脚为低电平，所以这里设置为0 */
#define KEY1_DOWN_LEVEL               0  /* 根据原理图设计，KEY0按下时引脚为低电平，所以这里设置为0 */
#define KEY2_DOWN_LEVEL               0  /* 根据原理图设计，KEY0按下时引脚为低电平，所以这里设置为0 */
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|LED3_Pin|DHT11_CLK_Pin
                          |RL1_Pin|RL2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|RL1_Pin
                          |RL2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = KEY1_Pin|KEY2_Pin|KEY3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DHT11_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(DHT11_CLK_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void KeyRegister(void)
{
	button_init(&btn1, read_btn1_gpio, 	KEY1_DOWN_LEVEL);
	button_attach(&btn1, SINGLE_CLICK,     btn1_callback);
	button_attach(&btn1, DOUBLE_CLICK,     btn1_callback);
	button_attach(&btn1, LONG_PRESS_START, btn1_callback);
	button_start(&btn1);

	button_init(&btn2, read_btn2_gpio, 	KEY2_DOWN_LEVEL);
	button_attach(&btn2, SINGLE_CLICK,     btn2_callback);
	button_attach(&btn2, DOUBLE_CLICK,     btn2_callback);
	button_attach(&btn2, LONG_PRESS_START, btn2_callback);
	button_start(&btn2);
}

uint8_t read_btn1_gpio(void)
{
	return HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
}

void btn1_callback(void *btn)
{
	switch(get_button_event((struct Button*)btn))
	{
		case SINGLE_CLICK:
			printf("KEY1 SINGLE_CLICK! \r\n");
			break;
		case DOUBLE_CLICK:
			printf("KEY1 DOUBLE_CLICK! \r\n");
			break;
		case LONG_PRESS_START:
			keyLongPress = 1;
//			printf("KEY1 LONG_PRESS_START! \r\n");
			break;
		default:
			break;
		
	}
}	


uint8_t read_btn2_gpio(void)
{
	return HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin);
}

void btn2_callback(void *btn)
{
	switch(get_button_event((struct Button*)btn))
	{
		case SINGLE_CLICK:
			printf("KEY2 SINGLE_CLICK! \r\n");
			break;
		case DOUBLE_CLICK:
			printf("KEY2 DOUBLE_CLICK! \r\n");
			break;
		case LONG_PRESS_START:
			printf("KEY2 LONG_PRESS_START! \r\n");
			break;
		default:
			break;
	}
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
