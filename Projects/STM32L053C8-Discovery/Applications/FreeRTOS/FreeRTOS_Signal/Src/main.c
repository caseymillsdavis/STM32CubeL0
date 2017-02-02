/**
  ******************************************************************************
  * @file    FreeRTOS/FreeRTOS_Signal/Src/main.c
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
   #define BIT_0	( 1 << 0 )
   #define BIT_1	( 1 << 1 )
   #define BIT_2	( 1 << 2 )
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
osThreadId LED3_ThreadId, LED4_ThreadId;

/* Private function prototypes -----------------------------------------------*/
static void Signal_Gen_Thread(void const *argument);

static void LED_Thread1(void const *argument);
static void LED_Thread2(void const *argument);
static void SystemClock_Config(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* STM32L0xx HAL library initialization:
       - Configure the Flash prefetch, Flash preread and Buffer caches
       - Systick timer is configured by default as source of time base, but user 
             can eventually implement his proper time base source (a general purpose 
             timer for example or other time source), keeping in mind that Time base 
             duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
             handled in milliseconds basis.
       - Low Level Initialization
     */
  HAL_Init();  
  
  /* Configure the System clock to 2 MHz */
  SystemClock_Config();
  
  /* Initialize LEDs */
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);

  /* Thread 1 definition */
  osThreadDef(LED3, LED_Thread1, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);

  /* Thread 2 definition */
  osThreadDef(LED4, LED_Thread2, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);

  /* Thread 3 definition */
  osThreadDef(SIGNAL_GEN, Signal_Gen_Thread, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);

  /* Start thread 1 */
  LED3_ThreadId = osThreadCreate(osThread(LED3), NULL);

  /* Start thread 2 */
  LED4_ThreadId = osThreadCreate(osThread(LED4), NULL);

  /* Start thread 3 */
  osThreadCreate(osThread(SIGNAL_GEN), NULL);
  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */
  for(;;);
}

/**
  * @brief  Thread (LED_Thread1) used to toggle a LED when getting the appropriate signal.
  * @param  Thread not used
  * @retval None
  */
static void LED_Thread1(void const *argument)
{
  (void) argument;
  osEvent event;
  
  for(;;)
  {
    event = osSignalWait( BIT_0, osWaitForever);
    if(event.value.signals == BIT_0)
    {
      BSP_LED_Toggle(LED3);
    }
  }
}

/**
  * @brief  Thread (LED_Thread2) used to toggle a LED when getting the appropriate signal.
  * @param  argument not used
  * @retval None
  */
static void LED_Thread2(void const *argument)
{
  (void) argument;
  osEvent event;
  
  for(;;)
  {
    event = osSignalWait( BIT_1 | BIT_2, osWaitForever);
    if(event.value.signals == (BIT_1 | BIT_2))
    {
     BSP_LED_Toggle(LED4);
    }
  }
}

/**
  * @brief  Signal generator thread
  * @param  Thread not used
  * @retval None
  */
static void Signal_Gen_Thread(void const *argument)
{
  (void) argument;
  
  for(;;)
  {
    osSignalSet( LED3_ThreadId, BIT_0 );
    osDelay(500);
    osSignalSet( LED4_ThreadId, BIT_1 | BIT_2 );
    osDelay(500);
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = MSI
  *            SYSCLK(Hz)                     = 2000000
  *            HCLK(Hz)                       = 2000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            Flash Latency(WS)              = 0
  *            Main regulator output voltage  = Scale3 mode
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  
  /* Enable MSI Oscillator */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.MSICalibrationValue=0x00;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
  
  /* Select MSI as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0)!= HAL_OK)
  {
    /* Initialization Error */
    while(1); 
  }
  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  
  /* Disable Power Control clock */
  __HAL_RCC_PWR_CLK_DISABLE();
  
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
