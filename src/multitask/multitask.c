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


#include "multitask.h"

static uint64_t virtualTimer[MAX_VIRTUAL_TIMERS]=
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint8_t functionEnabled[MAX_VIRTUAL_TIMERS]=
				{true,true,true,true,true,true,true,true,true,true,
				 true,true,true,true,true,true,true,true,true,true};

static uint32_t maxExecutionTimes[MAX_VIRTUAL_TIMERS];

/* 2^64ms = 5.84555e8 years. Enough =)
 * 1ms/count
 *  */
volatile uint64_t sysTickTimer=0;

void initMultiTask(){
	printf("[MultiTask]Starting Setup\n");
	/* Set SysTick to 1ms */
	HAL_SYSTICK_Config(SystemCoreClock / TIMER_FREQUENCY_HZ);

	/* Use only preemption priority (do not use sub priority) */
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	/* Set SysTick to highest priority */
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
	printf("[MultiTask]Starting Setup\n");
}


/* CAUTION: IT ASSUMES SYSTICK CONFIGURED TO 1 ms */
void executeEveryInterval(uint8_t timerIndex, uint32_t intervalInMs, void (*functionToExecute)(void)){
	if ( timerIndex >= MAX_VIRTUAL_TIMERS){
		printf("[APP]Virtual timers out of bound\n");
		return;
	}

	if(((sysTickTimer - virtualTimer[timerIndex]) >= intervalInMs) && (functionEnabled[timerIndex])){
		int s,e,total;
		s=sysTickTimer;
		functionToExecute();
		e=sysTickTimer;
		total=e-s;
		if(total>maxExecutionTimes[timerIndex]){
			maxExecutionTimes[timerIndex]=total;
		}
		virtualTimer[timerIndex] = sysTickTimer;
	}
}

void enableFunction(uint8_t timerIndex, uint8_t enable){
	functionEnabled[timerIndex] = enable;
}

uint32_t getMaxExecutionTime(uint8_t timerIndex){
	return maxExecutionTimes[timerIndex];
}


void delayMsUsingSysTick(uint32_t delayMs){
		uint64_t startTimeInMs=sysTickTimer;
		while(sysTickTimer-startTimeInMs<delayMs);
}

inline bool achievedTimeout(uint32_t startTimeInMs, uint32_t timeoutInMs){
	return (sysTickTimer-startTimeInMs>timeoutInMs);
}

/**
 * @brief  This function is the SysTick Handler.
 * @param  None
 * @retval None
 */
void SysTick_Handler(void){
	sysTickTimer++;
}
