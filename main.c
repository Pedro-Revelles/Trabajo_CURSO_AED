
#include <stdint.h>
#include "REGISTERS_IO.h"
#include "peripherals_configuration.h"

int main(void)
{
	output_led();
	input_botton();
    /* Loop forever */
	for(;;);
}
