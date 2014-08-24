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

#include "gpios.h"

void initStatusLeds(void);

void initGPIOs(void){
	printf("[IOs]Starting Setup\n");

	initStatusLeds();

	printf("[IOs]Setup complete\n");
}

void initStatusLeds(void){
	  GPIO_InitTypeDef  GPIO_InitStruct;

	  /* Enable the GPIO_LEDS Clock */
	  LEDS_GPIO_CLK_ENABLE();

	  /* Configure the GPIO_LED pin */
	  GPIO_InitStruct.Pin = LED3_PIN | LED4_PIN | LED5_PIN | LED6_PIN;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	  HAL_GPIO_Init(LEDS_GPIO_PORT, &GPIO_InitStruct);

	  HAL_GPIO_WritePin(LEDS_GPIO_PORT, LED3_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LEDS_GPIO_PORT, LED4_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LEDS_GPIO_PORT, LED5_PIN, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LEDS_GPIO_PORT, LED6_PIN, GPIO_PIN_RESET);

}



void toggleLED3(void){
	HAL_GPIO_TogglePin(LEDS_GPIO_PORT,LED3_PIN);
}

void toggleLED4(void){
	HAL_GPIO_TogglePin(LEDS_GPIO_PORT,LED4_PIN);
}

void toggleLED5(void){
	HAL_GPIO_TogglePin(LEDS_GPIO_PORT,LED5_PIN);
}

void toggleLED6(void){
	HAL_GPIO_TogglePin(LEDS_GPIO_PORT,LED6_PIN);
}
