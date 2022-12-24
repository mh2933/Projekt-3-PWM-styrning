/* adc.c: AD_omvandling och PWM-aktivering */

#include "adc.h"

void adc_init(struct adc* self,
              const uint8_t pin)
{
	if (pin >= 0 && pin <= 5)
	{
		self->pin = pin;
	}
	else if (pin >= 14 && pin <= 19)
	{
		self->pin = pin - 14;
	}

	self->pwm_on_time_us = 0;
	self->pwm_off_time_us = 0;

	(void)adc_read(self);
	return;
}

/****************************************************************************************************** 
   1. ADMUX-register vilken matningssp�nning AVcc 5.0V (1 << REFS0) 
   2. Vilken analog pin A0-A5, pin. Seleketorbitar [MUX[3:0]] skiftas bin�rt ej bit-shifting. 
   3. AD-aktivering via bitarna ADEN, ADSC i status-register ADCSRA   
   4. Presacler-bitar v�ljs utefter divisionsfaktorn som �nskas ADPSn
   5. ADIF ettst�lls n�r AD omvandlingen �r klar vi v�ntar med hj�lp av while
   6. Vi m�ste nollst�lla(�terst�lla) ADIF biten n�r AD-omvandlingen �r klar via ettst�llning av ADIF
   7. Resultatet ligger nu i 16-bitars registret ADC(ADCH och ADCL) och returneras direkt
 ******************************************************************************************************/
uint16_t adc_read(const struct adc* self)
{
	ADMUX = (1 << REFS0) | self->pin;
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADPS2 ) | (1 << ADPS1) | (1 << ADPS0);
	while ((ADCSRA & (1 << ADIF)) == 0);
	ADCSRA = (1 << ADIF); 
	return ADC;
}

/********************************************************************************
* adc_duty_cycle: L�ser av en analog insignal och returnerar motsvarande
*                 duty_cycle som ett flyttal mellan 0 - 1.
*
*                 - self: Pekare till AD-omvandlaren som skall l�sas av.
********************************************************************************/
double adc_duty_cycle(const struct adc* self)
{
	return adc_read(self) / ADC_MAX;
}


/*************************************************************************** 
   self:            Analog pin
   pwm_period_us:   Periodtid mikrosekunder
   pwm_on__time_us: Tiden som duty cykeln �r p�, pekarna sparas v�rdet i
   pwm_off_time_us: Tiden som duty cykeln �r av, pekarna sparas v�rdet i
 ***************************************************************************/
void adc_get_pwm_values(struct adc* self, 
                        const uint16_t pwm_period_us, 
						uint16_t* pwm_on_time_us,  
						uint16_t* pwm_off_time_us)

{
	*pwm_on_time_us = (uint16_t)(adc_duty_cycle(self) * pwm_period_us + 0.5);
	*pwm_off_time_us = pwm_period_us - *pwm_on_time_us;
	return;
}


