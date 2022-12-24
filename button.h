
#ifndef BUTTON_H_
#define BUTTON_H_

#include "misc.h"

struct button
{
	uint8_t pin;
	enum io_port io_port;
	bool interrupt_enabled;
};

/********************************************************************************
* button_init: Initierar ny tryckknapp på angiven pin.
*
*              - self: Pekare till tryckknappen som ska initieras.
*              - pin : Tryckknappens pin-nummer på Arduino Uno, exempelvis 13.
*                      Alternativt kan motsvarande port-nummer på ATmega328P
*                      anges, exempelvis B5 för pin 13 eller D3 för pin 3.
********************************************************************************/
void button_init(struct button* self,
                 const uint8_t pin);

/********************************************************************************
* button_clear: Nollställer tryckknapp samt motsvarande pin.
*
*               - self: Pekare till tryckknappen som ska nollställas.
********************************************************************************/
void button_clear(struct button* self);

/********************************************************************************
* button_is_pressed: Läser av tryckknappens pin och indikerar ifall denna är
*                    nedtryckt. I så fall returneras true, annars false.
*
*                    - self: Pekare till tryckknappen som ska läsas av.
********************************************************************************/
bool button_is_pressed(const struct button* self);

/********************************************************************************
* button_enable_interrupt: Aktiverar PCI-avbrott på angiven tryckknapp så att
*                          event på tryckknappens pin medför avbrott, både på
*                          stigande och fallande flank. Kontroll av flank måste
*                          skötas av användaren, förslagsvis via avläsning i
*                          motsvarande avbrottsrutin.
*
*                          Nedan visas sambandet mellan använd I/O-port samt
*                          avbrottsvektorn för motsvarande avbrottsrutin:
*
*                          I/O-port     pin (Arduino Uno)     Avbrottsvektor
*                             B              8 - 13             PCINT0_vect
*                             C             A0 - A5             PCINT1_vect
*                             D              0 - 7              PCINT2_vect
*
*                          - self: Pekare till tryckknappen som PCI-avbrott
*                                  ska aktiveras på.
********************************************************************************/
void button_enable_interrupt(struct button* self);

/********************************************************************************
* button_disable_interrupt: Inaktiverar PCI-avbrott på angiven tryckknapp.
*
*                           - self: Pekare till tryckknappen som PCI-avbrott
*                                  ska inaktiveras på.
********************************************************************************/
void button_disable_interrupt(struct button* self);

/********************************************************************************
* button_toggle_interrupt: Togglar aktivering av PCI-avbrott på angiven
*                          tryckknapp. Om avbrott är aktiverat vid anrop
*                          så sker inaktivering. På samma sätt gäller att om
*                          avbrott är inaktiverat vid anrop så sker aktivering.
*
*                          - self: Pekare till tryckknappen som aktivering av
*                                  PCI-avbrott ska inaktiveras på.
********************************************************************************/
void button_toggle_interrupt(struct button* self);



#endif /* BUTTON_H_ */