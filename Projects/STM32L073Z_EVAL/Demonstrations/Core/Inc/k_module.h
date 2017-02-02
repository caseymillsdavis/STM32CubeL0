/**
  ******************************************************************************
  * @file    k_module.h
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016
  * @brief   Header for k_module.c file
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __K_MODULE_H
#define __K_MODULE_H

#ifdef __cplusplus
 extern "C" {
#endif

#undef GLOBAL
#ifndef KMODULE_C
#define GLOBAL extern
#else
#define GLOBAL
#endif   
   
/* Includes ------------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
typedef enum {
  KMODULE_OK, 
  /* Module exec */
  KMODULE_ERROR_PRE,
  KMODULE_ERROR_EXEC,
  KMODULE_ERROR_POST,
  KMODULE_ERROR_ICON,
  KMODULE_RESMISSIG
} KMODULE_RETURN;

/* Exported types ------------------------------------------------------------*/
typedef struct
{
 uint8_t     kModuleId;
 KMODULE_RETURN (*kModulePreExec)(void);  
 KMODULE_RETURN (*kModuleExec)(void);
 KMODULE_RETURN (*kModulePostExec)(void);
 KMODULE_RETURN (*kModuleRessouceCheck)(void);
} K_ModuleItem_Typedef;

/* Exported macros -----------------------------------------------------------*/
/* Exported variable ---------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
GLOBAL void kModule_Init(void);
GLOBAL void kModule_Add(uint8_t kModuleId, K_ModuleItem_Typedef kModuleInfo);
GLOBAL KMODULE_RETURN kModule_CheckRessource(void);
GLOBAL KMODULE_RETURN kModule_Execute(uint8_t kModuleId);

#ifdef __cplusplus
}
#endif

#endif /*__K_MODULE_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
