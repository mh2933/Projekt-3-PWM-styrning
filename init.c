/* init.c initierar strukt objekten och interrupts */

#include "init.h"

void init_struct_objects()
{
	/* led objekt och pin 12-8 */
	 led_init(&l1, 12);
	 led_init(&l2, 11);
	 led_init(&l3, 10);
	 led_init(&l4, 9);
	 led_init(&l5, 8);

    /* button objekt och pin 1-5 */
	 button_init(&b1, 1);
	 button_init(&b2, 2);
	 button_init(&b3, 3);
	 button_init(&b4, 4);
	 button_init(&b5, 5);
	 
	/* button interrupts b1-b5*/ 
	 button_enable_interrupt(&b1);
	 button_enable_interrupt(&b2);
	 button_enable_interrupt(&b3);
	 button_enable_interrupt(&b4);
	 button_enable_interrupt(&b5);
	 
    /* adc objekt och pin A0 */ 
	 adc_init(&a1, 0);
}

/* denna funktion körs i while loopen i main */
void init_while_loop()
{
	adc_get_pwm_values(&a1, 1000, &pwm_on_time_us, &pwm_off_time_us);
	
	if (led1_enabled) led_on(&l1);  // Tänder lysdioderna om enabled.
	if (led2_enabled) led_on(&l2);
	if (led3_enabled) led_on(&l3);
	if (led4_enabled) led_on(&l4);
	if (led5_enabled) led_on(&l5);
	
	delay_us(&pwm_on_time_us);  // Håller lysdioden tänd under on-tiden.
	
	led_off(&l1);     // Släcker lysdioden.
	led_off(&l2);
	led_off(&l3);
	led_off(&l4);
	led_off(&l5);
	
	delay_us(&pwm_off_time_us); // Håller lysdioden släckt under off-tiden.
}
