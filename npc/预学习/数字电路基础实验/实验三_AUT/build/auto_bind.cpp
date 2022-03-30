#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->signed_A, BIND_RATE_SCR, BIND_DIR_IN , 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->signed_B, BIND_RATE_SCR, BIND_DIR_IN , 4, SW7, SW6, SW5, SW4);
	nvboard_bind_pin( &top->function_chosing, BIND_RATE_SCR, BIND_DIR_IN , 3, SW8, SW9, SW10);
	nvboard_bind_pin( &top->out_led, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD0);
	nvboard_bind_pin( &top->out_result, BIND_RATE_SCR, BIND_DIR_OUT, 4, LD4, LD3, LD2, LD1);
}
