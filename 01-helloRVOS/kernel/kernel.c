#include "os.h"

void start_kernel(void)
{
	uart_init();
	uart_puts("Hello, RVOS!\n");	
	char c;

	// while (1)
	// {
	// 	c = uart_getc();

	// 	if(c == '\n'){
	// 		uart_putc('\n');
	// 	}
	// 	uart_putc(c);
	// }
	
	
}

