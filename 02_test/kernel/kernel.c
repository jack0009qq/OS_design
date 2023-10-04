#include "os.h"

void start_kernel(void)
{
	uart_init();
	uart_puts("Hello, RVOS!\n");

	char c;
	while(1){
		// sscanf("%d", &c);
		c = uart_getc();
		kprintf("%c",c);
		if (c == '\r') {
            kprintf("\n");
		}
	}

	// while (1) {
	// 	c = uart_getc();
	// 	uart_putc(c);
	// 	if (c=='\r') uart_putc(0x0A);
	// }; // stop here!

	
}

