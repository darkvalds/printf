#include "_printf.h"

/**
 * _printf - Réimplémentation simplifiée de la fonction printf.
 * @format: Chaîne de format contenant du texte et des spécificateurs.
 *
 * Description : Cette fonction lit la chaîne de format et affiche son contenu.
 * Elle prend en charge certains spécificateurs de format (comme `%c`, `%s`, `%%`)
 * en appelant des fonctions associées à chaque spécificateur.
 * Si un spécificateur inconnu est rencontré, il est affiché tel quel avec `%`.
 *
 * Return: Le nombre total de caractères imprimés.
 * Retourne -1 si la chaîne de format est NULL.
 */
int _printf(const char *format, ...)
{
    /* Tableau de spécificateurs et de leurs fonctions associées */
    specifier_t specs[] = {
        {"c", print_char},   /* Spécifie `%c` pour afficher un caractère */
        {"s", print_string}, /* Spécifie `%s` pour afficher une chaîne */
        {"%", print_percent},/* Spécifie `%%` pour afficher un `%` */
        {NULL, NULL}         /* Fin du tableau */
    };
    va_list args;    /* Liste d'arguments variadiques */
    int i, j, count = 0; /* Compteurs et indices */

    /* Vérification si la chaîne de format est NULL */
    if (!format)
        return (-1);

    /* Initialisation de la liste d'arguments variadiques */
    va_start(args, format);

    /* Parcours de la chaîne de format caractère par caractère */
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%') /* Détection d'un spécificateur */
        {
            i++; /* Passer le caractère `%` */
            for (j = 0; specs[j].specifier; j++) /* Recherche du spécificateur */
            {
                if (format[i] == *(specs[j].specifier))
                {
                    /* Appel de la fonction associée au spécificateur */
                    count += specs[j].f(args);
                    break; /* Sortir de la boucle pour passer au caractère suivant */
                }
            }
            if (!specs[j].specifier) /* Si le spécificateur est inconnu */
            {
                write(1, "%", 1);      /* Afficher `%` */
                write(1, &format[i], 1); /* Afficher le caractère suivant */
                count += 2;           /* Incrémenter le compteur de 2 caractères */
            }
        }
        else /* Si ce n'est pas un spécificateur */
        {
            write(1, &format[i], 1); /* Afficher le caractère tel quel */
            count++; /* Incrémenter le compteur de caractères imprimés */
        }
    }

    /* Libérer la liste d'arguments variadiques */
    va_end(args);

    /* Retourner le nombre total de caractères imprimés */
    return (count);
}
