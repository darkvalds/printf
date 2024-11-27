#ifndef _PRINTF_H
#define __PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct specifier
{
    char *specifier;  /* Le spécificateur (ex : "c", "s", etc.) */
    int (*f)(va_list); /* Pointeur vers la fonction qui gère ce spécificateur */
} specifier_t;


int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);


#endif _PRINTF_H
