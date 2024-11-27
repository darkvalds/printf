#include "_printf.h"


int _printf(const char *format, ...)
{
	va_list agrs;
	int count;

	 if (!format)
        return (-1);

	va_start(args, format);

	for (count = 0; count < format[count]; count++)
 }

