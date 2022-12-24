#include "header.h"

/* definition/initiering av enable variabel, startvärde false anges */
volatile bool led1_enabled = false;
volatile bool led2_enabled = false;
volatile bool led3_enabled = false;
volatile bool led4_enabled = false;
volatile bool led5_enabled = false;

/* assembler interrupt rutin */
ISR (PCINT2_vect)
{
	if (button_is_pressed(&b1))
	{
		led1_enabled = !led1_enabled;
	}
	if (button_is_pressed(&b2))
	{
		led2_enabled = !led2_enabled;
	}
	if (button_is_pressed(&b3))
	{
		led_toggle(&l3);
		led3_enabled = !led3_enabled;
	}
	if (button_is_pressed(&b4))
	{
		led_toggle(&l4);
		led4_enabled = !led4_enabled;
	}
	if (button_is_pressed(&b5))
	{
		led_toggle(&l5);
		led5_enabled = !led5_enabled;
	}
}