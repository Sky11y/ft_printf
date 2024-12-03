/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:34:29 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/29 12:53:51 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_n(unsigned long nbr, int shift)
{
	int		count;
	char	*str;

	str = ft_xtoa(nbr, shift);
	count = ft_putstr_n(str);
	free(str);
	return (count);
}
