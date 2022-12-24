
#ifndef HEADER_H_
#define HEADER_H_

/* .h filerna sammlade i en gemensam header.h */
#include "misc.h"
#include "led.h"
#include "button.h"
#include "adc.h"
#include "init.h"

/* deklaration av globala struktar */
struct led l1, l2, l3, l4, l5;
struct button b1, b2, b3, b4, b5;
struct adc a1;

/* deklaration av enable variabel */
volatile bool led1_enabled;
volatile bool led2_enabled;
volatile bool led3_enabled;
volatile bool led4_enabled;
volatile bool led5_enabled;

/* globala variabler */
uint16_t pwm_on_time_us, pwm_off_time_us;


#endif /* HEADER_H_ */