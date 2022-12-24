
#include "header.h"


/********************************************************************************
* main: Initierar mikrodatorn vid start. Programmet h�lls sedan ig�ng s� l�nge
*       matningssp�nning tillf�rs. Toggling av lysdioderna sker via interrupts,
*       d�rav avsaknad av kod i while-satsen.
********************************************************************************/
int main(void)
{  
    init_struct_objects();
	
	while (1)
	{
	  init_while_loop();
	}

	return 0;
}
