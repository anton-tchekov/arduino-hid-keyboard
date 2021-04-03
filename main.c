#include <stdio.h>
#include "usb.c"

int main(void)
{
	static const char hw[] PROGMEM = "Hello World!\n";
	usb_init();
	usb_string_P(hw);
	for(;;)
	{
	}

	return 0;
}

