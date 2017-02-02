/**
  @page PWR_LPSLEEP Low Power sleep Mode Example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    PWR/PWR_LPSLEEP/readme.txt
  * @author  MCD Application Team
  * @version V1.8.0
  * @date    25-November-2016
  * @brief   Description of the Low Power Sleep Mode example.
  ******************************************************************************
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

This example shows how to enters the system to Low Power Sleep mode and wake-up 
from this mode using Key push button EXTI Line 0.
This example shows also how to configure the STM32L0xx system to measure 
LP SLEEP mode current consumption.

The Low power sleep mode is entered by configuring the voltage regulator in low power
mode, and by executing the WFI (wait for interrupt) or WFE (wait for event) instructions. In
this mode, the Flash memory is not available but the RAM memory remains available.

In this example, the WFI instruction is used to enter Low power sleep mode, any 
peripheral interrupt acknowledged by the nested vectored interrupt controller (NVIC) 
can wake up the device from Low power sleep mode.

In the associated software
  - the system clock is set to 32 KHz.
  - the EXTI_Line0 is configured to generate an interrupt on falling edge.

 @note In Low power sleep mode, the system frequency should not exceed MSI range1.
 @note Low power sleep mode can only be entered when VCORE is in range 2. 

The system enters LP SLEEP mode by pressing the User push button and will wait 
for the same button to be pressed to wake up from LP SLEEP mode. Current consumption 
could be monitored through an ampermeter.

This behavior is repeated in an infinite loop.
 - LED3 ON: HAL configuration failed (system will go to an infinite loop)
 
    - Low Power Sleep Mode
    =======================
          - Regulator in LP mode
          - System Running at MSI (~32KHz)
          - Flash 0 wait state  
          - Voltage Range 2
          - Code running from Internal FLASH
          - All peripherals OFF
          - VDD from 1.65V to 3.6V
          - Wakeup using EXTI Line (Key Button PA.00)     

 @note This example can not be used in DEBUG mode, this is due to the fact 
       that the Cortex-M0+ core is no longer clocked during low power mode 
       so debugging features are disbaled


@par Directory contents  

  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_conf.h     Library Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32l0xx_it.h       Header for stm32l0xx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h               header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32l0xx.c   STM32L0xx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_it.c       Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/main.c               Main program
  - PWR/PWR_LPSLEEP/Src/stm32l0xx_hal_msp.c  HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32L053xx devices.
    
  - This example has been tested with STM32L0538-DISCO REVB board and can be
    easily tailored to any other supported device and development board.

  - STM32L0538-DISCO Set-up
    - Use LED3 connected to PB.04 pin
    - Use the Key push-button connected to pin PA.00 (EXTI_Line0)
    - Put the JP4 to position 2-3, then measure the IDD current
      between the JP4 position 1-2.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
