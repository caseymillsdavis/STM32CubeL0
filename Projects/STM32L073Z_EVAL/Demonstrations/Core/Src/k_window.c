/**
  ******************************************************************************
  * @file    k_window.c
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016   
  * @brief   This file contains the Hex dumps of the images available
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
#define  _K_WINDOW_C
/* Includes ------------------------------------------------------------------*/
#include <k_config.h>
#include <k_window.h>

static void kWindow_PopupGeneric(char *title, uint16_t title_tc, 
                                 uint16_t title_bc ,char *Msg, 
                                 uint16_t msg_tc, uint16_t msg_bc,
                                 Line_ModeTypdef mode) ;

/** @addtogroup CORE
  * @{
  */

/** @defgroup KERNEL_RES
  * @brief Kernel resources 
  * @{
  */


/* External variables --------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions ---------------------------------------------------------*/

/**
  * @brief  Handle a window display with message centered.
  * @param  title to display a message, \n is used for multiple line.
  * @param  title_tc : title text color.
  * @param  title_bc : title backgroun color.
  * @param  Msg to display a message, \n is used for multiple line.
  * @param  msg_tc : title text color.
  * @param  msg_bc : title backgroun color.
  * @retval None
  */
void kWindow_PopupCentered(char *title, uint16_t title_tc, uint16_t title_bc ,char *Msg, uint16_t msg_tc, uint16_t msg_bc )
{
   kWindow_PopupGeneric(title,title_tc,title_bc ,Msg,msg_tc,msg_bc,CENTER_MODE);
}

/**
  * @brief  Handle a window display with message left aligned.
  * @param  title to display a message, \n is used for multiple line.
  * @param  title_tc : title text color.
  * @param  title_bc : title backgroun color.
  * @param  Msg to display a message, \n is used for multiple line.
  * @param  msg_tc : title text color.
  * @param  msg_bc : title backgroun color.
  * @retval None
  */
void kWindow_PopupAligned(char *title, uint16_t title_tc, uint16_t title_bc ,char *Msg, uint16_t msg_tc, uint16_t msg_bc )
{
  kWindow_PopupGeneric(title,title_tc,title_bc ,Msg,msg_tc,msg_bc,LEFT_MODE);

}

/**
  * @brief  Handle a generic window display.
  * @param  title to display a message, \n is used for multiple line.
  * @param  title_tc : title text color.
  * @param  title_bc : title backgroun color.
  * @param  Msg to display a message, \n is used for multiple line.
  * @param  msg_tc : title text color.
  * @param  msg_bc : title backgroun color.
  * @retval None
  */
static void kWindow_PopupGeneric(char *title, uint16_t title_tc, uint16_t title_bc ,char *Msg, uint16_t msg_tc, uint16_t msg_bc,Line_ModeTypdef mode )
{
  uint8_t substring[25];
  uint8_t lineindex;
  uint16_t index,subindex;

  /* Clear the LCD Screen */
  BSP_LCD_Clear(title_bc);
  BSP_LCD_SetBackColor(title_bc);
  BSP_LCD_SetTextColor(title_tc);

  /* Set the Back Color */
  BSP_LCD_SetFont(&Font24);
  BSP_LCD_SetTextColor(title_tc);
  BSP_LCD_DisplayStringAt(0, 0, (uint8_t *)title, mode);

  /* Prepare the msg area */
  BSP_LCD_SetBackColor(msg_bc);
  BSP_LCD_SetTextColor(msg_bc);
  BSP_LCD_FillRect(0, Font24.Height, BSP_LCD_GetXSize(), BSP_LCD_GetYSize() - Font24.Height);
  BSP_LCD_SetTextColor(msg_tc);

  lineindex = subindex = index = 0;
  do
  {
    substring[subindex]=Msg[index];
    if((Msg[index] == '\n') || (Msg[subindex] == '\0'))
    {
      substring[subindex] = '\0';
      BSP_LCD_DisplayStringAt(0, (2+lineindex) * Font24.Height, substring, mode);
      lineindex++;
      subindex = 0;
    }
    else
    {
      subindex++;
    }

    if(Msg[index] != '\0')
    {
      index++;
    }
  }
  while(Msg[index] != '\0');

}

/**
  * @brief  Handle a window display.
  * @param  Msg to display a message, \n is used for multiple line.
  * @retval None
  */
void kWindow_Error(char *msg)
{
  kWindow_PopupGeneric("Error popup",LCD_COLOR_BLACK,LCD_COLOR_RED,msg,LCD_COLOR_BLACK,LCD_COLOR_RED,CENTER_MODE);
}

/**
  * @}
  */

/**
  * @}
  */
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
