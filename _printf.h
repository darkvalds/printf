#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct specifier - Structure pour associer un spécificateur de format
 *                    à une fonction de gestion.
 * @specifier: Pointeur vers une chaîne de caractères représentant
 *             le spécificateur (par exemple "c" pour `%c` ou "s" pour `%s`).
 * @f: Pointeur vers la fonction qui gère le spécificateur correspondant.
 *
 * Description : Cette structure est utilisée dans le contexte de la fonction
 * _printf. Elle permet de mapper un spécificateur de format (comme `%c`, `%s
 * etc.) à une fonction spécifique qui sait comment traiter et afficher
 * les arguments correspondants. Cela rend le code modulaire et facilement
 * extensible.
 */
typedef struct specifier
{
	char *specifier;  /* Le spécificateur (exemple : "c", "s", etc.) */
	int (*f)(va_list);
	 /* Pointeur vers la fonction qui gère ce spécificateur*/
} specifier_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);


#endif

