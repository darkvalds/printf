#include <unistd.h>

/**
 * print_char - Affiche un caractère sur la sortie standard.
 * @c: Le caractère à afficher.
 *
 * Return: 0 en cas de succès, -1 en cas d'erreur.
 */
int print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}
