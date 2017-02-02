/**
  ******************************************************************************
  * @file    k_storage.h
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    31-May-2016
  * @brief   Header for k_storage.c file
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
#ifndef __K_STORAGE_H
#define __K_STORAGE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
typedef enum {
  KSTORAGE_NOERROR,
  KSTORAGE_ERROR_LINK,
  KSTORAGE_ERROR_MOUNT,
  KSTORAGE_ERROR_OPEN,
  KSTORAGE_ERROR_READ,
  KSTORAGE_ERROR_WRITE,
  KSTORAGE_ERROR_CLOSE,
  KSTORAGE_FIND_DIRDOESNTEXSIT,
  KSTORAGE_FIND_NOFILE,
  KSTORAGE_FIND_NOPREV,
  KSTORAGE_ERROR_MALLOC
} STORAGE_RETURN;

enum {
  KSTORAGE_FINDFIRST,
  KSTORAGE_FINDNEXT,
  KSTORAGE_FINDPREV,
  KSTORAGE_FINDCLOSE,
};
/* Exported functions ------------------------------------------------------- */
STORAGE_RETURN kStorage_Init(void);
STORAGE_RETURN kStorage_DeInit(void);
STORAGE_RETURN kStorage_OpenFileDrawBMP(uint16_t xpos, uint16_t ypos, uint8_t *BmpName);
STORAGE_RETURN kStorage_OpenFileDrawPixel(uint16_t xpos, uint16_t ypos, uint8_t *BmpName);
STORAGE_RETURN kStorage_FileExist(uint8_t *filename);
STORAGE_RETURN kStorage_GetFileInfo(uint8_t *filename,FILINFO* fileinfo);
STORAGE_RETURN kStorage_GetDirectoryFiles(const uint8_t *DirName, uint8_t action, uint8_t *FileName, uint8_t *FileExt);

uint8_t  kStorage_GetStatus (void);
void     kStorage_SdDetection(uint8_t status);
uint32_t kStorage_GetCapacity (void);
uint32_t kStorage_GetFree (void);

#ifdef __cplusplus
}
#endif

#endif /*__K_STORAGE_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
