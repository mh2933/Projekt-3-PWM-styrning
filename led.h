#ifndef LED_H_
#define LED_H_

#include "misc.h"

struct led
{
	uint8_t pin;
	enum io_port io_port;
	bool enabled;
};

void led_init(struct led* self, const uint8_t pin);

void led_on(struct led* self);

void led_off(struct led* self);

void led_toggle(struct led* self);

void led_clear(struct led* self);

#endif