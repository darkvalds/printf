#include "_printf.h"
/**
 * print_char - Gère le spécificateur `%c` dans la fonction _printf.
 * @args: Liste d'arguments passée à _printf, contenant le caractère à imprimer.
 *
 * Description : Cette fonction est appelée lorsque le spécificateur `%c`
 * est trouvé dans la chaîne de format de _printf. Elle extrait un caractère
 * de la liste d'arguments et l'imprime sur la sortie standard.
 *
 * Return: Retourne toujours 1, car un seul caractère est imprimé.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return write(1, &c, 1);
}

/**
 * print_string - Gère le spécificateur `%s` dans la fonction _printf.
 * @args: Liste d'arguments passée à _printf, contenant la chaîne à imprimer.
 *
 * Description : Cette fonction est appelée lorsque le spécificateur `%s`
 * est trouvé dans la chaîne de format de _printf. Elle extrait une chaîne
 * de caractères de la liste d'arguments, puis l'imprime sur la sortie
 * standard. Si la chaîne est NULL, elle affiche "(null)" par défaut.
 *
 * Return: Retourne le nombre total de caractères imprimés.
 */
int print_string(va_list args)
{
	/* Récupérer la chaîne de caractères de la liste d'arguments */
	char *str = va_arg(args, char *);
	int count = 0;

  /* Si la chaîne est NULL, utiliser "(null)" comme valeur par défaut */
	if (!str)
		str = "(null)";
		
	/* Parcourir la chaîne et imprimer chaque caractère */
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	  /* Retourner le nombre total de caractères imprimés */
	return count;
}


/**
 * print_percent - Gère le spécificateur `%%` dans la fonction _printf.
 * @args: Liste d'arguments passée à _printf (non utilisée ici).
 *
 * Description : Cette fonction est appelée lorsque le spécificateur `%%`
 * est trouvé dans la chaîne de format de _printf. Elle imprime un
 * caractère `%` sur la sortie standard. Le paramètre `args` est inclus
 * pour conserver une cohérence avec les autres fonctions associées
 * aux spécificateurs, mais il n'est pas utilisé pour ce cas particulier.
 *
 * Return: Retourne toujours 1, car un seul caractère est imprimé.
 */
int print_percent(va_list args)
{
	(void)args; /* Éviter les avertissements */
	return write(1, "%", 1);
}