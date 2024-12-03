/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiensal <jpiensal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:03:52 by jpiensal          #+#    #+#             */
/*   Updated: 2024/11/29 13:04:46 by jpiensal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_n(long nbr)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_ltoa(nbr);
	count = ft_putstr_n(str);
	free(str);
	return (count);
}
