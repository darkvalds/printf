#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "_printf.h"
int _printf(const char *format, ...)
{
int qui_parcours_format = 0;
int qui_parcours_spe = 0;
int compteur = 0;
specificateur_t spe[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'\0', NULL} /* Marque la fin du tableau */
};
va_list arguments1;
va_start(arguments1, format); /* Initialiser la liste d'arguments */
if (format == NULL) /* Si format est null */
return (-1); /* Signale une erreur */
for (qui_parcours_format = 0; format[qui_parcours_format] != '\0'; qui_parcours_format++)
{
if (format[qui_parcours_format] == '%') /* Si après avoir parcouru on trouve '%' */
{
qui_parcours_format++; /* On poursuit au prochain caractère */
if (format[qui_parcours_format] == '\0') /* Si % est le dernier élément */
return (-1); /* Renvoie une erreur */
for (qui_parcours_spe = 0; spe[qui_parcours_spe].specificateur != '\0'; qui_parcours_spe++) /* On passe à spe */
{
if (format[qui_parcours_format] == spe[qui_parcours_spe].specificateur)
{
compteur += spe[qui_parcours_spe].pointeurdefonction(arguments1);
}
}
}
else
{
write(1, &format[qui_parcours_format], 1);
compteur++;
}
}
va_end(arguments1);
return (compteur);
}
