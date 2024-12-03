/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:19 by jpiensal          #+#    #+#             */
/*   Updated: 2024/12/02 18:41:00 by jpiensal         ###   ########.fr       */
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
	if (c == 'c')
		return (ft_putchar_n(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_n(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_printptr_n(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr_n(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printnbr_n(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_printhex_n(va_arg(ap, unsigned int), 39));
	else if (c == 'X')
		return (ft_printhex_n(va_arg(ap, unsigned int), 7));
	else if (c == '%')
		return (ft_putchar_n('%'));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		check;

	if (!fmt)
		return (-1);
	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && check_next(*(fmt + 1)))
			check = read_specifier(ap, *(++fmt));
		else if (*fmt == '%' && !(check_next(*(fmt + 1))))
			check = -1;
		else
			check = write(1, &(*fmt), 1);
		if (check == -1)
			return (-1);
		count += check;
		fmt++;
	}
	va_end(ap);
	return (count);
}
