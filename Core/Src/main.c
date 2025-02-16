/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "app_subghz_phy.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32_timer.h"
#include "sys_app.h"
#include "stm32_seq.h"
#include "utilities_def.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static UTIL_TIMER_Object_t I2Csender;
static UTIL_TIMER_Object_t I2Creciever;
uint8_t RecievedData[6];
uint8_t SendedData[2] = {0x24,0x00}; // Data to SHT30: 0x24 no clock stretching, 0x00 - Repeatability high

uint16_t I2Ctransmitperiod = 1000;
uint16_t I2Crecieveperiod= 15;
uint8_t RecievedData[6];
uint16_t RecievedCtr,TransmitCtr;
uint8_t Flags;
UTIL_SEQ_bm_t I2CSendHandler=0;
UTIL_SEQ_bm_t I2CRecieveHandler=1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

//Received all data, print it in log
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{

	uint8_t i;
	char BuffCharSended[4];

	RecievedCtr++; //interrup counter only for debug
	  for(i=0; i < 6; i++)
	  {
		  itoa(RecievedData[i],BuffCharSended,10);
		  APP_LOG(TS_OFF, VLEVEL_L,  " %s \n\r", BuffCharSended);
	  }
}
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	//if command sended start counting down to launch receiver task
	TransmitCtr++;//interrup counter only for debug
	UTIL_TIMER_Start(&I2Creciever);
}

//This taks send periodically command to SHT30 by I2C
void SendI2C(void)
{
	// Send Data to SHT30 with interrupts
	HAL_I2C_Master_Transmit_IT(&hi2c2,  0x45<<1, SendedData, 2);

}
void RecieveI2C(void)
{
	// send request for new data
	HAL_I2C_Master_Receive_IT(&hi2c2,  0x45<<1, RecievedData, 6);

}
void SendI2CTimer(void)
{
	Flags=1;
	//trigger sender task
	  UTIL_SEQ_SetTask(1<<I2C_sender, I2C_senderPrio1);
}
void RecieveI2CTimer(void)
{
	//trigger reciever task
	UTIL_SEQ_SetTask(1<<I2C_reciever, I2C_recieverPrio2);
	Flags=2;
	//UTIL_SEQ_SetTask(1<<I2CRecieveHandler, 0);
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SubGHz_Phy_Init();
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
  UTIL_SEQ_Init();

  // create periodic timmer wich will triger Sending command to SHT30 by I2C
  UTIL_TIMER_Create(&I2Csender, 0xFFFFFFFFU, UTIL_TIMER_PERIODIC, SendI2CTimer, NULL);
  UTIL_TIMER_SetPeriod(&I2Csender, I2Ctransmitperiod);
  UTIL_TIMER_Start(&I2Csender);


  //create task wich will wait for process recieved command by SHT30 from STM32 and ask for data
  UTIL_TIMER_Create(&I2Creciever, 0xFFFFFFFFU, UTIL_TIMER_ONESHOT, RecieveI2CTimer, NULL);
  UTIL_TIMER_SetPeriod(&I2Creciever, I2Crecieveperiod);

  // Register tasks
  UTIL_SEQ_RegTask(1<<I2C_sender, 0, SendI2C);
  UTIL_SEQ_RegTask(1<<I2C_reciever,0,RecieveI2C);
  /* USER CODE END 2 */


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */
    MX_SubGHz_Phy_Process();

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3|RCC_CLOCKTYPE_HCLK
                              |RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
