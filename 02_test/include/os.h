#ifndef __OS_H__
#define __OS_H__

#include "types.h"
#include "platform.h"

#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/* uart */
void uart_init();
int uart_putc(char ch);
void uart_puts(char *s);
char uart_getc();

/* printf */
int  kprintf(const char* s, ...);
void panic(char *s);


#endif /* __OS_H__ */
