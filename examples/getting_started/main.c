/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 *  \page getting-started Getting Started with sama5d4x Microcontrollers
 *
 *  \section Purpose
 *
 *  The Getting Started example will help new users get familiar with Atmel's
 *  sama5d4x microcontroller. This basic application shows the startup
 *  sequence of a chip and how to use its core peripherals.
 *
 *  \section Requirements
 *
 *  This package can be used with SAMA5D4-EK and SAMA5D4-XULT.
 *
 *  \section Description
 *
 *  The demonstration program makes two LEDs on the board blink at a fixed rate.
 *  This rate is generated by using Time tick timer. The blinking can be stopped
 *  using two buttons (one for each LED). If there is no enough buttons on board, please
 *  type "1" or "2" in the terminal application on PC to control the LEDs
 *  instead.
 *
 *  \section Usage
 *
 *  -# Build the program and download it inside the evaluation board. Please
 *     refer to the
 *     <a href="http://www.atmel.com/dyn/resources/prod_documents/6421B.pdf">
 *     SAM-BA User Guide</a>, the
 *     <a href="http://www.atmel.com/dyn/resources/prod_documents/doc6310.pdf">
 *     GNU-Based Software Development</a>
 *     application note or to the
 *     <a href="ftp://ftp.iar.se/WWWfiles/arm/Guides/EWARM_UserGuide.ENU.pdf">
 *     IAR EWARM User Guide</a>,
 *     depending on your chosen solution.
 *  -# On the computer, open and configure a terminal application
 *     (e.g. HyperTerminal on Microsoft Windows) with these settings:
 *    - 115200 bauds
 *    - 8 bits of data
 *    - No parity
 *    - 1 stop bit
 *    - No flow control
 *  -# Start the application.
 *  -# Two LEDs should start blinking on the board. In the terminal window, the
 *     following text should appear (values depend on the board and chip used):
 *     \code
 *      -- Getting Started Example xxx --
 *      -- SAMxxxxx-xx
 *      -- Compiled: xxx xx xxxx xx:xx:xx --
 *     \endcode
 *  -# Pressing and release button 1 or type "1" in the terminal application on
 *     PC should make the first LED stop & restart blinking.
 *     Pressing and release button 2 or type "2" in the terminal application on
 *     PC should make the other LED stop & restart blinking.
 *
 *  \section References
 *  - getting-started/main.c
 *  - pio.h
 *  - pio_it.h
 *  - led.h
 *  - trace.h
 */

/** \file
 *
 *  This file contains all the specific code for the getting-started example.
 *
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "board.h"
#include "chip.h"
#include "trace.h"
#include "compiler.h"
#include "timer.h"

#include "peripherals/aic.h"
#include "peripherals/pio.h"
#include "peripherals/pmc.h"
#include "peripherals/tc.h"

#include "misc/console.h"
#include "misc/led.h"


#include <stdbool.h>
#include <stdio.h>

/*----------------------------------------------------------------------------
 *        Local definitions
 *----------------------------------------------------------------------------*/

/** Delay for pushbutton debouncing (in milliseconds). */
#define DEBOUNCE_TIME       500

/*----------------------------------------------------------------------------
 *        Local variables
 *----------------------------------------------------------------------------*/


#ifdef PINS_PUSHBUTTONS
/** Pushbutton \#1 pin instance. */
static const struct _pin button_pins[] = PINS_PUSHBUTTONS;
#endif

volatile bool led_status[NUM_LEDS];

/*----------------------------------------------------------------------------
 *        Local functions
 *----------------------------------------------------------------------------*/

/**
 *  \brief Process Buttons Events
 *
 *  Change active states of LEDs when corresponding button events happened.
 */
static void process_button_evt(uint8_t bt)
{
	if (bt >= NUM_LEDS) {
		return;
	}
	led_status[bt] = !led_status[bt];
	if (bt == 0) {
		if (!led_status[bt]) {
			led_clear(bt);
		}
	} else if (bt < NUM_LEDS) {
		if (led_status[bt]) {
			led_set(bt);
		} else {
			led_clear(bt);
		}
	}
}

#ifdef PINS_PUSHBUTTONS

/**
 *  \brief Handler for Buttons rising edge interrupt.
 *
 *  Handle process led1 status change.
 */
static void pio_handler(uint32_t group, uint32_t status, void* user_arg)
{
	int i;

	/* unused */
	(void)user_arg;

	for (i = 0; i < ARRAY_SIZE(button_pins); ++i) {
		if (group != button_pins[i].group)
			continue;
		if (status & button_pins[i].mask)
			process_button_evt(i);
	}
}

/**
 *  \brief Configure the Pushbuttons
 *
 *  Configure the PIO as inputs and generate corresponding interrupt when
 *  pressed or released.
 */
static void configure_buttons(void)
{
	/* Adjust debounce filter parameters, use 10 Hz filter */
	pio_set_debounce_filter(10);

	int i = 0;
	for (i = 0; i < ARRAY_SIZE(button_pins); ++i)
	{
		/* Configure PIO */
		pio_configure(&button_pins[i], 1);

		/* Initialize interrupt with its handlers */
		pio_add_handler_to_group(button_pins[i].group,
				      button_pins[i].mask, pio_handler, NULL);

		/* Enable interrupts */
		pio_enable_it(button_pins);
	}
}

#endif /* PINS_PUSHBUTTONS */

/**
 *  \brief Handler for DBGU input.
 *
 *  Handle process LED1 or LED2 status change.
 */
static void console_handler(uint8_t key)
{
	if (key >= '0' && key <= '9') {
		process_button_evt(key - '0');
	} else if (key == 's') {
		tc_stop(TC0, 0);
	} else if (key == 'b') {
		tc_start(TC0, 0);
	}
}

/**
 *  Interrupt handler for TC0 interrupt. Toggles the state of LED\#2.
 */
static void tc_handler(void)
{
	uint32_t status, i;

	/* Get status to acknowledge interrupt */
	status = tc_get_status(TC0, 0);

	if (status & TC_SR_CPCS) {
		/** Toggle LEDs state. */
		for (i = 1; i < NUM_LEDS; ++i) {
			if (led_status[i]) {
				led_toggle(i);
				printf("%i ", (unsigned int)i);
			}
		}
	}
}

/**
 *  Configure Timer Counter 0 to generate an interrupt every 250ms.
 */
static void configure_tc(void)
{
	/** Enable peripheral clock. */
	pmc_enable_peripheral(ID_TC0);

	/* Put the source vector */
	aic_set_source_vector(ID_TC0, tc_handler);

	/** Configure TC for a 4Hz frequency and trigger on RC compare. */
	tc_trigger_on_freq(TC0, 0, 4);

	/* Configure and enable interrupt on RC compare */
	aic_enable(ID_TC0);
	tc_enable_it(TC0, 0, TC_IER_CPCS);

	/* Start the counter if LED1 is enabled. */
	if (led_status[1]) {
		tc_start(TC0, 0);
	}
}

/*----------------------------------------------------------------------------
 *        Global functions
 *----------------------------------------------------------------------------*/

/**
 *  \brief getting-started Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
int main(void)
{
	int i = 0;

	led_status[0] = true;
	for (i = 1; i < NUM_LEDS; ++i) {
		led_status[i] = led_status[i-1];
	}

	console_example_info("Getting Started Example");

	printf("Initializing console interrupts\r\n");
	console_set_rx_handler(console_handler);
	console_enable_rx_interrupt();

#ifdef PINS_PUSHBUTTONS
	printf("Configure buttons with debouncing.\n\r");
	configure_buttons();
	printf("Use push buttons or console key 0 to 9.\n\r");
#else
	printf("Use console key 0 to 9.\n\r");
#endif /* PINS_PUSHBUTTONS */

	printf("Press the number of the led to make it "
	       "start or stop blinking.\n\r");
	printf("Press 's' to stop the TC and 'b' to start it\r\n");

	/* Configure TC */
	printf("Configure TC.\n\r");
	configure_tc();

	while (1) {

		/* Wait for LED to be active */
		while (!led_status[0]);

		/* Toggle LED state if active */
		if (led_status[0]) {
			led_toggle(0);
			printf("0 ");
		}

		/* Wait for 250ms (4Hz) */
		timer_wait(250);
	}
}
