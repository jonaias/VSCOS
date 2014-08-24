/*
 * Copyright (c) 2014 Spectra Tecnologia
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MULTITASK_H
#define __MULTITASK_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


#define TIMER_FREQUENCY_HZ (1000u)

/* Exported types ------------------------------------------------------------*/
volatile uint64_t sysTickTimer;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define MAX_VIRTUAL_TIMERS 20


/* Exported functions ------------------------------------------------------- */
void initMultiTask();

void executeEveryInterval(uint8_t timerIndex, uint32_t intervalInMs, void (*functionToExecute)(void));
void enableFunction(uint8_t timerIndex, uint8_t enable);

uint32_t getMaxExecutionTime(uint8_t timerIndex);
void delayMsUsingSysTick(uint32_t delayMs);
bool achievedTimeout(uint32_t startTimeInMs, uint32_t timeoutInMs);


/* SysTick interrupt handles */
void SysTick_Handler(void);


#endif /* __MULTITASK_H */
