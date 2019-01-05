/*

Copyright 2011-2018 Stratify Labs, Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	 http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/


#include <mcu/types.h>
#include <mcu/core.h>
#include <mcu/bootloader.h>
#include <mcu/arch.h>

#include "boot_link_config.h"

const struct __sFILE_fake __sf_fake_stdin;
const struct __sFILE_fake __sf_fake_stdout;
const struct __sFILE_fake __sf_fake_stderr;

extern void sos_led_root_enable(void*);

#include "../src/config.h"
//Bootloader configuration (don't need Stratify OS configuration for just the bootloader)
STM32_NUCLEO144_DECLARE_BOOT_BOARD_CONFIG(&link_transport);

extern void SystemClock_Config();
extern void boot_main();

//Execute the Stratify OS default bootloader
void _main(){ boot_main(); }

void board_event_handler(int event, void * args){
	switch(event){

		case BOOT_EVENT_START:
			break;

		case BOOT_EVENT_CHECK_APP_EXISTS:
			break;

		case BOOT_EVENT_CHECK_SOFTWARE_BOOT_REQUEST:
			break;

		case BOOT_EVENT_CHECK_HARDWARE_BOOT_REQUEST:
			break;

		case BOOT_EVENT_RUN_APP:

			break;

		case BOOT_EVENT_RUN_BOOTLOADER:
			break;

		case BOOT_EVENT_INIT_CLOCK:
			break;

		case MCU_BOARD_CONFIG_EVENT_ROOT_INITIALIZE_CLOCK:
			SystemClock_Config();
			break;
	}
}
