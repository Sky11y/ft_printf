/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:19 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/20 14:11:09 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_next(char c)
{
	int	i;

	i = 0;
	while (SPECIFIERS[i] && c)
	{
		if (SPECIFIERS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	read_specifier(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_n(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr_n(va_arg(ap, char *));
	else if (c == 'p')
	{
		count += ft_putstr_n("0x");
		count += ft_putptr_n(va_arg(ap, void *));
	}
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_base_n(va_arg(ap, int), NUMS_LOW, 10);
	else if (c == 'u')
		count += ft_putnbr_base_n(va_arg(ap, unsigned int), NUMS_LOW, 10);
	else if (c == 'x')
		count += ft_putnbr_base_n(va_arg(ap, unsigned int), NUMS_LOW, 16);
	else if (c == 'X')
		count += ft_putnbr_base_n(va_arg(ap, unsigned int), NUMS_UP, 16);
	else if (c == '%')
		count += ft_putchar_n('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	if (!fmt)
		return (0);
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && check_next(*(fmt + 1)))
			count += read_specifier(ap, *(++fmt));
		else if (*fmt == '%' && !(check_next(*(fmt + 1))))
			return (-1);
		else
			count += write(1, &(*fmt), 1);
		fmt++;
	}
	va_end(ap);
	return (count);
}
