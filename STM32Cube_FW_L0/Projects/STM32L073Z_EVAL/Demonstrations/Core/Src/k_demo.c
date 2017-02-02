/**
  ******************************************************************************
  * @file    k_demo.c
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016   
  * @brief   This file provides the kernel demo functions 
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
#include "k_config.h"
#include "k_demo.h"
#include "k_module.h"
#include "k_menu.h"

/** @addtogroup CORE
  * @{
  */

/** @defgroup KERNEL_MENU
  * @brief Kernel menu routines
  * @{
  */


/* External variables --------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
typedef enum {
  DEMO_INIT,
  DEMO_RUN,
  DEMO_DEINIT,
  DEMO_EXIT
} kDEMO_STATE;

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* External functions --------------------------------------------------------*/

/**
  * @brief  function used to start a demo
  * @param  None
  * @retval None
  */
void kDemo_Start(void) 
{
  kDEMO_STATE  demo_stat =  DEMO_INIT;
  
  do {
    switch (demo_stat) 
    {
    case DEMO_INIT:
      kDemo_Initialization();
      demo_stat = DEMO_RUN;
      break;
    case DEMO_RUN :
      kMenu_Init();
      kModule_Execute(MODULE_MAIN_APP);
      demo_stat = DEMO_DEINIT;
      break;
    case DEMO_DEINIT :
      kDemo_UnInitialization();
      demo_stat = DEMO_EXIT;
      break;
    default:
      break;
    }
  }
  while(demo_stat != DEMO_EXIT);
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
