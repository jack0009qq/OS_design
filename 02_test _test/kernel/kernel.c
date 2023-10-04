#include "os.h"

void start_kernel(void)
{
	uart_init();
	uart_puts("Hello, RVOS!\n");
	
	while (1) {
		int  num1 =0;
		char  num2 [100];
		kprintf("here is value\n");
    	scanf("%d%s",&num1,&num2);
		kprintf("here is a %p\nhere is b %p \n",&num1,&num2);
		kprintf("num1 = %d\n",num1);
		kprintf("num2 = %s\n",num2);
		kprintf("Enddd!!!!!!!!!!!!!!!!!\n");
		break;
	}; // stop here!	
}

