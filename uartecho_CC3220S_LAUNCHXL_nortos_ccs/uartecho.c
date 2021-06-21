/*
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== uartecho.c ========
 */
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>

/* Driver configuration */
#include "ti_drivers_config.h"

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    char        input;
    const char  echoPrompt[] = "Echoing characters:\r\n";
    UART_Handle uart;
    UART_Params uartParams;

    /* Call driver init functions */
    GPIO_init();
    UART_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.baudRate = 115200;

    uart = UART_open(CONFIG_UART_0, &uartParams);

    if (uart == NULL) {
        /* UART_open() failed */
        while (1);
    }

    /* Turn on user LED to indicate successful initialization */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);

    UART_write(uart, echoPrompt, sizeof(echoPrompt));


    /* Loop forever echoing */
    while (1) {

        UART_read(uart, &input, 1);


        // State Machine
        enum TL_States { TL_SMStart, TL_LedOff, TL_LedOn, TL_O, TL_N, TL_F } TL_State;

        switch (TL_State) {
            case TL_SMStart:        // Initialize to LED being on
                TL_State = TL_LedOn;
                break;

            case TL_O:              // If character is O find what current char is by if/else statement then set state
                if (input == 'N') {
                    TL_State = TL_N;
                }
                else if (input == 'F') {
                    TL_State = TL_F;
                }
                break;

            case TL_LedOn:          // If state is TL_LedOn, turn on LED
                TL_State = TL_LedOn;
                GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
                break;

            case TL_LedOff:         // If state is TL_LedOff, turn off LED
                TL_State = TL_LedOff;
                GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
                break;
        }

        switch (TL_State) {
            case TL_LedOn:          // If LED state is TL_LedOn find what current char is by if/else statement then set state
                if (input == 'O') {
                    TL_State = TL_O;
                }
                else if (input == 'N') {
                    TL_State = TL_N;
                }
                else if (input == 'F') {
                    TL_State = TL_F;
                }
                break;

            case TL_N:              // If LED state is TL_N change state to TL_LedOn and turn on LED
                if (input == 'N') {
                    TL_State = TL_LedOn;
                    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
                    break;
                }

            case TL_F:              // If LED state is TL_F change state to TL_LedOff and turn off LED
                if (input == 'F') {
                    TL_State = TL_LedOff;
                    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
                    break;
                }

            case TL_LedOff:         // If LED state is TL_LedOff find what current char is by if/else statement then set state
                if (input == 'O') {
                    TL_State = TL_O;
                }
                else if (input == 'N') {
                    TL_State = TL_N;
                }
                else if (input == 'F') {
                    TL_State = TL_F;
                }
                break;

        }

        UART_write(uart, &input, 1);
    }
}
