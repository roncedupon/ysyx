#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->in, BIND_RATE_SCR, BIND_DIR_IN , 8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->en, BIND_RATE_SCR, BIND_DIR_IN , 1, SW8);
	nvboard_bind_pin( &top->en_led, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD3);
	nvboard_bind_pin( &top->out, BIND_RATE_SCR, BIND_DIR_OUT, 3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->SEG, BIND_RATE_SCR, BIND_DIR_OUT, 7, SEG1G, SEG1F, SEG1E, SEG1D, SEG1C, SEG1B, SEG1A);
}
