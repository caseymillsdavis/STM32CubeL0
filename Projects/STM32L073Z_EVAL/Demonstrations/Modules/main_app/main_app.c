/**
  ******************************************************************************
  * @file    main_app.c
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

/* Includes ------------------------------------------------------------------*/
#include "k_config.h"
#include "k_module.h"
#include "k_menu.h"
#include "k_storage.h"

/* Private function prototypes -----------------------------------------------*/
KMODULE_RETURN AppMainExec(void);
KMODULE_RETURN AppMainExecCheckRessource(void);


/* Defines  ----------------------------------------------------------*/
#define C_PATH_LOGO_UART            "STFILES/Uart.bmp"
#define C_PATH_LOGO_POWER           "STFILES/Power.bmp"
#define C_PATH_LOGO_THERMOMETER     "STFILES/Temp.bmp"
#define C_PATH_LOGO_LC_SENSOR       "STFILES/LCsensor.bmp"
#define C_PATH_LOGO_PRESSURE        "STFILES/Pressure.bmp"
#define C_PATH_LOGO_HELP            "STFILES/Help.bmp"

/* Private Variable ----------------------------------------------------------*/
__IO uint8_t exit_func;


const tMenuItem MainMenuItems[] =
{
    {"LPUART Wakeup"        ,32,60,  SEL_MODULE,MODULE_LPUART_WAKEUP, NULL, NULL, NULL,C_PATH_LOGO_UART },
    {"Low Power"            ,128,60, SEL_MODULE,MODULE_LOW_POWER, NULL, NULL, NULL,C_PATH_LOGO_POWER },
    {"Thermometer"          ,224,60, SEL_MODULE,MODULE_TSENSOR, NULL, NULL, NULL,C_PATH_LOGO_THERMOMETER },
    {"LC sensor metering"   ,32,144, SEL_MODULE,MODULE_LC_SENSOR_METERING, NULL, NULL, NULL,C_PATH_LOGO_LC_SENSOR },
    {"Pressure"             ,128,144,SEL_MODULE,MODULE_PRESSURE_MEASUREMENT, NULL, NULL, NULL,C_PATH_LOGO_PRESSURE },
    {"Help"                ,224,144,SEL_MODULE,MODULE_SYSTEM_INFO, NULL, NULL, NULL,C_PATH_LOGO_HELP}
};

const tMenu MainMenu = {
  "Main menu", MainMenuItems, countof(MainMenuItems), TYPE_ICON, 2, 3
  };


    

/* Private typedef -----------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
const K_ModuleItem_Typedef ModuleAppMain =
{
  MODULE_MAIN_APP,
  NULL,
  AppMainExec,
  NULL,
  AppMainExecCheckRessource
};  

/**
  * @brief  Run the main application 
  * @param  None.
  * @note   run and display main menu.  
  * @retval None.
  */
KMODULE_RETURN AppMainExec(void)
{
  kMenu_Execute(MainMenu);
  return KMODULE_OK;
}

/**
  * @brief  check the main application ressources 
  * @param  None.
  * @note   None.  
  * @retval None.
  */
KMODULE_RETURN AppMainExecCheckRessource(void)
{
 uint8_t index; 
 
  /* check icon menu */
  for(index = 0; index <  countof(MainMenuItems); index++)
  {
    if(kStorage_FileExist((uint8_t *)MainMenuItems[index].pIconPath) != KSTORAGE_NOERROR)
    {
      return KMODULE_ERROR_ICON;
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

