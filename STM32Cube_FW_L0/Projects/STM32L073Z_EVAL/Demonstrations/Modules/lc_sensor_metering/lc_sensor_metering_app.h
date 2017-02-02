/**
  ******************************************************************************
  * @file    lc_sensor_metering_app.h
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016   
  * @brief   System information functions
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

#undef GLOBAL
#ifdef MODULE_LC_SENSOR_METERING
#define GLOBAL
#else
#define GLOBAL extern
#endif



/* Includes ------------------------------------------------------------------*/

/** @addtogroup SYSTEM_INFO_MODULE
  * @{
  */

/** @defgroup LC_SENSOR_INFO
  * @brief system info routines 
  * @{
  */

/* external defines -----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define TIMx                         TIM6
#define TIMx_CLK_ENABLE              __TIM6_CLK_ENABLE

/* Definition for TIMx's NVIC */
#define TIMx_IRQn                    TIM6_DAC_IRQn
#define TIMx_IRQHandler              TIM6_DAC_IRQHandler

#define DACx                            DAC
#define DACx_CLK_ENABLE()               __DAC_CLK_ENABLE()
#define DACx_CHANNEL_GPIO_CLK_ENABLE()  __GPIOA_CLK_ENABLE()


/* External variables --------------------------------------------------------*/
GLOBAL const K_ModuleItem_Typedef LcSensorMeteringModuleItem;
/* Private function prototypes -----------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

