#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define SYMBOLS "0123456789abcdef"
#define UP_SYMBOLS "0123456789ABCDEF"
#define SPECIFIERS "cdipusxX%"

int ft_putchar_n(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr_n(char *str)
{
    int count;

    count = 0;
    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }
    return (count);
}

int ft_putnbr_base_n(long nbr, int base, char *symbols)
{
    int count = 0;

    if (nbr < 0)
    {
        count += write(1, "-", 1);
        return (ft_putnbr_base_n(-nbr, base, symbols) + count);
    }
    else if (nbr < base)
        return (ft_putchar_n(symbols[nbr]));
    count += ft_putnbr_base_n(nbr / base, base, symbols);
    count += ft_putnbr_base_n(nbr % base, base, symbols);
    return (count);
}

int ft_putaddr_n(void *ptr, unsigned long base)
{
    int count = 0;
    unsigned long   ptr_addr;

    ptr_addr = (unsigned long)ptr;
    if (ptr_addr < base)
    {
        count += ft_putchar_n(SYMBOLS[ptr_addr]);
        return (count);
    }
    count += ft_putaddr_n((void *)(ptr_addr / base), base);
    count += ft_putaddr_n((void *)(ptr_addr % base), base);
    return (count);
}

int ft_putfmt_n(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'c')
        count += ft_putchar_n(va_arg(ap, int));
    else if (specifier == 's')
        count += ft_putstr_n(va_arg(ap, char *));
    else if (specifier == 'p')
    {
        count += ft_putaddr_n(va_arg(ap, void *), 16);
        count += 2;
    }
    else if (specifier == 'd')
        count += ft_putnbr_base_n((va_arg(ap, int)), 10, SYMBOLS);
    else if (specifier == 'i')
        count += ft_putnbr_base_n((va_arg(ap, int)), 10, SYMBOLS);
    else if (specifier == 'u')
        count += ft_putnbr_base_n((va_arg(ap, unsigned int)), 10, SYMBOLS);
    else if (specifier == 'x')
        count += ft_putnbr_base_n((va_arg(ap, unsigned int)), 16, SYMBOLS);
    else if (specifier == 'X')
        count += ft_putnbr_base_n((va_arg(ap, unsigned int)), 16, UP_SYMBOLS);
    else
        count += write(1, &specifier, 1);
    return (count);
}


int check_specifier(char c)
{
    int i = 0;

    while (SPECIFIERS[i++])
    {
        if (c == 'p')
            return (write(1, "0x", 2));
        else if (c == SPECIFIERS[i])
            return (1);
        i++;
    }
    return (0);
}

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int count;
    int i;

    va_start(ap, fmt);
    count = 0;
    i = 0;
    while (fmt[i])
    {
        if (fmt[i] == '%' && check_specifier(fmt[i + 1]))
        {
            count += ft_putfmt_n(fmt[i + 1], ap);
            i++;
        }
        else
            count += write (1, &fmt[i], 1);
        i++;
    }
    va_end(ap);
    return count;
}

int main(void)
{
    int count;
    int cnt;
    count = ft_printf("%p, %d, %x, %X\n", -33, -33, -33, -33);
    cnt = printf("[%-10.12s], [% 8d], %x, %X, [%+0 5c]\n", "Hello", -33, -33, -33, 'c');
    ft_printf("ft_printf chars = %d\n", count);
    printf("printf chars = %d\n", cnt);
    return (0);
}
