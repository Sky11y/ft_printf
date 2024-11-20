/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:59 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/20 10:25:08 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_n(long nbr, char *str, int base)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += write (1, "-", 1);
		count += ft_putnbr_base_n(-nbr, str, base);
	}
	else if (nbr < base)
		count += write(1, &str[nbr], 1);
	else
	{
		count += ft_putnbr_base_n(nbr / base, str, base);
		count += ft_putnbr_base_n(nbr % base, str, base);
	}
	return (count);
}
