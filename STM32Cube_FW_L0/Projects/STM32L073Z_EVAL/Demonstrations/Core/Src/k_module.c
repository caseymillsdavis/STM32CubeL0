/**
  ******************************************************************************
  * @file    k_module.c
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016   
  * @brief   This file provides the kernel module functions 
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

#define KMODULE_C
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "main.h"
#include "k_config.h"
#include "k_module.h"

/** @addtogroup CORE
  * @{
  */

/** @defgroup KERNEL_MODULE
  * @brief Kernel module routines
  * @{
  */

/* External variables --------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static K_ModuleItem_Typedef    kmodule_info[MODULE_MAX];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Add module inside the module list 
  * @param  kModuleId:   module id
            kModuleInfo: module information 
  * @retval none
  */
void kModule_Add(uint8_t kModuleId, K_ModuleItem_Typedef kModuleInfo)
{
  kmodule_info[kModuleId] = kModuleInfo;
}

/**
  * @brief  Check if the ressouce associated to a module are present 
  * @param  kModuleId:   module id
            kModuleInfo: module information 
  * @retval none
  */
KMODULE_RETURN kModule_CheckRessource(void)
{
uint8_t index;

  for(index = 0; index <  MODULE_MAX; index++)
  {
    if(kmodule_info[index].kModuleRessouceCheck != NULL)
    {
      if(kmodule_info[index].kModuleRessouceCheck() != KMODULE_OK)
      {
        return KMODULE_RESMISSIG;
      }
    }
  }
  return KMODULE_OK;
}

/**
  * @brief  Execute a module
  * @param  moduleid : id of the module
  * @retval Execution status 
  */
KMODULE_RETURN kModule_Execute(uint8_t moduleid) 
{
  
  /* Module Preprocessing  */
  if(kmodule_info[moduleid].kModulePreExec != NULL)
  {
    if(kmodule_info[moduleid].kModulePreExec() != KMODULE_OK)
    {
      return KMODULE_ERROR_PRE;
    }
  }
  
  /* Module Execution      */
  if(kmodule_info[moduleid].kModuleExec != NULL)
  {
    if(kmodule_info[moduleid].kModuleExec() != KMODULE_OK)
    {
      return KMODULE_ERROR_EXEC;
    }
  }
  
  /* Module Postprocessing */
  if(kmodule_info[moduleid].kModulePostExec != NULL)
  {
    if(kmodule_info[moduleid].kModulePostExec() != KMODULE_OK)
    {
      return KMODULE_ERROR_POST;
    }
  }
  
  return KMODULE_OK;
}
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
