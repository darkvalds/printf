int print_char(va_list args)
{
    char c = va_arg(args, int);
    return write(1, &c, 1);
}

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        write(1, str++, 1);
        count++;
    }
    return count;
}

int print_percent(va_list args)
{
    (void)args; /* Éviter les avertissements */
    return write(1, "%", 1);
}