/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:52:59 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/20 10:27:02 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_n(void *ptr)
{
	unsigned long	nbr;
	int				count;

	count = 0;
	nbr = (unsigned long)ptr;
	if (nbr < 16)
	{
		count += ft_putchar_n(NUMS_LOW[nbr]);
		return (count);
	}
	count += ft_putptr_n((void *)(nbr / 16));
	count += ft_putptr_n((void *)(nbr % 16));
	return (count);
}
