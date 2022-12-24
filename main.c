
#include "header.h"


/********************************************************************************
* main: Initierar mikrodatorn vid start. Programmet hålls sedan igång så länge
*       matningsspänning tillförs. Toggling av lysdioderna sker via interrupts,
*       därav avsaknad av kod i while-satsen.
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
