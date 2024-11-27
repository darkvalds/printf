#include "_printf.h"


int _printf(const char *format, ...)
{
	specifier_t specs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}};
	va_list args;
	int i, j, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)

}
