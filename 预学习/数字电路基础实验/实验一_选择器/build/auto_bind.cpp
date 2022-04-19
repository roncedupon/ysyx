#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->s, BIND_RATE_SCR, BIND_DIR_IN , 2, SW0, SW1);
	nvboard_bind_pin( &top->x0, BIND_RATE_SCR, BIND_DIR_IN , 2, SW2, SW3);
	nvboard_bind_pin( &top->x1, BIND_RATE_SCR, BIND_DIR_IN , 2, SW4, SW5);
	nvboard_bind_pin( &top->x2, BIND_RATE_SCR, BIND_DIR_IN , 2, SW6, SW7);
	nvboard_bind_pin( &top->x3, BIND_RATE_SCR, BIND_DIR_IN , 2, SW8, SW9);
	nvboard_bind_pin( &top->y, BIND_RATE_SCR, BIND_DIR_OUT, 2, LD0, LD1);
}
